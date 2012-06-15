// dv01View.cpp : implementation of the CDv01View class
//

#include "stdafx.h"
#include "dv01.h"

#include "dv01Doc.h"
#include "dv01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDv01View

IMPLEMENT_DYNCREATE(CDv01View, CScrollView)

BEGIN_MESSAGE_MAP(CDv01View, CScrollView)
	//{{AFX_MSG_MAP(CDv01View)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDv01View construction/destruction

CDv01View::CDv01View()
{
	// TODO: add construction code here
	m_nPrevIndex = 0;
}

CDv01View::~CDv01View()
{
}

BOOL CDv01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDv01View drawing

void CDv01View::OnDraw(CDC* pDC)
{
	CDv01Doc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
	UINT nPositions = pDoc->GetSize();
	if (nPositions <= m_nPrevIndex) {
		return;
	}
	CPoint *pPoint;
	pPoint = pDoc->GetMPosition(m_nPrevIndex);
	pDC->MoveTo(*pPoint);

	UINT i;
	for (i = m_nPrevIndex; i < nPositions; i++) {
		pPoint = pDoc->GetMPosition(i);
		if (pDoc->GetMButton(i)) {
			pDC->MoveTo(*pPoint);
			pDC->SetPixelV(*pPoint, RGB(0, 0, 0));
		} else {
			pDC->LineTo(*pPoint);
		}
	}

	m_nPrevIndex = nPositions - 1;
	// Enable document updates from now on
	pDoc->EnableUpdate();

}

/////////////////////////////////////////////////////////////////////////////
// CDv01View printing

BOOL CDv01View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDv01View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDv01View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDv01View diagnostics

#ifdef _DEBUG
void CDv01View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDv01View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDv01Doc* CDv01View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDv01Doc)));
	return (CDv01Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDv01View message handlers

void CDv01View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CScrollView::OnLButtonDown(nFlags, point);
	CDv01Doc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	point += CSize(GetDeviceScrollPosition());
	pDoc->AddList(point, TRUE);
	Invalidate(FALSE);
}

void CDv01View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CScrollView::OnMouseMove(nFlags, point);

	if (!(nFlags & MK_LBUTTON)) {
		return;
	}
	CDv01Doc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	point += CSize(GetDeviceScrollPosition());
	pDoc->AddList(point, FALSE);

	Invalidate(FALSE);
}

void CDv01View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CScrollView::OnRButtonDown(nFlags, point);

	CDv01Doc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->ClearList();
	m_nPrevIndex = 0;
	Invalidate(TRUE);

}

BOOL CDv01View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	m_nPrevIndex = 0;

	return CScrollView::OnEraseBkgnd(pDC);
}

void CDv01View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	// Set the scroll size based on the size of the initial window
	RECT rectClientArea;
	GetClientRect(&rectClientArea);
	CSize sizeTotal(rectClientArea.right, rectClientArea.bottom);
	SetScrollSizes(MM_TEXT, sizeTotal);
}
