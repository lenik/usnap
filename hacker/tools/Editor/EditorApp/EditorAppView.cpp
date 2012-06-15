// EditorAppView.cpp : implementation of the CEditorAppView class
//

#include "stdafx.h"
#include "EditorApp.h"

#include "EditorAppDoc.h"
#include "EditorAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditorAppView

IMPLEMENT_DYNCREATE(CEditorAppView, CView)

BEGIN_MESSAGE_MAP(CEditorAppView, CView)
	//{{AFX_MSG_MAP(CEditorAppView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditorAppView construction/destruction

CEditorAppView::CEditorAppView()
{
	// TODO: add construction code here

}

CEditorAppView::~CEditorAppView()
{
}

BOOL CEditorAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEditorAppView drawing

void CEditorAppView::OnDraw(CDC* pDC)
{
	CEditorAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEditorAppView printing

BOOL CEditorAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEditorAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEditorAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEditorAppView diagnostics

#ifdef _DEBUG
void CEditorAppView::AssertValid() const
{
	CView::AssertValid();
}

void CEditorAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEditorAppDoc* CEditorAppView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEditorAppDoc)));
	return (CEditorAppDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEditorAppView message handlers
