#if !defined(AFX_DOGPPG_H__3080D182_6F77_4A59_8ECA_0379543159B3__INCLUDED_)
#define AFX_DOGPPG_H__3080D182_6F77_4A59_8ECA_0379543159B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// DogPpg.h : Declaration of the CDogPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CDogPropPage : See DogPpg.cpp.cpp for implementation.

class CDogPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CDogPropPage)
	DECLARE_OLECREATE_EX(CDogPropPage)

// Constructor
public:
	CDogPropPage();

// Dialog Data
	//{{AFX_DATA(CDogPropPage)
	enum { IDD = IDD_PROPPAGE_DOG };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CDogPropPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOGPPG_H__3080D182_6F77_4A59_8ECA_0379543159B3__INCLUDED)
