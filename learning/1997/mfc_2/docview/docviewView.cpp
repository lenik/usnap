// docviewView.cpp : implementation of the CDocviewView class
//

#include "stdafx.h"
#include "docview.h"

#include "docviewDoc.h"
#include "docviewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDocviewView

IMPLEMENT_DYNCREATE(CDocviewView, CView)

BEGIN_MESSAGE_MAP(CDocviewView, CView)
	//{{AFX_MSG_MAP(CDocviewView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDocviewView construction/destruction

CDocviewView::CDocviewView()
{
	// TODO: add construction code here

}

CDocviewView::~CDocviewView()
{
}

BOOL CDocviewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDocviewView drawing

void CDocviewView::OnDraw(CDC* pDC)
{
	CDocviewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDocviewView printing

BOOL CDocviewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDocviewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDocviewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDocviewView diagnostics

#ifdef _DEBUG
void CDocviewView::AssertValid() const
{
	CView::AssertValid();
}

void CDocviewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDocviewDoc* CDocviewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDocviewDoc)));
	return (CDocviewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDocviewView message handlers
