// MyCom2_Client.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#define INITGUID
#include <objbase.h>
#include <winerror.h>

#include "..\MyCom2\MyCom2.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	CoInitialize(NULL);

	HRESULT hr;
	//IClassFactory *pIClassFactory;
	IMyCom2_Class1_Interface1 *p;

	hr	= CoCreateInstance(
		CLSID_MyCom2_Class1,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IMyCom2_Class1_Interface1,
		(LPVOID *)&p
		);

	if (FAILED(hr)) {
		MessageBox(NULL, "can't create instance. ", NULL, 0);
	} else {
		p->Popup();
		p->Release();
	}

	CoUninitialize();
	return 0;
}