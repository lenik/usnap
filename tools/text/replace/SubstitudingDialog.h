#if !defined(AFX_SUBSTITUDINGDIALOG_H__43175920_DB2A_11D4_8A3A_5254AB307B64__INCLUDED_)
#define AFX_SUBSTITUDINGDIALOG_H__43175920_DB2A_11D4_8A3A_5254AB307B64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubstitudingDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubstitudingDialog dialog

class CSubstitudingDialog : public CDialog
{
// Construction
public:
	CSubstitudingDialog();   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSubstitudingDialog)
	enum { IDD = IDD_DIALOG_WORK };
	CString	m_strCurrentFilename;
	CString	m_strSubcon;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubstitudingDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSubstitudingDialog)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBSTITUDINGDIALOG_H__43175920_DB2A_11D4_8A3A_5254AB307B64__INCLUDED_)
