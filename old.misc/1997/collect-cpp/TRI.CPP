
// loop triangles generator

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void putA(int x, int y) {
	gotoxy(x, y);
	cprintf("A");
}

int drawTriangle(int depth, int startx, int starty) {
	if (depth == 1) {
		putA(startx, starty);
	} else {
		int step = pow(6, depth - 2);
		depth--;
		drawTriangle(depth, startx, starty);
		drawTriangle(depth, startx - step, starty + depth);
		drawTriangle(depth, startx + step, starty + depth);
		drawTriangle(depth, startx - step - step,
					starty + depth + depth);
		drawTriangle(depth, startx,
					starty + depth + depth);
		drawTriangle(depth, startx + step + step,
					starty + depth + depth);

	}
}

void main() {
	clrscr();
	drawTriangle(3, 40, 1);
}
