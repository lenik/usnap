// TestComCtl.cpp : Implementation of the CTestComCtrl ActiveX Control class.

#include "stdafx.h"
#include "TestCom.h"
#include "TestComCtl.h"
#include "TestComPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CTestComCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTestComCtrl, COleControl)
	//{{AFX_MSG_MAP(CTestComCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

#define DISPID_ABOUTBOX2	1001
BEGIN_DISPATCH_MAP(CTestComCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CTestComCtrl)
	// NOTE - ClassWizard will add and remove dispatch map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CTestComCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CTestComCtrl, "AboutBox2", DISPID_ABOUTBOX2, AboutBox2, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CTestComCtrl, COleControl)
	//{{AFX_EVENT_MAP(CTestComCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CTestComCtrl, 1)
	PROPPAGEID(CTestComPropPage::guid)
END_PROPPAGEIDS(CTestComCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTestComCtrl, "TestCom.TestComCtrl.1",
	0, 0x4341, 0xFFFF, 0, 0x12, 0x48, 0x69, 0x54, 0x65, 0x63, 0x68)



/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CTestComCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DTestCom =
		{ 0, 0x4341, 0xFFFF, { 0, 0x0011, 0x48, 0x69, 0x54, 0x65, 0x63, 0x68 } };
const IID BASED_CODE IID_DTestComEvents =
		{ 0, 0x4341, 0xFFFF, { 0, 0x0017, 0x48, 0x69, 0x54, 0x65, 0x63, 0x68 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwTestComOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CTestComCtrl, IDS_TESTCOM, _dwTestComOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CTestComCtrl::CTestComCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CTestComCtrl

BOOL CTestComCtrl::CTestComCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_TESTCOM,
			IDB_TESTCOM,
			afxRegApartmentThreading,
			_dwTestComOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CTestComCtrl::CTestComCtrl - Constructor

CTestComCtrl::CTestComCtrl()
{
	InitializeIIDs(&IID_DTestCom, &IID_DTestComEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CTestComCtrl::~CTestComCtrl - Destructor

CTestComCtrl::~CTestComCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CTestComCtrl::OnDraw - Drawing function

void CTestComCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CTestComCtrl::DoPropExchange - Persistence support

void CTestComCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CTestComCtrl::OnResetState - Reset control to default state

void CTestComCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CTestComCtrl::AboutBox - Display an "About" box to the user

void CTestComCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_TESTCOM);
	dlgAbout.DoModal();
}

void CTestComCtrl::AboutBox2() {
	::MessageBox(NULL, "AboutBox2", NULL, MB_OK);
}

/////////////////////////////////////////////////////////////////////////////
// CTestComCtrl message handlers
