// HashCode.cpp : Implementation of CHashCode
#include "stdafx.h"
#include "Fastalg.h"
#include "HashCode.h"

/////////////////////////////////////////////////////////////////////////////
// CHashCode


STDMETHODIMP CHashCode::hcVariant(VARIANT *var, long *result)
{
    if (result == NULL)
        return E_POINTER;

	if (var == NULL)
        return E_POINTER;

    DWORD hash = (DWORD)var->vt;
    wchar_t *pws;
    size_t nws;

    switch (var->vt) {
    case VT_BSTR:
        _assert_(var->bstrVal);
        pws = var->bstrVal;
        nws = (((size_t *)var->bstrVal)[-1] + 1) / 2;
        while (nws) {
            hash = (hash << 8) | (hash >> 24);
            hash = hash ^ (DWORD) (0x12345678 * nws * *pws);
            pws++;
            nws--;
        }
        break;
    case VT_R8:
        hash ^= ((DWORD *)&var->dblVal)[1];
    case VT_UNKNOWN:                    // var->punkVal
    case VT_DISPATCH:                   // var->pdispVal
    case VT_ARRAY:                      // var->parray.
    default:
        hash ^= (DWORD)var->lVal;
    }

    *result = hash;
	return S_OK;
}
