#if !defined(AFX_HTMLVIEWERDIALOG_H__A2FBCFEC_2CD9_4666_95DC_DD2B1FE2DA77__INCLUDED_)
#define AFX_HTMLVIEWERDIALOG_H__A2FBCFEC_2CD9_4666_95DC_DD2B1FE2DA77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HtmlViewerDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHtmlViewerDialog dialog

class CHtmlViewerDialog : public CDialog
{
// Construction
public:
	CHtmlViewerDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHtmlViewerDialog)
	enum { IDD = IDD_HTMLVIEW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHtmlViewerDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHtmlViewerDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTMLVIEWERDIALOG_H__A2FBCFEC_2CD9_4666_95DC_DD2B1FE2DA77__INCLUDED_)
