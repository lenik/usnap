// Cat002.h : Declaration of the CCat002

#ifndef __CAT002_H_
#define __CAT002_H_

#include "resource.h"       // main symbols
#include <atlctl.h>


/////////////////////////////////////////////////////////////////////////////
// CCat002
class ATL_NO_VTABLE CCat002 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<ICat002, &IID_ICat002, &LIBID_CATLib>,
	public CComControl<CCat002>,
	public IPersistStreamInitImpl<CCat002>,
	public IOleControlImpl<CCat002>,
	public IOleObjectImpl<CCat002>,
	public IOleInPlaceActiveObjectImpl<CCat002>,
	public IViewObjectExImpl<CCat002>,
	public IOleInPlaceObjectWindowlessImpl<CCat002>,
	public IPersistStorageImpl<CCat002>,
	public ISpecifyPropertyPagesImpl<CCat002>,
	public IQuickActivateImpl<CCat002>,
	public IDataObjectImpl<CCat002>,
	public IProvideClassInfo2Impl<&CLSID_Cat002, NULL, &LIBID_CATLib>,
	public CComCoClass<CCat002, &CLSID_Cat002>
{
public:
	CCat002()
	{
        m_szName = "Hello";
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CAT002)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCat002)
	COM_INTERFACE_ENTRY(ICat002)
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

BEGIN_PROP_MAP(CCat002)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// Example entries
	//PROP_ENTRY("My name", dispid, clsid)
	PROP_PAGE(CLSID_StockColorPage)
    PROP_PAGE(CLSID_CatPropPage)
END_PROP_MAP()

public:
	BOOL ProcessWindowMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT& lResult, DWORD dwMsgMapID = 0)
	{
        BOOL bHandled = TRUE;
        hWnd;
        uMsg;
        wParam;
        lParam;
        lResult;
        bHandled;
        switch(dwMsgMapID)
        {
        case 0:
            if(uMsg == WM_CHAR)
            {
                switch (wParam) {
                case 's':
                    //
                    ::MessageBox(0, m_szName, 0, 0);
                    break;
                }
            }
            {
                if(CComControl<CCat002>::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult))
                    return TRUE;
            }
            if(DefaultReflectionHandler(hWnd, uMsg, wParam, lParam, lResult))
                return TRUE;
            break;
        default:
            ATLTRACE2(atlTraceWindowing, 0, _T("Invalid message map ID (%i)n"), dwMsgMapID);
            ATLASSERT(FALSE);
            break;
        }
        return FALSE;
	}
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);



// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

//
public:
    HWND m_cmdShow;
    char *m_szName;

// ICat002
public:
	STDMETHOD(GetRawObject)(long *pRawAddr);

    HRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		RECT& rc = *(RECT*)di.prcBounds;
		Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);

		SetTextAlign(di.hdcDraw, TA_CENTER|TA_BASELINE);
		LPCTSTR pszText = _T("ATL 3.0 : Cat002");
		TextOut(di.hdcDraw,
			(rc.left + rc.right) / 2,
			(rc.top + rc.bottom) / 2,
			pszText,
			lstrlen(pszText));

		return S_OK;
	}
};

#endif //__CAT002_H_
