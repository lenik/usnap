// TraceLogsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "oletrace_cfg.h"
#include "TraceLogsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTraceLogsDlg dialog


CTraceLogsDlg::CTraceLogsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTraceLogsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTraceLogsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTraceLogsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTraceLogsDlg)
	DDX_Control(pDX, IDC_TREE_LOGS, m_treeLogs);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTraceLogsDlg, CDialog)
	//{{AFX_MSG_MAP(CTraceLogsDlg)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTraceLogsDlg message handlers

void CTraceLogsDlg::OnClear()
{

}
