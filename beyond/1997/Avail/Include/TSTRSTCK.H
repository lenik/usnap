#ifndef __TSTRSTCK_H

#define __TSTRSTCK_H

#include "TopType.h"

class TStringStack{
public:
  Word bp, sp;
public:
  Byte *String;
public:
  TStringStack();
  TStringStack(Word _InitSize);
  ~TStringStack();
public:
  void push(DWord _PushDWord);
  void push(Word _PushWord);
  void push(Byte _PushByte);
  Byte pop();
  Byte popb();
  Word popw();
  DWord popdw();
  void clear();
};

#endif