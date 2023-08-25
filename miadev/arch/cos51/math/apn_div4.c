#include "apn.h"
#include "../util.h"

BYTE apnDiv4(BYTE *apn, BYTE len, BYTE div) {
    BYTE x;
    BYTE a = 0; // dividend
    BYTE quo = 0; // 4bit|4bit
    BYTE rem4 = 0;

    if (div == 0 || div > 0x10)
        return -1;

    apn += len;
    while (len--) {
        x = * --apn;

        __swap8(x);
        a = (rem4 << 4) | (x & 0x0f);
        quo |= a / div;
        rem4 = a % div;
        quo <<= 4;

        __swap8(x);
        a = (rem4 << 4) | (x & 0x0f);
        quo |= a / div;
        rem4 = a % div;

        *apn = quo;
    }
    return rem4;
}
