// clipbrdViewerDlg.h : header file
//
//{{AFX_INCLUDES()
#include "sliderrefresh.h"
//}}AFX_INCLUDES

#if !defined(AFX_CLIPBRDVIEWERDLG_H__0A62C447_667E_4FAE_B492_F73134A8DF95__INCLUDED_)
#define AFX_CLIPBRDVIEWERDLG_H__0A62C447_667E_4FAE_B492_F73134A8DF95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClipbrdViewerDlg dialog

class CClipbrdViewerDlg : public CDialog
{
// Construction
public:
	CClipbrdViewerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CClipbrdViewerDlg)
	enum { IDD = IDD_CLIPBRDVIEWER_DIALOG };
	CString	m_strAvail;
	CString	m_strIsStatic;
	CSliderRefresh	m_sliderRefresh;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClipbrdViewerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClipbrdViewerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnChangeSliderRefresh();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIPBRDVIEWERDLG_H__0A62C447_667E_4FAE_B492_F73134A8DF95__INCLUDED_)
