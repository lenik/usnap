// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "TextPainter.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_FONT_BAR, OnViewFontBar)
	ON_COMMAND(ID_VIEW_DRAW, OnViewDraw)
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
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndCommandToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndCommandToolBar.LoadToolBar(IDR_COMMANDS))
	{
		TRACE0("Failed to create command toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndCommandToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	DockControlBar(&m_wndCommandToolBar);

	m_wndCommandToolBar.SetButtonStyle(0, TBBS_CHECKGROUP);
	m_wndCommandToolBar.SetButtonStyle(1, TBBS_CHECKGROUP);
	m_wndCommandToolBar.SetButtonStyle(2, TBBS_CHECKGROUP);
	m_wndCommandToolBar.SetButtonStyle(3, TBBS_CHECKGROUP);

	if (!m_wndFont.Create(IDD_FONT, this)) {
		TRACE0("Failed to create font tool bar\n");
		return -1;
	}

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnViewFontBar()
{
	int state = GetMenu()->GetMenuState(ID_VIEW_FONT_BAR, MF_CHECKED);
	state = state & MF_CHECKED ? MF_UNCHECKED : MF_CHECKED;
	GetMenu()->CheckMenuItem(ID_VIEW_FONT_BAR, state);
	m_wndFont.ShowWindow(state == MF_CHECKED ? SW_SHOW : SW_HIDE);
}

void CMainFrame::OnViewDraw()
{
	int state = GetMenu()->GetMenuState(ID_VIEW_DRAW, MF_CHECKED);
	state = state & MF_CHECKED ? MF_UNCHECKED : MF_CHECKED;
	GetMenu()->CheckMenuItem(ID_VIEW_DRAW, state);
	ShowControlBar(&m_wndCommandToolBar, state, FALSE);
}
