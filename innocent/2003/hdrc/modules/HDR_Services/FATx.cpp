// FATx.cpp : Implementation of CFATx
#include "stdafx.h"
#include "HDR_Services.h"
#include "FATx.h"

/////////////////////////////////////////////////////////////////////////////
// CFATx

STDMETHODIMP CFATx::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_IFSPMapper,
        &IID_IFSPReconstruct,
        &IID_IFSPRecstrMonitor,
        &IID_IFSPAddInsMgr,
        &IID_IFSPFATxParser,
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CFATx::get_FiltersCount(long *pVal)
{
	// TODO: Add your implementation code here

	return S_OK;
}
