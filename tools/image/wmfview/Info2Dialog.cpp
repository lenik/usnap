// Info2Dialog.cpp : implementation file
//

#include "stdafx.h"
#include "wmfview.h"
#include "Info2Dialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInfo2Dialog dialog


CInfo2Dialog::CInfo2Dialog(CWnd* pParent /*=NULL*/)
	: CDialog(CInfo2Dialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInfo2Dialog)
	m_strHDRSIZE = _T("");
	m_strMAXREC = _T("");
	m_strNOOBJ = _T("");
	m_strNOPARAM = _T("");
	m_strSIZE = _T("");
	m_strVERSION = _T("");
	m_strTYPE = _T("");
	//}}AFX_DATA_INIT
	Create(IDD_DIALOG_INFO2);
}


void CInfo2Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInfo2Dialog)
	DDX_Text(pDX, IDC_EDIT_HDRSIZE, m_strHDRSIZE);
	DDX_Text(pDX, IDC_EDIT_MAXREC, m_strMAXREC);
	DDX_Text(pDX, IDC_EDIT_NOOBJ, m_strNOOBJ);
	DDX_Text(pDX, IDC_EDIT_NOPARAM, m_strNOPARAM);
	DDX_Text(pDX, IDC_EDIT_SIZE, m_strSIZE);
	DDX_Text(pDX, IDC_EDIT_VERSION, m_strVERSION);
	DDX_Text(pDX, IDC_EDIT_TYPE, m_strTYPE);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInfo2Dialog, CDialog)
	//{{AFX_MSG_MAP(CInfo2Dialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInfo2Dialog message handlers
