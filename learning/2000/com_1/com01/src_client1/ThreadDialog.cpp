// ThreadDialog.cpp : implementation file
//

#include "stdafx.h"
#include "src_client1.h"
#include "ThreadDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThreadDialog dialog


CThreadDialog::CThreadDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CThreadDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThreadDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CThreadDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThreadDialog)
	DDX_Control(pDX, IDC_STATIC_STATIC_SRC_THREAD, m_picStaticSrcThread);
	DDX_Control(pDX, IDC_STATIC_STATIC_SRC_PROCESS, m_picStaticSrcProcess);
	DDX_Control(pDX, IDC_STATIC_SRC_THREAD, m_picSrcThread);
	DDX_Control(pDX, IDC_STATIC_SRC_PROCESS, m_picSrcProcess);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CThreadDialog, CDialog)
	//{{AFX_MSG_MAP(CThreadDialog)
	ON_BN_CLICKED(IDC_BUTTON_APPLY_ALL, OnButtonApplyAll)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreadDialog message handlers

void CThreadDialog::OnButtonApplyAll()
{
	// TODO: Add your control notification handler code here
	queryallsrc("Thread1");
}

void CThreadDialog::UpdateAvailview() {
	BOOL	r;

	r = QueryThreadAvailable();
	m_picSrcThread.SetBitmap(
		::LoadBitmap(
			AfxGetApp()->m_hInstance,
			r ? IDB_BITMAP_AVAIL : IDB_BITMAP_NOTAVAIL
		)
	);

	UpdateData(FALSE);

}
