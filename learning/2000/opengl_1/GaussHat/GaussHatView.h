// GaussHatView.h : interface of the CGaussHatView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAUSSHATVIEW_H__7E343DCC_C03C_11D3_8ACB_484C0001E209__INCLUDED_)
#define AFX_GAUSSHATVIEW_H__7E343DCC_C03C_11D3_8ACB_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

#include <math.h>

class CGaussHatView : public CView
{
protected: // create from serialization only
	CGaussHatView();
	DECLARE_DYNCREATE(CGaussHatView)

// Attributes
public:
	CGaussHatDoc* GetDocument();

	HGLRC hglrc;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGaussHatView)
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
	virtual ~CGaussHatView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	void myinit();
	void display();

// Generated message map functions
protected:
	//{{AFX_MSG(CGaussHatView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GaussHatView.cpp
inline CGaussHatDoc* CGaussHatView::GetDocument()
   { return (CGaussHatDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAUSSHATVIEW_H__7E343DCC_C03C_11D3_8ACB_484C0001E209__INCLUDED_)
