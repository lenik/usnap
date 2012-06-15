// HexEditCtlPpg.cpp : Implementation of the CHexEditCtlPropPage property page class.

#include "stdafx.h"
#include "HexEditCtl.h"
#include "HexEditCtlCtl.h"
#include "HexEditCtlPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CHexEditCtlPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CHexEditCtlPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CHexEditCtlPropPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CHexEditCtlPropPage, "HEXEDITCTL.HexEditCtlPropPage.1",
	0x7c7e1272, 0xc0a6, 0x4072, 0x96, 0, 0x62, 0x8b, 0x43, 0x1f, 0x2c, 0xdb)


/////////////////////////////////////////////////////////////////////////////
// CHexEditCtlPropPage::CHexEditCtlPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CHexEditCtlPropPage

BOOL CHexEditCtlPropPage::CHexEditCtlPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_HEXEDITCTL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CHexEditCtlPropPage::CHexEditCtlPropPage - Constructor

CHexEditCtlPropPage::CHexEditCtlPropPage() :
	COlePropertyPage(IDD, IDS_HEXEDITCTL_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CHexEditCtlPropPage)
	m_LeftMargin = _T("");
	m_TopMargin = _T("");
	m_Check = FALSE;
	m_Height = 0;
	m_Width = 0;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CHexEditCtlPropPage::DoDataExchange - Moves data between page and properties

void CHexEditCtlPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CHexEditCtlPropPage)
	DDX_Text(pDX, IDC_LeftMargin, m_LeftMargin);
	DDX_Text(pDX, IDC_TopMargin, m_TopMargin);
	DDX_Check(pDX, IDC_Display, m_Check);
	DDX_Text(pDX, IDC_Height, m_Height);
	DDX_Text(pDX, IDC_Width, m_Width);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CHexEditCtlPropPage message handlers


BOOL CHexEditCtlPropPage::OnInitDialog()
{
	COlePropertyPage::OnInitDialog();

	LPDISPATCH *	pObjs = NULL;
	ULONG			nObjs = 0;

	pObjs = GetObjectArray(&nObjs);
	ASSERT(pObjs && nObjs > 0);

	HRESULT hr;
	IUnknown *		pObj = NULL;
	hr = pObjs[0]->QueryInterface(IID_IUnknown, (void **)&pObj);
	ASSERT(SUCCEEDED(hr));

	m_pObj = (CHexEditCtlCtrl *)pObj;
	m_pObj->AssertValid();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
