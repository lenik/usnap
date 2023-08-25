#ifndef __LED8_H
#define __LED8_H

#include "types.h"

#ifndef __LED8_C

#   ifndef LED8_COUNT
#   define LED8_COUNT 8
#   endif

__xdata BYTE led8Cache[LED8_COUNT];
__xdata BYTE led8Count = LED8_COUNT;

#endif

void led8Set(BYTE index, BYTE mask);
void led8Draw(BYTE index, char c);
void led8Refresh();

/**
 * @param apn arbitrary number.
 * @param cb BYTEs of apn
 * @param frac10 fractional width, [0, frac10^10)
 */
void led8PutNum(const BYTE *apn, BYTE cb, BYTE frac10) __reentrant;

#endif
