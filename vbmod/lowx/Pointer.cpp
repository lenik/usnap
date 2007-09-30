// Pointer.cpp : Implementation of CPointer
#include "stdafx.h"
#include "LowX.h"
#include "Pointer.h"

/////////////////////////////////////////////////////////////////////////////
// CPointer



// properties
STDMETHODIMP CPointer::get_TestValid(VARIANT_BOOL *pVal)
{
	*pVal = (VARIANT_BOOL)m_bTestValid;
	return S_OK;
}

STDMETHODIMP CPointer::put_TestValid(VARIANT_BOOL newVal)
{
	m_bTestValid = (BOOL)newVal;
	return S_OK;
}

STDMETHODIMP CPointer::get_AutoReferenceManagement(VARIANT_BOOL *pVal)
{
	*pVal = (VARIANT_BOOL)m_bAutoRef;
	return S_OK;
}

STDMETHODIMP CPointer::put_AutoReferenceManagement(VARIANT_BOOL newVal)
{
	m_bAutoRef = (BOOL)newVal;
	return S_OK;
}

STDMETHODIMP CPointer::get_Base(long *pVal)
{
	*pVal = m_lBase;
	return S_OK;
}

STDMETHODIMP CPointer::put_Base(long newVal)
{
	m_lBase = newVal;
	return S_OK;
}



// utility
STDMETHODIMP CPointer::Eval(long val, long *pRet)
{
	*pRet = val;
	return S_OK;
}



// get pointer

STDMETHODIMP CPointer::pAny(VARIANT *refData, long *pRet)
{
	*pRet = (long)refData;
	return S_OK;
}

STDMETHODIMP CPointer::pByte(BYTE *refData, long *pRet)
{
	*pRet = (long)refData;
	return S_OK;
}

STDMETHODIMP CPointer::pWord(short *refData, long *pRet)
{
	*pRet = (long)refData;
	return S_OK;
}

STDMETHODIMP CPointer::pDword(long *refData, long *pRet)
{
	*pRet = (long)refData;
	return S_OK;
}

STDMETHODIMP CPointer::pStr(BSTR refData, long *pRet)
{
	*pRet = (long)refData;
	return S_OK;
}

STDMETHODIMP CPointer::ppStr(BSTR *refData, long *pRet)
{
	*pRet = (long)refData;
	return S_OK;
}

STDMETHODIMP CPointer::pFunc(long refData, long *pRet)
{
	*pRet = (long)refData;
	return S_OK;
}

STDMETHODIMP CPointer::pUnk(LPUNKNOWN refData, long *pRet)
{
	*pRet = (long)refData;
	return S_OK;
}

STDMETHODIMP CPointer::ppUnk(LPUNKNOWN *refData, long *pRet)
{
	*pRet = (long)refData;
	return S_OK;
}

STDMETHODIMP CPointer::pDisp(LPDISPATCH refData, long *pRet)
{
	*pRet = (long)refData;
	return S_OK;
}

STDMETHODIMP CPointer::ppDisp(LPDISPATCH *refData, long *pRet)
{
	*pRet = (long)refData;
	return S_OK;
}



// memory array
STDMETHODIMP CPointer::get_Byte(long lOffset, BYTE *pVal)
{
	void *p = (void *)(m_lBase + lOffset);
	if (m_bTestValid) if (::IsBadReadPtr(p, sizeof(BYTE))) return E_POINTER;

	*pVal = *(BYTE *)p;
	return S_OK;
}

STDMETHODIMP CPointer::put_Byte(long lOffset, BYTE newVal)
{
	void *p = (void *)(m_lBase + lOffset);
	if (m_bTestValid) if (::IsBadWritePtr(p, sizeof(BYTE))) return E_POINTER;

	*(BYTE *)p = newVal;
	return S_OK;
}

STDMETHODIMP CPointer::get_Word(long lOffset, short *pVal)
{
	void *p = (void *)(m_lBase + lOffset * sizeof(WORD));
	if (m_bTestValid) if (::IsBadReadPtr(p, sizeof(WORD))) return E_POINTER;

	*pVal = (short)*(WORD *)p;
	return S_OK;
}

STDMETHODIMP CPointer::put_Word(long lOffset, short newVal)
{
	void *p = (void *)(m_lBase + lOffset * sizeof(WORD));
	if (m_bTestValid) if (::IsBadWritePtr(p, sizeof(WORD))) return E_POINTER;

	*(WORD *)p = (WORD)newVal;
	return S_OK;
}

STDMETHODIMP CPointer::get_Dword(long lOffset, long *pVal)
{
	void *p = (void *)(m_lBase + lOffset * sizeof(DWORD));
	if (m_bTestValid) if (::IsBadReadPtr(p, sizeof(DWORD))) return E_POINTER;

	*pVal = (long)*(DWORD *)p;
	return S_OK;
}

STDMETHODIMP CPointer::put_Dword(long lOffset, long newVal)
{
	void *p = (void *)(m_lBase + lOffset * sizeof(DWORD));
	if (m_bTestValid) if (::IsBadWritePtr(p, sizeof(DWORD))) return E_POINTER;

	*(DWORD *)p = (DWORD)newVal;
	return S_OK;
}

STDMETHODIMP CPointer::get_Float(long lOffset, float *pVal)
{
	void *p = (void *)(m_lBase + lOffset * sizeof(float));
	if (m_bTestValid) if (::IsBadReadPtr(p, sizeof(float))) return E_POINTER;

	*pVal = *(float *)p;
	return S_OK;
}

STDMETHODIMP CPointer::put_Float(long lOffset, float newVal)
{
	void *p = (void *)(m_lBase + lOffset * sizeof(float));
	if (m_bTestValid) if (::IsBadWritePtr(p, sizeof(float))) return E_POINTER;

	*(float *)p = (float)newVal;
	return S_OK;
}

STDMETHODIMP CPointer::get_Double(long lOffset, double *pVal)
{
	void *p = (void *)(m_lBase + lOffset * sizeof(double));
	if (m_bTestValid) if (::IsBadReadPtr(p, sizeof(double))) return E_POINTER;

	*pVal = *(double *)p;
	return S_OK;
}

STDMETHODIMP CPointer::put_Double(long lOffset, double newVal)
{
	void *p = (void *)(m_lBase + lOffset * sizeof(double));
	if (m_bTestValid) if (::IsBadWritePtr(p, sizeof(double))) return E_POINTER;

	*(double *)p = (double)newVal;
	return S_OK;
}

STDMETHODIMP CPointer::get_Unk(long lOffset, LPUNKNOWN *pVal)
{
	void *p = (void *)(m_lBase + lOffset * sizeof(LPUNKNOWN));
	if (m_bTestValid) if (::IsBadReadPtr(p, sizeof(LPUNKNOWN))) return E_POINTER;

	*pVal = *(LPUNKNOWN *)p;
	return S_OK;
}

STDMETHODIMP CPointer::put_Unk(long lOffset, LPUNKNOWN newVal)
{
	void *p = (void *)(m_lBase + lOffset * sizeof(LPUNKNOWN));
	if (m_bTestValid) if (::IsBadWritePtr(p, sizeof(LPUNKNOWN))) return E_POINTER;

	*(LPUNKNOWN *)p = (LPUNKNOWN)newVal;
	return S_OK;
}

STDMETHODIMP CPointer::get_Disp(long lOffset, LPDISPATCH *pVal)
{
	void *p = (void *)(m_lBase + lOffset * sizeof(LPDISPATCH));
	if (m_bTestValid) if (::IsBadReadPtr(p, sizeof(LPDISPATCH))) return E_POINTER;

	*pVal = *(LPDISPATCH *)p;
	return S_OK;
}

STDMETHODIMP CPointer::put_Disp(long lOffset, LPDISPATCH newVal)
{
	void *p = (void *)(m_lBase + lOffset * sizeof(LPDISPATCH));
	if (m_bTestValid) if (::IsBadWritePtr(p, sizeof(LPDISPATCH))) return E_POINTER;

	*(LPDISPATCH *)p = (LPDISPATCH)newVal;
	return S_OK;
}
