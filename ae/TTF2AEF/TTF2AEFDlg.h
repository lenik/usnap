// TTF2AEFDlg.h : header file
//

#if !defined(AFX_TTF2AEFDLG_H__2FBEA211_1339_4AA8_93B4_C29F3DACD228__INCLUDED_)
#define AFX_TTF2AEFDLG_H__2FBEA211_1339_4AA8_93B4_C29F3DACD228__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTTF2AEFDlg dialog

class CTTF2AEFDlg : public CDialog
{
// Construction
public:
	CTTF2AEFDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTTF2AEFDlg)
	enum { IDD = IDD_TTF2AEF_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTTF2AEFDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTTF2AEFDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TTF2AEFDLG_H__2FBEA211_1339_4AA8_93B4_C29F3DACD228__INCLUDED_)
