
#pragma once

class CeE2DAux :
	public CComObjectRoot,
	public CComCoClass<CeE2DAux, &CLSID_CeE2DAux>,
	public IDispatchImpl<ICeE2DAux, &IID_ICeE2DAux> {
public:
	CeE2DAux();
	virtual ~CeE2DAux();

public:

public:
	BEGIN_COM_MAP(CeE2DAux)
		COM_INTERFACE_ENTRY2(IDispatch, ICeE2DAux)
		COM_INTERFACE_ENTRY(ICeE2DAux)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CeE2D)
	DECLARE_NOT_AGGREGATABLE(CeE2DAux)
};

typedef ATL::CComObject<CeE2DAux>	CCeE2DAux;
