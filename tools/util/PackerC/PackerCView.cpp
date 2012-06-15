// PackerCView.cpp : implementation of the CPackerCView class
//

#include "stdafx.h"
#include "PackerC.h"

#include "PackerCDoc.h"
#include "PackerCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPackerCView

IMPLEMENT_DYNCREATE(CPackerCView, CHtmlView)

BEGIN_MESSAGE_MAP(CPackerCView, CHtmlView)
	//{{AFX_MSG_MAP(CPackerCView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPackerCView construction/destruction

CPackerCView::CPackerCView()
{
	// TODO: add construction code here

}

CPackerCView::~CPackerCView()
{
}

BOOL CPackerCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPackerCView drawing

void CPackerCView::OnDraw(CDC* pDC)
{
	CPackerCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CPackerCView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like.
	Navigate2(_T("about:PackerC"),NULL,NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CPackerCView printing


/////////////////////////////////////////////////////////////////////////////
// CPackerCView diagnostics

#ifdef _DEBUG
void CPackerCView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CPackerCView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CPackerCDoc* CPackerCView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPackerCDoc)));
	return (CPackerCDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPackerCView message handlers
