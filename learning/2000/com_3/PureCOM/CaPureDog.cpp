// CaPureDog.cpp : Implementation of CPureCOMApp and DLL registration.

#include "stdafx.h"
#include "PureCOM.h"
#include "CaPureDog.h"

#define _CT(x)	::MessageBox(NULL, _T(x), _T("COM Trace"), MB_OK)

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CCaPureDog::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_ICaPureDog,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP
CCaPureDog::shout() {
	_CT("CCaPureDog::shout()");
	this->Fire_onBitten();
	return NOERROR;
}
