// StdFileTypeVerifier.cpp : Implementation of CStdFileTypeVerifier
#include "stdafx.h"
#include "HDR_StdLib.h"
#include "StdFileTypeVerifier.h"

/////////////////////////////////////////////////////////////////////////////
// CStdFileTypeVerifier

struct BytesAccessor {
    IBytesBlock *   m_pBinary;
    DWORD           m_cbSize;

    BYTE            Byte(const DWORD Index, bool *ret);
    WORD            Word(const DWORD Index, bool *ret);
    DWORD           Dword(const DWORD Index, bool *ret);

    BytesAccessor(IBytesBlock *pBytesBlock);
};

BytesAccessor::BytesAccessor(IBytesBlock *pBytesBlock) {
    m_pBinary = pBytesBlock;
    ASSERT(m_pBinary);

    HRESULT hr;
    hr = m_pBinary->GetSize(&m_cbSize);
    ASSERT(SUCCEEDED(hr));
}

BYTE& BytesAccessor::Byte(const DWORD Index, bool *ret) {
    DWORD dwOffset = Index;
    BYTE buf[1];
    HRESULT hr;
    if (dwOffset >= m_cbSize) {
        if (ret) *ret = false;
        return 0;
    }
    hr = m_pBinary->Read(dwOffset, 1, buf);
    if (FAILED(hr)) {
        if (ret) *ret = false;
        return 0;
    }
    if (ret) *ret = TRUE;
    return *(BYTE *)buf;
}

WORD BytesAccessor::Word(DWORD Index, bool *ret) {
    DWORD dwOffset = Index * 2;
    BYTE buf[2];
    HRESULT hr;
    if (dwOffset + 1 >= m_cbSize) {
        if (ret) *ret = false;
        return 0;
    }
    hr = m_pBinary->Read(dwOffset, 2, buf);
    if (FAILED(hr)) {
        if (ret) *ret = false;
        return 0;
    }
    if (ret) *ret = true;
    return *(WORD *)buf;
}

DWORD BytesAccessor::Dword(const DWORD Index, bool *ret) {
    DWORD dwOffset = Index * 4;
    HRESULT hr;
    BYTE buf[4];
    if (dwOffset + 3 >= m_cbSize) {
        if (ret) *ret = false;
        return 0;
    }
    hr = m_pBinary->Read(dwOffset, 4, buf);
    if (FAILED(hr)) {
        if (ret) *ret = false;
        return 0;
    }
    if (ret) *ret = true;
    return *(DWORD *)buf;
}

struct ExtTypeMap {
    LPCTSTR szName;
    DWORD   dwType;
};
enum StdTypeConstants {
    stPE,
    stRiff,
    stOleStg,
    stBmp,
    stJpeg,
};

ExtTypeMap g_types[] = {
    { _T("exe"), stPE },
    { _T("dll"), stPE },
    { _T("ocx"), stPE },
    { _T("bmp"), stBmp ),
    { _T("jpg"), stJpeg },
    { _T("jpeg"), stJpeg },
    { _T("mid"), stRiff },
    { _T("wav"), stRiff },
    { _T("xls"), stOleStg },
    { _T("ppt"), stOleStg },
};
int g_types_count = sizeof(g_types) / sizeof(g_types[0]);

BOOL VerifyFile(LPCTSTR szExt, IBytesBlock *pBinary) {
    ASSERT(szExt && pBinary);
    BytesAccessor accessor(pBinary);

    bool bFound = false;
    for (int i = 0; i < g_types_count; i++) {
        if (!lstrcmp(g_types[i].szName, szExt)) {
            bFound = true;
            break;
        }
    }
    if (!bFound) return FALSE;

    DWORD dw;
    bool ret;
    switch (g_types[i].dwType) {
    case stPE:
        dw = accessor.Word(0, &ret);
        if (!ret || dw != 0x5A4D) return FALSE;
        break;
    case stRiff:
        dw = accessor.Dword(0, &ret);
        if (!ret || dw != '') return FALSE;
        break;
    case stBmp:
        dw = accessor.Word(0, &ret);
        if (!ret || dw != 0x4D42) return FALSE;
        break;
    case stJpeg:
        // (FF D8 FF E0) 00 10 (4A 46 49 46)
        dw = accessor.Dword(0, &ret);
        if (!ret || dw != 0xE0FFD8FF) return FALSE;
        break;
    case stOleStg:
        dw = accessor.Dword(0, &ret);
        if (!ret || dw != 0xE011CFD0
    default:
        ASSERT(FALSE);
        return FALSE;
    }
    return TRUE;
}

// Don't consider large file.



STDMETHODIMP CStdFileTypeVerifier::get_ExtensionsCount(long *pVal)
{
    if (pVal) return E_POINTER;
    *pVal = g_types_count;
	return S_OK;
}

STDMETHODIMP CStdFileTypeVerifier::get_Extension(long Index, BSTR *pVal)
{
	if (Index >= g_types_count) return E_INVALIDARG;
    if (!pVal) return E_POINTER;

    LPCTSTR szExt = g_types[Index].szName;
    *pVal = ::SysAllocString(_bstr_t(szExt));

	return S_OK;
}
