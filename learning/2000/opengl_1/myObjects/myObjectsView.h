// myObjectsView.h : interface of the CMyObjectsView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYOBJECTSVIEW_H__B6A71ECC_C087_11D3_8ACC_484C0001E209__INCLUDED_)
#define AFX_MYOBJECTSVIEW_H__B6A71ECC_C087_11D3_8ACC_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

#include <math.h>

#ifndef PI
#	define PI	3.14159265358979325
#endif

class CMyObjectsView : public CView
{
protected: // create from serialization only
	CMyObjectsView();
	DECLARE_DYNCREATE(CMyObjectsView)

// Attributes
public:
	CMyObjectsDoc* GetDocument();
public:
	HGLRC hglrc;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyObjectsView)
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
	virtual ~CMyObjectsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void myinit();
	void display();
	void getNormalize(double *nx, double *ny, double *nz, double x1, double y1, double z1, double x2, double y2, double z2);

// Generated message map functions
protected:
	//{{AFX_MSG(CMyObjectsView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in myObjectsView.cpp
inline CMyObjectsDoc* CMyObjectsView::GetDocument()
   { return (CMyObjectsDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYOBJECTSVIEW_H__B6A71ECC_C087_11D3_8ACC_484C0001E209__INCLUDED_)
