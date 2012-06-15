// materialView.h : interface of the CMaterialView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATERIALVIEW_H__FA95CAEC_C06F_11D3_8ACD_484C0001E209__INCLUDED_)
#define AFX_MATERIALVIEW_H__FA95CAEC_C06F_11D3_8ACD_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

class CMaterialView : public CView
{
protected: // create from serialization only
	CMaterialView();
	DECLARE_DYNCREATE(CMaterialView)

// Attributes
public:
	CMaterialDoc* GetDocument();
public:
	HGLRC hglrc;
	BOOL ldown;
	BOOL dcenabled;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMaterialView)
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
	virtual ~CMaterialView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void myinit();
	void display();
	void dispcolor(CPoint);

// Generated message map functions
protected:
	//{{AFX_MSG(CMaterialView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in materialView.cpp
inline CMaterialDoc* CMaterialView::GetDocument()
   { return (CMaterialDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATERIALVIEW_H__FA95CAEC_C06F_11D3_8ACD_484C0001E209__INCLUDED_)
