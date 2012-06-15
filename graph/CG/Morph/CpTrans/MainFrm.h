// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__56FCF87A_804B_40B2_B22A_47C3517AAC92__INCLUDED_)
#define AFX_MAINFRM_H__56FCF87A_804B_40B2_B22A_47C3517AAC92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MoreControls.h"
#include "ChildView.h"

class CMainFrame : public CFrameWnd
{
public:
	CMainFrame();
protected:
	DECLARE_DYNAMIC(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar	m_wndStatusBar;
	CToolBar	m_wndToolBar;
	CReBar		m_wndReBar;
	CDialogBar      m_wndDlgBar;
	CMoreControls	m_wndMoreControls;
	CChildView	m_wndView;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	afx_msg void OnButtonChkRes();
	afx_msg void OnButtonChkWait();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnUpdateSpeedFast(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSpeedSlow(CCmdUI* pCmdUI);
	afx_msg void OnButtonPixelOrLine();
	afx_msg void OnButtonPrecise();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	virtual	BOOL setStatus(int, LPCTSTR);
	virtual BOOL getChkres();
	virtual BOOL getChkwait();
	virtual BOOL getChkpixelorline();
	virtual BOOL getChkprecise();

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__56FCF87A_804B_40B2_B22A_47C3517AAC92__INCLUDED_)
