#if !defined(AFX_MFC_COM2PPG_H__FC2CEF52_2FDF_416A_801D_646288A8377B__INCLUDED_)
#define AFX_MFC_COM2PPG_H__FC2CEF52_2FDF_416A_801D_646288A8377B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Mfc_com2Ppg.h : Declaration of the CMfc_com2PropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CMfc_com2PropPage : See Mfc_com2Ppg.cpp.cpp for implementation.

class CMfc_com2PropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMfc_com2PropPage)
	DECLARE_OLECREATE_EX(CMfc_com2PropPage)

// Constructor
public:
	CMfc_com2PropPage();

// Dialog Data
	//{{AFX_DATA(CMfc_com2PropPage)
	enum { IDD = IDD_PROPPAGE_MFC_COM2 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CMfc_com2PropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_COM2PPG_H__FC2CEF52_2FDF_416A_801D_646288A8377B__INCLUDED)
