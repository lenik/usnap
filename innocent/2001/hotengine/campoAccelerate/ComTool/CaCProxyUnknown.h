
#pragma once

class CaCProxyUnknown :
	public CComObjectRoot,
	public CComCoClass<CaCProxyUnknown, &CLSID_CaCProxyUnknown>,
	public IDispatchImpl<ICaCProxyUnknown, &IID_ICaCProxyUnknown> {
public:
	CaCProxyUnknown();
	virtual ~CaCProxyUnknown();

public:
	BEGIN_COM_MAP(CaCProxyUnknown)
		COM_INTERFACE_ENTRY2(IDispatch, ICaCProxyUnknown)
		COM_INTERFACE_ENTRY(ICaCProxyUnknown)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CaComTool)
	DECLARE_NOT_AGGREGATABLE(CaCProxyUnknown)

protected:
};
