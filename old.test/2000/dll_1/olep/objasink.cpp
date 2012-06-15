
#include "stdafx.h"

#include "obj.h"

Object::ObjAdviseSink::ObjAdviseSink(Object *m_pObj) {
	m_pObj		= pObj;
	m_refCount	= 0;
}

STDMETHODIMP	Object::ObjAdviseSink::QueryInterface(REFIID riid, LPVOID *ppv) {
	return m_pObj->QueryInterface(riid, ppv);
}
STDMETHODIMP	Object::ObjAdviseSink::AddRef() {
	return m_pObj->AddRef();
}
STDMETHODIMP	Object::ObjAdviseSink::Release() {
	return m_pObj->Release();
}

STDMETHODIMP_(void)	Object::ObjAdviseSink::OnDataChange(
							    FORMATETC *pFormatetc,
							    STGMEDIUM *pStgmed) {
}

STDMETHODIMP_(void)	Object::ObjAdviseSink::OnViewChange(
							    DWORD	dwAspect,
							    LONG	lindex) {
	m_pObj->UpdateObjectSize();
	m_pObj->Invalidate();
	m_pObj->m_pDoc->SetModified(TRUE);
}

STDMETHODIMP_(void)	Object::ObjAdviseSink::OnRename(LPMONIKER pmk) {
}
STDMETHODIMP_(void)	Object::ObjAdviseSink::OnSave() {
}
STDMETHODIMP_(void)	Object::ObjAdviseSink::OnClose() {
}
