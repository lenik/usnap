
#pragma once

class CaCTools :
	public CComObjectRoot,
	public CComCoClass<CaCTools, &CLSID_CaCTools>,
	public IDispatchImpl<ICaCTools, &IID_ICaCTools> {
public:
	CaCTools();
	virtual ~CaCTools();

	STDMETHOD(get_progid)(BSTR *ret);
	STDMETHOD(put_progid)(BSTR progid);
	STDMETHOD(get_clsid)(BSTR *ret);
	STDMETHOD(put_clsid)(BSTR clsid);
	STDMETHOD(get_iid)(BSTR *ret);
	STDMETHOD(put_iid)(BSTR iid);

	STDMETHOD(createObject)(BOOL forceCreate, IDispatch **ret);
	STDMETHOD(createObject2)(BOOL forceCreate, IDispatch **ret);
	STDMETHOD(createObjectByProgid)(BSTR progid, BOOL forceCreate, IDispatch **ret);
	STDMETHOD(createObjectByProgid2)(BSTR progid, BSTR iid, BOOL forceCreate, IDispatch **ret);
	STDMETHOD(createObjectByClsid)(BSTR clsid, BOOL forceCreate, IDispatch **ret);
	STDMETHOD(createObjectByClsid2)(BSTR clsid, BSTR iid, BOOL forceCreate, IDispatch **ret);

	STDMETHOD(get_reference)(IUnknown *obj, LONG *ret);

	STDMETHOD(forceAddRef)(IUnknown *obj, LONG *ret);
	STDMETHOD(forceRelease)(IUnknown *obj, LONG *ret);
	STDMETHOD(forceQueryInterface)(IUnknown *obj, BSTR iid, IUnknown **ppv, HRESULT *ret);
	STDMETHOD(forceGetTypeInfoCount)(IDispatch *obj, LONG *ret);
	STDMETHOD(forceGetTypeInfo)(IDispatch *obj, LONG iTInfo, LONG lcid, IDispatch **ret);
	STDMETHOD(forceGetIDsOfNames)(IDispatch *obj, BSTR riid, BSTR *rgszNames, LONG cNames, LONG lcid, LONG *ret);
	STDMETHOD(forceGetIDOfName)(IDispatch *obj, BSTR riid, BSTR szName, LONG lcid, LONG *ret);

	BEGIN_COM_MAP(CaCTools)
		COM_INTERFACE_ENTRY2(IDispatch, ICaCTools)
		COM_INTERFACE_ENTRY(ICaCTools)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CaComTool)
	DECLARE_NOT_AGGREGATABLE(CaCTools)

protected:
	CLSID	m_clsid;
	IID	m_iid;
};

typedef CaCTools	*PCaCTools, *LPCaCTools;
