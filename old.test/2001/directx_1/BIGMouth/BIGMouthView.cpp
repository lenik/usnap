// BIGMouthView.cpp : implementation of the CBIGMouthView class
//

#include "stdafx.h"
#include "BIGMouth.h"

#include "BIGMouthDoc.h"
#include "BIGMouthView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBIGMouthView

IMPLEMENT_DYNCREATE(CBIGMouthView, CView)

BEGIN_MESSAGE_MAP(CBIGMouthView, CView)
	//{{AFX_MSG_MAP(CBIGMouthView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBIGMouthView construction/destruction

CBIGMouthView::CBIGMouthView()
{
	// TODO: add construction code here

}

CBIGMouthView::~CBIGMouthView()
{
}

BOOL CBIGMouthView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBIGMouthView drawing

void CBIGMouthView::OnDraw(CDC* pDC)
{
	CBIGMouthDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBIGMouthView diagnostics

#ifdef _DEBUG
void CBIGMouthView::AssertValid() const
{
	CView::AssertValid();
}

void CBIGMouthView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBIGMouthDoc* CBIGMouthView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBIGMouthDoc)));
	return (CBIGMouthDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBIGMouthView message handlers
