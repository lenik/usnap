#if !defined(AFX_LOGDIALOG_H__D2B0B266_1E62_4CD1_A88C_30E1B0223DA0__INCLUDED_)
#define AFX_LOGDIALOG_H__D2B0B266_1E62_4CD1_A88C_30E1B0223DA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogDialog dialog

class CLogDialog : public CDialog
{
// Construction
public:
	CLogDialog(CWnd* pParent = NULL, CString log = _T(""));   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLogDialog)
	enum { IDD = IDD_DIALOG_LOG };
	CString	m_strLog;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGDIALOG_H__D2B0B266_1E62_4CD1_A88C_30E1B0223DA0__INCLUDED_)
