#ifndef COS51_UTIL_H
#define COS51_UTIL_H

#define HIGH_BYTE(w) \
    ((unsigned char)(((unsigned) (w)) >> 8))
#define LOW_BYTE(w) \
    ((unsigned char)((w) & 0xff))

#define __rol8(x, n)    (((x) << (n)) | ((x) >> (8 - (n))))
#define __ror8(x, n)    (((x) >> (n)) | ((x) << (8 - (n))))

#define __swap8(x)      __ror8(x, 4)

#endif
