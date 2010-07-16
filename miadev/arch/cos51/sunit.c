#include <stdio.h>
#include <8051.h>

#define SUNIT_IMPL
#include "sunit.h"

extern __xdata byte sunitBuffer[];
extern byte sunitBufferSize;

static int _start = 0;
static int _end = 0;

void putchar(char c) {
    while (!TI)
        ;
    TI = 0;
    SBUF = c;
}

char getchar() {
    byte c;
    while (_start == _end)
        ;
    c = sunitBuffer[_start++];
    _start %= sunitBufferSize;
    return (char) c;
}

void sunitSerialProc()
__interrupt 4 {
    if (RI) {
        if (_start <= _end) {
            sunitBuffer[_end++] = SBUF;
            _end %= sunitBufferSize;
        } else if (_end + 1 < _start) {
            sunitBuffer[_end++] = SBUF;
        } else {
            die("recvbuf full");
        }
        RI = 0;
    }
}

void vmstop() {
__asm
        ljmp 0xffff
__endasm;
}

void die(const char *message) {
    puts(message);
    vmstop();
}

void _assert(char *message, const char *file, unsigned int line) {
    printf("%s:%d: assertion failure: ", file, line);
    die(message);
}
