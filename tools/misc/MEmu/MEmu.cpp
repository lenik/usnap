// MEmu.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MEmu.h"
#include "MEmuDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMEmuApp

BEGIN_MESSAGE_MAP(CMEmuApp, CWinApp)
	//{{AFX_MSG_MAP(CMEmuApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMEmuApp construction

CMEmuApp::CMEmuApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMEmuApp object

CMEmuApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMEmuApp initialization

BOOL CMEmuApp::InitInstance()
{
	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CMEmuDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
