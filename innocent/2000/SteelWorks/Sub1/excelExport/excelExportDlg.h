// excelExportDlg.h : header file
//

#if !defined(AFX_EXCELEXPORTDLG_H__410E6008_8E38_451F_A3E5_D8F10CC4D521__INCLUDED_)
#define AFX_EXCELEXPORTDLG_H__410E6008_8E38_451F_A3E5_D8F10CC4D521__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CExcelExportDlg dialog

class CExcelExportDlg : public CDialog
{
// Construction
public:
	CExcelExportDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CExcelExportDlg)
	enum { IDD = IDD_EXCELEXPORT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExcelExportDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CExcelExportDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXCELEXPORTDLG_H__410E6008_8E38_451F_A3E5_D8F10CC4D521__INCLUDED_)
