// AdvancedTimerCtl.cpp : Implementation of the CAdvancedTimerCtrl ActiveX Control class.

#include "stdafx.h"
#include "mfcx1.h"
#include "AdvancedTimerCtl.h"
#include "AdvancedTimerPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CAdvancedTimerCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CAdvancedTimerCtrl, COleControl)
	//{{AFX_MSG_MAP(CAdvancedTimerCtrl)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CAdvancedTimerCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CAdvancedTimerCtrl)
	DISP_PROPERTY_NOTIFY(CAdvancedTimerCtrl, "Interval", m_interval, OnIntervalChanged, VT_I4)
	DISP_PROPERTY_NOTIFY(CAdvancedTimerCtrl, "TimerEnabled", m_timerEnabled, OnTimerEnabledChanged, VT_I4)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CAdvancedTimerCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CAdvancedTimerCtrl, COleControl)
	//{{AFX_EVENT_MAP(CAdvancedTimerCtrl)
	EVENT_CUSTOM("OnTimer", FireOnTimer, VTS_I2)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CAdvancedTimerCtrl, 1)
	PROPPAGEID(CAdvancedTimerPropPage::guid)
END_PROPPAGEIDS(CAdvancedTimerCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CAdvancedTimerCtrl, "MFCX1.AdvancedTimerCtrl.1",
	0xe7aa7bb6, 0x8dbe, 0x4d97, 0xac, 0x7d, 0xf1, 0x13, 0xee, 0x12, 0x10, 0x43)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CAdvancedTimerCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DAdvancedTimer =
		{ 0xf3053ac1, 0xc491, 0x4749, { 0x92, 0xf7, 0x89, 0xb9, 0xbc, 0x42, 0x79, 0xe4 } };
const IID BASED_CODE IID_DAdvancedTimerEvents =
		{ 0xeeb1e2e7, 0xabac, 0x4a30, { 0x95, 0x89, 0x3f, 0x29, 0x2f, 0x23, 0xa4, 0xa } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwAdvancedTimerOleMisc =
	OLEMISC_INVISIBLEATRUNTIME |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CAdvancedTimerCtrl, IDS_ADVANCEDTIMER, _dwAdvancedTimerOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CAdvancedTimerCtrl::CAdvancedTimerCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CAdvancedTimerCtrl

BOOL CAdvancedTimerCtrl::CAdvancedTimerCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_ADVANCEDTIMER,
			IDB_ADVANCEDTIMER,
			afxRegApartmentThreading,
			_dwAdvancedTimerOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CAdvancedTimerCtrl::CAdvancedTimerCtrl - Constructor

CAdvancedTimerCtrl::CAdvancedTimerCtrl()
{
	InitializeIIDs(&IID_DAdvancedTimer, &IID_DAdvancedTimerEvents);

	// TODO: Initialize your control's instance data here.
	this->m_timerEnabled	= FALSE;
	this->m_interval	= 1000;
}


/////////////////////////////////////////////////////////////////////////////
// CAdvancedTimerCtrl::~CAdvancedTimerCtrl - Destructor

CAdvancedTimerCtrl::~CAdvancedTimerCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CAdvancedTimerCtrl::OnDraw - Drawing function

void CAdvancedTimerCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CAdvancedTimerCtrl::DoPropExchange - Persistence support

void CAdvancedTimerCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CAdvancedTimerCtrl::OnResetState - Reset control to default state

void CAdvancedTimerCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CAdvancedTimerCtrl::AboutBox - Display an "About" box to the user

void CAdvancedTimerCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_ADVANCEDTIMER);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CAdvancedTimerCtrl message handlers

void CAdvancedTimerCtrl::OnIntervalChanged()
{
	// TODO: Add notification handler code
	if (m_timerEnabled) {
		::SetTimer(m_hWnd, 9999, m_interval, NULL);
	}
	SetModifiedFlag();
	OnTimer(9999);
}

void CAdvancedTimerCtrl::OnTimer(UINT nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	::MessageBox(NULL, "OnTimer", NULL, MB_OK);
	COleControl::OnTimer(nIDEvent);
	FireOnTimer(nIDEvent);
}

void CAdvancedTimerCtrl::OnTimerEnabledChanged()
{
	// TODO: Add notification handler code
	if (m_timerEnabled) {
		::SetTimer(m_hWnd, 9999, m_interval, NULL);
	} else {
		::KillTimer(m_hWnd, 9999);
	}
	SetModifiedFlag();
}
