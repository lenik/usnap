#include "TStrStck.h"
#include <alloc.h>

/* push hi bits first, than lo bits
   the sp point to the byte push last.
   e.g. push 1234h
   sp-> 34h
	12h
	...
   bp-> [0000h]
*/

TStringStack::TStringStack(){
  bp=0;
  sp=0;
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

Byte pop(){
  return popb();
}
Byte popb(){
  if (!String) return (Byte)0;
  return String[sp--];
}
Word popw(){
  if (!String) return (Word)0;
  return (popb()<<8)+popb();
}
DWord popdw(){
  if (!String) return (DWord)0;
  return (popw()<<16)+popw();
}
void popall(){
  if (String) delete String;
  TStringStack();
}

#include <stdio.h>
void main(){
  TStringStack tss;
  tss.push((Byte)0xcd);
  for (int i=tss.bp; i<=tss.sp; i++) {
    printf("stack[%2d]=%8X\n", i-tss.bp, tss.String[i-tss.bp]);
  }

}