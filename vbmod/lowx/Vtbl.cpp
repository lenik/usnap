// Vtbl.cpp : Implementation of CVtbl
#include "stdafx.h"
#include "LowX.h"
#include "Vtbl.h"

/////////////////////////////////////////////////////////////////////////////
// CVtbl

STDMETHODIMP
CVtbl::get_Item(int Index, POINTER_TYPE *ret) {
	if (m_pObj == NULL) return E_FAIL;

	void *pv = GetVtblItem((void *)m_pObj, Index);
	*ret = (POINTER_TYPE)pv;

	return S_OK;
}

STDMETHODIMP
CVtbl::put_Item(int Index, POINTER_TYPE newVal) {
	if (m_pObj == NULL) return E_FAIL;

	SetVtblItem((void *)m_pObj, Index, (void *)newVal);
	return S_OK;
}

STDMETHODIMP CVtbl::Bind(POINTER_TYPE pObject, int BindActionIndex, int UnbindActionIndex)
{
	Unbind();
	m_pObj = pObject;
	m_nUnbindAction = UnbindActionIndex;

	if (BindActionIndex >= 0) {
		InvokeThiscallByIndex((void *)m_pObj, BindActionIndex);
	}

	return S_OK;
}

STDMETHODIMP CVtbl::Unbind()
{
	if (m_pObj) {
		if (m_nUnbindAction >= 0) {
			InvokeThiscallByIndex((void *)m_pObj, m_nUnbindAction);
		}
		m_pObj = NULL;
	}
	return S_OK;
}

void *CVtbl::GetVtblItem(void *pThis, int Index) {
	int nTable = Index >> 16;
	int nItem = Index & 0xFFFF;

	if (nItem < 0) {
		return ((void **)pThis)[nTable];
	}

	return ((void **)(((void **)pThis)[nTable]))[nItem];
}

void *CVtbl::SetVtblItem(void *pThis, int Index, void *newVal) {
	int nTable = Index >> 16;
	int nItem = Index & 0xFFFF;

	if (nItem < 0) {
		void *& pv = ((void **)pThis)[nTable];
		pv = newVal;
		return pv;
	}

	void *& pv = ((void **)(((void **)pThis)[nTable]))[nItem];
	pv = newVal;
	return pv;
}

int CVtbl::InvokeThiscall(void *pThis, void *pProc) {
	int ret1;

	__asm {
		mov ecx, pThis
		call pProc
		mov ret1, eax
	}

	return ret1;
}

int CVtbl::InvokeThiscallByIndex(void *pThis, int index) {
	void *proc;
	proc = GetVtblItem(pThis, index);

	int ret;
	ret = InvokeThiscall((void *)m_pObj, (void *)proc);

	return ret;
}
