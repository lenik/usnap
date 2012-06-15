// DRIA.cpp : Implementation of CDRIA
#include "stdafx.h"
#include "Fastalg.h"
#include "DRIA.h"

/////////////////////////////////////////////////////////////////////////////
// CDRIA


STDMETHODIMP CDRIA::Clear()
{
	m_dria.clear();
	return S_OK;
}

STDMETHODIMP CDRIA::Ceil(long x, int *retval)
{
	if (retval == NULL)
        return E_POINTER;
    int i = m_dria.ceil(x);
    *retval = i;
	return S_OK;
}

STDMETHODIMP CDRIA::Floor(long x, int *retval)
{
	if (retval == NULL)
        return E_POINTER;
    int i = m_dria.floor(x);
    *retval = i;
	return S_OK;
}

STDMETHODIMP CDRIA::AddRange(long lower, long upper, BOOL *retval)
{
    return m_dria.add(int_range(lower, upper)) ? S_OK : S_FALSE;
}

STDMETHODIMP CDRIA::RemoveRange(long lower, long upper, BOOL *retval)
{
	return m_dria.remove(int_range(lower, upper)) ? S_OK : S_FALSE;
}

STDMETHODIMP CDRIA::Add(long x, BOOL *retval)
{
	return m_dria.add(x) ? S_OK : S_FALSE;
}

STDMETHODIMP CDRIA::Remove(long x, BOOL *retval)
{
	return m_dria.remove(x) ? S_OK : S_FALSE;
}

STDMETHODIMP CDRIA::get_Count(int *pVal)
{
	return m_dria.size();
}

STDMETHODIMP CDRIA::get_RangeLower(int index, long *pVal)
{
    if (index < 0 || index >= m_dria.size())
        return E_INVALIDARG;
	if (pVal == NULL)
        return E_POINTER;
    *pVal = m_dria[index].from;
	return S_OK;
}

STDMETHODIMP CDRIA::get_RangeUpper(int index, long *pVal)
{
    if (index < 0 || index >= m_dria.size())
        return E_INVALIDARG;
	if (pVal == NULL)
        return E_POINTER;
    *pVal = m_dria[index].to;
	return S_OK;
}
