// DrawerView.cpp : implementation of the CDrawerView class
//

#include "stdafx.h"
#include "Drawer.h"

#include "DrawerDoc.h"
#include "DrawerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawerView

IMPLEMENT_DYNCREATE(CDrawerView, CView)

BEGIN_MESSAGE_MAP(CDrawerView, CView)
	//{{AFX_MSG_MAP(CDrawerView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawerView construction/destruction

CDrawerView::CDrawerView()
{
	// TODO: add construction code here

}

CDrawerView::~CDrawerView()
{
}

BOOL CDrawerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawerView drawing

void CDrawerView::OnDraw(CDC* pDC)
{
	CDrawerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDrawerView printing

BOOL CDrawerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawerView diagnostics

#ifdef _DEBUG
void CDrawerView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawerDoc* CDrawerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawerDoc)));
	return (CDrawerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawerView message handlers
