#if !defined(AFX_THREADDIALOG_H__60D09495_6D18_4EEA_A1B7_AC6FB3EF7AEC__INCLUDED_)
#define AFX_THREADDIALOG_H__60D09495_6D18_4EEA_A1B7_AC6FB3EF7AEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ThreadDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CThreadDialog dialog

class CThreadDialog : public CDialog
{
// Construction
public:
	CThreadDialog(CWnd* pParent = NULL);   // standard constructor

	void UpdateAvailview();

// Dialog Data
	//{{AFX_DATA(CThreadDialog)
	enum { IDD = IDD_THREAD };
	CStatic	m_picStaticSrcThread;
	CStatic	m_picStaticSrcProcess;
	CStatic	m_picSrcThread;
	CStatic	m_picSrcProcess;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CThreadDialog)
	afx_msg void OnButtonApplyAll();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADDIALOG_H__60D09495_6D18_4EEA_A1B7_AC6FB3EF7AEC__INCLUDED_)
