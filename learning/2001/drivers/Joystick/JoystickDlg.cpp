// JoystickDlg.cpp : implementation file
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
// CJoystickDlg dialog

CJoystickDlg::CJoystickDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CJoystickDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJoystickDlg)
	m_X = 0;
	m_Y = 0;
	m_Scale = 10;
	m_strButton = _T("");
	m_chkWinstart = FALSE;
	m_bNoUpdate = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJoystickDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJoystickDlg)
	DDX_Control(pDX, IDC_COMBO_DEFAULT_MBUTTON, m_cboMB);
	DDX_Control(pDX, IDC_COMBO_DEFAULT_RBUTTON, m_cboRB);
	DDX_Control(pDX, IDC_COMBO_DEFAULT_LBUTTON, m_cboLB);
	DDX_Text(pDX, IDC_EDIT_X, m_X);
	DDX_Text(pDX, IDC_EDIT_Y, m_Y);
	DDX_Text(pDX, IDC_EDIT_SCALE, m_Scale);
	DDV_MinMaxInt(pDX, m_Scale, 0, 100);
	DDX_Text(pDX, IDC_EDIT_BUTTON, m_strButton);
	DDX_Check(pDX, IDC_CHECK_WINSTART, m_chkWinstart);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CJoystickDlg, CDialog)
	//{{AFX_MSG_MAP(CJoystickDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
	ON_EN_SETFOCUS(IDC_EDIT_SCALE, OnSetfocusEditScale)
	ON_EN_KILLFOCUS(IDC_EDIT_SCALE, OnKillfocusEditScale)
	ON_EN_CHANGE(IDC_EDIT_SCALE, OnChangeEditScale)
	ON_BN_CLICKED(IDC_BUTTON_CAP, OnButtonCap)
	ON_BN_CLICKED(IDM_ABOUTBOX, OnAboutbox)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJoystickDlg message handlers

BOOL CJoystickDlg::OnInitDialog()
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

void CJoystickDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CJoystickDlg::OnPaint()
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
HCURSOR CJoystickDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

int CJoystickDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here
	if (joySetCapture(this->m_hWnd, app->wDeviceID, NULL, FALSE)) {
        MessageBeep(MB_ICONEXCLAMATION);
        MessageBox("无法连接到手柄.", NULL, MB_OK | MB_ICONEXCLAMATION);
        PostMessage(WM_CLOSE,0,0L);
    }
	return 0;
}

void PushMouse(UINT message, WPARAM wParam, LPARAM lParam) {
	//::SendMessage(HWND_BROADCAST, message, wParam, lParam);
//	MouseEventEx(NULL, 0, 0, 0);
	//AtomicVirtualEvent(TRUE);
	//PostVirtualMouseEvent();
	//AtomicVirtualEvent(FALSE);

	PostThreadMessage(GetCurrentThreadId(), message, wParam, lParam);
}

LRESULT CJoystickDlg::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: Add your specialized code here and/or call the base class
	POINT pt;
	POINT joypt;
	BOOL b;

	switch (message) {
	case MM_JOY1MOVE:
	case MM_JOY1BUTTONDOWN:
	case MM_JOY1BUTTONUP:
	case MM_JOY2MOVE:
	case MM_JOY2BUTTONDOWN:
	case MM_JOY2BUTTONUP:
		GetCursorPos(&pt);
		joypt.x = Scale(app->joycaps.wXmin, app->joycaps.wXmax, LOWORD(lParam));
		joypt.y = Scale(app->joycaps.wYmin, app->joycaps.wYmax, HIWORD(lParam));
		switch (app->wDeviceID) {
		case JOYSTICKID1:
			switch (message) {
			case MM_JOY1MOVE:
				b = SetCursorPos(pt.x + joypt.x, pt.y + joypt.y);
				m_X = LOWORD(lParam);
				m_Y = HIWORD(lParam);
				if (!m_bNoUpdate) UpdateData(FALSE);
				break;
			case MM_JOY1BUTTONDOWN:
				if (wParam & JOY_BUTTON1CHG) {
					if (m_cboLB.GetCurSel() == 1)
						PushMouse(WM_LBUTTONDOWN, 0, MAKELONG(pt.x, pt.y));
					if (m_cboRB.GetCurSel() == 1)
						PushMouse(WM_RBUTTONDOWN, 0, MAKELONG(pt.x, pt.y));
					if (m_cboMB.GetCurSel() == 1)
						PushMouse(WM_MBUTTONDOWN, 0, MAKELONG(pt.x, pt.y));
				}
				if (wParam & JOY_BUTTON2CHG) {
					if (m_cboLB.GetCurSel() == 2)
						PushMouse(WM_LBUTTONDOWN, 0, MAKELONG(pt.x, pt.y));
					if (m_cboRB.GetCurSel() == 2)
						PushMouse(WM_RBUTTONDOWN, 0, MAKELONG(pt.x, pt.y));
					if (m_cboMB.GetCurSel() == 2)
						PushMouse(WM_MBUTTONDOWN, 0, MAKELONG(pt.x, pt.y));
				}
				if (wParam & JOY_BUTTON3CHG) {
					if (m_cboLB.GetCurSel() == 3)
						PushMouse(WM_LBUTTONDOWN, 0, MAKELONG(pt.x, pt.y));
					if (m_cboRB.GetCurSel() == 3)
						PushMouse(WM_RBUTTONDOWN, 0, MAKELONG(pt.x, pt.y));
					if (m_cboMB.GetCurSel() == 3)
						PushMouse(WM_MBUTTONDOWN, 0, MAKELONG(pt.x, pt.y));
				}
				if (wParam & JOY_BUTTON4CHG) {
					if (m_cboLB.GetCurSel() == 3)
						PushMouse(WM_LBUTTONDOWN, 0, MAKELONG(pt.x, pt.y));
					if (m_cboRB.GetCurSel() == 3)
						PushMouse(WM_RBUTTONDOWN, 0, MAKELONG(pt.x, pt.y));
					if (m_cboMB.GetCurSel() == 3)
						PushMouse(WM_MBUTTONDOWN, 0, MAKELONG(pt.x, pt.y));
				}
				break;
			case MM_JOY1BUTTONUP:
				::SendMessage(HWND_BROADCAST, WM_LBUTTONUP, 0, MAKELONG(pt.x, pt.y));
				break;
			}
			break;
		case JOYSTICKID2:
			break;
		}
		break; // joy messages
	default:
		;
	}

	return CDialog::DefWindowProc(message, wParam, lParam);
}

int CJoystickDlg::Scale(int min, int max, int val) {
	int width = max - min + 1;
	int halfwidth = width / 2;
	int midp = (val - min) - halfwidth;
	return (midp * m_Scale)/ width;
}

void CJoystickDlg::OnSetfocusEditScale()
{
	// TODO: Add your control notification handler code here
	m_bNoUpdate = TRUE;
}

void CJoystickDlg::OnKillfocusEditScale()
{
	// TODO: Add your control notification handler code here
	m_bNoUpdate = FALSE;
}

void CJoystickDlg::OnChangeEditScale()
{
	// TODO: Add your control notification handler code here
	UpdateData();
}

void CJoystickDlg::OnButtonCap()
{
	// TODO: Add your control notification handler code here
	app->CapsJoystick();
}

void CJoystickDlg::OnAboutbox()
{
	// TODO: Add your control notification handler code here
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}
