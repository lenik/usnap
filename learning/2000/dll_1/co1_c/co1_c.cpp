// co1_c.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string.h>
#include <ole2ver.h>
#define INITGUID
#include <objbase.h>
#include <winerror.h>
#include "..\co1\co1.h"

BOOL	InitCOM() {
	DWORD coVersion = CoBuildVersion();
	if (HIWORD(coVersion) != rmm || LOWORD(coVersion) < rup) {
		printf("Bad version of COM!\n");
		return FALSE;
	}

	HRESULT hErr = CoInitialize(NULL);
	if (FAILED(GetScode(hErr))) {
		printf("Failed to initialize OLE!\n");
		return FALSE;
	}
	return TRUE;
}

void	DeinitCOM() {
	CoUninitialize();
}

int main(int argc, char* argv[])
{
	HRESULT hErr;
	LPBEEP pBeep;
	LPUNKNOWN pUnk;
	LPCLASSFACTORY pCf;
	if (!InitCOM()) return -1;

	//
	printf("Method 1: Using CoGetClassObject() - ");
	hErr = CoGetClassObject(
		CLSID_IBeep,
		CLSCTX_INPROC,
		NULL,
		IID_IClassFactory,
		(LPVOID *)&pCf);
	if (FAILED(hErr)) {
		printf("failed!\n");
	} else {
		printf("Createing the Beep object.-.");
		hErr = pCf->CreateInstance(NULL, IID_IBeep, (LPVOID *)&pBeep);
		pCf->Release();

		if (FAILED(hErr)) {
			printf("failed in create beep object. \n");
		} else {
			printf("succeeded in geting beep object. \n");

			pBeep->DoBeep(-1);
			pBeep->Release();
		}
	}

	printf("Method 2: Using CoCreateInstance - ");
	hErr = CoCreateInstance(CLSID_IBeep, NULL, CLSCTX_INPROC_SERVER,
		IID_IUnknown, (LPVOID *)&pUnk);
	if (FAILED(hErr)) {
		printf("failed in call CoCreateInstance");
	} else {
		printf("succeeded in call CoCreateInstance. \n");
		pUnk->QueryInterface(IID_IBeep, (LPVOID *)&pBeep);
		pUnk->Release();
		if (pBeep != NULL) {
			pBeep->DoBeep(-1);
			pBeep->Release();
		}
	}

	DeinitCOM();
	printf("done\n");
	return 0;
}
