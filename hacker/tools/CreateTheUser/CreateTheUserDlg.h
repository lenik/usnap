// CreateTheUserDlg.h : header file
//

#if !defined(AFX_CREATETHEUSERDLG_H__37E493CB_C670_4BDA_B9D2_AAD32347B187__INCLUDED_)
#define AFX_CREATETHEUSERDLG_H__37E493CB_C670_4BDA_B9D2_AAD32347B187__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreateTheUserDlg dialog

class CCreateTheUserDlg : public CDialog
{
// Construction
public:
	CCreateTheUserDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreateTheUserDlg)
	enum { IDD = IDD_CREATETHEUSER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateTheUserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreateTheUserDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonCreate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATETHEUSERDLG_H__37E493CB_C670_4BDA_B9D2_AAD32347B187__INCLUDED_)
