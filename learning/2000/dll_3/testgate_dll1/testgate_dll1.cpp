// testgate_dll1.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "testgate_dll1.h"

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}


int _stdcall f1() {
	MessageBox(NULL, "Hello!", "Original dll", MB_OK);
	return 0;
}

int _cdecl f1c() {
	return 0;
}
