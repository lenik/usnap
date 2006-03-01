// Recordset.cpp : Implementation of CRecordset
#include "stdafx.h"
#include "Mapping.h"
#include "Recordset.h"

/////////////////////////////////////////////////////////////////////////////
// CRecordset

STDMETHODIMP CRecordset::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_IRecordset
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
