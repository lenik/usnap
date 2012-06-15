#if !defined(AFX_ADVANCEDTIMERPPG_H__B81D2E96_3A5A_473F_87E4_FDE288858899__INCLUDED_)
#define AFX_ADVANCEDTIMERPPG_H__B81D2E96_3A5A_473F_87E4_FDE288858899__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// AdvancedTimerPpg.h : Declaration of the CAdvancedTimerPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CAdvancedTimerPropPage : See AdvancedTimerPpg.cpp.cpp for implementation.

class CAdvancedTimerPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CAdvancedTimerPropPage)
	DECLARE_OLECREATE_EX(CAdvancedTimerPropPage)

// Constructor
public:
	CAdvancedTimerPropPage();

// Dialog Data
	//{{AFX_DATA(CAdvancedTimerPropPage)
	enum { IDD = IDD_PROPPAGE_ADVANCEDTIMER };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CAdvancedTimerPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADVANCEDTIMERPPG_H__B81D2E96_3A5A_473F_87E4_FDE288858899__INCLUDED)
