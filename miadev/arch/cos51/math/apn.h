#ifndef __APN_H
#define __APN_H

#include "../types.h"

/**
 * If arglen is longer than len, the extra BYTEs are ignored, and 1 is returned.
 *
 * @return carry/overflow bit
 */
bool apnAdd(BYTE *apn, BYTE len, const BYTE *arg, BYTE arglen);

void apnNeg(BYTE *apn, BYTE len);

/**
 * @param div must be 0 < div ≤ 0x10
 * @return remainder. Always return 0xff if div==0 or >0x10.
 */
BYTE apnDiv4(BYTE *apn, BYTE len, BYTE div);

/**
 * @return the extra BYTE, non-zero if overflow.
 */
BYTE apnMul8(BYTE *apn, BYTE len, BYTE mul);

//BYTE apnShiftLeft(BYTE *apn, BYTE len, BYTE n);
//BYTE apnShiftRight(BYTE *apn, BYTE len, BYTE n);

/**
 * @param buf must be large enough to hold the result string (include '\0').
 * @param len should less than 0x100 / (8/log(2,ordix)) - 1 for safe purpose.
 * @param ordix must >= 2 and <= 16
 * @return length of the result string (exclude '\0').
 */
WORD apnToString(char *buf, BYTE *apn, BYTE len, BYTE ordix);

#endif
