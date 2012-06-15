// Base64.cpp : Implementation of CBase64
#include "stdafx.h"
#include "Binaries.h"
#include "Base64.h"

#include <comutil.h>
#pragma comment(lib, "comsupp.lib")

#ifndef ASSERT
#   ifdef _DEBUG
#       include <assert.h>
#       define ASSERT(x) assert(x)
#   else
#       define ASSERT(x)
#   endif
#endif

/////////////////////////////////////////////////////////////////////////////
// CBase64

static char base64_enc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static int base64_dec[] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -2, -1, -1,     /* -2: '=' */
    -1,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1,
    -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
};

// returns actual characters written (include '\0'), or 0 if buffer too small.
int base64_encode(const char *data, int cb, char *buffer, int cc) {
    int packs = cb / 3;
    int csize = packs;
    unsigned char a, b, c;

    if (cb %= 3) csize++;
    csize <<= 2;
    if (cc < ++csize)   // include '\0'
        return 0;

    while (packs--) {
        a = *data++;
        b = *data++;
        c = *data++;
        *buffer++ = base64_enc[a >> 2];
        *buffer++ = base64_enc[((a & 0x3) << 4) | (b >> 4)];
        *buffer++ = base64_enc[((b & 0xf) << 2) | (c >> 6)];
        *buffer++ = base64_enc[c & 0x3f];
    }

    if (cb--) {
        a = *data++;
        *buffer++ = base64_enc[a >> 2];
        if (cb) {
            b = *data++;
            *buffer++ = base64_enc[((a & 0x3) << 4) | (b >> 4)];
            *buffer++ = base64_enc[((b & 0xf) << 2)];
            *buffer++ = '=';
        } else {
            *buffer++ = base64_enc[((a & 0x3) << 4)];
            *buffer++ = '=';
            *buffer++ = '=';
        }
    }

    *buffer = 0;
    return csize;
}

// returns actual bytes written, space and new-line are stripped.
int base64_decode(const char *base64, int cc, char *buffer, int cb) {
    int x, y, z, w;
    int bsize = 0;

    while (cc) {
        while (cc-- && (x = base64_dec[*base64++]) == -1);
        if (!cc) break;
        while (cc-- && (y = base64_dec[*base64++]) == -1);
        if (!cc) break;
        while (cc-- && (z = base64_dec[*base64++]) == -1);
        if (!cc) break;
        while (cc-- && (w = base64_dec[*base64++]) == -1);
        if (w == -1) break;

        if (w == -2) {
            if (--cb < 0) break;
            *buffer++ = (x << 2) | (y >> 4);
            bsize++;
            if (z != -2) {
                if (--cb < 0) break;
                *buffer++ = (y << 4) | (z >> 2);
                bsize++;
            }
            break;
        }

        if ((cb -= 3) < 0) break;
        *buffer++ = (x << 2) | (y >> 4);
        *buffer++ = (y << 4) | (z >> 2);
        *buffer++ = (z << 6) | (w);
        bsize += 3;
    }
    return bsize;
}

STDMETHODIMP CBase64::EncodeString(BSTR string, BSTR *ret)
{
    int cb, cc;
    char *base64;
    int l;

    if (! string || ! ret)
        return E_INVALIDARG;

    cb = wcslen(string) * 2;
    cc = (cb / 3 + (cb % 3 != 0)) << 2;
    base64 = (char *)malloc(cc + 1);

    l = base64_encode((const char *)string, cb, base64, cc + 1);
    ASSERT(l == cc + 1);

    _bstr_t bs(base64);
    *ret = SysAllocString((const wchar_t *)bs);

    free(base64);
	return S_OK;
}

STDMETHODIMP CBase64::DecodeString(BSTR bstr_base64, BSTR *ret)
{
    int size, bsize;
    char *buf;
    int l;

    if (! bstr_base64 || ! ret)
        return E_INVALIDARG;

    _bstr_t bs(bstr_base64);
    const char *base64 = (const char *)bs;
    size = bs.length();

    bsize = size / 4 * 3;   // appx. max size
    buf = (char *)malloc(bsize);
    l = base64_decode(base64, size, buf, bsize);
    ASSERT(l >= bsize - 2);

    *ret = SysAllocStringLen((const wchar_t *)buf, l / 2);

    free(buf);
	return S_OK;
}

STDMETHODIMP CBase64::EncodeData(VARIANT *data, BSTR *ret)
{

	return S_OK;
}

STDMETHODIMP CBase64::DecodeData(BSTR base64, VARIANT *data)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CBase64::EncodeFile(BSTR fileName, BSTR *ret)
{
    const char *path;
	FILE *f;
    int size, csize;
    char *data, *base64;
    int l;

    if (! fileName || ! ret)
        return E_INVALIDARG;

    path = _bstr_t(fileName);
    f = fopen(path, "rb");
    fseek(f, -1, SEEK_END);
    size = (int)ftell(f);

    data = (char *)malloc(size);
    fseek(f, 0, SEEK_SET);
    fread(data, size, 1, f);
    fclose(f);

    csize = (size / 3 + (size % 3 != 0)) << 2;
    base64 = (char *)malloc(csize + 1);
    l = base64_encode(data, size, base64, csize + 1);
    ASSERT(l == csize + 1);


    *ret = SysAllocString((const wchar_t *)_bstr_t(base64));

    free(data);
    free(base64);
	return S_OK;
}

STDMETHODIMP CBase64::DecodeFile(BSTR bstr_base64, BSTR outputFileName)
{
    const char *path;
    FILE *f;
    int size, bsize;
    const char *base64;
    char *buf;
    int l;

    if (! bstr_base64 || ! outputFileName)
        return E_INVALIDARG;

    size = wcslen(bstr_base64);
    base64 = (const char *)_bstr_t(bstr_base64);

    bsize = size / 4 * 3;   // appx. max size
    buf = (char *)malloc(bsize);
    l = base64_decode(base64, size, buf, bsize);
    ASSERT(l >= bsize - 2);

    path = _bstr_t(outputFileName);
    f = fopen(path, "wb");
    fwrite(buf, l, 1, f);
    fclose(f);

    free(buf);
	return S_OK;
}
