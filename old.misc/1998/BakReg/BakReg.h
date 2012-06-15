#include <windows.h>
#include <winreg.h>
#include "GWin.h"

#define SWidth	4

#define IS_SPACE(c)	((c) == ' ' || (c) == '\r' || (c) == '\n' || (c) == '\t')
#define SWAP(a, b) { (a) += (b); (b) = (a) - (b); (a) = (a) - (b); }

void PrintError(HWND hWnd, LPSTR lpHint, DWORD e);
void RegClose(HKEY hKeyS, HKEY hKeyD);
INT PreKey(LPSTR *lpStr);
int PerCmdLine(LPSTR lpCmdLine, HKEY *hKeyS, HKEY *hKeyD, LPSTR *strNameS, LPSTR *strNamsD);
