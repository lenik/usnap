// Joystick.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Joystick.h"
#include "JoystickDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJoystickApp

BEGIN_MESSAGE_MAP(CJoystickApp, CWinApp)
	//{{AFX_MSG_MAP(CJoystickApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJoystickApp construction

CJoystickApp::CJoystickApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	this->wNumDevs = 0;
	this->wDeviceID = 0;
	this->bDev1Attached = this->bDev2Attached = FALSE;
	app = this;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CJoystickApp object

CJoystickApp theApp, *app;

/////////////////////////////////////////////////////////////////////////////
// CJoystickApp initialization

BOOL CJoystickApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CJoystickDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

BOOL CJoystickApp::InitApplication()
{
	// TODO: Add your specialized code here and/or call the base class
	if (this->InitJoystick() == MMSYSERR_NODRIVER) {
		MessageBox(NULL, "没有找到手柄或没有安装驱动程序 ", "初始化错误", MB_OK);
		PostQuitMessage(0);
	}
	if (this->CapsJoystick() != JOYERR_NOERROR) {
		MessageBox(NULL, "检查手柄时发生错误, 可能是没有连接好", "检查错误", MB_OK);
		PostQuitMessage(0);
	}
	app = this;
	return CWinApp::InitApplication();
}

MMRESULT CJoystickApp::InitJoystick() {
	if ((this->wNumDevs = joyGetNumDevs()) == 0) {
		return MMSYSERR_NODRIVER;
	}
	this->bDev1Attached = joyGetPos(JOYSTICKID1, &this->joyinfo) != JOYERR_UNPLUGGED;
	if (this->wNumDevs > 1) {
		this->bDev2Attached = joyGetPos(JOYSTICKID2, &this->joyinfo) != JOYERR_UNPLUGGED;
	}
	if (this->bDev1Attached || this->bDev2Attached) {
		this->wDeviceID = this->bDev1Attached ? JOYSTICKID1 : JOYSTICKID2;
	} else {
		return MMSYSERR_NODRIVER;
	}
	return JOYERR_NOERROR;
}

MMRESULT CJoystickApp::CapsJoystick() {
	MMRESULT mmr;
	mmr = joyGetDevCaps(this->wDeviceID, &joycaps, sizeof(joycaps));
	if (mmr == JOYERR_NOERROR) {
		char desc[1024];
		sprintf(desc, "\
生产商    = %hd         产品号    = %hd\n\
手柄名称  = %s\n\
X轴范围   = %d .. %d      R值 = %d .. %d\n\
Y轴范围   = %d .. %d      U值 = %d .. %d\n\
Z轴范围   = %d .. %d      V值 = %d .. %d\n\
时期      = %d .. %d\n\
按钮数目  = %d          性能字 = %XH\n\
最大坐标  = %d          坐标数 = %d\n\
最大按钮数= %d\n\
注册      = %s\n\
OEM驱动程序号为 %s",
			joycaps.wMid, joycaps.wPid,
			joycaps.szPname,
			joycaps.wXmin, joycaps.wXmax, joycaps.wRmin, joycaps.wRmax,
			joycaps.wYmin, joycaps.wYmax, joycaps.wUmin, joycaps.wUmax,
			joycaps.wZmin, joycaps.wZmax, joycaps.wVmin, joycaps.wVmax,
			joycaps.wPeriodMin, joycaps.wPeriodMax,
			joycaps.wNumButtons, joycaps.wCaps,
			joycaps.wMaxAxes, joycaps.wNumAxes,
			joycaps.wMaxButtons,
			joycaps.szRegKey,
			joycaps.szOEMVxD
		);
	MessageBox(NULL, desc, "手柄信息", MB_OK);
	}
	return mmr;
}
