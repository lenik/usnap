// dv01View.h : interface of the CDv01View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DV01VIEW_H__2AFBD09B_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_)
#define AFX_DV01VIEW_H__2AFBD09B_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDv01View : public CScrollView
{
protected: // create from serialization only
	CDv01View();
	DECLARE_DYNCREATE(CDv01View)
protected:
	UINT m_nPrevIndex;

// Attributes
public:
	CDv01Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDv01View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDv01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDv01View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in dv01View.cpp
inline CDv01Doc* CDv01View::GetDocument()
   { return (CDv01Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DV01VIEW_H__2AFBD09B_C07C_11D3_8D4E_BBF47FF1F969__INCLUDED_)
