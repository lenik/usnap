#if !defined(AFX_SUBDIALOG_H__0B0883D0_DB24_11D4_8A3A_5254AB307B64__INCLUDED_)
#define AFX_SUBDIALOG_H__0B0883D0_DB24_11D4_8A3A_5254AB307B64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubDialog dialog

#pragma warning(disable: 4806)

class CSubDialog : public CDialog
{
// Construction
public:
	CSubDialog(CString src = _T(""), CString dest = _T(""));   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSubDialog)
	enum { IDD = IDD_DIALOG_SUB };
	CString	m_strDest;
	CString	m_strSrc;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSubDialog)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBDIALOG_H__0B0883D0_DB24_11D4_8A3A_5254AB307B64__INCLUDED_)
