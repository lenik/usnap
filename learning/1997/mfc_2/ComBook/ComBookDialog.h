#if !defined(AFX_COMBOOKDIALOG_H__EB2B97B0_C022_11D3_8D4F_E2E9095ED3EF__INCLUDED_)
#define AFX_COMBOOKDIALOG_H__EB2B97B0_C022_11D3_8D4F_E2E9095ED3EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ComBookDialog.h : header file
//

#include "ComEntry.h"

/////////////////////////////////////////////////////////////////////////////
// CComBookDialog dialog

class CComBookDialog : public CDialog
{
// Construction
public:
	CComBookDialog(CWnd* pParent = NULL);   // standard constructor
	CComBookDialog(CEntry *pEntry, CWnd *pParent = NULL);

// Dialog Data
	//{{AFX_DATA(CComBookDialog)
	enum { IDD = IDD_DIALOG_NSE };
	UINT	m_nYear;
	UINT	m_nHour;
	UINT	m_nMinute;
	UINT	m_nDay;
	CString	m_sText;
	int		m_nAMPM;
	BOOL	m_bDisable;
	int		m_nMonth;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComBookDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CComBookDialog)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOOKDIALOG_H__EB2B97B0_C022_11D3_8D4F_E2E9095ED3EF__INCLUDED_)
