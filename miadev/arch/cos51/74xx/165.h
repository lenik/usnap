#ifndef _74XX_165_H
#define _74XX_165_H

#include "../util.h"

#define X165_READ_BITS(b, n, sh_ld, clk, in) \
    do { \
        byte i = n + 1; \
        sh_ld = 0; /* load */ \
        sh_ld = 1; /* shift */ \
        while (--i) { \
            b <<= 1; \
            if ((in)) \
                b |= 1; \
            clk = 1; \
            clk = 0; \
        } \
    } while (0)

#define X165_READ_NIBBLE(x, sh_ld, clk, in) X165_READ_BITS(x, 4, sh_ld, clk, in)
#define X165_READ_BYTE(x, sh_ld, clk, in)   X165_READ_BITS(x, 8, sh_ld, clk, in)
#define X165_READ_WORD(x, sh_ld, clk, in)   X165_READ_BITS(x, 16, sh_ld, clk, in)
#define X165_READ_DWORD(x, sh_ld, clk, in)  X165_READ_BITS(x, 32, sh_ld, clk, in)

#endif
