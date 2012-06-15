// DDRGenerateView.cpp : implementation of the CDDRGenerateView class
//

#include "stdafx.h"
#include "DDRGenerate.h"

#include "DDRGenerateDoc.h"
#include "DDRGenerateView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDDRGenerateView

IMPLEMENT_DYNCREATE(CDDRGenerateView, CView)

BEGIN_MESSAGE_MAP(CDDRGenerateView, CView)
	//{{AFX_MSG_MAP(CDDRGenerateView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDDRGenerateView construction/destruction

CDDRGenerateView::CDDRGenerateView()
{
	// TODO: add construction code here

}

CDDRGenerateView::~CDDRGenerateView()
{
}

BOOL CDDRGenerateView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDDRGenerateView drawing

void CDDRGenerateView::OnDraw(CDC* pDC)
{
	CDDRGenerateDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	// the line which flows up the arrows
	const int baseline = 300;

	int beginline = 0;
	int nLines = 0;

	for (int i = 0; i < nLines; i++) {
		// out one line from pDoc->keybuf....
		beginline += height;
	}
	//
}

/////////////////////////////////////////////////////////////////////////////
// CDDRGenerateView printing

BOOL CDDRGenerateView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDDRGenerateView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDDRGenerateView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDDRGenerateView diagnostics

#ifdef _DEBUG
void CDDRGenerateView::AssertValid() const
{
	CView::AssertValid();
}

void CDDRGenerateView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDDRGenerateDoc* CDDRGenerateView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDDRGenerateDoc)));
	return (CDDRGenerateDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDDRGenerateView message handlers
