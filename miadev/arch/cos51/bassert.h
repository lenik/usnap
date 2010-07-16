#ifndef COS51_BASSERT_H
#define COS51_BASSERT_H

#include "sleep.h"

#undef assert
#define assert(x) ((x) == 0 ? _bassert() : (void)0)

void _bassert() {
    P1_5 = 0;
    while (1) {
        P1_0 ^= 1;
        mdelay(100);
    }
}

#endif
