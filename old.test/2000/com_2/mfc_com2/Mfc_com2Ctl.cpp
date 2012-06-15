// Mfc_com2Ctl.cpp : Implementation of the CMfc_com2Ctrl ActiveX Control class.

#include "stdafx.h"
#include "mfc_com2.h"
#include "Mfc_com2Ctl.h"
#include "Mfc_com2Ppg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CMfc_com2Ctrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CMfc_com2Ctrl, COleControl)
	//{{AFX_MSG_MAP(CMfc_com2Ctrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CMfc_com2Ctrl, COleControl)
	//{{AFX_DISPATCH_MAP(CMfc_com2Ctrl)
	// NOTE - ClassWizard will add and remove dispatch map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CMfc_com2Ctrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CMfc_com2Ctrl, COleControl)
	//{{AFX_EVENT_MAP(CMfc_com2Ctrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CMfc_com2Ctrl, 1)
	PROPPAGEID(CMfc_com2PropPage::guid)
END_PROPPAGEIDS(CMfc_com2Ctrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMfc_com2Ctrl, "MFCCOM2.Mfccom2Ctrl.1",
	0x296c0696, 0xb6a, 0x451e, 0x8d, 0xac, 0x8c, 0xde, 0xe2, 0xf6, 0xc8, 0x89)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CMfc_com2Ctrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DMfc_com2 =
		{ 0x947fd3ba, 0xf33b, 0x4562, { 0x9e, 0x2c, 0x36, 0xc7, 0x29, 0x42, 0x78, 0x57 } };
const IID BASED_CODE IID_DMfc_com2Events =
		{ 0x6b606f1b, 0x2bed, 0x4870, { 0xbc, 0x3a, 0x68, 0x35, 0x64, 0x98, 0x89, 0xc8 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwMfc_com2OleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMfc_com2Ctrl, IDS_MFC_COM2, _dwMfc_com2OleMisc)


/////////////////////////////////////////////////////////////////////////////
// CMfc_com2Ctrl::CMfc_com2CtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CMfc_com2Ctrl

BOOL CMfc_com2Ctrl::CMfc_com2CtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_MFC_COM2,
			IDB_MFC_COM2,
			afxRegApartmentThreading,
			_dwMfc_com2OleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CMfc_com2Ctrl::CMfc_com2Ctrl - Constructor

CMfc_com2Ctrl::CMfc_com2Ctrl()
{
	InitializeIIDs(&IID_DMfc_com2, &IID_DMfc_com2Events);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CMfc_com2Ctrl::~CMfc_com2Ctrl - Destructor

CMfc_com2Ctrl::~CMfc_com2Ctrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CMfc_com2Ctrl::OnDraw - Drawing function

void CMfc_com2Ctrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CMfc_com2Ctrl::DoPropExchange - Persistence support

void CMfc_com2Ctrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CMfc_com2Ctrl::OnResetState - Reset control to default state

void CMfc_com2Ctrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CMfc_com2Ctrl::AboutBox - Display an "About" box to the user

void CMfc_com2Ctrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_MFC_COM2);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CMfc_com2Ctrl message handlers
