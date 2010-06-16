// d1.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include <stdio.h>

char buf[1000];
HANDLE hModule;

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		::hModule = hModule;
		break;
	}
    return TRUE;
}

void _stdcall f1() {
	sprintf(buf, "Dll/hModule:%x", hModule);
	MessageBox(NULL, buf, NULL, 0);
}
