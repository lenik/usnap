#if !defined(AFX_SSDIALOG_H__29D75370_67C8_41A4_931E_DE67A53DF391__INCLUDED_)
#define AFX_SSDIALOG_H__29D75370_67C8_41A4_931E_DE67A53DF391__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SSDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSSDialog dialog

class CSSDialog : public CDialog
{
public:
	CView		*m_pviewOwner;
	IStorage	*m_pStg;

// Construction
public:
	CSSDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSSDialog)
	enum { IDD = IDD_SS };
	CTreeCtrl	m_treeStorage;
	CTreeCtrl	m_treeContent;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSSDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSSDialog)
	afx_msg void OnClickTreestorage(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSDIALOG_H__29D75370_67C8_41A4_931E_DE67A53DF391__INCLUDED_)
