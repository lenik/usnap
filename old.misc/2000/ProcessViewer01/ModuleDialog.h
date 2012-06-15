#if !defined(AFX_MODULEDIALOG_H__32350929_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_)
#define AFX_MODULEDIALOG_H__32350929_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ModuleDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CModuleDialog dialog

class CModuleDialog : public CDialog
{
// Construction
public:
	CModuleDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CModuleDialog)
	enum { IDD = IDD_VMODULE };
	int		m_mList;
	CString	m_pAddress;
	DWORD	m_pData;
	int		m_pType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModuleDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CModuleDialog)
	afx_msg void OnPrefresh();
	afx_msg void OnSelchangePlist();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODULEDIALOG_H__32350929_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_)
