
#include "..\\EnumProcess.h"

int WINAPI WinMain(
				   HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine,
				   int nShowCmd) {
	HWND hWnd;
	char name[1023];
	for (; EnumProcess(hWnd); )
		GetWindowText(hWnd, name, 300);
	return 0;
}
