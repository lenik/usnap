// whello.cpp : Defines the entry point for the application.
//

/*
#include <afxwin.h>

class CHelloWnd : public CFrameWnd {

};

class CHelloApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};

BOOL CHelloApp::InstInstance() {
	m_pMainWnd = new CHelloWnd();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CHelloApp helloApp;
*/


#include <afxwin.h>

// Define a window class derived from CFrameWnd
class CHelloWindow : public CFrameWnd
{
public:
	//CHelloWindow() { Create(NULL, _T("Hello World!"), WS_OVERLAPPEDWINDOW, rectDefault); }
};

// Define an application class derived from CWinApp
class CHelloApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

// Construct the CHelloApp's m_pMainWnd data member
BOOL CHelloApp::InitInstance()
{
	m_pMainWnd = new CHelloWindow();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CHelloApp HelloApp;  // HelloApp's constructor initializes and runs the app
