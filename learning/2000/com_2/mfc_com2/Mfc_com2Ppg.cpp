// Mfc_com2Ppg.cpp : Implementation of the CMfc_com2PropPage property page class.

#include "stdafx.h"
#include "mfc_com2.h"
#include "Mfc_com2Ppg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CMfc_com2PropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CMfc_com2PropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CMfc_com2PropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMfc_com2PropPage, "MFCCOM2.Mfccom2PropPage.1",
	0xdc8e8cb4, 0xd4ea, 0x44ed, 0x89, 0x42, 0xc5, 0x8e, 0xb4, 0x7c, 0x61, 0x1b)


/////////////////////////////////////////////////////////////////////////////
// CMfc_com2PropPage::CMfc_com2PropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CMfc_com2PropPage

BOOL CMfc_com2PropPage::CMfc_com2PropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MFC_COM2_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CMfc_com2PropPage::CMfc_com2PropPage - Constructor

CMfc_com2PropPage::CMfc_com2PropPage() :
	COlePropertyPage(IDD, IDS_MFC_COM2_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CMfc_com2PropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CMfc_com2PropPage::DoDataExchange - Moves data between page and properties

void CMfc_com2PropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CMfc_com2PropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CMfc_com2PropPage message handlers
