// dhtml_client1Dlg.h : header file
//

#if !defined(AFX_DHTML_CLIENT1DLG_H__F08889FB_5201_4DD6_B434_24C1D6948EAB__INCLUDED_)
#define AFX_DHTML_CLIENT1DLG_H__F08889FB_5201_4DD6_B434_24C1D6948EAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDhtml_client1Dlg dialog

class CDhtml_client1Dlg : public CDialog
{
// Construction
public:
	CDhtml_client1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDhtml_client1Dlg)
	enum { IDD = IDD_DHTML_CLIENT1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDhtml_client1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDhtml_client1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DHTML_CLIENT1DLG_H__F08889FB_5201_4DD6_B434_24C1D6948EAB__INCLUDED_)
