#include "TChain.h"

void TChainClassBase::Constructor() {
  Prev=Next=NULL;
}

void TChainClassBase::Destroy() {
  if (Prev!=NULL) Prev->Destroy();
  if (Next!=NULL) Next->Destroy();
}

// Change Current Node Functions
char TChainClassBasic::GoTop(void) {
  if (Chain==NULL) return 0;
  while (Chain->Prev!=NULL) Chain=Chain->Prev;
  return 1;
}
char TChainClassBasic::GoBottom(void) {
  if (Chain==NULL) return 0;
  while (Chain->Next!=NULL) Chain=Chain->Next;
  return 1;
}
char TChainClassBasic::GoPrev(void) {
  if (IsPrevNull()) return 0;
  Chain=Chain->Prev;
  return 1;
}
char TChainClassBasic::GoNext() {
  if (IsNextNull()) return 0;
  Chain=Chain->Next;
  return 1;
}
char TChainClassBasic::GoSomePrev(Word Num) {
  if (Chain==NULL) return 0;
  while ((Num--)&&(Chain->Prev!=NULL)) Chain=Chain->Prev;
  return 1;
}
char TChainClassBasic::GoSomeNext(Word Num) {
  if (Chain==NULL) return 0;
  while ((Num--)&&(Chain->Next!=NULL)) Chain=Chain->Next;
  return 1;
}

// Test Current Node Functions
char TChainClassBasic::IsPrevNull(void) {
  return ((Chain==NULL)||(Chain->Prev==NULL))?1:0;
}
char TChainClassBasic::IsNextNull(void) {
  return ((Chain==NULL)||(Chain->Next==NULL))?1:0;
}
char TChainClassBasic::IsSomePrevNull(Word Num) {
  if (Chain==NULL) return 1;
  char IsNull=0;
  while (Num--) {
    if (Chain->Prev==NULL) {
      IsNull=1;
      break;
    }Chain=Chain->Prev;
  }
  return IsNull;
}
char TChainClassBasic::IsSomeNextNull(Word Num) {
  if (Chain==NULL) return 1;
  char IsNull=0;
  while (Num--) {
    if (Chain->Next==NULL) {
      IsNull=1;
      break;
    }Chain=Chain->Next;
  }
  return IsNull;
}

// Insert And Delete Node Functions
char TChainClassBasic::Push(TChainClassBase *_TChainClassBaseNew) {
  TChainClassBase *_OriPoint=Chain;
  if (!_TChainClassBaseNew->GoBottom()) return 0;
  if (!GoTop()) Chain=_TChainClassBaseNew;
  else {
    Chain->Prev=_TChainClassBaseNew;
    _TChainClassBaseNew->Next=Chain;
    Chain=_OriPoint;
  }
  return 1;
}
char TChainClassBasic::Append(TChainClassBase *_TChainClassBaseNew) {
  TChainClassBase *_OriPoint=Chain;
  if (!_TChainClassBaseNew->GoTop()) return 0;
  if (!GoBottom()) Chain=_TChainClassBaseNew;
  else {
    Chain->Next=_TChainClassBaseNew;
    _TChainClassBaseNew->Prev=Chain;
    Chain=_OriPoint;
  }
  return 1;
}
char TChainClassBasic::Insert(TChainClassBase *_TChainClassBaseNew) {
  TChainClassBase *_OriPoint=Chain;
  if (!_TChainClassBaseNew->GoBottom()) return 0;
  if (Chain==NULL) Chain=_TChainClassBaseNew;
  else {
    _TChainClassBaseNew->Next=Chain;
    if (IsPrevNull()) {
      Chain->Prev=_TChainClassBaseNew;
    } else {
      Chain=Chain->Prev;
      Chain->Next->Prev=_TChainClassBaseNew;
      _TChainClassBaseNew->GoTop();
      _TChainClassBaseNew->Prev=Chain;
      Chain->Next=_TChainClassBaseNew;
    } Chain=_OriPoint;
  }
  return 1;
}
char TChainClassBasic::PushBlank(void) {
  TChainClassBase *_BlankTChainClassBase;
  if (!(_BlankTChainClassBase=new TChainClassBase)) return 0;
  return Push(_BlankTChainClassBase);
}
char TChainClassBasic::AppendBlank(void) {
  TChainClassBase *_BlankTChainClassBase;
  if (!(_BlankTChainClassBase=new TChainClassBase)) return 0;
  return Append(_BlankTChainClassBase);
}
char TChainClassBasic::InsertBlank(void) {
  TChainClassBase *_BlankTChainClassBase;
  if (!(_BlankTChainClassBase=new TChainClassBase)) return 0;
  return InsertBefore(_BlankTChainClassBase);
}
char TChainClassBasic::Distil(void) {
  TChainClassBase *_OriPoint=Chain;
  if (IsPrevNull()) _OriPoint=Chain->Next;
  if (!GoTop()) return 0;
  if (Chain->Next==NULL) {
    delete Chain;
    Chain=NULL;
  } else {
    Chain=Chain->Next;
    delete Chain->Prev;
    Chain->Prev=NULL;
    Chain=_OriPoint;
  }
  return 1;
}
char TChainClassBasic::Pull(void) {
  TChainClassBase *_OriPoint=Chain;
  if (IsNextNull()) _OriPoint=Chain->Prev;
  if (!GoBottom()) return 0;
  if (Chain->Prev==NULL) {
    delete Chain;
    Chain=NULL;
  } else {
    Chain=Chain->Prev;
    delete Chain->Next;
    Chain->Next=NULL;
    Chain=_OriPoint;
  }
  return 1;
}
char TChainClassBasic::Delete(void) {
  TChainClassBase *_OriPoint=Chain;
  if (Chain==NULL) return 0;
  if (!IsPrevNull()) {
    Chain->Prev->Next=Chain->Next;
  }
  if (!IsNextNull()) {
    Chain->Next->Prev=Chain->Prev;
  }
  if (!IsNextNull()) {
    Chain=Chain->Next;
    delete _OriPoint;
  } else if (!IsPrevNull()) {
    Chain=Chain->Prev;
    delete _OriPoint;
  } else {
    delete Chain;
    Chain=NULL;
  }
  return 1;
}
char TChainClassBasic::DeleteSomePrev(Word Num) {
  if (IsPrevNull()) return 0;
  TChainClassBase *_OriPoint=Chain;
  while ((Num--)&&(Chain!=NULL)) {
    TChainClassBase *_LastTChainClassBase=Chain;
    Chain=Chain->Prev;
    delete _LastTChainClassBase;
  }
  if (Chain==NULL) _OriPoint->Prev=NULL;
  else {
    Chain->Next=_OriPoint;
    _OriPoint->Prev=Chain;
  }
  return 1;
}
char TChainClassBasic::DeleteSomeNext(Word Num) {
  if (IsNextNull()) return 0;
  TChainClassBase *_OriPoint=Chain;
  while ((Num--)&&(Chain!=NULL)) {
    TChainClassBase *_LastTChainClassBase=Chain;
    Chain=Chain->Next;
    delete _LastTChainClassBase;
  }
  if (Chain==NULL) _OriPoint->Next=NULL;
  else {
    Chain->Prev=_OriPoint;
    _OriPoint->Next=Chain;
  }
  return 1;
}
char TChainClassBasic::DeleteAll(void) {
  if (!GoTop()) return 0;
  while (!IsNextNull()) {
    Chain=Chain->Next;
    delete Chain->Prev;
  } delete Chain;
  Chain=NULL;
  return 1;
}
char TChainClassBasic::Replace(TChainClassBase *_TChainClassBaseAnother) {
  TChainClassBase *_OriPoint=Chain;
  if (!Delete()) return 0;
  InsertBefore(_TChainClassBaseAnother);
  Chain=_OriPoint;
  return 1;
}

// Swap Node Functions
char TChainClassBasic::SwapWithPrev(void) {
  if (IsPrevNull()) return 0;
  TChainClassBase *_OriPointPrev=Chain->Prev;
  Chain->Next->Prev=_OriPointPrev;
  Chain->Prev=_OriPointPrev->Prev;
  _OriPointPrev->Prev=_OriPointPrev->Next;
  _OriPointPrev->Next=Chain->Next;
  Chain->Next=_OriPointPrev;
  Chain->Prev->Next=Chain;
  return 1;
}// swap current Node with prev Node !!! Note the nods before current decreased !!!
char TChainClassBasic::SwapWithNext(void) {
  if (IsNextNull()) return 0;
  TChainClassBase *_OriPointNext=Chain->Next;
  Chain->Prev->Next=_OriPointNext;
  Chain->Next=_OriPointNext->Next;
  _OriPointNext->Next=_OriPointNext->Prev;
  _OriPointNext->Prev=Chain->Prev;
  Chain->Prev=_OriPointNext;
  Chain->Next->Prev=Chain;
  return 1;
}// swap current Node with next Node !!! Note the nods behind current decreased!!!
char TChainClassBasic::SwapPrevWithNext(void) {
  if (IsNextNull()||IsPrevNull()) return 0;
  TChainClassBase *_Before=Chain->Prev, *_Behind=Chain->Next;
  _Before->Prev->Next=_Behind;
  _Before->Next=_Behind->Next;
  _Behind->Next->Prev=_Before;
  _Behind->Prev=_Before->Prev;
  Chain->Next=_Before;
  _Behind->Next=Chain;
  Chain->Prev=_Behind;
  _Before->Prev=Chain;
  return 1;
}// swap the two Node beside current Node
char TChainClassBasic::SwapWithOther(TChainClassBase **_TChainClassBaseOther) {
  if (_TChainClassBaseOther==NULL) return 0;
  TChainClassBase ChainNext=Chain->Next;
  TChainClassBase *_TChainClassBaseOtherNext=(*_TChainClassBaseOther)->Next;
  TChainClassBase *ChainC;
  ChainC=Chain->Prev->Next;
  Chain->Prev->Next=(*_TChainClassBaseOther)->Prev->Next;
  (*_TChainClassBaseOther)->Prev->Next=ChainC;
  ChainC=Chain->Next;
  Chain->Next=(*_TChainClassBaseOther)->Next;
  (*_TChainClassBaseOther)->Next=ChainC;
  ChainC=ChainNext->Prev;
  ChainNext->Prev=_TChainClassBaseOtherNext->Prev;
  _TChainClassBaseOtherNext->Prev=ChainC;
  ChainC=Chain->Prev;
  Chain->Prev=(*_TChainClassBaseOther)->Prev;
  (*_TChainClassBaseOther)->Prev=ChainC;
  ChainC=Chain;
  Chain=*_TChainClassBaseOther;
  *_TChainClassBaseOther=ChainC;
  return 1;
}
