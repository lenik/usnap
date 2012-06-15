// replaceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "replace.h"
#include "replaceDlg.h"

#include "SubDialog.h"
#include "SubstitudingDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define MAXFILESIZE		20000
#define SECTION_REPDLG		(_T("Replace Dialog"))


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
// CReplaceDlg dialog

CReplaceDlg::CReplaceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReplaceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReplaceDlg)
	m_strCurrentFilename = _T("");
	m_strSubcon = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReplaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReplaceDlg)
	DDX_Control(pDX, IDC_LIST_SUBSTITUDE, m_lstSubs);
	DDX_Control(pDX, IDC_LIST_FILES, m_lstFiles);
	DDX_Text(pDX, IDC_STATIC_CURRENT_FILENAME, m_strCurrentFilename);
	DDX_Text(pDX, IDC_STATIC_SUBCON, m_strSubcon);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CReplaceDlg, CDialog)
	//{{AFX_MSG_MAP(CReplaceDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EXIT, OnButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_SUBSTITUDE, OnButtonSubstitude)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_REMOVE, OnButtonRemove)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_SADD, OnButtonSadd)
	ON_LBN_DBLCLK(IDC_LIST_SUBSTITUDE, OnDblclkListSubstitude)
	ON_BN_CLICKED(IDC_BUTTON_SREMOVE, OnButtonSremove)
	ON_BN_CLICKED(IDC_BUTTON_SCLEAR, OnButtonSclear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReplaceDlg message handlers

BOOL CReplaceDlg::OnInitDialog()
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
	int count;
	CReplaceApp *app = (CReplaceApp *)::AfxGetApp();
	count = app->GetProfileInt(SECTION_REPDLG, _T("filescount"), 0);
	int i;
	CString itemname;
	CString str;
	for (i = 0; i < count; i++) {
		itemname.Format(_T("file%d"), i);
		str = app->GetProfileString(SECTION_REPDLG, itemname);
		this->m_lstFiles.AddString(str);
	}
	count = app->GetProfileInt(SECTION_REPDLG, _T("subscount"), 0);
	for (i = 0; i < count; i++) {
		itemname.Format(_T("subsrc%d"), i);
		CReplaceDlg::CSTRPAIR sp;
		sp.first = app->GetProfileString(SECTION_REPDLG, itemname);
		itemname.Format(_T("subdest%d"), i);
		sp.second = app->GetProfileString(SECTION_REPDLG, itemname);
		this->m_subslist.push_back(sp);
		str.Format("替换\"%s\"到\"%s\".", sp.first, sp.second);
		this->m_lstSubs.AddString(str);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CReplaceDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CReplaceDlg::OnPaint()
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
HCURSOR CReplaceDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CReplaceDlg::OnOK()
{
	// TODO: Add extra validation here
	OnButtonSubstitude();
}

void CReplaceDlg::OnCancel()
{
	// TODO: Add extra cleanup here
}

void CReplaceDlg::OnButtonExit()
{
	// TODO: Add your control notification handler code here
	int count;
	CReplaceApp *app = (CReplaceApp *)::AfxGetApp();
	count = this->m_lstFiles.GetCount();
	app->WriteProfileInt(SECTION_REPDLG, _T("filescount"), count);
	int i;
	CString itemname;
	CString str;
	for (i = 0; i < count; i++) {
		itemname.Format(_T("file%d"), i);
		this->m_lstFiles.GetText(i, str);
		str = app->WriteProfileString(SECTION_REPDLG, itemname, str);
	}

	count = this->m_lstSubs.GetCount();
	app->WriteProfileInt(SECTION_REPDLG, _T("subscount"), count);
	for (i = 0; i < count; i++) {
		itemname.Format(_T("subsrc%d"), i);
		CReplaceDlg::CSTRPAIR sp;
		sp = this->geti(i);
		app->WriteProfileString(SECTION_REPDLG, itemname, sp.first);
		itemname.Format(_T("subdest%d"), i);
		app->WriteProfileString(SECTION_REPDLG, itemname, sp.second);
	}

	CDialog::OnCancel();
}

void CReplaceDlg::OnButtonAdd()
{
	// TODO: Add your control notification handler code here
	CFileDialog fd(TRUE);

	if (fd.DoModal() == IDOK) {
		m_lstFiles.AddString(fd.GetPathName());
	}
}

void CReplaceDlg::OnButtonRemove()
{
	// TODO: Add your control notification handler code here
	int cs = m_lstFiles.GetCurSel();
	if (cs >= 0) {
		m_lstFiles.DeleteString(cs);
		if (cs > 0) {
			m_lstFiles.SetCurSel(cs - 1);
		}
	}
}

void CReplaceDlg::OnButtonClear()
{
	m_lstFiles.ResetContent();
}

void CReplaceDlg::OnButtonSadd()
{
	// TODO: Add your control notification handler code here
	CSubDialog sd("", "");
	if (sd.DoModal() == IDOK) {
		CReplaceDlg::CSTRPAIR sp;
		sp.first = sd.m_strSrc;
		sp.second = sd.m_strDest;
		this->m_subslist.push_back(sp);
		CString str;
		str.Format("替换\"%s\"到\"%s\".", sp.first, sp.second);
		this->m_lstSubs.AddString(str);
	}
}

CReplaceDlg::CSTRPAIR& CReplaceDlg::geti(int _i) {
	SUBSLIST::iterator si = this->m_subslist.begin();
	for (int i = 0; i < _i; i++) {
		++si;
	}
	return *si;
}

CReplaceDlg::SUBSLISTI CReplaceDlg::getsi(int _i) {
	SUBSLISTI si = this->m_subslist.begin();
	for (int i = 0; i < _i; i++) {
		++si;
	}
	return si;
}

void CReplaceDlg::OnDblclkListSubstitude()
{
	// TODO: Add your control notification handler code here
	CReplaceDlg::CSTRPAIR sp;
	int cs = this->m_lstSubs.GetCurSel();
	if (cs < 0) return;

	sp = this->geti(cs);
	CString str;

	CSubDialog sd(sp.second, sp.first);
	if (sd.DoModal() == IDOK) {
		this->m_lstSubs.DeleteString(cs);
		this->m_subslist.erase(getsi(cs));
		sp.first = sd.m_strSrc;
		sp.second = sd.m_strDest;
		this->m_subslist.push_back(sp);
		CString str;
		str.Format("替换\"%s\"到\"%s\".", sp.first, sp.second);
		this->m_lstSubs.AddString(str);
	}
}

void CReplaceDlg::OnButtonSremove()
{
	// TODO: Add your control notification handler code here
	int cs = this->m_lstSubs.GetCurSel();
	if (cs < 0) return;
	this->m_lstSubs.DeleteString(cs);
	if (cs > 0) {
		this->m_lstSubs.SetCurSel(cs - 1);
	}
	SUBSLISTI si = this->getsi(cs);
	this->m_subslist.erase(si);
}

void CReplaceDlg::OnButtonSclear()
{
	m_lstSubs.ResetContent();
	this->m_subslist.clear();
}

struct SUBSTRUCT {
	LPBYTE src;		// in  替换原数据
	LPBYTE dest;		// out 替换结果
	LPBYTE ssrc;		// in  模版源数据
	LPBYTE sdest;		// in  模版目标数据
	LONG nsrc;		// in
	LONG ndest;		// out
	LONG nssrc;		// in
	LONG nsdest;		// in
};

int substitude(SUBSTRUCT& ss) {
	LPBYTE ps = ss.src, pd = ss.dest;
	long si = 0, di = 0;
	long counts = 0;
	for (; si < ss.nsrc; ) {
		int xi;
		BOOL match = FALSE;
		if (ps[si] == ss.ssrc[0]) {
			// src[si..si+nssrc-1] <==> ssrc[0..nssrc-1]
			match = TRUE;
			for (xi = 0; xi < ss.nssrc; xi++) {
				if (ps[si + xi] != ss.ssrc[xi]) {
					match = FALSE;
					break;
				}
			}
			if (match == TRUE) {
				// substitude!
				// src[si..si+nssrc-1] ==> dest[di..di+nsdest-1]
				si += ss.nssrc;
				for (xi = 0; xi < ss.nsdest; xi++) {
					pd[di + xi] = ss.sdest[xi];
				}
				di += ss.nsdest;
				counts++;
			}
		}
		if (!match) {
			pd[di] = ps[si];
			si++;
			di++;
		}
	}
	ss.ndest = di;
	return counts;
}

void CReplaceDlg::OnButtonSubstitude()
{
	//CSubstitudingDialog sd(this);
	//sd.subs();

	int cFiles = m_lstFiles.GetCount();
	int cSubs = m_lstSubs.GetCount();

	FILE *f = NULL;
	BYTE d[MAXFILESIZE];
	BYTE dd[MAXFILESIZE];
	LONG fs = 0;
	CString fn;
	CString sn;
	//CReplaceDlg::CSTRPAIR sp;
	CSubstitudingDialog subdlg;

	for (int iF = 0; iF < cFiles; iF++) {
		this->m_lstFiles.GetText(iF, fn);

		this->m_strCurrentFilename = fn;
		UpdateData(FALSE);

		f = fopen(fn, "r+b");
		if (f == NULL) {
			if (MessageBox(_T("打开文件错误,继续下一个文件的替换?"), NULL, MB_YESNO) == IDNO) {
				break;
			} else {
				continue;
			}
		}
		fseek(f, 0, SEEK_END);
		fs = ftell(f);
		fseek(f, 0, SEEK_SET);

		fread(d, 1, fs, f);
		fclose(f);

		LONG lastsize = fs;
		SUBSTRUCT ss;
		ss.src = d;
		ss.dest = dd;
		for (int iS = 0; iS < cSubs; iS++) {
			CSTRPAIR& sp = this->geti(iS);

			this->m_strSubcon.Format("替换\"%s\"到\"%s\".", sp.first, sp.second);
			UpdateData(FALSE);

			ss.ssrc = (LPBYTE)(LPCTSTR)sp.first;
			ss.sdest = (LPBYTE)(LPCTSTR)sp.second;
			ss.nssrc = sp.first.GetLength();
			ss.nsdest = sp.second.GetLength();

			ss.nsrc = lastsize;
			long scount = substitude(ss);
			lastsize = ss.ndest;
			memcpy(d, dd, lastsize);
		}

		f = fopen(fn, "wb");
		if (f == NULL) {
			if (MessageBox(_T("不能写入文件!继续下一个文件替换?"), NULL, MB_YESNO) == IDNO) {
				break;
			} else {
				continue;
			}
		}
		fwrite(d, 1, lastsize, f);
		fclose(f);
	}
}
