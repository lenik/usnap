// SubstitudingDialog.cpp : implementation file
//

#include "stdafx.h"
#include "replace.h"
#include "SubstitudingDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubstitudingDialog dialog


CSubstitudingDialog::CSubstitudingDialog()
	: CDialog(CSubstitudingDialog::IDD, NULL)
{
	//{{AFX_DATA_INIT(CSubstitudingDialog)
	m_strCurrentFilename = _T("");
	m_strSubcon = _T("");
	//}}AFX_DATA_INIT
}


void CSubstitudingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubstitudingDialog)
	DDX_Text(pDX, IDC_STATIC_CURRENT_FILENAME, m_strCurrentFilename);
	DDX_Text(pDX, IDC_STATIC_SUBCON, m_strSubcon);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubstitudingDialog, CDialog)
	//{{AFX_MSG_MAP(CSubstitudingDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubstitudingDialog message handlers

void CSubstitudingDialog::OnOK()
{
	// TODO: Add extra validation here

}

void CSubstitudingDialog::OnCancel()
{
	// TODO: Add extra cleanup here

	CDialog::OnCancel();
}
