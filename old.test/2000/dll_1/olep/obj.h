
#include "stdafx.h"

class Object : public IUnknown {
public:
	Object();
	~Object();

	STDMETHOD(QueryInterface)(REFIID, LPVOID *);
	STDMETHOD_(ULONG, AddRef)();
	STDMETHOD_(ULONG, Release)();

	// IOleClientSite interface : OBJCSITE.CPP
	class ObjClientSite : public IOleClientSite {
	public:
		Object	*m_pObj;
		ObjClientSite(Object *pObj);

		STDMETHOD(QueryInterface)(REFIID, LPVOID *);
		STDMETHOD_(ULONG, AddRef)();
		STDMETHOD_(ULONG, Release)();

		STDMETHOD(SaveObject)();
		STDMETHOD(GetMoniker)(DWORD, DWORD, LPMONIKER *ppmk);
		STDMETHOD(GetContainer)(LPOLECONTAINER *);
		STDMETHOD(ShowObject)();
		STDMETHOD(OnShowWindow)(BOOL);
		STDMETHOD(RequestNewObjectLayout)();
	};
	ObjClientSite	m_clientSite;

	// IAdviseSink interface: OBJASINK.CPP
	class ObjAdviseSink : public IAdviseSink2 {
	public:
		Object	*m_pObj;
		ObjAdviseSink(Object *m_pObj);

		STDMETHOD(QueryInterface)(REFIID, LPVOID *);
		STDMETHOD_(ULONG, AddRef)();
		STDMETHOD_(ULONG, Release)();

		STDMETHOD_(void, OnDataChange)(FORMATETC *, STGMEDIUM *);
		STDMETHOD_(void, OnViewChange)(DWORD, LONG);
		STDMETHOD_(void, OnLinkSrcChange)(LPMONIKER);
		STDMETHOD_(void, OnRename)(LPMONIKER);
		STDMETHOD_(void, OnSave)();
		STDMETHOD_(void, OnClose)();
	};
	ObjAdviseSink	m_adviseSink;

	//
	// ...

	BOOL	CreateFromDataObject(POINT pt, LPDATAOBJECT pDataObject, HGLOBAL hMetaPict);


};

BOOL	Object::CreateFromDataObject(POINT pt, LPDATAOBJECT pDataObject, HGLOBAL hMetaPict) {
	HRESULT		hErr;
	LPOLECLIENTSITE	pClientSite;
	QueryInterface(IID_IOleClientSite, (LPVOID *)&pClientSite);

	if (!m_isStatic) {
		hErr	= OleCreateFromData(pDataObject, IID_IOleObject, OLERENDER_DRAW, NULL, pClientSite, pStg, (LPVOID *)&m_pOleObj);
	} else {
		hErr	= OleCreateStaticFromData(pDataObject, IID_IOleObject, OLERENDER_DRAW, NULL, pClientSite, m_pStg, (LPVOID *)&m_pOleObj);
	}

	if (FAILED(GetScode(hErr)) {
		return FALSE;
	}

	HGLOBAL		hMem;
	STGMEDIUM	stgMedium;

	if (hMem = OleStdGetData(pDataObject,
		RegisterClipboardFormat(CF_OBJECTDESCRIPTOR),
		NULL,
		DVASPECT_CONTENT,
		&stgMedium)) {
		LPOBJECTDESCRIPTOR	pObjDesc;
		pObjDesc	= (LPOBJECTDESCRIPTOR)GlobalLock(hMem);

		if (hMetaPict == NULL &&
			pObjDesc->dwDrawAspect == DVASPECT_ICON)
			m_dvAspect = DVASPECT_ICON;
		GlobalUnlock(hMem);
		ReleaseStgMedium(&stgMedium);
