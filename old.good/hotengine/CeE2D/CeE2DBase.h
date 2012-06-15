
#pragma once

class CeE2DBase :
	public CComObjectRoot,
	public CComCoClass<CeE2DBase, &CLSID_CeE2DBase>,
	public IDispatchImpl<ICeE2DBase, &IID_ICeE2DBase> {
public:
	CeE2DBase();
	virtual ~CeE2DBase();

public:
	STDMETHOD(init)(HWND hWnd);

public:
	STDMETHOD(Resolution)(LONG width, LONG height, LONG depth, BOOL *ret);
	STDMETHOD(CreatePage)(LONG width, LONG height, LONG nAdditionPage, BOOL bOffScreen, ICeE2DPage **ret);

public:
	BEGIN_COM_MAP(CeE2DBase)
		COM_INTERFACE_ENTRY2(IDispatch, ICeE2DBase)
		COM_INTERFACE_ENTRY(ICeE2DBase)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CeE2D)
	DECLARE_NOT_AGGREGATABLE(CeE2DBase)

protected:
	HWND	m_hWnd;
	BOOL	m_bInited;
	BOOL	m_bInWindowMode;
	LONG	m_nResWidth;
	LONG	m_nResHeight;
	LONG	m_nResDepth;

	LPDIRECTDRAW	m_lpDD;
};

typedef ATL::CComObject<CeE2DBase>	CCeE2DBase;
