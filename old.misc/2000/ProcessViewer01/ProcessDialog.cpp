// ProcessDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ProcessViewer01.h"
#include "ProcessDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#include <GWin.h>

/////////////////////////////////////////////////////////////////////////////
// CProcessDialog dialog


CProcessDialog::CProcessDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CProcessDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProcessDialog)
	m_pAddress = 0;
	m_pData = 0;
	m_pList = _T("");
	m_pType = 0;
	//}}AFX_DATA_INIT
}


void CProcessDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProcessDialog)
	DDX_Control(pDX, IDC_PLIST, m_lstpList);
	DDX_Text(pDX, IDC_PADDRESS, m_pAddress);
	DDX_Text(pDX, IDC_PDATA, m_pData);
	DDX_LBString(pDX, IDC_PLIST, m_pList);
	DDX_CBIndex(pDX, IDC_PTYPE, m_pType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProcessDialog, CDialog)
	//{{AFX_MSG_MAP(CProcessDialog)
	ON_BN_CLICKED(IDC_PREFRESH, OnPrefresh)
	ON_BN_CLICKED(IDC_PREAD, OnPread)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProcessDialog message handlers

void CProcessDialog::OnPrefresh()
{
	GetProcessList((CListBox *)GetDlgItem(IDC_PLIST));
}

void CProcessDialog::OnPread()
{
	CListBox *cb;
	char Buf[256];
	DWORD PId;
	HANDLE hProcess;

	UpdateData(TRUE);
	cb = (CListBox *)GetDlgItem(IDC_PLIST);
	cb->GetText(cb->GetCurSel(), (LPTSTR)Buf);

	PId = strtoul(Buf, NULL, 16);
	hProcess = OpenProcess(PROCESS_VM_READ, TRUE, PId);
	if (ReadProcessMemory(hProcess, (LPCVOID)m_pAddress, (LPVOID)m_pData, 4, NULL) == 0) {
		PrintError(GetLastError());
	}


	CloseHandle(hProcess);
	UpdateData(FALSE);

}
