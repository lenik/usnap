#include <stdio.h>
#include <stdlib.h>
#include "TopType.cpp"

void dtvs(TVarSet _tvs){
  int i;
  for (i=0; i<16; i++) {
    printf("d8[%2d]=%2x  ", i, _tvs.d8[i]);
    if (!((i+1)%4)) printf("\n");
  }
}
void dtvsb(TVarSet _tvs){
  int i;
  for (i=0; i<128; i++) {
    printf("%1d", tvsB1Get(_tvs, i));
    if (!((i+1)%8)) printf(" ");
    if (!((i+1)%32)) printf("\n");
  }
}

void main(){
  printf("\nTopType Test\n");
  TVarSet tt;
  dtvs(tt);
  tvsClear(&tt);
  dtvs(tt);
  tvsFill(&tt);
  dtvs(tt);
  printf("Bin code:\n");
  dtvsb(tt);
  randomize();
  for (int i=0; i<128; i++){
    tvsB1Set(&tt, i, i*random(1000));
  }
  dtvsb(tt);
}
