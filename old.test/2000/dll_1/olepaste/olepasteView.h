// olepasteView.h : interface of the COlepasteView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEPASTEVIEW_H__F35C0AF9_97D5_46CD_BE07_262134CBC4EC__INCLUDED_)
#define AFX_OLEPASTEVIEW_H__F35C0AF9_97D5_46CD_BE07_262134CBC4EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COlepasteView : public CView
{
protected: // create from serialization only
	COlepasteView();
	DECLARE_DYNCREATE(COlepasteView)

// Attributes
public:
	COlepasteDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COlepasteView)
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
	virtual ~COlepasteView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COlepasteView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in olepasteView.cpp
inline COlepasteDoc* COlepasteView::GetDocument()
   { return (COlepasteDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEPASTEVIEW_H__F35C0AF9_97D5_46CD_BE07_262134CBC4EC__INCLUDED_)
