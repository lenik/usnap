#if !defined(AFX_PRETTYRESULTDIALOG_H__46D8B49D_4701_4BE0_BC25_8B3AD615FF98__INCLUDED_)
#define AFX_PRETTYRESULTDIALOG_H__46D8B49D_4701_4BE0_BC25_8B3AD615FF98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PrettyResultDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPrettyResultDialog dialog

class CPrettyResultDialog : public CDialog
{
// Construction
public:
	CPrettyResultDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPrettyResultDialog)
	enum { IDD = IDD_DIALOG_PRETTY_RESULT };
	CString	m_strComp;
	CString	m_strResult;
	CString	m_strTemp;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrettyResultDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPrettyResultDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRETTYRESULTDIALOG_H__46D8B49D_4701_4BE0_BC25_8B3AD615FF98__INCLUDED_)
