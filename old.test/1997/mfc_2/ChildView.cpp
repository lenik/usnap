// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "mfc02.h"
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
	m_nMouseFlags = 0;
	m_pntPrevMouseLoc = m_pntMouseLoc = CPoint(0, 0);
	m_bButtonDown = FALSE;
	m_MousePositions.SetSize(0, 100);
	m_MouseButtons.SetSize(0, 100);
	m_nPrevIndex = 0;
}

CChildView::~CChildView()
{
	ClearList();
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_ERASEBKGND()
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

	// TODO: Add your message handler code here
	UINT i;
	UINT nPositions = m_MousePositions.GetSize();
	if (nPositions <= m_nPrevIndex) {
		return;
	}
	TRACE(
		"Total = %3d, Already done = %3d, Delta = %3d\n",
		nPositions,
		(m_nPrevIndex + 1),
		nPositions - (m_nPrevIndex + 1));

	CPoint *pPoint;
	pPoint = (CPoint *)m_MousePositions[m_nPrevIndex];
	dc.MoveTo(*pPoint);

	for (i = m_nPrevIndex; i < nPositions; i++) {
		pPoint = (CPoint *)m_MousePositions[i];
		if (m_MouseButtons[i]) {
			dc.MoveTo(*pPoint);
			dc.SetPixelV(*pPoint, RGB(0, 0, 0));
		} else {
			dc.LineTo(*pPoint);
		}
	}
	m_nPrevIndex = nPositions - 1;
/*
	int i, j;
	int nPositions = m_MousePositions.GetSize();
	CPoint *pPointFrom, *pPointTo;
	for (i = 0; i < nPositions; i++) {
		pPointFrom = (CPoint *)m_MousePositions[i];
		dc.SetPixelV(*pPointFrom, RGB(0, 0, 0));
		for (j = i + 1; j < nPositions; j++) {
			pPointTo = (CPoint *)m_MousePositions[j];
			dc.MoveTo(*pPointFrom);
			dc.LineTo(*pPointTo);
		}
	}
*/
/*
	char szBuffer[80];
	wsprintf(szBuffer, "Mouse loc = (%3d, %3d)", m_pntMouseLoc.x, m_pntMouseLoc.y);
	dc.TextOut(0, 0, szBuffer);
	COLORREF nColor = RGB(0, 0, 0);
	if (m_nMouseFlags & MK_RBUTTON) {
		nColor = RGB(0xFF, 0, 0);
	}
	if (m_nMouseFlags & (MK_RBUTTON | MK_LBUTTON)) {
		dc.SetPixelV(m_pntMouseLoc, nColor);
		if (!m_bButtonDown) {
			CPen penStroke(PS_SOLID , 1, nColor);
			CPen *ppenPrevious = dc.SelectObject(&penStroke);
			dc.MoveTo(m_pntPrevMouseLoc);
			dc.LineTo(m_pntMouseLoc);
			dc.SetPixelV(m_pntMouseLoc, nColor);
			dc.SelectObject(ppenPrevious);
			m_pntPrevMouseLoc = m_pntMouseLoc;
		}
	}
*/
	// Do not call CWnd::OnPaint() for painting messages
}

void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
/*
	m_pntMouseLoc = point;
	m_nMouseFlags = nFlags;
	m_bButtonDown = FALSE;
*/
	if (nFlags & MK_LBUTTON) {
		AddList(point, FALSE);
		Invalidate(FALSE);
	}
/*
	CWnd ::OnMouseMove(nFlags, point);
	Invalidate(FALSE);
*/
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
/*
	m_pntPrevMouseLoc = m_pntMouseLoc = point;
	m_nMouseFlags = nFlags;
	m_bButtonDown = TRUE;
*/
/*
	CPoint *pNewPoint = new CPoint(point);
	m_MousePositions.Add((void *)pNewPoint);
	Invalidate();
*/
	AddList(point, TRUE);
	Invalidate(FALSE);
/*
	CWnd ::OnLButtonDown(nFlags, point);

	Invalidate(FALSE);
*/
}

void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
/*
	m_pntPrevMouseLoc = m_pntMouseLoc = point;
	m_nMouseFlags = nFlags;
	m_bButtonDown = TRUE;
*/
	ClearList();
	Invalidate();
/*
	CWnd ::OnRButtonDown(nFlags, point);

	Invalidate(FALSE);
*/
}

void CChildView::ClearList() {
/*
	int i;
	CPoint *pPoint;
	for (i = 0; i < m_MousePositions.GetSize(); i++) {
		pPoint = (CPoint *)m_MousePositions[i];
		delete pPoint;
	}
	m_MousePositions.RemoveAll();
*/
	int i;
	CPoint *pPoint;
	int nSize = m_MousePositions.GetSize();
	m_nPrevIndex = 0;
	for (i = 0; i < nSize; i++) {
		pPoint = (CPoint *)m_MousePositions[i];
		delete pPoint;
	}
	m_MousePositions.RemoveAll();
	m_MouseButtons.RemoveAll();
}

void CChildView::AddList(CPoint& point, UINT nButton) {
	CPoint *pNewPoint = new CPoint(point);
	m_MousePositions.Add((void *)pNewPoint);
	m_MouseButtons.Add(nButton);
}

BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	m_nPrevIndex = 0;
	return CWnd ::OnEraseBkgnd(pDC);
}
