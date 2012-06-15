#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <conio.h>

REGS r;
SREGS sr;

/*
The OpenClipboard function opens the clipboard. Other applications
will not be able to modify the clipboard until the CloseClipboard
function is called.
*/
void OpenClipboard() {
  r.x.ax = 0x1701;
  int86(0x2f, &r, &r);
}
/*
The EmptyClipboard function empties the clipboard and frees handles
to data in the clipboard.
*/
void EmptyClipboard() {
  r.x.ax = 0x1702;
  int86(0x2f, &r, &r);
}
/*
The CloseClipboard function closes the clipboard.
*/
void CloseClipboard() {
  r.x.ax = 0x1708;
  int86(0x2f, &r, &r);
}
/*
The SetClipboardData function sets the data in the clipboard. The
application must have called the OpenClipboard function before
calling the SetClipboardData function.
*/
int SetClipboardData(char* s) {
  int Len;
  Len = strlen(s) + 1;
  r.x.ax = 0x1703;
  r.x.dx = 1;
  r.x.si = 0;
  r.x.cx = Len;
  r.x.bx = FP_OFF(s);
  sr.es = FP_SEG(s);
  int86x(0x2f, &r, &r, &sr);
  return r.x.ax;
}
/*
The GetClipboardDataSize function retrieves the size of the current
clipboard data. This function is undocumented in Windows SDK.
*/
int GetClipboardDataSize() {
  r.x.ax = 0x1704;
  r.x.dx = 1;
  int86(0x2f, &r, &r);
  return r.x.ax;
}
/*
The GetClipboardData function retrieves a handle of the current
clipboard data having string format. The clipboard must have been
opened previously.
*/
int GetClipboardData(char* s) {
  r.x.ax = 0x1705;
  r.x.dx = 1;
  r.x.bx = FP_OFF(s);
  sr.es = FP_SEG(s);
  int86x(0x2f, &r, &r, &sr);
  return r.x.ax;
}
/*
The IsWindowsRunning function detects whether Windows is running.
The application must have called this function before calling all
Clipboard functions.
*/
int IsWindowsRunning() {
  r.x.ax = 0x1700;
  int86(0x2f, &r, &r);
  return r.x.ax != 0x1700;
}

void main() {
  char s[256],s2[]="This string is passed by an MS-DOS application.";
  if (!IsWindowsRunning()) {
    printf("Windows is NOT running!\n");
    exit(- 1);
  }
  OpenClipboard();
  // SetClipboardData(s2);
  printf("Data size=%d, string length=%d\n", GetClipboardDataSize(),
  strlen(s2));
  GetClipboardData(s);
  printf("%s\n", s);
  CloseClipboard();
  getch();
}
