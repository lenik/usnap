// ssViewView.h : interface of the CSsViewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SSVIEWVIEW_H__430BFA09_E9E2_456E_B949_54CD7FAD36A8__INCLUDED_)
#define AFX_SSVIEWVIEW_H__430BFA09_E9E2_456E_B949_54CD7FAD36A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ssDialog.h"

class CSsViewView : public CView
{
protected: // create from serialization only
	CSsViewView();
	DECLARE_DYNCREATE(CSsViewView)

// Attributes
public:
	CSsViewDoc* GetDocument();
	CSSDialog	m_ssDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSsViewView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSsViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSsViewView)
	afx_msg void OnViewSs();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ssViewView.cpp
inline CSsViewDoc* CSsViewView::GetDocument()
   { return (CSsViewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSVIEWVIEW_H__430BFA09_E9E2_456E_B949_54CD7FAD36A8__INCLUDED_)
