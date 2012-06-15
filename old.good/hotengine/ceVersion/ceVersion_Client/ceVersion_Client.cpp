// ceVersion_Client.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#define INITGUID
#include <objbase.h>
#include <winerror.h>
#include "..\ceVersion\ceVersion.h"
#include "..\ceVersion\ceVersion_i.c"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	ICeVersion	*pCeVersion	= NULL;
	HRESULT		hr;

	CoInitialize(NULL);
	hr	= CoCreateInstance(
		CLSID_CeVersionSimple,
		NULL,
		CLSCTX_SERVER,
		IID_ICeVersion,
		(LPVOID *)&pCeVersion);

	if (SUCCEEDED(hr)) {
		pCeVersion->AboutBox();
		pCeVersion->Release();
	}

	CoUninitialize();

	return 0;
}