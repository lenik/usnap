// SSDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ssView.h"
#include "SSDialog.h"
#include "ssEleCon.h"

#include "makeSS\makeSS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSSDialog dialog

CSSDialog::CSSDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSSDialog::IDD, pParent), m_pviewOwner(NULL)
{
	//{{AFX_DATA_INIT(CSSDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CSSDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSSDialog)
	DDX_Control(pDX, IDC_TREESTORAGE, m_treeStorage);
	DDX_Control(pDX, IDC_TREECONTENT, m_treeContent);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSSDialog, CDialog)
	//{{AFX_MSG_MAP(CSSDialog)
	ON_NOTIFY(NM_CLICK, IDC_TREESTORAGE, OnClickTreestorage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSSDialog message handlers

void CSSDialog::OnClickTreestorage(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	HTREEITEM	hI;
	CString		text;
	DWORD		data;
	HRESULT		hr;

	hI	= m_treeStorage.GetSelectedItem();
	if (hI != NULL) {
		m_treeContent.DeleteAllItems();
		text	= m_treeStorage.GetItemText(hI);
		data	= m_treeStorage.GetItemData(hI);
		if (data & ELE_STORAGE) {
			IEnumSTATSTG	*penum;
			STATSTG		rgelt;
			hr	= m_pStg->EnumElements(0, NULL, 0, &penum);
			if (SUCCEEDED(hr)) {
				penum->Reset();
				while (penum->Next(1, &rgelt, NULL) == S_OK) {
					m_treeStorage.InsertItem(
						tombs(rgelt.pwcsName),
						hI);
				}
			}
		}
	}

	*pResult = 0;
}