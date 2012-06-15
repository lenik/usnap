
#include "EnumProcess.h"

BOOL CALLBACK EnumWindowProc(HWND hWnd, LPARAM lParam) {
	*(HWND *)lParam = hWnd;
	return TRUE;
}

BOOL EPAPI PASCAL EnumProcess(HWND &hWnd, BOOL FirstTime) {
	return EnumWindows(EnumWindowProc, (LPARAM)&hWnd);
}
