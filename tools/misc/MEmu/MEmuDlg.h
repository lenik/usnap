// MEmuDlg.h : header file
//

#if !defined(AFX_MEMUDLG_H__A3E699A5_C028_11D3_82DD_A0694CF2D1D4__INCLUDED_)
#define AFX_MEMUDLG_H__A3E699A5_C028_11D3_82DD_A0694CF2D1D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMEmuDlg dialog

class CMEmuDlg : public CDialog
{
// Construction
public:
	CMEmuDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMEmuDlg)
	enum { IDD = IDD_MEMU_DIALOG };
	CScrollBar	m_scrFrequence;
	CString	m_strFilename;
	CString	m_strFact;
	CString	m_strSize;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMEmuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	BOOL m_bFileOpened;
	HLOCAL m_hLocal;
	int m_nInterval;
	// Generated message map functions
	//{{AFX_MSG(CMEmuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonBrowse();
	afx_msg void OnRadioTypeOnce();
	afx_msg void OnRadioTypeFreq();
	afx_msg void OnButtonClose();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEMUDLG_H__A3E699A5_C028_11D3_82DD_A0694CF2D1D4__INCLUDED_)
