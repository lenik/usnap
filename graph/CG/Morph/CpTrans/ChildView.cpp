// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "CpTrans.h"
#include "ChildView.h"
#include "MainFrm.h"
#include "CpTransI.h"
#include "CpTransI_easy.h"

#include <math.h>

#define CIRCLE_PIXELS		16

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView

REAL	CChildView::_sleep_val		= 10;
BOOL	CChildView::IsChkWait		= FALSE;
BOOL	CChildView::MouseDownChecker	= FALSE;

const	int	D_WIDTH			= 100;
const	int	D_HEIGHT		= 100;

const	int	D_X0			= 80;
const	int	D_Y0			= 60;

const	int	D_X1			= D_X0 + 50 + D_WIDTH;
const	int	D_Y1			= D_Y0 + 40 + D_HEIGHT;

CChildView::CChildView()
{
	initData();
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_COMMAND(ID_BUTTON_LINE, OnButtonLine)
	ON_COMMAND(ID_BUTTON_RECT, OnButtonRect)
	ON_COMMAND(ID_BUTTON_CIRCLE, OnButtonCircle)
	ON_COMMAND(ID_SPEED_FAST, OnSpeedFast)
	ON_COMMAND(ID_SPEED_SLOW, OnSpeedSlow)
	ON_COMMAND(ID_BUTTON_CHKRES, OnButtonChkRes)
	ON_COMMAND(ID_BUTTON_CHKWAIT, OnButtonChkWait)
	ON_COMMAND(ID_BUTTON_CLS, OnButtonCls)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

void	STDCALL CChildView::initData() {
	int	i ;
	cpLine[0].x	= 20;
	cpLine[0].y	= 20;
	cpLine[1].x	= 80;
	cpLine[1].y	= 80;

	cpRect[0].x	= 20;
	cpRect[0].y	= 80;
	cpRect[1].x	= 80;
	cpRect[1].y	= 80;
	cpRect[2].x	= 80;
	cpRect[2].y	= 20;
	cpRect[3].x	= 20;
	cpRect[3].y	= 20;

	for (i = 0; i < CIRCLE_PIXELS; i++) {
		cpCircle[i].x	= (INT)(50 + cos(6.28 * i / CIRCLE_PIXELS) * 40);
		cpCircle[i].y	= (INT)(50 + sin(6.28 * i / CIRCLE_PIXELS) * 40);
	}
}

void	STDCALL CChildView::switchTo(INT i) {
	CPPACK		cpp;
	CPREFERPROC	referProc	= cp_refer_easy;
	cpp.cpSrc	= cpLine;
	cpp.nSrc	= 2;
	cpp.cpDst	= cpRect;
	cpp.nDst	= 4;

	switch (lastOp) {
	case 'l':
		cpp.cpSrc	= cpLine;
		cpp.nSrc	= 2;
		break;
	case 'r':
		cpp.cpSrc	= cpRect;
		cpp.nSrc	= 4;
		break;
	case 'c':
		cpp.cpSrc	= cpCircle;
		cpp.nSrc	= CIRCLE_PIXELS;
		break;
	}

	switch (i) {
	case 'l':
		cpp.cpDst	= cpLine;
		cpp.nDst	= 2;
		break;
	case 'r':
		cpp.cpDst	= cpRect;
		cpp.nDst	= 4;
		break;
	case 'c':
		cpp.cpDst	= cpCircle;
		cpp.nDst	= CIRCLE_PIXELS;
		break;
	}

	CMainFrame *	pFrame	= (CMainFrame *)GetParentFrame();
	IsChkWait	= pFrame->getChkwait();
	referProc	= pFrame->getChkprecise() ? cp_refer : cp_refer_easy;

	CDC	*pDC	= GetDC();

	if (((CMainFrame *)GetParentFrame())->getChkres()) {
		cpp.pDC	= pDC;
		cp_transform(
			cpp.cpSrc, cpp.nSrc, cpp.cpDst, cpp.nDst,
			DEFAULT_SAMPLE,
			distance_e,
			NULL, 0,
			chkrel, (DWORD)&cpp,
			TRUE,
			referProc);
	} else {
		cp_transform(cpp.cpSrc, cpp.nSrc, cpp.cpDst, cpp.nDst,
			DEFAULT_SAMPLE,
			distance_e,
			draw, (DWORD)pDC,
			NULL, 0,
			FALSE,
			referProc);
	}
	ReleaseDC(pDC);

	lastOp	= i;
}

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_DBLCLKS | CS_SAVEBITS,
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// Do not call CWnd::OnPaint() for painting messages
}

void CChildView::OnButtonLine()
{
	// TODO: Add your command handler code here
	switchTo('l');
}

void CChildView::OnButtonRect()
{
	// TODO: Add your command handler code here
	switchTo('r');
}

void CChildView::OnButtonCircle()
{
	// TODO: Add your command handler code here
	switchTo('c');
}

void CChildView::OnSpeedFast()
{
	// TODO: Add your command handler code here
	char curval[20];
	if (_sleep_val  > 0) _sleep_val--;
	sprintf(curval, "当前速度 = %3.0f", _sleep_val);
	((CMainFrame *)GetParentFrame())->setStatus(0, curval);
}

void CChildView::OnSpeedSlow()
{
	// TODO: Add your command handler code here
	char curval[20];
	if (_sleep_val < 100) _sleep_val++;
	sprintf(curval, "当前速度 = %3.0lf", _sleep_val);
	((CMainFrame *)GetParentFrame())->setStatus(0, curval);
}

BOOL	STDCALL waitcycle() {
	AfxGetApp()->OnIdle(0);
	return TRUE;
}

BOOL	STDCALL CChildView::waitunit() {
	DWORD		tick = GetTickCount();

	if (IsChkWait) {
		::MessageBox(NULL, "按任意键继续", "等待按键", MB_OK);
	} else {
		while (tick - GetTickCount() <= _sleep_val) {
			waitcycle();
		}
	}

	return TRUE;
}

BOOL	STDCALL CChildView::draw(REAL slider, LPPOINT cp, INT ncp, DWORD dwParam) {
	CDC	*pDC	= (CDC *)dwParam;
	BOOL	bLine	= FALSE;
	int	i;

	pDC->Rectangle(D_X0 + 1, D_Y0 + 1, D_X0 + D_WIDTH - 1, D_Y0 + D_HEIGHT - 1);

	bLine	= ((CMainFrame *)AfxGetMainWnd())->getChkpixelorline();
	pDC->MoveTo(D_X0 + cp[0].x, D_Y0 + cp[0].y);
	for (i = 0; i < ncp; i++) {
		if (bLine) {
			pDC->LineTo(D_X0 + cp[i].x, D_Y0 + cp[i].y);
		} else {
			drawPixel(pDC, D_X0 + cp[i].x, D_Y0 + cp[i].y, 2, 0x0);
		}
	}
	if (bLine) pDC->LineTo(D_X0 + cp[0].x, D_Y0 + cp[0].y);

	waitunit();
	return TRUE;
}

BOOL	STDCALL drawPixel(CDC *pDC, int x, int y, REAL pradius, COLORREF c) {
	CPen	*pNewPen	= new CPen(PS_SOLID, 1, c);
	CPen	*pOldPen;
	pOldPen	= pDC->SelectObject(pNewPen);
	pDC->Ellipse(x - (INT)pradius, y - (INT)pradius, x + (INT)pradius, y + (INT)pradius);
	pDC->SelectObject(pOldPen);
	pNewPen->DeleteObject();
	return TRUE;
}

BOOL	STDCALL arrowLine(CDC *pDC, int x0, int y0, int x1, int y1, COLORREF c) {
	CPen	*pOldPen;
	CPen	*pNewPen	= new CPen(PS_SOLID, 1, c);
	pOldPen	= pDC->SelectObject(pNewPen);

	pDC->MoveTo(x0, y0);
	pDC->LineTo(x1, y1);

	const double trimlen = 10.0;
	const double rotangle = 0.45;
	double w = x1 - x0, h = y1 - y0;
	double L = sqrt(w * w + h * h);

	if (L > 1) {
		double tx = x1 + (x1 - x0) * trimlen / L;
		double ty = y1 + (y1 - y0) * trimlen / L;
		double a, a1, a2;
		a = atan2(-h, -w);
		a1 = a - rotangle, a2 = a + rotangle;
		w = tx - x1; h = ty - y1;
		L = sqrt(w * w + h * h);
		pDC->MoveTo(x1, y1);
		pDC->LineTo((INT)(x1 + L * cos(a1)), (INT)(y1 + L * sin(a1)));
		pDC->MoveTo(x1, y1);
		pDC->LineTo((INT)(x1 + L * cos(a2)), (INT)(y1 + L * sin(a2)));
	}

	pDC->SelectObject(pOldPen);
	pNewPen->DeleteObject();

	return TRUE;
}

BOOL	STDCALL setColor(CDC *pDC, COLORREF c) {
	CPen	*pNewPen	= new CPen(PS_SOLID, 1, c);
	return pDC->SelectObject(pNewPen)->DeleteObject();
}

BOOL	STDCALL setBackColor(CDC *pDC, COLORREF c) {
	CBrush	*pNewBrush	= new CBrush(c);
	return pDC->SelectObject(pNewBrush)->DeleteObject();
}

BOOL	STDCALL textOut(CDC *pDC, int tx, int ty, LPCTSTR pzText, COLORREF c) {
	CPen	*pOldPen;
	CPen	*pNewPen	= new CPen(PS_SOLID, 1, c);
	pOldPen	= pDC->SelectObject(pNewPen);
	pDC->TextOut(tx, ty, pzText, strlen(pzText));
	pDC->SelectObject(pOldPen);
	pNewPen->DeleteObject();
	return TRUE;
}

BOOL	STDCALL CChildView::chkrel(LPPOINTR rtSrc, INT nSrc, LPPOINTR rtDst, INT nDst, DWORD dwParam) {
	LPCPPACK	ppp	= (LPCPPACK)dwParam;
	CDC		*pDC	= ppp->pDC;
	int		i;
	LPPOINT		p1, p2;
	TCHAR		numbuf[64];

	textOut(pDC, 10, 10, "控制点变形", 0xAAAAAA);

	setBackColor(pDC, 0xFFFFFF);
	setColor(pDC, 0);
	pDC->Rectangle(D_X0 - 3, D_Y0 - 3, D_X1 + D_WIDTH + 3, D_Y0 + D_HEIGHT + 3);
		textOut(pDC, D_X0, D_Y0 - 25, "源控制点-->目标控制点", 0xAA0000);
	pDC->Rectangle(D_X0 - 1, D_Y0 - 1, D_X0 + D_WIDTH + 1, D_Y0 + D_HEIGHT + 1);
	pDC->Rectangle(D_X1 - 1, D_Y0 - 1, D_X1 + D_WIDTH + 1, D_Y0 + D_HEIGHT + 1);
	pDC->Rectangle(D_X0 - 3, D_Y1 - 3, D_X1 + D_WIDTH + 3, D_Y1 + D_HEIGHT + 3);
		textOut(pDC, D_X0, D_Y1 - 25, "源控制点<--目标控制点", 0xAA0000);
	pDC->Rectangle(D_X0 - 1, D_Y1 - 1, D_X0 + D_WIDTH + 1, D_Y1 + D_HEIGHT + 1);
	pDC->Rectangle(D_X1 - 1, D_Y1 - 1, D_X1 + D_WIDTH + 1, D_Y1 + D_HEIGHT + 1);

	for (i = 0; i < nSrc; i++) {
		p1	= ppp->cpSrc	+ rtSrc[i].ref;
		p2	= ppp->cpDst	+ rtSrc[i].obj;
		sprintf(numbuf, "%d", i);
		textOut(pDC, (D_X0 + p1->x + D_X1 + p2->x) / 2, (D_Y0 + p1->y + D_Y0 + p2->y) / 2, numbuf, 0x00AAAA);
		drawPixel(pDC, D_X0 + p1->x, D_Y0 + p1->y, 3, 0xFF0000);
		drawPixel(pDC, D_X1 + p2->x, D_Y0 + p2->y, 3, 0xFF0000);
		arrowLine(pDC, D_X0 + p1->x, D_Y0 + p1->y, D_X1 + p2->x, D_Y0 + p2->y, 0x00AA00);
	}
	for (i = 0; i < nDst; i++) {
		p1	= ppp->cpSrc	+ rtDst[i].obj;
		p2	= ppp->cpDst	+ rtDst[i].ref;
		sprintf(numbuf, "%d", i);
		textOut(pDC, (D_X0 + p1->x + D_X1 + p2->x) / 2, (D_Y1 + p1->y + D_Y1 + p2->y) / 2, numbuf, 0x00AAAA);
		drawPixel(pDC, D_X0 + p1->x, D_Y1 + p1->y, 3, 0xFF0000);
		drawPixel(pDC, D_X1 + p2->x, D_Y1 + p2->y, 3, 0xFF0000);
		arrowLine(pDC, D_X1 + p2->x, D_Y1 + p2->y, D_X0 + p1->x, D_Y1 + p1->y, 0x00AA00);
	}

	const COLORREF	CPP_COLOR	= 0x80AA80;
	setBackColor(pDC, CPP_COLOR);
	for (i = 0; i < ppp->nSrc; i++) {
		drawPixel(pDC, D_X0 + ppp->cpSrc[i].x, D_Y0 + ppp->cpSrc[i].y, 2, CPP_COLOR);
		drawPixel(pDC, D_X0 + ppp->cpSrc[i].x, D_Y1 + ppp->cpSrc[i].y, 2, CPP_COLOR);
	}
	for (i = 0; i < ppp->nDst; i++) {
		drawPixel(pDC, D_X1 + ppp->cpDst[i].x, D_Y0 + ppp->cpDst[i].y, 2, CPP_COLOR);
		drawPixel(pDC, D_X1 + ppp->cpDst[i].x, D_Y1 + ppp->cpDst[i].y, 2, CPP_COLOR);
	}
	setBackColor(pDC, 0xFFFFFF);

	waitunit();
	return TRUE;
}

void CChildView::OnButtonChkRes()
{
	// TODO: Add your command handler code here

}

void CChildView::OnButtonChkWait()
{
	// TODO: Add your command handler code here

}

void CChildView::OnButtonCls()
{
	// TODO: Add your command handler code here
	Invalidate();
}
