// Iterator.cpp : Implementation of CIterator
#include "stdafx.h"
#include "Bastype.h"
#include "Iterator.h"

/////////////////////////////////////////////////////////////////////////////
// CIterator


STDMETHODIMP CIterator::hasNext(VARIANT_BOOL *result)
{
	if (m_Impl == NULL)
        return E_UNEXPECTED;
    return m_Impl->hasNext(result);
}

STDMETHODIMP CIterator::fetch(VARIANT *result)
{
	if (m_Impl == NULL)
        return E_UNEXPECTED;
    return m_Impl->fetch(result);
}

STDMETHODIMP CIterator::remove()
{
	if (m_Impl == NULL)
        return E_UNEXPECTED;
    return m_Impl->remove();
}
