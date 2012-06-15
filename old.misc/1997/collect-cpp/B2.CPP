
#include "display.h"
#include <math.h>
#include <conio.h>

#define UPDRAW(x, y)	moveto((int)(x), (int)(y))
#define DNDRAW(x, y)	lineto((int)(x), (int)(y))

void B2_curves(char pflag, long xq[][2], int m, long lxx, long lyy) {
	int i, j, k = 10;
	long lx1, ly1;
	double t0, t1, t2;
	lx1 = (xq[0][0] + xq[1][0]) / 2 + lxx;
	ly1 = (xq[0][1] + xq[1][1]) / 2 + lyy;

	if (pflag == 'p') UPDRAW(lx1, ly1);
	for (i = 1; i < m; i++)
	for (j = 0; j <= k; j++) {
		t2 = 1.0 * j / k;
		t0 = 1.0 - t2;
		t0 = 0.5 * t0 * t0;
		t1 = 0.5 * (1.0 + (2.0 - 2.0 * t2) * t2);
		t2 = 1.0 - t0 - t1;
		lx1 = xq[i - 1][0] * t0 +
			xq[i][0] * t1 +
			xq[i + 1][0] * t2 + lxx;
		ly1 = xq[i - 1][1] * t0 +
			xq[i][1] * t1 +
			xq[i + 1][1] * t2 + lyy;
		if (pflag == 'p') DNDRAW(lx1, ly1);
	}
}

#define N 	4

void main() {
	static long p[N + 2][2] = {
#if N > 4
		{ 50, 400 },
		{ 100, 120 },
		{ 260, 180 },
		{ 500, 120 },
		{ 600, 300 },
		{ 590, 420 },
		{ 50, 400 },
		{ 100, 120 },
#else
		{ 100, 100 },
		{ 200, 100 },
		{ 200, 200 },
		{ 100, 200 },
		{ 100, 100 },
		{ 200, 100 },
//		{ 200, 200 },
#endif
	};
	int i, color;
	Initialize();

	color = WHITE;
	setcolor(color);

	UPDRAW(p[0][0], p[0][1]);
	for (i = 1; i < N; i++) DNDRAW(p[i][0], p[i][1]);
	setcolor(BLUE);

	B2_curves('p', p, N - 1, 0, 0);
	while(getch() != ESC);

	setcolor(RED);
	p[0][0] = 2 * p[0][0] - p[1][0];
	p[0][1] = 2 * p[0][1] - p[1][1];
	p[N - 1][0] = 2 * p[N - 1][0] - p[N - 2][0];
	p[N - 1][1] = 2 * p[N - 1][1] - p[N - 2][1];

	B2_curves('p', p, N - 1, 0, 0);
	while(getch() != ESC);
	setcolor(GREEN);

	p[0][0] = 50;
	p[0][1] = 400;
	p[N - 1][0] = 590;
	p[N - 1][1] = 420;
	B2_curves('p', p, N + 1, 0, 0);
	while(getch() != ESC);

	closegraph();
}
