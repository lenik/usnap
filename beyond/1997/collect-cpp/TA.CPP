#include <stdio.h>
#include <bios.h>
#include <conio.h>

void main(){
  unsigned i, k;
  while (1) {
    i = getch();
    if (i == 0) {
      i = getch();
      printf("Extend -");
    }
    printf("%c- %d : 0%o : %#x \t", i, i, i, i);
    if (i == 's') {
    k = _bios_keybrd(_NKEYBRD_READ);
      printf("[%d %d] : [%02x %02x]", k >> 8, k & 0xFF, k >> 8, k & 0xFF);
    }
    printf("\n");
    if (i == 'q') return;
  }
}
