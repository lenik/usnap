#if !defined(AFX_XEDITBOXPPG_H__D430605A_9E53_4967_A484_8AE3C385EF4C__INCLUDED_)
#define AFX_XEDITBOXPPG_H__D430605A_9E53_4967_A484_8AE3C385EF4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// XEditBoxPpg.h : Declaration of the CXEditBoxPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CXEditBoxPropPage : See XEditBoxPpg.cpp.cpp for implementation.

class CXEditBoxPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CXEditBoxPropPage)
	DECLARE_OLECREATE_EX(CXEditBoxPropPage)

// Constructor
public:
	CXEditBoxPropPage();

// Dialog Data
	//{{AFX_DATA(CXEditBoxPropPage)
	enum { IDD = IDD_PROPPAGE_XEDITBOX };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CXEditBoxPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XEDITBOXPPG_H__D430605A_9E53_4967_A484_8AE3C385EF4C__INCLUDED)
