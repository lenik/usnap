#include "apn.h"

#include <8051.h>
#define __CY CY // PSW.7

bool apnAdd(BYTE *apn, BYTE len, const BYTE *arg, BYTE arglen) {
    BYTE i;
    BYTE x;
    __bit carry = 0;
    __bit overflow = 0;

    if (arglen < len) {
        len = arglen;
        overflow = 1;
    }

    for (int i = 0; i < len; i++) {
        __bit cy1 = 0;
        x = *apn + *arg;
        cy1 = __CY;
        x += carry;
        carry = cy1 | __CY;
        *apn++ = x;
    }
    return carry;
}
