// ports.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}


extern "C" _declspec(dllexport) void _cdecl C_dllexport_cdecl() {}
extern "C" _declspec(dllexport) void _stdcall C_dllexport_stdcall() {}

_declspec(dllexport) void _cdecl NC_dllexport_cdecl() {}
_declspec(dllexport) void _stdcall NC_dllexport_stdcall() {}

extern "C" void _cdecl C__cdecl() {}
extern "C" void _stdcall C__stdcall() {}

void _cdecl NC__cdecl() {}
void _stdcall NC__stdcall() {}
