#ifndef COS51_SUNIT_H
#define COS51_SUNIT_H

#include <assert.h>
#include <stdio.h>
#include <8051.h>
#include "types.h"
#include "config.h"

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

#   ifndef COMM_BUFSIZE
#       define COMM_BUFSIZE 8
#   endif

#   include "comm.h"

#endif

// SUnit Framework.

void testCase();

#ifndef COS51_SUNIT_C

void main() {

#   ifdef SUNIT_STDIO
    setTimer2Baud(9600);
    SCON = 0x40; // SM2, ¬REN
    ES = 1;
    EA = 1;
#   endif

    testCase();

#   ifdef SUNIT_STDIO
    flush();
#   endif

    vmstop();
}

#endif

#endif
