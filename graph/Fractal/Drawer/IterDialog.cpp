// IterDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Drawer.h"
#include "IterDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIterDialog dialog


CIterDialog::CIterDialog(CDrawerDoc *pDrawerDoc, CWnd* pParent /*=NULL*/)
	: CDialog(CIterDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIterDialog)
	m_strIterStatus = _T("");
	m_nIterCount = 1;
	m_igInit = _T("");
	m_igSegment = _T("");
	m_igB = _T("");
	m_igA = _T("");
	m_bIterAngle = TRUE;
	//}}AFX_DATA_INIT
	pDoc = pDrawerDoc;
	Create(IDD_ITER);
}


void CIterDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIterDialog)
	DDX_Control(pDX, IDC_ITER_CHOICE, m_spinChoice);
	DDX_Text(pDX, IDC_ITER_STATUS, m_strIterStatus);
	DDX_Text(pDX, IDC_EDIT_ITER_COUNT, m_nIterCount);
	DDV_MinMaxUInt(pDX, m_nIterCount, 1, 100);
	DDX_Text(pDX, IDC_EDIT_INITGRAPH, m_igInit);
	DDX_Text(pDX, IDC_EDIT_IG_SEGMENT, m_igSegment);
	DDX_Text(pDX, IDC_EDIT_IG_B, m_igB);
	DDX_Text(pDX, IDC_EDIT_IG_A, m_igA);
	DDX_Check(pDX, IDC_CHECK_ITER_ANGLE, m_bIterAngle);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIterDialog, CDialog)
	//{{AFX_MSG_MAP(CIterDialog)
	ON_NOTIFY(UDN_DELTAPOS, IDC_ITER_CHOICE, OnDeltaposIterChoice)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIterDialog message handlers

void CIterDialog::Save(UINT i) {
	this->UpdateData(TRUE);
	if (pDoc->m_igCount - 1 < i) {
		pDoc->m_igCount = i + 1;
		pDoc->m_igA.SetSize(pDoc->m_igCount);
		pDoc->m_igB.SetSize(pDoc->m_igCount);
	}
	pDoc->m_igA[i] = m_igA;
	pDoc->m_igB[i] = m_igB;
}

void CIterDialog::Restore(UINT i) {
	m_igA = pDoc->m_igA[i];
	m_igB = pDoc->m_igB[i];
	this->UpdateData(FALSE);
}

void CIterDialog::Add() {
	pDoc->m_igCount++;
	int count = pDoc->m_igCount;
	pDoc->m_igA.SetSize(count);
	this->m_spinChoice.SetRange(0, count - 1);
}

void CIterDialog::Erase() {
	int count = pDoc->m_igCount;
	if (count > 0) {
		pDoc->m_igCount--;
		this->m_spinChoice.SetRange(0, count - 2);
	}
}

void CIterDialog::SwitchTo(UINT iFrom, UINT iTo) {
	Save(iFrom);
	Restore(iTo);
	if (iTo == pDoc->m_igCount - 1) {
		int lower, upper;
		m_spinChoice.GetRange(lower, upper);
		if (iTo == (UINT)upper) Add();
	}
}

void CIterDialog::OnDeltaposIterChoice(NMHDR* pNMHDR, LRESULT* pResult)
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	static UINT lastPos = -1, curPos = m_spinChoice.GetBase();
	if (lastPos >= 0) Save(lastPos);
	Restore(curPos);
	if (curPos == pDoc->m_igCount - 1) {
		int lower, upper;
		m_spinChoice.GetRange(lower, upper);
		if (curPos == (UINT)upper) Add();
	}
	*pResult = 0;
	lastPos = curPos;
}

void CIterDialog::OnButtonDelete()
{
	// TODO: Add your control notification handler code here
	Erase();
}
