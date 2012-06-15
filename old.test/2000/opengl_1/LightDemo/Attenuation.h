#if !defined(AFX_ATTENUATION_H__4BA31B54_C07A_11D3_8AD1_484C0001E209__INCLUDED_)
#define AFX_ATTENUATION_H__4BA31B54_C07A_11D3_8AD1_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Attenuation.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Attenuation dialog

class Attenuation : public CDialog
{
// Construction
public:
	Attenuation(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Attenuation)
	enum { IDD = IDD_DIALOG_ATTENUATION };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Attenuation)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Attenuation)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTENUATION_H__4BA31B54_C07A_11D3_8AD1_484C0001E209__INCLUDED_)
