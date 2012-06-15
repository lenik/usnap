// LogDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Valider.h"
#include "LogDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogDialog dialog


CLogDialog::CLogDialog(CWnd* pParent /*=NULL*/, CString log /*=NULL*/)
	: CDialog(CLogDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogDialog)
	m_strLog = log;
	//}}AFX_DATA_INIT
}


void CLogDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogDialog)
	DDX_Text(pDX, IDC_EDIT_LOG, m_strLog);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogDialog, CDialog)
	//{{AFX_MSG_MAP(CLogDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogDialog message handlers
