// syntestView.cpp : implementation of the CSyntestView class
//

#include "stdafx.h"
#include "syntest.h"

#include "syntestDoc.h"
#include "syntestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSyntestView

IMPLEMENT_DYNCREATE(CSyntestView, CView)

BEGIN_MESSAGE_MAP(CSyntestView, CView)
	//{{AFX_MSG_MAP(CSyntestView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSyntestView construction/destruction

CSyntestView::CSyntestView()
{
	// TODO: add construction code here

}

CSyntestView::~CSyntestView()
{
}

BOOL CSyntestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSyntestView drawing

void CSyntestView::OnDraw(CDC* pDC)
{
	CSyntestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSyntestView printing

BOOL CSyntestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSyntestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSyntestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSyntestView diagnostics

#ifdef _DEBUG
void CSyntestView::AssertValid() const
{
	CView::AssertValid();
}

void CSyntestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSyntestDoc* CSyntestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSyntestDoc)));
	return (CSyntestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSyntestView message handlers
