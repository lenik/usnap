// gdi32_arc_func.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

BOOL _stdcall Arc(HDC hdc, int a, int b, int c, int d, int e, int f, int g, int h) {
	return 0;
}
