
#pragma once

class CeVersionSimple :
	public CComObjectRoot,
	public CComCoClass<CeVersionSimple,&CLSID_CeVersionSimple>,
	public ICeVersion {
public:
	CeVersionSimple();
	virtual ~CeVersionSimple();

	STDMETHOD(AboutBox)();
	STDMETHOD(GetCurrentVersion)(LONG *pVer);

	BEGIN_COM_MAP(CeVersionSimple)
		COM_INTERFACE_ENTRY(ICeVersion)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_REGSCRIPT)
	DECLARE_NOT_AGGREGATABLE(CeVersionSimple)
};
