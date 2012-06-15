// SComp_ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SComp_Client.h"
#include "SComp_ClientDlg.h"
#include "PrettyResultDialog.h"

#include <_SComp.h>
#include "SComp.h"

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
// CSComp_ClientDlg dialog

CSComp_ClientDlg::CSComp_ClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSComp_ClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSComp_ClientDlg)
	m_nWidth = 16;
	m_nDepth = 3;
	m_strResult = _T("");
	m_fTemp = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSComp_ClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSComp_ClientDlg)
	DDX_Control(pDX, IDC_LIST_FILECOMP, m_lstFComp);
	DDX_Control(pDX, IDC_COMBO_DECORATE, m_cboDecorate);
	DDX_Control(pDX, IDC_COMBO_ALGOR, m_cboAlgorithm);
	DDX_Text(pDX, IDC_EDIT_COMP_WIDTH, m_nWidth);
	DDV_MinMaxLong(pDX, m_nWidth, 1, 256);
	DDX_Text(pDX, IDC_EDIT_COMP_DEPTH, m_nDepth);
	DDV_MinMaxLong(pDX, m_nDepth, 1, 256);
	DDX_Text(pDX, IDC_STATIC_COMP_RESULT, m_strResult);
	DDV_MaxChars(pDX, m_strResult, 256);
	DDX_Text(pDX, IDC_EDIT_FILETEMP, m_fTemp);
	DDV_MaxChars(pDX, m_fTemp, 256);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSComp_ClientDlg, CDialog)
	//{{AFX_MSG_MAP(CSComp_ClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_BROWSE_TEMP, OnButtonBrowseTemp)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, OnButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_REMOVE, OnButtonRemove)
	ON_LBN_DBLCLK(IDC_LIST_FILECOMP, OnDblclkListFilecomp)
	ON_BN_CLICKED(IDC_BUTTON_PRETTY_RESULT, OnButtonPrettyResult)
	ON_BN_CLICKED(IDC_BUTTON_COMP, OnButtonComp)
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, OnButtonAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSComp_ClientDlg message handlers

BOOL CSComp_ClientDlg::OnInitDialog()
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
	m_cboAlgorithm.SetCurSel(0);
	m_cboDecorate.SetCurSel(1);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSComp_ClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSComp_ClientDlg::OnPaint()
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

HCURSOR CSComp_ClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSComp_ClientDlg::OnButtonBrowseTemp()
{
	// TODO: Add your control notification handler code here
	CFileDialog	fd(TRUE, "txt", "比较模版.txt",
				OFN_FILEMUSTEXIST,
				"模版文件(比较模版.txt)|比较模版.txt|文本文件(*.txt)|*.txt|所有文件|*.*||");
	if (fd.DoModal() == IDOK) {
		m_fTemp	= fd.GetPathName();
		UpdateData(FALSE);

	}
}

void CSComp_ClientDlg::OnButtonInsert()
{
	// TODO: Add your control notification handler code here
	CFileDialog	fd(TRUE, "txt", NULL,
				OFN_ALLOWMULTISELECT |
				OFN_FILEMUSTEXIST,
				"文本文件(*.txt)|*.txt|所有文件|*.*||");
	if (fd.DoModal() == IDOK) {
		POSITION	pos;
		CString		fn;
		pos		= fd.GetStartPosition();
		for (; pos != NULL; ) {
			fn	= fd.GetNextPathName(pos);

			m_lstFComp.AddString(fn);
		}
		UpdateData(FALSE);
	}
}

void CSComp_ClientDlg::OnButtonRemove()
{
	// TODO: Add your control notification handler code here
	int	sel = m_lstFComp.GetCurSel();
	if (sel >= 0) {
		m_lstFComp.DeleteString(sel);
	}
}

void CSComp_ClientDlg::compfile(BOOL bDetail)
{
	int	sel	= m_lstFComp.GetCurSel();
	if (sel < 0) return;

	CString	fComp;
	m_lstFComp.GetText(sel, fComp);

	CFile	*pfTemp = NULL, *pfComp = NULL;
	LPBYTE	pTemp	= NULL, pComp	= NULL;
	DWORD	nTemp, nComp;
	size_t	*pcr	= NULL, size_cr;

	if (!UpdateData()) return;

	TRY {
		pfTemp	= new CFile(m_fTemp,	CFile::modeRead | CFile::typeBinary | CFile::shareDenyNone);
		pfComp	= new CFile(fComp,	CFile::modeRead | CFile::typeBinary | CFile::shareDenyNone);

		nTemp	= pfTemp->GetLength() + 1;
		nComp	= pfComp->GetLength() + 1;
		pTemp	= new BYTE[nTemp + 1];
		pComp	= new BYTE[nComp + 1];
		pTemp[nTemp] = pComp[nComp] = 0;

		if (pTemp == NULL || pComp == NULL) {
			if (pTemp != NULL) delete pTemp;
			if (pComp != NULL) delete pComp;
			AfxThrowMemoryException();
		}

		pfTemp->Read((LPVOID)pTemp, nTemp);
		pfComp->Read((LPVOID)pComp, nComp);

		pcr	= new size_t[32768];
		size_cr	= 32768;

		switch (m_cboAlgorithm.GetCurSel()) {
		case 0: // ansi
			stream_comp_byte(pTemp, pComp, nTemp, nComp, m_nWidth, m_nDepth, pcr, &size_cr);
			break;
		case 1: // unicode
			stream_comp_word((LPWORD)pTemp, (LPWORD)pComp, nTemp / 2, nComp / 2, m_nWidth, m_nDepth, pcr, &size_cr);
			break;
		case 2: // multibyte
			stream_comp_mbcs(pTemp, pComp, nTemp, nComp, m_nWidth, m_nDepth, pcr, &size_cr);
			break;
		case 3: // ole
			stream_comp_word((LPWORD)pTemp, (LPWORD)pComp, nTemp / 2, nComp / 2, m_nWidth, m_nDepth, pcr, &size_cr);
			break;
		case 4: // long*
			stream_comp_dword((LPDWORD)pTemp, (LPDWORD)pComp, nTemp / 4, nComp / 4, m_nWidth, m_nDepth, pcr, &size_cr);
			break;
		case 5: // bit*
			//stream_comp_word((LPBYTE)pTemp, (LPBYTE)pComp, nTemp * 8, nComp * 8, m_nWidth, m_nDepth, pcr, &size_cr);
			MessageBox("位串比较尚有问题，改进中。");
			break;
		default: ;
		}
		size_t	crignore	= 0;
		switch (m_cboDecorate.GetCurSel()) {
		case 0: // none
			break;
		case 1: // trim temp end
			crignore	= STREAM_COMP_TRIM_END | STREAM_COMP_LOST;
			break;
		case 2: // trim comp end
			crignore	= STREAM_COMP_TRIM_END | STREAM_COMP_EXTRA;
			break;
		}

		stream_comp_validate(pcr, size_cr, crignore, 0x0F, 0);
		m_strResult.Format("正确：%d 错误：%d 误增：%d 遗漏：%d",
					pcr[0], pcr[1], pcr[2], pcr[3]);
		if (bDetail) {
			char	*pRefResult	= NULL;
			char	*pObjResult	= NULL;
			TRY {
				size_t	size_rbuf	= 0;
				size_t	size_obuf	= 0;
				stream_comp_pretty_result_a(pcr, size_cr, 0x0F, NULL, &size_rbuf, NULL, &size_obuf);
				size_rbuf++;
				size_obuf++;

				pRefResult	= new char[size_rbuf + 1];
				pObjResult	= new char[size_obuf + 1];
				stream_comp_pretty_result_a(pcr, size_cr, 0x0F, pRefResult, &size_rbuf, pObjResult, &size_obuf);

				pTemp[nTemp]		= '\0';
				pComp[nComp]		= '\0';
				rdlg.m_strTemp		= pTemp;
				rdlg.m_strComp		= pComp;
				rdlg.m_strResult	= pRefResult;
				rdlg.UpdateData(FALSE);
				rdlg.ShowWindow(SW_SHOW);
				rdlg.UpdateWindow();
				rdlg.RunModalLoop(MLF_NOIDLEMSG);
			} CATCH(CException, e) {
				e->ReportError();
			} END_CATCH;
			if (pRefResult != NULL) delete[] pRefResult;
			if (pObjResult != NULL) delete[] pObjResult;
		}

		UpdateData(FALSE);
	} CATCH(CException, e) {
		e->ReportError();
	} END_CATCH;

	if (pTemp != NULL) delete[] pTemp;
	if (pComp != NULL) delete[] pComp;
	if (pcr != NULL) delete[] pcr;

	if (pfTemp != NULL) {
		pfTemp->Close();
		delete pfTemp;
	}
	if (pfComp != NULL) {
		pfComp->Close();
		delete pfComp;
	}
}

void CSComp_ClientDlg::OnDblclkListFilecomp() {
	// TODO: Add your control notification handler code here
	compfile(FALSE);
}

void CSComp_ClientDlg::OnButtonPrettyResult()
{
	// TODO: Add your control notification handler code here
	compfile(TRUE);
}

void CSComp_ClientDlg::OnButtonComp()
{
	// TODO: Add your control notification handler code here
	compfile(FALSE);
}

void CSComp_ClientDlg::OnButtonAbout()
{
	// TODO: Add your control notification handler code here
	CAboutDlg	aboutDlg;
	aboutDlg.DoModal();
}
