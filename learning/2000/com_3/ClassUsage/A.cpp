// A.cpp : Implementation of CClassUsageApp and DLL registration.

#include "stdafx.h"
#include "ClassUsage.h"
#include "A.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CA::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_IA,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CA::run() {
	MessageBox(NULL, _T("Hello"), NULL, MB_OK);
	return S_OK;
}

void x() {
	CAu c1;
}
