// htmlHelloView.h : interface of the CHtmlHelloView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HTMLHELLOVIEW_H__44C5CC9F_E8A9_409B_A347_4A35DEEE6ABF__INCLUDED_)
#define AFX_HTMLHELLOVIEW_H__44C5CC9F_E8A9_409B_A347_4A35DEEE6ABF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHtmlHelloView : public CHtmlView
{
protected: // create from serialization only
	CHtmlHelloView();
	DECLARE_DYNCREATE(CHtmlHelloView)

// Attributes
public:
	CHtmlHelloDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHtmlHelloView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHtmlHelloView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHtmlHelloView)
	afx_msg void OnButton32771();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in htmlHelloView.cpp
inline CHtmlHelloDoc* CHtmlHelloView::GetDocument()
   { return (CHtmlHelloDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTMLHELLOVIEW_H__44C5CC9F_E8A9_409B_A347_4A35DEEE6ABF__INCLUDED_)
