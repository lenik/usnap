// XMLViewerView.cpp : implementation of the CXMLViewerView class
//

#include "stdafx.h"
#include "XMLViewer.h"

#include "XMLViewerDoc.h"
#include "XMLViewerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXMLViewerView

IMPLEMENT_DYNCREATE(CXMLViewerView, CHtmlView)

BEGIN_MESSAGE_MAP(CXMLViewerView, CHtmlView)
	//{{AFX_MSG_MAP(CXMLViewerView)
	ON_COMMAND(ID_REDRAW, OnRedraw)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CHtmlView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CHtmlView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXMLViewerView construction/destruction

CXMLViewerView::CXMLViewerView()
{
	// TODO: add construction code here
	this->bInited = FALSE;
}

CXMLViewerView::~CXMLViewerView()
{
}

BOOL CXMLViewerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CXMLViewerView drawing

void CXMLViewerView::OnDraw(CDC* pDC)
{
	CXMLViewerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	if (!this->bInited) {
		this->OnInitialUpdate();
	}
	LPDISPATCH pdisp = this->GetHtmlDocument();
	if (pdisp != NULL) {
		IHTMLDocument2 *phtml;
		pdisp->QueryInterface(IID_IHTMLDocument, (LPVOID *)&phtml);
		IHTMLElement *body;
		phtml->get_body(&body);
		if (body != NULL) {
			body->put_innerHTML(pDoc->m_view);
		} else {
			MessageBox(_T("couldn't get html body!"));
		}
		pdisp->Release();
	} else {
		MessageBox(_T("couldn't get html document"));
	}
}

/////////////////////////////////////////////////////////////////////////////
// CXMLViewerView printing

BOOL CXMLViewerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CXMLViewerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CXMLViewerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CXMLViewerView diagnostics

#ifdef _DEBUG
void CXMLViewerView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CXMLViewerView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CXMLViewerDoc* CXMLViewerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CXMLViewerDoc)));
	return (CXMLViewerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CXMLViewerView message handlers

void CXMLViewerView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: Add your specialized code here and/or call the base class
	if (this->bInited) {
		this->OnDraw(NULL);
	}
}

void CXMLViewerView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();
	//TODO: This code navigates to a popular spot on the web.
	//Change the code to go where you'd like.
	Navigate2(_T("about:Hello World!"),NULL,NULL);
	this->bInited	= TRUE;
	this->OnUpdate(NULL, 0, NULL);
}

void CXMLViewerView::OnRedraw()
{
	// TODO: Add your command handler code here
	this->OnUpdate(NULL, 0, NULL);
}
