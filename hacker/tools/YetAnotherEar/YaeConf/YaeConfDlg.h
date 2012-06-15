// YaeConfDlg.h : header file
//

#if !defined(AFX_YAECONFDLG_H__2DE455D3_3F74_476B_90C0_F5F08FE8DC5B__INCLUDED_)
#define AFX_YAECONFDLG_H__2DE455D3_3F74_476B_90C0_F5F08FE8DC5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CYaeConfDlg dialog

class CYaeConfDlg : public CDialog
{
// Construction
public:
	CYaeConfDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CYaeConfDlg)
	enum { IDD = IDD_YAECONF_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYaeConfDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CYaeConfDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YAECONFDLG_H__2DE455D3_3F74_476B_90C0_F5F08FE8DC5B__INCLUDED_)
