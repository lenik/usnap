// PromptDialog.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "PromptDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPromptDialog dialog


CPromptDialog::CPromptDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CPromptDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPromptDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPromptDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPromptDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPromptDialog, CDialog)
	//{{AFX_MSG_MAP(CPromptDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPromptDialog message handlers
