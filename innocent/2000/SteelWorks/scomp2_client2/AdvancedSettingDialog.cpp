// AdvancedSettingDialog.cpp : implementation file
//

#include "stdafx.h"
#include "scomp2_client2.h"
#include "AdvancedSettingDialog.h"
#include "DetailDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdvancedSettingDialog dialog


CAdvancedSettingDialog::CAdvancedSettingDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CAdvancedSettingDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdvancedSettingDialog)
	m_chkCombineError = TRUE;
	m_strPlugin = _T("");
	m_fFuzzySame = 1.0f;
	m_cboCompareMode = 1;
	//}}AFX_DATA_INIT
}


void CAdvancedSettingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdvancedSettingDialog)
	DDX_Check(pDX, IDC_CHECK_COMBINE_ERROR, m_chkCombineError);
	DDX_Text(pDX, IDC_EDIT_PLUGIN, m_strPlugin);
	DDX_Text(pDX, IDC_EDIT_FUZZY_SAME, m_fFuzzySame);
	DDV_MinMaxFloat(pDX, m_fFuzzySame, 0.f, 1.f);
	DDX_CBIndex(pDX, IDC_COMBO_COMPARE_MODE, m_cboCompareMode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAdvancedSettingDialog, CDialog)
	//{{AFX_MSG_MAP(CAdvancedSettingDialog)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE, OnButtonBrowse)
	ON_BN_CLICKED(IDC_BUTTON_PLUGIN_HELP, OnButtonPluginHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdvancedSettingDialog message handlers

BOOL CAdvancedSettingDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	CWinApp *app = ::AfxGetApp();

	this->m_fFuzzySame	= app->GetProfileInt(_T("config"), _T("fuzzy_same"), 1000) / 1000.0f;
	this->m_cboCompareMode	= app->GetProfileInt(_T("config"), _T("compare_mode"), 1);
	this->m_chkCombineError	= app->GetProfileInt(_T("config"), _T("combine_error"), 1);
	this->m_strPlugin	= app->GetProfileString(_T("config"), _T("plugin"));

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAdvancedSettingDialog::OnOK()
{
	// TODO: Add extra validation here
	CWinApp *app = ::AfxGetApp();

	if (UpdateData(TRUE)) {
		app->WriteProfileInt(_T("config"), _T("fuzzy_same"), (int)(this->m_fFuzzySame * 1000));
		app->WriteProfileInt(_T("config"), _T("compare_mode"), this->m_cboCompareMode);
		app->WriteProfileInt(_T("config"), _T("combine_error"), this->m_chkCombineError);
		app->WriteProfileString(_T("config"), _T("plugin"), (LPCTSTR)this->m_strPlugin);
	}

	CDialog::OnOK();
}

void CAdvancedSettingDialog::OnButtonBrowse()
{
	// TODO: Add your control notification handler code here
	CFileDialog	fd(TRUE, "scp", "*.scp",
				OFN_FILEMUSTEXIST,
				"ģ���Ƚϲ��(*.scp)|*.scp|��̬���ӿ�(*.dll)|*.dll|�����ļ�|*.*||");
	if (fd.DoModal() == IDOK) {
		this->m_strPlugin	= fd.GetPathName();
		UpdateData(FALSE);

		HMODULE	h = LoadLibrary(this->m_strPlugin);
		if (h) {
			typedef void (_stdcall *about_proc)();
			about_proc	about;
			about	= (about_proc)GetProcAddress(h, _T("about_for_plugin"));
			if (about) about();
			FreeLibrary(h);
		}
	}
}

void CAdvancedSettingDialog::OnButtonPluginHelp()
{
	// TODO: Add your control notification handler code here
	CString hstr;

	hstr	= _T(
			"<html><head><title>�������</title><meta http-equiv=\"Content-Type\" content=\"text/html; charset=gb2312\"></head>"
			"<body bgcolor=\"#FFFFee\"><p><font size=\"+3\"><b><font color=\"#0000FF\">�Ʒֲ����������</font></b></font></p>"
			"<p>ģ�����Ƚϲ������������: ��ͳ��<a href=\"#chapter1\">�����������</a>(��̬���ӿ�)��<a href=\"#chapter2\">����ActiveX��������</a>������ֱ���ܣ�</p>"
			"<p><a name=\"chapter1\"></a><font size=\"+2\">һ�������������</font></p>"
			"<blockquote><p>��̬���ӿ�(DLL)���ܹ��ڽ�������ʱ��̬װ�أ�������ַ�ռ�ӳ�������̵ĵ�ַ�ռ䡣����ͨ������ϵͳAPI/GetProcAddress��ȡ��̬���ӿ��еĵ���������ַ����Ϊ���ͽ��̴�����ͬһ��ַ�ռ䣬���Խ��̿���ֱ�ӵ��øú�����</p>"
			"<p>����������ʽ��</p><blockquote> <table border=\"0\"><tr> <td>float _pascal score_for_stream_units_compare(</td>"
			"<td>&nbsp;</td><td>&nbsp;</td></tr><tr> <td>&nbsp;</td><td>int match, <br>int unmatch, <br>int extra, <br>int lost</td><td>// ƥ����<br>// ��ƥ����<br>// ������<br>// ȱ����</td></tr>"
			"<tr> <td> <div align=\"right\">)</div></td><td>;</td><td>&nbsp;</td></tr></table><p>(ע���Сд��) </p></blockquote><p>������</p><blockquote> <p>float _pascal score_for_stream_units_compare(int match, int unmatch, int extra, int lost) {</p>"
			"<blockquote> <p> float ret = 0; </p><p>ret = match - (unmatch + extra + lost) * 5; </p><p>if (ret &lt; 0) ret = 0; </p></blockquote><p>}</p></blockquote><p>ע��</p>"
			"<blockquote> <p>_pascal��ʾ����ʹ��pascal�������ݹ淶, ������WINAPI��_stdcall�ȴ���, ��������_cdecl��(ʡ��)��, ������������Э�鲻���ô���</p><p>�����е�int��32λ����, ���ʹ��֧��DLL�����Basic����Ӧʹ��Long����, ������ʹ��Integer����(����16λ)��</p>"
			"</blockquote></blockquote><p><a name=\"chapter2\"></a><font size=\"+2\">��������ActiveX��������</font></p><blockquote> <p>ActiveX������OLE2��΢��X�ƻ��Ĳ��һ�ֿ�ƽ̨�ġ��������޹صĶ����ƶ������ǻ���COM�ġ�֧��˫�ӿڵ���淶����Visual Basic��������Active "
			"X���̣����ɼ���ActiveX DLL/EXE���ɼ���ActiveX �ؼ�(OCX)��ActiveX �ĵ�DLL/EXE�����潫�ֱ���������ÿһ��Ĳ������������</p><p>COM���������ģ�͡�OLE2�ĵײ㹹�죬Win32(����Win95-Me)��WinNT�ĹǼܡ���������ӿڵ�(����������������)��</p>"
			"<p>�����ƣ�StreamUnitsComparePlugin</p><p>�Ʒַ�����</p><blockquote> <table border=\"0\"><tr> <td>Public Function Score(</td><td>&nbsp;</td>"
			"<td>&nbsp;</td></tr><tr> <td>&nbsp;</td><td>ByVal match as Long, <br>ByVal unmatch as Long, <br>ByVal extra as Long, <br>"
			"ByVal lost as Long</td><td>' ƥ����<br>' ��ƥ����<br>' ������<br>' ȱ����</td></tr><tr> <td> <div align=\"right\">)</div></td><td> as Single</td><td>&nbsp;</td></tr></table>"
			"<p>�磺<br>Public Function Score(match, unmatch, extra, lost)</p><blockquote> <p>Score = match - (unmatch + extra + lost) * 5<br>If Score &lt; 0 Then Score = 0 </p></blockquote><p>End Function</p></blockquote>"
			"<p>������ActiveX DLLΪ�����½�ActiveX DLL���̣�����Class1������ΪStreamUnitsComparePlugin������Score���������湤�̣�ȷ���������͹����ļ�����ͬ������˵����������̴��롰�Ƚϲ��.vbp������ô��������������1���ĳɣ��Ƚϲ����������ɡ��Ƚϲ��.dll����ActiveX "
			"EXE�����ͬ�� </p><p>����ActiveX �ؼ�/�ĵ� DLL/EXE����������ȫһ���ģ�Ҳ����Ӻ����Ĺ��̣�ֻ�ǿؼ�����һ��ͼ����ѡ�</p><p>&nbsp;</p></blockquote>"
			"<hr><p align=\"center\"><font size=\"-1\" color=\"#006600\">TopCroak Software(�ҿ����) | Campo Accelerate(��ԭ��������) | Stream Works(������)</font><font color=\"#006600\"><br>"
			"<font size=\"-1\">���ߣ�Mr. DanSei(л����) <br>����ͽ��飺<a href=\"mailto:dansei@126.com\">dansei@126.com</a></font></font></p><p>&nbsp; </p>"
			"</body></html>"
		);

	CDetailDialog dd(NULL, hstr);
	dd.DoModal();
}
