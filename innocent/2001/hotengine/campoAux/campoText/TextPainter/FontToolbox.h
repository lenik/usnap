#if !defined(AFX_FONTTOOLBOX_H__BBD50862_C025_11D3_82D0_CD5041702DCD__INCLUDED_)
#define AFX_FONTTOOLBOX_H__BBD50862_C025_11D3_82D0_CD5041702DCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FontToolbox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFontToolbox dialog

int CALLBACK EnumFontFamProc(
	ENUMLOGFONT FAR *lpelf,		// pointer to logical-font data
	NEWTEXTMETRIC FAR *lpntm,	// pointer to physical-font data
	int FontType,				// type of font
	LPARAM lParam				// pointer to application-defined data
);

class CFontToolbox : public CDialog
{
// Construction
public:
	CFontToolbox(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFontToolbox)
	enum { IDD = IDD_FONT };
	CComboBox	m_listFontSize;
	CComboBox	m_listFontName;
	BOOL	m_bFontBold;
	BOOL	m_bFontItalic;
	BOOL	m_bFontUnderline;
	int		m_alignH;
	int		m_alignV;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontToolbox)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	FONTENUMPROC lpEnumFontFamProc;

	// Generated message map functions
	//{{AFX_MSG(CFontToolbox)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTTOOLBOX_H__BBD50862_C025_11D3_82D0_CD5041702DCD__INCLUDED_)
