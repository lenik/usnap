// __TB_DataView.cpp : implementation of the C__TB_DataView class
//

#include "stdafx.h"
#include "__TB_Data.h"

#include "__TB_DataDoc.h"
#include "__TB_DataView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// C__TB_DataView

IMPLEMENT_DYNCREATE(C__TB_DataView, CView)

BEGIN_MESSAGE_MAP(C__TB_DataView, CView)
	//{{AFX_MSG_MAP(C__TB_DataView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// C__TB_DataView construction/destruction

C__TB_DataView::C__TB_DataView()
{
	// TODO: add construction code here

}

C__TB_DataView::~C__TB_DataView()
{
}

BOOL C__TB_DataView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// C__TB_DataView drawing

void C__TB_DataView::OnDraw(CDC* pDC)
{
	C__TB_DataDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// C__TB_DataView printing

BOOL C__TB_DataView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void C__TB_DataView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void C__TB_DataView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// C__TB_DataView diagnostics

#ifdef _DEBUG
void C__TB_DataView::AssertValid() const
{
	CView::AssertValid();
}

void C__TB_DataView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C__TB_DataDoc* C__TB_DataView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C__TB_DataDoc)));
	return (C__TB_DataDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// C__TB_DataView message handlers
