// Command.cpp : Implementation of CCommand
#include "stdafx.h"
#include "Mapping.h"
#include "Command.h"

/////////////////////////////////////////////////////////////////////////////
// CCommand

STDMETHODIMP CCommand::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_ICommand
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
