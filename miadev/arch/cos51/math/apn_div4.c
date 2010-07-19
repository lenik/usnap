#include "apn.h"
#include "../util.h"

byte apnDiv4(byte *apn, byte len, byte div) {
    byte x;
    byte a = 0; // dividend
    byte quo = 0; // 4bit|4bit
    byte rem4 = 0;

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
