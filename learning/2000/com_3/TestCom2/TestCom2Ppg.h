#if !defined(AFX_TESTCOM2PPG_H__CF991DE9_A970_4773_B77E_627ABE221B21__INCLUDED_)
#define AFX_TESTCOM2PPG_H__CF991DE9_A970_4773_B77E_627ABE221B21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// TestCom2Ppg.h : Declaration of the CTestCom2PropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CTestCom2PropPage : See TestCom2Ppg.cpp.cpp for implementation.

class CTestCom2PropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CTestCom2PropPage)
	DECLARE_OLECREATE_EX(CTestCom2PropPage)

// Constructor
public:
	CTestCom2PropPage();

// Dialog Data
	//{{AFX_DATA(CTestCom2PropPage)
	enum { IDD = IDD_PROPPAGE_TESTCOM2 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CTestCom2PropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCOM2PPG_H__CF991DE9_A970_4773_B77E_627ABE221B21__INCLUDED)
