// TextPainterView.h : interface of the CTextPainterView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEXTPAINTERVIEW_H__086AA0CD_C087_11D3_82CE_F690E07058CA__INCLUDED_)
#define AFX_TEXTPAINTERVIEW_H__086AA0CD_C087_11D3_82CE_F690E07058CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTextPainterView : public CView
{
protected: // create from serialization only
	CTextPainterView();
	DECLARE_DYNCREATE(CTextPainterView)

// Attributes
public:
	CTextPainterDoc* GetDocument();

protected:
	enum cmdstatus {
		noop,
		createtext,
		scaletext,
		rotatetext
	};
	enum downstatus {
		none,
		selected,
		dragbox,
		onborder,
		oncorner
	};
	enum downborder {
		left,
		right,
		top,
		bottom
	};
	enum downcorner{
		topleft,
		topright,
		bottomleft,
		bottomright
	};

	cmdstatus		statusCommand;
	downstatus		statusDown;
	downborder		statusBorder;
	downcorner		statusCorner;

	ctElement *		selectedElement;

	CPoint			posDown;

	CRect			rectDragBoxLast;	// used for erase next time
	CRect			rectDragBox;
	SIZE			sizeBorder;
	BOOL			bRectOn;			// used for identify first rect drawing

// Operations
public:

	void		DrawDragBox(LPRECT);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextPainterView)
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
	virtual ~CTextPainterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTextPainterView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnCommandText();
	afx_msg void OnCommandScale();
	afx_msg void OnCommandRotate();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnCommandSelect();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TextPainterView.cpp
inline CTextPainterDoc* CTextPainterView::GetDocument()
   { return (CTextPainterDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTPAINTERVIEW_H__086AA0CD_C087_11D3_82CE_F690E07058CA__INCLUDED_)
