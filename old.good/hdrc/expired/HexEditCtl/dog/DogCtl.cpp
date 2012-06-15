// DogCtl.cpp : Implementation of the CDogCtrl ActiveX Control class.

#include "stdafx.h"
#include "dog.h"
#include "DogCtl.h"
#include "DogPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CDogCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CDogCtrl, COleControl)
	//{{AFX_MSG_MAP(CDogCtrl)
	ON_WM_CREATE()
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CDogCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CDogCtrl)
	DISP_FUNCTION(CDogCtrl, "ShowName", ShowName, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CDogCtrl, "GetRawObject", GetRawObject, VT_I4, VTS_NONE)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CDogCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CDogCtrl, COleControl)
	//{{AFX_EVENT_MAP(CDogCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CDogCtrl, 1)
	PROPPAGEID(CDogPropPage::guid)
END_PROPPAGEIDS(CDogCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CDogCtrl, "DOG.DogCtrl.1",
	0xf4a61a17, 0xcc0d, 0x482f, 0xa1, 0xb2, 0xd6, 0xd7, 0x46, 0xfd, 0x72, 0x49)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CDogCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DDog =
		{ 0x5e562824, 0x7785, 0x4d23, { 0x93, 0x94, 0x50, 0x29, 0x78, 0xf7, 0xe7, 0x36 } };
const IID BASED_CODE IID_DDogEvents =
		{ 0xa8d7d3f5, 0x94bc, 0x4358, { 0xb0, 0xac, 0x3a, 0xcd, 0x90, 0x42, 0xe0, 0x3b } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwDogOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CDogCtrl, IDS_DOG, _dwDogOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CDogCtrl::CDogCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CDogCtrl

BOOL CDogCtrl::CDogCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_DOG,
			IDB_DOG,
			afxRegApartmentThreading,
			_dwDogOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CDogCtrl::CDogCtrl - Constructor

CDogCtrl::CDogCtrl()
{
	InitializeIIDs(&IID_DDog, &IID_DDogEvents);

	// TODO: Initialize your control's instance data here.
    m_szName = "Hello";
    m_hButtonShow = NULL;
}


/////////////////////////////////////////////////////////////////////////////
// CDogCtrl::~CDogCtrl - Destructor

CDogCtrl::~CDogCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CDogCtrl::OnDraw - Drawing function

void CDogCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CDogCtrl::DoPropExchange - Persistence support

void CDogCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}



/////////////////////////////////////////////////////////////////////////////
// CDogCtrl::AboutBox - Display an "About" box to the user

void CDogCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_DOG);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CDogCtrl message handlers

void CDogCtrl::ShowName()
{
    ::MessageBox(0, this->m_szName, 0, 0);
}

int CDogCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;


    m_hButtonShow = ::CreateWindow("BUTTON", "Show my name",
        WS_CHILD, 10, 10, 50, 20, this->m_hWnd, NULL, AfxGetApp()->m_hInstance, NULL);

    ASSERT(m_hButtonShow != NULL);
    ::ShowWindow(m_hButtonShow, SW_NORMAL);

	return 0;
}

void CDogCtrl::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    switch (nChar | ' ') {
    case 's':
        this->ShowName();
        break;
    }
	COleControl::OnChar(nChar, nRepCnt, nFlags);
}

long CDogCtrl::GetRawObject()
{
	return (long)this;
}
