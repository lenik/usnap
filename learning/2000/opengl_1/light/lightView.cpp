// lightView.cpp : implementation of the CLightView class
//

#include "stdafx.h"
#include "light.h"

#include "lightDoc.h"
#include "lightView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLightView

IMPLEMENT_DYNCREATE(CLightView, CView)

BEGIN_MESSAGE_MAP(CLightView, CView)
	//{{AFX_MSG_MAP(CLightView)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLightView construction/destruction

CLightView::CLightView()
{
	// TODO: add construction code here

}

CLightView::~CLightView()
{
}

BOOL CLightView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLightView drawing

void CLightView::OnDraw(CDC* pDC)
{
	CLightDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	wglMakeCurrent(pDC->m_hDC, hglrc);
	display();
	wglMakeCurrent(NULL, NULL);
	SwapBuffers(pDC->m_hDC);
}

/////////////////////////////////////////////////////////////////////////////
// CLightView printing

BOOL CLightView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLightView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLightView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLightView diagnostics

#ifdef _DEBUG
void CLightView::AssertValid() const
{
	CView::AssertValid();
}

void CLightView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLightDoc* CLightView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLightDoc)));
	return (CLightDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLightView message handlers

void CLightView::display() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myinit();

	auxSolidTorus(0.5, 1.0);
	glFlush();
}

void CLightView::myinit() {
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 60.0 };
	GLfloat light_position[] = { 0.0f, 0.2, 0.6, 0.0 };

	light_position[0] = lx;
	light_position[1] = ly;
	light_position[2] = lz;

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	// enable
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
}

void CLightView::OnSize(UINT nType, int cx, int cy)
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
	if (w <= h) {
		glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w,
			1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	} else {
		glOrtho(-1.5 * (GLfloat)w / (GLfloat)h, 1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int CLightView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here
	lx = ly = lz = 0;

	PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
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

void CLightView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here

}

void CLightView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	switch (nChar) {
	case VK_LEFT:
		lx -= .002;
		break;
	case VK_RIGHT:
		lx += .002;
		break;
	case VK_UP:
		ly += .005;
		break;
	case VK_DOWN:
		ly -= .005;
		break;
	case VK_PRIOR:
		lz -= .005;
		break;
	case VK_NEXT:
		lz += .005;
		break;

	default:
		break;
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	Invalidate(FALSE);
}
