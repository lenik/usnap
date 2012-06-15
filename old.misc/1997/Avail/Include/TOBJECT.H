#ifndef __TOBJECT_H

#define __TOBJECT_H

#include "TopType.h"

class TObjectChain;
class TObjectChainFuncs;

class TObjectChainFuncs{
public:
  TObjectChain *Source;

public:	/* ...... */
  char GetObjectType();

public: // Change Current Node Functions
  char _GoTop();
  char _GoBottom();
  char _GoPrev();
  char _GoNext();
  char _GoNPrev(Word Num);
  char _GoNNext(Word Num);
public:	// Test Current Node Functions
  char IsPrevNull();
  char IsNextNull();
  char IsSomePrevNull(Word Num);
  char IsSomeNextNull(Word Num);

public:	// Copy Node Functions
  void CopyTo(TObjectChain *_CopyTo);

public:	// Insert And Delete Node Functions
  char Push(TObjectChain *_TObjectChainNew);
  char Append(TObjectChain *_TObjectChainNew);
  char InsertBefore(TObjectChain *_TObjectChainNew);
  char InsertBehind(TObjectChain *_TObjectChainNew);
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

public:	// Replace Node Functions
  char Replace(TObjectChain *_TObjectChainAnother);

public:	// Swap Node Functions
  char SwapWithNext();
  char SwapWithPrev();
  char SwapPrevWithNext();
};

char CommonSwapTObjectChain(TObjectChain **_TObjectChainA, TObjectChain **_TObjectChainB);

class TObjectChain{
public:
  TObjectChain *Prev;
  TObjectChain *Next;
  TObjectChain *Parent;	//Reserved
  TObjectChain *Sub;	//Reserved
  char *Name;
  char *Data;
  TObjectChain();
  ~TObjectChain();
public:
  TObjectChainFuncs Funcs;
};

#endif	//__TOBJECT_H
