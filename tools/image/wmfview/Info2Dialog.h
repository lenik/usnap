#if !defined(AFX_INFO2DIALOG_H__BE3E6877_672A_4031_902E_B5AF0C6C0BED__INCLUDED_)
#define AFX_INFO2DIALOG_H__BE3E6877_672A_4031_902E_B5AF0C6C0BED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Info2Dialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInfo2Dialog dialog

class CInfo2Dialog : public CDialog
{
// Construction
public:
	CInfo2Dialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInfo2Dialog)
	enum { IDD = IDD_DIALOG_INFO2 };
	CString	m_strHDRSIZE;
	CString	m_strMAXREC;
	CString	m_strNOOBJ;
	CString	m_strNOPARAM;
	CString	m_strSIZE;
	CString	m_strVERSION;
	CString	m_strTYPE;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInfo2Dialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInfo2Dialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFO2DIALOG_H__BE3E6877_672A_4031_902E_B5AF0C6C0BED__INCLUDED_)
