#ifndef COS51_UTIL_H
#define COS51_UTIL_H

#define HIGH_BYTE(w) \
    ((unsigned char)(((unsigned) (w)) >> 8))
#define LOW_BYTE(w) \
    ((unsigned char)((w) & 0xff))

#define __shiftl(x, n) (((x) << (n)) | ((x) >> (8 - (n))))
#define __shiftr(x, n) (((x) >> (n)) | ((x) << (8 - (n))))

#endif
