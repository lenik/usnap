// ED_Client1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "../EasyDialog/EasyDialog.h"
#include "../EasyDialog/EasyDialog_i.c"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	CoInitialize(NULL);

	HRESULT hr;
	ICaEDViewer	*pCaEDViewer = NULL;
	ICaEDSmalls	*pCaEDSmalls = NULL;

	hr = CoCreateInstance(
		CLSID_CaEDViewer,
		NULL,
		CLSCTX_SERVER,
		IID_ICaEDViewer,
		(LPVOID *)&pCaEDViewer);

	hr = CoCreateInstance(
		CLSID_CaEDSmalls,
		NULL, CLSCTX_SERVER,
		IID_ICaEDSmalls,
		(LPVOID *)&pCaEDSmalls);

	if (SUCCEEDED(hr)) {
		int r;
	//	pCaEDViewer->DoModal(&r);
		pCaEDViewer->Release();

		pCaEDSmalls->DoPrompt(&r);
		pCaEDSmalls->Release();
	} else {
		MessageBox(NULL, "Error creating instance of CaEDViewer!", NULL, MB_OK);
	}

	CoUninitialize();

	return 0;
}
