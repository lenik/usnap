// solarsysView.cpp : implementation of the CSolarsysView class
//

#include "stdafx.h"
#include "solarsys.h"

#include "solarsysDoc.h"
#include "solarsysView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSolarsysView

IMPLEMENT_DYNCREATE(CSolarsysView, CView)

BEGIN_MESSAGE_MAP(CSolarsysView, CView)
	//{{AFX_MSG_MAP(CSolarsysView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSolarsysView construction/destruction

CSolarsysView::CSolarsysView()
{
	// TODO: add construction code here

}

CSolarsysView::~CSolarsysView()
{
}

BOOL CSolarsysView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSolarsysView drawing

void CSolarsysView::OnDraw(CDC* pDC)
{
	CSolarsysDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	wglMakeCurrent(pDC->m_hDC, hglrc);
	display();
	wglMakeCurrent(pDC->m_hDC, NULL);
	SwapBuffers(pDC->m_hDC);
}

/////////////////////////////////////////////////////////////////////////////
// CSolarsysView printing

BOOL CSolarsysView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSolarsysView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSolarsysView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSolarsysView diagnostics

#ifdef _DEBUG
void CSolarsysView::AssertValid() const
{
	CView::AssertValid();
}

void CSolarsysView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSolarsysDoc* CSolarsysView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSolarsysDoc)));
	return (CSolarsysDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSolarsysView message handlers

int CSolarsysView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here
	PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		23,
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		32,
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};

	CClientDC clientdc(this);
	int pf = ChoosePixelFormat(clientdc.m_hDC, &pfd);
	BOOL rt = SetPixelFormat(clientdc.m_hDC, pf, &pfd);
	hglrc = wglCreateContext(clientdc.m_hDC);

	return 0;
}

void CSolarsysView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	GLsizei w = cx, h = cy;
	if (!h) return;

	CClientDC clientDC(this);
	wglMakeCurrent(clientDC.m_hDC, hglrc);
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1, 20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);

	wglMakeCurrent(NULL, NULL);

}

void CSolarsysView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	wglDeleteContext(hglrc);
}

void CSolarsysView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	switch (nChar) {
	case VK_LEFT:
		revanticlockwise();
		break;
	case VK_RIGHT:
		revclockwise();
		break;
	case VK_UP:
		rotationanticlockwise();
		break;
	case VK_DOWN:
		rotationclockwise();
		break;
	default:
		break;
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	Invalidate(FALSE);
}

void CSolarsysView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}

void CSolarsysView::display() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	auxWireSphere(1.0);
	glPopMatrix();

	glPushMatrix();

	glRotatef((GLfloat)revolution, 0.0, 1.0, 0.0);
	glTranslatef(3.0, 0.0, 0.0);
	glRotatef((GLfloat)rotation, 0.0, 1.0, 0.0);
	// Draw planet
	glPushMatrix();
	glRotatef((GLfloat)rotation, 0.0, 1.0, 0.0);
	auxWireSphere(0.4);
	glPopMatrix();

	glPopMatrix();

	glFlush();
}

void CSolarsysView::revanticlockwise() {
	revolution = (revolution + 10) % 360;
}

void CSolarsysView::revclockwise() {
	revolution = (revolution - 10) % 360;
}

void CSolarsysView::rotationanticlockwise() {
	rotation = (rotation + 1) % 360;
}

void CSolarsysView::rotationclockwise() {
	rotation = (rotation - 1) % 360;
}
