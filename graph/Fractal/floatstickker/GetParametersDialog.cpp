// GetParametersDialog.cpp : implementation file
//

#include "stdafx.h"
#include "floatstickker.h"
#include "GetParametersDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGetParametersDialog dialog


CGetParametersDialog::CGetParametersDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CGetParametersDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGetParametersDialog)
	m_nums = 0;
	m_power = 0.0;
	m_speed = 0.0;
	m_radius = 0.0;
	//}}AFX_DATA_INIT
}


void CGetParametersDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGetParametersDialog)
	DDX_Text(pDX, IDC_EDIT_NUMS, m_nums);
	DDV_MinMaxInt(pDX, m_nums, 3, 99999);
	DDX_Text(pDX, IDC_EDIT_POWER, m_power);
	DDV_MinMaxDouble(pDX, m_power, 1.e-004, 5.e-002);
	DDX_Text(pDX, IDC_EDIT_SPEED, m_speed);
	DDV_MinMaxDouble(pDX, m_speed, 1.e-004, 0.2);
	DDX_Text(pDX, IDC_EDIT_RADIUS, m_radius);
	DDV_MinMaxDouble(pDX, m_radius, 1.e-004, 0.3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGetParametersDialog, CDialog)
	//{{AFX_MSG_MAP(CGetParametersDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetParametersDialog message handlers
