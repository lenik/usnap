// scomp2_client2Dlg.cpp : implementation file
//

#include "stdafx.h"

//	#define _DETAIL_DEBUG

#include "scomp2_client2.h"
#include "scomp2_client2Dlg.h"
#include "DetailDialog.h"
#include "SettingDialog.h"
#include "AdvancedSettingDialog.h"
#include "sc_plugin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString	units_desc(stream_units_work_bytes& o) {
	return *(new CString((TCHAR)o.d()));
}
CString units_desc(stream_units_work_words& o) {
	switch (sizeof(TCHAR)) {
	case 1: {
		char	c1 = o.d() >> 8, c2 = o.d() & 0xFF;
		CString r1(c1);
		CString r2(c2);
		return r1 + r2;
		break;
		}
	case 2:
		return *(new CString((TCHAR)o.d()));
	}
	__assume(0);
}
CString units_desc(stream_units_work_dwords& o) {
	CString r;
	r.Format(_T("%ld"), o.d());
	return r;
}
CString units_desc(stream_units_work_mbcs& o) {
	CString r;
	size_t	d = o.d();
	if (d < 0xFF) {
#ifdef _DEBUG
		if (d == _T(' ')) {
			d	= _T('_');
		}
#endif
		r	= (TCHAR)d;
	} else {
		if (d < 0xFFFFul) {
			switch (sizeof(TCHAR)) {
			case 1:
				r.Format(_T("%c%c"), (TCHAR)(d >> 8), (TCHAR)(d & 0xFF));
				break;
			case 2:
				r	= (TCHAR)d;
			}
		} else {
			switch (sizeof(TCHAR)) {
			case 1:
				r.Format(_T("%c%c%c%c"),
					(TCHAR)(d >> 24),
					(TCHAR)((d >> 16) & 0xFF),
					(TCHAR)((d >> 8) & 0xFF),
					(TCHAR)(d & 0xFF)
					);
				break;
			case 2:
				r.Format(_T("%c%c"),
					(TCHAR)(d >> 16),
					(TCHAR)(d & 0xFFFFul)
					);
			}
		}
	}
	return r;
}
CString units_desc(stream_units_work_bits& o) {
	return *(new CString(_T("<not impl>")));
}

CString units_desc(stream_units_work& o) {
	switch (o.id) {
	case 1:
		return units_desc(*(stream_units_work_bytes *)&o);
	case 2:
		return units_desc(*(stream_units_work_words *)&o);
	case 4:
		return units_desc(*(stream_units_work_dwords *)&o);
	case 3:
		return units_desc(*(stream_units_work_mbcs *)&o);
	case 5:
		return units_desc(*(stream_units_work_bits *)&o);
	case 0:
	default:
		return *(new CString(_T("*")));
	}
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
// CScomp2_client2Dlg dialog

CScomp2_client2Dlg::CScomp2_client2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScomp2_client2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScomp2_client2Dlg)
	m_fTemp = _T("");
	m_strResult = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScomp2_client2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScomp2_client2Dlg)
	DDX_Control(pDX, IDC_LIST_FILECOMP, m_lstFComp);
	DDX_Text(pDX, IDC_EDIT_FILETEMP, m_fTemp);
	DDX_Text(pDX, IDC_STATIC_COMP_RESULT, m_strResult);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CScomp2_client2Dlg, CDialog)
	//{{AFX_MSG_MAP(CScomp2_client2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EXIT, OnButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, OnButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_REMOVE, OnButtonRemove)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE_TEMP, OnButtonBrowseTemp)
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, OnButtonAbout)
	ON_LBN_DBLCLK(IDC_LIST_FILECOMP, OnDblclkListFilecomp)
	ON_BN_CLICKED(IDC_BUTTON_COMP, OnButtonComp)
	ON_BN_CLICKED(IDC_BUTTON_PRETTY_RESULT, OnButtonPrettyResult)
	ON_BN_CLICKED(IDC_BUTTON_SETTING, OnButtonSetting)
	ON_BN_CLICKED(IDC_BUTTON_BATCH, OnButtonBatch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScomp2_client2Dlg message handlers

BOOL CScomp2_client2Dlg::OnInitDialog()
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
	CWinApp	*app = AfxGetApp();
	CString s, s1;
	int i;
	this->m_fTemp	= app->GetProfileString(_T("config"), _T("template_filename"));
	for (i = 0; i < 1000; i++) {
		s1.Format(_T("object_filename_%d"), i);
		s	= app->GetProfileString(_T("config"), s1);
		if (s.GetLength() > 0) {
			this->m_lstFComp.AddString(s);
		} else {
			break;
		}
	}

	this->m_strResult	= _T("����ע���������Ŀ¼�µ����...");
	UpdateData(FALSE);

	HMODULE	hmod;
	DllRegisterServer_proc regproc;
	hmod	= LoadLibrary(_T("DHTMLED.OCX"));
	if (hmod != NULL) {
		regproc	= (DllRegisterServer_proc)GetProcAddress(hmod, _T("DllRegisterServer"));
		if (regproc != NULL) {
			regproc();
		}
		FreeLibrary(hmod);
	}
	hmod	= LoadLibrary(_T("scw01.dll"));
	if (hmod != NULL) {
		regproc = (DllRegisterServer_proc)GetProcAddress(hmod, _T("DllRegisterServer"));
		if (regproc != NULL) {
			regproc();
		}
		FreeLibrary(hmod);
	}

	this->m_strResult	= _T("�Ѿ�ע���˳�������Ŀ¼������������");
	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CScomp2_client2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CScomp2_client2Dlg::OnPaint()
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
HCURSOR CScomp2_client2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CScomp2_client2Dlg::OnOK()
{
}

void CScomp2_client2Dlg::OnCancel()
{
}

void CScomp2_client2Dlg::OnButtonExit()
{
	// TODO: Add your control notification handler code here
	CWinApp *app = AfxGetApp();
	CString s, s1;
	int i;

	UpdateData(TRUE);
	app->WriteProfileString(_T("config"), _T("template_filename"), this->m_fTemp);
	for (i = 0; i < this->m_lstFComp.GetCount(); i++) {
		s1.Format(_T("object_filename_%d"), i);
		this->m_lstFComp.GetText(i, s);
		app->WriteProfileString(_T("config"), s1, s);
	}
	s1.Format(_T("object_filename_%d"), i);
	app->WriteProfileString(_T("config"), s1, NULL);

	CDialog::OnOK();
}

void CScomp2_client2Dlg::OnButtonInsert()
{
	CFileDialog	fd(TRUE, "txt", NULL,
				OFN_ALLOWMULTISELECT |
				OFN_FILEMUSTEXIST,
				"�ı��ļ�(*.txt)|*.txt|�����ļ�|*.*||");
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

void CScomp2_client2Dlg::OnButtonRemove()
{
	int	sel = m_lstFComp.GetCurSel();
	if (sel >= 0) {
		m_lstFComp.DeleteString(sel);
		if (m_lstFComp.GetCount() > 0) {
			m_lstFComp.SetSel(0);
		}
	}
}

void CScomp2_client2Dlg::OnButtonBrowseTemp()
{
	CFileDialog	fd(TRUE, "txt", "�Ƚ�ģ��.txt",
				OFN_FILEMUSTEXIST,
				"ģ���ļ�(�Ƚ�ģ��.txt)|�Ƚ�ģ��.txt|�ı��ļ�(*.txt)|*.txt|�����ļ�|*.*||");
	if (fd.DoModal() == IDOK) {
		m_fTemp	= fd.GetPathName();
		UpdateData(FALSE);
	}
}

void CScomp2_client2Dlg::OnButtonAbout()
{
	CAboutDlg	aboutDlg;
	aboutDlg.DoModal();
}

void CScomp2_client2Dlg::OnDblclkListFilecomp()
{
	this->OnButtonComp();
}

void CScomp2_client2Dlg::OnButtonComp()
{
	CString obj;
	res_easy_type res;
	if (UpdateData(TRUE)) {
		int	cs = this->m_lstFComp.GetCurSel();
		if (cs >= 0) {
			this->m_lstFComp.GetText(cs, obj);
			res = compare(this->m_fTemp, obj, FALSE);
			showres(res);
		}
	}
}

void CScomp2_client2Dlg::OnButtonPrettyResult()
{
//	CDetailDialog dd;
//	dd.DoModal();
	CString obj;
	res_easy_type res;
	if (UpdateData(TRUE)) {
		int	cs = this->m_lstFComp.GetCurSel();
		if (cs >= 0) {
			this->m_lstFComp.GetText(cs, obj);
			res = compare(this->m_fTemp, obj, TRUE);
			showres(res);
		}
	}
}

void CScomp2_client2Dlg::OnButtonSetting()
{
	CSettingDialog sd;
	sd.DoModal();
}

void CScomp2_client2Dlg::OnButtonBatch()
{
	res_easy_type res;
	stream_units_work_bytes	tmp;	// ���ڲ������

	if (UpdateData(TRUE)) {
		int	i;
		CString body;		// HTMLȫ��
		CString	smid;		// HTML��ϸ����
		CString each;		// HTML������¼
		CString obj;		// �ļ���

		CString s_algor;
		CString s_decor;
		CString s_score;

		getconfigs();

		switch (this->configs.algor) {
		case 0:
			s_algor	= _T("ANSI�ַ���");
			break;
		case 1:
			s_algor	= _T("Unicode�ַ���");
			break;
		case 2:
			s_algor	= _T("OLE�ַ���");
			break;
		case 3:
			s_algor	= _T("Multibyte����ַ���");
			break;
		case 4:
			s_algor	= _T("����(Long *)");
			break;
		case 5:
			s_algor	= _T("λ��");
			break;
		}

		switch (this->configs.decor) {
		case 0:
			s_decor	= _T("����ģʽ");
			break;
		case 1:
			s_decor	= _T("����ģ���ļ���β");
			break;
		case 2:
			s_decor	= _T("���ԱȽ��ļ���β");
			break;
		case 3:
			s_decor	= _T("��Сģʽ");
			break;
		}

		s_score	= _T("��ȷ-����*5-����*5-��©*5");
		if (score_plugin_mode != spm_none) {
			s_score	= _T("δ����");
		}

		int saveExcel;
		saveExcel	= MessageBox(_T("�����������Excel�ļ�ô? ѡ��񽫱�����HTML�ļ�, ѡ���Ǳ�����Office97�����֧��. "), _T("ѡ���Ƿ񱣴�Excel�ļ�"), MB_YESNO);
		if (saveExcel == IDCANCEL) return;

		if (saveExcel == IDYES) {
			CFileDialog	fd(FALSE, _T("xls"), _T("�ȽϽ��.xls"));
			if (fd.DoModal() != IDOK) return;

			if (!this->m_excel_generator.CreateDispatch(_T("StreamWorkHelper01.G1"))) {
				return;
			}
			this->m_excel_generator.SetMagicNum(54656368);
			this->m_excel_generator.SetS_savetofile(fd.GetPathName());

			this->m_excel_generator.SetS_tempfile(this->m_fTemp);
			this->m_excel_generator.SetS_algor(s_algor);
			this->m_excel_generator.SetS_decor(s_decor);
			this->m_excel_generator.SetS_configfile(this->configs.filename);
			// ��δ�ص���չ��
			this->m_excel_generator.SetS_scoreplugfile(this->configs.plugin);
			this->m_excel_generator.SetN_d1(this->configs.depth);
			this->m_excel_generator.SetN_w1(this->configs.width);
			this->m_excel_generator.SetN_fuzzy(this->configs.fuzzysame);
			this->m_excel_generator.SetN_precise(this->configs.precise);
			this->m_excel_generator.ClearCode();

			this->m_excel_generator.SetB_showExcelWindow(TRUE);
		} else {
			body	= _T("<html><body bgcolor=\"#CCFFCC\"><p><font size=\"-1\" color=\"#006600\">"
					"������[������|һά������(�ϸ�Ԫ)|ģ�����Ƚ�|���ܽ���|Beta|�����Ƚ�]��������<br>"
					"��Ȩ���� (C)TopCroak Software(�ҿ����), 1997-2001</font></p><p>"
					"<font size=\"+3\"><u><i><b><font color=\"#000099\">�����ȽϽ������</i></font></b></u></font></p>"
					"<table><tr><td>&gt;&gt;&gt;</td><td><table>"
					);

			each.Format(_T("<tr> <td> <div align=\"right\"><font color=\"#0000CC\"><i>ģ���ļ�</i></font></div></td>"
					"<td colspan=\"2\"><i>%s</i></td>"
					"</tr><tr> <td> <div align=\"right\"><font color=\"#0000CC\"><i>ʹ���㷨</i></font></div></td>"
					"<td colspan=\"2\"><i>%s</i></td>"
					"</tr><tr> <td> <div align=\"right\"><font color=\"#0000CC\"><i>��������</i></font></div></td>"
					"<td colspan=\"2\"><i>%s</i></td>"
					"</tr><tr> <td> <div align=\"right\"><font color=\"#0000CC\"><i>�Ƚ����</i></font></div></td>"
					"<td><i>%d</i></td>"
					"<td><i><font color=\"#003399\">��</font></i></td></tr><tr> <td> "
					"<div align=\"right\"><font color=\"#0000CC\"><i>�ȽϹ��</i></font></div></td>"
					"<td><i>%d</i></td>"
					"<td><i><font color=\"#003399\">��</font></i></td></tr><tr> <td> "
					"<div align=\"right\"><font color=\"#0000CC\"><i>�Ʒַ���</i></font></div></td>"
					"<td colspan=\"2\"><i>%s</i></td>"
					"</tr><tr> <td colspan=\"3\"><font color=\"#0000CC\"><i></i></font></td></tr><tr> <td> "
					"<div align=\"right\"><font color=\"#0000CC\"><i>���в�����Ʒ</i></font></div></td>"
					"<td><i>%d</i></td>"
					"<td><i><font color=\"#003399\">��</font></i></td></tr><tr> <td> "
					"<div align=\"right\"><font color=\"#0000CC\"><i>�ۼ����</i></font></div></td>"
					"<td colspan=\"2\"><i>%s</i></td>"
					"</tr></table></td></tr></table>"
					"<p><i><font size=\"+2\"><u><b><font color=\"#330099\">��ϸ����б�</font></b></u></font></i></p>"
					),
					(LPCTSTR)this->m_fTemp,			// %s ģ���ļ�
					(LPCTSTR)s_algor,			// %s ʹ���㷨
					(LPCTSTR)s_decor,			// %s ��������
					configs.depth,				// %d �Ƚ����
					configs.width,				// %d �ȽϹ��
					(LPCTSTR)s_score,			// %s �Ʒַ���
					m_lstFComp.GetCount(),			// %d ���в�����Ʒ
					_T("N/A")				// %s �ۼ����
					);
			body	+= each;
			smid	= _T("<table><tr> <td>&gt;&gt;&gt;</td><td> <table>");
		}

		// ��¼����
		for (i = 0; i < this->m_lstFComp.GetCount(); i++) {
			this->m_lstFComp.GetText(i, obj);
			this->m_lstFComp.SetCurSel(i);
			res = compare(this->m_fTemp, obj, FALSE);
			int	pp;
			if ((pp = obj.ReverseFind(_T('\\'))) > 0) {
				obj.Delete(0, pp + 1);
			}
			showres(res);
			// �ۼƽ��...
			if (saveExcel == IDYES) {
				this->m_excel_generator.AddScore(
					(LPCTSTR)obj,
					res.match,
					res.unmatch,
					res.extra,
					res.lost
					);
			} else {
				int score = advanced_score(res.match, res.unmatch, res.extra, res.lost);
				int less_than_0 = score < 0;
				if (score < 0) score = 0;
				each.Format(_T(
					"<tr><td><b><font color=\"#003333\">%s</font><b></td>"
					"<td><font color=\"#0000FF\">��ȷ��%d</font></td>"
					"<td><font color=\"#FF0000\">����%d</font></td>"
					"<td><font color=\"#990099\">������%d</font></td>"
					"<td><font color=\"#666600\">��©��%d</font></td>"
					"</tr><tr> <td>&nbsp;</td><td colspan=\"4\"><font color=\"#6666FF\">"
					"�Ʒ֣�%s%d%s = %d-%d*5-%d*5-%d*5</font></td></tr><tr> <td colspan=\"5\"></td></tr>"
					),
					(LPCTSTR)obj,
					res.match,
					res.unmatch,
					res.extra,
					res.lost,
					less_than_0 ? _T("<font color=\"#ff0000\">") : _T(""),
						score,
					less_than_0 ? _T("</font>") : _T(""),
					res.match, res.unmatch, res.extra, res.lost
					);
				smid	+= each;
			}
		}

		// ��β����
		if (saveExcel == IDYES) {
			this->m_strResult	= _T("��������Excel�ļ�, ���Ժ�...");
			UpdateData(FALSE);
			this->m_excel_generator.Generate();
			this->m_strResult	= _T("Excel�ļ�������ϡ�");
			UpdateData(FALSE);
		} else {
			smid	+= _T("</table></td></tr></table><br><hr><p align=\"center\"><font size=\"-1\" color=\"#006600\">"
					"TopCroak Software(�ҿ����) | Campo Accelerate(��ԭ��������) | Stream Works(������)</font><font color=\"#006600\"><br><font size=\"-1\">"
					"���ߣ�Mr. DanSei(л����) <br>����ͽ��飺<a href=\"mailto:dansei@126.com\">dansei@126.com</a></font></font></p></body></html>"
					);
			body	+= smid;
			// ����DHTML����
			CDetailDialog dd(NULL, body);
			dd.DoModal();
		}
	}
}

void CScomp2_client2Dlg::showres(res_easy_type res) {
	m_strResult.Format(_T("��ȷ:%d, ����:%d, ����:%d, ȱ��:%d"),
		res.match,
		res.unmatch,
		res.extra,
		res.lost);
	this->UpdateData(FALSE);
}

res_easy_type CScomp2_client2Dlg::compare(CString f1, CString f2, BOOL detail, BOOL bgetconfigs) {
	res_easy_type ret;
	stream_units_work	*s1, *s2;

	ret.op	= -1;

	if (bgetconfigs) this->getconfigs();

	// �����ļ��ֽ�(���������Ż����벿�ֻ�ȫ��)
		LPBYTE	data_me = NULL, data_obj = NULL;
		LONG	size_me, size_obj;
		TRY {
			CFile fme(f1, CFile::modeRead | CFile::shareDenyNone);
			CFile fobj(f2, CFile::modeRead | CFile::shareDenyNone);
			if (this->configs.decor == config_type::d_whole ||
				this->configs.decor == config_type::d_mebig) {
				size_me = fme.GetLength();
			} else {
				size_me = fme.GetLength() <= fobj.GetLength() ?
					fme.GetLength() : fobj.GetLength();
			}
			data_me	= new BYTE[size_me + 1];
			fme.Read((void *)data_me, size_me);
			if (this->configs.decor == config_type::d_whole ||
				this->configs.decor == config_type::d_mesmall) {
				size_obj = fobj.GetLength();
			} else {
				size_obj = fobj.GetLength() <= fme.GetLength() ?
					fobj.GetLength() : fme.GetLength();
			}
			data_obj = new BYTE[size_obj + 1];
			fobj.Read((void *)data_obj, size_obj);
			fme.Close();
			fobj.Close();
		} CATCH(CFileException, fe) {
			fe->ReportError();
			return ret;
		} AND_CATCH(CMemoryException, me) {
			me->ReportError();
			if (data_me != NULL) delete[] data_me;
			if (data_obj != NULL) delete[] data_obj;
			return ret;
		} END_CATCH;

	// �����û�������
		switch (this->configs.algor) {
		case this->config_type::s_ole:
		case this->config_type::s_unicode:
			s1	= new stream_units_work_words;
			s2	= new stream_units_work_words;
			break;
		case this->config_type::s_longs:
			s1	= new stream_units_work_dwords;
			s2	= new stream_units_work_dwords;
			break;
		case this->config_type::s_bits:
			s1	= new stream_units_work_bits;
			s2	= new stream_units_work_bits;
			break;
		//case this->config_type::s_manual:
		case this->config_type::s_mbcs:
			s1	= new stream_units_work_mbcs;
			s2	= new stream_units_work_mbcs;
			break;
		case this->config_type::s_ansi:
		default:
			s1	= new stream_units_work_bytes;
			s2	= new stream_units_work_bytes;
		}
		s1->c.bid	= 0;		// ǿ�Ƶ���
		s1->c.parts	= (stream_units_work::stream_units_work_compare::parts_enum)
			this->configs.decor;	// decor_enum --> parts_enum
		s1->c.w1	= this->configs.width;
		s1->c.d1	= this->configs.depth;

		s1->c.fuzzy_same	= this->configs.fuzzysame;
		s1->c.combine_error	= this->configs.com_error;
		s1->c.compare_mode	= this->configs.precise;

		s1->c.samelists		= this->configs.sames;
		s1->c.skiplist		= this->configs.skips;
		s2->c.samelists		= this->configs.sames;
		s2->c.skiplist		= this->configs.skips;

		switch (score_plugin_mode) {
		case spm_none:
			s1->c.score_proc	= stream_units_work::stream_units_work_compare::default_score;
			break;
		case spm_dll:
			s1->c.score_proc	= score_plugin_dll;
			break;
		case spm_activex:
		default:
			s1->c.score_proc	= advanced_score;
		}

		if (detail) {
			s1->c.save_result	= 1;
		} else {
			s1->c.save_result	= 0;
		}
		s1->init((void *)data_me, size_me, -1);
		s2->init((void *)data_obj, size_obj, -1);

	// �Ƚ�
		if (s1->c.compare(*s2) == 0) {
			ret.match	= s1->c.match;
			ret.unmatch	= s1->c.unmatch;
			ret.extra	= s1->c.extra;
			ret.lost	= s1->c.lost;

			if (detail) {
				// MessageBox(_T("��ϸ��Ϣ����:..."));
				this->showdetail(*s1, *s2);
			}
		} else {
			MessageBox(_T("��������"));
		}
	// �˳�
		delete[] data_me;
		delete[] data_obj;
	return ret;
}

void CScomp2_client2Dlg::getconfigs() {
	CWinApp *app = AfxGetApp();
	this->configs.filename	= app->GetProfileString(_T("config"), _T("configfile"));
	this->configs.algor	= (config_type::algor_enum)app->GetProfileInt(_T("config"), _T("algor"), 0);
	this->configs.decor	= (config_type::decor_enum)app->GetProfileInt(_T("config"), _T("decor"), 0);
	this->configs.width	= app->GetProfileInt(_T("config"), _T("width"), 0);
	this->configs.depth	= app->GetProfileInt(_T("config"), _T("depth"), 0);
	this->configs.fuzzysame	= app->GetProfileInt(_T("config"), _T("fuzzy_same"), 1000) / 1000.0f;
	this->configs.com_error	= app->GetProfileInt(_T("config"), _T("combine_error"), 1);
	this->configs.precise	= (stream_units_work::stream_units_work_compare::compare_mode_enum)
					app->GetProfileInt(_T("config"), _T("compare_mode"), 1);

	// ������ͬ��Ԫ��
	TCHAR rets[16384], *prets = rets;
	DWORD nsize;
	nsize = ::GetPrivateProfileSection(_T("��ͬ��Ԫ��"), rets, sizeof(rets), this->configs.filename);
	this->configs.sames.clear();
	for (; prets - rets < nsize && *prets != _T('\0'); ) {
		// prets += ::(lstrlen(prets) + 1)
		// pretsָ��һ�� xxx=a1,b1;a2,b2,c2;a3,b3\0yyy=...\0\0 ��
		while (*prets != _T('=') && *prets) prets++;
		if (*prets == _T('\0')) break;
		prets++; // ���Ե�ʽ���(����'=')
		// �����ֵ��
		szlist	szs;
		size_t	c;
		int	c_offset;
		TCHAR	*p_section, *p_column;
		for (p_section = prets; *p_section; ) {
			c		= 0;
			c_offset	= 0;
			for (p_column = p_section; *p_column; ) {
				if (sizeof(TCHAR) == 1) {
					c		|= ((BYTE)*p_column) << c_offset;
					c_offset	+= 8;
				} else {
					c		|= ((WORD)*p_column) << c_offset;
					c_offset	+= 16;
				}
				p_column++;
				if (*p_column == _T(',') || *p_column == _T(';') || *p_column == _T('\0')) {
					szs.push_back(c);
					c = 0;
					c_offset = 0;
					if (*p_column == _T(';') || *p_column == _T('\0')) {
						p_section = p_column;
						if (*p_column == _T(';')) p_section++;
						// \0: һ����Ϊ��ͳһ��ʽ����+1,
						//	��һ�������ר�Ŵ���+2, ����ѡ����ߡ�
						break;
					}
					p_column++;
				}
			}
			if (szs.size() > 0) {
				this->configs.sames.push_back(szs);
				szs.clear();
			}
		}
		prets	= p_section + 1;
	}

	// ���ú��Լ�
	nsize = ::GetPrivateProfileSection(_T("��ͣ��Ԫ��"), rets, sizeof(rets), this->configs.filename);
	this->configs.skips.clear();
	for (prets = rets; prets - rets < nsize && *prets != _T('\0'); ) {
		// pretsָ��һ�� xxx=a1,b1...\0 ��
		while (*prets != _T('=') && *prets) prets++;
		if (*prets == _T('\0')) break;
		prets++; // ���Ե�ʽ���(����'=')

		size_t	c;
		TCHAR	*p_section;
		for (p_section = prets; *p_section; p_section++) {
			if (*p_section >= _T('0') && *p_section <= _T('9')) {
				c	= strtol(p_section, &p_section, 0);
				this->configs.skips.push_back(c);
				if (*p_section == _T('\0')) {
					break;
				}
			} else {
				switch (*p_section) {
				case ' ':
				case ',':
				case ';':
				default:
					continue;
				}
			}
		}
		prets	= p_section + 1;
	}

#ifdef _DETAIL_DEBUG
		// ���Խ��
		szlists::iterator	i;
		szlist::iterator	ii;
		CString			s;
		for (i = this->configs.sames.begin(); i != this->configs.sames.end(); ++i) {
			for (ii = (*i).begin(); ii != (*i).end(); ) {
				size_t	ele	= *ii;
				s	+= (LPCTSTR)&ele;
				++ii;
				if (ii != (*i).end()) {
					s	+= _T(",");
				}
			}
			s	+= _T(";\n");
		}
		MessageBox(s);

		s.Empty();
		for (ii = this->configs.skips.begin(); ii != this->configs.skips.end(); ++ii) {
			size_t ele = *ii;
			CString s2;
			s2.Format(_T("%d(0x%x, '%c')\n"), ele, ele, (TCHAR)(ele ? ele : _T(' ')));
			s	+= s2;
		}
		MessageBox(s);
#endif

	// ���ò��
	this->configs.plugin	= app->GetProfileString(_T("config"), _T("plugin"));

	if (configs.plugin.GetLength() > 0) {
		if (hmodPlugin	!= NULL) {
			FreeLibrary(hmodPlugin);
		}
		hmodPlugin	= LoadLibrary(configs.plugin);
		if (hmodPlugin == NULL) {
			::MessageBox(NULL, _T("װ�ز��ʱ��������!"), NULL, 0);
		}
		stream_units_work::stream_units_work_compare::score_proc_type score_proc;
		score_proc	= (stream_units_work::stream_units_work_compare::score_proc_type)
			GetProcAddress(hmodPlugin, _T("score_for_stream_units_compare"));
		if (score_proc != NULL) {
			score_plugin_dll	= score_proc;
			score_plugin_mode	= spm_dll;
		}

		// �Ƿ����
		/*
		DllRegisterServer_proc sproc;
		sproc	= (DllRegisterServer_proc)GetProcAddress(hmodPlugin, _T("DllRegisterServer"));
		if (sproc != NULL) {
			HRESULT hr;
			CoInitialize(NULL);
			if (SUCCEEDED(sproc())) {
				CClassFactory *fact = NULL;
				hr = DllGetClassObject(0, IID_IClassFactory, (LPVOID *)&fact);
		*/

		/*
			score_plugin_mode	= spm_activex;
		*/
		// �������
	} else {
		if (hmodPlugin != NULL) {
			FreeLibrary(hmodPlugin);
			hmodPlugin		= NULL;
			score_plugin_mode	= spm_none;
		}
	}
}


#define _FONT		"</font>"

void CScomp2_client2Dlg::showdetail(stream_units_work& s, stream_units_work& os) {
	CString		body;
	CString		data;
	CString		unit;
	int		cc;

	body	= _T("<html><body bgcolor=\"#FFFFee\"><p><font size=\"-1\" color=\"#006600\">������[������|һά������(�ϸ�Ԫ)|ģ�����Ƚ�|���ܽ���|Beta]��������<br>��Ȩ���� (C)TopCroak Software(�ҿ����), 1997-2001</font>"
			"</p><table border=\"1\"><tr><td><font color=\"#000000\">����: </font><font color=\"#006666\">��ȷ </font><font color=\"#FF0000\">����<font color=\"#999999\">(ԭ��) "
			" </font></font><font color=\"#CC00CC\">����</font><font color=\"#666600\"> ��©</font></td></tr></table><p>"
			);

	// ���ɱȽϽ��
	{
		reslist::iterator i	= s.c.result.begin();
		restype	res		= *i;
		s.reset();
		os.reset();

		//    +--------------------------> 1. ��s����ѭ��
		//    |		  +--------------> 2. s��������Ϊֹ, �������ȷ����
		//    |		  |    +---------> 3. (��o����ѭ��)������д���, ����o�ж���
		// s: | 1v 23456x | 7v |
		// o: | 1v 23456x | 7v | 890
		for (; !s.eof(); ) {
			// ��s����ѭ��, os������. ������¼����ref����������.
			if (s.pd() != res.refaddr) {
				unit	+= units_desc(s);
				++s;
			} else {
				// ��ԭunit��������Ϊ��ȷ���ݸ���data֮��
					if (unit.GetLength() > 0) {
						unit.Insert(0, _T("<font color=\"#006666\">"));
						unit	+= _T(_FONT);
						data	+= unit;
						unit.Empty();
					}

				// ������������
					if (res.type == restype::end_of_list) break;
					os.pd()	= res.objaddr;
					switch (res.type) {
					case restype::unmatch:
						// os-����(s-ԭ��)
						unit	= _T("<font color=\"#FF0000\">");
						for (cc = 0; cc < res.count; cc++) {
							unit	+= units_desc(os);
							++os;
						}
						unit	+= _T(_FONT"<font color=\"#999999\">(");
						for (cc = 0; cc < res.count; cc++) {
							unit	+= units_desc(s);
							++s;
						}
						unit	+= _T(")"_FONT);
						break;
					case restype::extra:
						// os-����
						unit	= _T("<font color=\"#CC00CC\">");
						for (cc = 0; cc < res.count; cc++) {
							unit	+= units_desc(os);
							++os;
						}
						unit	+= _T(_FONT);
						break;
					case restype::lost:
						// s-ȱ��
						unit	= _T("<font color=\"#666600\">");
						for (cc = 0; cc < res.count; cc++) {
							unit	+= units_desc(s);
							++s;
						}
						unit	+= _T(_FONT);
						break;
					}
					data	+= unit;
					unit.Empty();
				// ׼����һ�������Ŀ��s��ַ
					++i;
					res	= *i;
			} // if ==
		} // for
		// ��󲿷���ȷ����(�������)����data֮��
		if (unit.GetLength() > 0) {
			unit.Insert(0, _T("<font color=\"#006666\">"));
			unit	+= _T(_FONT);
			data	+= unit;
		}
		if (res.type != restype::end_of_list) {
			//__assume(res.type == restype::extra);
			if (res.type == restype::extra) {
				// os-����
				os.pd()	= res.objaddr;
				unit	= _T("<font color=\"#CC00CC\">");
				for (cc = 0; cc < res.count; cc++) {
					unit	+= units_desc(os);
					++os;
				}
				unit	+= _T(_FONT);
				data	+= unit;
			}
			++i;
			res	= *i;
		}
		// ������־
		data	+= _T("<font color=\"#000000\">��</font>");
	}

	body	+= data;
	data	= _T("</p><hr><p align=\"center\"><font size=\"-1\" color=\"#006600\">TopCroak Software(�ҿ����) | Campo Accelerate(��ԭ��������) | Stream Works(������)</font><font color=\"#006600\"><br>"
			"<font size=\"-1\">���ߣ�Mr. DanSei(л����) <br>����ͽ��飺<a href=\"mailto:dansei@126.com\">dansei@126.com</a></font></font></p><p>&nbsp; </p></body></html>"
			);
	body	+= data;

	CDetailDialog	dd(NULL, body);
	dd.DoModal();
}
