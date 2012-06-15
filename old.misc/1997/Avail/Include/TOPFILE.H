#ifndef __TOPFILE_H
#define __TOPFILE_H

#include "TopType.h"

extern Word _BlockSize;
extern long _FileMax;

//#ifdef __cplusplus
//extern "C" {
//#endif

Word topfileGetBlockSize(void);
void topfileSetBlockSize(Word _setBlockSize);
long topfileGetFileMax(void);
void topfileSetFileMax(long _setFileMax);

long topfileFindTillByteForward(int handle, Byte _byte);
TRetStr topfileGetStringTillByteForward(int handle, Byte _byte);

//#ifdef __cplusplus
//}
//#endif

#define topfileGetForwardASCIIZLength(handle) topfileFindTillByteForward(handle, '\x0')
#define topfileGetForwardASCIIZ(handle) topfileGetStringTillByteForward(handle, '\x0')

#endif	//__TOPFILE_H
