// Como1.cpp : Implementation of CComoApp and DLL registration.

#include "stdafx.h"
#include "como.h"
#include "Como1.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CComo1::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_IComo1,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
