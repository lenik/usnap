#include <stdio.h>
#include <dos.h>

void interrupt (*old1b)();
void interrupt (*old23)();

int main(int argc, char **argv) {
  int pass = 0;
  unsigned long x;
  char secword[1000];
  old1b = getvect(0x1B);
  old23 = getvect(0x23);
  x = MK_FP(FP_SEG(_Break), FP_OFF(_Break));
  disable();
  setvect(0x1B, x);
  setvect(0x23, x);
  enable();
  while (pass == 0) {
    printf("please enter security word: ");
    scanf("%s", secword);
    if (stricmp("whatsnew", secword) == 0) { pass = 1; }
    else { printf("error! \n"); }
  }
  printf("ok! waiting, please...\n");
  disable();
  setvect(0x1B, old1b);
  setvect(0x23, old23);
  enable();
  return 123;
}

void _Break {
  asm db 0xEA, 0x0, 0x0, 0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF
}
