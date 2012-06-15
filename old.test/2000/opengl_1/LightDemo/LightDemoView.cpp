// LightDemoView.cpp : implementation of the CLightDemoView class
//

#include "stdafx.h"
#include "LightDemo.h"

#include "LightDemoDoc.h"
#include "LightDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLightDemoView

IMPLEMENT_DYNCREATE(CLightDemoView, CView)

BEGIN_MESSAGE_MAP(CLightDemoView, CView)
	//{{AFX_MSG_MAP(CLightDemoView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLightDemoView construction/destruction

CLightDemoView::CLightDemoView()
{
	// TODO: add construction code here

}

CLightDemoView::~CLightDemoView()
{
}

BOOL CLightDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLightDemoView drawing

void CLightDemoView::OnDraw(CDC* pDC)
{
	CLightDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CLightDemoView printing

BOOL CLightDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLightDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLightDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLightDemoView diagnostics

#ifdef _DEBUG
void CLightDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CLightDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLightDemoDoc* CLightDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLightDemoDoc)));
	return (CLightDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLightDemoView message handlers

int CLightDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here

	return 0;
}

void CLightDemoView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here

}

void CLightDemoView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CLightDemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC clientdc(this);
	clientdc.SelectStockObject(WHITE_BRUSH);
	clientdc.TextOut(10, 10, "RGB");

	CView::OnLButtonDown(nFlags, point);
}

void CLightDemoView::DrawLight(pos p) {
	glBegin(GL_POLYGON);
		glVertex3f(p.x - .001, p.y - .001, p.z);
		glVertex3f(p.x + .001, p.y - .001, p.z);
		glVertex3f(p.x + .001, p.y + .001, p.z);
		glVertex3f(p.x - .001, p.y + .001, p.z);
	glEnd();
}

void CLightDemoView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	int w = cx;
	int h = cy;
	if (!h) return;
	CClientDC clientDC(this);
	wglMakeCurrent(clientDC.m_hDC, hglrc);
	glViewport(0, 0, w, h);
	viewrect.left = viewrect.top = 0;
	viewrect.right = w;
	viewrect.bottom = h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	wglMakeCurrent(NULL, NULL);
}

pos CLightDemoView::GetRasPos(pos glpos) {
	pos raspos = { 0, 0, 0, 1 };
	raspos.x = (glpos.x + 1) / 2 * viewrect.Width() + viewrect.left;
	raspos.y = (glpos.y + 1) / 2 * viewrect.Height() + viewrect.top;
	return raspos;
}

pos CLightDemoView::GetGlPos(pos raspos) {
	pos glpos = { 0, 0, 0, 1};
	glpos.x = (raspos.x - viewrect.left) / viewrect.Width() * 2 - 1;
	glpos.y = (raspos.y - viewrect.top) / viewrect.Height() * 2 - 1;
	return glpos;
}
