#if !defined(AFX_PROCESSDIALOG_H__3235092A_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_)
#define AFX_PROCESSDIALOG_H__3235092A_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProcessDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProcessDialog dialog

class CProcessDialog : public CDialog
{
// Construction
public:
	CProcessDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProcessDialog)
	enum { IDD = IDD_VPROCESS };
	CListBox	m_lstpList;
	DWORD	m_pAddress;
	DWORD	m_pData;
	CString	m_pList;
	int		m_pType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcessDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProcessDialog)
	afx_msg void OnPrefresh();
	afx_msg void OnPread();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCESSDIALOG_H__3235092A_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_)
