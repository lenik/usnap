
#pragma once

class CeE2DPage :
	public CComObjectRoot,
	public CComCoClass<CeE2DPage, &CLSID_CeE2DPage>,
	public IDispatchImpl<ICeE2DPage, &IID_ICeE2DPage> {
public:
	CeE2DPage();
	virtual ~CeE2DPage();

public:
	STDMETHOD(init)(LPDIRECTDRAWSURFACE lpDDS, DWORD nPages);
	STDMETHOD(get_lpdds)(LPDIRECTDRAWSURFACE *ret);

public:
	STDMETHOD(NextPage)(ICeE2DPage **ret);
	STDMETHOD(SwapPage)();
	STDMETHOD(DrawBegin)(HDC *ret);
	STDMETHOD(DrawEnd)();
	STDMETHOD(ProcessBegin)(LONG *ret);
	STDMETHOD(ProcessEnd)();
	STDMETHOD(BitBlt)(ICeE2DPage *pdest, LONG destx, LONG desty, LONG width, LONG height, LONG srcx, LONG srcy, LONG rop);

public:
	BEGIN_COM_MAP(CeE2DPage)
		COM_INTERFACE_ENTRY2(IDispatch, ICeE2DPage)
		COM_INTERFACE_ENTRY(ICeE2DPage)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CeE2D)
	DECLARE_NOT_AGGREGATABLE(CeE2DPage)

protected:
	BOOL			m_bInited;
	DWORD			m_nPages;
	LPDIRECTDRAWSURFACE	m_lpDDS;
	LPDIRECTDRAWSURFACE	m_lpCurrentDDS;
	BOOL			m_bDrawing;
	HDC			m_hDC;
	BOOL			m_bLocked;
	LPVOID			m_lpMemoryBase;
};

typedef ATL::CComObject<CeE2DPage>	CCeE2DPage;
