// AdvancedTimerPpg.cpp : Implementation of the CAdvancedTimerPropPage property page class.

#include "stdafx.h"
#include "mfcx1.h"
#include "AdvancedTimerPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CAdvancedTimerPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CAdvancedTimerPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CAdvancedTimerPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CAdvancedTimerPropPage, "MFCX1.AdvancedTimerPropPage.1",
	0xc40d2f99, 0xb0e6, 0x43fb, 0x8b, 0x81, 0xa9, 0x28, 0xce, 0xf8, 0x18, 0x69)


/////////////////////////////////////////////////////////////////////////////
// CAdvancedTimerPropPage::CAdvancedTimerPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CAdvancedTimerPropPage

BOOL CAdvancedTimerPropPage::CAdvancedTimerPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_ADVANCEDTIMER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CAdvancedTimerPropPage::CAdvancedTimerPropPage - Constructor

CAdvancedTimerPropPage::CAdvancedTimerPropPage() :
	COlePropertyPage(IDD, IDS_ADVANCEDTIMER_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CAdvancedTimerPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CAdvancedTimerPropPage::DoDataExchange - Moves data between page and properties

void CAdvancedTimerPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CAdvancedTimerPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CAdvancedTimerPropPage message handlers
