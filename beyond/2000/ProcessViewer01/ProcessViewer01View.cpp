// ProcessViewer01View.cpp : implementation of the CProcessViewer01View class
//

#include "stdafx.h"
#include "ProcessViewer01.h"

#include "ProcessViewer01Doc.h"
#include "ProcessViewer01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProcessViewer01View

IMPLEMENT_DYNCREATE(CProcessViewer01View, CView)

BEGIN_MESSAGE_MAP(CProcessViewer01View, CView)
	//{{AFX_MSG_MAP(CProcessViewer01View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProcessViewer01View construction/destruction

CProcessViewer01View::CProcessViewer01View()
{
	// TODO: add construction code here

}

CProcessViewer01View::~CProcessViewer01View()
{
}

BOOL CProcessViewer01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CProcessViewer01View drawing

void CProcessViewer01View::OnDraw(CDC* pDC)
{
	CProcessViewer01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CProcessViewer01View diagnostics

#ifdef _DEBUG
void CProcessViewer01View::AssertValid() const
{
	CView::AssertValid();
}

void CProcessViewer01View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProcessViewer01Doc* CProcessViewer01View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProcessViewer01Doc)));
	return (CProcessViewer01Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProcessViewer01View message handlers
