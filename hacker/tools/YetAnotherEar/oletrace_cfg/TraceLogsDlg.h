#if !defined(AFX_TRACELOGSDLG_H__154B1BCF_BB79_4680_96BF_1AE5EF172F87__INCLUDED_)
#define AFX_TRACELOGSDLG_H__154B1BCF_BB79_4680_96BF_1AE5EF172F87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TraceLogsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTraceLogsDlg dialog

class CTraceLogsDlg : public CDialog
{
// Construction
public:
	CTraceLogsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTraceLogsDlg)
	enum { IDD = IDD_TRACE_LOGS };
	CTreeCtrl	m_treeLogs;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTraceLogsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTraceLogsDlg)
	afx_msg void OnClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRACELOGSDLG_H__154B1BCF_BB79_4680_96BF_1AE5EF172F87__INCLUDED_)
