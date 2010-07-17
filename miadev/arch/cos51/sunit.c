#include <stdio.h>
#include <8051.h>

#include "config.h"

#define COS51_SUNIT_C
#include "sunit.h"

extern __xdata byte sunitBuffer[];
extern byte sunitBufferSize;
extern byte sunitReadPtr;
extern byte sunitRecvPtr;

static __bit empty = 1;
static __bit full = 0;
static __bit sending = 0;

void putchar(char c) {
    while (sending)
        ;
    SBUF = c;
    sending = 1;
}

char getchar() {
    byte c;

    if (empty) {
        REN = 1;
        while (empty)
            ;
    }

    c = sunitBuffer[sunitReadPtr++];
    sunitReadPtr %= sunitBufferSize;

    full = 0;

    ES = 0;
    if (sunitReadPtr == sunitRecvPtr)
        empty = 1;
    ES = 1;

    return (char) c;
}

char *gets(char *s) {
    char *_s = s;
    char c;
    __bit end = 0;
    unsigned int count = 0;
printf_small("recvbuf[%d,%d]\n", sunitReadPtr, sunitRecvPtr);
    while (!end) {
        c = getchar();
        switch (c) {
        case '\x7f':
            if (count == 0)
                continue;
            s--;
            count--;
            break;
        case '\n':
            end = 1;
            break;
        default:
            *s++ = c;
            count++;
        }
        putchar(c);
    }
    *s = 0;
    return _s;
}

void sunitSerialProc()
__interrupt(4) __using(RBANK_SUNIT) {
    if (TI) {
        sending = 0;
        TI = 0;
    }
    if (RI) {
        if (full)
        if (REN)
        die("Unexpected RI, REN=1");
        else
        die("Unexpected RI, REN=0");

        sunitBuffer[sunitRecvPtr++] = SBUF;
        sunitRecvPtr %= sunitBufferSize;
        empty = 0;

        if (sunitRecvPtr == sunitReadPtr) {
            full = 1;
            REN = 0;
        }

        RI = 0;
    }
}

void _assert(char *message, const char *file, unsigned int line) {
    printf_small("%s:%d: assertion failure: ", file, line);
    die(message);
}

void vmstop() {
    while (sending)
        ;
__asm ljmp 0xffff __endasm;
}

void die(const char *message) {
    puts(message);
    vmstop();
}
