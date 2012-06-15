// solarsysView.h : interface of the CSolarsysView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOLARSYSVIEW_H__B6A71EE0_C087_11D3_8ACC_484C0001E209__INCLUDED_)
#define AFX_SOLARSYSVIEW_H__B6A71EE0_C087_11D3_8ACC_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

#ifndef PI
#	define PI	3.14159265358979325
#endif

class CSolarsysView : public CView
{
protected: // create from serialization only
	CSolarsysView();
	DECLARE_DYNCREATE(CSolarsysView)

// Attributes
public:
	CSolarsysDoc* GetDocument();
public:
	HGLRC hglrc;
	int revolution;
	int rotation;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSolarsysView)
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
	virtual ~CSolarsysView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	//void myinit();
	void display();

	void revanticlockwise();
	void revclockwise();
	void rotationanticlockwise();
	void rotationclockwise();

// Generated message map functions
protected:
	//{{AFX_MSG(CSolarsysView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in solarsysView.cpp
inline CSolarsysDoc* CSolarsysView::GetDocument()
   { return (CSolarsysDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOLARSYSVIEW_H__B6A71EE0_C087_11D3_8ACC_484C0001E209__INCLUDED_)
