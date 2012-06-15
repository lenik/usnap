#include <_Null.h>

#include "TopType.h"

Word _topbinMaxLen=0x1000;

Word topbinGetMaxLen(void);
void topbinSetMaxLen(Word _setMaxLen);
TRetNum topbinFindByteInString(char *Str, Byte _byte);
TRetStr topbinDistilString(char *Str, Byte _endmark);
TRetNum topbinFindInScopeInString(char *Str, Byte _MinByte, Byte _MaxByte);
TRetNum topbinFindOutScopeInString(char *Str, Byte _MinByte, Byte _MaxByte);
TRetStr topbinDistilStringInScope(char *Str, Byte _MinByte, Byte _MaxByte);
TRetStr topbinDistilStringOutScope(char *Str, Byte _MinByte, Byte _MaxByte);

Word topbinGetMaxLen(void) {
  return _topbinMaxLen;
}
void topbinSetMaxLen(Word _setMaxLen) {
  _topbinMaxLen=_setMaxLen;
}

TRetNum topbinFindByteInString(char *Str, Byte _byte) {
  Word p=0;
  _TRetNum.r=0;
  _TRetNum.s=1;
  while (p<_topbinMaxLen) {
    if (Str[p]==_byte) {
      _TRetNum.r=p;
      return _TRetNum;
    } p++;
  }
  _TRetNum.s=0;
  return _TRetNum;
}

TRetStr topbinDistilString(char *Str, Byte _endmark) {
  _TRetStr.r=NULL;
  _TRetStr.s=1;
  Byte *_Ret;
  if (!topbinFindByteInString(Str, _endmark).s) { // Cannot find _endmark
    _TRetStr.s=0;
    return _TRetStr;
  }
  if (!(_Ret=new char[_TRetNum.r+1])) {
    _TRetStr.s=0;
    return _TRetStr;
  }
  _Ret[_TRetNum.r]=0;
  while (_TRetNum.r) { // Copy
    _Ret[_TRetNum.r-1]=Str[_TRetNum.r---1];
  }
  _TRetStr.r=_Ret;
  _TRetStr.s=1;
  return _TRetStr;
}

TRetNum topbinFindInScopeInString(char *Str, Byte _MinByte, Byte _MaxByte) {
  Word p=0;
  _TRetNum.r=0;
  _TRetNum.s=1;
  while (p<_topbinMaxLen) {
    if (
	 ((_MinByte<=_MaxByte) && (
	   (Str[p]>=_MinByte) &&
	   (Str[p]<=_MaxByte)
	 )) ||
	 ((_MinByte>_MaxByte) && (
	   (Str[p]>=_MinByte) ||
	   (Str[p]<=_MaxByte)
	 ))
       ) {
      _TRetNum.r=p;
      return _TRetNum;
    } p++;
  }
  _TRetNum.s=0;	// No char In scope
  return _TRetNum;
}	// The 1st char In scope

TRetNum topbinFindOutScopeInString(char *Str, Byte _MinByte, Byte _MaxByte) {
  Word p=0;
  _TRetNum.r=0;
  _TRetNum.s=1;
  while (p<_topbinMaxLen) {
    if (
	 ((_MinByte<=_MaxByte) && (
	   (Str[p]<_MinByte) ||
	   (Str[p]>_MaxByte)
	 )) ||
	 ((_MinByte>_MaxByte) && (
	   (Str[p]<_MinByte) &&
	   (Str[p]>_MaxByte)
	 ))
       ) {
      _TRetNum.r=p;	// The 1st char out of scope
      return _TRetNum;
    } p++;
  }
  _TRetNum.s=0;	// No char Out scope
  return _TRetNum;
}

TRetStr topbinDistilStringInScope(char *Str, Byte _MinByte, Byte _MaxByte) {
  _TRetStr.r=NULL;
  _TRetStr.s=1;
  char *_Ret;
  if (!topbinFindOutScopeInString(Str, _MinByte, _MaxByte).s) { // All In Scope
    _TRetStr.s=0;
    return _TRetStr;
  }
  if (!(_Ret=new char[_TRetNum.r+1])) {
    _TRetStr.s=0;
    return _TRetStr;
  }
  _Ret[_TRetNum.r]=0;
  while (_TRetNum.r) { // Copy
    _Ret[_TRetNum.r-1]=Str[_TRetNum.r---1];
  }
  _TRetStr.r=_Ret;
  _TRetStr.s=1;
  return _TRetStr;
}

TRetStr topbinDistilStringOutScope(char *Str, Byte _MinByte, Byte _MaxByte) {
  _TRetStr.r=NULL;
  _TRetStr.s=1;
  char *_Ret;
  if (!topbinFindInScopeInString(Str, _MinByte, _MaxByte).s) { // All In Scope
    _TRetStr.s=0;
    return _TRetStr;
  }
  if (!(_Ret=new char[_TRetNum.r+1])) {
    _TRetStr.s=0;
    return _TRetStr;
  }
  _Ret[_TRetNum.r]=0;
  while (_TRetNum.r) { // Copy
    _Ret[_TRetNum.r-1]=Str[_TRetNum.r---1];
  }
  _TRetStr.r=_Ret;
  _TRetStr.s=1;
  return _TRetStr;
}

/*
#include <stdio.h>
#include <alloc.h>
void main() {
  char *test;
  DWord LC=coreleft();
  strinit(&test, "1234567890 abcdefgrstuvwxyz Hi! Every one! my telephone= 05767444659 . Welcome!");
  LC=coreleft();
  printf("\nnum:\t\t@%s\n", topbinDistilString(test, ' ').r);
  test+=topbinFindByteInString(test, ' ').r+1;
  LC=coreleft();
  printf("alpha:\t\t@%s\n", topbinDistilStringInScope(test, 'a', 'z').r);
  test+=topbinFindOutScopeInString(test, 'a', 'z').r+1;
  LC=coreleft();
  printf("Welcome:\t@%s\n", topbinDistilStringOutScope(test, '0', '9').r);
  test+=topbinFindInScopeInString(test, '0', '9').r;
  LC=coreleft();
  printf("Phone:\t\t@%s\n", topbinDistilString(test,'.').r);
  test+=topbinFindByteInString(test, '.').r+1;
  LC=coreleft();
  printf("Rest:\t\t@%s\n", topbinDistilString(test, '\x0').r);
  LC=coreleft();
  delete test;
  LC=coreleft();
}
*/
