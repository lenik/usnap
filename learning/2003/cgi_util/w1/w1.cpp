// w1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	char *what = "Hello, world!";
	float x = 1.0;
	double y = 1.0;

	goto p2;
	_asm {
		push	0
		push	0
		push	what
		push	0
		call	MessageBoxA
	}
p2:
	MessageBox(NULL, "Hello, world!fhasdkfhjkl;kvl;jkt9ertuiortprtuioetuopewertuitwruioert", "Exavxzxvzxcvcvzxcvzvmple 01", MB_YESNOCANCEL);

	return 0;
}
