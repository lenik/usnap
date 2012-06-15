// _DynamicCode_1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	BYTE codes[1000];

codestart:
	_asm {
		mov ax, 1234h
		ret
	}

	memcpy(codes, codestart, 100);
	_asm {
		call offset codes
	}

	return 0;
}
