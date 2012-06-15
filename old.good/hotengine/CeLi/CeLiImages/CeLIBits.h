
#pragma once

class CeLIBits :
	public CComObjectRoot,
	public CComCoClass<CeLIBits, &CLSID_CeLIBits>,
	public IDispatchImpl<ICeLIBits, &IID_ICeLIBits> {
public:
	CeLIBits();
	virtual ~CeLIBits();

public:
	STDMETHOD(Mosaic)();

public:
	BEGIN_COM_MAP(CeLIBits)
		COM_INTERFACE_ENTRY2(IDispatch, ICeLIBits)
		COM_INTERFACE_ENTRY(ICeLIBits)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CeLiImages)
	DECALRE_NOT_AGGREGATABLE(CeLIBits);

protected:
};
