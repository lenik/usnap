// DrawerView.h : interface of the CDrawerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWERVIEW_H__72D349B0_F94D_419E_B809_3373DDF574C2__INCLUDED_)
#define AFX_DRAWERVIEW_H__72D349B0_F94D_419E_B809_3373DDF574C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawerView : public CView
{
protected: // create from serialization only
	CDrawerView();
	DECLARE_DYNCREATE(CDrawerView)

// Attributes
public:
	CDrawerDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawerView)
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
	virtual ~CDrawerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawerView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DrawerView.cpp
inline CDrawerDoc* CDrawerView::GetDocument()
   { return (CDrawerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWERVIEW_H__72D349B0_F94D_419E_B809_3373DDF574C2__INCLUDED_)
