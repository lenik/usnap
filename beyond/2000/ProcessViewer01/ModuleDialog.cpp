// ModuleDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ProcessViewer01.h"
#include "ModuleDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CModuleDialog dialog


CModuleDialog::CModuleDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CModuleDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CModuleDialog)
	m_mList = -1;
	m_pAddress = _T("");
	m_pData = 0;
	m_pType = 0;
	//}}AFX_DATA_INIT
}


void CModuleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CModuleDialog)
	DDX_LBIndex(pDX, IDC_MLIST, m_mList);
	DDX_Text(pDX, IDC_PADDRESS, m_pAddress);
	DDX_Text(pDX, IDC_PDATA, m_pData);
	DDX_CBIndex(pDX, IDC_PTYPE, m_pType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CModuleDialog, CDialog)
	//{{AFX_MSG_MAP(CModuleDialog)
	ON_BN_CLICKED(IDC_PREFRESH, OnPrefresh)
	ON_CBN_SELCHANGE(IDC_PLIST, OnSelchangePlist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModuleDialog message handlers

void CModuleDialog::OnPrefresh()
{
	// TODO: Add your control notification handler code here
	GetProcessList((CComboBox *)GetDlgItem(IDC_PLIST));
}

void CModuleDialog::OnSelchangePlist()
{
	CComboBox *lb;
	CString s;
	char Buf[256];
	DWORD idProcess;

	lb = (CComboBox *)GetDlgItem(IDC_PLIST);
	lb->GetWindowText(Buf, 255);

	idProcess = strtoul((LPCTSTR)Buf, NULL, 16);

	// TODO: Add your control notification handler code here
	GetModuleList((CListBox *)GetDlgItem(IDC_MLIST), idProcess);
}
