#ifndef __TDVIDEOA_H

#define __TDVIDEOA_H

#include "TopType.h"

void TGetCharMap(Word CharBegin, Word CharCount, Byte *FontStartAddr, Byte CharSet);
void TSetCharMap(Word CharBegin, Word CharCount, Byte *FontStartAddr);
void TResetCharMap(void);

void TChineseFont16(Byte Font[16][2], Byte StartAscii);
void TChineseFont32(Byte Font[16][8], Byte StartAscii);
void TChineseFont48(Byte Font[16][18], Byte StartAscii);

#endif