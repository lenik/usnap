// htmlHelloView.cpp : implementation of the CHtmlHelloView class
//

#include "stdafx.h"
#include "htmlHello.h"

#include "htmlHelloDoc.h"
#include "htmlHelloView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHtmlHelloView

IMPLEMENT_DYNCREATE(CHtmlHelloView, CHtmlView)

BEGIN_MESSAGE_MAP(CHtmlHelloView, CHtmlView)
	//{{AFX_MSG_MAP(CHtmlHelloView)
	ON_COMMAND(ID_BUTTON32771, OnButton32771)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHtmlHelloView construction/destruction

CHtmlHelloView::CHtmlHelloView()
{
	// TODO: add construction code here

}

CHtmlHelloView::~CHtmlHelloView()
{
}

BOOL CHtmlHelloView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHtmlHelloView drawing

void CHtmlHelloView::OnDraw(CDC* pDC)
{
	CHtmlHelloDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CHtmlHelloView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like.

	Navigate2(_T("about:Hello World!"),NULL,NULL);

}

/////////////////////////////////////////////////////////////////////////////
// CHtmlHelloView printing


/////////////////////////////////////////////////////////////////////////////
// CHtmlHelloView diagnostics

#ifdef _DEBUG
void CHtmlHelloView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CHtmlHelloView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CHtmlHelloDoc* CHtmlHelloView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHtmlHelloDoc)));
	return (CHtmlHelloDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHtmlHelloView message handlers

void CHtmlHelloView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: Add your specialized code here and/or call the base class

	LPDISPATCH pdisp = this->GetHtmlDocument();
	if (pdisp != NULL) {
		IHTMLDocument2 *phtml;
		pdisp->QueryInterface(IID_IHTMLDocument, (LPVOID *)&phtml);
		IHTMLElement *body;
		phtml->get_body(&body);
		body->put_innerHTML(
			SysAllocString(L"Hello, world!")
			);
		pdisp->Release();
	} else {
		MessageBox(_T("couldn't get html document"));
	}

}

void CHtmlHelloView::OnButton32771()
{
	// TODO: Add your command handler code here
	this->OnUpdate(NULL, 0, NULL);
}
