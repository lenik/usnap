// ProcessViewer01.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ProcessViewer01.h"

#include "MainFrm.h"
#include "ProcessViewer01Doc.h"
#include "ProcessViewer01View.h"

#include "ProcessDialog.h"
#include "ModuleDialog.h"
#include "ThreadDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProcessViewer01App

BEGIN_MESSAGE_MAP(CProcessViewer01App, CWinApp)
	//{{AFX_MSG_MAP(CProcessViewer01App)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_VMODULE, OnVmodule)
	ON_COMMAND(ID_VPROCESS, OnVprocess)
	ON_COMMAND(ID_VTHREAD, OnVthread)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProcessViewer01App construction

CProcessViewer01App::CProcessViewer01App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CProcessViewer01App object

CProcessViewer01App theApp;

/////////////////////////////////////////////////////////////////////////////
// CProcessViewer01App initialization

BOOL CProcessViewer01App::InitInstance()
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

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CProcessViewer01Doc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CProcessViewer01View));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CProcessViewer01App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CProcessViewer01App message handlers


void CProcessViewer01App::OnVmodule()
{
	// TODO: Add your command handler code here
	CModuleDialog moduleDialog;
	moduleDialog.DoModal();
}

void CProcessViewer01App::OnVprocess()
{
	// TODO: Add your command handler code here
	CProcessDialog processDialog;
	processDialog.DoModal();
}

void CProcessViewer01App::OnVthread()
{
	// TODO: Add your command handler code here
	CThreadDialog threadDialog;
	threadDialog.DoModal();
}

BOOL CALLBACK
EnumProcessListFunc( HWND hWnd, LPARAM lParam )
{
  static DWORD dwCurrentProcessId;
  static BOOL  fFirstTime = TRUE;
  static LONG  MaxStrLen  = 0;
  static TCHAR TextBuffer[256];

  CComboBox *cb = (CComboBox *)GetDlgItem((HWND)lParam, IDC_PLIST);

  if( fFirstTime ) {
    fFirstTime = FALSE;
    dwCurrentProcessId = GetCurrentProcessId();
  }

  if( hWnd ) {
    GetWindowText( hWnd, (LPTSTR) &TextBuffer, sizeof(TextBuffer) );
    if( *TextBuffer ) {
      DWORD  dwProcessId;

      GetWindowThreadProcessId( hWnd, &dwProcessId );
      if( dwProcessId != dwCurrentProcessId ) {
        LONG Index;
        HWND hWndListBox = (HWND) lParam;

        Index = ListBoxInsert( hWndListBox, &MaxStrLen, TextBuffer );
        SendMessage( hWndListBox, LB_SETITEMDATA, (WPARAM) Index,
          (LPARAM) dwProcessId );
      }
    }
  }

  return( TRUE );
}

int GetProcessList(CListBox *lb) {
	// TODO: Add your control notification handler code here
	HANDLE hSnapshot;
	PROCESSENTRY32 pe;
	char strProcessTitle[256];

	hSnapshot = CreateToolhelp32Snapshot(
		TH32CS_SNAPPROCESS,
		0);
	if (hSnapshot == NULL) {
		lb->MessageBox("刷新进程出错!", NULL, MB_OK);
	} else {
		if (Process32First(hSnapshot, &pe)) {
			int n = lb->GetCount();
			while (n > 0) n = lb->DeleteString(0);

			do {
				wsprintf(strProcessTitle, "%X %s", pe.th32ProcessID, pe.szExeFile);
				lb->AddString(strProcessTitle);
			} while (Process32Next(hSnapshot, &pe));
		}
	}
	CloseHandle(hSnapshot);
	return 0;
}

int GetProcessList(CComboBox *lb) {
	// TODO: Add your control notification handler code here
	HANDLE hSnapshot;
	PROCESSENTRY32 pe;
	char strProcessTitle[256];

	hSnapshot = CreateToolhelp32Snapshot(
		TH32CS_SNAPPROCESS,
		0);
	if (hSnapshot == NULL) {
		lb->MessageBox("刷新进程出错!", NULL, MB_OK);
	} else {
		if (Process32First(hSnapshot, &pe)) {
			int n = lb->GetCount();
			while (n > 0) n = lb->DeleteString(0);

			do {
				wsprintf(strProcessTitle, "0x%X %s", pe.th32ProcessID, pe.szExeFile);
				lb->AddString(strProcessTitle);
			} while (Process32Next(hSnapshot, &pe));
		}
	}
	CloseHandle(hSnapshot);
	return 0;
}

int GetModuleList(CListBox *lb, DWORD idProcess) {
	// TODO: Add your control notification handler code here
	HANDLE hSnapshot;
	MODULEENTRY32 me;
	char strModuleTitle[256];

	hSnapshot = CreateToolhelp32Snapshot(
		TH32CS_SNAPMODULE,
		idProcess);
	if (hSnapshot == NULL) {
		::MessageBox(NULL, "刷新进程出错! ", NULL, MB_OK);
	} else {
		if (Module32First(hSnapshot, &me)) {
			int n = lb->GetCount();
			while (n > 0) n = lb->DeleteString(0);
			do {
				wsprintf(strModuleTitle, "0x%X/%X-%X %s %s", me.th32ModuleID, me.modBaseAddr, me.modBaseSize, me.szModule, me.szExePath);
				lb->AddString(strModuleTitle);
			} while (Module32Next(hSnapshot, &me));
		}
	}
	CloseHandle(hSnapshot);
	return 0;
}
