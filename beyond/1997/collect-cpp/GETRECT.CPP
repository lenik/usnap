#include <conio.h>
#include <dos.h>
#include "TKey_MKC.cpp"
#include "TKey_FLG.cpp"
#include "TKey_SCN.cpp"
#define MaxOf(n) ((n)>1?(n):1)

void box(int, int, int, int);
void interrupt (*OldKeyInt)(...);
void interrupt NewKeyInt(...);
void KeyInt();
int getting=0;

void interrupt NewKeyInt(...){
  unsigned char KeyScan;
  if (getting) goto Ignore;
  asm push ax
  asm in al, 0x60
  asm mov KeyScan, al
  asm pop ax
  if (KeyScan==MKC_F12(MKC_MAKE)) {
    unsigned char kflag;
    asm {
      push dx
      push ds
      mov dx, 0x40
      mov ds, dx
      ds:
      mov dl, [0x17]
      pop ds
      mov kflag, dl
      pop dx
    }
    if (kflag&FLAG_CTRL)
      KeyInt();
  }
  Ignore:
  (*OldKeyInt)();
}

void KeyInt(){
  getting=1;
  char oritext[4096];
  char cornor=1;
  int x[2]={20, 60}, y[2]={5, 15};
  gettext(1, 1, 80, 25, oritext);
  int key=0;
  while (key!=SCAN_ENTER(SCAN_NORMAL)) {
    switch (key) {
      case SCAN_UP(SCAN_NORMAL):
	if (y[cornor]>1) y[cornor]--;
	break;
      case SCAN_DOWN(SCAN_NORMAL):
	if (y[cornor]<25) y[cornor]++;
	break;
      case SCAN_LEFT(SCAN_NORMAL):
	if (x[cornor]>1) x[cornor]--;
	break;
      case SCAN_RIGHT(SCAN_NORMAL):
	if (x[cornor]<80) x[cornor]++;
	break;
      case SCAN_TAB(SCAN_NORMAL):
	cornor=1-cornor;
	break;
    }
    puttext(1, 1, 80, 25, oritext);
    gotoxy(MaxOf(x[0]+(x[1]-x[0])/2-8), y[0]-1); cprintf("Getting Screen Rect");
    gotoxy(x[0]+1, y[1]-1); cprintf("<Tab>:%s", cornor?"TopLeft":"BottomRight");
    box(x[0], y[0], x[1], y[1]);
    loop1: asm {
      int 0x28
      mov ah, 1
      int 0x16
      jz loop1
      xor ah, ah
      int 0x16
      mov key, ax
    }
  } //while
  puttext(1, 1, 80, 25, oritext);
  getting=0;
}

void box(int x1, int y1, int x2, int y2){
  int c;
  gotoxy(x1, y1); putch(0xda);
  gotoxy(x2, y1); putch(0xbf);
  gotoxy(x1, y2); putch(0xc0);
  gotoxy(x2, y2); putch(0xd9);
  for (c=x1+1; c<x2; c++) {
    gotoxy(c, y1); putch(0xc4);
    gotoxy(c, y2); putch(0xc4);
  }
  for (c=y1+1; c<y2; c++) {
    gotoxy(x1, c); putch(0xb3);
    gotoxy(x2, c); putch(0xb3);
  }
  gotoxy(x1+1, y1+1); cprintf("Size: %2d x %2d", x2-x1+1, y2-y1+1);
  gotoxy(MaxOf(x2-22), y2-1); cprintf("Pos: [%2d, %2d]-[%2d, %2d]", x1, y1, x2, y2);
}

void main(){
  OldKeyInt=getvect(9);
  setvect(9, NewKeyInt);
  keep(0, _SS+_SP/16-_psp);
}
