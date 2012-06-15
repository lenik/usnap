#include <conio.h>
#include <dos.h>
#include <math.h>

int pointchar = 'Û';
int defaultmode = C4350;

struct text_info ti;

unsigned delaytime = 0;

int gmain();

void cls() {
	clrscr();
}

void pset(int x, int y) {
	gotoxy(x, y);
	putch(pointchar);
}

void drawpixel(int x, int y, int c) {
	textcolor(c);
	pset(x, y);
	if (delaytime > 0) delay(delaytime);
}

void end(int hint) {
	window(ti.winleft, ti.wintop, ti.winright, ti.winbottom);
	if (hint) {
		gotoxy(1, ti.screenheight);
		cprintf("Press any key to continue...");
	}
	if (!getch()) getch();
}

void main() {
	asm {
		pusha
		mov ah, 0bh
		mov bh, 0
		mov bl, 7
		int 10h
		popa
	}
	textmode(defaultmode);
	gettextinfo(&ti);
	cls();
	end(gmain());
}
