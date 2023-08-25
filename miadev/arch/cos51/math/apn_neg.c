#include "apn.h"

void apnNeg(BYTE *apn, BYTE len) {
    BYTE i, x;
    __bit carry = 1;
    for (i = 0; i < len; i++) {
        x = *apn;
        x = ~x + carry;
        carry = !x;
        *apn++ = ~x;
    }
}
