#if !defined(AFX_MAINPROCESSDLG_H__0E618654_C052_11D3_8DBB_FE025B14AD4C__INCLUDED_)
#define AFX_MAINPROCESSDLG_H__0E618654_C052_11D3_8DBB_FE025B14AD4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainProcessDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMainProcessDlg dialog

#define MUSIC_FILE_MAXSIZE	65536
#define BLOCKSIZE			16384

#define MUSIC_FILE_HEADER	"本文件由BasCode->简谱转换器产生\r\n"
#define MUSIC_FILE_FOOTER	"谢谢使用本软件! 谢谢!\r\n桃壳软件  版权保留\r\n"
#define MUSIC_FILE_MARKER	"\x1A ALL RIGHTS RESERVED.\r\n"
#define SECSEPARATOR		"******\r\n"

int GetNum(LPSTR, int Default = 0);

int TakeLines(int);
inline float TakeBeat(int);
inline int Takel(float);

class CMainProcessDlg : public CDialog
{
// Construction
public:
	CMainProcessDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMainProcessDlg)
	enum { IDD = IDD_MAINPROCESS };
	CString	m_DestName;
	CString	m_SourceName;
	CString	m_TransReport;
	BOOL	m_chkSourceClip;
	BOOL	m_chkDestClip;
	short	m_nBeats;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainProcessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL Translate();
	// Generated message map functions
	//{{AFX_MSG(CMainProcessDlg)
	afx_msg void OnButtonSource();
	afx_msg void OnButtonDest();
	afx_msg void OnBeginTran();
	afx_msg void OnCheckSource();
	afx_msg void OnCheckDest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINPROCESSDLG_H__0E618654_C052_11D3_8DBB_FE025B14AD4C__INCLUDED_)
