// ModuleProvider.cpp : Implementation of CModuleProvider
#include "stdafx.h"
#include "HDR_StdLib.h"
#include "ModuleProvider.h"

/////////////////////////////////////////////////////////////////////////////
// CModuleProvider

STDMETHODIMP CModuleProvider::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_IModuleProvider
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
