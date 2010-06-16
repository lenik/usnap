// _BinDebug.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "_80x86.h"


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

/*
	_asm {
		mov eax, 11000000b
		bsf ebx, eax
	}
*/

	Cpu80x86_32 c32;
	DWORD s, d;
	s = 0x00000008;

	c32.BSF(d, s);

	return 0;
}
