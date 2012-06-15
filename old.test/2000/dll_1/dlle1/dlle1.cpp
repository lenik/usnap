// dlle1.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "dlle1.h"

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


// This is an example of an exported variable
DLLE1_API int nDlle1=0;

// This is an example of an exported function.
DLLE1_API int fnDlle1(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see dlle1.h for the class definition
CDlle1::CDlle1()
{
	return;
}
