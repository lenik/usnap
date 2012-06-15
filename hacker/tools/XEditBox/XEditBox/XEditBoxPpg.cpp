// XEditBoxPpg.cpp : Implementation of the CXEditBoxPropPage property page class.

#include "stdafx.h"
#include "XEditBox.h"
#include "XEditBoxPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CXEditBoxPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CXEditBoxPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CXEditBoxPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CXEditBoxPropPage, "XEDITBOX.XEditBoxPropPage.1",
	0x1ca0b387, 0x9d82, 0x4433, 0xa3, 0xa2, 0x2c, 0x7e, 0x5a, 0x5b, 0xa8, 0x84)


/////////////////////////////////////////////////////////////////////////////
// CXEditBoxPropPage::CXEditBoxPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CXEditBoxPropPage

BOOL CXEditBoxPropPage::CXEditBoxPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_XEDITBOX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CXEditBoxPropPage::CXEditBoxPropPage - Constructor

CXEditBoxPropPage::CXEditBoxPropPage() :
	COlePropertyPage(IDD, IDS_XEDITBOX_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CXEditBoxPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT

	SetHelpInfo(_T("Names to appear in the control"), _T("XEDITBOX.HLP"), 0);
}


/////////////////////////////////////////////////////////////////////////////
// CXEditBoxPropPage::DoDataExchange - Moves data between page and properties

void CXEditBoxPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CXEditBoxPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CXEditBoxPropPage message handlers
