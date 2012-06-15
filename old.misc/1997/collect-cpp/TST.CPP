
#include <stdio.h>

#include "tmisc.cpp"

void main(int argc, char **argv) {
  Byte a[300];
  Byte b[300];

  TSELFCONTROLID
  TDEFBYTESMIN (60) 'DanSei --]', 0; asm db 90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h;
  asm db 90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h,90h

  TSelfControl tsc(argv[0]);
  tsc.TReadSelfConfig (2, b, 30);
  printf ("+2= %s \n", b);
  printf ("Input +2 string: ");
  scanf ("%s", a);
  tsc.TWriteSelfConfig (2, a, 30);

}