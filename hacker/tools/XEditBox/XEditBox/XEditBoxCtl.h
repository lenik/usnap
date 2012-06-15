#if !defined(AFX_XEDITBOXCTL_H__01E878E9_E537_4E69_B26A_79A400C586F7__INCLUDED_)
#define AFX_XEDITBOXCTL_H__01E878E9_E537_4E69_B26A_79A400C586F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// XEditBoxCtl.h : Declaration of the CXEditBoxCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CXEditBoxCtrl : See XEditBoxCtl.cpp for implementation.

class CXEditBoxCtrl : public COleControl
{
	DECLARE_DYNCREATE(CXEditBoxCtrl)

// Constructor
public:
	CXEditBoxCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXEditBoxCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CXEditBoxCtrl();

	BEGIN_OLEFACTORY(CXEditBoxCtrl)        // Class factory and guid
		virtual BOOL VerifyUserLicense();
		virtual BOOL GetLicenseKey(DWORD, BSTR FAR*);
	END_OLEFACTORY(CXEditBoxCtrl)

	DECLARE_OLETYPELIB(CXEditBoxCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CXEditBoxCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CXEditBoxCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CXEditBoxCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CXEditBoxCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CXEditBoxCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CXEditBoxCtrl)
		// NOTE: ClassWizard will add and remove enumeration elements here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XEDITBOXCTL_H__01E878E9_E537_4E69_B26A_79A400C586F7__INCLUDED)
