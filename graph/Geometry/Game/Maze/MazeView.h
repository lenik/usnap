// MazeView.h : interface of the CMazeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAZEVIEW_H__6D320F8B_087C_4D4B_8F08_5EC7346560F6__INCLUDED_)
#define AFX_MAZEVIEW_H__6D320F8B_087C_4D4B_8F08_5EC7346560F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMazeView : public CView
{
protected: // create from serialization only
	CMazeView();
	DECLARE_DYNCREATE(CMazeView)

// Attributes
public:
	CMazeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMazeView)
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
	virtual ~CMazeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMazeView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MazeView.cpp
inline CMazeDoc* CMazeView::GetDocument()
   { return (CMazeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAZEVIEW_H__6D320F8B_087C_4D4B_8F08_5EC7346560F6__INCLUDED_)
