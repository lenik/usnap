// emDlg.cpp : implementation file
//

#include "stdafx.h"
#include "em.h"
#include "emDlg.h"
#include "helpDialog.h"

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
// CEmDlg dialog

CEmDlg::CEmDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEmDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEmDlg)
	m_bModify1 = FALSE;
	m_bModify2 = FALSE;
	m_txtDataDest1 = _T("");
	m_txtDataDest2 = _T("");
	m_txtDataSrc1 = _T("");
	m_txtDataSrc2 = _T("");
	m_txtFilename1 = _T("");
	m_txtFilename2 = _T("");
	m_bSaveState = FALSE;
	m_strStatus = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmDlg)
	DDX_Check(pDX, IDC_CHECK_MODIFY1, m_bModify1);
	DDX_Check(pDX, IDC_CHECK_MODIFY2, m_bModify2);
	DDX_Text(pDX, IDC_EDIT_DATADEST1, m_txtDataDest1);
	DDX_Text(pDX, IDC_EDIT_DATADEST2, m_txtDataDest2);
	DDX_Text(pDX, IDC_EDIT_DATASRC1, m_txtDataSrc1);
	DDX_Text(pDX, IDC_EDIT_DATASRC2, m_txtDataSrc2);
	DDX_Text(pDX, IDC_EDIT_FILENAME1, m_txtFilename1);
	DDX_Text(pDX, IDC_EDIT_FILENAME2, m_txtFilename2);
	DDX_Check(pDX, IDC_CHECK_SAVESTATE, m_bSaveState);
	DDX_Text(pDX, IDC_STATIC_STATUS, m_strStatus);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEmDlg, CDialog)
	//{{AFX_MSG_MAP(CEmDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_FILEBROWSE1, OnButtonFilebrowse1)
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, OnButtonAbout)
	ON_BN_CLICKED(IDC_BUTTON_FILEBROWSE2, OnButtonFilebrowse2)
	ON_BN_CLICKED(IDC_BUTTON_BEGIN, OnButtonBegin)
	ON_BN_CLICKED(IDC_CHECK_SAVESTATE, OnCheckSavestate)
	ON_BN_CLICKED(IDC_BUTTON_HELP, OnButtonHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmDlg message handlers

BOOL CEmDlg::OnInitDialog()
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
	HKEY k;
	if (RegOpenKey(HKEY_CURRENT_USER, "Software\\CampoSoft\\Modifier", &k) == ERROR_SUCCESS) {
		BYTE buf[1024];
		DWORD bufsize = sizeof(buf);

		if (RegQueryValueEx(k, "bSaveState", NULL, NULL, buf, &bufsize) == ERROR_SUCCESS) {
			m_bSaveState = buf[0] != 0;
			if (m_bSaveState) {		// bSaveState is TRUE
				bufsize = sizeof(buf);
				if (RegQueryValueEx(k, "Filename1", NULL, NULL, buf, &bufsize) == ERROR_SUCCESS)
					m_txtFilename1 = buf;
				bufsize = sizeof(buf);
				if (RegQueryValueEx(k, "Filename2", NULL, NULL, buf, &bufsize) == ERROR_SUCCESS)
					m_txtFilename2 = buf;
				bufsize = sizeof(buf);
				if (RegQueryValueEx(k, "bModify1", NULL, NULL, buf, &bufsize) == ERROR_SUCCESS)
					m_bModify1 = buf[0] != 0;
				bufsize = sizeof(buf);
				if (RegQueryValueEx(k, "bModify2", NULL, NULL, buf, &bufsize) == ERROR_SUCCESS)
					m_bModify2 = buf[0] != 0;
				bufsize = sizeof(buf);
				if (RegQueryValueEx(k, "DataSrc1", NULL, NULL, buf, &bufsize) == ERROR_SUCCESS)
					m_txtDataSrc1 = buf;
				bufsize = sizeof(buf);
				if (RegQueryValueEx(k, "DataSrc2", NULL, NULL, buf, &bufsize) == ERROR_SUCCESS)
					m_txtDataSrc2 = buf;
				bufsize = sizeof(buf);
				if (RegQueryValueEx(k, "DataDest1", NULL, NULL, buf, &bufsize) == ERROR_SUCCESS)
					m_txtDataDest1 = buf;
				bufsize = sizeof(buf);
				if (RegQueryValueEx(k, "DataDest2", NULL, NULL, buf, &bufsize) == ERROR_SUCCESS)
					m_txtDataDest2 = buf;
			} // m_bSaveState == TRUE
		} // if Query "Modifier\\bSaveState" success
		RegCloseKey(k);
	} //if open key "...\\Modifier" success
	else
	{ // default options if key "...\\Modifier" doesn't exists
		m_bModify1 = TRUE;
	}
	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEmDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEmDlg::OnPaint()
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

HCURSOR CEmDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEmDlg::OnButtonFilebrowse1()
{
	// TODO: Add your control notification handler code here
	CFileDialog fileDialog(TRUE);		// TRUE for open

	if (fileDialog.DoModal() == IDOK) {
		m_txtFilename1 = fileDialog.GetPathName();
		this->UpdateData(FALSE);
	}
}

void CEmDlg::OnButtonFilebrowse2()
{
	// TODO: Add your control notification handler code here
	CFileDialog fileDialog(TRUE);		// TRUE for open

	if (fileDialog.DoModal() == IDOK) {
		m_txtFilename2 = fileDialog.GetPathName();
		this->UpdateData(FALSE);
	}
}

void CEmDlg::OnButtonAbout()
{
	// TODO: Add your control notification handler code here
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

// get a number word, return -1 if error occurs
long getWord(CString str, int &pos) {
	char buf[128];
	int i = 0;
	int length = str.GetLength();
	int ordix = 10;

	if (pos >= length) return -1;

	// get a part
	while (pos < length) {
		if (str[pos] != ' ') break;
		pos++;
	}
	while (i < 128 && pos < length) {
		char c = str[pos];
		if (c >= '0' && c <= '9') {
			buf[i++] = str[pos++];
			continue;
		}
		if (c >= 'a' && c <= 'f') {
			buf[i++] = str[pos++];
			ordix = 16;
			continue;
		}
		if (c >= 'A' && c <= 'F') {
			buf[i++] = str[pos++];
			ordix = 16;
			continue;
		}
		if (c == 'H' || c == 'h') ordix = 16;
		if (c == 'O' || c == 'o') ordix = 8;
		if (c == 'B' || c == 'b') ordix = 2;
		pos++;
		break;
	}
	while (pos < length) {
		if (str[pos] != ' ') break;
		pos++;
	}

	buf[i] = '\0';

	return strtol(buf, NULL, ordix);
}

int getData(CString src, BYTE *dest, int nDest) {
	// convert user text to internal data
	// return the length
	int length = src.GetLength();
	BOOL bBinary;
	int i = 0;

	if (length <= 0) return 0;
	if (bBinary = src[0] != '\\') {
		int pos = 0;
		while (i < nDest - 3) {
			long l = getWord(src, pos);
			if (l < 0) break;
			if (l <= 255)
				dest[i++] = (BYTE)l;
			else if (l <= 65536) {
				dest[i++] = (BYTE)(l & 0xFF);
				dest[i++] = (BYTE)(l >> 8);
			} else {
				dest[i++] = (BYTE) (l & 0xFF);
				dest[i++] = (BYTE)((l & 0xFF00) >> 8);
				dest[i++] = (BYTE)((l & 0xFF0000) >> 16);
				dest[i++] = (BYTE) (l >> 24);
			}
		}
		return i;
	} else {	// string
		int pos = 1;
		while (i < nDest && pos < length) {
			dest[i++] = src[pos++];
		}
		return i;
	}
}

BYTE fByte(CFile &f, LONG pos, BOOL bReSeek = TRUE) {
	BYTE b;
	if (bReSeek) f.Seek(pos, CFile::begin);
	f.Read(&b, 1);
	return b;
}

#define BLOCK_SIZE			10000

// get position where BYTE b is in the file f
// return -1 if no found

LONG fFindByte(CFile &f, BYTE b, LONG startpos = 0) {
	LONG length;
	BYTE buf[BLOCK_SIZE];
	int getsize = sizeof(buf);

	TRY {
		length = (LONG)f.GetLength();
		if (length <= 0) return -1;

		while (startpos < length) {
			if (getsize + startpos >= length) getsize = length - startpos;

			f.Seek(startpos, CFile::begin);
			f.Read(buf, getsize);

			for (int i = 0; i < getsize; i++) {
				if (buf[i] == b) {
					return startpos + i;
				}
			}

			startpos += getsize;
		}
		return -1;
	} CATCH (CFileException, e) {
		e->ReportError();
		return -1;
	} END_CATCH;

	return -1;
}

void CEmDlg::UseFormat(CString &str, BYTE *data, int len) {
	CString num;

	str = "";
	for (int i = 0; i < len; i++) {
		num.Format("%02XH ", data[i]);
		str += num;
	}
}

void CEmDlg::OnButtonBegin()
{
	// TODO: Add your control notification handler code here

	CFile f1, f2;
	CFileException e;
	LONG length;
	LONG pos;

#	define D_SRC1		0
#	define D_DEST1		1
#	define D_SRC2		2
#	define D_DEST2		3

	BYTE data[4][MAXDATA];
	int  nData[4];

	BOOL bShouldModify = FALSE;
	BOOL bModifyAll = FALSE;

	UpdateData();

	// 1) Check file
		if (!f1.Open(m_txtFilename1, CFile::modeReadWrite | CFile::typeBinary, &e)) {
			e.ReportError();
			return;
		}
		if (!f2.Open(m_txtFilename2, CFile::modeReadWrite | CFile::typeBinary, &e)) {
			f1.Close();
			e.ReportError();
			return;
		}

		length = min(f1.GetLength(), f2.GetLength());

	// 2) Check entered data
		nData[D_SRC1]	= getData(m_txtDataSrc1, data[D_SRC1], MAXDATA);
		nData[D_SRC2]	= getData(m_txtDataSrc2, data[D_SRC2], MAXDATA);
		nData[D_DEST1]	= getData(m_txtDataDest1, data[D_DEST1], MAXDATA);
		nData[D_DEST2]	= getData(m_txtDataDest2, data[D_DEST2], MAXDATA);

		UseFormat(m_txtDataSrc1, data[D_SRC1], nData[D_SRC1]);
		UseFormat(m_txtDataSrc2, data[D_SRC2], nData[D_SRC2]);
		UseFormat(m_txtDataDest1, data[D_DEST1], nData[D_DEST1]);
		UseFormat(m_txtDataDest2, data[D_DEST2], nData[D_DEST2]);

		m_strStatus = "";

		UpdateData(FALSE);

		if (nData[D_SRC1] == 0 || nData[D_SRC2] == 0) {
			MessageBox("源数据空! ");
			goto Clean;
		}
		if (nData[D_SRC1] != nData[D_SRC2]) {
			int r = MessageBox("两个源数据长度不一致! 是否继续?", "询问", MB_YESNOCANCEL | MB_ICONQUESTION);
			if (r != IDYES) goto Clean;
		}

	// 3) Find position
		// 3a) Find Src

		pos = 0;
		while ((pos = fFindByte(f1, data[D_SRC1][0], pos)) >= 0) {
			TRY {
				BOOL bMatch = TRUE;
				bShouldModify = FALSE;
				// check if it matches the whole word
				for (int i = 1; i < nData[D_SRC1]; i++) {
					if (fByte(f1, pos + i) != data[D_SRC1][i]) {
						bMatch = FALSE;
						break;
					}
				}
				// check if it matches the same pos at the second file
				if (bMatch) {
					for (int i = 0; i < nData[D_SRC2]; i++) {
						if (fByte(f2, pos + i) != data[D_SRC2][i]) {
							bMatch = FALSE;
							break;
						}
					}
					if (bMatch) {
						// found 1 position where both data matched
						// we then modify it
						if (!bModifyAll) {
							int r;
							CString str;
							str.Format("找到一处匹配(位置%d, %xH), 是否替换? ", pos, pos);
							r = MessageBox(str, "数据找到", MB_YESNOCANCEL | MB_ICONQUESTION);
							if (r == IDCANCEL) goto Clean;
							if (r == IDYES) {
								// modify it
								bShouldModify = TRUE;
								r = MessageBox("全部替换吗?", "是否全部替换", MB_YESNOCANCEL | MB_ICONQUESTION);
								if (r == IDCANCEL) goto Clean;
								bModifyAll = r == IDYES ? TRUE : FALSE;
							}
						} else {
							bShouldModify = TRUE;
						} // if user accept
					} // if match both
				} // if match single
			} CATCH (CFileException, e) {
				e->ReportError();
				m_strStatus = "查找匹配串时发生错误";
				goto Clean;
			} END_CATCH;

			if (bShouldModify) {
				int i;
				BYTE b;
				TRY {
					if (m_bModify1) {
						for (i = 0; i < nData[D_DEST1]; i++) {
							b = data[D_DEST1][i];
							f1.Seek(pos + i, SEEK_SET);
							f1.Write(&b, 1);
						}
					}
					if (m_bModify2) {
						for (i = 0; i < nData[D_DEST2]; i++) {
							b = data[D_DEST2][i];
							f2.Seek(pos + i, SEEK_SET);
							f2.Write(&b, 1);
						}
					}
				} CATCH (CFileException, e) {
					e->ReportError();
					m_strStatus = "修改文件是发生错误";
					goto Clean;
				} END_CATCH;
			}
			pos++;
		} // while fFindByte >= 0
		m_strStatus = "修改成功!";
	// x) Clean part
Clean:
		f1.Close();
		f2.Close();
		UpdateData(FALSE);
}

void CEmDlg::OnCheckSavestate()
{
	// TODO: Add your control notification handler code here
	HKEY k;
	BYTE buf[1024];
	DWORD bufsize = sizeof(buf);

	UpdateData();

	if (RegOpenKey(HKEY_CURRENT_USER, "Software\\CampoSoft\\Modifier", &k) != ERROR_SUCCESS) {
		// create if not existed
		if (RegCreateKey(HKEY_CURRENT_USER, "Software\\CampoSoft\\Modifier", &k) != ERROR_SUCCESS) {
			goto Error;
		}
	}

	buf[0] = m_bSaveState;
	RegSetValueEx(k, "bSaveState", NULL, REG_BINARY, buf, 1);

	if (m_bSaveState) {
		RegSetValueEx(k, "Filename1", 0, REG_SZ, (LPBYTE)(LPCTSTR)m_txtFilename1, m_txtFilename1.GetLength());
		RegSetValueEx(k, "Filename2", 0, REG_SZ, (LPBYTE)(LPCTSTR)m_txtFilename2, m_txtFilename2.GetLength());
		buf[0] = m_bModify1;
		RegSetValueEx(k, "bModify1", 0, REG_BINARY, buf, 1);
		buf[0] = m_bModify2;
		RegSetValueEx(k, "bModify2", 0, REG_BINARY, buf, 1);
		RegSetValueEx(k, "DataSrc1", 0, REG_SZ, (LPBYTE)(LPCTSTR)m_txtDataSrc1, m_txtDataSrc1.GetLength());
		RegSetValueEx(k, "DataSrc2", 0, REG_SZ, (LPBYTE)(LPCTSTR)m_txtDataSrc2, m_txtDataSrc2.GetLength());
		RegSetValueEx(k, "DataDest1", 0, REG_SZ, (LPBYTE)(LPCTSTR)m_txtDataDest1, m_txtDataDest1.GetLength());
		RegSetValueEx(k, "DataDest2", 0, REG_SZ, (LPBYTE)(LPCTSTR)m_txtDataDest2, m_txtDataDest2.GetLength());
	}

	RegCloseKey(k);
	return;

Error:
	MessageBox("保存选项数据时出错");

}

void CEmDlg::OnOK()
{
	// TODO: Add extra validation here
	OnCheckSavestate();

	CDialog::OnOK();
}

void CEmDlg::OnButtonHelp()
{
	// TODO: Add your control notification handler code here
	CHelpDialog helpDialog;
	helpDialog.DoModal();
}
