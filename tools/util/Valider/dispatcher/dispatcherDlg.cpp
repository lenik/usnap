// dispatcherDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dispatcher.h"
#include "dispatcherDlg.h"
#include "logdialog.h"

#include <shltools.h>
#include <gmsg.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int _stdcall srcproc(HANDLE h, UINT msg, DWORD p1, DWORD p2) {
	static CDispatcherDlg *pdlg;
	switch (msg) {
	case FF_INIT:
		pdlg = (CDispatcherDlg *)(*(DWORD *)p1);
		break;
	}
	return pdlg->srcproc(h, msg, p1, p2);
}

int _stdcall destproc(HANDLE h, UINT msg, DWORD p1, DWORD p2) {
	static CDispatcherDlg *pdlg;
	switch (msg) {
	case FF_INIT:
		pdlg = (CDispatcherDlg *)(*(DWORD *)p1);
		break;
	}
	return pdlg->destproc(h, msg, p1, p2);
}

int CDispatcherDlg::srcproc(HANDLE h, UINT msg, DWORD p1, DWORD p2) {
	static int baseDirLen = 0;
	LPCTSTR dir = (LPCTSTR)p2;
	TCHAR file[MAX_PATH];
	LPWIN32_FIND_DATA pfd = (LPWIN32_FIND_DATA)p1;
	if (this->m_bCanceled) return FF_CANCEL;

	switch (msg) {
	case FF_INIT:
		baseDirLen = lstrlen((LPCTSTR)p2);
		break;
	case FF_FILE:
		if (!(pfd->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
			wsprintf(file, "%s\\%s", dir, pfd->cFileName);
			lstrcpy(this->m_strCurrentSrc, file);
			//lstrcpy(this->m_strCurrentSrcBase, file + baseDirLen + 1);
			lstrcpy(this->m_strCurrentSrcBase, pfd->cFileName);
			this->srcfile();
		}
		break;
	case FF_ENTER:
		//this->
		//if (!CFile::GetStatus(dir,
		;
	}
	return 0;
}
int CDispatcherDlg::srcfile() {
	TCHAR destdir[MAX_PATH];
	lstrcpy(destdir, this->m_strDest);
	if (destdir[lstrlen(destdir) - 1] != _T('\\')) {
		lstrcat(destdir, _T("\\"));
	}
	return findfiles(destdir, -1, ::destproc, (DWORD)this);
}
int CDispatcherDlg::destproc(HANDLE h, UINT msg, DWORD p1, DWORD p2) {
	LPCTSTR dir = (LPCTSTR)p2;
	LPWIN32_FIND_DATA pfd = (LPWIN32_FIND_DATA)p1;
	if (this->m_bCanceled) return FF_CANCEL;

	switch (msg) {
	case FF_INIT:
	case FF_ENTER:
		this->destdir(this->m_strCurrentSrc, dir);
		break;
	}
	return 0;
}
int CDispatcherDlg::destdir(LPCTSTR srcfile, LPCTSTR destdir) {
	CString line;
	TRY {
		CFile src(srcfile, CFile::modeRead | CFile::typeBinary);
		TCHAR destfile[MAX_PATH];
		wsprintf(destfile, "%s\\%s", destdir, this->m_strCurrentSrcBase);
		CFile dest(destfile,
			CFile::modeWrite | CFile::typeBinary | CFile::modeCreate);

		line.Format(_T("file %s"), destfile);
		this->m_strLog	+= line;

		BYTE buf[4096];
		int c = 0, block;
		if (this->m_chkTemplate) {
			BOOL	bEscaped = FALSE;
			LPTSTR	subs;
			LPTSTR	pbuf = (LPTSTR)buf;
			for (;; c = 0) {
				if ((block = src.Read(&c, 1)) == 0) break;
				if (c == _T('%') && !bEscaped) {
					bEscaped = TRUE;
					continue;
				}
				if (bEscaped) {
					switch (c) {
					case _T('%'):
						subs = _T("%");
						break;
					case _T('r'): // related path to dest
					case _T('R'): // related path to src
						{
							TCHAR srcdir[MAX_PATH];
							lstrcpyn(srcdir, this->m_strCurrentSrc,
								lstrlen(this->m_strCurrentSrc) - lstrlen(this->m_strCurrentSrcBase) // - 1 + 1
								);	// -1:throw '\\', +1:pad '\0'
							if (c == _T('r')) {
								subs = related_path(destdir, srcdir, pbuf);
							} else {
								subs = related_path(srcdir, destdir, pbuf);
							}
						}
						break;
					case _T('s'):
						// src file-basename
						subs = this->m_strCurrentSrcBase;
						break;
					case _T('d'):
						// dest dir
						subs = (LPTSTR)destdir;
						break;
					case _T('D'):
						// dest file
						subs = destfile;
						break;
					case _T('c'):
						// counter
						//subs = ltoa(counter++, pbuf
						wsprintf(pbuf, _T("%d"), this->m_nCounter++);
						subs = pbuf;
						break;
					case _T('*'):
						// random byte
						subs = _T("x");
						subs[0] = rand();
						break;
					case _T('?'):
						// random '0'..'9'
						subs = _T("x");
						subs[0] = '0' + (rand() % 10);
						break;
					}
					bEscaped = FALSE;
					dest.Write(subs, lstrlen(subs) * sizeof(TCHAR));
				} else {
					dest.Write(&c, 1);
				} // if bEscape
			} // for (;;)
		} else {
			while (block = src.Read(buf, 4096)) {
				dest.Write(buf, block);
			}
		}

		line.Format(_T(" created successed. \r\n"));
		this->m_strLog	+= line;

		src.Close();
		dest.Close();

	} CATCH (CFileException, fe) {
		fe->ReportError();
		TCHAR buf[4096];
		fe->GetErrorMessage(buf, 4096);
		line.Format(_T(" error: %s\r\n"), buf);
		this->m_strLog	+= line;
	} END_CATCH

	return 0;
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
	virtual void OnOK();
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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDispatcherDlg dialog

CDispatcherDlg::CDispatcherDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDispatcherDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDispatcherDlg)
	m_chkDirectory = FALSE;
	m_chkLog = TRUE;
	m_chkTemplate = TRUE;
	m_strDest = _T("");
	m_strSource = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bCanceled = FALSE;
}

void CDispatcherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDispatcherDlg)
	DDX_Control(pDX, IDC_BUTTON_EXIT, m_btnExit);
	DDX_Control(pDX, IDC_BUTTON_ABOUT, m_btnAbout);
	DDX_Control(pDX, IDC_EDIT_SOURCE, m_edtSource);
	DDX_Control(pDX, IDC_EDIT_DEST, m_edtDest);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_btnStop);
	DDX_Control(pDX, IDC_BUTTON_START, m_btnStart);
	DDX_Control(pDX, IDC_BUTTON_SELECT_FOLDER, m_btnSelectDir);
	DDX_Control(pDX, IDC_BUTTON_SELECT_FILE, m_btnSelectFile);
	DDX_Control(pDX, IDC_BUTTON_BROWSE_DEST, m_btnBrowseDest);
	DDX_Check(pDX, IDC_CHECK_DIRECTORY, m_chkDirectory);
	DDX_Check(pDX, IDC_CHECK_LOG, m_chkLog);
	DDX_Check(pDX, IDC_CHECK_TEMPLATE, m_chkTemplate);
	DDX_Text(pDX, IDC_EDIT_DEST, m_strDest);
	DDX_Text(pDX, IDC_EDIT_SOURCE, m_strSource);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDispatcherDlg, CDialog)
	//{{AFX_MSG_MAP(CDispatcherDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, OnButtonAbout)
	ON_BN_CLICKED(IDC_BUTTON_SELECT_FILE, OnButtonSelectFile)
	ON_BN_CLICKED(IDC_BUTTON_SELECT_FOLDER, OnButtonSelectFolder)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE_DEST, OnButtonBrowseDest)
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, OnButtonExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDispatcherDlg message handlers

BOOL CDispatcherDlg::OnInitDialog()
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

void CDispatcherDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDispatcherDlg::OnPaint()
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
HCURSOR CDispatcherDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDispatcherDlg::OnButtonAbout()
{
	// TODO: Add your control notification handler code here
	CAboutDlg dlg;
	dlg.DoModal();
}

void CDispatcherDlg::OnButtonSelectFile()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE);
	if (dlg.DoModal()) {
		this->m_strSource = dlg.GetPathName();
		this->m_chkDirectory = FALSE;

		this->UpdateData(FALSE);
	}
}

void CDispatcherDlg::OnButtonSelectFolder()
{
	// TODO: Add your control notification handler code here
	TCHAR dirname[MAX_PATH];
	if (doDirSelect(dirname, NULL)) {
		this->m_strSource = dirname;
		this->m_chkDirectory = TRUE;

		this->UpdateData(FALSE);
	}
}

void CDispatcherDlg::OnButtonBrowseDest()
{
	// TODO: Add your control notification handler code here
	TCHAR dirname[MAX_PATH];
	if (doDirSelect(dirname, NULL)) {
		this->m_strDest = dirname;

		this->UpdateData(FALSE);
	}
}

void CDispatcherDlg::OnButtonStart()
{
	// TODO: Add your control notification handler code here
	this->UpdateData(TRUE);

	this->m_btnSelectFile.EnableWindow(FALSE);
	this->m_btnSelectDir.EnableWindow(FALSE);
	this->m_btnBrowseDest.EnableWindow(FALSE);
	this->m_btnStart.EnableWindow(FALSE);
	this->m_btnStop.EnableWindow(TRUE);
	this->m_btnExit.EnableWindow(FALSE);

	this->m_bCanceled = FALSE;
	this->m_strLog	= _T("");
	this->m_nCounter = 0;

	if (this->m_chkDirectory) {
		TCHAR srcdir[MAX_PATH];
		lstrcpy(srcdir, this->m_strSource);
		if (srcdir[lstrlen(srcdir) - 1] != _T('\\')) {
			lstrcat(srcdir, _T("\\"));
		}
		findfiles(srcdir, -1, ::srcproc, (DWORD)this);
	} else {
		TCHAR basename[MAX_PATH];
		split_dirfile(this->m_strSource, NULL, basename);
		lstrcpy(this->m_strCurrentSrc, this->m_strSource);
		lstrcpy(this->m_strCurrentSrcBase, basename);
		this->srcfile();
	}

	this->m_bCanceled = TRUE;
	this->m_btnSelectFile.EnableWindow(TRUE);
	this->m_btnSelectDir.EnableWindow(TRUE);
	this->m_btnBrowseDest.EnableWindow(TRUE);
	this->m_btnStart.EnableWindow(TRUE);
	this->m_btnStop.EnableWindow(FALSE);
	this->m_btnExit.EnableWindow(TRUE);

	if (this->m_chkLog) {
		CLogDialog dlg(NULL, this->m_strLog);
		dlg.DoModal();
	}
}

void CDispatcherDlg::OnButtonStop()
{
	// TODO: Add your control notification handler code here
	this->m_bCanceled = TRUE;
	this->m_btnStop.EnableWindow(FALSE);
}

void CDispatcherDlg::OnOK()
{
}

void CDispatcherDlg::OnCancel()
{
}

void CAboutDlg::OnOK()
{
	// TODO: Add extra validation here

	CDialog::OnOK();
}

void CDispatcherDlg::OnButtonExit()
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
