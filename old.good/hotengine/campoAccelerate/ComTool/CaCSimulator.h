
#pragma once

class CaCSimulator :
	public CComObjectRoot,
	public CComCoClass<CaCSimulator, &CLSID_CaCSimulator>,
	public IDispatchImpl<ICaCSimulator, &IID_ICaCSimulator> {
public:
	CaCSimulator();
	virtual ~CaCSimulator();

public:
	STDMETHOD(simulate)(IDispatch *simulate_object);

public:
	STDMETHOD(GetTypeInfoCount)(UINT *pctinfo);
	STDMETHOD(GetTypeInfo)(INT iTInfo, LCID lcid, ITypeInfo **ppTInfo);
	STDMETHOD(GetIDsOfNames)(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId);
	STDMETHOD(Invoke)(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags,
		DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr);

	BEGIN_COM_MAP(CaCSimulator)
		COM_INTERFACE_ENTRY2(IDispatch, ICaCSimulator)
		COM_INTERFACE_ENTRY(ICaCSimulator)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CaComTool)
	DECLARE_NOT_AGGREGATABLE(CaCSimulator)

protected:
	IDispatch	*m_pSimulatorObject;
};
