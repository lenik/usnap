#if !defined(AFX_THREADDIALOG_H__32350928_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_)
#define AFX_THREADDIALOG_H__32350928_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ThreadDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CThreadDialog dialog

class CThreadDialog : public CDialog
{
// Construction
public:
	CThreadDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CThreadDialog)
	enum { IDD = IDD_VTHREAD };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CThreadDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADDIALOG_H__32350928_C08B_11D3_8D8B_9B78F2ACB14A__INCLUDED_)
