#ifndef __LED8_H
#define __LED8_H

#include "types.h"

#ifndef __LED8_C

#   ifndef LED8_COUNT
#   define LED8_COUNT 8
#   endif

__xdata byte led8Cache[LED8_COUNT];
__xdata byte led8Count = LED8_COUNT;

#endif

void led8Set(byte index, byte mask);
void led8Draw(byte index, char c);
void led8Refresh();

/**
 * @param apn arbitrary number.
 * @param cb bytes of apn
 * @param frac10 fractional width, [0, frac10^10)
 */
void led8PutNum(const byte *apn, byte cb, byte frac10) __reentrant;

#endif
