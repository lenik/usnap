// Mfc1_Imp1_Client1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#define INITGUID
#include <objbase.h>
#include <winerror.h>

#include "..\mfc_com3\Mfc1_Interface.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	IMfc1_Interface1	*pI1	= NULL;
	IMfc1_Interface2	*pI2	= NULL;
	VOID			*pI3	= NULL;

	HRESULT			hr;

	CoInitialize(NULL);

	hr	= CoCreateInstance(
		CLSID_Mfc1,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IMfc1_Interface1,
		(LPVOID *)&pI1);

	if (SUCCEEDED(hr)) {
		pI1->I1_Method1();
		pI1->Release();
	}

	hr	= CoCreateInstance(
		CLSID_Mfc1,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IMfc1_Interface2,
		(LPVOID *)&pI2);

	if (SUCCEEDED(hr)) {
		pI2->I2_Method1();
		pI2->Release();
	}

	hr	= CoCreateInstance(
		CLSID_Mfc1,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IMfc1_Interface3,
		(LPVOID *)&pI3);

	if (FAILED(hr)) {
		MessageBox(NULL, "Failed in get IID_IMfc1_Interface3 from CLSID_Mfc1", NULL, MB_OK);
	}

	CoUninitialize();

	return 0;
}