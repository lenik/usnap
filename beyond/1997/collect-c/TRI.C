#include <stdio.h>
#include <conio.h>
#include <math.h>

void putA(int x, int y) {
	gotoxy(x, y);
	cprintf("A");
}

void drawTriangle(int depth, int startx, int starty) {

	if (depth == 1) putA(startx, starty);
	else {
		int step = pow(2, depth - 1);
		int xstep = sqrt(step * step + step * step);
		depth--;
		drawTriangle(depth, startx, starty);
		drawTriangle(depth, startx - xstep, starty + xstep);
		drawTriangle(depth, startx + xstep, starty + xstep);
	}
}

void main() {
	clrscr();
	drawTriangle(2, 40, 1);

	getch();
}
