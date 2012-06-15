// TextEditorView.h : interface of the CTextEditorView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEXTEDITORVIEW_H__4D81D94E_C06D_11D3_8D51_D78E1C71984A__INCLUDED_)
#define AFX_TEXTEDITORVIEW_H__4D81D94E_C06D_11D3_8D51_D78E1C71984A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTextEditorView : public CView
{
protected:
	int m_nLineNo;
	int m_nCharOffset;
	int m_nCharHeight;
	int m_nCharWidth;

	void UpdateCaret();

	int DPtoLine(int nDP);
	int LinetoDP(int nLine);

	void Output(CDC *pDC, CString sText, int nOffset);

protected:
	int m_nViewOffset;
	int GetWindowHeight();
	int GetDocHeight();
	// Update scroll bars
	void UpdateScrollBar();

protected: // create from serialization only
	CTextEditorView();
	DECLARE_DYNCREATE(CTextEditorView)

// Attributes
public:
	CTextEditorDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextEditorView)
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
	virtual ~CTextEditorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTextEditorView)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TextEditorView.cpp
inline CTextEditorDoc* CTextEditorView::GetDocument()
   { return (CTextEditorDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTEDITORVIEW_H__4D81D94E_C06D_11D3_8D51_D78E1C71984A__INCLUDED_)
