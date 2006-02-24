// List.cpp : Implementation of CList
#include "stdafx.h"
#include "Bastype.h"
#include "List.h"
#include "Iterator.h"

/////////////////////////////////////////////////////////////////////////////
// CList


CList::CList() {
}

CList::~CList() {
    varlist::iterator it = m_vars.begin();
    while (it != m_vars.end()) {
        VARIANT var = *it;
        VariantClear(&var);
        it++;
    }
}

STDMETHODIMP CList::get_size(long *pVal)
{
	if (pVal == NULL)
        return E_POINTER;
    *pVal = m_vars.size();
	return S_OK;
}

STDMETHODIMP CList::push(VARIANT *var)
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

STDMETHODIMP CList::pop(VARIANT *var)
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

STDMETHODIMP CList::unshift(VARIANT *var)
{
    VARIANT copy;
	if (var == NULL)
        return E_INVALIDARG;
    VariantInit(&copy);
    if (SUCCEEDED(VariantCopy(&copy, var))) {
        m_vars.push_front(copy);
        return S_OK;
    }
    return E_FAIL;
}

STDMETHODIMP CList::shift(VARIANT *var)
{
	if (var == NULL)
        return E_POINTER;
    if (m_vars.size() == 0)
        return E_FAIL;
    VARIANT v = m_vars.front();
    m_vars.pop_front();
    *var = v;
    return S_OK;
}

class ListIterator : public IteratorImpl {
    varlist::const_iterator m_It;
    varlist::const_iterator m_End;
public:
    ListIterator(varlist::const_iterator it, varlist::const_iterator end)
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

STDMETHODIMP CList::iterator(IIterator **result)
{
	if (result == NULL)
        return E_POINTER;
    CIteratorObject *pIt = new CIteratorObject;
    pIt->AddRef();
    pIt->setImpl(new ListIterator(m_vars.begin(), m_vars.end()));
    *result = pIt;
	return S_OK;
}
