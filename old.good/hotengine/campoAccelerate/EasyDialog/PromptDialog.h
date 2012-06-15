#if !defined(AFX_PROMPTDIALOG_H__095F3B08_33AD_47D6_8137_BB7930A060E5__INCLUDED_)
#define AFX_PROMPTDIALOG_H__095F3B08_33AD_47D6_8137_BB7930A060E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PromptDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPromptDialog dialog

class CPromptDialog : public CDialog
{
// Construction
public:
	CPromptDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPromptDialog)
	enum { IDD = IDD_PROMPT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPromptDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPromptDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROMPTDIALOG_H__095F3B08_33AD_47D6_8137_BB7930A060E5__INCLUDED_)
