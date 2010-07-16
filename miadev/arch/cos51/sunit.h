#ifndef COS51_SUNIT_H
#define COS51_SUNIT_H

#include <assert.h>
#include <stdio.h>
#include <8051.h>
#include "types.h"

#ifdef DEBUG
#   define TRACE(message) \
        printf("%s:%d: %s\n", __FILE__, __LINE__, message)
#else
#   define TRACE(m)
#endif

void _assert(char *message, const char *file, unsigned int line);
void die(const char *message);
void vmstop();

#ifdef SUNIT_NOCOMM
#   define SUNIT_BUFSIZE 1
#else
#   ifndef SUNIT_BUFSIZE
#   define SUNIT_BUFSIZE 32
#   endif
#endif

#ifndef SUNIT_IMPL
    __xdata byte sunitBuffer[SUNIT_BUFSIZE];
    byte sunitBufferSize = SUNIT_BUFSIZE;

    void testCase();
    void main() {
        // SCON = 0x50; // SM1, REN
        REN = 1;
        ES = 1; // IE0.4
        testCase();
        vmstop();
    }
#endif

#endif
