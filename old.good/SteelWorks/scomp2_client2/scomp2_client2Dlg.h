// scomp2_client2Dlg.h : header file
//

#if !defined(AFX_SCOMP2_CLIENT2DLG_H__74E1CA37_968D_4FB0_9786_6BD091C6D678__INCLUDED_)
#define AFX_SCOMP2_CLIENT2DLG_H__74E1CA37_968D_4FB0_9786_6BD091C6D678__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <SComp2.h>

#include "streamworkhelper01.h"

struct res_easy_type {
	int	op;		// 操作标志, 0成功, 否则失败
	int	match;
	int	unmatch;
	int	extra;
	int	lost;
};

/////////////////////////////////////////////////////////////////////////////
// CScomp2_client2Dlg dialog

class CScomp2_client2Dlg : public CDialog
{
// Construction
public:
	CScomp2_client2Dlg(CWnd* pParent = NULL);	// standard constructor

public:
	res_easy_type	compare(CString f1, CString f2, BOOL detail, BOOL bgetconfigs = TRUE);
	void	showres(res_easy_type res);
	void	showdetail(stream_units_work& s, stream_units_work& os);

	struct config_type {
		enum algor_enum {
			s_ansi		= 0,
			s_unicode,
			s_ole,
			s_mbcs,
			s_longs,
			s_bits,
			s_manual
		} algor;
		enum decor_enum {
			d_whole		= 0,
			d_mebig,
			d_mesmall,
			d_least
		} decor;
		int		width;
		int		depth;
		float		fuzzysame;
		stream_units_work::stream_units_work_compare::compare_mode_enum
				precise;
		int		com_error;

		szlists		sames;		// 认为等同字符列表
		szlist		skips;		// 忽略集

		CString		filename;
		CString		plugin;
	} configs;
	void	getconfigs();

	::_G1	m_excel_generator;

public:
// Dialog Data
	//{{AFX_DATA(CScomp2_client2Dlg)
	enum { IDD = IDD_SCOMP2_CLIENT2_DIALOG };
	CListBox	m_lstFComp;
	CString	m_fTemp;
	CString	m_strResult;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScomp2_client2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CScomp2_client2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonExit();
	afx_msg void OnButtonInsert();
	afx_msg void OnButtonRemove();
	afx_msg void OnButtonBrowseTemp();
	afx_msg void OnButtonAbout();
	afx_msg void OnDblclkListFilecomp();
	afx_msg void OnButtonComp();
	afx_msg void OnButtonPrettyResult();
	afx_msg void OnButtonSetting();
	afx_msg void OnButtonBatch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCOMP2_CLIENT2DLG_H__74E1CA37_968D_4FB0_9786_6BD091C6D678__INCLUDED_)
