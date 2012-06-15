// olepasteView.cpp : implementation of the COlepasteView class
//

#include "stdafx.h"
#include "olepaste.h"

#include "olepasteDoc.h"
#include "olepasteView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COlepasteView

IMPLEMENT_DYNCREATE(COlepasteView, CView)

BEGIN_MESSAGE_MAP(COlepasteView, CView)
	//{{AFX_MSG_MAP(COlepasteView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COlepasteView construction/destruction

COlepasteView::COlepasteView()
{
	// TODO: add construction code here

}

COlepasteView::~COlepasteView()
{
}

BOOL COlepasteView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// COlepasteView drawing

void COlepasteView::OnDraw(CDC* pDC)
{
	COlepasteDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// COlepasteView printing

BOOL COlepasteView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COlepasteView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COlepasteView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// COlepasteView diagnostics

#ifdef _DEBUG
void COlepasteView::AssertValid() const
{
	CView::AssertValid();
}

void COlepasteView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COlepasteDoc* COlepasteView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COlepasteDoc)));
	return (COlepasteDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COlepasteView message handlers
