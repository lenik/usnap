// TextEditorView.cpp : implementation of the CTextEditorView class
//

#include "stdafx.h"
#include "TextEditor.h"

#include "TextEditorDoc.h"
#include "TextEditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextEditorView

IMPLEMENT_DYNCREATE(CTextEditorView, CView)

BEGIN_MESSAGE_MAP(CTextEditorView, CView)
	//{{AFX_MSG_MAP(CTextEditorView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_VSCROLL()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextEditorView construction/destruction

CTextEditorView::CTextEditorView()
{
	// TODO: add construction code here
	m_nLineNo = m_nCharOffset = 0;
	m_nCharWidth = m_nCharHeight = 0;
	m_nViewOffset = 0;
}

CTextEditorView::~CTextEditorView()
{
}

BOOL CTextEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTextEditorView drawing

void CTextEditorView::OnDraw(CDC* pDC)
{
	CTextEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rectInvalid;
	pDC->GetClipBox(&rectInvalid);

	// Now convert the display region into line
	// numbers with in the document (include any partial lines)
	int nMinLine = DPtoLine(rectInvalid.top);
	int nMaxLine = DPtoLine(rectInvalid.bottom + m_nCharHeight - 1);
	// Make sure that nMax doesn't exceed the number of lines in th e document
	nMaxLine = min(nMaxLine, pDoc->GetLength());

	int nLine;
	for (nLine = nMinLine; nLine < nMaxLine; nLine++) {
		TRACE("Updatnig line %d\n", nLine);
		Output(pDC, pDoc->String(nLine), nLine);
	}
	TRACE("Finished OnDraw()\n");
}

/////////////////////////////////////////////////////////////////////////////
// CTextEditorView printing

BOOL CTextEditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTextEditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTextEditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTextEditorView diagnostics

#ifdef _DEBUG
void CTextEditorView::AssertValid() const
{
	CView::AssertValid();
}

void CTextEditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTextEditorDoc* CTextEditorView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextEditorDoc)));
	return (CTextEditorDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTextEditorView message handlers

void CTextEditorView::OnInitialUpdate()
{
	// TODO: Add your specialized code here and/or call the base class
	// Get the font-size information for Output()
	// and save it in the class
	CClientDC cDC(this);
	TEXTMETRIC tmDescrip;
	cDC.GetTextMetrics(&tmDescrip);
	m_nCharHeight = tmDescrip.tmHeight + tmDescrip.tmExternalLeading;
	m_nCharWidth = tmDescrip.tmAveCharWidth;

	CView::OnInitialUpdate();
}

// process the keystroke messages
void CTextEditorView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CTextEditorDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CView::OnChar(nChar, nRepCnt, nFlags);
	pDoc->AddChar(m_nLineNo, m_nCharOffset, nChar);
	UpdateCaret();
}

void CTextEditorView::Output(CDC *pDC, CString sText, int nLine) {
	int nYOffset = LinetoDP(nLine);
	pDC->SetTextColor(RGB(0x00, 0x00, 0x00));
	pDC->TextOut(0, nYOffset, sText);

}

// Convert from/to offset measured
int CTextEditorView::DPtoLine(int nDP) {
	nDP += m_nViewOffset;
	return nDP / m_nCharHeight;
}

int CTextEditorView::LinetoDP(int nLine) {
	int nDP = nLine * m_nCharHeight;
	return nDP - m_nViewOffset;
}

void CTextEditorView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	// Char is intereesting -- first get the string
	CTextEditorDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Find where this is: Line number is easy
	m_nLineNo = max(pDoc->GetLength() - 1, 0);
	m_nLineNo = min(m_nLineNo, DPtoLine(point.y));

	CString sText = pDoc->String(m_nLineNo);
	// Use the string to recursively zero in on
	// the caret position
	CClientDC cDC(this);
	int nCOff;
	int nFudgeFactor = m_nCharWidth / 2;
	int nLength = sText.GetLength();
	CSize szTrial;
	for (nCOff = 0; nCOff < nLength; nCOff++) {
		szTrial = cDC.GetTextExtent(sText, nCOff);
		if (point.x <= (szTrial.cx + nFudgeFactor)) { break; }
	}
	m_nCharOffset = nCOff;
	// Now update caret with new location
	UpdateCaret();

	CView::OnLButtonDown(nFlags, point);
}

// OnUpdate -- repaint just the parts of the window that need to be repainte, The LPARAM hint is th e line numer that needs to be repainted, if negative, then repaint from here down
void CTextEditorView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: Add your specialized code here and/or call the base class

	// Firt update the scroll bars based on the number
	// of lines in the document
	UpdateScrollBar();

	// Figure out how much to repaint
	// Construct the invali rectange starting with
	// the entire client window
	CRect rectInvalid;
	GetClientRect(&rectInvalid);
	// Now recalculate the top and bottom based on line number in the hint. If the line number is negative...
	int nLine = (int)lHint;
	if (nLine < 0) {
		nLine = ~nLine;
		rectInvalid.top = LinetoDP(nLine);
	} else {
		// If positive, just this line
		rectInvalid.top = LinetoDP(nLine);
		rectInvalid.bottom = rectInvalid.top + m_nCharHeight;
	}
	InvalidateRect(rectInvalid);
}

void CTextEditorView::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);

	// TODO: Add your message handler code here
	CreateSolidCaret(2 * GetSystemMetrics(SM_CXBORDER), m_nCharHeight);
	UpdateCaret();
	ShowCaret();
}

void CTextEditorView::OnKillFocus(CWnd* pNewWnd)
{
	// TODO: Add your message handler code here
	HideCaret();
	DestroyCaret();

	CView::OnKillFocus(pNewWnd);
}

// UpdateCaret() -- update the caret location based on
//					the line number and char offset.
//					Make sure that the caret is
//					between characters.
void CTextEditorView::UpdateCaret() {
	CTextEditorDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Keep character offset within range of a line
	// 0 <= m_nCharOffset <= sOutString.GetLength()
	CString sOutString = pDoc->String(m_nLineNo);
	m_nCharOffset = min(m_nCharOffset, sOutString.GetLength());
	m_nCharOffset = max(m_nCharOffset, 0);

	CPoint ptCaret;
	CClientDC cDC(this);
	CSize sString = cDC.GetTextExtent(sOutString, m_nCharOffset);
	ptCaret.x = sString.cx;
	ptCaret.y = LinetoDP(m_nLineNo);

	// Reposition caret
	SetCaretPos(ptCaret);
}

void CTextEditorView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default

	// Set new offset
	switch (nSBCode) {
	case SB_LINEDOWN:
		m_nViewOffset++; break;
	case SB_LINEUP:
		m_nViewOffset--; break;
	case SB_THUMBTRACK:
		m_nViewOffset = nPos; break;
	default:
		return;
	}
	// Make sure that this isn't out of range
	int nMin, nMax;
	GetScrollRange(SB_VERT, &nMin, &nMax);
	m_nViewOffset = max(m_nViewOffset, nMin);
	m_nViewOffset = min(m_nViewOffset, nMax);
	// Now update the scroll bar position
	SetScrollPos(SB_VERT, m_nViewOffset);
	// Keep caret in the same place in document
	UpdateCaret();
	Invalidate();

	CView::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CTextEditorView::OnSize(UINT nType, int cx, int cy)
{
	// TODO: Add your message handler code here
	if (m_nCharHeight) {
		UpdateScrollBar();
	}

	CView::OnSize(nType, cx, cy);
}

int CTextEditorView::GetWindowHeight() {
	// Divide the height of the window by
	// the height of a character
	CRect rectView;
	GetClientRect(&rectView);
	// Note that rectView.top is always 0.
	return rectView.bottom;
}

int CTextEditorView::GetDocHeight() {
	CTextEditorDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	return pDoc->GetLength() * m_nCharHeight;
}

void CTextEditorView::UpdateScrollBar() {
	// If all the lines are visible...
	int nVisible = GetWindowHeight();
	int nMax = GetDocHeight();
	if (nVisible >= nMax) {
		// ... hide the scroll bar
		SetScrollRange(SB_VERT, 0, 0);
		// if you're going th hide the scroll bar,
		// you have to make sure that everything's
		// visible
		m_nViewOffset = 0;
		UpdateCaret();
	} else {
		// Not all lines visible -- set scroll range
		SetScrollRange(SB_VERT, 0, nMax - nVisible, FALSE);
		if (m_nViewOffset > (nMax - nVisible)) {
			m_nViewOffset = nMax - nVisible;
			UpdateCaret();
		}
		SetScrollPos(SB_VERT, m_nViewOffset);
	}
}

void CTextEditorView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CTextEditorDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// Get the height of the window in both
	// device units and lines
	int nWindowHeight = GetWindowHeight();
	int nWindowLH = nWindowHeight / m_nCharHeight;
	// Handle the arrow keys -- everything else
	// just pass through
	switch (nChar) {
	case VK_RIGHT:
		m_nCharOffset++;
		break;
	case VK_LEFT:
		m_nCharOffset--;
		break;
	case VK_UP:
		m_nLineNo--;
		break;
	case VK_DOWN:
		m_nLineNo++;
		break;
	case VK_PRIOR:
		m_nLineNo -= (nWindowLH / 2);
		break;
	case VK_NEXT:
		m_nLineNo += (nWindowLH / 2);
		break;
	default:
		if (nChar == VK_DELETE) {
			OnChar('\x7', nRepCnt, nFlags);
		}
		CView::OnKeyDown(nChar, nRepCnt, nFlags);
		return;
	}
	// Make sure that the line number is still reasonable
	m_nLineNo = min(m_nLineNo, pDoc->GetLength() - 1);
	m_nLineNo = max(m_nLineNo, 0);
	// Now make sure that the caret stays visible
	// Is it off the top of the window ?
	int nCaretOffset = LinetoDP(m_nLineNo);
	if (nCaretOffset < 0) {
		// Yes -- move the window up
		m_nViewOffset += nCaretOffset;
		UpdateScrollBar();
		Invalidate();
	}
	// How about off the bottom ?
	int nWindowBottom = nWindowHeight - m_nCharHeight;
	if (nCaretOffset > nWindowBottom) {
		// Yes -- move the window down
		m_nViewOffset += (nCaretOffset - nWindowBottom);
		UpdateScrollBar();
		Invalidate();
	}
	UpdateCaret();
}
