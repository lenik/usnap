// SComp_ClientDlg.h : header file
//

#if !defined(AFX_SCOMP_CLIENTDLG_H__B081007D_7A5B_4998_8B8B_F58B57B81BD9__INCLUDED_)
#define AFX_SCOMP_CLIENTDLG_H__B081007D_7A5B_4998_8B8B_F58B57B81BD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSComp_ClientDlg dialog

#include "PrettyResultDialog.h"

class CSComp_ClientDlg : public CDialog
{
// Construction
public:
	CSComp_ClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSComp_ClientDlg)
	enum { IDD = IDD_SCOMP_CLIENT_DIALOG };
	CListBox	m_lstFComp;
	CComboBox	m_cboDecorate;
	CComboBox	m_cboAlgorithm;
	long	m_nWidth;
	long	m_nDepth;
	CString	m_strResult;
	CString	m_fTemp;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSComp_ClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	CPrettyResultDialog	rdlg;
	virtual void compfile(BOOL bDetail = FALSE);

protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSComp_ClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonBrowseTemp();
	afx_msg void OnButtonInsert();
	afx_msg void OnButtonRemove();
	afx_msg void OnDblclkListFilecomp();
	afx_msg void OnButtonPrettyResult();
	afx_msg void OnButtonComp();
	afx_msg void OnButtonAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCOMP_CLIENTDLG_H__B081007D_7A5B_4998_8B8B_F58B57B81BD9__INCLUDED_)
