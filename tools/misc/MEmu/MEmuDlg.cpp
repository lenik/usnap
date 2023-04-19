// MEmuDlg.cpp : implementation file
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
// CMEmuDlg dialog

CMEmuDlg::CMEmuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMEmuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMEmuDlg)
	m_strFilename = _T("");
	m_strFact = _T("");
	m_strSize = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bFileOpened = FALSE;
	m_hLocal = 0;
	m_nInterval = 0;		// once
}

void CMEmuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMEmuDlg)
	DDX_Control(pDX, IDC_SCROLLBAR_FREQ, m_scrFrequence);
	DDX_Text(pDX, IDC_EDIT_FILENAME, m_strFilename);
	DDX_Text(pDX, IDC_STATIC_FACT, m_strFact);
	DDX_Text(pDX, IDC_STATIC_SIZE, m_strSize);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMEmuDlg, CDialog)
	//{{AFX_MSG_MAP(CMEmuDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_BROWSE, OnButtonBrowse)
	ON_BN_CLICKED(IDC_RADIO_TYPE_ONCE, OnRadioTypeOnce)
	ON_BN_CLICKED(IDC_RADIO_TYPE_FREQ, OnRadioTypeFreq)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, OnButtonClose)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, OnButtonAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMEmuDlg message handlers

BOOL CMEmuDlg::OnInitDialog()
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

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_scrFrequence.SetScrollRange(0, 20);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMEmuDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMEmuDlg::OnPaint()
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

HCURSOR CMEmuDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMEmuDlg::OnButtonBrowse()
{
	// TODO: Add your control notification handler code here
	CFileDialog fileDialog(TRUE);

	if (fileDialog.DoModal() == IDOK) {
		m_strFilename = fileDialog.GetPathName();
		this->UpdateData(FALSE);
	}
}

void CMEmuDlg::OnRadioTypeOnce()
{
	// TODO: Add your control notification handler code here
	if (m_bFileOpened) {
		int r = MessageBox("文件已打开, 将其关闭?", NULL, MB_YESNOCANCEL | MB_ICONQUESTION);
		if (r != IDYES) return;
	}
	UpdateData();
	m_nInterval = 0;
	m_bFileOpened = TRUE;
	if (m_hLocal) LocalFree(m_hLocal);
	m_hLocal = 0;
	OnTimer(0);

}

void CMEmuDlg::OnRadioTypeFreq()
{
	// TODO: Add your control notification handler code here
	int TransTable[21] = {
		0,					// once
		1,					// once per 5 minute
		2, 3, 4, 5,			// 2, 3, 4, 5 times per 5 minute
		6, 7, 8, 9, 10, 	// 1, 2, 3, 4, 5 times per minute
		11, 12, 13, 14, 15,	// 1, 2, 3, 4, 5 times per second
		16, 17, 18, 19,		// 10, 100, 1000, 10000 times per second
		20					// realtime
	};

	if (m_bFileOpened) {
		int r = MessageBox("文件已打开, 将其关闭?", NULL, MB_YESNOCANCEL | MB_ICONQUESTION);
		if (r != IDYES) return;
	}
	UpdateData();
	m_nInterval = m_scrFrequence.GetScrollPos();
	m_bFileOpened = TRUE;
	if (m_hLocal) LocalFree(m_hLocal);
	m_hLocal = 0;
	OnTimer(0);
}

void CMEmuDlg::OnButtonClose()
{
	// TODO: Add your control notification handler code here
	if (m_bFileOpened) {
		m_bFileOpened = FALSE;
		if (m_hLocal) LocalFree(m_hLocal);
		m_strSize = "0";
		UpdateData(FALSE);
	} else {
		MessageBox("文件已关闭");
	}
}

void CMEmuDlg::OnTimer(UINT nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	static BOOL bRunning = FALSE;
	CFile f;
	CFileException e;

	if (bRunning) return;

	UpdateData();

	TRY {
		if (f.Open(m_strFilename, CFile::modeRead | CFile::typeBinary, &e)) {
			LONG length = f.GetLength();
			LPVOID buf;

			m_strSize.Format("%d", length);
			UpdateData(FALSE);

			if (m_hLocal) LocalFree(m_hLocal);
			if (m_hLocal = LocalAlloc(LMEM_FIXED, length)) {
				buf = LocalLock(m_hLocal);
				f.ReadHuge(buf, length);
				LocalUnlock(m_hLocal);
			}

			f.Close();

		} else {
			e.ReportError();
			return;
		}
	} CATCH (CFileException, e) {
		e->ReportError();
		return;
	} END_CATCH;

	CDialog::OnTimer(nIDEvent);
}

void CMEmuDlg::OnButtonAbout()
{
	// TODO: Add your control notification handler code here
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}
