// Ut1.cpp : Implementation of CUt1
#include "stdafx.h"
#include "UtFiles.h"
#include "Ut1.h"

#include <shellapi.h>

/////////////////////////////////////////////////////////////////////////////
// CUt1


STDMETHODIMP CUt1::GetDragFileNames(IDataObject *pData, int Index, BSTR *pName)
{
    if (!pData || Index < 0 || !pName) return E_INVALIDARG;

    HRESULT hr;
    FORMATETC fmt;

    fmt.cfFormat = CF_HDROP;
    fmt.ptd = NULL;
    fmt.dwAspect = DVASPECT_CONTENT;
    fmt.lindex = -1;
    fmt.tymed = TYMED_HGLOBAL;
	hr = pData->QueryGetData(&fmt);
    if (FAILED(hr)) return E_INVALIDARG;

    STGMEDIUM med;

    hr = pData->GetData(&fmt, &med);
    if (FAILED(hr)) return hr;

    HDROP hDrop = (HDROP)med.hGlobal;
    TCHAR buf[_MAX_PATH];
    UINT c;

    c = DragQueryFile(hDrop, Index, buf, _MAX_PATH);
    ReleaseStgMedium(&med);

    if (c <= 0) return E_INVALIDARG;

    *pName = _bstr_t(buf).copy();

	return S_OK;
}


STDMETHODIMP CUt1::GetDragFileNamesCount(IDataObject *pData, int *pVal)
{
    if (!pData || !pVal) return E_INVALIDARG;

    HRESULT hr;
    FORMATETC fmt;

    fmt.cfFormat = CF_HDROP;
    fmt.ptd = NULL;
    fmt.dwAspect = DVASPECT_CONTENT;
    fmt.lindex = -1;
    fmt.tymed = TYMED_HGLOBAL;
	hr = pData->QueryGetData(&fmt);
    if (FAILED(hr)) return E_INVALIDARG;

    STGMEDIUM med;

    hr = pData->GetData(&fmt, &med);
    if (FAILED(hr)) return hr;

    HDROP hDrop = (HDROP)med.hGlobal;
    TCHAR buf[_MAX_PATH];
    UINT c;

    c = DragQueryFile(hDrop, -1, buf, _MAX_PATH);
    ReleaseStgMedium(&med);

    *pVal = c;

    return S_OK;
}
