
#include <graphics.h>
#include <dos.h>
#include <math.h>
#include <stdio.h>

/* POINT structure */
typedef struct _POINT {
	float	x;
	float	y;
} POINT;

const float PI	= 3.14159265358979;

#define PCON		32
#define BGIPATH		"bgi"

/* drawp: draw polygon by array of POINT
 *	p	contains data of polygon's shape
 *	size	elements (not bytes)
 *	color	line color
 * returns nothing
 */
void drawp(POINT *p, int size, int color) {
	int	i;
	if (p == NULL || size == 0) return;

	setcolor(color);
	moveto(p->x, p->y);
	for (i = 1; i < size; i++) {
		p++;
		lineto(p->x, p->y);
	}
}

void main() {
	int	gd = 0, gm = 0, i;
	POINT	s[PCON], d[PCON];	/* source shape and dest shape */
	float	t;		/* time interpolating point */

	/* initialize screen */
	initgraph(&gd, &gm, BGIPATH);
	if ((i = graphresult()) != grOk) {
		puts(grapherrormsg(i));
		return;
	}

	/* initialize morph shapes of two objects
	 * 	s: source shape
	 * 	d: dest shape
	 * notice here dest shape uses -sin(a),
	 * because s is CW, but d is CCW
	 */
	for (i = 0; i < PCON; i++) {
		float a1 = (float)i / (PCON - 1) * PI + 1.5 * PI;
		float a2 = (float)i / (PCON - 1) * PI + 0.8 * PI;

		s[i].x	= cos(a1) * 80 + 50;
		s[i].y	= sin(a1) * 50 + 150;
		d[i].x	= cos(a2) * 50 + 250;
		d[i].y	= -sin(a2) * 80 + 150;
	}

	/* time interpolation */
	for (t = 0; t <= 1; t += .01) {
		static POINT tr[PCON];

		/* erase last drawing, tr may be correct erased
		 * because it is declared with `static' modification
		 */
		drawp(s, PCON, BLACK);
		drawp(d, PCON, BLACK);
		drawp(tr, PCON, BLACK);

		/* calculate for simple interpolations */
		for (i = 0; i < PCON; i++) {
			tr[i].x	= (1 - t) * s[i].x + t * d[i].x;
			tr[i].y	= (1 - t) * s[i].y + t * d[i].y;
		}

		/* draw out */
		drawp(s, PCON, LIGHTBLUE);
		drawp(d, PCON, LIGHTBLUE);
		drawp(tr, PCON, LIGHTGREEN);

		/* delay for demonstrating */
		delay(20);

		/* pause for initial screen */
		if (t == 0) {
			getchar();
		}
	}
	getchar();

	/* exiting */
	closegraph();
}
