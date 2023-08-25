#include "apn.h"

BYTE apnMul8(BYTE *apn, BYTE len, BYTE mul) {
    BYTE i, x;
    WORD y;
    BYTE carry = 0;
    for (i = 0; i < len; i++) {
        x = *apn;
        y = (WORD)x * (WORD)mul;
        y += carry;
        x = y & 0xff;
        carry = y >> 8;
        *apn++ = x;
    }
    return carry;
}
