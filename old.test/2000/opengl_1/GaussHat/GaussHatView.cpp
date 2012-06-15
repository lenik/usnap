// GaussHatView.cpp : implementation of the CGaussHatView class
//

#include "stdafx.h"
#include "GaussHat.h"

#include "GaussHatDoc.h"
#include "GaussHatView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGaussHatView

IMPLEMENT_DYNCREATE(CGaussHatView, CView)

BEGIN_MESSAGE_MAP(CGaussHatView, CView)
	//{{AFX_MSG_MAP(CGaussHatView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGaussHatView construction/destruction

CGaussHatView::CGaussHatView()
{
	// TODO: add construction code here

}

CGaussHatView::~CGaussHatView()
{
}

BOOL CGaussHatView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGaussHatView drawing

void CGaussHatView::OnDraw(CDC* pDC)
{
	CGaussHatDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	wglMakeCurrent(pDC->m_hDC, hglrc);
	display();
	wglMakeCurrent(pDC->m_hDC, NULL);
	SwapBuffers(pDC->m_hDC);
}

/////////////////////////////////////////////////////////////////////////////
// CGaussHatView printing

BOOL CGaussHatView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGaussHatView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGaussHatView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGaussHatView diagnostics

#ifdef _DEBUG
void CGaussHatView::AssertValid() const
{
	CView::AssertValid();
}

void CGaussHatView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGaussHatDoc* CGaussHatView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGaussHatDoc)));
	return (CGaussHatDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGaussHatView message handlers

int CGaussHatView::OnCreate(LPCREATESTRUCT lpCreateStruct)
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
		24,
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

void CGaussHatView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	int width = cx, height = cy;
	CClientDC clientDC(this);
	wglMakeCurrent(clientDC.m_hDC, hglrc);
	glViewport(0, 0, width, height);
	wglMakeCurrent(NULL, NULL);
}

void CGaussHatView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	wglDeleteContext(hglrc);
}

void CGaussHatView::myinit() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
}


float degree = 5;
float rx = 0, ry = 0, rz = 0;

CPoint p;
float scalex, scaley;

BOOLEAN inRotate = FALSE, inScale = FALSE;

void CGaussHatView::display() {
	myinit();
	glColor3f(.9, .9, .9);

	double Matrix[4][4];

	glGetDoublev(GL_MODELVIEW_MATRIX, (double *)Matrix);

	glLoadIdentity();

	glGetDoublev(GL_MODELVIEW_MATRIX, (double *)Matrix);

	glTranslatef(2, 3, 4);

	glGetDoublev(GL_MODELVIEW_MATRIX, (double *)Matrix);

	/*
		glEnable(GL_POLYGON_SMOOTH);
		glEnable(GL_LINE_SMOOTH);
		glEnable(GL_POINT_SMOOTH);
		glEnable(GL_LINE_WIDTH);
		glPointSize(1);
	*/
		//glScalef(2, 1, 1);

		glLineWidth(.5);

		//glLoadIdentity();
		if (inRotate)
			glRotatef(degree, rx, ry, rz);
		if (inScale)
			glScalef(scalex + 1, scaley + 1, 1);


/*
		glTranslatef(.2, 0, 0);
		auxWireOctahedron(.05);
		glTranslatef(.1, 0, 0);
		auxWireTetrahedron(.05);
		glTranslatef(.1, 0, 0);
		auxWireDodecahedron(.05);
		glTranslatef(.1, 0, 0);
		auxWireCone(.05, .05);
		glTranslatef(-.4, 0, 0);
*/

		glFlush();


	glBegin(GL_LINE_LOOP);
		/*

		glVertex2f(-.5, -.5);
		glVertex2f(.5, -.5);
		glVertex2f(-.45, 0);
		glVertex2f(.5, .5);
		glVertex2f(-.5, .5);
		*/

	glEnd();
}

void CGaussHatView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	rx = ry = rz = 0;
	p = point;
	inRotate = TRUE;

	CView::OnLButtonDown(nFlags, point);
}

void CGaussHatView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	inRotate = FALSE;

	CView::OnLButtonUp(nFlags, point);
}

void CGaussHatView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (inRotate) {
		ry = point.x - p.x;
		rx = point.y - p.y;
		rz = 0;
		p = point;
		this->Invalidate(FALSE);
	}
	if (inScale) {
		scalex = (point.x - p.x) / 50;
		scaley = (point.y - p.y) / 50;
		p = point;
		this->Invalidate(FALSE);
	}
	CView::OnMouseMove(nFlags, point);
}

void CGaussHatView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p = point;
	inScale = TRUE;
	CView::OnRButtonDown(nFlags, point);
}

void CGaussHatView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	inScale = FALSE;
	CView::OnRButtonUp(nFlags, point);
}
