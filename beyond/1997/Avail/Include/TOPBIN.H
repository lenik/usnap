#ifndef __TOPBIN_H
#define __TOPBIN_H

#include "TopType.h"

#define topbinDistilASCIIZ(str, __endtype) topbinDistilString(str, '\x0')

extern Word _topbinMaxLen;

//#ifdef __cplusplus
//extern "C" {
//#endif

Word topbinGetMaxLen(void);
void topbinSetMaxLen(Word _setMaxLen);
TRetNum topbinFindByteInString(char *Str, Byte _byte);
TRetStr topbinDistilString(char *Str, Byte _endmark);
TRetNum topbinFindInScopeInString(char *Str, Byte _MinByte, Byte _MaxByte);
TRetNum topbinFindOutScopeInString(char *Str, Byte _MinByte, Byte _MaxByte);
TRetStr topbinDistilStringInScope(char *Str, Byte _MinByte, Byte _MaxByte);
TRetStr topbinDistilStringOutScope(char *Str, Byte _MinByte, Byte _MaxByte);

//#ifdef __cplusplus
//}
//#endif

#endif	//__TOPBIN_H
