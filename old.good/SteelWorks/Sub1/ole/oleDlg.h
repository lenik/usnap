// oleDlg.h : header file
//
//{{AFX_INCLUDES()
#include "webcalc.h"
//}}AFX_INCLUDES

#if !defined(AFX_OLEDLG_H__23E16511_ADA2_45E3_8EF5_26B6ED51A722__INCLUDED_)
#define AFX_OLEDLG_H__23E16511_ADA2_45E3_8EF5_26B6ED51A722__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COleDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// COleDlg dialog

class COleDlg : public CDialog
{
	DECLARE_DYNAMIC(COleDlg);
	friend class COleDlgAutoProxy;

// Construction
public:
	COleDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~COleDlg();

// Dialog Data
	//{{AFX_DATA(COleDlg)
	enum { IDD = IDD_OLE_DIALOG };
	CWebCalc	m_s;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	COleDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(COleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBeforeCommandSpreadsheet1(LPDISPATCH EventInfo);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDLG_H__23E16511_ADA2_45E3_8EF5_26B6ED51A722__INCLUDED_)
