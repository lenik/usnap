// Mfc1_Imp1_Client2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#define INITGUID
#include <objbase.h>
#include <winerror.h>

#include "..\mfc_com3\Mfc1_Interface.h"

STDAPI	DllRegisterServer();
STDAPI	DllUnregisterServer();
STDAPI	DllGetClassObject(REFCLSID, REFIID, LPVOID *);
STDAPI	DllCanUnloadNow();

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	LPCLASSFACTORY		pIClassFactory	= NULL;
	LPMFC1_INTERFACE1	pI1		= NULL;
	LPMFC1_INTERFACE2	pI2		= NULL;
	LPVOID			pI3		= NULL;
	HRESULT			hr;

	CoInitialize(NULL);

	hr	= CoGetClassObject(
		CLSID_Mfc1,
		CLSCTX_INPROC_SERVER,
		NULL,
		IID_IClassFactory,
		(LPVOID *)&pIClassFactory
		);

	if (SUCCEEDED(hr)) {
		hr	= pIClassFactory->CreateInstance(
				NULL,
				IID_IMfc1_Interface1,
				(LPVOID *)&pI1);
		if (SUCCEEDED(hr)) {
			pI1->I1_Method1();
			pI1->Release();
		}
		hr	= pIClassFactory->CreateInstance(
				NULL,
				IID_IMfc1_Interface2,
				(LPVOID *)&pI2);
		if (SUCCEEDED(hr)) {
			pI2->I2_Method1();
			pI2->Release();
		}
		hr	= pIClassFactory->CreateInstance(
				NULL,
				IID_IMfc1_Interface3,
				(LPVOID *)&pI3);
		if (FAILED(hr)) {
			MessageBox(NULL, "Failed to create instance of IID_IMfc1_Interface3 \n from CLSID_Mfc1!", NULL, MB_OK);
		}

		pIClassFactory->Release();
	}

	CoUninitialize();

	return 0;
}