
#pragma once

class CeLIBits2 :
	public CComObjectRoot,
	public CComCoClass<CeLIBits2, &CLSID_CeLIBits2>,
	public IDispatchImpl<ICeLIBits2, &IID_ICeLIBits2> {
public:
	CeLIBits2();
	virtual ~CeLIBits2();

public:
	STDMETHOD(Blit)(
		ICeLIDevice *cldDest,
		LONG destx, LONG desty, LONG width, LONG height,
		LONG rop);

public:
	BEGIN_COM_MAP(CeLIBits2)
		COM_INTERFACE_ENTRY2(IDispatch, ICeLIBits2)
		COM_INTERFACE_ENTRY(ICeLIBits2)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CeLiImages)
	DECALRE_NOT_AGGREGATABLE(CeLIBits2);

protected:
};
