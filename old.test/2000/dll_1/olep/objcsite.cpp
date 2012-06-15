
#include "stdafx.h"

#include "obj.h"

Object::ObjClientSite::ObjClientSite(Object *pObj) {
	m_pObj	= pObj;
}

STDMETHODIMP	Object::ObjClientSite::QueryInterface(REFIID riid, LPVOID *ppv) {
	return m_pObj->QueryInterface(riid, ppv);
}
STDMETHODIMP_(ULONG)	Object::ObjClientSite::AddRef() {
	return m_pObj->AddRef();
}
STDMETHODIMP_(ULONG)	Object::ObjClientSite::Release() {
	return m_pObj->Release();
}

STDMETHODIMP_(ULONG)	Object::ObjClientSite::SaveObject() {
	return m_pObj->Save(m_pObj->m_pStg, TRUE);
}

STDMETHODIMP	Object::ObjClientSite::GetMoniker(
						  DWORD dwAssign,
						  DWORD dwWhichMoniker,
						  LPMONIKER *ppmk) {
	*ppmk	= NULL;
	return ResultFromScode(E_FAIL);
}

STDMETHODIMP	Object::ObjClientSite::GetContainer(LPOLECONTAINER *ppContainer) {
	ppContainer	= NULL;
	return ResultFromScode(E_NOTIMPL);
}

STDMETHODIMP	Object::ObjClientSite::ShowObject() {
	m_pObj->m_pDoc->MakeRecVisible(&m_pObj->m_objRect);
	return NOERROR;
}

STDMETHODIMP	Object::ObjClientSite::OnShowWindow(BOOL fShow) {
	m_pObj->m_objWinOpen	= fShow;
	if (!fShow) {
		BringWindowToTop(m_pObj->m_pDoc->m_hWnd);
		SetFocus(m_pObj->m_pDoc->m_hWnd);
	} else {
		ShowObject();
	}
	m_pObj->Invalidate();
	return NOERROR;
}

STDMETHODIMP	Object::ObjClientSite::RequestNewObjectLayout() {
	return NOERROR;
}
