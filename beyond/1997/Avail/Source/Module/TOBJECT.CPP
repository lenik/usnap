#include <_Null.h>

#include "TObject.h"

TObjectChain::TObjectChain(void) {
  Prev=Next=Parent=Sub=NULL;
  Name=Data=NULL;
  Funcs.Source=this;
}
TObjectChain::~TObjectChain(void) {
  if (Name!=NULL) delete Name;
  if (Data!=NULL) delete Data;
  if ((Parent!=NULL)&&(Parent->Sub==this)) {
    if (!Funcs.IsPrevNull()) Parent->Sub=Prev;
    else if (!Funcs.IsNextNull()) Parent->Sub=Next;
    else Parent->Sub=NULL;
  }
  if (Sub!=NULL) Sub->Funcs.DeleteAll();
}

char TObjectChainFuncs::GetObjectType() {
  return (Source->Data[0]>>5);
}

char TObjectChainFuncs::_GoTop(void) {
  if (Source==NULL) return 0;
  while (Source->Prev!=NULL) Source=Source->Prev;
  return 1;
}
char TObjectChainFuncs::_GoBottom(void) {
  if (Source==NULL) return 0;
  while (Source->Next!=NULL) Source=Source->Next;
  return 1;
}
char TObjectChainFuncs::_GoPrev(void) {
  if (IsPrevNull()) return 0;
  Source=Source->Prev;
  return 1;
}
char TObjectChainFuncs::_GoNext() {
  if (IsNextNull()) return 0;
  Source=Source->Next;
  return 1;
}
char TObjectChainFuncs::_GoNPrev(Word Num) {
  if (Source==NULL) return 0;
  while ((Num--)&&(Source->Prev!=NULL)) Source=Source->Prev;
  return 1;
}
char TObjectChainFuncs::_GoNNext(Word Num) {
  if (Source==NULL) return 0;
  while ((Num--)&&(Source->Next!=NULL)) Source=Source->Next;
  return 1;
}

char TObjectChainFuncs::IsPrevNull(void) {
  return ((Source==NULL)||(Source->Prev==NULL))?1:0;
}
char TObjectChainFuncs::IsNextNull(void) {
  return ((Source==NULL)||(Source->Next==NULL))?1:0;
}
char TObjectChainFuncs::IsSomePrevNull(Word Num) {
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
char TObjectChainFuncs::IsSomeNextNull(Word Num) {
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

void TObjectChainFuncs::CopyTo(TObjectChain *_CopyTo) {
  _CopyTo->Prev=Source->Prev;
  _CopyTo->Next=Source->Next;
  _CopyTo->Parent=Source->Parent;
  _CopyTo->Sub=Source->Sub;
  _CopyTo->Name=Source->Name;
  _CopyTo->Data=Source->Data;
}// Only Copy the Pointers in Source To _CopyTo

char TObjectChainFuncs::Push(TObjectChain *_TObjectChainNew) {
  TObjectChain *_OriPoint=Source;
  if (!_TObjectChainNew->Funcs._GoBottom()) return 0;
  if (!_GoTop()) Source=_TObjectChainNew;
  else {
    Source->Prev=_TObjectChainNew;
    _TObjectChainNew->Next=Source;
    Source=_OriPoint;
  }
  return 1;
}
char TObjectChainFuncs::Append(TObjectChain *_TObjectChainNew) {
  TObjectChain *_OriPoint=Source;
  if (!_TObjectChainNew->Funcs._GoTop()) return 0;
  if (!_GoBottom()) Source=_TObjectChainNew;
  else {
    Source->Next=_TObjectChainNew;
    _TObjectChainNew->Prev=Source;
    Source=_OriPoint;
  }
  return 1;
}
char TObjectChainFuncs::InsertBefore(TObjectChain *_TObjectChainNew) {
  TObjectChain *_OriPoint=Source;
  if (!_TObjectChainNew->Funcs._GoBottom()) return 0;
  if (Source==NULL) Source=_TObjectChainNew;
  else {
    _TObjectChainNew->Next=Source;
    if (IsPrevNull()) {
      Source->Prev=_TObjectChainNew;
    } else {
      Source=Source->Prev;
      Source->Next->Prev=_TObjectChainNew;
      _TObjectChainNew->Funcs._GoTop();
      _TObjectChainNew->Prev=Source;
      Source->Next=_TObjectChainNew;
    } Source=_OriPoint;
  }
  return 1;
}// Insert before current Node
char TObjectChainFuncs::InsertBehind(TObjectChain *_TObjectChainNew) {
  TObjectChain *_OriPoint=Source;
  if (!_TObjectChainNew->Funcs._GoTop()) return 0;
  if (Source==NULL) Source=_TObjectChainNew;
  else {
    _TObjectChainNew->Prev=Source;
    if (IsNextNull()) {
      Source->Next=_TObjectChainNew;
    } else {
      Source=Source->Next;
      Source->Prev->Next=_TObjectChainNew;
      _TObjectChainNew->Funcs._GoBottom();
      _TObjectChainNew->Next=Source;
      Source->Prev=_TObjectChainNew;
    } Source=_OriPoint;
  }
  return 1;
}// Insert behind current Node

char TObjectChainFuncs::PushBlank(void) {
  TObjectChain *_BlankTObjectChain;
  if (!(_BlankTObjectChain=new TObjectChain)) return 0;
  return Push(_BlankTObjectChain);
}
char TObjectChainFuncs::AppendBlank(void) {
  TObjectChain *_BlankTObjectChain;
  if (!(_BlankTObjectChain=new TObjectChain)) return 0;
  return Append(_BlankTObjectChain);
}
char TObjectChainFuncs::InsertBeforeBlank(void) {
  TObjectChain *_BlankTObjectChain;
  if (!(_BlankTObjectChain=new TObjectChain)) return 0;
  return InsertBefore(_BlankTObjectChain);
}
char TObjectChainFuncs::InsertBehindBlank(void) {
  TObjectChain *_BlankTObjectChain;
  if (!(_BlankTObjectChain=new TObjectChain)) return 0;
  return InsertBehind(_BlankTObjectChain);
}

char TObjectChainFuncs::Distil(void) {
  TObjectChain *_OriPoint=Source;
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
char TObjectChainFuncs::Pull(void) {
  TObjectChain *_OriPoint=Source;
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
char TObjectChainFuncs::Delete(void) {
  TObjectChain *_OriPoint=Source;
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
char TObjectChainFuncs::DeletePrev(void) {
  if (!IsPrevNull()) return 0;
  TObjectChain *_OriPointPrev=Source->Prev;
  if (_OriPointPrev->Funcs.IsPrevNull()) {
    delete _OriPointPrev;
    Source->Prev=NULL;
  } else {
    _OriPointPrev->Prev->Next=Source;
    Source->Prev=_OriPointPrev->Prev;
    delete _OriPointPrev;
  }
  return 1;
}// Delete the Node before current Node
char TObjectChainFuncs::DeleteNext(void) {
  if (!IsNextNull()) return 0;
  TObjectChain *_OriPointNext=Source->Next;
  if (_OriPointNext->Funcs.IsNextNull()) {
    delete _OriPointNext;
    Source->Next=NULL;
  } else {
    _OriPointNext->Next->Prev=Source;
    Source->Next=_OriPointNext->Next;
    delete _OriPointNext;
  }
  return 1;
}// Delete the Node behind current Node
char TObjectChainFuncs::DeleteSomePrev(Word Num) {
  if (IsPrevNull()) return 0;
  TObjectChain *_OriPoint=Source;
  while ((Num--)&&(Source!=NULL)) {
    TObjectChain *_LastTObjectChain=Source;
    Source=Source->Prev;
    delete _LastTObjectChain;
  }
  if (Source==NULL) _OriPoint->Prev=NULL;
  else {
    Source->Next=_OriPoint;
    _OriPoint->Prev=Source;
  }
  return 1;
}
char TObjectChainFuncs::DeleteSomeNext(Word Num) {
  if (IsNextNull()) return 0;
  TObjectChain *_OriPoint=Source;
  while ((Num--)&&(Source!=NULL)) {
    TObjectChain *_LastTObjectChain=Source;
    Source=Source->Next;
    delete _LastTObjectChain;
  }
  if (Source==NULL) _OriPoint->Next=NULL;
  else {
    Source->Prev=_OriPoint;
    _OriPoint->Next=Source;
  }
  return 1;
}
char TObjectChainFuncs::DeleteAll(void) {
  if (!_GoTop()) return 0;
  while (!IsNextNull()) {
    Source=Source->Next;
    delete Source->Prev;
  } delete Source;
  Source=NULL;
  return 1;
}
char TObjectChainFuncs::Replace(TObjectChain *_TObjectChainAnother) {
  TObjectChain *_OriPoint=Source;
  if (!Delete()) return 0;
  InsertBefore(_TObjectChainAnother);
  Source=_OriPoint;
  return 1;
}

char TObjectChainFuncs::SwapWithNext(void) {
  if (IsNextNull()) return 0;
  TObjectChain *_OriPointNext=Source->Next;
  Source->Prev->Next=_OriPointNext;
  Source->Next=_OriPointNext->Next;
  _OriPointNext->Next=_OriPointNext->Prev;
  _OriPointNext->Prev=Source->Prev;
  Source->Prev=_OriPointNext;
  Source->Next->Prev=Source;
  return 1;
}// swap current Node with next Node !!! Note the nods behind current decreased!!!
char TObjectChainFuncs::SwapWithPrev(void) {
  if (IsPrevNull()) return 0;
  TObjectChain *_OriPointPrev=Source->Prev;
  Source->Next->Prev=_OriPointPrev;
  Source->Prev=_OriPointPrev->Prev;
  _OriPointPrev->Prev=_OriPointPrev->Next;
  _OriPointPrev->Next=Source->Next;
  Source->Next=_OriPointPrev;
  Source->Prev->Next=Source;
  return 1;
}// swap current Node with prev Node !!! Note the nods before current decreased !!!
char TObjectChainFuncs::SwapPrevWithNext(void) {
  if (IsNextNull()||IsPrevNull()) return 0;
  TObjectChain *_Before=Source->Prev, *_Behind=Source->Next;
  _Before->Prev->Next=_Behind;
  _Before->Next=_Behind->Next;
  _Behind->Next->Prev=_Before;
  _Behind->Prev=_Before->Prev;
  Source->Next=_Before;
  _Behind->Next=Source;
  Source->Prev=_Behind;
  _Before->Prev=Source;
  return 1;
}// swap the two Node beside current Node
char CommonSwapTObjectChain(TObjectChain **SourceA, TObjectChain **SourceB) {
  if ((SourceA==NULL)||(SourceB==NULL)) return 0;
  TObjectChain *SourceANext=(*SourceA)->Next;
  TObjectChain *SourceBNext=(*SourceB)->Next;
  TObjectChain *SourceC;
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


#include <stdio.h>
#include <Alloc.h>
#include "TString.cpp"

void DumpTObjectChain(TObjectChain *Source, char *Title="This TObjectChain") {
  Source->Funcs._GoTop();
  printf("%s", Title);
  while (Source!=NULL) {
    printf("-: this=%p <-%p %p-> Name=%s\n", Source, Source->Prev, Source->Next, Source->Name);
    Source=Source->Next;
  }
}
void DumpThis(TObjectChain *Source, char *Title="") {
  printf("%s", Title);
  printf("-: this=%p <-%p %p-> Name=%s\n", Source->Funcs.Source, Source->Funcs.Source->Prev, Source->Funcs.Source->Next, Source->Funcs.Source->Name);
}
/*
void m() {
  long lc=coreleft(); printf("Left: %ld\n", lc);
  TObjectChain *test1, *test2;
  TObjectChain *temp;
  lc=coreleft(); printf("Left: %ld\n", lc);
  test1=new TObjectChain; strinit(&test1->Name, "Class A---1");
  temp=new TObjectChain;  strinit(&temp->Name, "Class A---2");  test1->Funcs.Append(temp);
  temp=new TObjectChain;  strinit(&temp->Name, "Class A---3");  test1->Funcs.Append(temp);
  temp=new TObjectChain;  strinit(&temp->Name, "Class A---4");  test1->Funcs.Append(temp);
  lc=coreleft(); printf("Left: %ld\n", lc);
  test2=new TObjectChain;  strinit(&test2->Name, "Class B+++1");
  temp=new TObjectChain;  strinit(&temp->Name, "Class B+++2");  test2->Funcs.Append(temp);
  temp=new TObjectChain;  strinit(&temp->Name, "Class B+++3");  test2->Funcs.Append(temp);
  lc=coreleft(); printf("Left: %ld\n", lc);

  test1->Funcs._GoNext();
  test2->Funcs._GoNext();
  lc=coreleft(); printf("Left: %ld\n", lc);

  TObjectChain *testx=test1->Funcs.Source->Next;
  CommonSwapTObjectChain(&(test1->Funcs.Source), &(testx->Funcs.Source));
  lc=coreleft(); printf("Left: %ld\n", lc);
  test1->Funcs.DeleteAll();
  test2->Funcs.DeleteAll();
}

void main() {
  long lc=coreleft(); printf("Left: %ld\n", lc);
  m();
  lc=coreleft(); printf("Left: %ld\n", lc);
}
*/