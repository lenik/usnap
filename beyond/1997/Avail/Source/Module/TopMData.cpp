#include <_Null.h>

#include "TopType.h"

Word Trans2BytesToWord(Byte _Byte1, Byte _Byte2){
  return (Word)_Byte2<<8+_Byte1;
}

DWord Trans4BytesToDWord(Byte _Byte1, Byte _Byte2, Byte _Byte3, Byte _Byte4){
  return (DWord)((Word)_Byte4<<8+_Byte3)<<16+(Word)_Byte2<<8+_Byte1;
}

Byte* TransExpressToStore(Byte *_EBytes, Word Num){
  if (!Num) return _EBytes;
  for (Word HalfLoop=0; HalfLoop<(Num)/2-1; HalfLoop++){
    Byte _ByteSwap=_EBytes[HalfLoop];
    _EBytes[HalfLoop]=_EBytes[Num-1-HalfLoop];
    _EBytes[Num-1-HalfLoop]=_ByteSwap;
  }
  return _EBytes;
}
