// lightView.h : interface of the CLightView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIGHTVIEW_H__36C079AC_C040_11D3_8ACD_484C0001E209__INCLUDED_)
#define AFX_LIGHTVIEW_H__36C079AC_C040_11D3_8ACD_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

class CLightView : public CView
{
protected: // create from serialization only
	CLightView();
	DECLARE_DYNCREATE(CLightView)

// Attributes
public:
	CLightDoc* GetDocument();
public:
	HGLRC hglrc;
public:
	double lx, ly, lz;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLightView)
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
	virtual ~CLightView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void myinit();
	void display();

// Generated message map functions
protected:
	//{{AFX_MSG(CLightView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in lightView.cpp
inline CLightDoc* CLightView::GetDocument()
   { return (CLightDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIGHTVIEW_H__36C079AC_C040_11D3_8ACD_484C0001E209__INCLUDED_)
