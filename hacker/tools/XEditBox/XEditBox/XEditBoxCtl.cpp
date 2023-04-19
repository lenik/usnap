// XEditBoxCtl.cpp : Implementation of the CXEditBoxCtrl ActiveX Control class.

#include "stdafx.h"
#include "XEditBox.h"
#include "XEditBoxCtl.h"
#include "XEditBoxPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CXEditBoxCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CXEditBoxCtrl, COleControl)
	//{{AFX_MSG_MAP(CXEditBoxCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CXEditBoxCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CXEditBoxCtrl)
	// NOTE - ClassWizard will add and remove dispatch map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CXEditBoxCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CXEditBoxCtrl, COleControl)
	//{{AFX_EVENT_MAP(CXEditBoxCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CXEditBoxCtrl, 1)
	PROPPAGEID(CXEditBoxPropPage::guid)
END_PROPPAGEIDS(CXEditBoxCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CXEditBoxCtrl, "XEDITBOX.XEditBoxCtrl.1",
	0x84908e2, 0xfff, 0x4057, 0xb2, 0x72, 0x46, 0x3a, 0xe4, 0x55, 0x1, 0xf0)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CXEditBoxCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DXEditBox =
		{ 0x9eb88073, 0x4ac4, 0x4cd1, { 0x89, 0xd3, 0x83, 0x86, 0x51, 0x11, 0x3, 0x62 } };
const IID BASED_CODE IID_DXEditBoxEvents =
		{ 0xebdcd718, 0x224b, 0x44f6, { 0x9e, 0x8d, 0xf2, 0xab, 0xe4, 0xa2, 0x3, 0xdc } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwXEditBoxOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CXEditBoxCtrl, IDS_XEDITBOX, _dwXEditBoxOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CXEditBoxCtrl::CXEditBoxCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CXEditBoxCtrl

BOOL CXEditBoxCtrl::CXEditBoxCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_XEDITBOX,
			IDB_XEDITBOX,
			afxRegApartmentThreading,
			_dwXEditBoxOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// Licensing strings

static const TCHAR BASED_CODE _szLicFileName[] = _T("XEditBox.lic");

static const WCHAR BASED_CODE _szLicString[] =
	L"Copyright (c) 2002 识惠软件公司·中国";


/////////////////////////////////////////////////////////////////////////////
// CXEditBoxCtrl::CXEditBoxCtrlFactory::VerifyUserLicense -
// Checks for existence of a user license

BOOL CXEditBoxCtrl::CXEditBoxCtrlFactory::VerifyUserLicense()
{
	return AfxVerifyLicFile(AfxGetInstanceHandle(), _szLicFileName,
		_szLicString);
}


/////////////////////////////////////////////////////////////////////////////
// CXEditBoxCtrl::CXEditBoxCtrlFactory::GetLicenseKey -
// Returns a runtime licensing key

BOOL CXEditBoxCtrl::CXEditBoxCtrlFactory::GetLicenseKey(DWORD dwReserved,
	BSTR FAR* pbstrKey)
{
	if (pbstrKey == NULL)
		return FALSE;

	*pbstrKey = SysAllocString(_szLicString);
	return (*pbstrKey != NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CXEditBoxCtrl::CXEditBoxCtrl - Constructor

CXEditBoxCtrl::CXEditBoxCtrl()
{
	InitializeIIDs(&IID_DXEditBox, &IID_DXEditBoxEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CXEditBoxCtrl::~CXEditBoxCtrl - Destructor

CXEditBoxCtrl::~CXEditBoxCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CXEditBoxCtrl::OnDraw - Drawing function

void CXEditBoxCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CXEditBoxCtrl::DoPropExchange - Persistence support

void CXEditBoxCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CXEditBoxCtrl::OnResetState - Reset control to default state

void CXEditBoxCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CXEditBoxCtrl::AboutBox - Display an "About" box to the user

void CXEditBoxCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_XEDITBOX);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CXEditBoxCtrl message handlers
