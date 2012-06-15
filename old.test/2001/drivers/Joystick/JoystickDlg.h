// JoystickDlg.h : header file
//

#if !defined(AFX_JOYSTICKDLG_H__E26F3336_C088_11D3_8278_484C0001E209__INCLUDED_)
#define AFX_JOYSTICKDLG_H__E26F3336_C088_11D3_8278_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CJoystickDlg dialog

class CJoystickDlg : public CDialog
{
// Construction
public:
	CJoystickDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CJoystickDlg)
	enum { IDD = IDD_JOYSTICK_DIALOG };
	CComboBox	m_cboMB;
	CComboBox	m_cboRB;
	CComboBox	m_cboLB;
	int		m_X;
	int		m_Y;
	int		m_Scale;
	CString	m_strButton;
	BOOL	m_chkWinstart;
	BOOL	m_bNoUpdate;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJoystickDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CJoystickDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetfocusEditScale();
	afx_msg void OnKillfocusEditScale();
	afx_msg void OnChangeEditScale();
	afx_msg void OnButtonCap();
	afx_msg void OnAboutbox();
	//}}AFX_MSG
	int Scale(int, int, int);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JOYSTICKDLG_H__E26F3336_C088_11D3_8278_484C0001E209__INCLUDED_)
