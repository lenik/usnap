// Connection.cpp : Implementation of CConnection
#include "stdafx.h"
#include "Mapping.h"
#include "Connection.h"

/////////////////////////////////////////////////////////////////////////////
// CConnection

STDMETHODIMP CConnection::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_IConnection
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
