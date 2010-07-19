#ifndef __APN_H
#define __APN_H

#include "../types.h"

/**
 * If arglen is longer than len, the extra bytes are ignored, and 1 is returned.
 *
 * @return carry/overflow bit
 */
byte apnAdd(byte *apn, byte len, const byte *arg, byte arglen);

void apnNeg(byte *apn, byte len);

/**
 * @param div must be 0 < div ≤ 0x10
 * @return remainder. Always return 0xff if div==0 or >0x10.
 */
byte apnDiv4(byte *apn, byte len, byte div);

/**
 * @return the extra byte, non-zero if overflow.
 */
byte apnMul8(byte *apn, byte len, byte mul);

//byte apnShiftLeft(byte *apn, byte len, byte n);
//byte apnShiftRight(byte *apn, byte len, byte n);

/**
 * @param buf must be large enough to hold the result string (include '\0').
 * @param len should less than 0x100 / (8/log(2,ordix)) - 1 for safe purpose.
 * @param ordix must >= 2 and <= 16
 * @return length of the result string (exclude '\0').
 */
word apnToString(char *buf, byte *apn, byte len, byte ordix);

#endif
