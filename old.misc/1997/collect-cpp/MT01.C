#include <dos.h>
#include <conio.h>

enum Boolean {False = 0, True};
enum Status {Installed, Uninstalled};
enum ButtonStatus {Unpressed = 0, Pressed};

const LeftMask = 0x0001, RightMask = 0x0002;

struct MousePosition {
  int X;
  int Y;
  enum ButtonStatus LeftButton;
  enum ButtonStatus RightButton;
};

int GetMouseStatus () {
  union REGS r;
  r.x.ax = 0;
  int86 (0x33, &r, &r);
  return (r.x.ax == 0xFFFF) ? Installed : Uninstalled;
}

void SetMousePosition (struct MousePosition pos) {
  union REGS r;
  r.x.ax = 4;
  r.x.cx = pos.X;
  r.x.dx = pos.Y;
  int86 (0x33, &r, &r);
}

void GetMousePosition (struct MousePosition *pos) {
  union REGS r;
  r.x.ax = 3;
  int86 (0x33, &r, &r);
  pos -> X = r.x.cx;
  pos -> Y = r.x.dx;
  pos -> LeftButton = r.x.bx & LeftMask;
  pos -> RightButton = (r.x.bx & RightMask) >> 1;
}

void ShowMouseCursor () {
  union REGS r;
  r.x.ax = 1;
  int86 (0x33, &r, &r);
}

void HideMouseCursor () {
  union REGS r;
  r.x.ax = 2;
  int86 (0x33, &r, &r);
}

void main () {

  struct MousePosition mpos;

  if (GetMouseStatus() == Installed) printf ("I found mouse driver.\n");
  else {
    printf ("I haven't found mouse driver.\n");
    return;
  }

  clrscr ();	/* Clear Screen */

  mpos.X = 10;
  mpos.Y = 10;
  SetMousePosition (mpos);

  ShowMouseCursor ();

  do {
    GetMousePosition (&mpos);
    gotoxy (30, 10);
    cprintf ("x=%d,y=%d     ", mpos.X, mpos.Y);
    gotoxy (30, 13);
    cprintf ("Left Pressed  : %s    ",
		mpos.LeftButton == Pressed ? "Pressed" : "Released");
    gotoxy (30, 14);
    cprintf ("Right Pressed : %s    ",
		mpos.RightButton == Pressed ? "Pressed" : "Released");
  } while (mpos.LeftButton == Unpressed || mpos.RightButton == Unpressed);

  HideMouseCursor();
}
