
#include "gra.h"

void DDAline(int x0, int y0, int x1, int y1, int color) {
	int x;
	float dx, dy, k, y;
	dx = x1 - x0;
	dy = y1 - y0;
	k = dy / dx;
	y = y0;
	for (x = x0; x <= x1; x++) {
		drawpixel(x, int(y + .5), color);
		y += k;
	}
}

void MidpointLine(int x0, int y0, int x1, int y1, int color) {
	int a, b, delta1, delta2, d, x, y;
	a = y0 - y1;
	b = x1 - x0;
	d = 2 * a + b;
	delta1 = 2 * a;
	delta2 = 2 * (a + b);
	x = x0;
	y = y0;
	drawpixel(x, y, color);
	while (x < x1) {
		x++;
		if (d < 0) {
			y++;
			d += delta2;
		} else {
			d += delta1;
		}
		drawpixel(x, y, color);
	}
}

void BresenhamLine(int x0, int y0, int x1, int y1, int color) {
	int i, x, y, dx, dy;
	float k, e;
	dx = x1 - x0;
	dy = y1 - y0;
	k = (float)dy / dx;
	e = -0.5;
	x = x0; y = y0;
	for (i = 0; i <= dx; i++) {
		drawpixel(x, y, color);
		x = x + 1;
		e = e + k;
		if (e >= 0) {
			y = y + 1;
			e = e - 1;
		}
	}
}

void Integer_Bresenham_Line(int x0, int y0, int x1, int y1, int color) {
	int i, x, y, dx, dy;
	float e;
	dx = x1 - x0;
	dy = y1 - y0;
	e = -dx; x = x0; y = y0;
	for (i = 0; i <= dx; i++) {
		drawpixel(x, y, color);
		x = x + 1;
		e = e + 2 * dy;
		if (e >= 0) {
			y = y + 1;
			e = e - 2 * dx;
		}
	}
}

void MidpointCircle(int r, int color) {
	int x, y;
	float d;
	x = 0; y = r; d = 1.25 - r;
	drawpixel(x, y, color);
	while (x < y) {
		x++;
		if (d < 0) {
			d += 2 * x + 3;
		} else {
			d += 2 * (x - y) + 5;
			y--;
		}
		drawpixel(x, y, color);
	}
}

void IntegerMidpointCircle(int r, int color) {
	int x, y, d;
	x = 0; y = r; d = 1 - r;
	drawpixel(x, y, color);
	while (x < y) {
		if (d < 0) {
			d += 2 * x + 3;
			x++;
		} else {
			d += 2 * (x - y) + 5;
			x++;
			y--;
		}
		drawpixel(x, y, color);
	}
}

void AdvancedMidpointCircle(int r, int color) {
	int x, y, deltax, deltay, d;
	x = 0; y = r;
	deltax = 3; deltay = 2 - r - r; d = 1 - r;
	drawpixel(x, y, color);
	while (x < y) {
		if (d < 0) {
			d += deltax;
			deltax += 2;
			x++;
		} else {
			d += (deltax + deltay);
			deltax += 2;
			deltay += 2;
			x++;
			y--;
		}
		drawpixel(x, y, color);
	}
}

void BresenhamCircle(int r, int color) {
	int x, y, delta, delta1, delta2, direction;
	x = 0; y = r;
	delta = 2 * (1 - r);
	while (y >= 0) {
		drawpixel(x, y, color);
		if (delta < 0) {
			delta1 = 2 * (delta + y) - 1;
			if (delta1 <= 0) direction = 1;
			else direction = 2;
		} else if (delta > 0) {
			delta2 = 2 * (delta - x) - 1;
			if (delta2 <= 0) direction = 2;
			else direction = 3;
		} else {
			direction = 2;
		}
		switch (direction) {
		case 1:
			x++;
			delta += 2 * x + 1;
			break;
		case 2:
			x++;
			y--;
			delta += 2 * (x - y + 1);
			break;
		case 3:
			y--;
			delta += (-2 * y + 1);
			break;
		}
	}
}

void MidpointEllipse(int a, int b, int color) {
	int x, y;
	float d1, d2;
	x = 0;
	y = b;
	d1 = b * b + a * a * (-b + 0.25);
	drawpixel(x, y, color);
	while (b * b * (x + 1) < a * a * (y - 0.5)) {
		if (d1 < 0) {
			d1 += b * b * (2 * x + 3);
			x++;
		} else {
			d1 += (b * b * (2 * x + 3) + a * a * (-2 * y + 2));
			x++;
			y--;
		}
		drawpixel(x, y, color);
	} // up-side
	d2 = sqrt(b * (x + .5)) + sqrt(a * (y - 1)) - sqrt(a * b);
	while (y > 0) {
		if (d2 < 0) {
			d2 += b * b * (2 * x + 2) + a * a * (-2 * y + 3);
			x++;
			y--;
		} else {
			d2 += a * a * (-2 * y + 3);
			y--;
		}
		drawpixel(x, y, color);
	}
}


int gmain() {
	delaytime = 10;
/*
	DDAline(1, 1, 20, 10, 15);
		//MidpointLine(1, 2, 20, 11, 7);
	MidpointLine(1, 3, 20, 12, 15);
		//BresenhamLine(1, 4, 20, 13, 7);
	BresenhamLine(1, 5, 20, 14, 15);
		//Integer_Bresenham_Line(1, 6, 20, 15, 7);
	Integer_Bresenham_Line(1, 7, 20, 16, 15);
*/
	window(40, 20, 80, 40);
	BresenhamCircle(10, 15);
	MidpointEllipse(30, 15, 15);
}
