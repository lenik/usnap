// HelloControl.h : Declaration of the CHelloControl

#ifndef __HELLOCONTROL_H_
#define __HELLOCONTROL_H_

#include "resource.h"       // main symbols
#include <atlctl.h>


/////////////////////////////////////////////////////////////////////////////
// CHelloControl
class ATL_NO_VTABLE CHelloControl :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IHelloControl, &IID_IHelloControl, &LIBID_OCX1Lib>,
	public CComControl<CHelloControl>,
	public IPersistStreamInitImpl<CHelloControl>,
	public IOleControlImpl<CHelloControl>,
	public IOleObjectImpl<CHelloControl>,
	public IOleInPlaceActiveObjectImpl<CHelloControl>,
	public IViewObjectExImpl<CHelloControl>,
	public IOleInPlaceObjectWindowlessImpl<CHelloControl>,
	public IPersistStorageImpl<CHelloControl>,
	public ISpecifyPropertyPagesImpl<CHelloControl>,
	public IQuickActivateImpl<CHelloControl>,
	public IDataObjectImpl<CHelloControl>,
	public IProvideClassInfo2Impl<&CLSID_HelloControl, NULL, &LIBID_OCX1Lib>,
	public CComCoClass<CHelloControl, &CLSID_HelloControl>
{
public:
	CHelloControl()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HELLOCONTROL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CHelloControl)
	COM_INTERFACE_ENTRY(IHelloControl)
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
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
END_COM_MAP()

BEGIN_PROP_MAP(CHelloControl)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_MSG_MAP(CHelloControl)
	CHAIN_MSG_MAP(CComControl<CHelloControl>)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);



// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IHelloControl
public:

	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		RECT& rc = *(RECT*)di.prcBounds;
		Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);

		SetTextAlign(di.hdcDraw, TA_CENTER|TA_BASELINE);
		LPCTSTR pszText = _T("ATL 3.0 : HelloControl");
		TextOut(di.hdcDraw,
			(rc.left + rc.right) / 2,
			(rc.top + rc.bottom) / 2,
			pszText,
			lstrlen(pszText));

		return S_OK;
	}
};

#endif //__HELLOCONTROL_H_
