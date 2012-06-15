// dispatcherDlg.h : header file
//

#if !defined(AFX_DISPATCHERDLG_H__5FD6CF7C_F930_4F0E_97DE_81C89508FFC3__INCLUDED_)
#define AFX_DISPATCHERDLG_H__5FD6CF7C_F930_4F0E_97DE_81C89508FFC3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDispatcherDlg dialog

class CDispatcherDlg : public CDialog
{
// Construction
public:
	CDispatcherDlg(CWnd* pParent = NULL);	// standard constructor
	BOOL	m_bCanceled;
	int srcproc(HANDLE h, UINT msg, DWORD p1, DWORD p2);
	int srcfile();
	TCHAR	m_strCurrentSrc[MAX_PATH];
	TCHAR	m_strCurrentSrcBase[MAX_PATH];
	int destproc(HANDLE h, UINT msg, DWORD p1, DWORD p2);
	int destdir(LPCTSTR srcfile, LPCTSTR destdir);
	CString	m_strLog;
	int	m_nCounter;

// Dialog Data
	//{{AFX_DATA(CDispatcherDlg)
	enum { IDD = IDD_DISPATCHER_DIALOG };
	CButton	m_btnExit;
	CButton	m_btnAbout;
	CEdit	m_edtSource;
	CEdit	m_edtDest;
	CButton	m_btnStop;
	CButton	m_btnStart;
	CButton	m_btnSelectDir;
	CButton	m_btnSelectFile;
	CButton	m_btnBrowseDest;
	BOOL	m_chkDirectory;
	BOOL	m_chkLog;
	BOOL	m_chkTemplate;
	CString	m_strDest;
	CString	m_strSource;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDispatcherDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDispatcherDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonAbout();
	afx_msg void OnButtonSelectFile();
	afx_msg void OnButtonSelectFolder();
	afx_msg void OnButtonBrowseDest();
	afx_msg void OnButtonStart();
	afx_msg void OnButtonStop();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISPATCHERDLG_H__5FD6CF7C_F930_4F0E_97DE_81C89508FFC3__INCLUDED_)
