
#pragma once

class CeE3DRender :
	public CComObjectRoot,
	public CComCoClass<CeE3DRender, &CLSID_CeE3DRender>,
	public IDispatchImpl<ICeE3DRender, &IID_ICeE3DRender> {
public:
	CeE3DRender();
	virtual ~CeE3DRender();

public:
	STDMETHOD(ShadeFlat)();
	STDMETHOD(ShadeSmooth)();
	STDMETHOD(SetDepthFunc)(DEPTHFUNCENUM func);

public:

	BEGIN_COM_MAP(CeE3DRender)
		COM_INTERFACE_ENTRY2(IDispatch, ICeE3DRender)
		COM_INTERFACE_ENTRY(ICeE3DRender)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CeE3DRender)
	DECLARE_NOT_AGGREGATABLE(CeE3DRender);

protected:
};

typedef CeE3DRender	*PCEE3DRENDER, *LPCEE3DRENDER;
