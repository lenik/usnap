// Mfc02About.cpp : implementation file
//

#include "stdafx.h"
#include "mfc02.h"
#include "Mfc02About.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMfc02About dialog


CMfc02About::CMfc02About(CWnd* pParent /*=NULL*/)
	: CDialog(CMfc02About::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMfc02About)
	m_strT = _T("");
	//}}AFX_DATA_INIT
}


void CMfc02About::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMfc02About)
	DDX_Control(pDX, IDC_PROGRESS, m_p1);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_strT);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMfc02About, CDialog)
	//{{AFX_MSG_MAP(CMfc02About)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMfc02About message handlers
