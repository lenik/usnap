// WNetAddDlg.h : header file
//

#if !defined(AFX_WNETADDDLG_H__C5E3AA49_18EB_11D4_B811_000021DBCE3F__INCLUDED_)
#define AFX_WNETADDDLG_H__C5E3AA49_18EB_11D4_B811_000021DBCE3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <WinNetwk.h>

/////////////////////////////////////////////////////////////////////////////
// CWNetAddDlg dialog

class CWNetAddDlg : public CDialog
{
// Construction
public:
	CWNetAddDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWNetAddDlg)
	enum { IDD = IDD_WNETADD_DIALOG };
	CComboBox	m_cboDisplayType;
	CComboBox	m_cboUsage;
	CComboBox	m_cboScope;
	CComboBox	m_cboResourceType;
	CString	m_strLocalName;
	CString	m_strProvider;
	CString	m_strRemoteName;
	CString	m_strStatus;
	CString	m_strComment;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWNetAddDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	HANDLE hEnum;

	void status(DWORD status);
	void show(NETRESOURCE nr);

	// Generated message map functions
	//{{AFX_MSG(CWNetAddDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonAddConnection2();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnButtonReEnum();
	afx_msg void OnButtonNext();
	afx_msg void OnButtonClose2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WNETADDDLG_H__C5E3AA49_18EB_11D4_B811_000021DBCE3F__INCLUDED_)
