#include "apn.h"

byte apnMul8(byte *apn, byte len, byte mul) {
    byte i, x;
    word y;
    byte carry = 0;
    for (i = 0; i < len; i++) {
        x = *apn;
        y = (word)x * (word)mul;
        y += carry;
        x = y & 0xff;
        carry = y >> 8;
        *apn++ = x;
    }
    return carry;
}
