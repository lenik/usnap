// ComBookDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ComBook.h"
#include "ComBookDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComBookDialog dialog

CComBookDialog::CComBookDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CComBookDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CComBookDialog)
	m_nYear = 0;
	m_nHour = 0;
	m_nMinute = 0;
	m_nDay = 0;
	m_sText = _T("");
	m_nAMPM = -1;
	m_bDisable = FALSE;
	m_nMonth = -1;
	//}}AFX_DATA_INIT
	time_t ttCurrent;
	time(&ttCurrent);
	CTime tCurrent(ttCurrent);
	m_nMonth = tCurrent.GetMonth() - 1;
	m_nDay = tCurrent.GetDay();
	m_nYear = tCurrent.GetYear();
	m_nHour = tCurrent.GetHour();
	m_nMinute = tCurrent.GetMinute();
}

CComBookDialog::CComBookDialog(CEntry *pEntry, CWnd *pParent)
	: CDialog(CComBookDialog::IDD, pParent) {
	CTime cTime = pEntry->GetTime();
	m_nYear = cTime.GetYear();
	m_nMonth = cTime.GetMonth() - 1;
	m_nDay = cTime.GetDay();
	m_nHour = cTime.GetHour();
	m_nMinute = cTime.GetMinute();
	m_bDisable = pEntry->GetDisabled();
	m_sText = pEntry->GetText();
}

void AFXAPI DDV_Time(CDataExchange *pDX, UINT nMonth, UINT nDay);

void CComBookDialog::DoDataExchange(CDataExchange* pDX)
{
	if (!pDX->m_bSaveAndValidate) {
		m_nAMPM = m_nHour < 12 ? 0 : 1;
		m_nHour %= 12;
		if (m_nHour == 0) { m_nHour = 12; }
	}

	if (!pDX->m_bSaveAndValidate) {
		CScrollBar *psbControl;
		psbControl = (CScrollBar *)GetDlgItem(IDC_SCROLLBAR_DAY);
		ASSERT_VALID(psbControl);
		psbControl->SetScrollRange(1, 31, FALSE);
		psbControl->SetScrollPos(m_nDay);
		psbControl = (CScrollBar *)GetDlgItem(IDC_SCROLLBAR_YEAR);
		ASSERT_VALID(psbControl);
		psbControl->SetScrollRange(1990, 2020, FALSE);
		psbControl->SetScrollPos(m_nYear);
		psbControl = (CScrollBar *)GetDlgItem(IDC_SCROLLBAR_HOUR);
		ASSERT_VALID(psbControl);
		psbControl->SetScrollRange(1, 12, FALSE);
		psbControl->SetScrollPos(m_nHour);
		psbControl = (CScrollBar *)GetDlgItem(IDC_SCROLLBAR_MINUTE);
		psbControl->SetScrollRange(0, 59, FALSE);
		psbControl->SetScrollPos(m_nMinute);
	}

	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComBookDialog)
	DDX_Text(pDX, IDC_EDIT_YEAR, m_nYear);
	DDV_MinMaxUInt(pDX, m_nYear, 1990, 2020);
	DDX_Text(pDX, IDC_EDIT_HOUR, m_nHour);
	DDV_MinMaxUInt(pDX, m_nHour, 1, 12);
	DDX_Text(pDX, IDC_EDIT_MINUTE, m_nMinute);
	DDV_MinMaxUInt(pDX, m_nMinute, 0, 59);
	DDX_Text(pDX, IDC_EDIT_DAY, m_nDay);
	DDV_MinMaxUInt(pDX, m_nDay, 1, 31);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_sText);
	DDX_Radio(pDX, IDC_RADIO1, m_nAMPM);
	DDX_Check(pDX, IDC_CHECK_DISABLE, m_bDisable);
	DDX_CBIndex(pDX, IDC_COMBO_MONTH, m_nMonth);
	//}}AFX_DATA_MAP

	DDX_Text(pDX, IDC_EDIT_DAY, m_nDay);
	DDV_Time(pDX, m_nMonth, m_nDay);

	if (pDX->m_bSaveAndValidate) {
		m_nHour += m_nAMPM == 1 ? 12 : 0;
	}
}

void AFXAPI DDV_Time(CDataExchange *pDX, UINT nMonth, UINT nDay) {
	// Doesn't work for leap year -
	// the fix is left as an assignment to student
	static UINT nDaysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (nMonth >= 12 || nDay > nDaysInMonth[nMonth]) {
		AfxMessageBox("Illegal day / month combination", MB_ICONEXCLAMATION | MB_OK);
		pDX->Fail();
	}
}

BEGIN_MESSAGE_MAP(CComBookDialog, CDialog)
	//{{AFX_MSG_MAP(CComBookDialog)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CComBookDialog message handlers


static UINT ScrollBarValue(
						   CScrollBar *pScrollBar,
						   UINT nSBCode,
						   UINT nSBPos) {
	int nPos = pScrollBar->GetScrollPos();
	int nMinPos, nMaxPos;
	pScrollBar->GetScrollRange(&nMinPos, &nMaxPos);
	switch (nSBCode) {
	case SB_LEFT: nPos = nMinPos; break;
	case SB_RIGHT: nPos = nMaxPos; break;
	case SB_LINELEFT: nPos = max(nPos - 1, nMinPos); break;
	case SB_LINERIGHT: nPos = min(nPos + 1, nMaxPos); break;
	case SB_PAGELEFT: nPos = max(nPos - 10, nMinPos); break;
	case SB_PAGERIGHT : nPos = min(nPos + 10, nMaxPos); break;
	case SB_THUMBPOSITION:
	case SB_THUMBTRACK:
		nSBPos = min((int)nSBPos, nMaxPos);
		nSBPos = max((int)nSBPos, nMinPos);
		nPos = nSBPos;
		break;
	case SB_ENDSCROLL: break;
	default:
		TRACE("Received an nSBCode we didn't understand\n");
	}
	pScrollBar->SetScrollPos(nPos);
	return nPos;
}

void CComBookDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	nPos = ScrollBarValue(pScrollBar, nSBCode, nPos);
	int nSourceID = pScrollBar->GetDlgCtrlID();
	switch(nSourceID) {
	case IDC_SCROLLBAR_DAY:
		SetDlgItemInt(IDC_EDIT_DAY, nPos);
		break;
	case IDC_SCROLLBAR_YEAR:
		SetDlgItemInt(IDC_EDIT_YEAR, nPos);
		break;
	case IDC_SCROLLBAR_HOUR:
		SetDlgItemInt(IDC_EDIT_HOUR, nPos);
		break;
	case IDC_SCROLLBAR_MINUTE:
		SetDlgItemInt(IDC_EDIT_MINUTE, nPos);
		break;
	default:
		TRACE("Unrecognized dialog control id received\n");
	}

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
