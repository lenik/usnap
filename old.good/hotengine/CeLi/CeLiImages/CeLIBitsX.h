
#pragma once

class CeLIBitsX :
	public CComObjectRoot,
	public CComCoClass<CeLIBitsX, &CLSID_CeLIBitsX>,
	public IDispatchImpl<ICeLIBitsX, &IID_ICeLIBitsX> {
public:
	CeLIBitsX();
	virtual ~CeLIBitsX();

public:
	BEGIN_COM_MAP(CeLIBitsX)
		COM_INTERFACE_ENTRY2(IDispatch, ICeLIBitsX)
		COM_INTERFACE_ENTRY(ICeLIBitsX)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CeLiImages)
	DECALRE_NOT_AGGREGATABLE(CeLIBitsX);

protected:
};
