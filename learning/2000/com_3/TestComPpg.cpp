// TestComPpg.cpp : Implementation of the CTestComPropPage property page class.

#include "stdafx.h"
#include "TestCom.h"
#include "TestComPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CTestComPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTestComPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CTestComPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTestComPropPage, "TESTCOM.TestComPropPage.1",
	0xcf2517c6, 0xb227, 0x464e, 0x8b, 0xc4, 0xfa, 0x13, 0xfa, 0x57, 0xde, 0x39)


/////////////////////////////////////////////////////////////////////////////
// CTestComPropPage::CTestComPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CTestComPropPage

BOOL CTestComPropPage::CTestComPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_TESTCOM_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CTestComPropPage::CTestComPropPage - Constructor

CTestComPropPage::CTestComPropPage() :
	COlePropertyPage(IDD, IDS_TESTCOM_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CTestComPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CTestComPropPage::DoDataExchange - Moves data between page and properties

void CTestComPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CTestComPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CTestComPropPage message handlers
