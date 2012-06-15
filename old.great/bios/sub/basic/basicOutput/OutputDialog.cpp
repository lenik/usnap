// OutputDialog.cpp : implementation file
//

#include "stdafx.h"
#include "basicOutput.h"
#include "OutputDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutputDialog dialog


COutputDialog::COutputDialog(CWnd* pParent /*=NULL*/)
	: CDialog(COutputDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(COutputDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void COutputDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COutputDialog)
	DDX_Control(pDX, IDC_EDIT_MAINBOX, m_mainbox);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COutputDialog, CDialog)
	//{{AFX_MSG_MAP(COutputDialog)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutputDialog message handlers

void COutputDialog::OnOK()
{
	// TODO: Add extra validation here

	CDialog::OnOK();
}

void COutputDialog::OnCancel()
{
	// TODO: Add extra cleanup here

	CDialog::OnCancel();
}

void COutputDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	RECT r;
//	this->m_mainbox.GetWindowRect(&r);
//	this->m_mainbox.MoveWindow(r.left, r.top, cx, cy);
}
