#ifndef COS51_UTIL_H
#define COS51_UTIL_H

#define HIGH_BYTE(w) \
    ((unsigned char)(((unsigned) (w)) >> 8))
#define LOW_BYTE(w) \
    ((unsigned char)((w) & 0xff))

#endif
