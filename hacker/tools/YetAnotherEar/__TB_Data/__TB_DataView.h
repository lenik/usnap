// __TB_DataView.h : interface of the C__TB_DataView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX___TB_DATAVIEW_H__4633D95C_A480_46DC_9DB5_9F34B2702E4A__INCLUDED_)
#define AFX___TB_DATAVIEW_H__4633D95C_A480_46DC_9DB5_9F34B2702E4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class C__TB_DataView : public CView
{
protected: // create from serialization only
	C__TB_DataView();
	DECLARE_DYNCREATE(C__TB_DataView)

// Attributes
public:
	C__TB_DataDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C__TB_DataView)
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
	virtual ~C__TB_DataView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(C__TB_DataView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in __TB_DataView.cpp
inline C__TB_DataDoc* C__TB_DataView::GetDocument()
   { return (C__TB_DataDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX___TB_DATAVIEW_H__4633D95C_A480_46DC_9DB5_9F34B2702E4A__INCLUDED_)
