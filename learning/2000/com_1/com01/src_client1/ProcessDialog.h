#if !defined(AFX_PROCESSDIALOG_H__D51F1B28_19C8_411A_8B70_3F478D016977__INCLUDED_)
#define AFX_PROCESSDIALOG_H__D51F1B28_19C8_411A_8B70_3F478D016977__INCLUDED_

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
	enum { IDD = IDD_PROCESS };
	CString	m_strName;
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
	afx_msg void OnButtonCreateThread();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCESSDIALOG_H__D51F1B28_19C8_411A_8B70_3F478D016977__INCLUDED_)
