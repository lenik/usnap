
#include "StdAfx.h"

#include "kernel.h"

static char base64_enc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static int base64_dec[] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -2, -1, -1,     /* -2: '=' */
    -1,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1,
    -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
};

// returns actual characters written (include '\0'), or 0 if buffer too small.
int base64_encode(const char *data, int cb, char *buffer, int cc) {
    int packs = cb / 3;
    int csize = packs;
    unsigned char a, b, c;

    if (cb %= 3) csize++;
    csize <<= 2;
    if (cc < ++csize)   // include '\0'
        return 0;

    while (packs--) {
        a = *data++;
        b = *data++;
        c = *data++;
        *buffer++ = base64_enc[a >> 2];
        *buffer++ = base64_enc[((a & 0x3) << 4) | (b >> 4)];
        *buffer++ = base64_enc[((b & 0xf) << 2) | (c >> 6)];
        *buffer++ = base64_enc[c & 0x3f];
    }

    if (cb--) {
        a = *data++;
        *buffer++ = base64_enc[a >> 2];
        if (cb) {
            b = *data++;
            *buffer++ = base64_enc[((a & 0x3) << 4) | (b >> 4)];
            *buffer++ = base64_enc[((b & 0xf) << 2)];
            *buffer++ = '=';
        } else {
            *buffer++ = base64_enc[((a & 0x3) << 4)];
            *buffer++ = '=';
            *buffer++ = '=';
        }
    }

    *buffer = 0;
    return csize;
}

// returns actual bytes written, space and new-line are stripped.
int base64_decode(const char *base64, int cc, char *buffer, int cb) {
    int x, y, z, w;
    int bsize = 0;

    while (cc) {
        while (cc-- && (x = base64_dec[*base64++]) == -1);
        if (!cc) break;
        while (cc-- && (y = base64_dec[*base64++]) == -1);
        if (!cc) break;
        while (cc-- && (z = base64_dec[*base64++]) == -1);
        if (!cc) break;
        while (cc-- && (w = base64_dec[*base64++]) == -1);
        if (w == -1) break;

        if (w == -2) {
            if (--cb < 0) break;
            *buffer++ = (x << 2) | (y >> 4);
            bsize++;
            if (z != -2) {
                if (--cb < 0) break;
                *buffer++ = (y << 4) | (z >> 2);
                bsize++;
            }
            break;
        }

        if ((cb -= 3) < 0) break;
        *buffer++ = (x << 2) | (y >> 4);
        *buffer++ = (y << 4) | (z >> 2);
        *buffer++ = (z << 6) | (w);
        bsize += 3;
    }
    return bsize;
}
