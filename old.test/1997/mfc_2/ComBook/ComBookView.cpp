// ComBookView.cpp : implementation of the CComBookView class
//

#include "stdafx.h"
#include "ComBook.h"

#include "ComBookDoc.h"
#include "ComBookView.h"

#include "ComBookDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const UINT ENTRIES_PER_PAGE = 4;
const UINT TWIPS_PER_POINT = 20;
const UINT TWIPS_PER_INCH = 72 * TWIPS_PER_POINT;

const UINT ONE_MINUTE_TIMER = 1;
const UINT SECOND = 1000;

/////////////////////////////////////////////////////////////////////////////
// CComBookView

IMPLEMENT_DYNCREATE(CComBookView, CScrollView)

BEGIN_MESSAGE_MAP(CComBookView, CScrollView)
	//{{AFX_MSG_MAP(CComBookView)
	ON_COMMAND(ID_EDIT_DEL, OnEditDel)
	ON_COMMAND(ID_EDIT_MODIFY, OnEditModify)
	ON_UPDATE_COMMAND_UI(ID_EDIT_DEL, OnUpdateEditDel)
	ON_UPDATE_COMMAND_UI(ID_EDIT_MODIFY, OnUpdateEditModify)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComBookView construction/destruction

CComBookView::CComBookView()
{
	// TODO: add construction code here
	m_posCurrent = (POSITION)0;
}

CComBookView::~CComBookView()
{
}

BOOL CComBookView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CComBookView drawing

void CComBookView::OnDraw(CDC* pDC)
{
	CComBookDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here

	/*****************************************************************
	  Be sure and comment out or remove the following lines of code, because
	  they have been replaced by the call to SetFont() above;
		TEXTMETRIC tmDescrip;
		pDC->GetTextMetrics(&tmDescrip);
		m_nCharHeight = tmDescrip.tmHeight + tmDescrip.tmExternalLeading;
		m_nCharWidth = tmDescrip.tmAveCharWidth;
	*****************************************************************/

	int nSkipEntries, nMaxPerPass;

	if (!pDC->IsPrinting()) {
		m_nLeftMargin = m_nPageOffset = 0;

		nMaxPerPass = MAXSHORT;
		nSkipEntries = 0;
	} else {
		nMaxPerPass = ENTRIES_PER_PAGE;
		nSkipEntries = (m_nPageNumber - 1) * nMaxPerPass;
	}

	SetFont(pDC);

	CEntry *pEntry;
	POSITION Index;

	pEntry = pDoc->GetFirst(Index);
	while (nSkipEntries-- && pEntry) {
		pEntry = pDoc->GetNext(Index);
	}

	int nYOffset = 0;
	for (; pEntry; pEntry = pDoc->GetNext(Index)) {
		Output(pDC, pEntry, nYOffset, Index == m_posCurrent);
		nYOffset++;
		if (nYOffset >= nMaxPerPass) { break; }
	}

}

void CComBookView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	// TODO: calculate the total size of this view
	CRect rectViewSize;
	GetClientRect(&rectViewSize);
	CSize sizeTotal;
	sizeTotal.cx = rectViewSize.right;
	sizeTotal.cy = rectViewSize.bottom;
	SetScrollSizes(MM_TEXT, sizeTotal);

	if (!SetTimer(ONE_MINUTE_TIMER, 60 * SECOND, NULL)) {
		AfxMessageBox("Couldn't get timer for this window", MB_OK | MB_ICONEXCLAMATION);
	} else {
//		pTimerView = this;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CComBookView printing

BOOL CComBookView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation

	CComBookDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	int nPages = (pDoc->GetCount() - 1) / ENTRIES_PER_PAGE + 1;
	pInfo->SetMaxPage(nPages);

	return DoPreparePrinting(pInfo);
}

void CComBookView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: add extra initialization before printing
	pDC->SetMapMode(MM_TWIPS);
	m_pHeaderFont = new CFont;
	m_pHeaderFont->CreateFont(
		32 * TWIPS_PER_POINT,
		0, 0, 0,
		FW_NORMAL,
		0,
		1,
		0,
		ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH,
		CString("MS Sans Serif"));

	m_pColumnHeaderFont = new CFont;
	m_pColumnHeaderFont->CreateFont(
		18 * TWIPS_PER_POINT,
		0,
		0,
		0,
		FW_NORMAL,
		0,
		1,
		0,
		ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH,
		CString("MS Sans Serif"));

	m_pTextFont = new CFont;
	m_pTextFont->CreateFont(
		18 * TWIPS_PER_POINT,	/* Height */
		0,	/* Width */
		0,	/* Escapement */
		0,	/* Orientation */
		FW_NORMAL,	/* WEIGHT */
		0,	/* 1 -> italics */
		0,	/* 1 -> Underline */
		0,	/* Strikeout */
		ANSI_CHARSET,	/* Character set */
		OUT_DEFAULT_PRECIS,		/* Precision */
		CLIP_DEFAULT_PRECIS,	/* Clipping prec. */
		DEFAULT_QUALITY,
		DEFAULT_PITCH,
		CString("MS Sans Serif"));
}

void CComBookView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: Add your specialized code here and/or call the base class

	CScrollView::OnPrepareDC(pDC, pInfo);
}

void CComBookView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: Add your specialized code here and/or call the base class
	int nXOffset;
	m_nLeftMargin = 1 * TWIPS_PER_INCH;
	m_nPageOffset = TWIPS_PER_INCH / 2;

	m_nPageNumber = pInfo->m_nCurPage;

	// Change the font for printing
	CFont *pOldFont;
	pOldFont = SetFont(pDC, m_pHeaderFont);
	CString header("Personal Scheduler");
	if (m_nPageNumber > 1) {
		header = CString("Personal Scheduler");
	}
	nXOffset = m_nLeftMargin + 8 * m_nCharWidth;
	m_nPageOffset += m_nCharHeight;
	pDC->TextOut(nXOffset, m_nPageOffset, header);
	m_nPageOffset += m_nCharHeight;
	m_nPageOffset += m_nCharHeight;

	SetFont(pDC, m_pColumnHeaderFont);
	CString time("Time");
	nXOffset = m_nLeftMargin;
	pDC->TextOut(nXOffset, m_nPageOffset, time);

	CString text("Text");
	nXOffset = m_nLeftMargin + 20 * m_nCharWidth;
	pDC->TextOut(nXOffset, m_nPageOffset, text);

	m_nPageOffset += m_nCharHeight;

	SetFont(pDC, m_pTextFont);
	CScrollView::OnPrint(pDC, pInfo);

	// And add the page number at the bottom
	// make sure that it's black;
	pDC->SetTextColor(RGB(0x00, 0x00, 0x00));
	CString page;
	page.Format("Page %d of %d", m_nPageNumber, pInfo->GetMaxPage());
	nXOffset = m_nLeftMargin + 20 * m_nCharWidth;
	m_nPageOffset += (ENTRIES_PER_PAGE + 2) * m_nCharHeight;
	pDC->TextOut(nXOffset, m_nPageOffset, page);

	// Restore the original font
	SetFont(pDC, pOldFont);
}

void CComBookView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: add cleanup after printing
	delete m_pHeaderFont;
	delete m_pColumnHeaderFont;
	delete m_pTextFont;
}

CFont *CComBookView::SetFont(CDC *pDC, CFont *pFont) {
	CFont *pOldFont = NULL;
	pDC->SetMapMode(MM_TWIPS);
	// if there is a font, select it into the DC
	if (pFont) {
		pOldFont = pDC->SelectObject(pFont);
	}

	// Get the font-size information for Output()
	// and save it into the class
	// (The minus sign in the calculation of m_nCharHeight
	// is to account for the fact that y increases in the
	// oposite direction in MM_TWIPS mode. )

	TEXTMETRIC tmDescrip;
	pDC->GetTextMetrics(&tmDescrip);
	m_nCharHeight = -(tmDescrip.tmHeight + tmDescrip.tmExternalLeading);
	m_nCharWidth = tmDescrip.tmAveCharWidth;
	// Return the old font (returns NULL if no font change made)
	return pOldFont;
}

/////////////////////////////////////////////////////////////////////////////
// CComBookView diagnostics

#ifdef _DEBUG
void CComBookView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CComBookView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CComBookDoc* CComBookView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CComBookDoc)));
	return (CComBookDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CComBookView message handlers

void CComBookView::OnEditDel()
{
	// TODO: Add your command handler code here
	CComBookDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (m_posCurrent == (POSITION)0) { return; }
	POSITION oldPosition = m_posCurrent;
	pDoc->GetNext(m_posCurrent);
	pDoc->Delete(oldPosition);
}

void CComBookView::OnEditModify()
{
	// TODO: Add your command handler code here
	CComBookDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (m_posCurrent == (POSITION)0) { return; }
	pDoc->Modify(m_posCurrent);
}

void CComBookView::OnUpdateEditDel(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CComBookDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->GetCount()) { pCmdUI->Enable(TRUE); }
	else { pCmdUI->Enable(FALSE); }
}

void CComBookView::OnUpdateEditModify(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	OnUpdateEditDel(pCmdUI);
}

void CComBookView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CComBookDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	point += CSize(GetDeviceScrollPosition());

	CClientDC dc(this);
	dc.SetMapMode(MM_TWIPS);
	dc.DPtoLP(&point);

	int nSelectedLine = point.y / m_nCharHeight;
	CEntry *pEntry;
	int nYOffset = 0;
	m_posCurrent = (POSITION)0;
	POSITION Index;
	for (pEntry = pDoc->GetFirst(Index); pEntry; pEntry = pDoc->GetNext(Index)) {
		if (nYOffset == nSelectedLine) {
			m_posCurrent = Index;
			break;
		}
		nYOffset++;
	}
	Invalidate(FALSE);
	CScrollView::OnLButtonDown(nFlags, point);
}

void CComBookView::Output(CDC *pDC, CEntry *pEntry, int nOffset, int bSelected) {
	int nXOffset;
	int nYOffset = nOffset * m_nCharHeight + m_nPageOffset;

	CTime tTime = pEntry->GetTime();
	CString strTime = tTime.Format("%c");
	if (pEntry->GetDisabled()) {
		pDC->SetTextColor(RGB(0x80, 0x80, 0x80));
	} else {
		pDC->SetTextColor(RGB(0x00, 0x00, 0x00));
	}
	if (bSelected) {
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}
	nXOffset = m_nLeftMargin;
	pDC->TextOut(nXOffset, nYOffset, strTime);
	nXOffset = m_nLeftMargin + 20 * m_nCharWidth;
	CString sOut = pEntry->GetText();
	pDC->TextOut(nXOffset, nYOffset, sOut);
}

void CComBookView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	OnLButtonDown(nFlags, point);
	OnEditModify();

	CScrollView::OnLButtonDblClk(nFlags, point);
}

void CComBookView::OnTimer(UINT nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CComBookDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Ignore any timers that go off while dialog box popped up
	static int bIgnoreTimer = FALSE;
	if (bIgnoreTimer) { return; }
	// Loop through the list of entries, looking for one to go off
	CTime tNow = CTime::GetCurrentTime();
	CEntry *pEntry;
	POSITION Index;
	for (pEntry = pDoc->GetFirst(Index); pEntry; pEntry = pDoc->GetNext(Index)) {
		if (pEntry->GetDisabled() == FALSE) {
			// ... for one that's ready to go off
			if (pEntry->GetTime() < tNow) {
				bIgnoreTimer = TRUE;
				pEntry->SetDisabled();
				MessageBox(pEntry->GetText(), "Timer went off", MB_OK | MB_ICONEXCLAMATION);
				bIgnoreTimer = FALSE;
			}
		}
	}

	CScrollView::OnTimer(nIDEvent);
}
