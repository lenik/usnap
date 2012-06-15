// Memory.cpp : Implementation of CMemory
#include "stdafx.h"
#include "LowX.h"
#include "Memory.h"

/////////////////////////////////////////////////////////////////////////////
// CMemory


STDMETHODIMP CMemory::CopyBytes(long pDest, long pSrc, long cBytes)
{
	if (m_bTestValid) {
		if (::IsBadReadPtr((void *)pSrc, cBytes)) return E_POINTER;
		if (::IsBadWritePtr((void *)pDest, cBytes)) return E_POINTER;
	}

	try {
		memcpy((void *)pDest, (void *)pSrc, cBytes);
	} catch(...) {
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CMemory::get_TestValid(VARIANT_BOOL *pVal)
{
	*pVal = (VARIANT_BOOL)m_bTestValid;
	return S_OK;
}

STDMETHODIMP CMemory::put_TestValid(VARIANT_BOOL newVal)
{
	m_bTestValid = (BOOL)newVal;
	return S_OK;
}
