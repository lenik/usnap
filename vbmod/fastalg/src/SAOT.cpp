// SAOT.cpp : Implementation of CSAOT
#include "stdafx.h"
#include "Fastalg.h"
#include "SAOT.h"

/////////////////////////////////////////////////////////////////////////////
// CSAOT

STDMETHODIMP CSAOT::get_SlotAllocated(long *pVal)
{
	if (pVal == NULL)
        return E_POINTER;
    *pVal = m_saot.slot_alloc();
	return S_OK;
}

STDMETHODIMP CSAOT::get_Size(long *pVal)
{
	if (pVal == NULL)
        return E_POINTER;
    *pVal = m_saot.size();
	return S_OK;
}

STDMETHODIMP CSAOT::SlotAdd(long *result)
{
    if (result == NULL)
        return E_POINTER;
	int slot = m_saot.slot_add();
    *result = slot;
	return S_OK;
}

STDMETHODIMP CSAOT::SlotRemove(long slot)
{
	m_saot.slot_remove(slot);
	return S_OK;
}

STDMETHODIMP CSAOT::SlotClear()
{
	m_saot.slot_clear();
	return S_OK;
}

STDMETHODIMP CSAOT::Insert(long Index, long *result)
{
	if (result == NULL)
        return E_POINTER;
	int slot = m_saot.idx_insert(Index);
    *result = slot;
	return S_OK;
}

STDMETHODIMP CSAOT::Remove(long Index, long *result)
{
	if (result == NULL)
        return E_POINTER;
	int slot = m_saot.idx_remove(Index);
    *result = slot;
	return S_OK;
}

STDMETHODIMP CSAOT::FindSlot(long Slot, long *result)
{
	if (result == NULL)
        return E_POINTER;
    index_type index = m_saot.find_slot(Slot);
    *result = index;
	return S_OK;
}

STDMETHODIMP CSAOT::FindIndex(long Index, long *result)
{
	if (result == NULL)
        return E_POINTER;
	int slot = m_saot.find_index(Index);
    *result = slot;
	return S_OK;
}

STDMETHODIMP CSAOT::SortSlots(VARIANT *SortedSlots)
{
	if (SortedSlots == NULL)
        return E_POINTER;
    int size = m_saot.size();
    int *slots = new int[size];
    m_saot.idx_sort(slots);

    HRESULT hr;
    SAFEARRAY *sa = SafeArrayCreateVector(VT_I4, 0, size);
    for (long i = 0; i < size; i++) {
        long v = slots[i];
        hr = SafeArrayPutElement(sa, &i, &v);
        _assert_(SUCCEEDED(hr));
    }

    VariantInit(SortedSlots);
    SortedSlots->vt = VT_ARRAY | VT_I4;
    SortedSlots->parray = sa;

    delete[] slots;
	return S_OK;
}

STDMETHODIMP CSAOT::Append(long count, long *result)
{
	if (count < 0)
        return E_INVALIDARG;
    if (result == NULL)
        return E_POINTER;
    long made = m_saot.idx_append(count);
    *result = made;
    return made == count ? S_OK : S_FALSE;
}
