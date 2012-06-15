// MineView.h : interface of the CMineView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MINEVIEW_H__1CDF20DF_F9C0_43A0_9617_85791C528E87__INCLUDED_)
#define AFX_MINEVIEW_H__1CDF20DF_F9C0_43A0_9617_85791C528E87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MineMap.h"

class CMineView : public CView
{
protected: // create from serialization only
	CMineView();
	DECLARE_DYNCREATE(CMineView)

// Attributes
public:
	CMineDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMineView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMineView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MineView.cpp
inline CMineDoc* CMineView::GetDocument()
   { return (CMineDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MINEVIEW_H__1CDF20DF_F9C0_43A0_9617_85791C528E87__INCLUDED_)
