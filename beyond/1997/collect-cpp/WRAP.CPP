#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

#define L	1
#define R	2

#define link(x, a, b)	if (a != b) { x[a].n = b; x[b].p = a; }

struct point {
  int x, y, p, n;
};

int readin(char *fn, struct point *ps) {
  FILE *f;
  int n, c;
  if ((f = fopen(fn, "rt")) == NULL) {
    printf("error in opening file %s\n", fn);
    return 0;
  }
  fscanf(f, "%d", &n);
  for (c = 0; c < n; c++) { fscanf(f, "%d, %d", &ps[c].x, &ps[c].y); }
  fclose(f);
  return n;
}

int ycmp(const void *a, const void *b) {
  //struct point *a, struct point *b) {

  return (((point *)a)->y < ((point *)b)->y) ? -1 : 1;
}

void out(struct point *p, int len) {
  int c = 1;
  while (c <= len) { printf("p[%2d] = %4d %4d\n", c++, p[c].x, p[c].y); }
}

void outg(struct point *p, int len) {
  int c, gd = VGA, gm = VGAMED;
  initgraph(&gd, &gm, "..\\bgi");
  setbkcolor(0); setwritemode(1); setcolor(7); cleardevice();
  for (c = 1; c <= len; c++) {
    p[c].x = p[c].x * 20;
    p[c].y = (15 - p[c].y) * 20;
  } c = 1;
  setcolor(14);
  do {
    circle(p[c].x, p[c].y, 5); moveto(p[c].x, p[c].y);
    c = p[c].n;
    lineto(p[c].x, p[c].y);
  } while (c != 0);	/* c[0]'s pos is equ to c[1] */
}

void linkp(int d, struct point *p, int t, int b) {	/* d: 1Left 2Right */
  const bb = p[b].p;
  const xbb = p[bb].x, xb = p[b].x, xt = p[t].x;
  const ybb = p[bb].y, yt = p[t].x;
  float by = (float)(xb - xbb) * (yt - ybb);
  int jump;
  if (bb != 0 && xt == xbb) { jump = 1; }
  else {
    by /= (xt - xbb) + ybb;
    jump = p[b].y > by ? 1 : 0;
  }
  if ((d == L && p[t].x < p[b].x) || (d == R && p[t].x > p[b].x)) {
    if (jump == 1) { linkp(d, p, t, bb); } else { link(p, bb, t); }
  } else {
    if (jump == 0) { linkp(d, p, t, bb); } else { link(p, bb, t); }
  }
}

void main(int argc, char **argv) {
  struct point p[200];
  int c, len, x;
  int l, r;
  int dl, dr;

  len = readin(argv[1], p + 1);
  if (len < 1) { printf("no element.\n"); return; }
  qsort(p, len, sizeof(struct point), ycmp);
  p[1].p = p[0].p = 0;
  l = r = 1;
  for (c = 2; c < len; c++) {
    x = p[c].x;
    dl = x - p[l].x;
    dr = p[r].x - x;
    if (dl < dr) {			/* Left side */
      linkp(L, p, c, l);
      l = c;
    } else {				/* Right side */
      linkp(R, p, c, r);
      r = c;
    }
  }
  if (l != r) link(p, l, r);
  outg(p, len);
  getch();
  closegraph();
}
