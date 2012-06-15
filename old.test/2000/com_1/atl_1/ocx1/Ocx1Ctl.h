#if !defined(AFX_OCX1CTL_H__CAD68C67_8808_49E8_8159_8CAD6B7624CF__INCLUDED_)
#define AFX_OCX1CTL_H__CAD68C67_8808_49E8_8159_8CAD6B7624CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Ocx1Ctl.h : Declaration of the COcx1Ctrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// COcx1Ctrl : See Ocx1Ctl.cpp for implementation.

class COcx1Ctrl : public COleControl
{
	DECLARE_DYNCREATE(COcx1Ctrl)

// Constructor
public:
	COcx1Ctrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COcx1Ctrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~COcx1Ctrl();

	DECLARE_OLECREATE_EX(COcx1Ctrl)    // Class factory and guid
	DECLARE_OLETYPELIB(COcx1Ctrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(COcx1Ctrl)     // Property page IDs
	DECLARE_OLECTLTYPE(COcx1Ctrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(COcx1Ctrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(COcx1Ctrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(COcx1Ctrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(COcx1Ctrl)
		// NOTE: ClassWizard will add and remove enumeration elements here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCX1CTL_H__CAD68C67_8808_49E8_8159_8CAD6B7624CF__INCLUDED)
