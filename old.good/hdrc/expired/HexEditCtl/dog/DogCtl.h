#if !defined(AFX_DOGCTL_H__3F20804A_E210_4F8A_B2B1_6A20F26769DF__INCLUDED_)
#define AFX_DOGCTL_H__3F20804A_E210_4F8A_B2B1_6A20F26769DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// DogCtl.h : Declaration of the CDogCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CDogCtrl : See DogCtl.cpp for implementation.

class CDogCtrl : public COleControl
{
	DECLARE_DYNCREATE(CDogCtrl)

// Constructor
public:
	CDogCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDogCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CDogCtrl();

	DECLARE_OLECREATE_EX(CDogCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CDogCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CDogCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CDogCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CDogCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CDogCtrl)
	afx_msg void ShowName();
	afx_msg long GetRawObject();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CDogCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CDogCtrl)
	dispidShowName = 1L,
	dispidGetRawObject = 2L,
	//}}AFX_DISP_ID
	};

public:
    char *m_szName;

    HWND m_hButtonShow;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOGCTL_H__3F20804A_E210_4F8A_B2B1_6A20F26769DF__INCLUDED)
