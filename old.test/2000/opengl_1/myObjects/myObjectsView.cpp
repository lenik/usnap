// myObjectsView.cpp : implementation of the CMyObjectsView class
//

#include "stdafx.h"
#include "myObjects.h"

#include "myObjectsDoc.h"
#include "myObjectsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyObjectsView

IMPLEMENT_DYNCREATE(CMyObjectsView, CView)

BEGIN_MESSAGE_MAP(CMyObjectsView, CView)
	//{{AFX_MSG_MAP(CMyObjectsView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyObjectsView construction/destruction

CMyObjectsView::CMyObjectsView()
{
	// TODO: add construction code here

}

CMyObjectsView::~CMyObjectsView()
{
}

BOOL CMyObjectsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyObjectsView drawing

void CMyObjectsView::OnDraw(CDC* pDC)
{
	CMyObjectsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	wglMakeCurrent(pDC->m_hDC, hglrc);
	display();
	wglMakeCurrent(pDC->m_hDC, NULL);

	SwapBuffers(pDC->m_hDC);
}

/////////////////////////////////////////////////////////////////////////////
// CMyObjectsView printing

BOOL CMyObjectsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyObjectsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyObjectsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyObjectsView diagnostics

#ifdef _DEBUG
void CMyObjectsView::AssertValid() const
{
	CView::AssertValid();
}

void CMyObjectsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyObjectsDoc* CMyObjectsView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyObjectsDoc)));
	return (CMyObjectsDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyObjectsView message handlers

int CMyObjectsView::OnCreate(LPCREATESTRUCT lpCreateStruct)
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

void CMyObjectsView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	wglDeleteContext(hglrc);
}

void CMyObjectsView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	int w = cx, h = cy;
	if (!h) return;

	CClientDC clientDC(this);
	wglMakeCurrent(clientDC.m_hDC, hglrc);
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
		glOrtho(-2, 2, -2 * (GLfloat)h / (GLfloat)w, 2 * (GLfloat)h / (GLfloat)w, -50, 50);
	else
		glOrtho(-2 * (GLfloat)h / (GLfloat)w, 2 * (GLfloat)h / (GLfloat)w, -2, 2, -50, 50);
	glMatrixMode(GL_MODELVIEW);
	wglMakeCurrent(NULL, NULL);
}

void CMyObjectsView::myinit() {
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLfloat ambientProperties[] = {0.9f, 1.0f, 0.6f, 1.0f};
	GLfloat diffuseProperties[] = {0.8f, 0.8f, 0.8f, 1.0f};
	GLfloat specularProperties[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat position[] = {0.0f, 5.0f, 5.0f, 0.0f};
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientProperties);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseProperties);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularProperties);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 1.0f);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_NORMALIZE);
}

void CMyObjectsView::display() {
	myinit();
	int ii, jj, numR = 25;
	int *numSita = new int[numR];
	double r;
	double tmp0;
	double **coordX = new double *[numR];
	double **coordY = new double *[numR];
	double **coordZ = new double *[numR];
	double nx, ny, nz;
	numSita[0] = 1;
	coordX[0] = new double[numSita[0]];
	coordY[0] = new double[numSita[0]];
	coordZ[0] = new double[numSita[0]];
	for (ii = 1; ii < numR; ii++) {
		if (ii == 1) numSita[ii] = 20;
		else if (ii < 12) numSita[ii] = numSita[ii - 1] * 2;
		else numSita[ii] = numSita[11];
		coordX[ii] = new double[numSita[ii]];
		coordY[ii] = new double[numSita[ii]];
		coordZ[ii] = new double[numSita[ii]];
	}	// for ii

	glPushMatrix();

		glColor3f(0.0f, .5f, 0.0f);
		glRotatef(60, 1.0, 0.0, 0.0);
		for (ii = 0; ii< numR; ii++) {
			r = 1.6 * ii / numR;
			for (jj = 0; jj < numSita[ii]; jj++) {
				coordX[ii][jj] = r * cos(jj * 2 * PI / numSita[ii]);
				coordY[ii][jj] = r * sin(jj * 2 * PI / numSita[ii]);
				tmp0 = r * 8;
				coordZ[ii][jj] = 0.8 * (1 - tmp0 * tmp0) * exp(-0.3 * tmp0 * tmp0);
			}
		}

		for (ii = 0; ii < numR; ii++) {
			if (ii == 1) {
				glBegin(GL_TRIANGLES);
				for (jj = 0; jj < numSita[ii]; jj++) {
					getNormalize(&nx, &ny, &nz,
						coordX[1][jj] - coordX[0][0],
						coordY[1][jj] - coordY[0][0],
						coordZ[1][jj] - coordZ[0][0],
						coordX[1][(jj + 1) % numSita[ii]] - coordX[0][0],
						coordY[1][(jj + 1) % numSita[ii]] - coordY[0][0],
						coordZ[1][(jj + 1) % numSita[ii]] - coordZ[0][0]);
					glNormal3d(nx, ny, nz);
					glVertex3d(coordX[0][0], coordY[0][0], coordZ[0][0]);
					glVertex3d(coordX[1][jj], coordY[1][jj], coordZ[1][jj]);
					glVertex3d(coordX[1][(jj + 1) % numSita[1]],
						coordY[1][(jj + 1) % numSita[1]],
						coordZ[1][(jj + 1) % numSita[1]]);
				}	// for jj
				glEnd();
			} else if (ii > 1 && ii < 12) {
				for (jj = 0; jj < numSita[ii - 1]; jj++) {
					glBegin(GL_TRIANGLES);
						getNormalize(&nx, &ny, &nz,
							coordX[ii][2 * jj] - coordX[ii - 1][jj],
							coordY[ii][2 * jj] - coordY[ii - 1][jj],
							coordZ[ii][2 * jj] - coordZ[ii - 1][jj],
							coordX[ii][(2 * jj + 1) % numSita[ii]] - coordX[ii - 1][jj],
							coordY[ii][(2 * jj + 1) % numSita[ii]] - coordY[ii - 1][jj],
							coordZ[ii][(2 * jj + 1) % numSita[ii]] - coordZ[ii - 1][jj]);
						glNormal3d(nx, ny, nz);
						glVertex3d(
							coordX[ii - 1][jj],
							coordY[ii - 1][jj],
							coordZ[ii - 1][jj]);
						glVertex3d(
							coordX[ii][2 * jj],
							coordY[ii][2 * jj],
							coordZ[ii][2 * jj]);
						glVertex3d(
							coordX[ii][(2 * jj + 1) % numSita[ii]],
							coordY[ii][(2 * jj + 1) % numSita[ii]],
							coordZ[ii][(2 * jj + 1) % numSita[ii]]);
					glEnd();
				}	// for jj
				for (jj = 0; jj < numSita[ii - 1]; jj++) {
					glBegin(GL_TRIANGLES);
						getNormalize(&nx, &ny, &nz,
							coordX[ii][(2 * jj + 1) % numSita[ii]] - coordX[ii - 1][jj],
							coordY[ii][(2 * jj + 1) % numSita[ii]] - coordY[ii - 1][jj],
							coordZ[ii][(2 * jj + 1) % numSita[ii]] - coordZ[ii - 1][jj],
							coordX[ii - 1][(jj + 1) % numSita[ii - 1]] - coordX[ii - 1][jj],
							coordY[ii - 1][(jj + 1) % numSita[ii - 1]] - coordY[ii - 1][jj],
							coordZ[ii - 1][(jj + 1) % numSita[ii - 1]] - coordZ[ii - 1][jj]);
						glNormal3d(nx, ny, nz);
						glVertex3d(
							coordX[ii - 1][jj],
							coordY[ii - 1][jj],
							coordZ[ii - 1][jj]);
						glVertex3d(
							coordX[ii][(2 * jj + 1) % numSita[ii]],
							coordY[ii][(2 * jj + 1) % numSita[ii]],
							coordZ[ii][(2 * jj + 1) % numSita[ii]]);
						glVertex3d(
							coordX[ii - 1][(jj + 1) % numSita[ii - 1]],
							coordY[ii - 1][(jj + 1) % numSita[ii - 1]],
							coordZ[ii - 1][(jj + 1) % numSita[ii - 1]]);
					glEnd();
				}	// for jj
				for (jj = 1; jj < numSita[ii - 1]; jj++) {
					glBegin(GL_TRIANGLES);
						getNormalize(&nx, &ny, &nz,
							coordX[ii][2 * jj - 1] - coordX[ii - 1][jj],
							coordY[ii][2 * jj - 1] - coordY[ii - 1][jj],
							coordZ[ii][2 * jj - 1] - coordZ[ii - 1][jj],
							coordX[ii][2 * jj] - coordX[ii - 1][jj],
							coordY[ii][2 * jj] - coordY[ii - 1][jj],
							coordZ[ii][2 * jj] - coordZ[ii - 1][jj]);
						glNormal3d(nx, ny, nz);
						glVertex3d(
							coordX[ii - 1][jj],
							coordY[ii - 1][jj],
							coordZ[ii - 1][jj]);
						glVertex3d(
							coordX[ii][2 * jj - 1],
							coordY[ii][2 * jj - 1],
							coordZ[ii][2 * jj - 1]);
						glVertex3d(
							coordX[ii][2 * jj],
							coordY[ii][2 * jj],
							coordZ[ii][2 * jj]);
					glEnd();
				}	// for jj
				glBegin(GL_TRIANGLES);
					getNormalize(&nx, &ny, &nz,
						coordX[ii][numSita[ii] - 1] - coordX[ii - 1][0],
						coordY[ii][numSita[ii] - 1] - coordY[ii - 1][0],
						coordZ[ii][numSita[ii] - 1] - coordZ[ii - 1][0],
						coordX[ii][0] - coordX[ii - 1][0],
						coordY[ii][0] - coordY[ii - 1][0],
						coordZ[ii][0] - coordZ[ii - 1][0]);
					glNormal3d(nx, ny, nz);
					glVertex3d(
						coordX[ii - 1][0],
						coordY[ii - 1][0],
						coordZ[ii - 1][0]);
					glVertex3d(
						coordX[ii][numSita[ii] - 1],
						coordY[ii][numSita[ii] - 1],
						coordZ[ii][numSita[ii] - 1]);
					glVertex3d(coordX[ii][0], coordY[ii][0], coordZ[ii][0]);
				glEnd();
			} else if (ii >= 12) {
				for (jj = 0; jj < numSita[ii]; jj++) {
					glBegin(GL_QUAD_STRIP);
						if (jj < numSita[ii] - 1) {
							glVertex3d(
								coordX[ii - 1][jj + 1],
								coordY[ii - 1][jj + 1],
								coordZ[ii - 1][jj + 1]);
							glVertex3d(
								coordX[ii][jj + 1],
								coordY[ii][jj + 1],
								coordZ[ii][jj + 1]);
						} else {
							glVertex3d(
								coordX[ii - 1][0],
								coordY[ii - 1][0],
								coordZ[ii - 1][0]);
							glVertex3d(
								coordX[ii][0],
								coordY[ii][0],
								coordZ[ii][0]);
						}
					glEnd();
				}	// for jj
			}	// if
		}	// for
	glPopMatrix();

	glFlush();
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_NORMALIZE);
	delete coordX;
	delete coordY;
	delete coordZ;
}

void CMyObjectsView::getNormalize(double *nx, double *ny, double *nz, double x1,double y1, double z1, double x2, double y2, double z2) {
	*nx = y1 * z2 - y2 * z1;
	*ny = x2 * z1 - x1 * z2;
	*nz = x1 * y2 - x2 * y1;
}

void CMyObjectsView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
