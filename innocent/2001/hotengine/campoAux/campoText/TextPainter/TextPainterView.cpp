// TextPainterView.cpp : implementation of the CTextPainterView class
//

#include "stdafx.h"
#include "TextPainter.h"

#include "TextPainterDoc.h"
#include "TextPainterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextPainterView

IMPLEMENT_DYNCREATE(CTextPainterView, CView)

BEGIN_MESSAGE_MAP(CTextPainterView, CView)
	//{{AFX_MSG_MAP(CTextPainterView)
	ON_WM_CREATE()
	ON_COMMAND(ID_COMMAND_TEXT, OnCommandText)
	ON_COMMAND(ID_COMMAND_SCALE, OnCommandScale)
	ON_COMMAND(ID_COMMAND_ROTATE, OnCommandRotate)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_COMMAND_SELECT, OnCommandSelect)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextPainterView construction/destruction

CTextPainterView::CTextPainterView()
{
	statusCommand	= noop;
	statusDown		= none;
	statusBorder	= left;
	statusCorner	= topleft;

	selectedElement	= NULL;

	sizeBorder.cx	= 5;
	sizeBorder.cy	= 5;
	bRectOn			= FALSE;
}

CTextPainterView::~CTextPainterView()
{
}

BOOL CTextPainterView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

void CTextPainterView::DrawDragBox(LPRECT r) {
	CDC *pDC = GetDC();
	CRect *last = bRectOn ? &rectDragBoxLast : NULL;

	if (r != NULL) {
		rectDragBox.CopyRect(r);
		pDC->DrawDragRect(&rectDragBox, sizeBorder, last, sizeBorder);
		rectDragBoxLast.CopyRect(rectDragBox);

		bRectOn = TRUE;
	} else if (last != NULL) {
		pDC->DrawDragRect(last, sizeBorder, NULL, sizeBorder);

		bRectOn = FALSE;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTextPainterView drawing

void CTextPainterView::OnDraw(CDC* pDC)
{
	CTextPainterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	pDoc->text.draw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CTextPainterView printing

BOOL CTextPainterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTextPainterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CTextPainterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

/////////////////////////////////////////////////////////////////////////////
// CTextPainterView diagnostics

#ifdef _DEBUG
void CTextPainterView::AssertValid() const
{
	CView::AssertValid();
}

void CTextPainterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTextPainterDoc* CTextPainterView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextPainterDoc)));
	return (CTextPainterDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTextPainterView message handlers

int CTextPainterView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here
	return 0;
}

void CTextPainterView::OnCommandSelect()
{
	// TODO: Add your command handler code here
	statusCommand	= noop;
}

void CTextPainterView::OnCommandText()
{
	// TODO: Add your command handler code here
	statusCommand	= createtext;
}

void CTextPainterView::OnCommandScale()
{
	// TODO: Add your command handler code here
	statusCommand	= scaletext;
}

void CTextPainterView::OnCommandRotate()
{
	// TODO: Add your command handler code here
	statusCommand	= rotatetext;
}

void CTextPainterView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDC *pDC = GetDC();
	CTextPainterDoc *pDoc = GetDocument();
	ctElement *pointElement;
	pointElement = pDoc->text.getPointOn(pDC, point);
	RECT r;

	posDown = point;

	// TODO: Add your message handler code here and/or call default
	switch (statusCommand) {
	case noop:
		if (pointElement == NULL) {		// seem not probably
			// select none
			DrawDragBox(NULL);
			statusDown = dragbox;
		} else {
			pointElement->getExtent(pDC)->GetRgnBox(&r);
			DrawDragBox(&r);
			statusDown = selected;
			selectedElement = pointElement;
		}
		break;
	case createtext:
		// dragbox
		// test if mouse click on a text
		/// then test if on border, on corner, on client
		statusDown = dragbox;

		break;
	case scaletext:
		// test if mouse click on a text
		// break if none
		break;
	case rotatetext:
		// same as scaletext
		break;
	default:
		;
	}
	pDC->ReleaseOutputDC();
	CView::OnLButtonDown(nFlags, point);
}

void CTextPainterView::OnMouseMove(UINT nFlags, CPoint point)
{
	CDC *pDC = GetDC();
	CTextPainterDoc *pDoc = GetDocument();
	ctElement *pointElement = pDoc->text.getPointOn(pDC, point);
	RECT r;

	if (pointElement != NULL) {
		pointElement->getExtent(pDC)->GetRgnBox(&r);
		DrawDragBox(&r);
	} else
		DrawDragBox(NULL);

	switch (statusCommand) {
	case noop:
		switch (statusDown) {
		case selected:
			// move
			if (selectedElement != NULL) {
				selectedElement->position.Offset(point - posDown);
				posDown = point;
				selectedElement->getExtent(pDC)->GetRgnBox(&r);
				DrawDragBox(&r);
			}
			break;
		case dragbox:
			// draging
				r.left	= posDown.x;
				r.top	= posDown.y;
				r.right	= point.x;
				r.bottom= point.y;
				DrawDragBox(&r);
				break;
		case onborder:
			// size
		case oncorner:
			// size
		default: ;
		}
		break;
	case createtext:
		// dragbox
		// test if mouse click on a text
		/// then test if on border, on corner, on client
		//statusDown = dragbox;

		break;
	case scaletext:
		// test if mouse click on a text
		// break if none
		break;
	case rotatetext:
		// same as scaletext
		break;
	default:
		;
	}

	CView::OnMouseMove(nFlags, point);
}

void CTextPainterView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	statusDown = none;
	switch (statusCommand) {
	case noop:
		switch (statusDown) {
		case selected:
			DrawDragBox(NULL);
			Invalidate();
			break;
		case dragbox:
		case onborder:
		case oncorner:
		default: ;
		}
		break;
	case createtext:
		;
	}

	CView::OnLButtonUp(nFlags, point);
}
