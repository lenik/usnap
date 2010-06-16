// oletrace_cfgDlg.h : header file
//

#if !defined(AFX_OLETRACE_CFGDLG_H__1EE65B8B_40CC_4DB5_9171_0F4EBB46C81C__INCLUDED_)
#define AFX_OLETRACE_CFGDLG_H__1EE65B8B_40CC_4DB5_9171_0F4EBB46C81C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COletrace_cfgDlg dialog

class COletrace_cfgDlg : public CDialog
{
// Construction
public:
	COletrace_cfgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COletrace_cfgDlg)
	enum { IDD = IDD_OLETRACE_CFG_DIALOG };
	CListBox	m_lstSkips;
	BOOL	m_bLogCall;
	BOOL	m_bTraceIntoVtbl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COletrace_cfgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COletrace_cfgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLETRACE_CFGDLG_H__1EE65B8B_40CC_4DB5_9171_0F4EBB46C81C__INCLUDED_)
