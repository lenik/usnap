// emDlg.h : header file
//

#if !defined(AFX_EMDLG_H__ECB9BFE7_C096_11D3_82DA_E142916ADDD3__INCLUDED_)
#define AFX_EMDLG_H__ECB9BFE7_C096_11D3_82DA_E142916ADDD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEmDlg dialog

#define MAXDATA	1000

class CEmDlg : public CDialog
{
// Construction
public:
	CEmDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEmDlg)
	enum { IDD = IDD_EM_DIALOG };
	BOOL	m_bModify1;
	BOOL	m_bModify2;
	CString	m_txtDataDest1;
	CString	m_txtDataDest2;
	CString	m_txtDataSrc1;
	CString	m_txtDataSrc2;
	CString	m_txtFilename1;
	CString	m_txtFilename2;
	BOOL	m_bSaveState;
	CString	m_strStatus;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

	void UseFormat(CString &src, BYTE *data, int len);
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEmDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonFilebrowse1();
	afx_msg void OnButtonAbout();
	afx_msg void OnButtonFilebrowse2();
	afx_msg void OnButtonBegin();
	afx_msg void OnCheckSavestate();
	virtual void OnOK();
	afx_msg void OnButtonHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMDLG_H__ECB9BFE7_C096_11D3_82DA_E142916ADDD3__INCLUDED_)
