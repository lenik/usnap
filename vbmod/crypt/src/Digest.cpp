// Digest.cpp : Implementation of CDigest
#include "stdafx.h"
#include "Crypt.h"
#include "Digest.h"

#include "md5.h"

/////////////////////////////////////////////////////////////////////////////
// CDigest


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
    if (a_msb) *a_msb = d[3];
    if (b) *b = d[2];
    if (c) *c = d[1];
    if (d_lsb) *d_lsb = d[0];

	return S_OK;
}
