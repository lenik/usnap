#ifndef __TSTRING_H

#define __TSTRING_H

#include "TType.h"

class TStringClass;
  class TStringChain;
    class TStringChainFuncs;

class TStringChainFuncs{
public:
  TStringChain *Source;

public: // Change Current Nod Functions
  char _GoTop();
  char _GoBottom();
  char _GoPrev();
  char _GoNext();
  char _GoNPrev(Word Num);
  char _GoNNext(Word Num);
public:	// Test Current Nod Functions
  char IsPrevNull();
  char IsNextNull();
  char IsSomePrevNull(Word Num);
  char IsSomeNextNull(Word Num);

public:	// Copy Nod Functions
  void CopyTo(TStringChain *_CopyTo);

public:	// Insert And Delete Nod Functions
  char Push(TStringChain *_TStringChainNew);
  char Append(TStringChain *_TStringChainNew);
  char InsertBefore(TStringChain *_TStringChainNew);
  char InsertBehind(TStringChain *_TStringChainNew);
  char PushBlank();
  char AppendBlank();
  char InsertBeforeBlank();
  char InsertBehindBlank();

  char Distil();
  char Pull();
  char Delete();
  char DeletePrev();
  char DeleteNext();
  char DeleteSomePrev(Word Num);
  char DeleteSomeNext(Word Num);
  char DeleteAll();

public:	// Replace Nod Functions
  char Replace(TStringChain *_TStringChainAnother);

public:	// Swap Nod Functions
  char SwapWithNext();
  char SwapWithPrev();
  char SwapPrevWithNext();
};

char CommonSwapTStringChain(TStringChain **_TStringChainA, TStringChain **_TStringChainB);

class TStringChain{
public:
  Word MaxLength;
public:
  TStringChain *Prev;
  TStringChain *Next;
  Word Length;
  Word CurPos;
  Byte *String;

public:
  void Init();
  TStringChain();
  TStringChain(Word _InitSize);
  TStringChain(Byte *_InitStr, Word _Len);
  ~TStringChain();

public:	// General String Type Test Functions
  Byte AllAlnum();
  Byte AllAlpha();
  Byte AllAscii();
  Byte AllCntrl();
  Byte AllDigit();
  Byte AllGraph();
  Byte AllLower();
  Byte AllPrint();
  Byte AllPunct();
  Byte AllSpace();
  Byte AllUpper();
  Byte AllXDigit();

public:	// String Shift Functions
  Byte FillByte;
  void Shift(int _Len, Word _SStart, Word _SEnd);
  void ShiftCycle(int _Len, Word _SStart, Word _SEnd);

public:	// Base String Functions
  void Init(Byte *_InitStr, Word _Len);
  void Assign(Byte *_AssignStr, Word _Len);
  void Count();

  void Push(Byte *_PushStr, Word _Len);
  void Append(Byte *_AppendStr, Word _Len);
  void Insert(Byte *_InsertStr, Word _Len);
  void Distil(Word _Len);
  void Pull(Word _Len);
  void Delete(Word _Len);

  Byte *Colon(Word _Len);
  Byte *Part(Word _Len);

public:	// String Compare Functions
  int Compare(Byte *_CompareStr, Word _Len);

public:	// String Scan Functions
  TRetWord WhereByte(Byte _Byte);
  TRetWord WhereRevByte(Byte _Byte);
  TRetWord WhereStr(Byte *_Str, Word _Len);
  TRetWord WhereRevStr(Byte *_Str, Word _Len);

  TRetWord ByteDupTimes(Byte _Byte);
  TRetWord ByteOnDispTime(Byte _Byte, Word _Time);
  TRetWord ByteOnRevDispTime(Byte _Byte, Word _RevTime);
  TRetWord StrDupTimes(Byte *_Str, Word _Len);
  TRetWord StrOnDispTime(Byte *_Str, Word _Len, Word _Time);
  TRetWord StrOnRevDispTime(Byte *_Str, Word _Len, Word _RevTime);

public:	// Enhanced String Modify Functions
  void StrChange(Byte *_ValueStr, Word _Len, Word _SrcLen);

  void StrReplace(Byte *StrOld, Word _OldLen, Byte *StrNew, Word _NewLen, Word _StartScanPos);
  void StrReplaceAll(Byte *StrOld, Word _OldLen, Byte *StrNew, Word _NewLen, Word _StartScanPos);

public:	// Extra Nod Functions
  TStringChainFuncs Funcs;
};

class TStringClass{
public:
  Word MaxBlockNum;
public:
  TStringChain **ChainDesc;
  TStringChain *StringBlocks;
  Word BlockNum;
  Word CurBlock;
  Byte UnitLen;
  TVarSet Status;
  TVarSetFuncs StatusFuncs;
public:
  void Init();
  TStringClass();
  TStringClass(DWord _InitSize);
  ~TStringClass();
};

#endif