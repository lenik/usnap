// src_client1Dlg.h : header file
//

#if !defined(AFX_SRC_CLIENT1DLG_H__DCC5C66E_2961_450D_B50C_B4756D7D024C__INCLUDED_)
#define AFX_SRC_CLIENT1DLG_H__DCC5C66E_2961_450D_B50C_B4756D7D024C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSrc_client1Dlg dialog

class CSrc_client1Dlg : public CDialog
{
// Construction
public:
	CSrc_client1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSrc_client1Dlg)
	enum { IDD = IDD_SRC_CLIENT1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSrc_client1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSrc_client1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SRC_CLIENT1DLG_H__DCC5C66E_2961_450D_B50C_B4756D7D024C__INCLUDED_)
