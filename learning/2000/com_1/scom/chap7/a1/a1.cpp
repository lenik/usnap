// a1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream.h>

#include "IFace.h"

void trace(const char *msg) {
	cout << "Client: \t" << msg << endl;
}

int main() {

	CoInitialize(NULL);

	trace("Call CoGetClassObject to create a class factory. ");

	IClassFactory *pIClassFactory = NULL;
	IX *pIX = NULL;
/*
	HRESULT hr = ::CoCreateInstance(
		CLSID_Component1,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IX,
		(void **)&pIX);
*/

	HRESULT hr = ::CoGetClassObject(
		CLSID_Component1,
		CLSCTX_INPROC_SERVER,
		NULL,
		IID_IClassFactory,
		(void **)&pIClassFactory);
	if (FAILED(hr)) {
		trace("Could not create a class factory. \n");
		CoUninitialize();
		return 0;
	}

	trace("Call IClassFactory::CreateInstance to create component and get IX\n");
	hr = pIClassFactory->CreateInstance(NULL, IID_IX, (LPVOID *)&pIX);

	if (SUCCEEDED(hr)) {
		trace("Succeeded getting IX. ");
		pIX->Fx();

		trace("Ask for interface IY. ");
		IY *pIY = NULL;
		hr = pIX->QueryInterface(IID_IY, (void **)&pIY);
		if (SUCCEEDED(hr)) {
			trace("Succeeded getting IY. ");
			pIY->Fy();
			pIY->Release();
			trace("Release IY interface");
		} else {
			trace("Could not get interface IY");
		}
		trace("Ask for interface IZ. ");
		IZ *pIZ = NULL;
		hr = pIX->QueryInterface(IID_IZ, (void **)&pIZ);
		if (SUCCEEDED(hr)) {
			trace("Succeeded getting IZ. ");
			pIZ->Fz();
			pIZ->Release();
			trace("Release IZ interface");
		} else {
			trace("Could not get interface IZ");
		}
		trace("Release IX interface");
		pIX->Release();
	} else {
		cout << "Client: \t\tCould not create component. hr = " << hex << hr << endl;
	}

	CoUninitialize();

	return 0;
}
