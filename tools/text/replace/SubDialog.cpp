// SubDialog.cpp : implementation file
//

#include "stdafx.h"
#include "replace.h"
#include "SubDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubDialog dialog


CSubDialog::CSubDialog(CString src, CString dest)
	: CDialog(CSubDialog::IDD, NULL)
{
	//{{AFX_DATA_INIT(CSubDialog)
	m_strDest = src;
	m_strSrc = dest;
	//}}AFX_DATA_INIT
}


void CSubDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubDialog)
	DDX_Text(pDX, IDC_EDIT_DEST, m_strDest);
	DDX_Text(pDX, IDC_EDIT_SRC, m_strSrc);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubDialog, CDialog)
	//{{AFX_MSG_MAP(CSubDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubDialog message handlers

void CSubDialog::OnOK()
{
	// TODO: Add extra validation here

	CDialog::OnOK();
}

void CSubDialog::OnCancel()
{
	// TODO: Add extra cleanup here

	CDialog::OnCancel();
}
