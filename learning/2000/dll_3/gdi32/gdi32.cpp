// gdi32.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include <stdio.h>

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

//BOOL Arc(HDC, int, int, int, int, int, int, int, int);

BOOL _stdcall Arc_proxy(HDC hdc, int a, int b, int c, int d, int e, int f, int g, int h) {
	MessageBox(NULL, "Arx_proxy", NULL, 0);
	return Arc(hdc, a, b, c, d, e, f, g, h);
}
