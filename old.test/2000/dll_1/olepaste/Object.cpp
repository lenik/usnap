
#include "stdafx.h"

#include "Object.h"


TheObject::TheObject(CDocument *pDocument) {
	m_pDocument	= pDocument;
	m_pAdviseSink	= new TheAdviseSink(this);
	m_pClientSite	= new TheClientSite(this);
}

TheObject::~TheObject() {
	if (m_pAdviseSink != NULL)	delete m_pAdviseSink;
	if (m_pClientSite != NULL)	delete m_pClientSite;
}

STDMETHODIMP		TheObject::QueryInterface(REFIID riid, LPVOID *ppv) {
	return NOERROR;
}
STDMETHODIMP_(ULONG)	TheObject::AddRef() {
	m_refCount++;
	return m_refCount;
}
STDMETHODIMP_(ULONG)	TheObject::Release() {
	m_refCount--;
	if (m_refCount == 0) {
		delete this;
		return 0;
	}
	return m_refCount;
}

TheObject::CreateFromDataObject(POINT pt, LPDATAOBJECT pDataObject, HGLOBAL hMetaPict) {
	HRESULT		hErr;
	LPOLECLIENTSITE	pClientSite;
	QueryInterface(IID_IOleClientSite, (LPVOID *)&pClientSite);

	if (!m_isStatic) {
		hErr	= OleCreateFromData(
			pDataObject,
			IID_IOleObject,
			OLERENDER_DRAW,
			NULL,
			pClientSite,
			m_pStorage,
			(LPVOID *)&m_pOleObject);
	} else {
		hErr	= OleCreateStaticFromData(
			pDataObject,
			IID_IOleObject,
			OLERENDER_DRAW,
			NULL,
			pClientSite,
			m_pStorage,
			(LPVOID *)&m_pOleObject);
	}

	if (FAILED(hErr) return FALSE;

	HGLOBAL		hMem;
	STGMEDIUM	stgMedium;
	if (hMem = OleStdGetData(
		pDataObject,
		RegisterClipboardFormat(CF_OBJECTDESCRIPTOR),
		NULL,
		DVASPECT_CONTENT,
		&stgMedium)) {

		LPOBJECTDESCRIPTOR	pObjectDesc;
		pObjectDesc		= (LPOBJECTDESCRIPTOR)GlobalLock(hMem);
		if (hMetaPict == NULL && pObjectDesc->dwDrawAspect == DVASPECT_ICON) {
			m_dvAspect	= DVASPECT_ICON;
		}
		GlobalUnlock(hMem);
		ReleaseStgMedium(&stgMedium);

		if (hMetaPict == NULL) {
			if (m_dvAspect == DVASPECT_ICON) {
				hMetaPict	= OleStdGetData(
					pDataObject,
					CF_METAFILEPICT,
					NULL,
					DVASPECT_ICON,
					&stgMedium);
				if (hMetaPict == NULL) m_dvAspect = DVASPECT_CONTENT;
			}
		} else {
			stgMedium.tymed		= TYMED_MFPICT;
			stgMedium.hGlobal	= hMetaPict;
			stgMedium.pUnkForRelease= NULL;
			m_dvAspect		= DVASPECT_ICON;
		}
	}

	if (m_dvAspect == DVASPECT_ICON) {
		DWORD	dw = DVASPECT_CONTENT;
		BOOL	fMustUpdate;
		OleStdSwitchDisplayAspect(
			m_pOleObject,
			&dw,
			DVASPECT_ICON,
			hMetaPict,
			TRUE,
			FALSE,
			NULL,
			&fMuseUpdate);
		if (hMetaPict != NULL) ReleaseStgMedium(&stgMedium);
	}

	m_pView		= (LPVIEWOBJECT)OleStdQueryInterface(
		(LPUNKNOWN)m_pOleObject,
		IID_IViewObject);
	m_pPs		= (LPPERSISTSTORAGE)OleStdQueryInterface(
		(LPUNKNOWN)m_pOleObject,
		IID_IPersistStorage);

	SetHostNames();

	HDC	hDC;
	SIZE	sizel;

	m_pOleObject->GetExtent(m_dvAspect, &sizel);
	hDC	= GetDC(m_pDocument->m_hWnd);
	Move(pt.x, pt.y,
		MAP_LOGHIM_TO_PIX(sizel.cx, GetDeviceCaps(hDC, LOGPIXELSX)),
		MAP_LOGHIM_TO_PIX(sizel.cy, GetDeviceCaps(hDC, LOGPIXELSY))
		);
	ReleaseDC(m_pDocument->m_hWnd, hDC);

	return TRUE;
}

/////////
TheObject::TheAdviseSink::TheAdviseSink(TheObject *pObject) {
	m_pObject	= pObject;
	m_refCount	= 0;
}

STDMETHODIMP		TheObject::TheAdviseSink::QueryInterface(REFIID riid, LPVOID *ppv) {
	return m_pObject->QueryInterface(riid, ppv);
}
STDMETHODIMP_(ULONG)	TheObject::TheAdviseSink::AddRef() {
	m_refCount++;
	return m_refCount;
}
STDMETHODIMP_(ULONG)	TheObject::TheAdviseSink::Release() {
	m_refCount--;
	if (m_refCount == 0) {
		delete this;
		return 0;
	}
	return m_refCount;
}
STDMETHODIMP_(void)	TheObject::TheAdviseSink::OnDataChange(LPFORMATETC pFormatetc, LPSTGMEDIUM pStgmedium) {
}
STDMETHODIMP_(void)	TheObject::TheAdviseSink::OnViewChange(DWORD dwAspect, LONG lindex) {
	m_pObject->UpdateObjectSize();
	m_pObject->Invalidate();
	m_pObject->m_pDocument->SetModifiedFlag(TRUE);
}
STDMETHODIMP_(void)	TheObject::TheAdviseSink::OnRename(LPMONIKER pmk) {
}
STDMETHODIMP_(void)	TheObject::TheAdviseSink::OnSave() {
}
STDMETHODIMP_(void)	TheObject::TheAdviseSink::OnClose() {
}


/////////
TheObject::TheClientSite::TheClientSite(TheObject *pObject) {
	m_pObject	= pObject;
	m_refCount	= 0;
}

STDMETHODIMP		TheObject::TheClientSite::QueryInterface(REFIID riid, LPVOID *ppv) {
	return m_pObject->QueryInterface(riid, ppv);
}
STDMETHODIMP_(ULONG)	TheObject::TheClientSite::AddRef() {
	m_refCount++;
	return m_refCount;
}
STDMETHODIMP_(ULONG)	TheObject::TheClientSite::Release() {
	m_refCount--;
	if (m_refCount == 0) {
		delete this;
		return 0;
	}
	return m_refCount;
}

STDMETHODIMP		TheObject::TheClientSite::SaveObject() {
	return m_pObject->m_pDocument->Save(m_pObject->m_pStorage, TRUE);
}
STDMETHODIMP		TheObject::TheClientSite::GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, LPMONIKER *ppmk) {
	*ppmk	= NULL;
	return E_FAIL;
}
STDMETHODIMP		TheObject::TheClientSite::GetContainer(LPOLECONTAINER *ppContainer) {
	ppContainer	= NULL;
	return E_NOTIMPL;
}
STDMETHODIMP		TheObject::TheClientSite::ShowObject() {
	m_pObject->m_pDocument->MakeRecVisible(&m_pObject->m_objectRect);
	return NOERROR;
}
STDMETHODIMP		TheObject::TheClientSite::OnShowWindow(BOOL fShow) {
	m_pObject->m_objWinOpen	= fShow;
	if (!fShow) {
		BringWindowToTop(m_pObject->m_pDocument->m_hWnd);
		SetFocus(m_pObject->m_pDocument->m_hWnd);
	} else {
		ShowObject();
	}
	m_pObject->Invalidate();
	return NOERROR;
}
STDMETHODIMP		TheObject::TheClientSite::RequestNewObjectLayout() {
	return NOERROR;
}
