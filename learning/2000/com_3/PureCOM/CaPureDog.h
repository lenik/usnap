
#pragma once

#include "resource.h"

#include "PureCOMCP.h"

class ATL_NO_VTABLE CCaPureDog {

// public IDispatchImpl<ICaPureDog, &IID_ICaPureDog, &LIBID_CaPureCOMLib>
public:
	typedef CComTypeInfoHolder	_tihclass;
	STDMETHOD(GetTypeInfoCount)(UINT *pctinfo) {
		*pctinfo = 1;
		return S_OK;
	}
	STDMETHOD(GetTypeInfo)(UINT itinfo, LCID lcid, ITypeInfo **pptinfo) {
		return _tih.GetTypeInfo(itinfo, lcid, pptinfo);
	}
	STDMETHOD(GetIDsOfNames)(REFIID riid, LPOLESTR *rgsznames, UINT cNames,
		LCID lcid, DISPID *rgdispid) {
		return _tih.GetIDsOfNames(riid, rgsznames, cNames, lcid, rgdispid);
	}
	STDMETHOD(Invoke)(DISPID dispidMember, REFIID riid,
		LCID lcid, WORD wFlags, DISPPARAMS *pdispparams, VARIANT *pvarResult,
		EXCEPINFO *pexcepinfo, UINT *puArgErr) {
		return _tih.Invoke((IDispatch *)this, dispidMember, riid, lcid,
			wFlags, pdispparams, pvarResult, pexcepinfo, puArgErr);
	}
protected:
	static _tihclass	_tih;
	static HRESULT GetTI(LCID lcid, ITypeInfo **ppInfo) {
		return _tih.GetTI(lcid, ppInfo);
	}

// public ISupportErrorInfo
public:
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid) PURE;

// public CComObjectRoot
	CCaPureDog() {
		m_dwRef = 0L;
	}
	HRESULT FinalConstruct() {
		return S_OK;
	}
	HRESULT _AtlFinalConstruct() {
		return S_OK;
	}
	void FinalRelease() {}
	void _AtlFinalRelease() {}
	static void WINAPI ObjectMain(bool) {}
	static HRESULT WINAPI InternalQueryInterface(void *pThis,
		const _ATL_INTMAP_ENTRY *pEntries, REFIID iid, void **ppvObject) {
		ATLASSERT(pThis != NULL);
		ATLASSERT(pEntries->pFunc == _ATL_SIMPLEMAPENTRY);
		LPCTSTR pszClassName = (LPCTSTR)pEntries[-1].dw;
		HRESULT hRes = AtlInternalQueryInterface(pThis, pEntries, iid, ppvObject);
		//_Module.AddThunk((IUnknown **)ppvObject, pszClassName, iid);
		return _ATLDUMPIID(iid, pszClassName, hRes);
	}
	ULONG OuterAddRef() {
		return m_pOuterUnknown->AddRef();
	}
	ULONG OuterRelease() {
		return m_pOuterUnknown->Release();
	}
	HRESULT OuterQueryInterface(REFIID iid, void **ppvObject) {
		return m_pOuterUnknown->QueryInterface(iid, ppvObject);
	}
	void SetVoid(void *) {}
	void InternalFinalConstructAddRef() {}
	void InternalFinalConstructRelease() {
		ATLASSERT(m_dwRef == 0);
	}
	static HRESULT WINAPI _Break(void *pv, REFIID iid, void **ppvObject) {
		iid;
		_ATLDUMPIID(iid, _T("Break due to QI for interface."), S_OK);
		DebugBreak();
		return S_FALSE;
	}
	static HRESULT WINAPI _NoInterface(void *pv, REFIID iid, void **ppvObject, DWORD dw) {
		return E_NOINTERFACE;
	}
	static HRESULT WINAPI _Creator(void *pv, REFIID iid, void **ppvObject, DWORD dw) {
		_ATL_CREATORDATA *pcd = (_ATL_CREATORDATA *)dw;
		return pcd->pFunc(pv, iid, ppvObject);
	}
	static HRESULT WINAPI _Delegate(void *pv, REFIID iid, void **ppvObject, DWORD dw) {
		HRESULT hRes = E_NOINTERFACE;
		IUnknown *p = *(IUnknown *)((DWORD)pv + dw);
		if (p != NULL) {
			hRes = p->QueryInterface(iid, ppvObject);
		}
		return hRes;
	}
	static HRESULT WINAPI _Chain(void *pv, REFIID iid, void **ppvObject, DWORD dw) {
		_ATL_CHAINDATA *pcd = (_ATL_CHAINDATA *)dw;
		void *p = (void *)((DWORD)pv + pcd->dwOffset());
		return InternalQueryInterface(p, pcd->pFunc(), iid, ppvObject);
	}
	static HRESULT WINAPI _Cache(void *pv, REFIID iid, void **ppvObject, DWORD dw) {
		HRESULT hRes = E_NOINTERFACE;
		_ATL_CACHEDATA *pcd = (_ATL_CACHEDATA *)dw;
		IUnknown **pp = (IUnknown **)((DWORD)pv + pcd->dwOffsetVar);
		if (*pp == NULL) {
			hRes = pcd->pFunc(pv, IID_IUnknown, (void **)pp);
		}
		if (*pp != NULL) {
			hRes = (*pp)->QueryInterface(iid, ppvObject);
		}
		return TRUE;
	}
	union {
		long m_dwRef;
		IUnknown *m_pOuterUnknown;
	};

	typedef CComObjectThreadModel	_ThreadModel;
	typedef _ThreadModel::AutoCriticalSection _CritSec;
	typedef CComObjectLockT<_ThreadModel> ObjectLock;
	ULONG InternalAddRef() {
		ATLASSERT(m_dwRef != -1L);
		return _ThreadModel::Increment(&m_dwRef);
	}
	ULONG InternalRelease() {
		ATLASSERT(m_dwRef != -1L);
		return _ThreadModel::Decrement(&m_dwRef);
	}
	void Lock() { m_critsec.Lock(); }
	void Unlock() { m_critsec.Unlock(); }
private:
	_CritSec m_critsec;

// public CComCoClass<CCaPureDog, &CLSID_CaPureDog>
public:
	DECLARE_CLASSFACTORY();
	typedef CComCreator2<
			CComCreator< CComObject<CCaPureDog> >,
			CComCreator< CComAggObject<CCaPureDog> >
		> _CreatorClass;

	typedef CCaPureDog	_CoClass;
	static const CLSID& WINAPI GetObjectCLSID() { return CLSID_CaPureDog; }
	static LPCTSTR WINAPI GetObjectDescription() { return NULL; }
	static const struct _ATL_CATMAP_ENTRY *GetCategoryMap() { return NULL; }
	static HRESULT WINAPI Error(LPOLESTR lpszDesc, const IID& iid = GUID_NULL, HRESULT hRes = 0) {
		return AtlReportError(GetObjectCLSID(), lpszDesc, iid, hRes);
	}
	static HRESULT WINAPI Error(LPCOLESTR lpszDesc, DWORD dwhelpID,
		LPCOLESTR lpszHelpFile, const IID& iid = GUID_NULL, HRESULT hRes = 0) {
		return AtlReportError(GetObjectCLSID(), lpszDesc, dwHelpID, lpszHelpFile,
			iid, hRes);
	}
	static HRESULT WINAPI Error(UINT nID, const IID& iid = GUID_NULL, HRESULT hRes = 0,
		HINSTANCE hInst = _Module.GetResourceInstance()) {
		return AtlReportError(GetObjectCLSID(), nID, iid, hRes, hInst);
	}
	static HRESULT WINAPI Error(UINT nID, DWORD dwHelpID, LPCOLESTR lpszHelpFile,
		const IID& iid = GUID_NULL, HRESULT hRes = 0, HINSTANCE hInst = _Module.GetResourceInstance()) {
		return AtlReportError(GetObjectCLSID(), nID, dwHelpID, lpszHelpFile,
			iid, hRes, hInst);
	}
	template <class Q>
	static HRESULT CreateInstance(IUnknown *punkOuter, Q **pp) {
		return CCaPureDog::_CreatorClass::CreateInstance(punkOuter, __uuidof(Q), (void **)pp);
	}
	template <class Q>
	static HRESULT CreateInstance(Q **pp) {
		return CCaPureDog::_CreatorClass::CreateInstance(NULL, __uuidof(Q), (void **)pp);
	}

//
};

CCaPureDog::_tihclass CCaPureDog::_tih = {
	&IID_ICaPureDog, &LIBID_CaPureCOMLib, 1, 0, NULL, 0, NULL, 0
};

class CCaPureDog2 :
	public IDispatchImpl<ICaPureDog, &IID_ICaPureDog, &LIBID_CaPureCOMLib>,
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CCaPureDog,&CLSID_CaPureDog>,
	public CProxyICaPureDogEvents< CCaPureDog >,
	public IConnectionPointContainerImpl<CCaPureDog>
{
public:
	CCaPureDog() {}
BEGIN_COM_MAP(CCaPureDog)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ICaPureDog)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

DECLARE_REGISTRY_RESOURCEID(IDR_CaPureDog)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ICaPureDog
public:
	STDMETHOD(shout)();
public :

BEGIN_CONNECTION_POINT_MAP(CCaPureDog)
	CONNECTION_POINT_ENTRY(DIID_ICaPureDogEvents)
END_CONNECTION_POINT_MAP()

};
