// MoreControls.cpp : implementation file
//

#include "stdafx.h"
#include "CpTrans.h"
#include "MoreControls.h"

#include "MainFrm.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMoreControls dialog


CMoreControls::CMoreControls(CWnd* pParent /*=NULL*/)
	: CDialog(CMoreControls::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMoreControls)
	m_sliderSpeed = 0;
	m_speed = 0.0;
	//}}AFX_DATA_INIT
}


void CMoreControls::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMoreControls)
	DDX_Text(pDX, IDC_EDIT_SPEED, m_speed);
	DDV_MinMaxDouble(pDX, m_speed, 0.1, 1000.);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMoreControls, CDialog)
	//{{AFX_MSG_MAP(CMoreControls)
	ON_EN_CHANGE(IDC_EDIT_SPEED, OnChangeEditSpeed)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMoreControls message handlers

void CMoreControls::OnChangeEditSpeed()
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO: Add your control notification handler code here
	TCHAR	buf[64];
	UpdateData();
	CChildView::_sleep_val	= m_speed;
	CMainFrame	*pFrame	= (CMainFrame *)AfxGetApp()->GetMainWnd()->GetParentFrame();
	sprintf(buf, "%4.0f", m_speed);
	pFrame->setStatus(1, buf);
}
