// DogPpg.cpp : Implementation of the CDogPropPage property page class.

#include "stdafx.h"
#include "dog.h"
#include "DogPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CDogPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CDogPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CDogPropPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CDogPropPage, "DOG.DogPropPage.1",
	0xc9c0132c, 0x5938, 0x4308, 0xab, 0xfe, 0x63, 0xc9, 0xce, 0x57, 0xec, 0x3b)


/////////////////////////////////////////////////////////////////////////////
// CDogPropPage::CDogPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CDogPropPage

BOOL CDogPropPage::CDogPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_DOG_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CDogPropPage::CDogPropPage - Constructor

CDogPropPage::CDogPropPage() :
	COlePropertyPage(IDD, IDS_DOG_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CDogPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CDogPropPage::DoDataExchange - Moves data between page and properties

void CDogPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CDogPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);

}


/////////////////////////////////////////////////////////////////////////////
// CDogPropPage message handlers

BOOL CDogPropPage::OnInitDialog()
{
	COlePropertyPage::OnInitDialog();
	LPDISPATCH *	pObjs = NULL;
	ULONG			nObjs = 0;

	pObjs = GetObjectArray(&nObjs);
	ASSERT(pObjs && nObjs > 0);

	HRESULT hr;
	_DDog *		pObj = NULL;
	hr = pObjs[0]->QueryInterface(IID__DDog, (void **)&pObj);
	ASSERT(SUCCEEDED(hr));

	CDogCtrl *pDogCtrl = (void *)pObj->GetRawObject();

    //pDogCtrl->m_szName
    pDogCtrl->AssertValid();

    return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
