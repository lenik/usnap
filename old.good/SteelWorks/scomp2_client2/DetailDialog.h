//{{AFX_INCLUDES()
#include "htmlsrc\dhtmledit.h"
//}}AFX_INCLUDES
#if !defined(AFX_DETAILDIALOG_H__DE94118C_2F81_4668_B53A_62AE989B3A0B__INCLUDED_)
#define AFX_DETAILDIALOG_H__DE94118C_2F81_4668_B53A_62AE989B3A0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DetailDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDetailDialog dialog

class CDetailDialog : public CDialog
{
// Construction
public:
	CDetailDialog(CWnd* pParent = NULL, CString initText = _T(""));   // standard constructor

private:
	BOOL	bFirstInited;
	CString	m_strText;

// Dialog Data
	//{{AFX_DATA(CDetailDialog)
	enum { IDD = IDD_DETAIL };
	CStatic	m_con_dhtml_leftborder;
	CDHTMLEdit	m_dhtml;
	CString	m_strInfo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDetailDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDetailDialog)
	virtual void OnOK();
	afx_msg void OnButtonSave();
	virtual BOOL OnInitDialog();
	afx_msg void OnDocumentCompleteDhtml();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DETAILDIALOG_H__DE94118C_2F81_4668_B53A_62AE989B3A0B__INCLUDED_)
