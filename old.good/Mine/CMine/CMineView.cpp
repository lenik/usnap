// CMineView.cpp : implementation of the CCMineView class
//

#include "stdafx.h"
#include "CMine.h"

#include "CMineDoc.h"
#include "CMineView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMineView

IMPLEMENT_DYNCREATE(CCMineView, CView)

BEGIN_MESSAGE_MAP(CCMineView, CView)
	//{{AFX_MSG_MAP(CCMineView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMineView construction/destruction

CCMineView::CCMineView()
{
	// TODO: add construction code here

}

CCMineView::~CCMineView()
{
}

BOOL CCMineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCMineView drawing

void CCMineView::OnDraw(CDC* pDC)
{
	CCMineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CCMineView printing

BOOL CCMineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCMineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCMineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCMineView diagnostics

#ifdef _DEBUG
void CCMineView::AssertValid() const
{
	CView::AssertValid();
}

void CCMineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCMineDoc* CCMineView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCMineDoc)));
	return (CCMineDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCMineView message handlers
