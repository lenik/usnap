// SpecWin.cpp: implementation of the CSpecWin class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SpecWin.h"
#include "HeroMp3Vis.h"

#define INI_VISDEMO_APPNAME "visdemo"

extern HeroMp3VisModule visModule;


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSpecWin::CSpecWin()
{
	winRect.SetRect(0,0,200,200);
	m_bClosed=TRUE;
}

CSpecWin::~CSpecWin()
{

}

BEGIN_MESSAGE_MAP(CSpecWin, CWnd)
	//{{AFX_MSG_MAP(CSpecWin)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_CLOSE()
	ON_WM_MOVE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CSpecWin::Create(const CString& title,int icon)
{
	CString sClassName;

	sClassName = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW,LoadCursor(0, IDC_ARROW),
			NULL, LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(icon)));
	return CWnd::CreateEx(WS_EX_TOOLWINDOW, sClassName, title, WS_POPUPWINDOW|WS_CAPTION|WS_SIZEBOX,winRect,0,0 );
}

int CSpecWin::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here
	m_nTimerID = this->SetTimer(TIMER_ID, TIMER_ELAPSE, NULL);
	m_bClosed=FALSE;

	return 0;
}

void CSpecWin::OnTimer(UINT nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	ASSERT(nIDEvent == m_nTimerID && nIDEvent == TIMER_ID);
	visModule.GetVisData();

	CClientDC clientDC(this);
	CRect clientRect;
	this->GetClientRect(clientRect);

	clientDC.Rectangle(clientRect);
	float sx = (float)clientRect.Width()/DATA_SIZE;
	float sy = (float)clientRect.Height()/256;
	int h=clientRect.Height();
	for (int x = 0; x<DATA_SIZE; x++) {
		MoveToEx(clientDC,x*sx,h,NULL);
		LineTo(clientDC,x*sx,h-visModule.spectrumData[0][x]*sy);
	}
}

void CSpecWin::OnDestroy()
{
	CWnd::OnDestroy();

	// TODO: Add your message handler code here
	if (m_nTimerID != 0)
	{
		this->KillTimer(m_nTimerID);
		m_nTimerID = 0;
	}
}

void CSpecWin::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	m_bClosed=TRUE;
	CWnd::OnClose();
}

void CSpecWin::OnMove(int x, int y)
{
	CWnd::OnMove(x, y);

	// TODO: Add your message handler code here
	this->GetWindowRect(winRect);
}

void CSpecWin::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	this->GetWindowRect(winRect);
}


void CSpecWin::WriteIni(LPCSTR iniFilename)
{
	CString string;
	string.Format("%ld",winRect.left);
	WritePrivateProfileString(INI_VISDEMO_APPNAME,"left",string,iniFilename);
	string.Format("%ld",winRect.top);
	WritePrivateProfileString(INI_VISDEMO_APPNAME,"top",string,iniFilename);
	string.Format("%ld",winRect.right);
	WritePrivateProfileString(INI_VISDEMO_APPNAME,"right",string,iniFilename);
	string.Format("%ld",winRect.bottom);
	WritePrivateProfileString(INI_VISDEMO_APPNAME,"bottom",string,iniFilename);
}

void CSpecWin::ReadIni(LPCSTR iniFilename)
{
	winRect.left   = GetPrivateProfileInt(INI_VISDEMO_APPNAME,"left",winRect.left,iniFilename);
	winRect.top    = GetPrivateProfileInt(INI_VISDEMO_APPNAME,"top",winRect.top,iniFilename);
	winRect.right  = GetPrivateProfileInt(INI_VISDEMO_APPNAME,"right",winRect.right,iniFilename);
	winRect.bottom = GetPrivateProfileInt(INI_VISDEMO_APPNAME,"bottom",winRect.bottom,iniFilename);
}
