// DLL_var1.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

int i;

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	i = 0;
	return TRUE;
}

int _stdcall geti() {
	return i;
}

void _stdcall seti(int ni) {
	i = ni;
	return;
}
