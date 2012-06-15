// dr_guiView.cpp : implementation of the CDr_guiView class
//

#include "stdafx.h"
#include "dr_gui.h"

#include "dr_guiDoc.h"
#include "dr_guiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDr_guiView

IMPLEMENT_DYNCREATE(CDr_guiView, CView)

BEGIN_MESSAGE_MAP(CDr_guiView, CView)
	//{{AFX_MSG_MAP(CDr_guiView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDr_guiView construction/destruction

CDr_guiView::CDr_guiView()
{
	// TODO: add construction code here

}

CDr_guiView::~CDr_guiView()
{
}

BOOL CDr_guiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDr_guiView drawing

void CDr_guiView::OnDraw(CDC* pDC)
{
	CDr_guiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDr_guiView printing

BOOL CDr_guiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDr_guiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDr_guiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDr_guiView diagnostics

#ifdef _DEBUG
void CDr_guiView::AssertValid() const
{
	CView::AssertValid();
}

void CDr_guiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr_guiDoc* CDr_guiView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr_guiDoc)));
	return (CDr_guiDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDr_guiView message handlers
