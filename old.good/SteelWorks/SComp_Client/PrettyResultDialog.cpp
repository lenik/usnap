// PrettyResultDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SComp_Client.h"
#include "PrettyResultDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrettyResultDialog dialog


CPrettyResultDialog::CPrettyResultDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CPrettyResultDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrettyResultDialog)
	m_strComp = _T("");
	m_strResult = _T("");
	m_strTemp = _T("");
	//}}AFX_DATA_INIT
	Create(IDD_DIALOG_PRETTY_RESULT);
}


void CPrettyResultDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrettyResultDialog)
	DDX_Text(pDX, IDC_EDIT_COMP, m_strComp);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_strResult);
	DDX_Text(pDX, IDC_EDIT_TEMP, m_strTemp);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPrettyResultDialog, CDialog)
	//{{AFX_MSG_MAP(CPrettyResultDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrettyResultDialog message handlers
