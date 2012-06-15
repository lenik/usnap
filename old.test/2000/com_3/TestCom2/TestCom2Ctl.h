#if !defined(AFX_TESTCOM2CTL_H__4F8D60ED_DF41_4F90_B8B7_D3FB81B2A02B__INCLUDED_)
#define AFX_TESTCOM2CTL_H__4F8D60ED_DF41_4F90_B8B7_D3FB81B2A02B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// TestCom2Ctl.h : Declaration of the CTestCom2Ctrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CTestCom2Ctrl : See TestCom2Ctl.cpp for implementation.

class CTestCom2Ctrl : public COleControl
{
	DECLARE_DYNCREATE(CTestCom2Ctrl)

// Constructor
public:
	CTestCom2Ctrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestCom2Ctrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CTestCom2Ctrl();

	DECLARE_OLECREATE_EX(CTestCom2Ctrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CTestCom2Ctrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CTestCom2Ctrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CTestCom2Ctrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CTestCom2Ctrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CTestCom2Ctrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CTestCom2Ctrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CTestCom2Ctrl)
		// NOTE: ClassWizard will add and remove enumeration elements here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCOM2CTL_H__4F8D60ED_DF41_4F90_B8B7_D3FB81B2A02B__INCLUDED)
