// ProcessDialog.cpp : implementation file
//

#include "stdafx.h"
#include "src_client1.h"
#include "ProcessDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProcessDialog dialog


CProcessDialog::CProcessDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CProcessDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProcessDialog)
	m_strName = _T("");
	//}}AFX_DATA_INIT
}


void CProcessDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProcessDialog)
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDV_MaxChars(pDX, m_strName, 32);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProcessDialog, CDialog)
	//{{AFX_MSG_MAP(CProcessDialog)
	ON_BN_CLICKED(IDC_BUTTON_CREATE_THREAD, OnButtonCreateThread)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProcessDialog message handlers

void CProcessDialog::OnButtonCreateThread()
{
	// TODO: Add your control notification handler code here
	HANDLE	hThread;
	DWORD	idThread;

	CThreadDialog *tdlg = new CThreadDialog;

	hThread = CreateThread(NULL, 0, _, m_strName.AllocSysString(), 0, &id);
	CloseHandle(hThread);
}
