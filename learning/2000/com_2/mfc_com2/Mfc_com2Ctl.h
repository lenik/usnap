#if !defined(AFX_MFC_COM2CTL_H__1C70F714_276F_4435_AD91_D9804B8ED6AA__INCLUDED_)
#define AFX_MFC_COM2CTL_H__1C70F714_276F_4435_AD91_D9804B8ED6AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Mfc_com2Ctl.h : Declaration of the CMfc_com2Ctrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CMfc_com2Ctrl : See Mfc_com2Ctl.cpp for implementation.

class CMfc_com2Ctrl : public COleControl
{
	DECLARE_DYNCREATE(CMfc_com2Ctrl)

// Constructor
public:
	CMfc_com2Ctrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfc_com2Ctrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CMfc_com2Ctrl();

	DECLARE_OLECREATE_EX(CMfc_com2Ctrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CMfc_com2Ctrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMfc_com2Ctrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CMfc_com2Ctrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CMfc_com2Ctrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CMfc_com2Ctrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CMfc_com2Ctrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CMfc_com2Ctrl)
		// NOTE: ClassWizard will add and remove enumeration elements here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_COM2CTL_H__1C70F714_276F_4435_AD91_D9804B8ED6AA__INCLUDED)
