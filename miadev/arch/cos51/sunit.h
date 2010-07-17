#ifndef COS51_SUNIT_H
#define COS51_SUNIT_H

#include <assert.h>
#include <stdio.h>
#include <8051.h>
#include "types.h"

// ASSERT(), TRACE() macros
void _assert(char *message, const char *file, unsigned int line);

#ifdef DEBUG
#   define TRACE(message) \
        printf_small("%s:%d: %s\n", __FILE__, __LINE__, message)
#else
#   define TRACE(m)
#endif

// TestVM Controls
void die(const char *message);
void vmstop();

// SUnit/STDIO
#ifdef SUNIT_STDIO

#   ifndef SUNIT_BUFSIZE
#       define SUNIT_BUFSIZE 32
#   endif

#else

#   define SUNIT_BUFSIZE 1

#endif

#   ifndef COS51_SUNIT_C
__xdata byte sunitBuffer[SUNIT_BUFSIZE];
byte sunitBufferSize = SUNIT_BUFSIZE;
byte sunitReadPtr = 0;
byte sunitRecvPtr = 0;
#   endif

// SUnit Framework.

void testCase();

#ifndef COS51_SUNIT_C
void main() {
#   ifdef SUNIT_STDIO
    SCON = 0x40; // SM2, ¬REN
    ES = 1;
    EA = 1;
#   endif

    testCase();
    vmstop();
}
#endif

#endif
