// ValiderDlg.h : header file
//

#if !defined(AFX_VALIDERDLG_H__0CE37688_9BA1_47FD_AD6E_C50CEF72C123__INCLUDED_)
#define AFX_VALIDERDLG_H__0CE37688_9BA1_47FD_AD6E_C50CEF72C123__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CValiderDlg dialog

#define TEST_SEQ_FULL		0
#define TEST_SEQ_H25		1
#define TEST_SEQ_T25		2
#define TEST_DIS_5		3
#define TEST_DIS_25		4
#define TEST_DIS_50		5

#define SEARCH_SEQ		0
#define SEARCH_SEQ_1		1
#define SEARCH_SEQ_25		2
#define SEARCH_DIS_5		3
#define SEARCH_DIS_25		4
#define SEARCH_DIS_50		5

class CValiderDlg : public CDialog
{
// Construction
public:
	CValiderDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CValiderDlg();

public:
	BOOL	m_bCanceled;

	float	matchfile(LPCTSTR f1, LPCTSTR f2);

	int	srcproc(HANDLE h, UINT msg, DWORD p1, DWORD p2);
	int	destproc(HANDLE h, UINT msg, DWORD p1, DWORD p2);
	float	srcfile();
	float	destfile();

	TCHAR	m_strFile[MAX_PATH];
	TCHAR	m_strFileBase[MAX_PATH];
	CString	m_strLog;

	BYTE	*b1, *b2;

	LONG	m_nTotalfiles;
	float	m_averageCorrect;

// Dialog Data
	//{{AFX_DATA(CValiderDlg)
	enum { IDD = IDD_VALIDER_DIALOG };
	CButton	m_btnBrowseSource;
	CButton	m_btnBrowseDest;
	CButton	m_btnStop;
	CProgressCtrl	m_progTotal;
	CProgressCtrl	m_progFile;
	CProgressCtrl	m_progDirectory;
	CEdit	m_edtSource;
	CEdit	m_edtDest;
	CButton	m_btnStart;
	CButton	m_btnExit;
	BOOL	m_chkNest;
	int		m_cboAlgorithm;
	int		m_cboBlockSize;
	int		m_cboSearch;
	CString	m_strCurrentDirectory;
	CString	m_strCurrentFile;
	BOOL	m_chkLog;
	CString	m_strSource;
	CString	m_strDest;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CValiderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CValiderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonAbout();
	afx_msg void OnButtonExit();
	afx_msg void OnBrowseSource();
	afx_msg void OnBrowseDest();
	afx_msg void OnButtonStart();
	afx_msg void OnButtonStop();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VALIDERDLG_H__0CE37688_9BA1_47FD_AD6E_C50CEF72C123__INCLUDED_)
