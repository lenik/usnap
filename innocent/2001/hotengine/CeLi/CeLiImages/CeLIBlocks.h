
#pragma once

class CeLIBlocks :
	public CComObjectRoot,
	public CComCoClass<CeLIBlocks, &CLSID_CeLIBlocks>,
	public IDispatchImpl<ICeLIBlocks, &IID_ICeLIBlocks> {
public:
	CeLIBlocks();
	virtual ~CeLIBlocks();

public:
	BEGIN_COM_MAP(CeLIBlocks)
		COM_INTERFACE_ENTRY2(IDispatch, ICeLIBlocks)
		COM_INTERFACE_ENTRY(ICeLIBlocks)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CeLiImages)
	DECALRE_NOT_AGGREGATABLE(CeLIBlocks);

protected:
};
