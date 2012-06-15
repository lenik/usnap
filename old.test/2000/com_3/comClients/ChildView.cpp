// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "comClients.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView

CChildView::CChildView()
{
	HRESULT hr;

	hr = this->m_pAux.CreateInstance(_T("CampoEngine.CeE3DAux"), NULL);
	if (FAILED(hr)) {
		MessageBox(_T("failed create instance. "));
	}
}

CChildView::~CChildView()
{
	this->m_pAux = NULL;
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
	LONG hDC = (LONG)dc.m_hDC;

	// TODO: Add your message handler code here
	if ((bool)m_pAux) {
		m_pAux->InitDC(hDC);

		m_pAux->DrawBegin(hDC);
			m_pAux->ClearAll();
			m_pAux->DrawWireTeapot(0.7);
		m_pAux->DrawEnd(hDC);
	}

	// Do not call CWnd::OnPaint() for painting messages
}
