// clipbrdViewerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "clipbrdViewer.h"
#include "clipbrdViewerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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

/////////////////////////////////////////////////////////////////////////////
// CClipbrdViewerDlg dialog

CClipbrdViewerDlg::CClipbrdViewerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClipbrdViewerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClipbrdViewerDlg)
	m_strAvail = _T("");
	m_strIsStatic = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClipbrdViewerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClipbrdViewerDlg)
	DDX_Text(pDX, IDC_STATIC_AVAILABLE, m_strAvail);
	DDX_Text(pDX, IDC_STATIC_ISSTATIC, m_strIsStatic);
	DDX_Control(pDX, IDC_SLIDER_REFRESH, m_sliderRefresh);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClipbrdViewerDlg, CDialog)
	//{{AFX_MSG_MAP(CClipbrdViewerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClipbrdViewerDlg message handlers

BOOL CClipbrdViewerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	pSysMenu	= GetSystemMenu(FALSE);
	if (pSysMenu != NULL) {
		CString strHelloWorld;
		strHelloWorld	= "Hello, world!\n";
		pSysMenu->AppendMenu(MF_SEPARATOR | MF_MENUBARBREAK);
		pSysMenu->AppendMenu(MF_STRING, IDM_HELLOWORLD, strHelloWorld);
	}

	UINT	r;
	r	= SetTimer(IDT_MAINTIMER, m_sliderRefresh.GetValue() * 10, NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClipbrdViewerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CClipbrdViewerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CClipbrdViewerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CClipbrdViewerDlg::OnTimer(UINT nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	HRESULT		hr;
	IDataObject	*pdo;
	static int	ii;
	char		*iis = "-\\|/";

	hr	= OleGetClipboard(&pdo);
	if (SUCCEEDED(hr)) {
		m_strAvail	= " Clipboard Available. ";
		hr	= OleQueryCreateFromData(pdo);
		if (hr & OLE_S_STATIC) {
			m_strIsStatic	= "the data IS static. ";
		} else {
			m_strIsStatic	= "the data IS NOT static. ";
		}
		pdo->Release();
	} else {
		m_strAvail	= " No available data in clipboard. ";
	}

	ii++;
	m_strAvail.SetAt(0, (TCHAR)iis[ii % 4]);

	UpdateData(FALSE);
	CDialog::OnTimer(nIDEvent);

}

BEGIN_EVENTSINK_MAP(CClipbrdViewerDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CClipbrdViewerDlg)
	ON_EVENT(CClipbrdViewerDlg, IDC_SLIDER_REFRESH, 2 /* Change */, OnChangeSliderRefresh, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CClipbrdViewerDlg::OnChangeSliderRefresh()
{
	// TODO: Add your control notification handler code here
	SetTimer(IDT_MAINTIMER, m_sliderRefresh.GetValue() * 10, NULL);
}
