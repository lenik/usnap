#ifndef __TOPMDATA_H
#define __TOPMDATA_H

#include "TopType.h"

//#ifdef __cplusplus
//extern "C" {
//#endif

Word Trans2BytesToWord(Byte _Byte1, Byte _Byte2);
DWord Trans4BytesToDWord(Byte _Byte1, Byte _Byte2, Byte _Byte3, Byte _Byte4);
Byte* TransExpressToStore(Byte *_EBytes, Word Num);

//#ifdef __cplusplus
//}
//#endif

#endif	//__TOPMDATA_H
