// WMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WM.h"
#include "WMDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

typedef VOID (CALLBACK *SHOWINGPROC)(LPARAM);

BOOL CALLBACK SetShowingProc(SHOWINGPROC spKey, SHOWINGPROC spMouse, SHOWINGPROC spGetMsg);
BOOL CALLBACK Start();
BOOL CALLBACK Stop();

VOID CALLBACK WMShowingProcKey(LPARAM lp) {
	CWMDlg *pdlg = (CWMDlg *)::AfxGetApp()->m_pMainWnd;
	pdlg->m_i1.Format("%s", (LPSTR)lp);
	pdlg->UpdateData(FALSE);

	CString s;
	static int WMcounter = 0;
	s.Format("%4d: %s", WMcounter++, lp);
	pdlg->m_lstKeys.InsertString(0, s);
	while (pdlg->m_lstKeys.GetCount() > 100) {
		pdlg->m_lstKeys.DeleteString(100);
	}
}

VOID CALLBACK WMShowingProcMouse(LPARAM lp) {
	CWMDlg *pdlg = (CWMDlg *)::AfxGetApp()->m_pMainWnd;
	pdlg->m_i2.Format("%s", (LPSTR)lp);
	pdlg->UpdateData(FALSE);
}

VOID CALLBACK WMShowingProcGetMsg(LPARAM lp) {
	CWMDlg *pdlg = (CWMDlg *)::AfxGetApp()->m_pMainWnd;
	pdlg->m_i3.Format("%s", (LPSTR)lp);
	pdlg->UpdateData(FALSE);
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
// CWMDlg dialog

CWMDlg::CWMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWMDlg)
	m_i1 = _T("");
	m_i2 = _T("");
	m_i3 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWMDlg)
	DDX_Control(pDX, IDC_LIST_KEYS, m_lstKeys);
	DDX_Text(pDX, IDC_STATIC_I1, m_i1);
	DDX_Text(pDX, IDC_STATIC_I2, m_i2);
	DDX_Text(pDX, IDC_STATIC_I3, m_i3);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWMDlg, CDialog)
	//{{AFX_MSG_MAP(CWMDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWMDlg message handlers

BOOL CWMDlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWMDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWMDlg::OnPaint()
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
HCURSOR CWMDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWMDlg::OnOK()
{
	// TODO: Add extra validation here

	CDialog::OnOK();
}

void CWMDlg::OnCancel()
{
	// TODO: Add extra cleanup here

	CDialog::OnCancel();
}

void CWMDlg::OnButtonStart()
{
	// TODO: Add your control notification handler code here
	Start();
}

int CWMDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	SetShowingProc(
		&::WMShowingProcKey,	// key
		&::WMShowingProcMouse,	// mouse
		&::WMShowingProcGetMsg	// getmsg
		);

	return 0;
}

void CWMDlg::OnButtonStop()
{
	// TODO: Add your control notification handler code here
	Stop();
}
