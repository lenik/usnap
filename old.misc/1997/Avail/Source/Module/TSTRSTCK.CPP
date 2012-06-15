#include "TStrStck.h"
#include <alloc.h>

TStringStack::TStringStack(){
  bp=sp=0;
  String=NULL;
}
TStringStack::TStringStack(Word _InitSize){
  TStringStack();
  if (!(String=new Byte[_InitSize])) return;
  sp=bp+_InitSize-1;
}
TStringStack::~TStringStack(){
  if (String) delete String;
}

void TStringStack::push(DWord _PushDWord){
  Byte *_TestPoint;
  if (!String) {
    if (!(String=new Byte[sizeof(_PushDWord)])) return;
    sp=(Word)-1;
  } else {
    _TestPoint=(Byte *)realloc(String, sp+1+sizeof(_PushDWord));
    if (_TestPoint!=NULL) String=_TestPoint;
  }
  for (Byte _LoopVar=0; _LoopVar<sizeof(_PushDWord); _LoopVar++){
    String[++sp]=(_PushDWord>>((sizeof(_PushDWord)-1-_LoopVar)*8))&0xFF;
  }
}
void TStringStack::push(Word _PushWord){
  Byte *_TestPoint;
  if (!String) {
    if (!(String=new Byte[sizeof(_PushWord)])) return;
    sp=(Word)-1;
  } else {
    _TestPoint=(Byte *)realloc(String, sp+1+sizeof(_PushWord));
    if (_TestPoint!=NULL) String=_TestPoint;
  }
  for (Byte _LoopVar=0; _LoopVar<sizeof(_PushWord); _LoopVar++){
    String[++sp]=(_PushWord>>((sizeof(_PushWord)-1-_LoopVar)*8))&0xFF;
  }
}
void TStringStack::push(Byte _PushByte){
  Byte *_TestPoint;
  if (!String) {
    if (!(String=new Byte[sizeof(_PushByte)])) return;
    sp=(Word)-1;
  } else {
    _TestPoint=(Byte *)realloc(String, sp+1+sizeof(_PushByte));
    if (_TestPoint!=NULL) String=_TestPoint;
  }
  for (Byte _LoopVar=0; _LoopVar<sizeof(_PushByte); _LoopVar++){
    String[++sp]=(_PushByte>>((sizeof(_PushByte)-1-_LoopVar)*8))&0xFF;
  }
}

Byte TStringStack::pop(){
  return popb();
}
Byte TStringStack::popb(){
  if (!String) return (Byte)0;
  if (sp<=bp) {
    Byte _Saving=String[sp];
    clear();
    return _Saving;
  }
  return String[sp--];
}
Word TStringStack::popw(){
  Word _RetWord=0;
  if (!String) return (Word)0;
  _RetWord=(Word)popb();
  _RetWord+=(Word)popb()<<8;
  return _RetWord;
}
DWord TStringStack::popdw(){
  DWord _RetDWord=0;
  if (!String) return (DWord)0;
  _RetDWord=(DWord)popw();
  _RetDWord+=(DWord)popw()<<16;
  return _RetDWord;
}
void TStringStack::clear(){
  if (String) delete String;
  bp=sp=0;
  String=NULL;
}
