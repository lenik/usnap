// RobotView.h : interface of the CRobotView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOTVIEW_H__B6A71EF6_C087_11D3_8ACC_484C0001E209__INCLUDED_)
#define AFX_ROBOTVIEW_H__B6A71EF6_C087_11D3_8ACC_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

#ifndef PI
#	define PI	3.14159265358979325
#endif

class CRobotView : public CView
{
protected: // create from serialization only
	CRobotView();
	DECLARE_DYNCREATE(CRobotView)

// Attributes
public:
	CRobotDoc* GetDocument();
public:
	HGLRC hglrc;
	int l_arm, r_arm;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobotView)
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
	virtual ~CRobotView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void display();
	void leftarmup();
	void leftarmdown();
	void rightarmup();
	void rightarmdown();

// Generated message map functions
protected:
	//{{AFX_MSG(CRobotView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RobotView.cpp
inline CRobotDoc* CRobotView::GetDocument()
   { return (CRobotDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOTVIEW_H__B6A71EF6_C087_11D3_8ACC_484C0001E209__INCLUDED_)
