#ifndef __TCHAIN_H

#define __TCHAIN_H

#include "TopType.h"

class TChainClassBase {
public:
  TChainClassBase *Prev;
  TChainClassBase *Next;
public:
  virtual void Constructor();
  virtual void Destroy();
};

template <class T> class TChainDataClassBase : public TChainClassBase {
  T Data;
};

class TChainClassBasic {
public:
  TChainClassBase *Chain;
public:	// Change Current Node Functions
  char GoTop();
  char GoBottom();
  char GoPrev();
  char GoNext();
  char GoSomePrev(Word Num);
  char GoSomeNext(Word Num);
public:	// Test Current Node Functions
  char IsPrevNull();
  char IsNextNull();
  char IsSomePrevNull(Word Num);
  char IsSomeNextNull(Word Num);
public:	// Insert And Delete Node Functions
  char Push(TChainClassBase *_TChainClassBaseNew);
  char Append(TChainClassBase *_TChainClassBaseNew);
  char Insert(TChainClassBase *_TChainClassBaseNew); //cur down, new in
  char PushBlank();
  char AppendBlank();
  char InsertBlank();
  char Distil();
  char Pull();
  char Delete(); // cur out, next in
  char DeleteSomePrev(Word Num);
  char DeleteSomeNext(Word Num);
  char DeleteAll();
  char Replace(TChainClassBase *_TChainClassBaseAnother);
public:	// Swap Node Functions
  char SwapWithPrev();
  char SwapWithNext();
  char SwapPrevWithNext();
  char SwapWithOther(TChainClassBase **_TChainClassBaseOther);
};

#endif