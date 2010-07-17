#include <stdio.h>
#include <8051.h>

#include "config.h"

#define COS51_SUNIT_C
#include "sunit.h"

extern __xdata byte sunitBuffer[];
extern byte sunitBufferSize;
extern byte sunitReadPtr;
extern byte sunitRecvPtr;

__bit sunitSending = 0;

void putchar(char c) {
    while (sunitSending)
        ;
    SBUF = c;
    sunitSending = 1;
}

char getchar() {
    byte c;

    REN = 1;
    while (sunitReadPtr == sunitRecvPtr)
        ;
    c = sunitBuffer[sunitReadPtr++];
    sunitReadPtr %= sunitBufferSize;
    return (char) c;
}

void sunitSerialProc()
__interrupt(4) __using(RBANK_SUNIT) {
    if (TI) {
        sunitSending = 0;
        TI = 0;
    }
    if (RI) {
        if (sunitReadPtr <= sunitRecvPtr) {
            sunitBuffer[sunitRecvPtr++] = SBUF;
            sunitRecvPtr %= sunitBufferSize;
        } else if (sunitRecvPtr + 1 < sunitReadPtr) {
            sunitBuffer[sunitRecvPtr++] = SBUF;
        } else {
            die("recvbuf full");
        }
        RI = 0;
    }
}

void _assert(char *message, const char *file, unsigned int line) {
    printf_small("%s:%d: assertion failure: ", file, line);
    die(message);
}

void vmstop() {
    while (sunitSending)
        ;
    __asm ljmp 0xffff __endasm;
}

void die(const char *message) {
    puts(message);
    vmstop();
}
