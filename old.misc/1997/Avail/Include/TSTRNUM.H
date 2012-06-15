#ifndef __TSTRNUM_H
#define __TSTRNUM_H

#include "TopType.h"

//#ifdef __cplusplus
//extern "C" {
//#endif

TRetStr GetCloseNum(char *str, Word p1);
TRetStr GetCloseNotNum(char *str, Word p1);

Byte _SingleMulTable[10][10];
TRetStr PureAdd(char *StrA, char *StrB, ...);

//#ifdef __cplusplus
//}
//#endif

#endif	//__TSTRNUM_H
