// HexEditCtl.h : Declaration of the CHexEditCtl

#ifndef __HEXEDITCTL_H_
#define __HEXEDITCTL_H_

#include "resource.h"       // main symbols
#include <atlctl.h>


/////////////////////////////////////////////////////////////////////////////
// CHexEditCtl
class ATL_NO_VTABLE CHexEditCtl :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IHexEditCtl, &IID_IHexEditCtl, &LIBID_HEXEDITLib>,
	public CComControl<CHexEditCtl>,
	public IPersistStreamInitImpl<CHexEditCtl>,
	public IOleControlImpl<CHexEditCtl>,
	public IOleObjectImpl<CHexEditCtl>,
	public IOleInPlaceActiveObjectImpl<CHexEditCtl>,
	public IViewObjectExImpl<CHexEditCtl>,
	public IOleInPlaceObjectWindowlessImpl<CHexEditCtl>,
	public IConnectionPointContainerImpl<CHexEditCtl>,
	public IPersistStorageImpl<CHexEditCtl>,
	public ISpecifyPropertyPagesImpl<CHexEditCtl>,
	public IQuickActivateImpl<CHexEditCtl>,
	public IDataObjectImpl<CHexEditCtl>,
	public IProvideClassInfo2Impl<&CLSID_HexEditCtl, &DIID__IHexEditCtlEvents, &LIBID_HEXEDITLib>,
	public IPropertyNotifySinkCP<CHexEditCtl>,
	public CComCoClass<CHexEditCtl, &CLSID_HexEditCtl>
{
public:
	CHexEditCtl()
	{
	}


DECLARE_REGISTRY_RESOURCEID(IDR_HEXEDITCTL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CHexEditCtl)
	COM_INTERFACE_ENTRY(IHexEditCtl)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
END_COM_MAP()

BEGIN_PROP_MAP(CHexEditCtl)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CHexEditCtl)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CHexEditCtl)
    MESSAGE_HANDLER(WM_CHAR, OnChar)
    MESSAGE_HANDLER(WM_LBUTTONDOWN,OnLeftMouse)
    MESSAGE_HANDLER(WM_KEYDOWN,OnKeyDown)
    MESSAGE_HANDLER(WM_KILLFOCUS,OnKillFocus)
    MESSAGE_HANDLER(WM_SETFOCUS,OnSetFocus)
    MESSAGE_HANDLER(WM_SIZING,OnSizing)

	CHAIN_MSG_MAP(CComControl<CHexEditCtl>)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);



// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IHexEditCtl
    HRESULT OnDraw(ATL_DRAWINFO& di);

    LRESULT OnChar(UINT uMsg ,WPARAM wParam,LPARAM lParam, BOOL& bHandled);

    LRESULT OnLeftMouse(UINT uMsg ,WPARAM wParam,LPARAM lParam, BOOL& bHandled);

    LRESULT OnKeyDown(UINT uMsg ,WPARAM wParam,LPARAM lParam, BOOL& bHandled);

    LRESULT OnSizing(UINT uMsg ,WPARAM wParam,LPARAM lParam, BOOL& bHandled);

    LRESULT OnKillFocus(UINT uMsg ,WPARAM wParam,LPARAM lParam, BOOL& bHandled);

    LRESULT OnSetFocus(UINT uMsg ,WPARAM wParam,LPARAM lParam, BOOL& bHandled);
public:
	// 视区的宽度和高度
	int				m_nWidth;
	int				m_nHeight;

	// 水平和垂直的页边距
	int				m_leftMargin;
	int				m_topMargin;

	// 是否显示亚洲字符
	BOOL			m_bRawOutput;

protected:
	LPBYTE			m_lpData;
	int				m_nDataLength;

	BOOL			m_bEditOnChars;

	int				m_nRow;
	int				m_nCol;
	int				m_bHalf;

	int				m_nViewOffset;

	BOOL			m_bDirty;

	HBITMAP			m_hbmpCaret;

	TEXTMETRIC		m_tm;

	// in current view
	int effective_height();
	// in current row of current view.
	int effective_width(int row);

	BOOL Refresh();
	BOOL UpdateCaret();
	virtual void OnFontChanged();

};

#endif //__HEXEDITCTL_H_
