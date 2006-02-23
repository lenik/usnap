// List.cpp : Implementation of CList
#include "stdafx.h"
#include "Bastype.h"
#include "List.h"

/////////////////////////////////////////////////////////////////////////////
// CList


CList::CList() {
}

CList::~CList() {
    VARIANTS::iterator it = m_vars.begin();
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
