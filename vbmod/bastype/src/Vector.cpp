// Vector.cpp : Implementation of CVector
#include "stdafx.h"
#include "Bastype.h"
#include "Vector.h"
#include "Iterator.h"

/////////////////////////////////////////////////////////////////////////////
// CVector


CVector::CVector() {
}

CVector::~CVector() {
    varvec::iterator it = m_vars.begin();
    while (it != m_vars.end()) {
        VARIANT var = *it;
        VariantClear(&var);
        it++;
    }
}

STDMETHODIMP CVector::get_size(long *pVal)
{
	if (pVal == NULL)
        return E_POINTER;
    *pVal = m_vars.size();
	return S_OK;
}

STDMETHODIMP CVector::push(VARIANT *var)
{
	VARIANT copy;
    if (var == NULL)
        return E_INVALIDARG;
    VariantInit(&copy);
    if (SUCCEEDED(VariantCopy(&copy, var))) {
        m_vars.push_back(copy);
        return S_OK;
    }
    return E_FAIL;
}

STDMETHODIMP CVector::pop(VARIANT *var)
{
	if (var == NULL)
        return E_POINTER;
    if (m_vars.size() == 0)
        return E_FAIL;
    VARIANT v = m_vars.back();
    m_vars.pop_back();
    *var = v;
    return S_OK;
}

STDMETHODIMP CVector::unshift(VARIANT *var)
{
    VARIANT copy;
	if (var == NULL)
        return E_INVALIDARG;
    VariantInit(&copy);
    if (SUCCEEDED(VariantCopy(&copy, var))) {
        m_vars.insert(m_vars.begin(), copy);
        return S_OK;
    }
    return E_FAIL;
}

STDMETHODIMP CVector::shift(VARIANT *var)
{
	if (var == NULL)
        return E_POINTER;
    if (m_vars.size() == 0)
        return E_FAIL;
    VARIANT v = m_vars.front();
    m_vars.erase(m_vars.begin());
    *var = v;
    return S_OK;
}

class VectorIterator : public IteratorImpl {
    varvec::const_iterator m_It;
    varvec::const_iterator m_End;
public:
    VectorIterator(varvec::const_iterator it, varvec::const_iterator end)
        : m_It(it), m_End(end) {}

    virtual HRESULT hasNext(VARIANT_BOOL *result) {
        if (result == NULL)
            return E_POINTER;
        *result = m_It != m_End;
        return S_OK;
    }

    virtual HRESULT fetch(VARIANT *v) {
        if (v == NULL)
            return E_POINTER;
        VariantClear(v);
        if (m_It == m_End) {
            return S_FALSE;
        }
        VARIANT cur = *m_It;
        m_It++;
        VariantCopy(v, &cur);
        return S_OK;
    }

    virtual HRESULT remove() {
        return E_NOTIMPL;
    }
};

STDMETHODIMP CVector::iterator(IIterator **result)
{
	if (result == NULL)
        return E_POINTER;
    CIteratorObject *pIt = new CIteratorObject;
    pIt->AddRef();
    pIt->setImpl(new VectorIterator(m_vars.begin(), m_vars.end()));
    *result = pIt;
	return S_OK;
}

STDMETHODIMP CVector::get_item(long index, VARIANT *pVal)
{
    if (index < 0 || index >= m_vars.size())
        return E_INVALIDARG;
    if (pVal == NULL)
        return E_POINTER;

    VARIANT& at = m_vars.at(index);
    VariantInit(pVal);
    VariantCopy(pVal, &at);
	return S_OK;
}

STDMETHODIMP CVector::put_item(long index, VARIANT *newVal)
{
    if (index < 0 || index >= m_vars.size())
        return E_INVALIDARG;
    if (newVal == NULL)
        return E_INVALIDARG;

    VARIANT& at = m_vars.at(index);
    VariantClear(&at);
    VariantCopy(&at, newVal);
	return S_OK;
}

STDMETHODIMP CVector::insert(long index, VARIANT *var)
{
	if (index < 0 || index > m_vars.size())
        return E_INVALIDARG;
    if (var == NULL)
        return E_INVALIDARG;
    varvec::iterator pos = m_vars.begin() + index;
    VARIANT copy;
    VariantInit(&copy);
    VariantCopy(&copy, var);
    m_vars.insert(pos, copy);
	return S_OK;
}

STDMETHODIMP CVector::remove(long index)
{
    if (index < 0 || index >= m_vars.size())
        return E_INVALIDARG;
    varvec::iterator pos = m_vars.begin() + index;
    VARIANT *pAt = &*pos;
    VariantClear(pAt);
    m_vars.erase(pAt);
	return S_OK;
}
