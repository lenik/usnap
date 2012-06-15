// XYPatchDlg.h : header file
//

#if !defined(AFX_XYPATCHDLG_H__B1364087_C06C_11D3_82EE_484C0001DF60__INCLUDED_)
#define AFX_XYPATCHDLG_H__B1364087_C06C_11D3_82EE_484C0001DF60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CXYPatchDlg dialog

class CXYPatchDlg : public CDialog
{
// Construction
public:
	CXYPatchDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CXYPatchDlg)
	enum { IDD = IDD_XYPATCH_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXYPatchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CXYPatchDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClickTreePatchContents(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XYPATCHDLG_H__B1364087_C06C_11D3_82EE_484C0001DF60__INCLUDED_)
