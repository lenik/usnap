#if !defined(AFX_SETTINGDIALOG_H__43E728D6_746B_4449_9592_E6743A292DCF__INCLUDED_)
#define AFX_SETTINGDIALOG_H__43E728D6_746B_4449_9592_E6743A292DCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SettingDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSettingDialog dialog

class CSettingDialog : public CDialog
{
// Construction
public:
	CSettingDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSettingDialog)
	enum { IDD = IDD_SETTING };
	CEdit	m_conConfigFile;
	CEdit	m_conWidth;
	CEdit	m_conDepth;
	CComboBox	m_conDecorate;
	CComboBox	m_conAlgor;
	CButton	m_conSave;
	CButton	m_conBrowse;
	BOOL	m_bChkSave;
	int		m_cboAlgorithm;
	int		m_cboDecorate;
	CString	m_strConfigFile;
	int		m_nDepth;
	int		m_nWidth;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSettingDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSettingDialog)
	afx_msg void OnButtonBrowse();
	virtual void OnOK();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonAdvance();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTINGDIALOG_H__43E728D6_746B_4449_9592_E6743A292DCF__INCLUDED_)
