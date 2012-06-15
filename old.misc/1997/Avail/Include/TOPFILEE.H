#ifndef __TOPFILEE_H
#define __TOPFILEE_H

#include "TopType.h"

//#ifdef __cplusplus
//extern "C" {
//#endif

TRetByte topfileGetByte(int Handle, long Offset, int FromWhere);
TRetWord topfileGetWord(int Handle, long Offset, int FromWhere);

//#ifdef __cplusplus
//}
//#endif

#endif	//__TOPFILEE_H
