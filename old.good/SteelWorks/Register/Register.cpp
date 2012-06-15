// Register.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

BOOL	_stdcall Register(LPTSTR id, LPTSTR regid) {
	LONG	l = lstrlen(id);
	for (LONG p = 0; p < l; p++) {
		if (regid[p] != 0x30 + id[p] % 10)
			return FALSE;
	}
	return TRUE;
}

LPTSTR	_stdcall RegisterVal(LPTSTR id) {
	LONG	l = lstrlen(id);
	LPTSTR	retval = new TCHAR[100];
	for (LONG p = 0; p < l; p++) {
		retval[p] = 0x30 + id[p] % 10;
	}
	retval[p] = 0;
	return retval;
}

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}
