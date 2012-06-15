// InfoDialog.cpp : implementation file
//

#include "stdafx.h"
#include "wmfview.h"
#include "InfoDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInfoDialog dialog


CInfoDialog::CInfoDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CInfoDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInfoDialog)
	m_strBBOX = _T("");
	m_strCHECKSUM = _T("");
	m_strHMF = _T("");
	m_strINCH = _T("");
	m_strKEY = _T("");
	m_strRESERVED = _T("");
	//}}AFX_DATA_INIT
	Create(IDD_DIALOG_INFO);
}


void CInfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInfoDialog)
	DDX_Text(pDX, IDC_EDIT_BBOX, m_strBBOX);
	DDX_Text(pDX, IDC_EDIT_CHECKSUM, m_strCHECKSUM);
	DDX_Text(pDX, IDC_EDIT_HMF, m_strHMF);
	DDX_Text(pDX, IDC_EDIT_INCH, m_strINCH);
	DDX_Text(pDX, IDC_EDIT_KEY, m_strKEY);
	DDX_Text(pDX, IDC_EDIT_RESERVED, m_strRESERVED);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInfoDialog, CDialog)
	//{{AFX_MSG_MAP(CInfoDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInfoDialog message handlers
