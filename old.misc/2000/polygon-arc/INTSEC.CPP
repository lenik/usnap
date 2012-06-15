#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

struct CPoint {
	double x, y;
};

void main() {
	double k2, k1, k0, test, r1, r2;
	CPoint cp, cpp, p2, p1;
	CPoint c_o;
	double c_r;
	int x, y;

	FILE *f = fopen("d:\\polytest.pnt", "r");
	if (f == NULL) {
		perror("");
		return;
	}
	fscanf(f, "%d,%d", &x, &y);	p1.x = x;	p1.y = y;
	fscanf(f, "%d,%d", &x, &y);	p2.x = x;		p2.y = y;
	fscanf(f, "%d,%d", &x, &y);
	fscanf(f, "%d,%d", &x, &y);	c_o.x = x; 		c_o.y = y;
	fscanf(f, ",%d", &x);		c_r = x;
	fclose(f);

	double w = p2.x - p1.x, h = p2.y - p1.y;
	k2 = w*w + h*h;
	k1 = (p1.x - c_o.x) * w + (p1.y - c_o.y) * h;
	k1 *= 2;
	k0 = pow(p1.x - c_o.x, 2) + pow(p1.y - c_o.y, 2) - c_r * c_r;
	test = k1 * k1 - 4 * k2 * k0;
	if (test >= 0) {
		r1 = (-k1 + sqrt(test)) / k2 / 2;
		r2 = (-k1 - sqrt(test)) / k2 / 2;
		cpp.x = p1.x + (p2.x - p1.x) * r1;
		cpp.y = p1.y + (p2.y - p1.y) * r1;
		cp.x = p1.x + (p2.x - p1.x) * r2;
		cp.y = p1.y + (p2.y - p1.y) * r2;
	}

	if (test >= 0) {
		int gd = DETECT, gm, er;
		initgraph(&gd, &gm, "..\\bgi");
		circle(c_o.x, c_o.y, c_r);
		line(p1.x, p1.y, p2.x, p2.y);
		setcolor(YELLOW);
			circle(cpp.x, cpp.y, 3);
			circle(cp.x, cp.y, 3);
			getch();
		closegraph();
	}
}
