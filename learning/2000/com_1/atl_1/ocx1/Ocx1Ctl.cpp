// Ocx1Ctl.cpp : Implementation of the COcx1Ctrl ActiveX Control class.

#include "stdafx.h"
#include "ocx1.h"
#include "Ocx1Ctl.h"
#include "Ocx1Ppg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(COcx1Ctrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(COcx1Ctrl, COleControl)
	//{{AFX_MSG_MAP(COcx1Ctrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(COcx1Ctrl, COleControl)
	//{{AFX_DISPATCH_MAP(COcx1Ctrl)
	// NOTE - ClassWizard will add and remove dispatch map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(COcx1Ctrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(COcx1Ctrl, COleControl)
	//{{AFX_EVENT_MAP(COcx1Ctrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(COcx1Ctrl, 1)
	PROPPAGEID(COcx1PropPage::guid)
END_PROPPAGEIDS(COcx1Ctrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(COcx1Ctrl, "OCX1.Ocx1Ctrl.1",
	0xb06b99c6, 0xe6a2, 0x4c0a, 0x97, 0xf4, 0x6e, 0xa9, 0xd2, 0x75, 0x6b, 0xdf)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(COcx1Ctrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DOcx1 =
		{ 0x8e36f09e, 0xbc6a, 0x4a8e, { 0x8b, 0x7f, 0x78, 0x95, 0x34, 0x9f, 0x5d, 0xb3 } };
const IID BASED_CODE IID_DOcx1Events =
		{ 0x19548ccb, 0xd942, 0x42a6, { 0xb1, 0xa, 0xa9, 0x86, 0xe0, 0x1e, 0x58, 0x65 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwOcx1OleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(COcx1Ctrl, IDS_OCX1, _dwOcx1OleMisc)


/////////////////////////////////////////////////////////////////////////////
// COcx1Ctrl::COcx1CtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for COcx1Ctrl

BOOL COcx1Ctrl::COcx1CtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_OCX1,
			IDB_OCX1,
			afxRegApartmentThreading,
			_dwOcx1OleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// COcx1Ctrl::COcx1Ctrl - Constructor

COcx1Ctrl::COcx1Ctrl()
{
	InitializeIIDs(&IID_DOcx1, &IID_DOcx1Events);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// COcx1Ctrl::~COcx1Ctrl - Destructor

COcx1Ctrl::~COcx1Ctrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// COcx1Ctrl::OnDraw - Drawing function

void COcx1Ctrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// COcx1Ctrl::DoPropExchange - Persistence support

void COcx1Ctrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// COcx1Ctrl::OnResetState - Reset control to default state

void COcx1Ctrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// COcx1Ctrl::AboutBox - Display an "About" box to the user

void COcx1Ctrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_OCX1);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// COcx1Ctrl message handlers
