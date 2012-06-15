#include "stdafx.h"

#include "t01.h"
#include "t01mf.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CT01App::CT01App() { }

CT01App theApp;

BOOL CT01App::InitInstance() {
        SetRegistryKey(_T("Local AppWizard-Generated Applications"));

        CMainFrame* pFrame = new CMainFrame;
	m_pMainWnd = pFrame;

	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);

	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();

        return TRUE;
}

class CAboutDlg :: public CDialog {
