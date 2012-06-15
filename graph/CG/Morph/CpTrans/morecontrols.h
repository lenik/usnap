#if !defined(AFX_MoreControls_H__E9910CDC_5BB0_497B_ABCD_A0109EECDF34__INCLUDED_)
#define AFX_MoreControls_H__E9910CDC_5BB0_497B_ABCD_A0109EECDF34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MoreControls.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMoreControls dialog

class CMoreControls : public CDialog
{
// Construction
public:
	CMoreControls(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMoreControls)
	enum { IDD = IDR_MAINFRAME };
	int		m_sliderSpeed;
	double	m_speed;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoreControls)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMoreControls)
	afx_msg void OnChangeEditSpeed();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MoreControls_H__E9910CDC_5BB0_497B_ABCD_A0109EECDF34__INCLUDED_)
