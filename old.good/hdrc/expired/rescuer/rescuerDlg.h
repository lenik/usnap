// rescuerDlg.h : header file
//

#if !defined(AFX_RESCUERDLG_H__8EA808EA_226B_42F8_BE28_D0E702FED08A__INCLUDED_)
#define AFX_RESCUERDLG_H__8EA808EA_226B_42F8_BE28_D0E702FED08A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRescuerDlg dialog

class CRescuerDlg : public CDialog
{
// Construction
public:
	CRescuerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRescuerDlg)
	enum { IDD = IDD_RESCUER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRescuerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRescuerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESCUERDLG_H__8EA808EA_226B_42F8_BE28_D0E702FED08A__INCLUDED_)
