// ThreadDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ProcessViewer01.h"
#include "ThreadDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThreadDialog dialog


CThreadDialog::CThreadDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CThreadDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThreadDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CThreadDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThreadDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CThreadDialog, CDialog)
	//{{AFX_MSG_MAP(CThreadDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreadDialog message handlers
