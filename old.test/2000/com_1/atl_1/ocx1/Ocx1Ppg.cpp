// Ocx1Ppg.cpp : Implementation of the COcx1PropPage property page class.

#include "stdafx.h"
#include "ocx1.h"
#include "Ocx1Ppg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(COcx1PropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(COcx1PropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(COcx1PropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(COcx1PropPage, "OCX1.Ocx1PropPage.1",
	0x2ef4e002, 0x22b9, 0x47ce, 0x9d, 0x1e, 0xc3, 0x8a, 0x11, 0xa7, 0x2, 0x5b)


/////////////////////////////////////////////////////////////////////////////
// COcx1PropPage::COcx1PropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for COcx1PropPage

BOOL COcx1PropPage::COcx1PropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_OCX1_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// COcx1PropPage::COcx1PropPage - Constructor

COcx1PropPage::COcx1PropPage() :
	COlePropertyPage(IDD, IDS_OCX1_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(COcx1PropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// COcx1PropPage::DoDataExchange - Moves data between page and properties

void COcx1PropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(COcx1PropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// COcx1PropPage message handlers
