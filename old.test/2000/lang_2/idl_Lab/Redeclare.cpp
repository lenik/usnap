// Redeclare.cpp : Implementation of CIdl_LabApp and DLL registration.

#include "stdafx.h"
#include "idl_Lab.h"
#include "Redeclare.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CRedeclare::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_IRedeclare,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

//STDMETHODIMP CRedeclare::f1(IRedeclare *p1) {
STDMETHODIMP CRedeclare::f1(IDispatch *p1) {
	return S_OK;
}
