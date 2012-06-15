// HelloView.h : interface of the CHelloView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HELLOVIEW_H__DF6EA7F0_C089_11D3_8AC9_484C0001E209__INCLUDED_)
#define AFX_HELLOVIEW_H__DF6EA7F0_C089_11D3_8AC9_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <GL\gl.h>
#include <GL\glu.h>
#include <GL\glaux.h>

class CHelloView : public CView
{
protected: // create from serialization only
	CHelloView();
	DECLARE_DYNCREATE(CHelloView)

// Attributes
public:
	CHelloDoc* GetDocument();

	HGLRC hglrc;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHelloView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHelloView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	void myinit();
	void display();

// Generated message map functions
protected:
	//{{AFX_MSG(CHelloView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HelloView.cpp
inline CHelloDoc* CHelloView::GetDocument()
   { return (CHelloDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELLOVIEW_H__DF6EA7F0_C089_11D3_8AC9_484C0001E209__INCLUDED_)
