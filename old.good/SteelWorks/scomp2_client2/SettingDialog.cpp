// SettingDialog.cpp : implementation file
//

#include "stdafx.h"
#include "scomp2_client2.h"
#include "SettingDialog.h"
#include "AdvancedSettingDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingDialog dialog


CSettingDialog::CSettingDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingDialog)
	m_bChkSave = FALSE;
	m_cboAlgorithm = -1;
	m_cboDecorate = -1;
	m_strConfigFile = _T("");
	m_nDepth = 0;
	m_nWidth = 0;
	//}}AFX_DATA_INIT
}


void CSettingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingDialog)
	DDX_Control(pDX, IDC_EDIT_CONFIGFILE, m_conConfigFile);
	DDX_Control(pDX, IDC_EDIT_COMP_WIDTH, m_conWidth);
	DDX_Control(pDX, IDC_EDIT_COMP_DEPTH, m_conDepth);
	DDX_Control(pDX, IDC_COMBO_DECORATE, m_conDecorate);
	DDX_Control(pDX, IDC_COMBO_ALGOR, m_conAlgor);
	DDX_Control(pDX, IDC_CHECK_SAVE, m_conSave);
	DDX_Control(pDX, IDC_BUTTON_BROWSE, m_conBrowse);
	DDX_Check(pDX, IDC_CHECK_SAVE, m_bChkSave);
	DDX_CBIndex(pDX, IDC_COMBO_ALGOR, m_cboAlgorithm);
	DDX_CBIndex(pDX, IDC_COMBO_DECORATE, m_cboDecorate);
	DDX_Text(pDX, IDC_EDIT_CONFIGFILE, m_strConfigFile);
	DDX_Text(pDX, IDC_EDIT_COMP_DEPTH, m_nDepth);
	DDX_Text(pDX, IDC_EDIT_COMP_WIDTH, m_nWidth);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSettingDialog, CDialog)
	//{{AFX_MSG_MAP(CSettingDialog)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE, OnButtonBrowse)
	ON_BN_CLICKED(IDC_RADIO_1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO_2, OnRadio2)
	ON_BN_CLICKED(IDC_BUTTON_ADVANCE, OnButtonAdvance)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingDialog message handlers

void CSettingDialog::OnButtonBrowse()
{
	CFileDialog	fd(TRUE, "ini", "*.ini",
				OFN_FILEMUSTEXIST,
				"配置文件(*.ini)|*.ini|所有文件|*.*||");
	if (fd.DoModal() == IDOK) {
		this->m_strConfigFile = fd.GetPathName();
		UpdateData(FALSE);
	}
}


void CSettingDialog::OnOK()
{
	UpdateData(TRUE);
	//if (this->m_bChkSave) {
		// 保存设置
		CWinApp *app = ::AfxGetApp();
		this->UpdateData(TRUE);
		app->WriteProfileString(_T("config"), _T("configfile"), this->m_strConfigFile);
		app->WriteProfileInt(_T("config"), _T("algor"), this->m_cboAlgorithm);
		app->WriteProfileInt(_T("config"), _T("decor"), this->m_cboDecorate);
		app->WriteProfileInt(_T("config"), _T("width"), this->m_nWidth);
		app->WriteProfileInt(_T("config"), _T("depth"), this->m_nDepth);
	//}
	CDialog::OnOK();
}

void CSettingDialog::OnRadio1()
{
	this->m_conConfigFile.EnableWindow(TRUE);
	this->m_conBrowse.EnableWindow(TRUE);
	this->m_conAlgor.EnableWindow(FALSE);
	this->m_conDecorate.EnableWindow(FALSE);
	this->m_conWidth.EnableWindow(FALSE);
	this->m_conDepth.EnableWindow(FALSE);

}

void CSettingDialog::OnRadio2()
{
	this->m_conConfigFile.EnableWindow(FALSE);
	this->m_conBrowse.EnableWindow(FALSE);
	this->m_conAlgor.EnableWindow(TRUE);
	this->m_conDecorate.EnableWindow(TRUE);
	this->m_conWidth.EnableWindow(TRUE);
	this->m_conDepth.EnableWindow(TRUE);
}

BOOL CSettingDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	CWinApp *app = ::AfxGetApp();
	this->m_strConfigFile	= app->GetProfileString(_T("config"), _T("configfile"));

	this->m_cboAlgorithm	= app->GetProfileInt(_T("config"), _T("algor"), 0);
	this->m_cboDecorate	= app->GetProfileInt(_T("config"), _T("decor"), 0);
	this->m_nWidth		= app->GetProfileInt(_T("config"), _T("width"), 1);
	this->m_nDepth		= app->GetProfileInt(_T("config"), _T("depth"), 1);

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSettingDialog::OnButtonAdvance()
{
	// TODO: Add your control notification handler code here
	CAdvancedSettingDialog asd;
	asd.DoModal();
}
