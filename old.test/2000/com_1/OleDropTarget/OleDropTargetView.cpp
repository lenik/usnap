// OleDropTargetView.cpp : implementation of the COleDropTargetView class
//

#include "stdafx.h"
#include "OleDropTarget.h"

#include "OleDropTargetDoc.h"
#include "OleDropTargetView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COleDropTargetView

IMPLEMENT_DYNCREATE(COleDropTargetView, CView)

BEGIN_MESSAGE_MAP(COleDropTargetView, CView)
	//{{AFX_MSG_MAP(COleDropTargetView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COleDropTargetView construction/destruction

COleDropTargetView::COleDropTargetView()
{
	// TODO: add construction code here

}

COleDropTargetView::~COleDropTargetView()
{
}

BOOL COleDropTargetView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// COleDropTargetView drawing

void COleDropTargetView::OnDraw(CDC* pDC)
{
	COleDropTargetDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// COleDropTargetView printing

BOOL COleDropTargetView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COleDropTargetView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COleDropTargetView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// COleDropTargetView diagnostics

#ifdef _DEBUG
void COleDropTargetView::AssertValid() const
{
	CView::AssertValid();
}

void COleDropTargetView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COleDropTargetDoc* COleDropTargetView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COleDropTargetDoc)));
	return (COleDropTargetDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COleDropTargetView message handlers
