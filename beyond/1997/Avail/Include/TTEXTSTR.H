#ifndef __TTEXTSTR_H

#define __TTEXTSTR_H

#include "TopType.h"
#include "TString.h"

class TTextString:TStringChain{
public:
  char *String;
  Word CurPos;
