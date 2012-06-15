#include <stdio.h>
#include <alloc.h>
#include "TString.cpp"
void main(){
  TStringChain tsc((Byte*)"c-+=#*?", 8);
  tsc.CurPos=2;
  printf("Mem[%ld] String[%s] Len[%d] CurPos[%d]\n", coreleft(), tsc.String, tsc.Length, tsc.CurPos);
  tsc.StrChange("abcdefghijklmnopqrstuvwxyz", 26, 2);
  printf("Mem[%ld] String[%s] Len[%d] CurPos[%d]\n", coreleft(), tsc.String, tsc.Length, tsc.CurPos);
}