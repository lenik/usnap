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
				"模糊比较插件(*.scp)|*.scp|动态链接库(*.dll)|*.dll|所有文件|*.*||");
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
			"<html><head><title>插件帮助</title><meta http-equiv=\"Content-Type\" content=\"text/html; charset=gb2312\"></head>"
			"<body bgcolor=\"#FFFFee\"><p><font size=\"+3\"><b><font color=\"#0000FF\">计分插件开发方法</font></b></font></p>"
			"<p>模糊流比较插件有两种类型: 传统的<a href=\"#chapter1\">导出函数插件</a>(动态链接库)和<a href=\"#chapter2\">基于ActiveX的组件插件</a>。下面分别介绍：</p>"
			"<p><a name=\"chapter1\"></a><font size=\"+2\">一、导出函数插件</font></p>"
			"<blockquote><p>动态链接库(DLL)：能够在进程运行时动态装载，并将地址空间映射至进程的地址空间。进程通过调用系统API/GetProcAddress获取动态链接库中的导出函数地址。因为它和进程存在于同一地址空间，所以进程可以直接调用该函数。</p>"
			"<p>导出函数格式：</p><blockquote> <table border=\"0\"><tr> <td>float _pascal score_for_stream_units_compare(</td>"
			"<td>&nbsp;</td><td>&nbsp;</td></tr><tr> <td>&nbsp;</td><td>int match, <br>int unmatch, <br>int extra, <br>int lost</td><td>// 匹配数<br>// 不匹配数<br>// 多余数<br>// 缺少数</td></tr>"
			"<tr> <td> <div align=\"right\">)</div></td><td>;</td><td>&nbsp;</td></tr></table><p>(注意大小写。) </p></blockquote><p>举例：</p><blockquote> <p>float _pascal score_for_stream_units_compare(int match, int unmatch, int extra, int lost) {</p>"
			"<blockquote> <p> float ret = 0; </p><p>ret = match - (unmatch + extra + lost) * 5; </p><p>if (ret &lt; 0) ret = 0; </p></blockquote><p>}</p></blockquote><p>注：</p>"
			"<blockquote> <p>_pascal表示函数使用pascal参数传递规范, 可以用WINAPI、_stdcall等代替, 但不能用_cdecl、(省略)等, 否则会产生调用协议不适用错误。</p><p>参数中的int是32位整数, 如果使用支持DLL编译的Basic语言应使用Long类型, 而不能使用Integer类型(它是16位)。</p>"
			"</blockquote></blockquote><p><a name=\"chapter2\"></a><font size=\"+2\">二、基于ActiveX的组件插件</font></p><blockquote> <p>ActiveX：它是OLE2和微软X计划的产物、一种跨平台的、与语言无关的二进制对象。它是基于COM的、支持双接口的类规范。在Visual Basic中有三种Active "
			"X工程：不可见的ActiveX DLL/EXE、可见的ActiveX 控件(OCX)、ActiveX 文档DLL/EXE。后面将分别叙述其中每一项的插件开发方法。</p><p>COM：组件对象模型。OLE2的底层构造，Win32(包括Win95-Me)、WinNT的骨架。它是面向接口的(不是真正面向对象的)。</p>"
			"<p>类名称：StreamUnitsComparePlugin</p><p>计分方法：</p><blockquote> <table border=\"0\"><tr> <td>Public Function Score(</td><td>&nbsp;</td>"
			"<td>&nbsp;</td></tr><tr> <td>&nbsp;</td><td>ByVal match as Long, <br>ByVal unmatch as Long, <br>ByVal extra as Long, <br>"
			"ByVal lost as Long</td><td>' 匹配数<br>' 不匹配数<br>' 多余数<br>' 缺少数</td></tr><tr> <td> <div align=\"right\">)</div></td><td> as Single</td><td>&nbsp;</td></tr></table>"
			"<p>如：<br>Public Function Score(match, unmatch, extra, lost)</p><blockquote> <p>Score = match - (unmatch + extra + lost) * 5<br>If Score &lt; 0 Then Score = 0 </p></blockquote><p>End Function</p></blockquote>"
			"<p>首先以ActiveX DLL为例：新建ActiveX DLL工程，将类Class1重命名为StreamUnitsComparePlugin，加入Score方法。保存工程，确保工程名和工程文件名相同。比如说，如果将工程存入“比较插件.vbp”，那么将工程名（工程1）改成：比较插件。最后生成“比较插件.dll”。ActiveX "
			"EXE与此相同。 </p><p>对于ActiveX 控件/文档 DLL/EXE，方法是完全一样的，也是添加函数的过程，只是控件多了一个图标而已。</p><p>&nbsp;</p></blockquote>"
			"<hr><p align=\"center\"><font size=\"-1\" color=\"#006600\">TopCroak Software(桃壳软件) | Campo Accelerate(草原加速引擎) | Stream Works(流处理)</font><font color=\"#006600\"><br>"
			"<font size=\"-1\">作者：Mr. DanSei(谢继雷) <br>意见和建议：<a href=\"mailto:dansei@126.com\">dansei@126.com</a></font></font></p><p>&nbsp; </p>"
			"</body></html>"
		);

	CDetailDialog dd(NULL, hstr);
	dd.DoModal();
}
