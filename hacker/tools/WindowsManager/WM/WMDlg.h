// WMDlg.h : header file
//

#if !defined(AFX_WMDLG_H__8E727088_C4C9_4E7D_9EC1_A69C8D9EE9DF__INCLUDED_)
#define AFX_WMDLG_H__8E727088_C4C9_4E7D_9EC1_A69C8D9EE9DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWMDlg dialog

class CWMDlg : public CDialog
{
// Construction
public:
	CWMDlg(CWnd* pParent = NULL);	// standard constructor

public:
	HINSTANCE	hInstDLL;

// Dialog Data
	//{{AFX_DATA(CWMDlg)
	enum { IDD = IDD_WM_DIALOG };
	CListBox	m_lstKeys;
	CString	m_i1;
	CString	m_i2;
	CString	m_i3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWMDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonStart();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnButtonStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMDLG_H__8E727088_C4C9_4E7D_9EC1_A69C8D9EE9DF__INCLUDED_)
