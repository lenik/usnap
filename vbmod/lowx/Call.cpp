// Call.cpp : Implementation of CCall
#include "stdafx.h"
#include "LowX.h"
#include "Call.h"

#include <stdarg.h>


/////////////////////////////////////////////////////////////////////////////
// CCall

STDMETHODIMP CCall::Call0(long pCallback, long *pRet)
{
	if (pCallback == NULL) return E_INVALIDARG;
	*pRet = ((long (_stdcall *)())pCallback)();
	return S_OK;
}

STDMETHODIMP CCall::Call1(long pCallback, long lParam1, long *pRet)
{
	if (pCallback == NULL) return E_INVALIDARG;
	*pRet = ((long (_stdcall *)(long))
		pCallback)(lParam1);
	return S_OK;
}

STDMETHODIMP CCall::Call2(long pCallback, long lParam1, long lParam2, long *pRet)
{
	if (pCallback == NULL) return E_INVALIDARG;
	*pRet = ((long (_stdcall *)(long, long))
		pCallback)(lParam1, lParam2);
	return S_OK;
}

STDMETHODIMP CCall::Call3(long pCallback, long lParam1, long lParam2, long lParam3, long *pRet)
{
	if (pCallback == NULL) return E_INVALIDARG;
	*pRet = ((long (_stdcall *)(long, long, long))
		pCallback)(lParam1, lParam2, lParam3);
	return S_OK;
}

STDMETHODIMP CCall::Call4(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long *pRet)
{
	if (pCallback == NULL) return E_INVALIDARG;
	*pRet = ((long (_stdcall *)(long, long, long, long))
		pCallback)(lParam1, lParam2, lParam3, lParam4);
	return S_OK;
}

STDMETHODIMP CCall::Call5(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long *pRet)
{
	if (pCallback == NULL) return E_INVALIDARG;
	*pRet = ((long (_stdcall *)(long, long, long, long, long))
		pCallback)(lParam1, lParam2, lParam3, lParam4, lParam5);
	return S_OK;
}

STDMETHODIMP CCall::Call6(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long *pRet)
{
	if (pCallback == NULL) return E_INVALIDARG;
	*pRet = ((long (_stdcall *)(long, long, long, long, long, long))
		pCallback)(lParam1, lParam2, lParam3, lParam4, lParam5, lParam6);
	return S_OK;
}

STDMETHODIMP CCall::Call7(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long *pRet)
{
	if (pCallback == NULL) return E_INVALIDARG;
	*pRet = ((long (_stdcall *)(long, long, long, long, long, long, long))
		pCallback)(lParam1, lParam2, lParam3, lParam4, lParam5, lParam6, lParam7);
	return S_OK;
}

STDMETHODIMP CCall::Call8(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long *pRet)
{
	if (pCallback == NULL) return E_INVALIDARG;
	*pRet = ((long (_stdcall *)(long, long, long, long, long, long, long, long))
		pCallback)(lParam1, lParam2, lParam3, lParam4, lParam5, lParam6, lParam7, lParam8);
	return S_OK;
}

STDMETHODIMP CCall::Call9(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long lParam9, long *pRet)
{
	if (pCallback == NULL) return E_INVALIDARG;
	*pRet = ((long (_stdcall *)(long, long, long, long, long, long, long, long, long))
		pCallback)(lParam1, lParam2, lParam3, lParam4, lParam5, lParam6, lParam7, lParam8, lParam9);
	return S_OK;
}

STDMETHODIMP CCall::Call10(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long lParam9, long lParam10, long *pRet)
{
	if (pCallback == NULL) return E_INVALIDARG;
	*pRet = ((long (_stdcall *)(long, long, long, long, long, long, long, long, long, long))
		pCallback)(lParam1, lParam2, lParam3, lParam4, lParam5, lParam6, lParam7, lParam8, lParam9, lParam10);
	return S_OK;
}

STDMETHODIMP CCall::Call11(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long lParam9, long lParam10, long lParam11, long *pRet)
{
	if (pCallback == NULL) return E_INVALIDARG;
	*pRet = ((long (_stdcall *)(long, long, long, long, long, long, long, long, long, long, long))
		pCallback)(lParam1, lParam2, lParam3, lParam4, lParam5, lParam6, lParam7, lParam8, lParam9, lParam10, lParam11);
	return S_OK;
}

STDMETHODIMP CCall::Call12(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long lParam9, long lParam10, long lParam11, long lParam12, long *pRet)
{
	if (pCallback == NULL) return E_INVALIDARG;
	*pRet = ((long (_stdcall *)(long, long, long, long, long, long, long, long, long, long, long, long))
		pCallback)(lParam1, lParam2, lParam3, lParam4, lParam5, lParam6, lParam7, lParam8, lParam9, lParam10, lParam11, lParam12);
	return S_OK;
}

STDMETHODIMP CCall::Call13(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long lParam9, long lParam10, long lParam11, long lParam12, long lParam13, long *pRet)
{
	if (pCallback == NULL) return E_INVALIDARG;
	*pRet = ((long (_stdcall *)(long, long, long, long, long, long, long, long, long, long, long, long, long))
		pCallback)(lParam1, lParam2, lParam3, lParam4, lParam5, lParam6, lParam7, lParam8, lParam9, lParam10, lParam11, lParam12, lParam13);
	return S_OK;
}

STDMETHODIMP CCall::Call14(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long lParam9, long lParam10, long lParam11, long lParam12, long lParam13, long lParam14, long *pRet)
{
	if (pCallback == NULL) return E_INVALIDARG;
	*pRet = ((long (_stdcall *)(long, long, long, long, long, long, long, long, long, long, long, long, long, long))
		pCallback)(lParam1, lParam2, lParam3, lParam4, lParam5, lParam6, lParam7, lParam8, lParam9, lParam10, lParam11, lParam12, lParam13, lParam14);
	return S_OK;
}

STDMETHODIMP CCall::Call15(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long lParam9, long lParam10, long lParam11, long lParam12, long lParam13, long lParam14, long lParam15, long *pRet)
{
	if (pCallback == NULL) return E_INVALIDARG;
	*pRet = ((long (_stdcall *)(long, long, long, long, long, long, long, long, long, long, long, long, long, long, long))
		pCallback)(lParam1, lParam2, lParam3, lParam4, lParam5, lParam6, lParam7, lParam8, lParam9, lParam10, lParam11, lParam12, lParam13, lParam14, lParam15);
	return S_OK;
}

STDMETHODIMP CCall::Call16(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long lParam9, long lParam10, long lParam11, long lParam12, long lParam13, long lParam14, long lParam15, long lParam16, long *pRet)
{
	if (pCallback == NULL) return E_INVALIDARG;
	*pRet = ((long (_stdcall *)(long, long, long, long, long, long, long, long, long, long, long, long, long, long, long, long))
		pCallback)(lParam1, lParam2, lParam3, lParam4, lParam5, lParam6, lParam7, lParam8, lParam9, lParam10, lParam11, lParam12, lParam13, lParam14, lParam15, lParam16);
	return S_OK;
}


////////////////////////////////////////////////////////////////////////////////////////////////
//
// custom calls
//
LONG _stdcall _call_pascal(void *proc, int vacount, int extra_release, LPINT pva) {
	LONG retval = -1;
	int i = 0, val;
	extra_release = extra_release * sizeof(int);

	for (i = 0; i < vacount; i++) {
		val = pva[vacount - 1 - i];
		_asm push val;
	}
	_asm call proc;
	//vacount = vacount * 4 - extra_release;
	//_asm add esp, vacount;
	_asm add esp, extra_release;
	_asm mov retval, eax;
	return retval;
}

LONG _stdcall _call_cdecl(void *proc, int vacount, int extra_release, LPINT pva) {
	LONG retval = -1;
	int i = 0, val;
	extra_release = extra_release * sizeof(int);

	for (i = 0; i < vacount; i++) {
		val = pva[vacount - 1 - i];
		_asm push val;
	}
	_asm call proc;
	vacount = vacount * 4 - extra_release;
	_asm add esp, vacount;
	_asm add esp, extra_release;
	_asm mov retval, eax;
	return retval;
}

LONG _stdcall _call_thiscall_pascal(void *proc, void *pthis, int vacount, int extra_release, LPINT pva) {
	LONG retval = -1;
	int i = 0, val;
	extra_release = extra_release * sizeof(int);

	_asm mov ecx, pthis
	_asm push pthis
	for (i = 0; i < vacount; i++) {
		val = pva[vacount - 1 - i];
		_asm push val;
	}
	_asm call proc;
	//vacount = vacount * 4 - extra_release;
	//_asm add esp, vacount;
	_asm add esp, extra_release;
	_asm mov retval, eax;
	return retval;
}

LONG _stdcall _call_thiscall_cdecl(void *proc, void *pthis, int vacount, int extra_release, LPINT pva) {
	LONG retval = -1;
	int i = 0, val;
	extra_release = extra_release * sizeof(int);

	_asm mov ecx, pthis;
	_asm push pthis;
	for (i = 0; i < vacount; i++) {
		val = pva[vacount - 1 - i];
		_asm push val;
	}
	_asm call proc;
	vacount = vacount * 4 - extra_release;
	_asm add esp, vacount;
	_asm add esp, extra_release;
	_asm mov retval, eax;
	return retval;
}


LONG _stdcall call_pascal(void *proc, int vacount, int extra_release, ...) {
	LONG retval = -1;
	int i = 0, val;
	LPINT pva = NULL;

	va_list args;
	va_start(args, extra_release);

	if (vacount < 0) {
		vacount = 0;
		while (val = va_arg(args, int)) vacount++;
		va_end(args);
		va_start(args, extra_release);
	}
	pva = new int[vacount];
	for (i = 0; i < vacount; i++) {
		pva[i] = va_arg(args, int);
	}
	va_end(args);
	retval = _call_pascal(proc, vacount, extra_release, pva);
	delete[] pva;
	return retval;
}

LONG _stdcall call_cdecl(void *proc, int vacount, int extra_release, ...) {
	LONG retval = -1;
	int i = 0, val;
	LPINT pva = NULL;

	va_list args;
	va_start(args, extra_release);

	if (vacount < 0) {
		vacount = 0;
		while (val = va_arg(args, int)) vacount++;
		va_end(args);
		va_start(args, extra_release);
	}
	pva = new int[vacount];
	for (i = 0; i < vacount; i++) {
		pva[i] = va_arg(args, int);
	}
	va_end(args);
	retval = _call_cdecl(proc, vacount, extra_release, pva);
	delete[] pva;
	return retval;
}

STDMETHODIMP CCall::Pascal(long pCallback, long cParameters, long cExtraReleases, long pParameters, long *pRet)
{
	if (pCallback == NULL ||
		(cParameters > 0 && pParameters == NULL)) return E_INVALIDARG;

	*pRet = _call_pascal((void *)pCallback, cParameters, cExtraReleases, (LPINT)pParameters);
	return S_OK;
}

STDMETHODIMP CCall::C(long pCallback, long cParameters, long cExtraReleases, long pParameters, long *pRet)
{
	if (pCallback == NULL ||
		(cParameters > 0 && pParameters == NULL)) return E_INVALIDARG;

	*pRet = _call_cdecl((void *)pCallback, cParameters, cExtraReleases, (LPINT)pParameters);
	return S_OK;
}

STDMETHODIMP CCall::ThisPascal(long pCallback, long pThis, long cParameters, long cExtraReleases, long pParameters, long *pRet)
{
	if (pCallback == NULL ||
		(cParameters > 0 && pParameters == NULL)) return E_INVALIDARG;

	*pRet = _call_thiscall_pascal((void *)pCallback, (void *)pThis, cParameters, cExtraReleases, (LPINT)pParameters);
	return S_OK;
}

STDMETHODIMP CCall::ThisC(long pCallback, long pThis, long cParameters, long cExtraReleases, long pParameters, long *pRet)
{
	if (pCallback == NULL ||
		(cParameters > 0 && pParameters == NULL)) return E_INVALIDARG;

	*pRet = _call_thiscall_cdecl((void *)pCallback, (void *)pThis, cParameters, cExtraReleases, (LPINT)pParameters);
	return S_OK;
}


STDMETHODIMP CCall::Dispatch(IDispatch *pObject, BSTR method, SAFEARRAY *pParams, VARIANT *pRetVal)
{
	// TODO: Add your implementation code here
	// pParams->cDims
	return S_OK;
}
