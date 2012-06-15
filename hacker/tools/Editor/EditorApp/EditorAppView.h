// EditorAppView.h : interface of the CEditorAppView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EDITORAPPVIEW_H__1F35464A_68B1_4ECB_BF77_AD8F066347C9__INCLUDED_)
#define AFX_EDITORAPPVIEW_H__1F35464A_68B1_4ECB_BF77_AD8F066347C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEditorAppView : public CView
{
protected: // create from serialization only
	CEditorAppView();
	DECLARE_DYNCREATE(CEditorAppView)

// Attributes
public:
	CEditorAppDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditorAppView)
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
	virtual ~CEditorAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEditorAppView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in EditorAppView.cpp
inline CEditorAppDoc* CEditorAppView::GetDocument()
   { return (CEditorAppDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITORAPPVIEW_H__1F35464A_68B1_4ECB_BF77_AD8F066347C9__INCLUDED_)
