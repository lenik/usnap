// OLEDocumentView.h : interface of the COLEDocumentView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDOCUMENTVIEW_H__BDEF3075_7F25_493F_B42C_854F671571E0__INCLUDED_)
#define AFX_OLEDOCUMENTVIEW_H__BDEF3075_7F25_493F_B42C_854F671571E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COLEDocumentCntrItem;

class COLEDocumentView : public CView
{
protected: // create from serialization only
	COLEDocumentView();
	DECLARE_DYNCREATE(COLEDocumentView)

// Attributes
public:
	COLEDocumentDoc* GetDocument();
	// m_pSelection holds the selection to the current COLEDocumentCntrItem.
	// For many applications, such a member variable isn't adequate to
	//  represent a selection, such as a multiple selection or a selection
	//  of objects that are not COLEDocumentCntrItem objects.  This selection
	//  mechanism is provided just to help you get started.

	// TODO: replace this selection mechanism with one appropriate to your app.
	COLEDocumentCntrItem* m_pSelection;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COLEDocumentView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL IsSelected(const CObject* pDocItem) const;// Container support
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COLEDocumentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COLEDocumentView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OLEDocumentView.cpp
inline COLEDocumentDoc* COLEDocumentView::GetDocument()
   { return (COLEDocumentDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDOCUMENTVIEW_H__BDEF3075_7F25_493F_B42C_854F671571E0__INCLUDED_)
