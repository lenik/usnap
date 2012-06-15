#if !defined(AFX_MAINDIALOG_H__7A7EA79B_9B9B_4780_8AD4_F236018C2C42__INCLUDED_)
#define AFX_MAINDIALOG_H__7A7EA79B_9B9B_4780_8AD4_F236018C2C42__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMainDialog dialog

class CMainDialog : public CDialog
{
// Construction
public:
	CMainDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMainDialog)
	enum { IDD = IDD_DIALOG_MAIN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMainDialog)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINDIALOG_H__7A7EA79B_9B9B_4780_8AD4_F236018C2C42__INCLUDED_)
