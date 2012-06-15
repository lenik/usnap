// RobotView.cpp : implementation of the CRobotView class
//

#include "stdafx.h"
#include "Robot.h"

#include "RobotDoc.h"
#include "RobotView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRobotView

IMPLEMENT_DYNCREATE(CRobotView, CView)

BEGIN_MESSAGE_MAP(CRobotView, CView)
	//{{AFX_MSG_MAP(CRobotView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_KEYDOWN()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRobotView construction/destruction

CRobotView::CRobotView()
{
	// TODO: add construction code here

}

CRobotView::~CRobotView()
{
}

BOOL CRobotView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRobotView drawing

void CRobotView::OnDraw(CDC* pDC)
{
	CRobotDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	wglMakeCurrent(pDC->m_hDC, hglrc);
	display();
	wglMakeCurrent(pDC->m_hDC, NULL);
	SwapBuffers(pDC->m_hDC);
}

/////////////////////////////////////////////////////////////////////////////
// CRobotView printing

BOOL CRobotView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRobotView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRobotView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRobotView diagnostics

#ifdef _DEBUG
void CRobotView::AssertValid() const
{
	CView::AssertValid();
}

void CRobotView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRobotDoc* CRobotView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRobotDoc)));
	return (CRobotDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRobotView message handlers

int CRobotView::OnCreate(LPCREATESTRUCT lpCreateStruct)
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

void CRobotView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	wglDeleteContext(hglrc);
}

void CRobotView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	switch (nChar) {
	case VK_UP:
		leftarmup();
		break;
	case VK_DOWN:
		leftarmdown();
		break;
	case VK_RIGHT:
		rightarmup();
		break;
	case VK_LEFT:
		leftarmdown();
		break;
	default:
		break;
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	Invalidate(FALSE);
}

void CRobotView::OnSize(UINT nType, int cx, int cy)
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
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
	wglMakeCurrent(NULL, NULL);

}

void CRobotView::display() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(0.0, 1.25, 0.0);
	auxWireBox(0.5, 0.5, 0.5);
	glTranslatef(0.0, -1.25, 0.0);

	// draw body
	auxWireBox(1.0, 2.0, 0.5);

	// draw left leg
	glTranslatef(-0.375, -1.5, 0.0);
	auxWireBox(0.25, 1.0, 0.5);

	// draw right leg
	glTranslatef(0.75, 0.0, 0.0);
	auxWireBox(0.25, 1.0, 0.5);

	glPopMatrix();

	glPushMatrix();
	// draw left arm
	glTranslatef(-0.5, 0.875, 0.0);
	glRotatef((GLfloat)l_arm, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, 0.0, 0.0);
	auxWireBox(1.0, 0.25, 0.5);
	glPopMatrix();

	glPushMatrix();
	// draw right arm
	glTranslatef(0.5, 0.875, 0.0);
	glRotatef((GLfloat)r_arm, 0.0, 0.0, 1.0);
	glTranslatef(0.5, 0.0, 0.0);
	auxWireBox(1.0, 0.25, 0.5);
	glPopMatrix();

	// Flush
	glFlush();
}

void CRobotView::leftarmup() {
	if (l_arm == -90) return;
	l_arm = (l_arm - 5) % 360;
}

void CRobotView::leftarmdown() {
	if (l_arm == 90) return;
	l_arm = (l_arm + 5) % 360;
}

void CRobotView::rightarmup() {
	if (r_arm == 90) return;
	r_arm = (r_arm + 5) % 360;
}

void CRobotView::rightarmdown() {
	if (r_arm == -90) return;
	r_arm = (r_arm - 5) % 360;
}
