#if !defined(AFX_MFC02ABOUT_H__3558D8E0_C078_11D3_8D69_90A7388C434C__INCLUDED_)
#define AFX_MFC02ABOUT_H__3558D8E0_C078_11D3_8D69_90A7388C434C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Mfc02About.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMfc02About dialog

class CMfc02About : public CDialog
{
// Construction
public:
	CMfc02About(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	///{{AFX_DATA(CMfc02About)
	enum { IDD = IDD_DIALOG_ABOUT };
	CProgressCtrl	m_p1;
	CString	m_strT;
	///}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	///{{AFX_VIRTUAL(CMfc02About)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	///}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMfc02About)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC02ABOUT_H__3558D8E0_C078_11D3_8D69_90A7388C434C__INCLUDED_)
