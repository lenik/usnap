// Base64.cpp : Implementation of CBase64
#include "stdafx.h"
#include "Binary.h"
#include "Base64.h"
#include "kernel.h"
#include <iconv.h>
#include <comutil.h>

#ifndef CS_UNICODE
#define CS_UNICODE "utf16-le"
#endif

/////////////////////////////////////////////////////////////////////////////
// CBase64


void CBase64::clear() {
    if (m_Raw) {
        free(m_Raw);
        m_Raw = NULL;
    }
    if (m_Base64) {
        SysFreeString(m_Base64);
        m_Base64 = NULL;
    }
}

STDMETHODIMP CBase64::SetStringB(BSTR stringB)
{
    if (stringB == NULL) {
        clear();
        return S_OK;
    }

    // stringB -> m_Raw

    DWORD len = ((DWORD *)stringB)[-1];
    char *copy = NULL;

    if (len > 0) {
        copy = (char *)malloc(len);
        if (copy == NULL)
            return E_OUTOFMEMORY;
    }

    clear();
    m_Raw = copy;
    m_RawSize = len;

    ASSERT(m_Base64 == NULL);
	return S_OK;
}


STDMETHODIMP CBase64::SetString(BSTR stringUnicode, BSTR encoding)
{
    if (encoding == NULL)
        return E_INVALIDARG;

    if (stringUnicode == NULL) {
        clear();
        return S_OK;
    }

	// stringUnicode / encoding -> m_Raw

    DWORD len = ((DWORD *)stringUnicode)[-1];
    // DWORD cc = len / 2;

    const char *inbuf = (const char *)stringUnicode;
    size_t inbytesleft = len;

    // scaled by * 1.5 for safe purpose.
    size_t outbytesleft = inbytesleft * 3 / 2;
    char *outbuf = (char *)malloc(outbytesleft);

    if (outbuf == NULL)
        return E_OUTOFMEMORY;

    iconv_t cd = iconv_open(_bstr_t(encoding), CS_UNICODE);
    if (cd == NULL) {
        free(outbuf);
        return E_FAIL;
    }

    const char *pin = inbuf;
    char *pout = outbuf;
    size_t converted;

    converted = iconv(cd, &pin, &inbytesleft, &pout, &outbytesleft);
    // converted ?? //

    iconv_close(cd);

    ASSERT(outbytesleft >= 0);

    clear();
    m_RawSize = pout - outbuf;
    m_Raw = outbuf;
    ASSERT(m_Base64 == NULL);

    return S_OK;
}

STDMETHODIMP CBase64::GetBase64(BSTR *base64)
{
    if (base64 == NULL)
        return E_POINTER;

    if (m_Base64 == NULL) {
        if (m_Raw == NULL || m_RawSize == 0) {
            m_Base64 = SysAllocString(L"");
        } else {
            // 6 bytes -> 8 chars, + 10 for safe purpose.
            char prox_chars = m_RawSize / 6 * 8 + 10;
            char *buffer = (char *)malloc(prox_chars);
            int cc = base64_encode(m_Raw, m_RawSize, buffer, prox_chars);
            _bstr_t bstr(buffer);
            m_Base64 = bstr.copy();
            free(buffer);
        }
    }

    *base64 = SysAllocString(m_Base64);
	return S_OK;
}

STDMETHODIMP CBase64::GetStringB(BSTR *stringB)
{
	if (stringB == NULL)
        return E_POINTER;

    if (m_Raw == NULL || m_RawSize == 0) {
        *stringB = SysAllocString(L"");
    }

    *stringB = SysAllocStringLen((BSTR)m_Raw, m_RawSize);
	return S_OK;
}

STDMETHODIMP CBase64::GetString(BSTR encoding, BSTR *string)
{
	if (encoding == NULL)
        return E_INVALIDARG;
    if (string == NULL)
        return E_POINTER;

    iconv_t cd;
    cd = iconv_open(CS_UNICODE, _bstr_t(encoding));
    if (cd == NULL)
        return E_FAIL;

    const char *pin = m_Raw;
    size_t inbytesleft = m_RawSize;

    // scaled by * 1.5 for safe purpose.
    size_t outbytesleft = inbytesleft * 3 / 2;
    char *outbuf = (char *)malloc(outbytesleft);
    char *pout = outbuf;

    size_t converted;
    converted = iconv(cd, &pin, &inbytesleft, &pout, &outbytesleft);

    iconv_close(cd);

    *string = SysAllocStringLen((BSTR)outbuf, pout - outbuf);
    free(outbuf);

    if (*string == NULL)
        return E_OUTOFMEMORY;

	return S_OK;
}
