// DLL_withmem.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "DLL_withmem.h"

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
DLL_WITHMEM_API int nDLL_withmem=0;

class Cimp1 : public CDLL_withmem {
public:
	virtual void m_F1();
};
void	Cimp1::m_F1() {
	MessageBox(NULL, "Cimp1::m_F1", NULL, MB_OKCANCEL);
}

// This is an example of an exported function.
DLL_WITHMEM_API int fnDLL_withmem(void)
{
	int	*pInt;
	MessageBox(NULL, "Hello!", NULL, MB_OKCANCEL);
	pInt	= new int;
	*pInt	= 1234;
	delete	pInt;
	return 42;
}

DLL_WITHMEM_API CDLL_withmem *fnDLL_getobject(void) {
	CDLL_withmem	*p;
	p	= new Cimp1;
	return p;
}

// This is the constructor of a class that has been exported.
// see DLL_withmem.h for the class definition
CDLL_withmem::CDLL_withmem()
{
	return;
}

CDLL_withmem *	_stdcall fn_getobject() {
	return fnDLL_getobject();
}
