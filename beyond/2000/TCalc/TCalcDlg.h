// TCalcDlg.h : header file
//

#if !defined(AFX_TCALCDLG_H__FE2965B9_C032_11D3_8D55_D0657801DC47__INCLUDED_)
#define AFX_TCALCDLG_H__FE2965B9_C032_11D3_8D55_D0657801DC47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTCalcDlg dialog

class CTCalcDlg : public CDialog
{
// Construction
public:
	CTCalcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTCalcDlg)
	enum { IDD = IDD_TCALC_DIALOG };
	BOOL	m_bHyp;
	BOOL	m_bInv;
	BOOL	m_bCheckMemoryA;
	BOOL	m_bCheckMemoryB;
	CString	m_strScreen;
	int		m_nRadix;
	int		m_nUnit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCalcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTCalcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCALCDLG_H__FE2965B9_C032_11D3_8D55_D0657801DC47__INCLUDED_)
