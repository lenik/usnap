// ColorTriView.h : interface of the CColorTriView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COLORTRIVIEW_H__B6A71F0A_C087_11D3_8ACC_484C0001E209__INCLUDED_)
#define AFX_COLORTRIVIEW_H__B6A71F0A_C087_11D3_8ACC_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <sys/timeb.h>
#include <time.h>
#include <process.h>
#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

class CColorTriView : public CView
{
protected: // create from serialization only
	CColorTriView();
	DECLARE_DYNCREATE(CColorTriView)

// Attributes
public:
	CColorTriDoc* GetDocument();
public:
	HGLRC hglrc;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorTriView)
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
	virtual ~CColorTriView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void myinit();
	void display();

// Generated message map functions
protected:
	//{{AFX_MSG(CColorTriView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ColorTriView.cpp
inline CColorTriDoc* CColorTriView::GetDocument()
   { return (CColorTriDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORTRIVIEW_H__B6A71F0A_C087_11D3_8ACC_484C0001E209__INCLUDED_)
