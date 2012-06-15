// DetailDialog.cpp : implementation file
//

#include "stdafx.h"
#include "scomp2_client2.h"
#include "DetailDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDetailDialog dialog


CDetailDialog::CDetailDialog(CWnd* pParent /*=NULL*/, CString initText)
	: CDialog(CDetailDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDetailDialog)
	m_strInfo = _T("正在加载组件中, 请稍后...");
	//}}AFX_DATA_INIT
	this->bFirstInited	= FALSE;
	this->m_strText		= initText;
}


void CDetailDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDetailDialog)
	DDX_Control(pDX, IDC_DHTML_LEFTBORDER, m_con_dhtml_leftborder);
	DDX_Control(pDX, IDC_DHTML, m_dhtml);
	DDX_Text(pDX, IDC_INFO, m_strInfo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDetailDialog, CDialog)
	//{{AFX_MSG_MAP(CDetailDialog)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDetailDialog message handlers

void CDetailDialog::OnOK()
{
	// TODO: Add extra validation here

	CDialog::OnOK();
}

void CDetailDialog::OnButtonSave()
{
	// TODO: Add your control notification handler code here
	CFileDialog	fd(FALSE, _T("html"), _T("比较结果.html"));
	if (fd.DoModal() == IDOK) {
		TRY {
			CString fn = fd.GetPathName();
			CFile f(fn, CFile::modeCreate | CFile::modeWrite);
			CString s = this->m_dhtml.GetDocumentHTML();
			f.Write((const void *)(LPCTSTR)s, s.GetLength());
			f.Close();
		} CATCH(CFileException, fe) {
			fe->ReportError();
		} END_CATCH;
	}
}

BOOL CDetailDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BEGIN_EVENTSINK_MAP(CDetailDialog, CDialog)
    //{{AFX_EVENTSINK_MAP(CDetailDialog)
	ON_EVENT(CDetailDialog, IDC_DHTML, 1 /* DocumentComplete */, OnDocumentCompleteDhtml, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CDetailDialog::OnDocumentCompleteDhtml()
{
	if (!this->bFirstInited) {
		this->m_strInfo		= _T("");
		UpdateData(FALSE);
		this->bFirstInited	= TRUE;
		this->m_dhtml.SetDocumentHTML(this->m_strText);
	}
}

void CDetailDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here

	if (this->bFirstInited && nType == SIZE_RESTORED) {
		RECT	rect, rect2;
		this->m_dhtml.GetWindowRect(&rect);
		this->ScreenToClient(&rect);
		this->m_dhtml.MoveWindow(rect.left, rect.top, cx - 112, cy - 32);
		this->m_con_dhtml_leftborder.GetWindowRect(&rect2);
		this->ScreenToClient(&rect2);
		this->m_con_dhtml_leftborder.MoveWindow(rect2.left, rect2.top, rect2.right - rect2.left, cy - 32);
	}
}
