
#include "stdafx.h"

#undef INTERFACE
#define INTERFACE	TheObject

class TheObject : public IUnknown {
public:
	TheObject(CDocument *pDocument);
	~TheObject();

	STDMETHOD(QueryInterface)(REFIID, LPVOID *);
	STDMETHOD_(ULONG, AddRef)();
	STDMETHOD_(ULONG, Release)();

public:
	class TheAdviseSink : public IAdviseSink2 {
	public:
		TheAdviseSink(TheObject *);

		STDMETHOD(QueryInterface)(REFIID, LPVOID *);
		STDMETHOD_(ULONG, AddRef)();
		STDMETHOD_(ULONG, Release)();

		STDMETHOD_(void, OnDataChange)(LPFORMATETC, LPSTGMEDIUM);
		STDMETHOD_(void, OnViewChange)(DWORD, LONG);
		STDMETHOD_(void, OnLinkSrcChange)(LPMONIKER);
		STDMETHOD_(void, OnRename)(LPMONIKER);
		STDMETHOD_(void, OnSave)();
		STDMETHOD_(void, OnClose)();
	public:
		TheObject	*m_pObject;
		int		m_refCount;
	};

	TheAdviseSink	*m_pAdviseSink;

	class TheClientSite : public IOleClientSite {
	public:
		TheClientSite(TheObject *);

		STDMETHOD(QueryInterface)(REFIID, LPVOID *);
		STDMETHOD_(ULONG, AddRef)();
		STDMETHOD_(ULONG, Release)();

		STDMETHOD(SaveObject)();
		STDMETHOD(GetMoniker)(DWORD, DWORD, LPMONIKER *);
		STDMETHOD(GetContainer)(LPOLECONTAINER *);
		STDMETHOD(ShowObject)();
		STDMETHOD(OnShowWindow)(BOOL);
		STDMETHOD(RequestNewObjectLayout)();
	public:
		TheObject	*m_pObject;
		int		m_refCount;
	};

public:
	void		CreateFromDataObject(POINT, LPDATAOBJECT, HGLOBAL);


public:
	TheClientSite	*m_pClientSite;
	CDocument	*m_pDocument;

public:
	int		m_refCount;
};
