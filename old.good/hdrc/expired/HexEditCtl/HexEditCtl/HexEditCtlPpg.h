#if !defined(AFX_HEXEDITCTLPPG_H__5F3063A5_761E_4066_AD3C_607247A610AD__INCLUDED_)
#define AFX_HEXEDITCTLPPG_H__5F3063A5_761E_4066_AD3C_607247A610AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// HexEditCtlPpg.h : Declaration of the CHexEditCtlPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CHexEditCtlPropPage : See HexEditCtlPpg.cpp.cpp for implementation.

class CHexEditCtlPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CHexEditCtlPropPage)
	DECLARE_OLECREATE_EX(CHexEditCtlPropPage)

// Constructor
public:
	CHexEditCtlPropPage();

// Dialog Data
	//{{AFX_DATA(CHexEditCtlPropPage)
	enum { IDD = IDD_PROPPAGE_HEXEDITCTL };
	CString	m_LeftMargin;
	CString	m_TopMargin;
	BOOL	m_Check;
	int		m_Height;
	int		m_Width;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CHexEditCtlPropPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	CHexEditCtlCtrl *	m_pObj;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HEXEDITCTLPPG_H__5F3063A5_761E_4066_AD3C_607247A610AD__INCLUDED)
