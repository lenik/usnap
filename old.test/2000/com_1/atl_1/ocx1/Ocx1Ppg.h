#if !defined(AFX_OCX1PPG_H__9BA5A92B_9BBE_4C6B_BFF1_A309CE83B9CC__INCLUDED_)
#define AFX_OCX1PPG_H__9BA5A92B_9BBE_4C6B_BFF1_A309CE83B9CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Ocx1Ppg.h : Declaration of the COcx1PropPage property page class.

////////////////////////////////////////////////////////////////////////////
// COcx1PropPage : See Ocx1Ppg.cpp.cpp for implementation.

class COcx1PropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(COcx1PropPage)
	DECLARE_OLECREATE_EX(COcx1PropPage)

// Constructor
public:
	COcx1PropPage();

// Dialog Data
	//{{AFX_DATA(COcx1PropPage)
	enum { IDD = IDD_PROPPAGE_OCX1 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(COcx1PropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCX1PPG_H__9BA5A92B_9BBE_4C6B_BFF1_A309CE83B9CC__INCLUDED)
