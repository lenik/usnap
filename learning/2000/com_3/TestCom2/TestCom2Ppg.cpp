// TestCom2Ppg.cpp : Implementation of the CTestCom2PropPage property page class.

#include "stdafx.h"
#include "TestCom2.h"
#include "TestCom2Ppg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CTestCom2PropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTestCom2PropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CTestCom2PropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTestCom2PropPage, "TESTCOM2.TestCom2PropPage.1",
	0x544f04f2, 0x8af3, 0x4384, 0x90, 0xcf, 0xa3, 0xba, 0x8e, 0xda, 0xf9, 0x3a)


/////////////////////////////////////////////////////////////////////////////
// CTestCom2PropPage::CTestCom2PropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CTestCom2PropPage

BOOL CTestCom2PropPage::CTestCom2PropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_TESTCOM2_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CTestCom2PropPage::CTestCom2PropPage - Constructor

CTestCom2PropPage::CTestCom2PropPage() :
	COlePropertyPage(IDD, IDS_TESTCOM2_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CTestCom2PropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CTestCom2PropPage::DoDataExchange - Moves data between page and properties

void CTestCom2PropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CTestCom2PropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CTestCom2PropPage message handlers
