// HtmlViewerDialog.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "HtmlViewerDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHtmlViewerDialog dialog


CHtmlViewerDialog::CHtmlViewerDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CHtmlViewerDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHtmlViewerDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CHtmlViewerDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHtmlViewerDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHtmlViewerDialog, CDialog)
	//{{AFX_MSG_MAP(CHtmlViewerDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHtmlViewerDialog message handlers
