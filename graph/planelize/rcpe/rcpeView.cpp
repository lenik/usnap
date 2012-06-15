// rcpeView.cpp : implementation of the CRcpeView class
//

#include "stdafx.h"
#include "rcpeApp.h"

#include "rcpeDoc.h"
#include "rcpeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRcpeView

IMPLEMENT_DYNCREATE(CRcpeView, CView)

BEGIN_MESSAGE_MAP(CRcpeView, CView)
	//{{AFX_MSG_MAP(CRcpeView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRcpeView construction/destruction

CRcpeView::CRcpeView()
{
	// TODO: add construction code here

}

CRcpeView::~CRcpeView()
{
}

BOOL CRcpeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRcpeView drawing

void CRcpeView::OnDraw(CDC* pDC)
{
	CRcpeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CRcpeView diagnostics

#ifdef _DEBUG
void CRcpeView::AssertValid() const
{
	CView::AssertValid();
}

void CRcpeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRcpeDoc* CRcpeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRcpeDoc)));
	return (CRcpeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRcpeView message handlers
