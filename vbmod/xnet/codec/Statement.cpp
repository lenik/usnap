// Statement.cpp : Implementation of CStatement
#include "stdafx.h"
#include "Codec.h"
#include "Statement.h"

#include "array.h"
#include "kernel.h"

/////////////////////////////////////////////////////////////////////////////
// CStatement


STDMETHODIMP CStatement::Add(VARIANT *v)
{
    HRESULT hr;

    if (v == 0)
        return E_POINTER;

    m_Vars.push_back(_variant_t());

    _variant_t& var = m_Vars.back();

    hr = VariantCopy(&var, v);
    if (FAILED(hr))
        return E_FAIL;

    return S_OK;
}

STDMETHODIMP CStatement::get_Item(int index, VARIANT *ret)
{
    HRESULT hr;

    if (index < 0 || index >= m_Vars.size())
        return E_INVALIDARG;

    if (ret == 0)
        return E_POINTER;

    _variant_t& var = m_Vars[index];

    VariantInit(ret);

    hr = VariantCopy(ret, &var);
    if (FAILED(hr))
        return E_FAIL;

    return S_OK;
}

STDMETHODIMP CStatement::put_Item(int index, VARIANT *newval)
{
    HRESULT hr;

    if (index < 0 || index >= m_Vars.size())
        return E_INVALIDARG;

    if (newval == 0)
        return E_POINTER;

    _variant_t& var = m_Vars[index];

    hr = VariantCopy(&var, newval);

    if (FAILED(hr))
        return E_FAIL;

    return S_OK;
}

STDMETHODIMP CStatement::get_TypedItem(int index, StatementItemTypeConstants type, VARIANT *ret)
{
    if (index < 0 || index >= m_Vars.size())
        return E_INVALIDARG;

    if (ret == 0)
        return E_POINTER;

    _variant_t& var = m_Vars[index];
    _variant_t out;

    switch (type) {
    case sitByte:

        break;
    case sitInt:
    case sitLong:
    case sitSingle:
    case sitDouble:
    case sitString:
    case sitBytes:
    default:
        return E_INVALIDARG;
    }

    return S_OK;
}

STDMETHODIMP CStatement::get_Count(int *pVal)
{
    if (pVal == 0)
        return E_POINTER;

    *pVal = m_Vars.size();
    return S_OK;
}

STDMETHODIMP CStatement::Encode(SAFEARRAY **pVal) {
    if (pVal == 0)
        return E_POINTER;

    ByteArray buf;
    int n = m_Vars.size();
    void *part;
    int size;

    for (int i = 0; i < n; i++) {
        _variant_t& v = m_Vars[i];
        part = &v.lVal;

        if (v.vt & VT_BYREF)
            return E_INVALIDARG;


        if (v.vt & VT_ARRAY) {
            size = 1;
            for (int i = 0; i < v.parray->cDims; i++)
                size *= v.parray->rgsabound[i].cElements;
            size *= v.parray->cbElements;
            part = v.parray->pvData;
        } else {
            switch (v.vt & VT_TYPEMASK) {
            case VT_EMPTY:
            case VT_NULL:
                size = 0; break;
            case VT_I1:
            case VT_UI1:
                size = 1; break;
            case VT_I2:
            case VT_UI2:
                size = 2; break;
            case VT_I4:
            case VT_UI4:
            case VT_R4:
                size = 4; break;
            case VT_I8:
            case VT_UI8:
            case VT_R8:
            case VT_CY:         // INT64
            case VT_DATE:       // double
                size = 8; break;
            case VT_BSTR:
                part = v.bstrVal; size = ((int *)v.bstrVal)[-1]; break;
            case VT_BOOL:
                size = 1; break;
            case VT_DECIMAL:    // 96-bit num, 32-bit ext
                size = 16; break;
            default:
                return E_FAIL;
            }
        }

        int encoded_size = 0;
        char *part_encoded = encode((char *)part, size, &encoded_size);
        _assert_(part_encoded);

        buf.write((unsigned char *)part_encoded, encoded_size);

        if (i != n - 1) {
            buf.write(' ');
        } else {
            buf.write(';');
            buf.write('\n');
        }
    }

    int cb = buf.getSize();
    SAFEARRAY *saBytes = SafeArrayCreateVector(VT_I1, 0, cb);
    if (saBytes == 0)
        return E_OUTOFMEMORY;

    memcpy(saBytes->pvData, buf, cb);

    if (*pVal)
        SafeArrayDestroy(*pVal);
    *pVal = saBytes;

    return S_OK;
}
