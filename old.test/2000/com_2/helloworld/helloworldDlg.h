// helloworldDlg.h : header file
//

#if !defined(AFX_HELLOWORLDDLG_H__64513591_5EBD_424F_A616_4ADE95C5F9E5__INCLUDED_)
#define AFX_HELLOWORLDDLG_H__64513591_5EBD_424F_A616_4ADE95C5F9E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHelloworldDlg dialog

class CHelloworldDlg : public CDialog
{
// Construction
public:
	CHelloworldDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHelloworldDlg)
	enum { IDD = IDD_HELLOWORLD_DIALOG };
	CString	m_strA;
	CString	m_strB;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHelloworldDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHelloworldDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonHello();
	afx_msg void OnButtonCalc();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELLOWORLDDLG_H__64513591_5EBD_424F_A616_4ADE95C5F9E5__INCLUDED_)
