#if !defined(AFX_ITERDIALOG_H__EE98B566_9474_42FC_8033_8ED91F441422__INCLUDED_)
#define AFX_ITERDIALOG_H__EE98B566_9474_42FC_8033_8ED91F441422__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CIterDialog;

#include "DrawerDoc.h"

// IterDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIterDialog dialog

class CIterDialog : public CDialog
{
// Construction
public:
	CIterDialog(CDrawerDoc *pDrawerDoc, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CIterDialog)
	enum { IDD = IDD_ITER };
	CSpinButtonCtrl	m_spinChoice;
	CString	m_strIterStatus;
	UINT	m_nIterCount;
	CString	m_igInit;
	CString	m_igSegment;
	CString	m_igB;
	CString	m_igA;
	BOOL	m_bIterAngle;
	//}}AFX_DATA

	CDrawerDoc *pDoc;
	void SwitchTo(UINT iFrom, UINT iTo);
	void Save(UINT);
	void Restore(UINT);
	void Add();
	void Erase();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIterDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CIterDialog)
	afx_msg void OnDeltaposIterChoice(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ITERDIALOG_H__EE98B566_9474_42FC_8033_8ED91F441422__INCLUDED_)
