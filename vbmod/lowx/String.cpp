
#include "stdafx.h"
#include "LowX.h"
#include "String.h"

/////////////////////////////////////////////////////////////////////////////
// CString


STDMETHODIMP CString::LenA(long pStr, long *pRet)
{
	if (m_bTestValid) if (IsBadStringPtrA((LPCSTR)pStr, 0x7FFFFFFFul)) return E_POINTER;
	*pRet = ::lstrlenA((LPSTR)pStr);
	return S_OK;
}

STDMETHODIMP CString::LenW(long pStr, long *pRet)
{
	if (m_bTestValid) if (IsBadStringPtrW((LPCWSTR)pStr, 0x7FFFFFFFul)) return E_POINTER;
	*pRet = ::lstrlenW((LPWSTR)pStr);
	return S_OK;
}

STDMETHODIMP CString::LenM(long pStr, long *pRet)
{
	if (m_bTestValid) if (IsBadStringPtrA((LPCSTR)pStr, 0x7FFFFFFFul)) return E_POINTER;
	*pRet = ::_mbslen((LPBYTE)pStr);
	return S_OK;
}


STDMETHODIMP CString::get_TestValid(VARIANT_BOOL *pVal)
{
	*pVal = (VARIANT_BOOL)m_bTestValid;
	return S_OK;
}

STDMETHODIMP CString::put_TestValid(VARIANT_BOOL newVal)
{
	m_bTestValid = (BOOL)newVal;
	return S_OK;
}
