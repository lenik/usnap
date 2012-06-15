#include <io.h>
#include "TopType.h"
#include "TopMData.h"

TRetByte topfileGetByte(int Handle, long Offset, int FromWhere=SEEK_SET){
  _TRetByte.r='\x0';
  _TRetByte.s=1;
  long OriginStart=tell(Handle);
  if (lseek(Handle, Offset, FromWhere)==-1L){
    _TRetByte.s=0;
    return _TRetByte;
  }
  if (read(Handle, &_TRetByte.r, 1)==-1){
    lseek(Handle, OriginStart, SEEK_SET);
    _TRetByte.r='\x0';
    _TRetByte.s=0;
    return _TRetByte;
  }
  return _TRetByte;
}

TRetWord topfileGetWord(int Handle, long Offset, int FromWhere=SEEK_SET){
  _TRetWord.r=0;
  _TRetWord.s=1;
  long OriginStart=tell(Handle);
  if (lseek(Handle, Offset, FromWhere)==-1L){
    _TRetWord.s=0;
    return _TRetWord;
  }
  if (read(Handle, &_TRetWord.r, 2)==-1){
    lseek(Handle, OriginStart, SEEK_SET);
    _TRetWord.r='\x0';
    _TRetWord.s=0;
    return _TRetWord;
  }
  _TRetWord.r=Trans2BytesToWord(_TRetWord.r>>8, _TRetWord.r&0xF);
  return _TRetWord;
}
