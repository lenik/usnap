#ifndef COS51_UTIL_H
#define COS51_UTIL_H

#define nop2() \
    __asm \
        nop \
        nop \
    __endasm

#define nop4() \
    __asm \
        nop \
        nop \
        nop \
        nop \
    __endasm

#endif
