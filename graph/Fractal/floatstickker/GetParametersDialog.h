#if !defined(AFX_GETPARAMETERSDIALOG_H__4FB2807C_5C26_443B_9CB3_B7C910F368CF__INCLUDED_)
#define AFX_GETPARAMETERSDIALOG_H__4FB2807C_5C26_443B_9CB3_B7C910F368CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GetParametersDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGetParametersDialog dialog

class CGetParametersDialog : public CDialog
{
// Construction
public:
	CGetParametersDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGetParametersDialog)
	enum { IDD = IDD_DIALOG_GET_PARAMETERS };
	int		m_nums;
	double	m_power;
	double	m_speed;
	double	m_radius;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetParametersDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGetParametersDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETPARAMETERSDIALOG_H__4FB2807C_5C26_443B_9CB3_B7C910F368CF__INCLUDED_)
