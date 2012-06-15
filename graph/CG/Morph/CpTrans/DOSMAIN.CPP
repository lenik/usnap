
#include "stdafx.h"
#include "CpTrans.h"
#include "CpTransI.h"
#include "CpTran~1.h"

#define CDC			void
#define COLORREF		int

#define CIRCLE_PIXELS		16
#define DEFAULT_SAMPLE		0.01

struct CPPACK {
	LPPOINT		cpSrc;
	INT		nSrc;
	LPPOINT		cpDst;
	INT		nDst;
	CDC		*pDC;
};
typedef struct CPPACK	*PCPPACK, *LPCPPACK;

POINT	cpLine[2];
POINT	cpRect[4];
POINT	cpCircle[CIRCLE_PIXELS];
INT	lastOp;

static REAL _sleep_val		= 10;

static	BOOL STDCALL setStatus(int, LPCTSTR);

static	BOOL bChkres		= FALSE;
static	BOOL bChkwait		= FALSE;
static	BOOL bChkpixelorline	= FALSE;
static	BOOL bChkprecise	= FALSE;

void	STDCALL initData();
void	STDCALL switchTo(INT);

static BOOL STDCALL waitunit();
static BOOL STDCALL draw(REAL, LPPOINT, INT, DWORD);
static BOOL STDCALL chkrel(LPPOINTR, INT, LPPOINTR, INT, DWORD);
static BOOL STDCALL redrawStatus();

BOOL	STDCALL drawPixel(CDC *, int, int, REAL, COLORREF);
BOOL	STDCALL arrowLine(CDC *, int, int, int, int, COLORREF);
BOOL	STDCALL setColor(CDC *, COLORREF);
BOOL	STDCALL setBackColor(CDC *, COLORREF);
BOOL	STDCALL textOut(CDC *, int, int, LPCTSTR, COLORREF);

BOOL	STDCALL waitcycle();

const	int	D_WIDTH			= 100;
const	int	D_HEIGHT		= 100;

const	int	D_X0			= 80;
const	int	D_Y0			= 60;

const	int	D_X1			= D_X0 + 50 + D_WIDTH;
const	int	D_Y1			= D_Y0 + 40 + D_HEIGHT;

void initScreen() {
	int	gd = VGA, gm = VGAHI;
	registerfarbgidriver(EGAVGA_driver_far);
	registerfarbgifont(triplex_font_far);

	initgraph(&gd, &gm, "");
	setbkcolor(WHITE);
	cleardevice();
}

void closeScreen() {
	closegraph();
}

void STDCALL initData() {
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

void 	STDCALL switchTo(INT i) {
	CPPACK		cpp;
	CPREFERPROC	referProc	= bChkprecise ? cp_refer : cp_refer_easy;
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

	if (bChkres) {
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
			draw, (DWORD)0,
			NULL, 0,
			FALSE,
			referProc);
	}

	lastOp	= i;
}

void OnSpeedFast()
{
	// TODO: Add your command handler code here
	char curval[20];
	if (_sleep_val > 0) _sleep_val--;
	sprintf(curval, "当前速度 = %3.0f", _sleep_val);
	setStatus(0, curval);
}

void OnSpeedSlow()
{
	// TODO: Add your command handler code here
	char curval[20];
	if (_sleep_val < 100) _sleep_val++;
	sprintf(curval, "当前速度 = %3.0lf", _sleep_val);
	setStatus(0, curval);
}

BOOL	STDCALL waitcycle() {
	return TRUE;
}

BOOL	STDCALL waitunit() {
	if (bChkwait) {
		textsettingstype	oldtext;
		gettextsettings(&oldtext);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
		textOut(NULL, 400, 300, "Press", BLUE);
		textOut(NULL, 420, 350, "Key", BLUE);
		while (getch() == 0);
		settextstyle(DEFAULT_FONT, oldtext.direction, oldtext.charsize);
		bar(400, 300, 600, 400);
	} else {
		delay(_sleep_val);
	}

	return TRUE;
}

BOOL	STDCALL draw(REAL slider, LPPOINT cp, INT ncp, DWORD dwParam) {
	CDC	*pDC	= NULL;
	int	oc	= getcolor();
	BOOL	bLine	= FALSE;
	int	i;

	bar(D_X0 + 1, D_Y0 + 1, D_X0 + D_WIDTH - 1, D_Y0 + D_HEIGHT - 1);

	setcolor(BLUE);

	bLine	= bChkpixelorline;
	moveto(D_X0 + cp[0].x, D_Y0 + cp[0].y);
	for (i = 0; i < ncp; i++) {
		if (bLine) {
			lineto(D_X0 + cp[i].x, D_Y0 + cp[i].y);
		} else {
			drawPixel(pDC, D_X0 + cp[i].x, D_Y0 + cp[i].y, 2, BLUE);
		}
	}
	if (bLine) lineto(D_X0 + cp[0].x, D_Y0 + cp[0].y);

	setcolor(oc);
	waitunit();
	return TRUE;
}

BOOL	STDCALL drawPixel(CDC *pDC, int x, int y, REAL pradius, COLORREF c) {
	int	oc = getcolor();
	setcolor(c);
	fillellipse(x, y, pradius, pradius);
	setcolor(oc);
	return TRUE;
}

BOOL	STDCALL arrowLine(CDC *pDC, int x0, int y0, int x1, int y1, COLORREF c) {
	int	oc = getcolor();
	setcolor(c);
	moveto(x0, y0);
	lineto(x1, y1);

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
		moveto(x1, y1);
		lineto((INT)(x1 + L * cos(a1)), (INT)(y1 + L * sin(a1)));
		moveto(x1, y1);
		lineto((INT)(x1 + L * cos(a2)), (INT)(y1 + L * sin(a2)));
	}
	setcolor(oc);
	return TRUE;
}

BOOL	STDCALL setColor(CDC *pDC, COLORREF c) {
	setcolor(c);
	return TRUE;
}

BOOL	STDCALL setBackColor(CDC *pDC, COLORREF c) {
	setfillstyle(SOLID_FILL, c);
	return TRUE;
}

BOOL	STDCALL textOut(CDC *pDC, int tx, int ty, LPCTSTR pzText, COLORREF c) {
	int	oc = getcolor();
	setcolor(c);
	outtextxy(tx, ty, pzText);
	setcolor(oc);
	return TRUE;
}

BOOL	STDCALL chkrel(LPPOINTR rtSrc, INT nSrc, LPPOINTR rtDst, INT nDst, DWORD dwParam) {
	LPCPPACK	ppp	= (LPCPPACK)dwParam;
	CDC		*pDC	= ppp->pDC;
	int		i;
	LPPOINT		p1, p2;
	TCHAR		numbuf[64];

	textOut(pDC, 10, 10, "Control Points Translation Demonstrate", BLUE);

	setBackColor(pDC, 15);
	setColor(pDC, BLACK);
	bar(D_X0 - 3, D_Y0 - 3, D_X1 + D_WIDTH + 3, D_Y0 + D_HEIGHT + 3);
		textOut(pDC, D_X0, D_Y0 - 25, "Source-->Dest", BLUE);
	bar(D_X0 - 1, D_Y0 - 1, D_X0 + D_WIDTH + 1, D_Y0 + D_HEIGHT + 1);
	bar(D_X1 - 1, D_Y0 - 1, D_X1 + D_WIDTH + 1, D_Y0 + D_HEIGHT + 1);
	bar(D_X0 - 3, D_Y1 - 3, D_X1 + D_WIDTH + 3, D_Y1 + D_HEIGHT + 3);
		textOut(pDC, D_X0, D_Y1 - 25, "Source<--Dest", BLUE);
	bar(D_X0 - 1, D_Y1 - 1, D_X0 + D_WIDTH + 1, D_Y1 + D_HEIGHT + 1);
	bar(D_X1 - 1, D_Y1 - 1, D_X1 + D_WIDTH + 1, D_Y1 + D_HEIGHT + 1);

	for (i = 0; i < nSrc; i++) {
		p1	= ppp->cpSrc	+ rtSrc[i].ref;
		p2	= ppp->cpDst	+ rtSrc[i].obj;
		sprintf(numbuf, "%d", i);
		textOut(pDC, (D_X0 + p1->x + D_X1 + p2->x) / 2, (D_Y0 + p1->y + D_Y0 + p2->y) / 2, numbuf, BLUE);
		drawPixel(pDC, D_X0 + p1->x, D_Y0 + p1->y, 3, BLUE);
		drawPixel(pDC, D_X1 + p2->x, D_Y0 + p2->y, 3, BLUE);
		arrowLine(pDC, D_X0 + p1->x, D_Y0 + p1->y, D_X1 + p2->x, D_Y0 + p2->y, GREEN);
	}
	for (i = 0; i < nDst; i++) {
		p1	= ppp->cpSrc	+ rtDst[i].obj;
		p2	= ppp->cpDst	+ rtDst[i].ref;
		sprintf(numbuf, "%d", i);
		textOut(pDC, (D_X0 + p1->x + D_X1 + p2->x) / 2, (D_Y1 + p1->y + D_Y1 + p2->y) / 2, numbuf, BLUE);
		drawPixel(pDC, D_X0 + p1->x, D_Y1 + p1->y, 3, BLUE);
		drawPixel(pDC, D_X1 + p2->x, D_Y1 + p2->y, 3, BLUE);
		arrowLine(pDC, D_X1 + p2->x, D_Y1 + p2->y, D_X0 + p1->x, D_Y1 + p1->y, GREEN);
	}

	const COLORREF	CPP_COLOR	= GREEN;
	setBackColor(pDC, CPP_COLOR);
	for (i = 0; i < ppp->nSrc; i++) {
		drawPixel(pDC, D_X0 + ppp->cpSrc[i].x, D_Y0 + ppp->cpSrc[i].y, 2, CPP_COLOR);
		drawPixel(pDC, D_X0 + ppp->cpSrc[i].x, D_Y1 + ppp->cpSrc[i].y, 2, CPP_COLOR);
	}
	for (i = 0; i < ppp->nDst; i++) {
		drawPixel(pDC, D_X1 + ppp->cpDst[i].x, D_Y0 + ppp->cpDst[i].y, 2, CPP_COLOR);
		drawPixel(pDC, D_X1 + ppp->cpDst[i].x, D_Y1 + ppp->cpDst[i].y, 2, CPP_COLOR);
	}
	setBackColor(pDC, 15);

	waitunit();
	return TRUE;
}

BOOL 	STDCALL setStatus(int pane, LPCTSTR str) {
	pane	= pane;
	textOut(NULL, 10, 440, str, WHITE);
	return TRUE;
}

BOOL	STDCALL redrawStatus() {
	const int COLOR_CMD	= BLUE;
	const int COLOR_HINT	= LIGHTBLUE;
	const int B_Y1		= 0;
	const int B_Y2		= 340;
	TCHAR sbuf[128];

	cleardevice();

	textOut(NULL, 400, B_Y1 + 20, 	"L   line", COLOR_CMD);
	textOut(NULL, 400, B_Y1 + 40, 	"R   rectangle", COLOR_CMD);
	textOut(NULL, 400, B_Y1 + 60, 	"C   circle", COLOR_CMD);
	textOut(NULL, 400, B_Y1 + 80, 	"<   slow", COLOR_CMD);
	textOut(NULL, 400, B_Y1 + 100, 	">   fast", COLOR_CMD);
	textOut(NULL, 400, B_Y1 + 120, 	"-   lined", COLOR_CMD);
	textOut(NULL, 400, B_Y1 + 140, 	".   dotted", COLOR_CMD);
	textOut(NULL, 400, B_Y1 + 160, 	"W   wait key", COLOR_CMD);
	textOut(NULL, 400, B_Y1 + 180, 	"D   debug mode", COLOR_CMD);
	textOut(NULL, 400, B_Y1 + 200, 	"P   precise mode", COLOR_CMD);
	textOut(NULL, 400, B_Y1 + 220, 	"----------------", 0);
	textOut(NULL, 400, B_Y1 + 240, 	"ESC quit program", COLOR_CMD);

	sprintf(sbuf, "current speed: %lf", _sleep_val);
	textOut(NULL, 100, B_Y2 + 0, sbuf, COLOR_HINT);
	sprintf(sbuf, "current draw mode: %s", bChkpixelorline ? "LINE" : "PIXEL");
	textOut(NULL, 100, B_Y2 + 20, sbuf, COLOR_HINT);
	sprintf(sbuf, "use waiting key: %s", bChkwait ? "YES" : "NO");
	textOut(NULL, 100, B_Y2 + 40, sbuf, COLOR_HINT);
	sprintf(sbuf, "release or debug: %s mode", bChkres ? "DEBUG" : "RELEASE");
	textOut(NULL, 100, B_Y2 + 60, sbuf, COLOR_HINT);
	sprintf(sbuf, "current algorithm selected: %s", bChkprecise ? "PRECISE" : "SIMPLE EASY");
	textOut(NULL, 100, B_Y2 + 80, sbuf, COLOR_HINT);

	return TRUE;
}

void main() {
	initData();
	initScreen();

	int k, quit = 0;
	redrawStatus();
	while (!quit) {
		k = getch();
		switch (toupper(k)) {
		case 'L':
			switchTo('l');
			break;
		case 'R':
			switchTo('r');
			break;
		case 'C':
			switchTo('c');
			break;
		case 'W':
			bChkwait	= 1 - bChkwait;
			redrawStatus();
			break;
		case 'D':
			bChkres		= 1 - bChkres;
			redrawStatus();
			break;
		case 'P':
			bChkprecise	= 1 - bChkprecise;
			redrawStatus();
			break;
		case '-':
			bChkpixelorline	= TRUE;
			redrawStatus();
			break;
		case '.':
			bChkpixelorline	= FALSE;
			redrawStatus();
			break;
		case '<':
			OnSpeedSlow();
			redrawStatus();
			break;
		case '>':
			OnSpeedFast();
			redrawStatus();
			break;
		case 27:
			quit = 1;
			break;
		}
	}
	closegraph();
}
