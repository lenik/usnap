// dr_guiView.h : interface of the CDr_guiView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DR_GUIVIEW_H__B93371ED_9452_4222_AF54_BA0E2F11D450__INCLUDED_)
#define AFX_DR_GUIVIEW_H__B93371ED_9452_4222_AF54_BA0E2F11D450__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDr_guiView : public CView
{
protected: // create from serialization only
	CDr_guiView();
	DECLARE_DYNCREATE(CDr_guiView)

// Attributes
public:
	CDr_guiDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDr_guiView)
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
	virtual ~CDr_guiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDr_guiView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in dr_guiView.cpp
inline CDr_guiDoc* CDr_guiView::GetDocument()
   { return (CDr_guiDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DR_GUIVIEW_H__B93371ED_9452_4222_AF54_BA0E2F11D450__INCLUDED_)
