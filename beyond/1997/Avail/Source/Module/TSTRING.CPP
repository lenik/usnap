#include <_Null.h>
#include <errno.h>

#ifndef InCRange
#define InCRange(x,a,b)  ((x>=a)&&(x<=b))
#endif
#ifndef OutCRange
#define OutCRange(x,a,b) ((x<=a)||(x>=b))
#endif
#ifndef InORange
#define InORange(x,a,b)  ((x>a)&&(x<b))
#endif
#ifndef OutORange
#define OutORange(x,a,b) ((x<a)||(x>b))
#endif

#include <mem.h>
#include <alloc.h>
#include "TString.h"
#include "TopType.h"

void TStringChain::Init() {
  MaxLength=0x4000;
  Prev=Next=NULL;
  Length=CurPos=0;
  String=NULL;
  FillByte=0;
  Funcs.Source=this;
}
TStringChain::TStringChain() {
  Init();
}
TStringChain::TStringChain(Word _InitSize) {
  Init();
  if (_InitSize>MaxLength) _InitSize=MaxLength;
  String=new Byte[_InitSize];
  Length=_InitSize;
}
TStringChain::TStringChain(Byte *_InitStr, Word _Len) {
  Init();
  Init(_InitStr, _Len);
}
TStringChain::~TStringChain() {
  if (String!=NULL) delete String;
}

// General String Type Test Functions
Byte TStringChain::AllAlnum(void) {
  Byte *str=String;
  if (!*str) return 0xff;
  while (*str) {
    if (
	 (*str<'0') ||
	 InORange(*str, '9', 'A') ||
	 InORange(*str, 'Z', 'a') ||
	 (*str>'z')
    ) return 0;
    *str++;
  } return 1;
}

Byte TStringChain::AllAlpha(void) {
  Byte *str=String;
  if (!*str) return 0xff;
  while (*str) {
    if (
	 (*str<'A') ||
	 InORange(*str, 'Z', 'a') ||
	 (*str>'z')
    ) return 0;
    *str++;
  } return 1;
}

Byte TStringChain::AllAscii(void) {
  Byte *str=String;
  if (!*str) return 0xff;
  while (*str) {
    if (*str>>7) return 0;
    *str++;
  } return 1;
}

Byte TStringChain::AllCntrl(void) {
  Byte *str=String;
  if (!*str) return 0xff;
  while (*str) {
    if (
	 InORange(*str, 0x1f, 0x7f) ||
	 (*str>>7)
    ) return 0;
    *str++;
  } return 1;
}

Byte TStringChain::AllDigit(void) {
  Byte *str=String;
  if (!*str) return 0xff;
  while (*str) {
    if OutORange(*str, '0', '9') return 0;
    *str++;
  } return 1;
}

Byte TStringChain::AllGraph(void) {
  Byte *str=String;
  if (!*str) return 0xff;
  while (*str) {
    if (
	 (*str<0x20) ||
	 (*str>0x7e)
    ) return 0;
    *str++;
  } return 1;
}

Byte TStringChain::AllLower(void) {
  Byte *str=String;
  if (!*str) return 0xff;
  while (*str) {
    if OutORange(*str, 'a', 'z') return 0;
    *str++;
  } return 1;
}

Byte TStringChain::AllPrint(void) {
  Byte *str=String;
  if (!*str) return 0xff;
  while (*str) {
    if OutORange(*str, 0x20, 0x7e) return 0;
    *str++;
  } return 1;
}

Byte TStringChain::AllPunct(void) {
  Byte *str=String;
  if (!*str) return 0xff;
  while (*str) {
    if (
	 InORange(*str, 0x20, 0x7f) ||
	 (*str>>7)
    ) return 0;
    *str++;
  } return 1;
}

Byte TStringChain::AllSpace(void) {
  Byte *str=String;
  if (!*str) return 0xff;
  while (*str) {
    if (
	 (*str!=' ') &&
	 OutORange(*str, 0x09, 0x0d)
    ) return 0;
    *str++;
  } return 1;
}

Byte TStringChain::AllUpper(void) {
  Byte *str=String;
  if (!*str) return 0xff;
  while (*str) {
    if OutORange(*str, 'A', 'Z') return 0;
    *str++;
  } return 1;
}

Byte TStringChain::AllXDigit(void) {
  Byte *str=String;
  if (!*str) return 0xff;
  while (*str) {
    if (
	 (*str<'0') ||
	 InORange(*str, '9', 'A') ||
	 InORange(*str, 'F', 'a') ||
	 (*str>'f')
    ) return 0;
    *str++;
  } return 1;
}

// String Shift Functions
void TStringChain::Shift(int _Len, Word _SStart=0, Word _SEnd=0xFFFF) {
  if (!_Len) return;
  if (_SEnd==0xFFFF) _SEnd=Length-1;
  if (_Len>0) if (_Len>_SEnd-_SStart+1) _Len=_SEnd-_SStart+1;
  if (_Len<0) if (-_Len>_SEnd-_SStart+1) _Len=_SStart-_SEnd-1;
  if (_Len>0) {
    Byte *_StringCopy=String+_SEnd;
    Byte _Count=_SEnd-_SStart+1-_Len;
    for (; _Count>0; _Count--) *_StringCopy=*(_StringCopy---_Len);
    memset(String+_SStart, FillByte, _Len);
    CurPos+=_Len;
    if (CurPos>_SEnd) CurPos=_SEnd;
  } else {
    memcpy(String+_SStart, String+_SStart-_Len, _SEnd-_SStart+1+_Len);
    memset(String+_SEnd+_Len+1, FillByte, -_Len);
    (CurPos<_SStart-_Len)?(CurPos=_SStart):(CurPos+=_Len);
  }
}

void TStringChain::ShiftCycle(int _Len, Word _SStart=0, Word _SEnd=0xFFFF) {
  if (!_Len) return;
  if (_SEnd==0xFFFF) _SEnd=Length-1;
  _Len=_Len%(int)(_SEnd-_SStart+1);
  Byte *__Save=new Byte[_Len>0?_Len:-_Len];
  if (_Len>0) memcpy(__Save, String+_SEnd-_Len+1, _Len);
  else memcpy(__Save, String+_SStart, -_Len);
  Shift(_Len, _SStart, _SEnd);
  if (_Len>0) memcpy(String+_SStart, __Save, _Len);
  else memcpy(String+_SEnd+_Len+1, __Save, -_Len);
  delete __Save;
}

// Base String Functions
void TStringChain::Init(Byte *_InitStr, Word _Len=1) {
  if (!(String=new Byte[_Len])) return;
  Length=_Len;
  memcpy(String, _InitStr, _Len);
  _TRetStr.r=String;
}

void TStringChain::Assign(Byte *_AssignStr, Word _Len=1) {
  if (String!=NULL) delete String;
  Init(_AssignStr, _Len);
}

void TStringChain::Count() {
  Byte *_String = String;
  Length = 0;
  while (*(String++)) Length++;
  String = _String;
}

void TStringChain::Push(Byte *_PushStr, Word _Len=1) {
  if (Length+_Len>MaxLength) _Len=MaxLength-Length;
  Length+=_Len;
  String=(Byte *)realloc(String, Length);
  Shift(_Len);
  memcpy(String, _PushStr, _Len);
}

void TStringChain::Append(Byte *_AppendStr, Word _Len=1) {
  if (Length+_Len>MaxLength) _Len=MaxLength-Length;
  Length+=_Len;
  String=(Byte *)realloc(String, Length);
  memcpy(String+Length-1, _AppendStr, _Len);
}

void TStringChain::Insert(Byte *_InsertStr, Word _Len=1) {
  if (Length+_Len>MaxLength) _Len=MaxLength-Length;
  Length+=_Len;
  String=(Byte *)realloc(String, Length);
  Shift(_Len, CurPos);
  memcpy(String+CurPos-_Len, _InsertStr, _Len);
} // Insert Between [CurPos-1,CurPos].

void TStringChain::Distil(Word _Len=1) {
  if (!_Len) return;
  if (Length<_Len) _Len=Length;
  Shift(-_Len);
  Length-=_Len;
  String=(Byte *)realloc(String, Length);
}

void TStringChain::Pull(Word _Len=1) {
  if (!_Len) return;
  if (Length<_Len) _Len=Length;
  Length-=_Len;
  String=(Byte *)realloc(String, Length);
  if (CurPos>Length-1) CurPos=Length-1;
}

void TStringChain::Delete(Word _Len=1) {
  if (!_Len) return;
  if (Length<_Len) _Len=Length;
  Shift(-_Len, CurPos);
  Length-=_Len;
  String=(Byte *)realloc(String, Length);
} // Delete include String[curpos].

Byte *TStringChain::Colon(Word _Len) {
  if (!_Len) return NULL;
  if (_Len>Length-CurPos) _Len=Length-CurPos;
  Byte *_RetStr=new Byte[_Len];
  memcpy(_RetStr, String+CurPos, _Len);
  return _RetStr;
}

Byte *TStringChain::Part(Word _Len) {
  if (!_Len) return NULL;
  if (_Len>Length-CurPos) _Len=Length-CurPos;
  Byte *_RetStr=new Byte[_Len];
  memcpy(_RetStr, String+CurPos, _Len);
  Delete(_Len);
  return _RetStr;
}

// String Compare Functions
int TStringChain::Compare(Byte *_CompareStr, Word _Len) {
  Word _SaveLen=_Len;
  if (!_Len) return (Length)?1:0;
  if (Length<_Len) _Len=Length;
  for (Word _p=0; _p<_Len; _p++) {
    if (String[_p]==_CompareStr[_p]) continue;
    return (String[_p]>_CompareStr[_p])?1:-1;
  }
  if ((_p == _Len) || (Length == _SaveLen)) return 0;
  return (Length>_SaveLen)?1:-1;
} // Return: string>comparestr?1:-1, ==:0

// String Scan Functions
TRetWord TStringChain::WhereByte(Byte _Byte) {
  _TRetWord.r=0;
  _TRetWord.s=1;
  for (Word _p=0; _p<Length; _p++) {
    if (String[_p]==_Byte) {
      _TRetWord.r=_p;
      return _TRetWord;
    }
  }
  _TRetWord.s=0; // No match
  return _TRetWord;
}

TRetWord TStringChain::WhereRevByte(Byte _Byte) {
  _TRetWord.r=0;
  _TRetWord.s=1;
  for (Word _p=Length; _p>0; _p--) {
    if (String[_p-1]==_Byte) {
      _TRetWord.r=_p-1;
      return _TRetWord;
    }
  }
  _TRetWord.s=0; // No match
  return _TRetWord;
}

TRetWord TStringChain::WhereStr(Byte *_Str, Word _Len) {
  _TRetWord.r=0;
  _TRetWord.s=1;
  for (Word _p=0; _p<Length; _p++) {
    String+=_p;
    if (Compare(_Str, _Len)==0) {
      _TRetWord.r=_p;
      return _TRetWord;
    }
    String-=_p;
  }
  _TRetWord.s=0; // No match
  return _TRetWord;
}

TRetWord TStringChain::WhereRevStr(Byte *_Str, Word _Len) {
  _TRetWord.r=0;
  _TRetWord.s=1;
  for (Word _p=Length; _p>0; _p--) {
    String+=_p-1;
    if (Compare(_Str, _Len)==0) {
      _TRetWord.r=_p-1;
      return _TRetWord;
    }
    String-=_p-1;
  }
  _TRetWord.s=0; // No match
  return _TRetWord;
}

TRetWord TStringChain::ByteDupTimes(Byte _Byte) {
  _TRetWord.r=0;
  _TRetWord.s=1;
  for (Word _p=0; _p<Length; _p++) {
    if (String[_p]==_Byte) _TRetWord.r++;
  }
  return _TRetWord;
}

TRetWord TStringChain::ByteOnDispTime(Byte _Byte, Word _Time) {
  Word _Count=0;
  _TRetWord.r=0;
  _TRetWord.s=1;
  for (Word _p=0; _p<Length; _p++) {
    if (String[_p]==_Byte) {
      if (_Count++==_Time) {
	_TRetWord.r=_p;
	return _TRetWord;
      }
    }
  }
  _TRetWord.s=0; // No match
  return _TRetWord;
}

TRetWord TStringChain::ByteOnRevDispTime(Byte _Byte, Word _RevTime) {
  Word _Count=0;
  _TRetWord.r=0;
  _TRetWord.s=1;
  for (Word _p=Length; _p>0; _p--) {
    if (String[_p-1]==_Byte) {
      if (_Count++==_RevTime) {
	_TRetWord.r=_p-1;
	return _TRetWord;
      }
    }
  }
  _TRetWord.s=0; // No match
  return _TRetWord;
}

TRetWord TStringChain::StrDupTimes(Byte *_Str, Word _Len) {
  _TRetWord.r=0;
  _TRetWord.s=1;
  for (Word _p=0; _p<Length; _p++) {
    String+=_p;
    if (Compare(_Str, _Len)==0) _TRetWord.r++;
    String-=_p;
  }
  return _TRetWord;
}

TRetWord TStringChain::StrOnDispTime(Byte *_Str, Word _Len, Word _Time) {
  Word _Count=0;
  _TRetWord.r=0;
  _TRetWord.s=1;
  for (Word _p=0; _p<Length; _p++) {
    String+=_p;
    if (Compare(_Str, _Len)==0) {
      if (_Count++==_Time) {
	_TRetWord.r=_p;
	return _TRetWord;
      }
    }
    String-=_p;
  }
  _TRetWord.s=0; // No match
  return _TRetWord;
}

TRetWord TStringChain::StrOnRevDispTime(Byte *_Str, Word _Len, Word _RevTime) {
  Word _Count=0;
  _TRetWord.r=0;
  _TRetWord.s=1;
  for (Word _p=Length; _p>0; _p--) {
    String+=_p-1;
    if (Compare(_Str, _Len)==0) {
      if (_Count++==_RevTime) {
	_TRetWord.r=_p-1;
	return _TRetWord;
      }
    }
    String-=_p-1;
  }
  _TRetWord.s=0; // No match
  return _TRetWord;
}

// Enhanced String Modify Functions
void TStringChain::StrChange(Byte *_ValueStr, Word _Len, Word _SrcLen) {
  if (_SrcLen>Length-CurPos) {
    _Len-=_SrcLen-(Length-CurPos);
    _SrcLen=Length-CurPos;
  }
  if (_Len>_SrcLen) {
    if (_Len-_SrcLen>MaxLength-Length) {
      _Len=MaxLength-Length+_SrcLen;
    }
  }
  Delete(_SrcLen);
  Insert(_ValueStr, _Len);
}

/*
TRetStr StrReplace(Byte *StrOld, Word _OldLen, Byte *StrNew, Word _NewLen, Word _StartScanPos) {
TRetStr StrReplaceAll(Byte *StrOld, Word _OldLen, Byte *StrNew, Word _NewLen, Word _StartScanPos) {
*/

// Change Current Nod Functions
char TStringChainFuncs::_GoTop(void) {
  if (Source==NULL) return 0;
  while (Source->Prev!=NULL) Source=Source->Prev;
  return 1;
}

char TStringChainFuncs::_GoBottom(void) {
  if (Source==NULL) return 0;
  while (Source->Next!=NULL) Source=Source->Next;
  return 1;
}

char TStringChainFuncs::_GoPrev(void) {
  if (IsPrevNull()) return 0;
  Source=Source->Prev;
  return 1;
}

char TStringChainFuncs::_GoNext() {
  if (IsNextNull()) return 0;
  Source=Source->Next;
  return 1;
}

char TStringChainFuncs::_GoNPrev(Word Num) {
  if (Source==NULL) return 0;
  while ((Num--)&&(Source->Prev!=NULL)) Source=Source->Prev;
  return 1;
}

char TStringChainFuncs::_GoNNext(Word Num) {
  if (Source==NULL) return 0;
  while ((Num--)&&(Source->Next!=NULL)) Source=Source->Next;
  return 1;
}

// Test Current Nod Functions
char TStringChainFuncs::IsPrevNull(void) {
  return ((Source==NULL)||(Source->Prev==NULL))?1:0;
}

char TStringChainFuncs::IsNextNull(void) {
  return ((Source==NULL)||(Source->Next==NULL))?1:0;
}

char TStringChainFuncs::IsSomePrevNull(Word Num) {
  if (Source==NULL) return 1;
  char IsNull=0;
  while (Num--) {
    if (Source->Prev==NULL) {
      IsNull=1;
      break;
    }Source=Source->Prev;
  }
  return IsNull;
}

char TStringChainFuncs::IsSomeNextNull(Word Num) {
  if (Source==NULL) return 1;
  char IsNull=0;
  while (Num--) {
    if (Source->Next==NULL) {
      IsNull=1;
      break;
    }Source=Source->Next;
  }
  return IsNull;
}

// Copy Nod Functions
void TStringChainFuncs::CopyTo(TStringChain *_CopyTo) {
  _CopyTo->Prev=Source->Prev;
  _CopyTo->Next=Source->Next;
  _CopyTo->String=Source->String;
  _CopyTo->Length=Source->Length;
  _CopyTo->CurPos=Source->CurPos;
}// Only Copy the Pointers in Source To _CopyTo

// Insert And Delete Nod Functions
char TStringChainFuncs::Push(TStringChain *_TStringChainNew) {
  TStringChain *_OriPoint=Source;
  if (!_TStringChainNew->Funcs._GoBottom()) return 0;
  if (!_GoTop()) Source=_TStringChainNew;
  else {
    Source->Prev=_TStringChainNew;
    _TStringChainNew->Next=Source;
    Source=_OriPoint;
  }
  return 1;
}
char TStringChainFuncs::Append(TStringChain *_TStringChainNew) {
  TStringChain *_OriPoint=Source;
  if (!_TStringChainNew->Funcs._GoTop()) return 0;
  if (!_GoBottom()) Source=_TStringChainNew;
  else {
    Source->Next=_TStringChainNew;
    _TStringChainNew->Prev=Source;
    Source=_OriPoint;
  }
  return 1;
}
char TStringChainFuncs::InsertBefore(TStringChain *_TStringChainNew) {
  TStringChain *_OriPoint=Source;
  if (!_TStringChainNew->Funcs._GoBottom()) return 0;
  if (Source==NULL) Source=_TStringChainNew;
  else {
    _TStringChainNew->Next=Source;
    if (IsPrevNull()) {
      Source->Prev=_TStringChainNew;
    } else {
      Source=Source->Prev;
      Source->Next->Prev=_TStringChainNew;
      _TStringChainNew->Funcs._GoTop();
      _TStringChainNew->Prev=Source;
      Source->Next=_TStringChainNew;
    } Source=_OriPoint;
  }
  return 1;
}// Insert before current nod
char TStringChainFuncs::InsertBehind(TStringChain *_TStringChainNew) {
  TStringChain *_OriPoint=Source;
  if (!_TStringChainNew->Funcs._GoTop()) return 0;
  if (Source==NULL) Source=_TStringChainNew;
  else {
    _TStringChainNew->Prev=Source;
    if (IsNextNull()) {
      Source->Next=_TStringChainNew;
    } else {
      Source=Source->Next;
      Source->Prev->Next=_TStringChainNew;
      _TStringChainNew->Funcs._GoBottom();
      _TStringChainNew->Next=Source;
      Source->Prev=_TStringChainNew;
    } Source=_OriPoint;
  }
  return 1;
}// Insert behind current nod

char TStringChainFuncs::PushBlank(void) {
  TStringChain *_BlankTStringChain;
  if (!(_BlankTStringChain=new TStringChain)) return 0;
  return Push(_BlankTStringChain);
}

char TStringChainFuncs::AppendBlank(void) {
  TStringChain *_BlankTStringChain;
  if (!(_BlankTStringChain=new TStringChain)) return 0;
  return Append(_BlankTStringChain);
}

char TStringChainFuncs::InsertBeforeBlank(void) {
  TStringChain *_BlankTStringChain;
  if (!(_BlankTStringChain=new TStringChain)) return 0;
  return InsertBefore(_BlankTStringChain);
}

char TStringChainFuncs::InsertBehindBlank(void) {
  TStringChain *_BlankTStringChain;
  if (!(_BlankTStringChain=new TStringChain)) return 0;
  return InsertBehind(_BlankTStringChain);
}

char TStringChainFuncs::Distil(void) {
  TStringChain *_OriPoint=Source;
  if (IsPrevNull()) _OriPoint=Source->Next;
  if (!_GoTop()) return 0;
  if (Source->Next==NULL) {
    delete Source;
    Source=NULL;
  } else {
    Source=Source->Next;
    delete Source->Prev;
    Source->Prev=NULL;
    Source=_OriPoint;
  }
  return 1;
}

char TStringChainFuncs::Pull(void) {
  TStringChain *_OriPoint=Source;
  if (IsNextNull()) _OriPoint=Source->Prev;
  if (!_GoBottom()) return 0;
  if (Source->Prev==NULL) {
    delete Source;
    Source=NULL;
  } else {
    Source=Source->Prev;
    delete Source->Next;
    Source->Next=NULL;
    Source=_OriPoint;
  }
  return 1;
}

char TStringChainFuncs::Delete(void) {
  TStringChain *_OriPoint=Source;
  if (Source==NULL) return 0;
  if (!IsPrevNull()) {
    Source->Prev->Next=Source->Next;
  }
  if (!IsNextNull()) {
    Source->Next->Prev=Source->Prev;
  }
  if (!IsNextNull()) {
    Source=Source->Next;
    delete _OriPoint;
  } else if (!IsPrevNull()) {
    Source=Source->Prev;
    delete _OriPoint;
  } else {
    delete Source;
    Source=NULL;
  }
  return 1;
}

char TStringChainFuncs::DeletePrev(void) {
  if (!IsPrevNull()) return 0;
  TStringChain *_OriPointPrev=Source->Prev;
  if (_OriPointPrev->Funcs.IsPrevNull()) {
    delete _OriPointPrev;
    Source->Prev=NULL;
  } else {
    _OriPointPrev->Prev->Next=Source;
    Source->Prev=_OriPointPrev->Prev;
    delete _OriPointPrev;
  }
  return 1;
}// Delete the nod before current nod

char TStringChainFuncs::DeleteNext(void) {
  if (!IsNextNull()) return 0;
  TStringChain *_OriPointNext=Source->Next;
  if (_OriPointNext->Funcs.IsNextNull()) {
    delete _OriPointNext;
    Source->Next=NULL;
  } else {
    _OriPointNext->Next->Prev=Source;
    Source->Next=_OriPointNext->Next;
    delete _OriPointNext;
  }
  return 1;
}// Delete the nod behind current nod

char TStringChainFuncs::DeleteSomePrev(Word Num) {
  if (IsPrevNull()) return 0;
  TStringChain *_OriPoint=Source;
  while ((Num--)&&(Source!=NULL)) {
    TStringChain *_LastTStringChain=Source;
    Source=Source->Prev;
    delete _LastTStringChain;
  }
  if (Source==NULL) _OriPoint->Prev=NULL;
  else {
    Source->Next=_OriPoint;
    _OriPoint->Prev=Source;
  }
  return 1;
}

char TStringChainFuncs::DeleteSomeNext(Word Num) {
  if (IsNextNull()) return 0;
  TStringChain *_OriPoint=Source;
  while ((Num--)&&(Source!=NULL)) {
    TStringChain *_LastTStringChain=Source;
    Source=Source->Next;
    delete _LastTStringChain;
  }
  if (Source==NULL) _OriPoint->Next=NULL;
  else {
    Source->Prev=_OriPoint;
    _OriPoint->Next=Source;
  }
  return 1;
}

char TStringChainFuncs::DeleteAll(void) {
  if (!_GoTop()) return 0;
  while (!IsNextNull()) {
    Source=Source->Next;
    delete Source->Prev;
  } delete Source;
  Source=NULL;
  return 1;
}

// Replace Nod Functions
char TStringChainFuncs::Replace(TStringChain *_TStringChainAnother) {
  TStringChain *_OriPoint=Source;
  if (!Delete()) return 0;
  InsertBefore(_TStringChainAnother);
  Source=_OriPoint;
  return 1;
}

// Swap Nod Functions
char TStringChainFuncs::SwapWithNext(void) {
  if (IsNextNull()) return 0;
  TStringChain *_OriPointNext=Source->Next;
  Source->Prev->Next=_OriPointNext;
  Source->Next=_OriPointNext->Next;
  _OriPointNext->Next=_OriPointNext->Prev;
  _OriPointNext->Prev=Source->Prev;
  Source->Prev=_OriPointNext;
  Source->Next->Prev=Source;
  return 1;
}// swap current nod with next nod !!! Note the nods behind current decreased!!!

char TStringChainFuncs::SwapWithPrev(void) {
  if (IsPrevNull()) return 0;
  TStringChain *_OriPointPrev=Source->Prev;
  Source->Next->Prev=_OriPointPrev;
  Source->Prev=_OriPointPrev->Prev;
  _OriPointPrev->Prev=_OriPointPrev->Next;
  _OriPointPrev->Next=Source->Next;
  Source->Next=_OriPointPrev;
  Source->Prev->Next=Source;
  return 1;
}// swap current nod with prev nod !!! Note the nods before current decreased !!!

char TStringChainFuncs::SwapPrevWithNext(void) {
  if (IsNextNull()||IsPrevNull()) return 0;
  TStringChain *_Before=Source->Prev, *_Behind=Source->Next;
  _Before->Prev->Next=_Behind;
  _Before->Next=_Behind->Next;
  _Behind->Next->Prev=_Before;
  _Behind->Prev=_Before->Prev;
  Source->Next=_Before;
  _Behind->Next=Source;
  Source->Prev=_Behind;
  _Before->Prev=Source;
  return 1;
}// swap the two nod beside current nod

char CommonSwapTStringChain(TStringChain **SourceA, TStringChain **SourceB) {
  if ((SourceA==NULL)||(SourceB==NULL)) return 0;
  TStringChain *SourceANext=(*SourceA)->Next;
  TStringChain *SourceBNext=(*SourceB)->Next;
  TStringChain *SourceC;
  SourceC=(*SourceA)->Prev->Next;
  (*SourceA)->Prev->Next=(*SourceB)->Prev->Next;
  (*SourceB)->Prev->Next=SourceC;
  SourceC=(*SourceA)->Next;
  (*SourceA)->Next=(*SourceB)->Next;
  (*SourceB)->Next=SourceC;
  SourceC=SourceANext->Prev;
  SourceANext->Prev=SourceBNext->Prev;
  SourceBNext->Prev=SourceC;
  SourceC=(*SourceA)->Prev;
  (*SourceA)->Prev=(*SourceB)->Prev;
  (*SourceB)->Prev=SourceC;
  SourceC=*SourceA;
  *SourceA=*SourceB;
  *SourceB=SourceC;
  return 1;
}

// TStringClass
TStringClass::TStringClass() {
  ChainDesc=NULL;
  StringBlocks=NULL;
  BlockNum=CurBlock=0;
  UnitLen=1;
  StatusFuncs.Clear(&Status);
}
TStringClass::TStringClass(DWord _InitSize) {
  TStringClass();
  if (_InitSize<1L) return;
  ChainDesc=new TStringChain*[(Word)((_InitSize-1)/StringBlocks->MaxLength+1)];
  for (; ; _InitSize-=StringBlocks->MaxLength) {
    BlockNum++;
    if (_InitSize<=StringBlocks->MaxLength) {
      StringBlocks->Funcs.Append(new TStringChain((Word)_InitSize));
      break;
    } else {
      StringBlocks->Funcs.Append(new TStringChain(StringBlocks->MaxLength));
    } ChainDesc[BlockNum-1]=StringBlocks;
  }
}
TStringClass::~TStringClass() {
  if (StringBlocks!=NULL) StringBlocks->Funcs.DeleteAll();
  if (ChainDesc!=NULL) { // Actually, if stringblocks not NULL, the ChainDesc of course not NULL.
    delete ChainDesc;
  }
}
