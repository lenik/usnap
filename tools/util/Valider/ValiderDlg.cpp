// ValiderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Valider.h"
#include "ValiderDlg.h"
#include "LogDialog.h"

#include <shltools.h>
#include <gmsg.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define massert(str)
#define abs(x) intabs(x)
static long inline intabs(long x) {
	return x >= 0 ? x : -x;
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
// CValiderDlg dialog

CValiderDlg::CValiderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CValiderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CValiderDlg)
	m_chkNest = TRUE;
	m_cboSearch = 4;
	m_cboAlgorithm = 4;
	m_cboBlockSize = 2;
	m_strCurrentDirectory = _T("");
	m_strCurrentFile = _T("");
	m_chkLog = TRUE;
	m_strSource = _T("");
	m_strDest = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	this->m_bCanceled = FALSE;

	b1 = b2 = NULL;
	b1 = new BYTE[0x1000000];
	b2 = new BYTE[0x1000000];
}

CValiderDlg::~CValiderDlg() {
	if (b1 != NULL) delete[] b1;
	if (b2 != NULL) delete[] b2;
}

void CValiderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CValiderDlg)
	DDX_Control(pDX, IDC_BROWSE_SOURCE, m_btnBrowseSource);
	DDX_Control(pDX, IDC_BROWSE_DEST, m_btnBrowseDest);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_btnStop);
	DDX_Control(pDX, IDC_PROGRESS_TOTAL, m_progTotal);
	DDX_Control(pDX, IDC_PROGRESS_FILE, m_progFile);
	DDX_Control(pDX, IDC_PROGRESS_DIRECTORY, m_progDirectory);
	DDX_Control(pDX, IDC_EDIT_SOURCE, m_edtSource);
	DDX_Control(pDX, IDC_EDIT_DEST, m_edtDest);
	DDX_Control(pDX, IDC_BUTTON_START, m_btnStart);
	DDX_Control(pDX, IDC_BUTTON_EXIT, m_btnExit);
	DDX_Check(pDX, IDC_CHECK_NEST, m_chkNest);
	DDX_CBIndex(pDX, IDC_COMBO_ALGORITHM, m_cboAlgorithm);
	DDX_CBIndex(pDX, IDC_COMBO_BLOCKSIZE, m_cboBlockSize);
	DDX_CBIndex(pDX, IDC_COMBO_SEARCH, m_cboSearch);
	DDX_Text(pDX, IDC_STATIC_CURRENT_DIRECTORY, m_strCurrentDirectory);
	DDX_Text(pDX, IDC_STATIC_CURRENT_FILE, m_strCurrentFile);
	DDX_Check(pDX, IDC_CHECK_LOG, m_chkLog);
	DDX_Text(pDX, IDC_EDIT_SOURCE, m_strSource);
	DDX_Text(pDX, IDC_EDIT_DEST, m_strDest);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CValiderDlg, CDialog)
	//{{AFX_MSG_MAP(CValiderDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, OnButtonAbout)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, OnButtonExit)
	ON_BN_CLICKED(IDC_BROWSE_SOURCE, OnBrowseSource)
	ON_BN_CLICKED(IDC_BROWSE_DEST, OnBrowseDest)
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CValiderDlg message handlers

BOOL CValiderDlg::OnInitDialog()
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
	this->m_btnStop.EnableWindow(FALSE);

	this->m_progTotal.SetRange(0, 100);
	this->m_progDirectory.SetRange(0, 100);
	this->m_progFile.SetRange(0, 100);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CValiderDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CValiderDlg::OnPaint()
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
HCURSOR CValiderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CValiderDlg::OnButtonAbout()
{
	// TODO: Add your control notification handler code here
	CAboutDlg dlg;
	dlg.DoModal();
}

void CValiderDlg::OnButtonExit()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}

void CValiderDlg::OnBrowseSource()
{
	// TODO: Add your control notification handler code here
	TCHAR	folder[MAX_PATH];
	if (doDirSelect(folder, NULL)) {
		this->m_edtSource.SetWindowText(folder);
	}
}

void CValiderDlg::OnBrowseDest()
{
	// TODO: Add your control notification handler code here
	TCHAR	folder[MAX_PATH];
	if (doDirSelect(folder, NULL)) {
		this->m_edtDest.SetWindowText(folder);
	}
}

TCHAR lastchr(CString &str) {
	int l = str.GetLength();
	if (l > 0) return str[l - 1];
	return (TCHAR)0;
}

int CValiderDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here

	return 0;
}

void CValiderDlg::OnOK()
{
}

void CValiderDlg::OnCancel()
{
}

void CValiderDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	this->OnButtonExit();
	CDialog::OnClose();
}

//////////////////////////////////////////////////////
// main section

int _stdcall srcproc(HANDLE h, UINT msg, DWORD p1, DWORD p2) {
	static CValiderDlg *pdlg;
	switch (msg) {
	case FF_INIT:
		pdlg = (CValiderDlg *)(*(DWORD *)p1);
		break;
	}
	return pdlg->srcproc(h, msg, p1, p2);
}

int _stdcall destproc(HANDLE h, UINT msg, DWORD p1, DWORD p2) {
	static CValiderDlg *pdlg;
	switch (msg) {
	case FF_INIT:
		pdlg = (CValiderDlg *)(*(DWORD *)p1);
		break;
	}
	return pdlg->destproc(h, msg, p1, p2);
}

int _stdcall getfilesproc(HANDLE h, UINT msg, DWORD p1, DWORD p2) {
	static DWORD *pnum = NULL;
	switch (msg) {
	case FF_INIT:
		pnum	= (DWORD *)(*(DWORD *)p1);
		break;
	case FF_ENTER:
		return FF_SKIP;
	case FF_END:
		*pnum	= p1;
		break;
	}
	return 0;
}

int getFilesNum(LPCTSTR dirname) {
	DWORD num = 0;
	findfiles(dirname, 0, getfilesproc, (DWORD)&num);
	return (int)num;
}

//////////////////////////////////////////////////////
// main searcher
// ----------------
// search modifiers only affected in srcproc
int CValiderDlg::srcproc(HANDLE h, UINT msg, DWORD p1, DWORD p2) {
	static int baseDirLen = 0;
	LPCTSTR dir = (LPCTSTR)p2;
	TCHAR file[MAX_PATH];
	LPWIN32_FIND_DATA pfd = (LPWIN32_FIND_DATA)p1;

	static int	counters[100];		// files-counters in each level of directories
	static int	pcounter;		// current level
	BOOL	process_thisfile = FALSE;	// random process flag from cboSearch/Discrete

	static int	totalfiles;
	static int	currentfile;

	if (this->m_bCanceled) return FF_CANCEL;

	switch (msg) {
	case FF_INIT:
		baseDirLen = lstrlen((LPCTSTR)p2);
		this->m_strCurrentDirectory = (LPCTSTR)p2;
		this->UpdateData(FALSE);
		pcounter = 0;
		counters[0] = 0;
		totalfiles = getFilesNum(this->m_strCurrentDirectory);
		currentfile = 0;
		break;
	case FF_FILE:
		ASSERT(pcounter >= 0);
		counters[pcounter]++;
		switch (this->m_cboSearch) {
		case SEARCH_SEQ:
			process_thisfile = TRUE;
			break;
		case SEARCH_SEQ_1:
			if (counters[pcounter] <= 1) process_thisfile = TRUE;
			break;
		case SEARCH_SEQ_25:
			if (counters[pcounter] <= 25) process_thisfile = TRUE;
			break;
		case SEARCH_DIS_5:
			if ((rand() % 20) == 0) process_thisfile = TRUE;
			break;
		case SEARCH_DIS_25:
			if ((rand() % 4) == 0) process_thisfile = TRUE;
			break;
		case SEARCH_DIS_50:
			if ((rand() % 2) == 0) process_thisfile = TRUE;
			break;
		default:
			process_thisfile = TRUE;
			break;
		}
		if (process_thisfile) {
			wsprintf(file, "%s\\%s", dir, pfd->cFileName);
			lstrcpy(this->m_strFile, file);
			//lstrcpy(this->m_strCurrentSrcBase, file + baseDirLen + 1);
			lstrcpy(this->m_strFileBase, file + (baseDirLen + 1)); // +1: '\\'
			this->m_averageCorrect += this->srcfile();
			this->m_nTotalfiles++;
		}
		break;
	case FF_ENTER:
		this->m_strCurrentDirectory = (LPCTSTR)p2;
		this->UpdateData(FALSE);
		if (!this->m_chkNest) return FF_GO_UP;
		pcounter++;
		counters[pcounter] = 0;
		break;
	case FF_EXIT:
		pcounter--;
		ASSERT(pcounter >= 0);
		break;
	}

	if (pcounter == 0) {
		int currentp = currentfile * 100 / totalfiles;
		switch (msg) {
		case FF_FILE:
		case FF_DIR:
			currentfile++;
			this->m_progTotal.SetPos(currentp);
			break;
		}
	}

	return 0;
}
int CValiderDlg::destproc(HANDLE h, UINT msg, DWORD p1, DWORD p2) {
	static int baseDirLen = 0;
	LPCTSTR dir = (LPCTSTR)p2;
	TCHAR file[MAX_PATH];
	LPWIN32_FIND_DATA pfd = (LPWIN32_FIND_DATA)p1;

	if (this->m_bCanceled) return FF_CANCEL;

	static int	counters[100];		// files-counters in each level of directories
	static int	pcounter;		// current level
	BOOL	process_thisfile = FALSE;	// random process flag from cboSearch/Discrete

	switch (msg) {
	case FF_INIT:
		baseDirLen = lstrlen((LPCTSTR)p2);
		this->m_strCurrentDirectory = (LPCTSTR)p2;
		this->UpdateData(FALSE);
		pcounter = 0;
		counters[0] = 0;
		break;
	case FF_FILE:
		//没有办法做到使反响遍历能够忽略正向遍历以便历过的文件
		//    massert("unpossible reach here if 2 directories as same");
		ASSERT(pcounter >= 0);
		counters[pcounter]++;
		switch (this->m_cboSearch) {
		case SEARCH_SEQ:
			process_thisfile = TRUE;
			break;
		case SEARCH_SEQ_1:
			if (counters[pcounter] <= 1) process_thisfile = TRUE;
			break;
		case SEARCH_SEQ_25:
			if (counters[pcounter] <= 25) process_thisfile = TRUE;
			break;
		case SEARCH_DIS_5:
			if ((rand() % 20) == 0) process_thisfile = TRUE;
			break;
		case SEARCH_DIS_25:
			if ((rand() % 4) == 0) process_thisfile = TRUE;
			break;
		case SEARCH_DIS_50:
			if ((rand() % 2) == 0) process_thisfile = TRUE;
			break;
		default:
			process_thisfile = TRUE;
			break;
		}
		if (process_thisfile) {
			float m;
			wsprintf(file, "%s\\%s", dir, pfd->cFileName);
			lstrcpy(this->m_strFile, file);
			//lstrcpy(this->m_strCurrentSrcBase, file + baseDirLen + 1);
			lstrcpy(this->m_strFileBase, file + (baseDirLen + 1)); // +1: '\\'

			// don't notice any file match, because it is duplicated
			// in srcproc.
			if ((m = this->destfile()) < 100.0) {
				this->m_averageCorrect += m;
				this->m_nTotalfiles++;
			}
		}
		break;
	case FF_ENTER:
		this->m_strCurrentDirectory = (LPCTSTR)p2;
		this->UpdateData(FALSE);
		if (!this->m_chkNest) return FF_GO_UP;
		pcounter++;
		counters[pcounter] = 0;
		break;
	case FF_EXIT:
		pcounter--;
		ASSERT(pcounter >= 0);
		break;
	}
	return 0;
}

void CValiderDlg::OnButtonStop()
{
	// TODO: Add your control notification handler code here
	this->m_bCanceled = TRUE;
}

void CValiderDlg::OnButtonStart()
{
	// TODO: Add your control notification handler code here

	UpdateData();

	this->m_btnBrowseSource.EnableWindow(FALSE);
	this->m_btnBrowseDest.EnableWindow(FALSE);
	this->m_btnStart.EnableWindow(FALSE);
	this->m_btnStop.EnableWindow(TRUE);
	this->m_btnExit.EnableWindow(FALSE);

	this->m_bCanceled = FALSE;

	this->m_averageCorrect = 0.0;
	this->m_nTotalfiles = 0;

	this->m_strLog = _T("");

	// 对source的每个文件分析 { source } union { dest int source }
	findfiles(this->m_strSource, -1, ::srcproc, (DWORD)this);
	// 对dest的每个文件分析 { dest } union { source int dest }
	findfiles(this->m_strDest, -1, ::destproc, (DWORD)this);
	// 得出： S+DS + D+SD == S + D + SD == S + D == E(entire)

	CString line;
	line.Format(_T("total %d files, correct accumulate: %.2f, average: %.2f\r\n"),
		this->m_nTotalfiles, this->m_averageCorrect,
		this->m_nTotalfiles == 0 ? 0 : (this->m_averageCorrect / this->m_nTotalfiles)
		);
	this->m_strLog = line + this->m_strLog;

	if (this->m_chkLog) {
		CLogDialog dlg(NULL, this->m_strLog);
		dlg.DoModal();
	}

	this->m_btnBrowseSource.EnableWindow(TRUE);
	this->m_btnBrowseDest.EnableWindow(TRUE);
	this->m_btnStart.EnableWindow(TRUE);
	this->m_btnStop.EnableWindow(FALSE);
	this->m_btnExit.EnableWindow(TRUE);
}

float CValiderDlg::srcfile() {
	// 1. check existance
	// 2. check contents

	float matchlevel = 100.0;
	massert("destdir contains basefilename");
	TCHAR destdir[MAX_PATH], destfile[MAX_PATH];
	lstrcpyn(destdir, this->m_strFile,
		lstrlen(this->m_strFile) - lstrlen(this->m_strFileBase) - 1 + 1
		); // -1:ignore '\\', +1:pad '\0'
	wsprintf(destfile, _T("%s\\%s"), destdir, this->m_strFileBase);

	CString line;
	CFileStatus st;
	if (CFile::GetStatus(destfile, st)) {
		matchlevel = matchfile(this->m_strFile, destfile);
		line.Format(_T("%s matched: %3.2f%%. \r\n"), destfile, matchlevel);
	} else {
		line.Format(_T("%s unexisted. \r\n"), destfile);
	}

	this->m_strLog += line;
	return matchlevel;
}

float CValiderDlg::destfile() {

	float matchlevel = 100.0;

	massert("srcdir contains basefilename");
	TCHAR srcdir[MAX_PATH], srcfile[MAX_PATH];
	lstrcpyn(srcdir, this->m_strFile,
		lstrlen(this->m_strFile) - lstrlen(this->m_strFileBase) - 1 + 1
		); // -1:ignore '\\', +1:pad '\0'
	wsprintf(srcfile, _T("%s\\%s"), srcdir, this->m_strFileBase);

	CFileStatus st;
	// 反向遍历中只查找多余的文件
	if (!CFile::GetStatus(srcfile, st)) {
		massert("if 2 directories same, it won't come here");
		CString line;
		line.Format(_T("%s addition. \r\n"), (LPCTSTR)this->m_strFile);
		this->m_strLog += line;
		matchlevel = 0.0;
	}

	return matchlevel;
}

static LONG	_random(LONG max) {
	LONG	adds = (max + 1) / RAND_MAX;
	LONG	left = (max + 1) % RAND_MAX;
	LONG	r = 0;
	for (int addsi = 0; addsi < adds; addsi++) {
		r += rand();
	}
	r += rand() % left;
	r %= (max + 1);
	return r;
}

double	testfileblock(CFile &f1, CFile &f2, LONG blocksize, BYTE *pbuf1, BYTE *pbuf2) {
	LONG	bmaxsize = 0x100000;
	LONG	actual1, actual2;
	LONG	intsize = 0, extra = 0;		// intsize: intersect part; extra: extra part
	LONG	unmatches = 0;

	if (blocksize < 0) blocksize = _random(bmaxsize);

	actual1 = f1.Read(pbuf1, blocksize);
	actual2 = f2.Read(pbuf2, blocksize);

	extra = abs(actual1 - actual2);
	intsize = (actual1 + actual2 - extra) >> 1;

	for (int i = 0; i < intsize; i++) {
		if (pbuf1[i] != pbuf2[i]) unmatches++;
	}

	if (intsize + extra <= 0) {
		return 1.0;
	} else {
		return (double)(intsize - unmatches) / (double)(intsize + extra);
	}
}

float	CValiderDlg::matchfile(LPCTSTR fn1, LPCTSTR fn2) {
	double	m = 1.0;
	LONG	bsize = 0;
	BOOL	disblock = FALSE;
	int	i;

	switch (this->m_cboAlgorithm) {
	case 0: bsize = 0x400; break;
	case 1: bsize = 0x1000; break;
	case 2: bsize = 0x8000; break;
	case 3: bsize = 0x100000; break;
	case 4:
		bsize = 0x80000;	// random(0x100000)'s average is 0x80000
		disblock = TRUE;
		break;
	}

	this->m_strCurrentFile.Format(_T("%s"), fn2);
	this->UpdateData(FALSE);

#define _RELEASE_MATCH
#ifdef _RELEASE_MATCH
	TRY {
#endif
		CFile f1(fn1, CFile::modeRead | CFile::typeBinary | CFile::shareDenyNone);
		CFile f2(fn2, CFile::modeRead | CFile::typeBinary | CFile::shareDenyNone);

		LONG	test_total = 0, test_match = 0;
		LONG	minlength = f1.GetLength() < f2.GetLength() ? f1.GetLength() : f2.GetLength();
		LONG	p = 0, bn = 0;

		switch (this->m_cboAlgorithm) {
		case TEST_SEQ_T25:
			p = minlength * 3 / 4;
			f1.Seek(p, CFile::begin);
			f2.Seek(p, CFile::begin);
		case TEST_SEQ_H25:
			bn	= minlength / 4 / bsize;
		case TEST_SEQ_FULL:
			if (this->m_cboAlgorithm == TEST_SEQ_FULL)
				bn = minlength / bsize;
			for (i = 0; i < bn; i++) {
				m *= testfileblock(f1, f2, bsize, b1, b2);
			}
			break;
		case TEST_DIS_5:
		case TEST_DIS_25:
		case TEST_DIS_50:
			switch (this->m_cboAlgorithm) {
			case TEST_DIS_5: bn = minlength / 20 / bsize; break;
			case TEST_DIS_25: bn = minlength / 4 / bsize; break;
			case TEST_DIS_50: bn = minlength / 2 / bsize; break;
			}
			if (bn == 0) {
				if (minlength > 0) {
					bn = 1;
				}
			}
			for (i = 0; i < bn; i++) {
				p	= (LONG)(((double)minlength) * rand() / RAND_MAX);
				f1.Seek(p, CFile::begin);
				f2.Seek(p, CFile::begin);
				m	*= testfileblock(f1, f2, -1, b1, b2);
			}
			break;
		default:
			break;
		}

		f1.Close();
		f2.Close();
#ifdef _RELEASE_MATCH
	} CATCH(CFileException, fe) {
		fe->ReportError();
	} END_CATCH;
#endif

	return (float)(100 * m);
}

#undef massert
#undef abs
