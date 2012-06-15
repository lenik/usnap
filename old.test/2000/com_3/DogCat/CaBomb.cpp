// CaBomb.cpp : Implementation of CDogCatApp and DLL registration.

#include "stdafx.h"
#include "DogCat.h"
#include "CaBomb.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CCaBomb::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_ICaBomb,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CCaBomb::bomb()
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CCaBomb::get_p1(long *pVal)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CCaBomb::put_p1(long newVal)
{
	// TODO: Add your implementation code here

	return S_OK;
}
