// mfc02View.cpp : implementation of the CMfc02View class
//

#include "stdafx.h"
#include "mfc02.h"

#include "mfc02Doc.h"
#include "mfc02View.h"
#include "mfc02Button01.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMfc02View

IMPLEMENT_DYNCREATE(CMfc02View, CView)

BEGIN_MESSAGE_MAP(CMfc02View, CView)
	//{{AFX_MSG_MAP(CMfc02View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMfc02View construction/destruction

CMfc02View::CMfc02View()
{
	// TODO: add construction code here

}

CMfc02View::~CMfc02View()
{
}

BOOL CMfc02View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	RECT r;
	r.left = r.top = 30;
	r.right = r.bottom = 180;
	r.right *= 3;

	CMfc02Button01 m1;
	m1.Create("AAA", WS_VISIBLE | BS_PUSHBUTTON, r, this, 234789);
	m1.ShowWindow(0);


	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMfc02View drawing

void CMfc02View::OnDraw(CDC* pDC)
{
	CMfc02Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMfc02View printing

BOOL CMfc02View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMfc02View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMfc02View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMfc02View diagnostics

#ifdef _DEBUG
void CMfc02View::AssertValid() const
{
	CView::AssertValid();
}

void CMfc02View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMfc02Doc* CMfc02View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMfc02Doc)));
	return (CMfc02Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMfc02View message handlers
