#if !defined(AFX_HELLOPPG_H__5C551DAA_572A_4A17_BF5B_80B7B71FCAE9__INCLUDED_)
#define AFX_HELLOPPG_H__5C551DAA_572A_4A17_BF5B_80B7B71FCAE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// HelloPpg.h : Declaration of the CHelloPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CHelloPropPage : See HelloPpg.cpp.cpp for implementation.

class CHelloPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CHelloPropPage)
	DECLARE_OLECREATE_EX(CHelloPropPage)

// Constructor
public:
	CHelloPropPage();

// Dialog Data
	//{{AFX_DATA(CHelloPropPage)
	enum { IDD = IDD_PROPPAGE_HELLO };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CHelloPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELLOPPG_H__5C551DAA_572A_4A17_BF5B_80B7B71FCAE9__INCLUDED)
