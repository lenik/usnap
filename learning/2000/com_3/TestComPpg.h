#if !defined(AFX_TESTCOMPPG_H__DD7B55B1_1FBF_4593_8D57_5412CDBA2684__INCLUDED_)
#define AFX_TESTCOMPPG_H__DD7B55B1_1FBF_4593_8D57_5412CDBA2684__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// TestComPpg.h : Declaration of the CTestComPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CTestComPropPage : See TestComPpg.cpp.cpp for implementation.

class CTestComPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CTestComPropPage)
	DECLARE_OLECREATE_EX(CTestComPropPage)

// Constructor
public:
	CTestComPropPage();

// Dialog Data
	//{{AFX_DATA(CTestComPropPage)
	enum { IDD = IDD_PROPPAGE_TESTCOM };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CTestComPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCOMPPG_H__DD7B55B1_1FBF_4593_8D57_5412CDBA2684__INCLUDED)
