// floatstickkerView.h : interface of the CFloatstickkerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLOATSTICKKERVIEW_H__74F6649D_ADE8_4698_A9EE_4B1B62626725__INCLUDED_)
#define AFX_FLOATSTICKKERVIEW_H__74F6649D_ADE8_4698_A9EE_4B1B62626725__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFloatstickkerView : public CView
{
protected: // create from serialization only
	CFloatstickkerView();
	DECLARE_DYNCREATE(CFloatstickkerView)

// Attributes
public:
	CFloatstickkerDoc* GetDocument();

	int LogicToClientX(double x);
	int LogicToClientY(double y);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFloatstickkerView)
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
	virtual ~CFloatstickkerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFloatstickkerView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in floatstickkerView.cpp
inline CFloatstickkerDoc* CFloatstickkerView::GetDocument()
   { return (CFloatstickkerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLOATSTICKKERVIEW_H__74F6649D_ADE8_4698_A9EE_4B1B62626725__INCLUDED_)
