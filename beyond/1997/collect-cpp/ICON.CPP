#include <stdio.h>
#include <conio.h>
#include <string.h>

#include <source\module\tdvideoa.cpp>

#define MAXX	10		// *8
#define MAXY	24
#define MAXRING	32

enum {False = 0, True} Boolean;
enum {Horiz = 0, Vert} Direction;
enum {Manual = 0, Draw, Erase, Invert} PenStatus;

struct file {
  char	filename[128];
  enum	Boolean brace;
} myfileinfo;

class icon {
  int	ringstat[MAXRING];
  enum	Boolean ringactive;
  void	ringleft(), ringright();
  int	maxx, maxy;
  int	ring;
  enum	Direction dir;
  void	xcopy(int, int), ycopy(int, int);
	icon(int, int, enum Direction);
public:
  enum	PenStatus pen;
  int	x, y;
  char	map[MAXRING][MAXX][MAXY];
  void	clear(), full(), invert();
  void	up(int), down(int), left(int), right(int);
  void	invertx(), inverty(), scalex(int), scaley(int);
  void	rotate(int);
  void	slipleft(int), slipright(int), slipup(int), slipdown(int);
  void	outline(), line(int, int, int, int);
  void	rect(int, int, int, int), box(int, int, int, int);
  void	circle(int, int, int, int), ellipse(int, int, int, int);
  void	fill();
  void	prev(), next();
};

void	main(int argc, char **argv) {
}

icon::icon(int _maxx, int _maxy, enum Direction _dir) {
  int i, j, k;
  dir = _dir;
  maxx = _maxx;
  maxy = _maxy;
  x = y = 0;
  ringactive = False;
  for (i = 0; i < MAXRING; i++) {
    ring = i;
    clear();
  }
  ring = 0;
  ringactive = True;
  pen = Manual;
}

void	icon::clear() {
  int i, j;
  if (ringactive == True) {
    ringleft();
  }
  for (i = 0; i < maxx; i++) {
    for (j = 0; j < maxy; j++) {
      map[ring][i][j] = 0;
    }
  }
}

void	icon::full() {
  int i, j;
  if (ringactive == True) {
    ringleft();
  }
  for (i = 0; i < maxx; i++) {
    for (j = 0; j < maxy; j++) {
      map[ring][i][j] = ~0;
    }
  }
}

void	icon::invert() {
  int i, j;
  if (ringactive == True) {
    ringleft();
  }
  for (i = 0; i < maxx; i++) {
    for (j = 0; j < maxy; j++) {
      map[ring][i][j] = ~map[ring][i][j];
    }
  }
}

void	icon::up(int n) {
  int i, j;
  char xmap[MAXX][MAXY];
  if (ringactive == True) {
    ringleft();
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < maxx; j++) {
      xmap[j][i] = map[ring][j][i];
    }
  }
  for (i = n; i < maxy; i++) {
    ycopy(i, i - n);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < maxx; j++) {
      map[ring][j][maxy - n + i] = xmap[j][i];
    }
  }
}

void	icon::down(int n) {
  int i, j;
  char xmap[MAXX][MAXY];
  if (ringactive == True) {
    ringleft();
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < maxx; j++) {
      xmap[j][i] = map[ring][j][maxy - n + i];
    }
  }
  for (i = maxy - n - 1; i >= 0; i--) {
    ycopy(i, i + n);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < maxx; j++) {
      map[ring][j][i] = xmap[j][i];
    }
  }
}
