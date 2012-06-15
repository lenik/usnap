#if !defined(AFX_TESTCOMCTL_H__E2B06DDA_8E6A_436D_8E10_32F42DCA1EBA__INCLUDED_)
#define AFX_TESTCOMCTL_H__E2B06DDA_8E6A_436D_8E10_32F42DCA1EBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// TestComCtl.h : Declaration of the CTestComCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CTestComCtrl : See TestComCtl.cpp for implementation.

class CTestComCtrl : public COleControl
{
	DECLARE_DYNCREATE(CTestComCtrl)

// Constructor
public:
	CTestComCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestComCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CTestComCtrl();

	DECLARE_OLECREATE_EX(CTestComCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CTestComCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CTestComCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CTestComCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CTestComCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CTestComCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();
	afx_msg void AboutBox2();

// Event maps
	//{{AFX_EVENT(CTestComCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CTestComCtrl)
		// NOTE: ClassWizard will add and remove enumeration elements here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCOMCTL_H__E2B06DDA_8E6A_436D_8E10_32F42DCA1EBA__INCLUDED)
