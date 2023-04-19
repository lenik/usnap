#if !defined(AFX_HEXEDITCTLCTL_H__9F4A1228_B7D0_491D_AC42_90EF46079264__INCLUDED_)
#define AFX_HEXEDITCTLCTL_H__9F4A1228_B7D0_491D_AC42_90EF46079264__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// HexEditCtlCtl.h : Declaration of the CHexEditCtlCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CHexEditCtlCtrl : See HexEditCtlCtl.cpp for implementation.

struct ModifyRecord {
	int Offset;
	int OldByte;
	int NewByte;
};

typedef std::vector<ModifyRecord> MODIFYRECORDS;

class CHexEditCtlCtrl : public COleControl
{
	DECLARE_DYNCREATE(CHexEditCtlCtrl)

// Constructor
public:
	CHexEditCtlCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHexEditCtlCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CHexEditCtlCtrl();

	DECLARE_OLECREATE_EX(CHexEditCtlCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CHexEditCtlCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CHexEditCtlCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CHexEditCtlCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CHexEditCtlCtrl)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CHexEditCtlCtrl)
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CHexEditCtlCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CHexEditCtlCtrl)
	//}}AFX_DISP_ID
	};

public:
	// 视区的宽度和高度
	int				m_nWidth;
	int				m_nHeight;

	// 水平和垂直的页边距
	int				m_leftMargin;
	int				m_topMargin;

	// 是否显示亚洲字符
	BOOL			m_bRawOutput;

protected:
	LPBYTE			m_lpData;
	int				m_nDataLength;

	BOOL			m_bEditOnChars;

	int				m_nRow;
	int				m_nCol;
	int				m_bHalf;

	int				m_nViewOffset;

	BOOL			m_bDirty;

	MODIFYRECORDS	m_ModifyRecords;

	HBITMAP			m_hbmpCaret;

	TEXTMETRIC		m_tm;

	// in current view
	int effective_height();
	// in current row of current view.
	int effective_width(int row);

	BOOL Refresh(CDC*);
	BOOL UpdateCaret();
	virtual void OnFontChanged();

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HEXEDITCTLCTL_H__9F4A1228_B7D0_491D_AC42_90EF46079264__INCLUDED)
