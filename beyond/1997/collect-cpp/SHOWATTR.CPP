#include <conio.h>
void main(){
  for (int x=0; x<=0xFF; x++) {
    textattr(x);
    cprintf(" ", x);
    if (x/0x10==x%0x10) textattr((x&0xF0)+0xF);
    cprintf("%2X", x);
    textattr(x);
    cprintf(" ", x);
    if (!((x+1)%0x10)) {
      textattr(7);
      cprintf("\r\n");
    }
  }
  textattr(7);
}