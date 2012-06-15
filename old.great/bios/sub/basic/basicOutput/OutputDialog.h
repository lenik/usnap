#if !defined(AFX_OUTPUTDIALOG_H__5E818D56_1B5E_426C_A77D_E6C1C00B3DB7__INCLUDED_)
#define AFX_OUTPUTDIALOG_H__5E818D56_1B5E_426C_A77D_E6C1C00B3DB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OutputDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COutputDialog dialog

class COutputDialog : public CDialog
{
// Construction
public:
	COutputDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COutputDialog)
	enum { IDD = IDD_DIALOG_OUTPUT };
	CEdit	m_mainbox;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutputDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COutputDialog)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTPUTDIALOG_H__5E818D56_1B5E_426C_A77D_E6C1C00B3DB7__INCLUDED_)
