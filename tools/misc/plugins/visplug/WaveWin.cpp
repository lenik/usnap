// WaveWin.cpp: implementation of the CWaveWin class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WaveWin.h"
#include "HeroMp3Vis.h"

#define INI_VISDEMO_APPNAME1 "visdemo1"

extern HeroMp3VisModule visModule;


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWaveWin::CWaveWin()
{
	winRect.SetRect(0,0,200,200);
	m_bClosed=TRUE;
}

CWaveWin::~CWaveWin()
{

}

BEGIN_MESSAGE_MAP(CWaveWin, CWnd)
	//{{AFX_MSG_MAP(CWaveWin)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_CLOSE()
	ON_WM_MOVE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CWaveWin::Create(const CString& title,int icon)
{
	CString sClassName;

	sClassName = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW,LoadCursor(0, IDC_ARROW),
			NULL, LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(icon)));
	return CWnd::CreateEx(WS_EX_TOOLWINDOW, sClassName, title, WS_POPUPWINDOW|WS_CAPTION|WS_SIZEBOX,winRect,0,0 );
}

int CWaveWin::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here
	m_nTimerID = this->SetTimer(TIMER_ID, TIMER_ELAPSE, NULL);
	m_bClosed=FALSE;

	return 0;
}

void CWaveWin::OnTimer(UINT nIDEvent)
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
	MoveToEx(clientDC,1,128*sy,NULL);
	for (int x = 0; x < DATA_SIZE; x++)
		LineTo(clientDC,x*sx,(visModule.waveformData[0][x]^128)*sy);

}

void CWaveWin::OnDestroy()
{
	CWnd::OnDestroy();

	// TODO: Add your message handler code here
	if (m_nTimerID != 0)
	{
		this->KillTimer(m_nTimerID);
		m_nTimerID = 0;
	}
}

void CWaveWin::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	m_bClosed=TRUE;
	CWnd::OnClose();
}

void CWaveWin::OnMove(int x, int y)
{
	CWnd::OnMove(x, y);

	// TODO: Add your message handler code here
	this->GetWindowRect(winRect);
}

void CWaveWin::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	this->GetWindowRect(winRect);
}


void CWaveWin::WriteIni(LPCSTR iniFilename)
{
	CString string;
	string.Format("%ld",winRect.left);
	WritePrivateProfileString(INI_VISDEMO_APPNAME1,"left",string,iniFilename);
	string.Format("%ld",winRect.top);
	WritePrivateProfileString(INI_VISDEMO_APPNAME1,"top",string,iniFilename);
	string.Format("%ld",winRect.right);
	WritePrivateProfileString(INI_VISDEMO_APPNAME1,"right",string,iniFilename);
	string.Format("%ld",winRect.bottom);
	WritePrivateProfileString(INI_VISDEMO_APPNAME1,"bottom",string,iniFilename);
}

void CWaveWin::ReadIni(LPCSTR iniFilename)
{
	winRect.left   = GetPrivateProfileInt(INI_VISDEMO_APPNAME1,"left",winRect.left,iniFilename);
	winRect.top    = GetPrivateProfileInt(INI_VISDEMO_APPNAME1,"top",winRect.top,iniFilename);
	winRect.right  = GetPrivateProfileInt(INI_VISDEMO_APPNAME1,"right",winRect.right,iniFilename);
	winRect.bottom = GetPrivateProfileInt(INI_VISDEMO_APPNAME1,"bottom",winRect.bottom,iniFilename);
}
