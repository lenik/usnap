// sockTalkDlg.h : header file
//

#if !defined(AFX_SOCKTALKDLG_H__2A816156_1B21_46A5_93DF_9258998C9CF7__INCLUDED_)
#define AFX_SOCKTALKDLG_H__2A816156_1B21_46A5_93DF_9258998C9CF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSockTalkDlg dialog

class CSockTalkDlg : public CDialog
{
// Construction
public:
	CSockTalkDlg(CWnd* pParent = NULL);	// standard constructor

public:
	SOCKET m_socket;

// Dialog Data
	//{{AFX_DATA(CSockTalkDlg)
	enum { IDD = IDD_SOCKTALK_DIALOG };
	CString	m_r;
	CString	m_s;
	CString	m_host;
	int		m_port;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSockTalkDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSockTalkDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonConnect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOCKTALKDLG_H__2A816156_1B21_46A5_93DF_9258998C9CF7__INCLUDED_)
