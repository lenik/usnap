#if !defined(AFX_HELLOCTL_H__F65E91FE_0AA1_4D77_B6A0_0FD44E088EAB__INCLUDED_)
#define AFX_HELLOCTL_H__F65E91FE_0AA1_4D77_B6A0_0FD44E088EAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// HelloCtl.h : Declaration of the CHelloCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CHelloCtrl : See HelloCtl.cpp for implementation.

class CHelloCtrl : public COleControl
{
	DECLARE_DYNCREATE(CHelloCtrl)

// Constructor
public:
	CHelloCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHelloCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CHelloCtrl();

	DECLARE_OLECREATE_EX(CHelloCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CHelloCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CHelloCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CHelloCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CHelloCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CHelloCtrl)
	afx_msg BOOL method_hello(BSTR FAR* caller);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CHelloCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CHelloCtrl)
	dispidHello = 1L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELLOCTL_H__F65E91FE_0AA1_4D77_B6A0_0FD44E088EAB__INCLUDED)
