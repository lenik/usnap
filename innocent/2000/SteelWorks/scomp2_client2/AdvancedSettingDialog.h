#if !defined(AFX_ADVANCEDSETTINGDIALOG_H__D34DC7DF_1D2E_4782_8299_A13BD2045F28__INCLUDED_)
#define AFX_ADVANCEDSETTINGDIALOG_H__D34DC7DF_1D2E_4782_8299_A13BD2045F28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AdvancedSettingDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAdvancedSettingDialog dialog

class CAdvancedSettingDialog : public CDialog
{
// Construction
public:
	CAdvancedSettingDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAdvancedSettingDialog)
	enum { IDD = IDD_SETTING_ADVANCED };
	BOOL	m_chkCombineError;
	CString	m_strPlugin;
	float	m_fFuzzySame;
	int		m_cboCompareMode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdvancedSettingDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAdvancedSettingDialog)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButtonBrowse();
	afx_msg void OnButtonPluginHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADVANCEDSETTINGDIALOG_H__D34DC7DF_1D2E_4782_8299_A13BD2045F28__INCLUDED_)
