#include <_Null.h>
#include <io.h>
#include <fcntl.h>

#include "TopBin.h"

Word _BlockSize=0x1000;		// 4k
long _FileMax=0x7FFF0000;	// 2G Max!

Word topfileGetBlockSize(void);
void topfileSetBlockSize(Word _setBlockSize);
long topfileGetFileMax(void);
void topfileSetFileMax(long _setFileMax);

long topfileFindTillByteForward(int handle, Byte _byte);
TRetStr topfileGetStringTillByteForward(int handle, Byte _byte);

Word topfileGetBlockSize(void) {
  return _BlockSize;
}
void topfileSetBlockSize(Word _setBlockSize) {
  if (_setBlockSize<=_FileMax) _BlockSize=_setBlockSize;
}
long topfileGetFileMax(void) {
  return _FileMax;
}
void topfileSetFileMax(long _setFileMax) {
  if (_setFileMax>=_BlockSize) _FileMax=_setFileMax;
}

long topfileFindTillByteForward(int handle, Byte _byte) {
  void *Buf;
  long len=0;
  long Restore=0;
  if ((Restore=tell(handle))==-1) return 0;
  while (len<=_FileMax-_BlockSize) {
    if (
	 (!(Buf=new char[_BlockSize+1])) ||
	 (read(handle, Buf, _BlockSize)==-1) // Memory out or File not exist
    ) {
      lseek(handle, Restore, SEEK_SET);
      return 0;
    } else {
      ((char *)Buf)[_BlockSize]=0;
      topbinSetMaxLen(_BlockSize);
      if (!topbinFindByteInString((char *)Buf, _byte).s) { // More Data...
	len+=_BlockSize;
	delete Buf;
	continue;
      } else {
	len+=_TRetNum.r;
	delete Buf;
	lseek(handle, Restore, SEEK_SET);
	return len; // The position relative to current
      } // Deal with block
    } // Read success
  } // loop
  lseek(handle, Restore, SEEK_SET);
  return 0; // Haven't found
}

#define topfileGetForwardASCIIZLength(handle) topfileFindTillByteForward(handle, '\x0')

TRetStr topfileGetStringTillByteForward(int handle, Byte _byte) {
  void *_RetStr;
  long len=topfileFindTillByteForward(handle, _byte)+1;
  _TRetStr.r=NULL;
  _TRetStr.s=1;
  if (
       (len==0) ||
       (!(_RetStr=new char[len])) ||
       (read(handle, _RetStr, len)==-1)
  ) {
    _TRetStr.s=0;
    return _TRetStr;
  } else {
    _TRetStr.r=(char *)_RetStr;
    return _TRetStr;
  }
}

#define topfileGetForwardASCIIZ(handle) topfileGetStringTillByteForward(handle, '\x0')

/*
#include <stdio.h>
void main() {
  int test;
  test=open("test\\Text01.", O_BINARY|O_RDONLY);
  long aa=tell(test);
  topfileGetStringTillByteForward(test, 'W');
  aa=tell(test);
  lseek(test,0,SEEK_SET);
  _TRetStr.r[topfileFindTillByteForward(test, 'W')]=0;
  aa=tell(test);
  printf("%send.\n", _TRetStr.r);
  close(test);
}
*/