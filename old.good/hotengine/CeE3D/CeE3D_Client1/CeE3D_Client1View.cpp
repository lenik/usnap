// CeE3D_Client1View.cpp : implementation of the CCeE3D_Client1View class
//

#include "stdafx.h"

#include "../CeE3D/CeE3D_i.c"

#include "CeE3D_Client1.h"

#include "CeE3D_Client1Doc.h"
#include "CeE3D_Client1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCeE3D_Client1View

IMPLEMENT_DYNCREATE(CCeE3D_Client1View, CView)

BEGIN_MESSAGE_MAP(CCeE3D_Client1View, CView)
	//{{AFX_MSG_MAP(CCeE3D_Client1View)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_KEYDOWN()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCeE3D_Client1View construction/destruction

CCeE3D_Client1View::CCeE3D_Client1View()
{
	this->pCeAux	= NULL;
	this->pCeBase	= NULL;
	this->pCeEnv	= NULL;
	this->pCeModel	= NULL;
	this->pCeRender	= NULL;
	this->pCeUtil	= NULL;
}

CCeE3D_Client1View::~CCeE3D_Client1View()
{
}

BOOL CCeE3D_Client1View::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCeE3D_Client1View drawing

void CCeE3D_Client1View::OnDraw(CDC* pDC)
{
	CCeE3D_Client1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	HDC hDC = pDC->m_hDC;
	BOOL b;

	this->pCeAux->DrawBegin(hDC, &b);
		this->pCeBase->ClearColor(0, 0, 0, 1);
		this->pCeBase->Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		this->pCeBase->Color3f(1, 1, 1);
		this->pCeAux->DrawWireTorus(0.1, 0.7);
		this->pCeAux->DrawWireTeapot(0.6);
		this->pCeAux->DrawSolidTeapot(0.3);
		this->pCeBase->Flush();

		//SwapBuffers(hDC);
	this->pCeAux->DrawEnd(hDC, &b);

	pDC->Rectangle(10, 10, 50, 50);
}

/////////////////////////////////////////////////////////////////////////////
// CCeE3D_Client1View diagnostics

#ifdef _DEBUG
void CCeE3D_Client1View::AssertValid() const
{
	CView::AssertValid();
}

void CCeE3D_Client1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCeE3D_Client1Doc* CCeE3D_Client1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCeE3D_Client1Doc)));
	return (CCeE3D_Client1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCeE3D_Client1View message handlers

int CCeE3D_Client1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here
	InitObjects();
	return 0;
}

void CCeE3D_Client1View::InitObjects() {
	HRESULT hr;

	CoCreateInstance(
		CLSID_CeE3DAux,
		NULL,
		CLSCTX_SERVER,
		IID_ICeE3DAux,
		(LPVOID *)&this->pCeAux);
	CoCreateInstance(
		CLSID_CeE3DBase,
		NULL,
		CLSCTX_SERVER,
		IID_ICeE3DBase,
		(LPVOID *)&this->pCeBase);
	CoCreateInstance(
		CLSID_CeE3DModel,
		NULL,
		CLSCTX_SERVER,
		IID_ICeE3DModel,
		(LPVOID *)&this->pCeModel);
	CoCreateInstance(
		CLSID_CeE3DEnv,
		NULL,
		CLSCTX_SERVER,
		IID_ICeE3DEnv,
		(LPVOID *)&this->pCeEnv);
	CoCreateInstance(
		CLSID_CeE3DRender,
		NULL,
		CLSCTX_SERVER,
		IID_ICeE3DRender,
		(LPVOID *)&this->pCeRender);
	CoCreateInstance(
		CLSID_CeE3DUtil,
		NULL,
		CLSCTX_SERVER,
		IID_ICeE3DUtil,
		(LPVOID *)&this->pCeUtil);

	if (this->pCeAux	== NULL) this->CleanUpObjects();
	else if (this->pCeBase	== NULL) this->CleanUpObjects();
	else if (this->pCeModel	== NULL) this->CleanUpObjects();
	else if (this->pCeEnv	== NULL) this->CleanUpObjects();
	else if (this->pCeRender== NULL) this->CleanUpObjects();
	else if (this->pCeUtil	== NULL) this->CleanUpObjects();
	else {
		//pCeAux->DrawBegin(this->GetDC()->m_hDC);
		/*
		PIXELFORMATDESCRIPTOR pfd;
		this->pCeAux->get_PixelFormatDescriptor(&pfd);
		pfd.dwFlags = PFD_DRAW_TO_WINDOW
				| PFD_SUPPORT_OPENGL;
		this->pCeAux->put_PixelFormatDescriptor(&pfd);
		*/
		BOOL b;

		hr = pCeAux->InitDC(this->GetDC()->m_hDC, &b);

		pCeAux->DrawBegin(this->GetDC()->m_hDC, &b);
		pCeAux->DrawEnd(this->GetDC()->m_hDC, &b);
	}
}

void CCeE3D_Client1View::CleanUpObjects() {
	if (this->pCeAux	!= NULL) this->pCeAux->Release();
	if (this->pCeBase	!= NULL) this->pCeBase->Release();
	if (this->pCeModel	!= NULL) this->pCeModel->Release();
	if (this->pCeEnv	!= NULL) this->pCeEnv->Release();
	if (this->pCeRender	!= NULL) this->pCeRender->Release();
	if (this->pCeUtil	!= NULL) this->pCeUtil->Release();
}

void CCeE3D_Client1View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	this->CleanUpObjects();
}

void CCeE3D_Client1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	switch (nChar) {
	case 'd':
		this->Invalidate();
		break;
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CCeE3D_Client1View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	HDC hDC = this->GetDC()->m_hDC;
	BOOL b;
	this->pCeAux->DrawBegin(hDC, &b);
		this->pCeBase->Viewport(0, 0, cx, cy);
	this->pCeAux->DrawEnd(hDC, &b);
}
