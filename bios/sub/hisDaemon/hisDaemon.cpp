// hisDaemon.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "hisDaemon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHisDaemonApp

BEGIN_MESSAGE_MAP(CHisDaemonApp, CWinApp)
	//{{AFX_MSG_MAP(CHisDaemonApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHisDaemonApp construction

CHisDaemonApp::CHisDaemonApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CHisDaemonApp object

CHisDaemonApp theApp;

BOOL CHisDaemonApp::InitInstance()
{
	// TODO: Add your specialized code here and/or call the base class
	m_main.Create(IDD_DIALOG_MAIN);
	m_main.ShowWindow(SW_NORMAL);
	BOOL r = CWinApp::InitInstance();
	return r;
}

BOOL CHisDaemonApp::InitApplication()
{
	// TODO: Add your specialized code here and/or call the base class
//	m_main.ShowWindow(SW_NORMAL);
	return CWinApp::InitApplication();
}
