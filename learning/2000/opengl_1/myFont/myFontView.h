// myFontView.h : interface of the CMyFontView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYFONTVIEW_H__F2818E1D_C080_11D3_8ACD_484C0001E209__INCLUDED_)
#define AFX_MYFONTVIEW_H__F2818E1D_C080_11D3_8ACD_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

class CMyFontView : public CView
{
protected: // create from serialization only
	CMyFontView();
	DECLARE_DYNCREATE(CMyFontView)

// Attributes
public:
	CMyFontDoc* GetDocument();
public:
	HGLRC hglrc;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyFontView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyFontView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void myinit();
	void display();

// Generated message map functions
protected:
	//{{AFX_MSG(CMyFontView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in myFontView.cpp
inline CMyFontDoc* CMyFontView::GetDocument()
   { return (CMyFontDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFONTVIEW_H__F2818E1D_C080_11D3_8ACD_484C0001E209__INCLUDED_)
