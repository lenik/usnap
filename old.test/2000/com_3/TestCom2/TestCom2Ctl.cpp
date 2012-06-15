// TestCom2Ctl.cpp : Implementation of the CTestCom2Ctrl ActiveX Control class.

#include "stdafx.h"
#include "TestCom2.h"
#include "TestCom2Ctl.h"
#include "TestCom2Ppg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CTestCom2Ctrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTestCom2Ctrl, COleControl)
	//{{AFX_MSG_MAP(CTestCom2Ctrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CTestCom2Ctrl, COleControl)
	//{{AFX_DISPATCH_MAP(CTestCom2Ctrl)
	// NOTE - ClassWizard will add and remove dispatch map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CTestCom2Ctrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CTestCom2Ctrl, COleControl)
	//{{AFX_EVENT_MAP(CTestCom2Ctrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CTestCom2Ctrl, 1)
	PROPPAGEID(CTestCom2PropPage::guid)
END_PROPPAGEIDS(CTestCom2Ctrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTestCom2Ctrl, "TESTCOM2.TestCom2Ctrl.1",
	0x8c1c3576, 0xef63, 0x475a, 0x91, 0x32, 0x7, 0xa0, 0x3e, 0x5b, 0x45, 0x5f)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CTestCom2Ctrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DTestCom2 =
		{ 0x8cfc8a45, 0x3a7d, 0x4f94, { 0x9f, 0xc0, 0x79, 0x57, 0x6, 0xc9, 0xe0, 0xd0 } };
const IID BASED_CODE IID_DTestCom2Events =
		{ 0xd8656d34, 0x8d20, 0x4264, { 0xba, 0xbe, 0xa9, 0x84, 0x50, 0x68, 0xd9, 0x19 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwTestCom2OleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CTestCom2Ctrl, IDS_TESTCOM2, _dwTestCom2OleMisc)


/////////////////////////////////////////////////////////////////////////////
// CTestCom2Ctrl::CTestCom2CtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CTestCom2Ctrl

BOOL CTestCom2Ctrl::CTestCom2CtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_TESTCOM2,
			IDB_TESTCOM2,
			afxRegApartmentThreading,
			_dwTestCom2OleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CTestCom2Ctrl::CTestCom2Ctrl - Constructor

CTestCom2Ctrl::CTestCom2Ctrl()
{
	InitializeIIDs(&IID_DTestCom2, &IID_DTestCom2Events);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CTestCom2Ctrl::~CTestCom2Ctrl - Destructor

CTestCom2Ctrl::~CTestCom2Ctrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CTestCom2Ctrl::OnDraw - Drawing function

void CTestCom2Ctrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CTestCom2Ctrl::DoPropExchange - Persistence support

void CTestCom2Ctrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CTestCom2Ctrl::OnResetState - Reset control to default state

void CTestCom2Ctrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CTestCom2Ctrl::AboutBox - Display an "About" box to the user

void CTestCom2Ctrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_TESTCOM2);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CTestCom2Ctrl message handlers
