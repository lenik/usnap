// MyCom1_Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define INITGUID
#include <objbase.h>
#include <winerror.h>

#include "..\MyCom1\Ellipse.h"

int main(int argc, char* argv[])
{
	CoInitialize(NULL);

	LPBoxGraph	pbg;
	HRESULT		hr;

	hr	= CoCreateInstance(
		CLSID_BoxGraph, NULL, CLSCTX_INPROC_SERVER,
		IID_IEllipse,
		(LPVOID *)&pbg);

	if (SUCCEEDED(hr)) {
		pbg->setPos(10, 10, 240, 240);
		pbg->draw(NULL);

		pbg->Release();
	}

	CoUninitialize();

	return 0;
}
