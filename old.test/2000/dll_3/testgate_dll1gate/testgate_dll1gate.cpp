// testgate_dll1gate.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

extern "C" int _cdecl f1();		// import from testgate_dll1old

int _stdcall f1new() {
	MessageBox(NULL, "now show the original f1(), press ok please....", NULL, 0);
	f1();
	return 0;
}

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}
