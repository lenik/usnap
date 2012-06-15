// ColorTriView.cpp : implementation of the CColorTriView class
//

#include "stdafx.h"
#include "ColorTri.h"

#include "ColorTriDoc.h"
#include "ColorTriView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorTriView

IMPLEMENT_DYNCREATE(CColorTriView, CView)

BEGIN_MESSAGE_MAP(CColorTriView, CView)
	//{{AFX_MSG_MAP(CColorTriView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorTriView construction/destruction

CColorTriView::CColorTriView()
{
	// TODO: add construction code here

}

CColorTriView::~CColorTriView()
{
}

BOOL CColorTriView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CColorTriView drawing

void CColorTriView::OnDraw(CDC* pDC)
{
	CColorTriDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	wglMakeCurrent(pDC->m_hDC, hglrc);
	display();
	wglMakeCurrent(pDC->m_hDC, NULL);
	SwapBuffers(pDC->m_hDC);
}

/////////////////////////////////////////////////////////////////////////////
// CColorTriView printing

BOOL CColorTriView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CColorTriView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CColorTriView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CColorTriView diagnostics

#ifdef _DEBUG
void CColorTriView::AssertValid() const
{
	CView::AssertValid();
}

void CColorTriView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CColorTriDoc* CColorTriView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CColorTriDoc)));
	return (CColorTriDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CColorTriView message handlers

int CColorTriView::OnCreate(LPCREATESTRUCT lpCreateStruct)
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

void CColorTriView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	wglDeleteContext(hglrc);
}

void CColorTriView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	GLsizei w = cx, h = cy;
	if (!h) return;
	CClientDC clientDC(this);
	wglMakeCurrent(clientDC.m_hDC, hglrc);
	glViewport(0, 0, w, h);
	wglMakeCurrent(NULL, NULL);
}

void CColorTriView::myinit() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_ALPHA_TEST);
}

void CColorTriView::display() {
	myinit();
	void DrawTriangle(double *v1, double *v2, double *v3, float *rgb);
	void sleep(clock_t wait);

	int ii;
	int numTriangle = 1000;

	double **Vertex1 = new double *[numTriangle];
	double **Vertex2 = new double *[numTriangle];
	double **Vertex3 = new double *[numTriangle];
	for (ii = 0; ii < numTriangle; ii++) {
		Vertex1[ii] = new double[2];
		Vertex2[ii] = new double[2];
		Vertex3[ii] = new double[2];
	}

	double maxX1 = -1e10, maxX2 = -1e10, maxX3 = -1e10;
	double minX1 = 1e10, minX2 = 1e10, minX3 = 1e10;
	double maxY1 = -1e10, maxY2 = -1e10, maxY3 = -1e10;
	double minY1 = 1e10, minY2 = 1e10, minY3 = 1e10;

	for (ii = 0; ii < numTriangle; ii++) {
		// Generates tirnalges' vertexes randomize
		// and work out the dispatch range of the value of the vertexes
		Vertex1[ii][0] = rand();
		if (maxX1 < Vertex1[ii][0]) maxX1 = Vertex1[ii][0];
		if (minX1 > Vertex1[ii][0]) minX1 = Vertex1[ii][0];
		Vertex1[ii][1] = rand();
		if (maxY1 < Vertex1[ii][1]) maxY1 = Vertex1[ii][1];
		if (minY1 > Vertex1[ii][1]) minY1 = Vertex1[ii][1];
		Vertex2[ii][0] = rand();
		if (maxX2 < Vertex2[ii][0]) maxX2 = Vertex2[ii][0];
		if (minX2 > Vertex2[ii][0]) minX2 = Vertex2[ii][0];
		Vertex2[ii][1] = rand();
		if (maxY2 < Vertex2[ii][1]) maxY2 = Vertex2[ii][1];
		if (minY2 > Vertex2[ii][1]) minY2 = Vertex2[ii][1];
		Vertex3[ii][0] = rand();
		if (maxX3 < Vertex2[ii][0]) maxX3 = Vertex3[ii][0];
		if (minX3 > Vertex3[ii][0]) minX3 = Vertex3[ii][0];
		Vertex3[ii][1] = rand();
		if (maxY3 < Vertex3[ii][1]) maxY3 = Vertex3[ii][1];
		if (minY3 > Vertex3[ii][1]) minY3 = Vertex3[ii][1];
	}

	for (ii = 0; ii < numTriangle; ii++) {
		Vertex1[ii][0] = -0.5 + 1.0 * (Vertex1[ii][0] - minX1) / (maxX1 - minX1);
		Vertex1[ii][1] = -0.8 + 1.6 * (Vertex1[ii][1] - minY1) / (maxY1 - minY1);

		Vertex2[ii][0] = -0.5 + 1.0 * (Vertex2[ii][0] - minX2) / (maxX2 - minX2);
		Vertex2[ii][1] = 00.8 + 1.6 * (Vertex2[ii][1] - minY2) / (maxY2 - minY2);

		Vertex3[ii][0] = -0.5 + 1.0 * (Vertex3[ii][0] - minX3) / (maxX3 - minX3);
		Vertex3[ii][1] = -0.8 + 1.6 * (Vertex3[ii][1] - minY3) / (maxY3 - minY3);
	}

	static GLfloat rgb[][3] = {
		{ 0.0f, 0.0f, 0.2f }, { 0.0f, 0.0f, 0.4f }, { 0.0f, 0.0f, 0.6f }, { 0.0f, 0.0f, 0.8f }, { 0.0f, 0.0f, 1.0f },
		{ 0.0f, 0.2f, 0.5f }, { 0.0f, 0.4f, 0.5f }, { 0.0f, 0.6f, 0.5f }, { 0.0f, 0.8f, 0.5f }, { 0.0f, 1.0f, 0.5f },
		{ 0.2f, 0.5f, 0.5f }, { 0.4f, 0.5f, 0.5f }, { 0.6f, 0.5f, 0.5f }, { 0.8f, 0.5f, 0.5f }, { 1.0f, 0.5f, 0.5f },
		{ 1.0f, 0.3f, 0.3f }
	};

	glPushMatrix();
	for (ii = 0; ii < numTriangle; ii++) {
		DrawTriangle(Vertex1[ii], Vertex2[ii], Vertex3[ii], rgb[ii % 16]);
		// Delay for a specified time
		// sleep((clock_t)0.01 * CLOCKS_PER_SEC);
	}
	glPopMatrix();
	glFlush();
}

void DrawTriangle(double *Vertex1, double *Vertex2, double *Vertex3, float *rgb) {
	glBegin(GL_TRIANGLES);
		glColor4f(rgb[0], rgb[1], rgb[2], .2);
		glVertex2dv(Vertex1);
		glVertex2dv(Vertex2);
		glVertex2dv(Vertex3);
	glEnd();
}

void sleep(clock_t wait) {
	clock_t goal;
	goal = wait + clock();
	while (goal > clock());
}