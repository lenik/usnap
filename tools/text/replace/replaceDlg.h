// replaceDlg.h : header file
//

#if !defined(AFX_REPLACEDLG_H__0B0883C8_DB24_11D4_8A3A_5254AB307B64__INCLUDED_)
#define AFX_REPLACEDLG_H__0B0883C8_DB24_11D4_8A3A_5254AB307B64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SubstitudingDialog.h"

/////////////////////////////////////////////////////////////////////////////
// CReplaceDlg dialog


class CReplaceDlg : public CDialog
{
// Construction
public:
	CReplaceDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CReplaceDlg)
	enum { IDD = IDD_REPLACE_DIALOG };
	CListBox	m_lstSubs;
	CListBox	m_lstFiles;
	CString	m_strCurrentFilename;
	CString	m_strSubcon;
	//}}AFX_DATA

	typedef std::pair<CString, CString> CSTRPAIR;
	typedef std::list<CSTRPAIR> SUBSLIST;
	typedef SUBSLIST::iterator SUBSLISTI;

	SUBSLIST	m_subslist;

	CSTRPAIR&	geti(int i);
	SUBSLISTI	getsi(int i);

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReplaceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReplaceDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonExit();
	afx_msg void OnButtonSubstitude();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonRemove();
	afx_msg void OnButtonClear();
	afx_msg void OnButtonSadd();
	afx_msg void OnDblclkListSubstitude();
	afx_msg void OnButtonSremove();
	afx_msg void OnButtonSclear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REPLACEDLG_H__0B0883C8_DB24_11D4_8A3A_5254AB307B64__INCLUDED_)
