// HelloPpg.cpp : Implementation of the CHelloPropPage property page class.

#include "stdafx.h"
#include "mfcx1.h"
#include "HelloPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CHelloPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CHelloPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CHelloPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CHelloPropPage, "MFCX1.HelloPropPage.1",
	0x3a25f58e, 0xff71, 0x47df, 0xb6, 0xf9, 0x65, 0x5c, 0x30, 0xd9, 0xc0, 0xeb)


/////////////////////////////////////////////////////////////////////////////
// CHelloPropPage::CHelloPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CHelloPropPage

BOOL CHelloPropPage::CHelloPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_HELLO_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CHelloPropPage::CHelloPropPage - Constructor

CHelloPropPage::CHelloPropPage() :
	COlePropertyPage(IDD, IDS_HELLO_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CHelloPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CHelloPropPage::DoDataExchange - Moves data between page and properties

void CHelloPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CHelloPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CHelloPropPage message handlers
