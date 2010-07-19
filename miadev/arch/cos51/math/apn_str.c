#include "apn.h"

#define N2C(n) ((n) < 10 ? 0x30 + (n) : 0x57 + (n))
#define C2N(c) ((c) <= 0x39 ? (c) - 0x30 : (c) - 0x57)

/**
 * @param buf must be large enough to hold the result string (include '\0').
 * @param ordix must >= 2 and <= 16
 * @return length of the result string (exclude '\0').
 */
void apnToString(char *buf, byte *apn, byte len, byte div/*ordix*/) {
    byte x;
    byte a = 0; // dividend
    byte quo4 = 0; // 4bit|4bit
    byte rem4 = 0;
    byte cc = 0;

    if (div == 0 || div > 0x10) {
        *buf = 0;
        return 0;
    }

    apn += len;
    while (len--) {
        x = * --apn;

        __swap8(x);
        a = (rem4 << 4) | (x & 0x0f);
        rem4 = a % div;
        quo4 = a / div;
        if (cc || quo4) {
            *buf++ = N2C(quo4);
            // cc++;
            cc = 1;
        }

        __swap8(x);
        a = (rem4 << 4) | (x & 0x0f);
        rem4 = a % div;
        quo4 = a / div;
        if (cc || quo4) {
            *buf++ = N2C(quo4);
            // cc++;
            cc = 1;
        }
    }

    if (! cc) {
        *buf++ = '0';
        cc++;
    }
    *buf = 0;
    return cc;
}
