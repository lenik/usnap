// DLL_throw.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "DLL_throw.h"

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


// This is an example of an exported function.
DLL_THROW_API int fnDLL_throw(void)
{
	CDLL_throw_exception *e = new CDLL_throw_exception("error 1");
	throw e;
	return 0;
}

// This is the constructor of a class that has been exported.
// see DLL_throw.h for the class definition
CDLL_throw::CDLL_throw()
{
	return;
}

CDLL_throw_exception::CDLL_throw_exception(char *desc) {
	this->description = desc;
	return;
}

void CDLL_throw_exception::msg() {
	MessageBox(NULL, this->description, this->description, MB_OK);
}
