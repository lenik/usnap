// HelloCtl.cpp : Implementation of the CHelloCtrl ActiveX Control class.

#include "stdafx.h"
#include "mfcx1.h"
#include "HelloCtl.h"
#include "HelloPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CHelloCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CHelloCtrl, COleControl)
	//{{AFX_MSG_MAP(CHelloCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CHelloCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CHelloCtrl)
	DISP_FUNCTION(CHelloCtrl, "hello", method_hello, VT_BOOL, VTS_PBSTR)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CHelloCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CHelloCtrl, COleControl)
	//{{AFX_EVENT_MAP(CHelloCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CHelloCtrl, 1)
	PROPPAGEID(CHelloPropPage::guid)
END_PROPPAGEIDS(CHelloCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CHelloCtrl, "MFCX1.HelloCtrl.1",
	0xf8b5f1bb, 0x189d, 0x40e3, 0xaa, 0x36, 0x1d, 0x42, 0xe2, 0x2e, 0xb4, 0x6f)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CHelloCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DHello =
		{ 0x5ed225e1, 0x3e21, 0x44ce, { 0xb0, 0xa5, 0x17, 0xbb, 0x32, 0x41, 0x99, 0xb8 } };
const IID BASED_CODE IID_DHelloEvents =
		{ 0x7e1eddab, 0xfaae, 0x4b04, { 0xac, 0xfa, 0xcc, 0xd3, 0xc3, 0x70, 0x4b, 0x51 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwHelloOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CHelloCtrl, IDS_HELLO, _dwHelloOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CHelloCtrl::CHelloCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CHelloCtrl

BOOL CHelloCtrl::CHelloCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_HELLO,
			IDB_HELLO,
			afxRegApartmentThreading,
			_dwHelloOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CHelloCtrl::CHelloCtrl - Constructor

CHelloCtrl::CHelloCtrl()
{
	InitializeIIDs(&IID_DHello, &IID_DHelloEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CHelloCtrl::~CHelloCtrl - Destructor

CHelloCtrl::~CHelloCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CHelloCtrl::OnDraw - Drawing function

void CHelloCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CHelloCtrl::DoPropExchange - Persistence support

void CHelloCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CHelloCtrl::OnResetState - Reset control to default state

void CHelloCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CHelloCtrl::AboutBox - Display an "About" box to the user

void CHelloCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_HELLO);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CHelloCtrl message handlers

BOOL CHelloCtrl::method_hello(BSTR FAR* caller)
{
	// TODO: Add your dispatch handler code here
	::MessageBoxW(NULL, *caller, L"Hello!", MB_OK);
	return TRUE;
}
