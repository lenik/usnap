// Digest.cpp : Implementation of CDigest
#include "stdafx.h"
#include "Crypt.h"
#include "Digest.h"

#include "md5.h"

/////////////////////////////////////////////////////////////////////////////
// CDigest


static DWORD le_to_be(DWORD x) {
    WORD h = x >> 16;
    WORD l = x & 0xFFFF;

    h = (h >> 8) | (h << 8);
    l = (l >> 8) | (l << 8);
    return h | (l << 16);
}

STDMETHODIMP CDigest::MD5_String(BSTR message, long *a_msb, long *b, long *c, long *d_lsb)
{
    const char *msg = "";
    _bstr_t msg_b;

    if (message) {
        msg_b = message;
        msg = (const char *)msg_b;
    }

    int len = strlen(msg);

    MD5 md5impl;
    md5impl.update((const unsigned char *)msg, len);
    md5impl.finalize();

    long *d = (long *)md5impl.raw_digest();
    if (a_msb) *a_msb = le_to_be(d[0]);
    if (b) *b = le_to_be(d[1]);
    if (c) *c = le_to_be(d[2]);
    if (d_lsb) *d_lsb = le_to_be(d[3]);

	return S_OK;
}
