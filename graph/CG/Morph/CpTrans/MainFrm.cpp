// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "CpTrans.h"

#include "MainFrm.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_COMMAND(ID_BUTTON_CHKRES, OnButtonChkRes)
	ON_COMMAND(ID_BUTTON_CHKWAIT, OnButtonChkWait)
	ON_WM_LBUTTONDBLCLK()
	ON_UPDATE_COMMAND_UI(ID_SPEED_FAST, OnUpdateSpeedFast)
	ON_UPDATE_COMMAND_UI(ID_SPEED_SLOW, OnUpdateSpeedSlow)
	ON_COMMAND(ID_BUTTON_PIXEL_OR_LINE, OnButtonPixelOrLine)
	ON_COMMAND(ID_BUTTON_PRECISE, OnButtonPrecise)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	// create a view to occupy the client area of the frame
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}

	if (!m_wndToolBar.CreateEx(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	if (!m_wndDlgBar.Create(this, IDR_MAINFRAME,
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("Failed to create dialogbar\n");
		return -1;		// fail to create
	}

	if (!m_wndReBar.Create(this) ||
		!m_wndReBar.AddBar(&m_wndToolBar) ||
		!m_wndReBar.AddBar(&m_wndDlgBar))
	{
		TRACE0("Failed to create rebar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndToolBar.SetButtonStyle(
		m_wndToolBar.CommandToIndex(ID_BUTTON_CHKRES),
		TBBS_CHECKBOX
		);
	m_wndToolBar.SetButtonStyle(
		m_wndToolBar.CommandToIndex(ID_BUTTON_CHKWAIT),
		TBBS_CHECKBOX
		);
	m_wndToolBar.SetButtonStyle(
		m_wndToolBar.CommandToIndex(ID_BUTTON_PIXEL_OR_LINE),
		TBBS_CHECKBOX
		);
	m_wndToolBar.SetButtonStyle(
		m_wndToolBar.CommandToIndex(ID_BUTTON_PRECISE),
		TBBS_CHECKBOX
		);

	SetWindowPos(&wndTop, 10, 10, 500, 500, 0);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
void CMainFrame::OnSetFocus(CWnd* pOldWnd)
{
	// forward focus to the view window
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// let the view have first crack at the command
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// otherwise, do default handling
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL CMainFrame::setStatus(int paneIndex, LPCTSTR paneText) {
	return m_wndStatusBar.SetPaneText(paneIndex, paneText);
}

BOOL CMainFrame::getChkres() {
	CToolBarCtrl &	tbc = m_wndToolBar.GetToolBarCtrl();
	return tbc.IsButtonChecked(ID_BUTTON_CHKRES);
}

BOOL CMainFrame::getChkwait() {
	CToolBarCtrl &	tbc = m_wndToolBar.GetToolBarCtrl();
	return tbc.IsButtonChecked(ID_BUTTON_CHKWAIT);
}

BOOL CMainFrame::getChkpixelorline() {
	CToolBarCtrl &	tbc = m_wndToolBar.GetToolBarCtrl();
	return tbc.IsButtonChecked(ID_BUTTON_PIXEL_OR_LINE);
}

BOOL CMainFrame::getChkprecise() {
	CToolBarCtrl &	tbc = m_wndToolBar.GetToolBarCtrl();
	return tbc.IsButtonChecked(ID_BUTTON_PRECISE);
}

void CMainFrame::OnButtonChkRes()
{
	// TODO: Add your command handler code here

}

void CMainFrame::OnButtonChkWait()
{
	// TODO: Add your command handler code here
	CToolBarCtrl &	tbc	= m_wndToolBar.GetToolBarCtrl();
	if (tbc.IsButtonChecked(ID_BUTTON_CHKWAIT)) {
		tbc.EnableButton(ID_SPEED_FAST, FALSE);
		tbc.EnableButton(ID_SPEED_SLOW, FALSE);
	} else {
		tbc.EnableButton(ID_SPEED_FAST);
		tbc.EnableButton(ID_SPEED_SLOW);
	}
}

void CMainFrame::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CChildView *pView;
	pView	= (CChildView *)this->GetActiveView();
	pView->MouseDownChecker	= TRUE;

	CFrameWnd::OnLButtonDblClk(nFlags, point);
}

void CMainFrame::OnUpdateSpeedFast(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CToolBarCtrl &	tbc = m_wndToolBar.GetToolBarCtrl();
	pCmdUI->Enable(!tbc.IsButtonChecked(ID_BUTTON_CHKWAIT));
}

void CMainFrame::OnUpdateSpeedSlow(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CToolBarCtrl &	tbc = m_wndToolBar.GetToolBarCtrl();
	pCmdUI->Enable(!tbc.IsButtonChecked(ID_BUTTON_CHKWAIT));
}

void CMainFrame::OnButtonPixelOrLine()
{
	// TODO: Add your command handler code here

}

void CMainFrame::OnButtonPrecise()
{
	// TODO: Add your command handler code here

}
