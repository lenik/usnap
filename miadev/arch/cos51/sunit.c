#include <stdio.h>
#include <8051.h>

#include "config.h"
#include "io/comm.h"

#define COS51_SUNIT_C
#include "sunit.h"

void putchar(char c) {
    send(c);
}

char getchar() {
    return recv();
}

char *gets(char *s) {
    char *_s = s;
    char c;
    bool end = 0;
    unsigned int count = 0;

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

void _assert(char *message, const char *file, unsigned int line) {
    printf_small("%s:%d: assertion failure: ", file, line);
    die(message);
}

void die(const char *message) {
    puts(message);
    flush();
    vmstop();
}

void vmstop() {
    __asm ljmp 0xffff __endasm;
}
