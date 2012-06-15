// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "GetObj02.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

HWND vvv::hWnd = NULL;
long vvv::count = 0;
HHOOK vvv::hhk = NULL;

/////////////////////////////////////////////////////////////////////////////
// CChildView

CChildView::CChildView()
{
	this->m_hWnd;
	if ((vvv::hhk = InstallMouseHook(MyMouseHook)) == NULL) {
		PostQuitMessage(0);
	}
}

CChildView::~CChildView()
{
	UninstallMouseHook(vvv::hhk);
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint()
{
	CPaintDC dc(this); // device context for painting


	// Do not call CWnd::OnPaint() for painting messages
}

LRESULT CALLBACK MyMouseHook(int &code, WPARAM &wParam, LPARAM &lParam) {
	char lpBuf[1024];
	return 0;
	MOUSEHOOKSTRUCT *mhs = (LPMOUSEHOOKSTRUCT)lParam;
	CWPSTRUCT *cs = (LPCWPSTRUCT)lParam;

	wsprintf(lpBuf, "[%x]\r\nHWND = %x\r\nx = %d\r\nY = %d\r\ndwExtraInfo = %x\r\nwHitTestcode = %x",
		vvv::count++,
		cs->hwnd, cs->message, cs->wParam, cs->lParam, vvv::hWnd
		//mhs->hwnd, mhs->pt.x, mhs->pt.y, mhs->dwExtraInfo, mhs->wHitTestCode
	);

	return 0;
}
