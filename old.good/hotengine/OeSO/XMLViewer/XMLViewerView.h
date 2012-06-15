// XMLViewerView.h : interface of the CXMLViewerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_XMLVIEWERVIEW_H__A9A51ACA_93FE_42B0_BC34_4341F65CAD92__INCLUDED_)
#define AFX_XMLVIEWERVIEW_H__A9A51ACA_93FE_42B0_BC34_4341F65CAD92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CXMLViewerView : public CHtmlView
{
protected: // create from serialization only
	CXMLViewerView();
	DECLARE_DYNCREATE(CXMLViewerView)

// Attributes
public:
	CXMLViewerDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXMLViewerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CXMLViewerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	BOOL	bInited;

// Generated message map functions
protected:
	//{{AFX_MSG(CXMLViewerView)
	afx_msg void OnRedraw();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in XMLViewerView.cpp
inline CXMLViewerDoc* CXMLViewerView::GetDocument()
   { return (CXMLViewerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XMLVIEWERVIEW_H__A9A51ACA_93FE_42B0_BC34_4341F65CAD92__INCLUDED_)
