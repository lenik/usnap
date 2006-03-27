// Base64.cpp : Implementation of CBase64
#include "stdafx.h"
#include "Binary.h"
#include "Base64.h"
#include "kernel.h"
#include <iconv.h>
#include <errno.h>
#include <comutil.h>

#ifndef CS_UNICODE
#define CS_UNICODE "UCS-2LE"
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
        memcpy(copy, stringB, len);
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

    // scaled by * 2 for safe purpose.
    size_t outbytesleft = inbytesleft * 2;
    char *outbuf = (char *)malloc(outbytesleft);

    if (outbuf == NULL)
        return E_OUTOFMEMORY;

    _bstr_t _encoding(encoding);
    iconv_t cd = iconv_open(_encoding, CS_UNICODE);
    if (cd == (iconv_t)-1) {
        int err = errno;
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
            size_t prox_chars = m_RawSize / 6 * 8 + 10;
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

STDMETHODIMP CBase64::SetBase64(BSTR base64)
{
    if (base64 == NULL) {
        clear();
        return S_OK;
    }

    DWORD len = ((DWORD *)base64)[-1];
    DWORD cc = len >> 1;                // ASSERT(len % 2 = 0);

    // 8 chars -> 6 bytes, + 10 for safe purpose.
    size_t prox_rawsize = cc / 8 * 6 + 10;

    char *raw = (char *)malloc(prox_rawsize);
    if (raw == NULL)
        return E_OUTOFMEMORY;

    size_t rawsize = 0;
    int cb = base64_decode(_bstr_t(base64), cc, raw, prox_rawsize);

    m_Raw = raw;
    m_RawSize = cb;
    m_Base64 = SysAllocString(base64);

	return S_OK;
}

STDMETHODIMP CBase64::GetStringB(BSTR *stringB)
{
	if (stringB == NULL)
        return E_POINTER;

    if (m_Raw == NULL || m_RawSize == 0) {
        *stringB = SysAllocString(L"");
    }

    *stringB = SysAllocStringByteLen(m_Raw, m_RawSize);
	return S_OK;
}

STDMETHODIMP CBase64::GetString(BSTR encoding, BSTR *string)
{
	if (encoding == NULL)
        return E_INVALIDARG;
    if (string == NULL)
        return E_POINTER;

    const char *pin = m_Raw;
    size_t inbytesleft = m_RawSize;

    // scaled by * 2.5 for safe purpose.
    size_t outbytesleft = inbytesleft * 5 / 2;
    char *outbuf = (char *)malloc(outbytesleft);
    if (outbuf == NULL)
        return E_OUTOFMEMORY;

    char *pout = outbuf;

    iconv_t cd;
    cd = iconv_open(CS_UNICODE, _bstr_t(encoding));
    if (cd == (iconv_t)-1) {
        int err = errno;
        return E_FAIL;
    }

    size_t converted;
    converted = iconv(cd, &pin, &inbytesleft, &pout, &outbytesleft);

    iconv_close(cd);

    *string = SysAllocStringByteLen(outbuf, pout - outbuf);
    free(outbuf);

    if (*string == NULL)
        return E_OUTOFMEMORY;

	return S_OK;
}

STDMETHODIMP CBase64::GetHex(BSTR separator, BSTR *hexes)
{
    if (hexes == NULL)
        return E_POINTER;

    bstr_t _sep = separator;
    char *sep = separator ? _sep : "";
    wchar_t *wsep = separator ? _sep : L"";
    int sep_len = strlen(sep);

	size_t cc = m_RawSize * (2 + sep_len);
    wchar_t *buf = (wchar_t *)malloc(cc * 2);
    if (buf == NULL)
        return E_OUTOFMEMORY;

    wchar_t *pbuf = buf;
    for (int i = 0; i < m_RawSize; i++) {
        pbuf += swprintf(pbuf, L"%s%02x", i == 0 ? L"" : wsep, (BYTE)m_Raw[i]);
    }

    *hexes = SysAllocStringLen(buf, cc);
    free(buf);

    if (*hexes == NULL)
        return E_OUTOFMEMORY;
	return S_OK;
}

int hex2dec[] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     0,  1,  2,  3,  4,  5,  6,  7,  8,  9, -1, -1, -1, -1, -1, -1,
    -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
};

STDMETHODIMP CBase64::SetHex(BSTR hexes, long *bytes)
{
    if (hexes == NULL) {
        clear();
    } else {
        DWORD len = ((DWORD *)hexes)[-1];
        int cc = len / 2;
        if (cc <= 0) {
            clear();
        } else {
            BYTE *buf = (BYTE *)malloc(cc / 2 + 1);         // alloc max bytes
            size_t used = 0;
            int val = -1;
            /*
                0 - initial
                1 - have got digit#1
                2 - word break
            */
            int state = 0;
            while (cc--) {
                wchar_t c = *hexes++;
                int d = hex2dec[c & 0xFF];

                switch (state) {
                case 0:
                    if (d == -1)
                        continue;
                    val = d;
                    state = 1;
                    break;
                case 1:
                    if (d == -1) {
                        buf[used++] = (BYTE)val;
                        state = 2;
                    } else {
                        val = (val << 4) | d;
                        buf[used++] = val;
                        state = 2;
                    }
                    break;
                case 2:
                    if (d == -1)
                        continue;
                    val = d;
                    state = 1;
                    break;
                }
            }
            if (state == 1) {
                buf[used++] = (BYTE)val;
                state = 2;
            }
            clear();
            m_Raw = (char *)buf;
            m_RawSize = used;
        }
    }

    if (bytes)
        *bytes = m_RawSize;

	return S_OK;
}
