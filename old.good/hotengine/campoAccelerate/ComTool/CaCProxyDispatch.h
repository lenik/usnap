
#pragma once

class CaCProxyDispatch :
	public CComObjectRoot,
	public CComCoClass<CaCProxyDispatch, &CLSID_CaCProxyDispatch>,
	public IDispatchImpl<ICaCProxyDispatch, &IID_ICaCProxyDispatch> {
public:
	CaCProxyDispatch();
	virtual ~CaCProxyDispatch();

public:
	BEGIN_COM_MAP(CaCProxyDispatch)
		COM_INTERFACE_ENTRY2(IDispatch, ICaCProxyDispatch)
		COM_INTERFACE_ENTRY(ICaCProxyDispatch)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CaComTool)
	DECLARE_NOT_AGGREGATABLE(CaCProxyDispatch)

protected:
};
