
#include "display.h"
#include <math.h>
#include <conio.h>

#define UPDRAW(x, y)	moveto((int)(x), (int)(y))
#define DNDRAW(x, y)	lineto((int)(x), (int)(y))

void B3_curves(char pflag, long xq[][2], int m, long lxx, long lyy) {
	int i, j, k = 10;
	long lx1, ly1;
	double t0 , t1, t2, t3;

	lx1 = (xq[0][0] + 4.0 * xq[1][0] + xq[2][0]) / 6 + lxx;
	ly1 = (xq[0][1] + 4.0 * xq[1][1] + xq[2][1]) / 6 + lyy;
	if (pflag == 'p') UPDRAW(lx1, ly1);

	for (i = 1; i < m - 1; i++) {
		for(j = 0; j <= k; j++) {
			t3 = 1.0 * j / k;
			t0 = 1 - t3;
			t0 = t0 * t0 * t0 / 6.0;
			t1 = ((3.0 * t3 - 6.0) * t3 * t3 + 4.0) / 6.0;
			t2 = (((3 - 3 * t3) * t3 + 3) * t3 + 1) / 6.0;
			t3 = 1.0 - t0 - t1 - t2;
			lx1 = xq[i - 1][0] * t0 + xq[i][0] * t1
				+ xq[i + 1][0] * t2 + xq[i + 2][0] * t3
				+ lxx;
			ly1 = xq[i - 1][1] * t0 + xq[i][1] * t1
				+ xq[i + 1][1] * t2 + xq[i + 2][1] * t3
				+ lyy;
			if (pflag == 'p') DNDRAW(lx1, ly1);
		}
	}
}

#define N	6

void main() {
	static long p[N + 3][2] = {
		{ 50, 400, },
		{ 100, 120, },
		{ 260, 180, },
		{ 500, 120, },
		{ 600, 300, },
		{ 590, 420, },
		{ 50, 400, },
		{ 100, 120, },
		{ 260, 180, },

/*		{ 100, 100 },
		{ 200, 100 },
		{ 200, 200 },
		{ 100, 200 },
		{ 100, 100 },
		{ 200, 100 },
		{ 200, 200 },
*/
	};
	int i, color;
	Initialize();

	color = WHITE;
	setcolor(color);
	UPDRAW(p[0][0], p[0][1]);
	for (i = 1; i < N; i++) {
		DNDRAW(p[i][0], p[i][1]);
	}

	setcolor(WHITE);

	B3_curves('p', p, N - 1, 0, 0);
	while (getch() != ESC);

	setcolor(RED);

	p[0][0] = 6.0 * p[0][0] - 4.0 * p[1][0] - p[2][0];
	p[0][1] = 6.0 * p[0][1] - 4.0 * p[1][1] - p[2][1];
	p[N - 1][0] = 6.0 * p[N - 1][0] - 4.0 * p[N - 2][0] - p[N - 3][0];
	p[N - 1][1] = 6.0 * p[N - 1][1] - 4.0 * p[N - 2][1] - p[N - 3][1];

	B3_curves('p', p, N - 1, 0, 0);
	while(getch() != ESC);

	setcolor(GREEN);

	p[0][0] = 50;
	p[0][1] = 400;
	p[N - 1][0] = 590;
	p[N - 1][1] = 420;
	B3_curves('p', p, N + 2, 0, 0);

	while(getch() != ESC);

	closegraph();
}
