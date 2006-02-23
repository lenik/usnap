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
    if (m_mask & saotemRemove) {
        int index = m_saot.find_slot(slot);
        if (index != -1)
            return this->Remove(index, &slot);
    }
    m_saot.slot_remove(slot);
	return S_OK;
}

STDMETHODIMP CSAOT::Clear()
{
    if (m_mask & saotemClear)
        this->Fire_Clear();
    int size = m_saot.size();
    int *slots = NULL;
    if (size > 0 && (m_mask & saotemRemove)) {
        slots = new int[size];
        m_saot.idx_sort(slots);
    }

    m_saot.slot_clear();

    if (m_mask & saotemRemove) {
        for (int index = 0; index < size; index++) {
            int slot = slots[index];
            this->Fire_Remove(slot, index);
        }
    }
    if (slots != NULL)
        delete[] slots;
	return S_OK;
}

STDMETHODIMP CSAOT::Insert(long Index, long *result)
{
	if (result == NULL)
        return E_POINTER;
	int slot = m_saot.idx_insert(Index);
    if (slot == -1)                     // Index > Size()
        return E_INVALIDARG;
    *result = slot;
    if (m_mask & saotemAdd)
        this->Fire_Add(slot, Index);
	return S_OK;
}

STDMETHODIMP CSAOT::Remove(long Index, long *result)
{
	if (result == NULL)
        return E_POINTER;
	int slot = m_saot.idx_remove(Index);
    if (slot == -1)
        return E_INVALIDARG;            // Index out of bounds
    if (m_mask & saotemRemove)
        this->Fire_Remove(slot, Index);
    *result = slot;
    return S_OK;
}

STDMETHODIMP CSAOT::FindSlot(long Slot, long *result)
{
    if (Slot < 0 || Slot >= m_saot.slot_alloc())
        return E_INVALIDARG;
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
    long index_from = m_saot.size();
    int *slots = NULL;
    if (m_mask & saotemAdd) {
        slots = new int[count];
        if (! slots)
            return E_OUTOFMEMORY;
    }
    long made = m_saot.idx_append(count, slots);
    *result = made;
    if (m_mask & saotemAdd) {
        for (long i = 0; i < made; i++) {
            Fire_Add((long)slots[i], index_from + i);
        }
        delete[] slots;
    }
    return made == count ? S_OK : S_FALSE;
}

STDMETHODIMP CSAOT::get_EventMask(SAOTEventMaskConstants *pVal)
{
	if (pVal == NULL)
        return E_POINTER;
    *pVal = m_mask;
	return S_OK;
}

STDMETHODIMP CSAOT::put_EventMask(SAOTEventMaskConstants newVal)
{
	m_mask = newVal;
	return S_OK;
}
