// mfc04Dlg.h : header file
//

#if !defined(AFX_MFC04DLG_H__C825B0A6_C07B_11D3_8D67_9218F7A2469C__INCLUDED_)
#define AFX_MFC04DLG_H__C825B0A6_C07B_11D3_8D67_9218F7A2469C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMfc04Dlg dialog

class CMfc04Dlg : public CDialog
{
// Construction
public:
	CMfc04Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMfc04Dlg)
	enum { IDD = IDD_MFC04_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfc04Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMfc04Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC04DLG_H__C825B0A6_C07B_11D3_8D67_9218F7A2469C__INCLUDED_)
