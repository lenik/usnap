#if !defined(AFX_PROCESSVIEW_H__A12A69D5_C07E_11D3_8DA3_C1CB78A83C75__INCLUDED_)
#define AFX_PROCESSVIEW_H__A12A69D5_C07E_11D3_8DA3_C1CB78A83C75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProcessView.h : header file
//

#define TYPE_BYTE	0
#define TYPE_WORD	1
#define TYPE_DWORD	2

/////////////////////////////////////////////////////////////////////////////
// CProcessView dialog

class CProcessView : public CDialog
{
// Construction
public:
	CProcessView(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProcessView)
	enum { IDD = IDD_PROCESSVIEW };
	DWORD	m_dwAddress;
	DWORD	m_dwValue;
	int		m_nType;
	int		m_nSelectPriority;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcessView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProcessView)
	afx_msg void OnRead();
	afx_msg void OnWrite();
	afx_msg void OnRefresh();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCESSVIEW_H__A12A69D5_C07E_11D3_8DA3_C1CB78A83C75__INCLUDED_)
