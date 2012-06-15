#if !defined(AFX_INFODIALOG_H__BBA8F0D5_5452_4587_BB04_05C7368BB3B1__INCLUDED_)
#define AFX_INFODIALOG_H__BBA8F0D5_5452_4587_BB04_05C7368BB3B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InfoDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInfoDialog dialog

class CInfoDialog : public CDialog
{
// Construction
public:
	CInfoDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInfoDialog)
	enum { IDD = IDD_DIALOG_INFO };
	CString	m_strBBOX;
	CString	m_strCHECKSUM;
	CString	m_strHMF;
	CString	m_strINCH;
	CString	m_strKEY;
	CString	m_strRESERVED;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInfoDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInfoDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFODIALOG_H__BBA8F0D5_5452_4587_BB04_05C7368BB3B1__INCLUDED_)
