// floatstickkerView.cpp : implementation of the CFloatstickkerView class
//

#include "stdafx.h"
#include "floatstickker.h"

#include "floatstickkerDoc.h"
#include "floatstickkerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFloatstickkerView

IMPLEMENT_DYNCREATE(CFloatstickkerView, CView)

BEGIN_MESSAGE_MAP(CFloatstickkerView, CView)
	//{{AFX_MSG_MAP(CFloatstickkerView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFloatstickkerView construction/destruction

CFloatstickkerView::CFloatstickkerView()
{
	// TODO: add construction code here

}

CFloatstickkerView::~CFloatstickkerView()
{
}

BOOL CFloatstickkerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFloatstickkerView drawing

void CFloatstickkerView::OnDraw(CDC* pDC)
{
	CFloatstickkerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	CFloatstickkerDoc::CPointList& pts = pDoc->stickked;
	POSITION p;
	for (p = pts.GetHeadPosition(); p != NULL; pts.GetNext(p)) {
		CFloatstickkerDoc::PT pt = pts.GetAt(p);

		int x0 = LogicToClientX(pt.x - pDoc->p_radius);
		int y0 = LogicToClientY(pt.y - pDoc->p_radius);
		int x1 = LogicToClientX(pt.x + pDoc->p_radius);
		int y1 = LogicToClientY(pt.y + pDoc->p_radius);

		pDC->Ellipse(x0, y0, x1, y1);
	}
}

int CFloatstickkerView::LogicToClientX(double x) {
	CRect rect;
	this->GetClientRect(&rect);
	int HalfClient = rect.Width() / 2;
	return (int)(x * HalfClient + HalfClient);
}
int CFloatstickkerView::LogicToClientY(double y) {
	CRect rect;
	this->GetClientRect(&rect);
	int HalfClient = rect.Height() / 2;
	return (int)(y * HalfClient + HalfClient);
}

/////////////////////////////////////////////////////////////////////////////
// CFloatstickkerView printing

BOOL CFloatstickkerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFloatstickkerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFloatstickkerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFloatstickkerView diagnostics

#ifdef _DEBUG
void CFloatstickkerView::AssertValid() const
{
	CView::AssertValid();
}

void CFloatstickkerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFloatstickkerDoc* CFloatstickkerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFloatstickkerDoc)));
	return (CFloatstickkerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFloatstickkerView message handlers
