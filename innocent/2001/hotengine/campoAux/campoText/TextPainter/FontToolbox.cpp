// FontToolbox.cpp : implementation file
//

#include "stdafx.h"
#include "TextPainter.h"
#include "FontToolbox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFontToolbox dialog


int CALLBACK EnumFontFamProc(
										   ENUMLOGFONT *lpelf,
										   NEWTEXTMETRIC *lpntm,
										   int FontType,
										   LPARAM lParam)
{
	CFontToolbox *lpFont = (CFontToolbox *)lParam;

	lpFont->m_listFontName.AddString((LPCTSTR)lpelf->elfFullName);

	return TRUE;
}

CFontToolbox::CFontToolbox(CWnd* pParent /*=NULL*/)
	: CDialog(CFontToolbox::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFontToolbox)
	m_bFontBold = FALSE;
	m_bFontItalic = FALSE;
	m_bFontUnderline = FALSE;
	m_alignH = -1;
	m_alignV = -1;
	//}}AFX_DATA_INIT
	lpEnumFontFamProc = (FONTENUMPROC)EnumFontFamProc;
//	CDialog
}

void CFontToolbox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFontToolbox)
	DDX_Control(pDX, IDC_COMBO_FONTSIZE, m_listFontSize);
	DDX_Control(pDX, IDC_COMBO_FONTNAME, m_listFontName);
	DDX_Check(pDX, IDC_CHECK_FONTBOLD, m_bFontBold);
	DDX_Check(pDX, IDC_CHECK_FONTITALIC, m_bFontItalic);
	DDX_Check(pDX, IDC_CHECK_FONTUNDERLINE, m_bFontUnderline);
	DDX_Radio(pDX, IDC_RADIO_LEFT, m_alignH);
	DDX_Radio(pDX, IDC_RADIO_TOP, m_alignV);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFontToolbox, CDialog)
	//{{AFX_MSG_MAP(CFontToolbox)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontToolbox message handlers

BOOL CFontToolbox::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here

	// enumarates fonts
	EnumFontFamilies(
		GetDC()->m_hDC,
		NULL,
		lpEnumFontFamProc,
		(LPARAM)this);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
