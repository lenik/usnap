#include "apn.h"
#include "util.h"

#define N2C(n) ((n) < 10 ? 0x30 + (n) : 0x57 + (n))
#define C2N(c) ((c) <= 0x39 ? (c) - 0x30 : (c) - 0x57)

/**
 * @param buf must be large enough to hold the result string (include '\0').
 * @param len should less than 0x100 / (8 / log(2, ordix)) for safe purpose.
 * @param ordix must >= 2 and <= 16
 * @return length of the result string (exclude '\0').
 */
WORD apnToString(char *buf, BYTE *apn, BYTE len, BYTE div/*ordix*/) {
    BYTE x;
    BYTE a = 0; // dividend
    BYTE quo4 = 0; // 4bit|4bit
    BYTE rem4 = 0;
    __bit lead = 0;
    WORD cc = 0;

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
        if (lead || quo4) {
            *buf++ = N2C(quo4);
            lead = 1;
            cc++;
        }

        __swap8(x);
        a = (rem4 << 4) | (x & 0x0f);
        rem4 = a % div;
        quo4 = a / div;
        if (lead || quo4) {
            *buf++ = N2C(quo4);
            lead = 1;
            cc++;
        }
    }

    if (! lead) {
        *buf++ = '0';
        cc = 1;
    }
    *buf = 0;
    return cc;
}
