// SComp_Client.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "SComp_Client.h"
#include "SComp_ClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSComp_ClientApp

BEGIN_MESSAGE_MAP(CSComp_ClientApp, CWinApp)
	//{{AFX_MSG_MAP(CSComp_ClientApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSComp_ClientApp construction

CSComp_ClientApp::CSComp_ClientApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSComp_ClientApp object

CSComp_ClientApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CSComp_ClientApp initialization

BOOL CSComp_ClientApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CSComp_ClientDlg dlg;
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
