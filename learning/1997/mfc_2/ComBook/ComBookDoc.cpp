// ComBookDoc.cpp : implementation of the CComBookDoc class
//

#include "stdafx.h"
#include "ComBook.h"

#include "ComBookDoc.h"

#include "ComBookDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComBookDoc

IMPLEMENT_DYNCREATE(CComBookDoc, CDocument)

BEGIN_MESSAGE_MAP(CComBookDoc, CDocument)
	//{{AFX_MSG_MAP(CComBookDoc)
	ON_COMMAND(ID_EDIT_ADD, OnEditAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComBookDoc construction/destruction

CComBookDoc::CComBookDoc()
{
	// TODO: add one-time construction code here

}

CComBookDoc::~CComBookDoc()
{
	DeleteAll();
}

BOOL CComBookDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	DeleteAll();
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CComBookDoc serialization

void CComBookDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << (WORD)GetCount();
		POSITION Index;
		CEntry *pEntry;
		for (pEntry = GetFirst(Index); pEntry; pEntry = GetNext(Index)) {
			pEntry->Serialize(ar);
		}
	}
	else
	{
		// TODO: add loading code here
		WORD wCount;
		DeleteAll();
		ar >> wCount;
		while (wCount--) {
			CEntry eEntry;
			if (eEntry.Serialize(ar)) {
				AfxMessageBox(
					"Error reading schedule file");
				DeleteAll();
				break;
			}
			Add(eEntry);
		}
	}
	SetModifiedFlag(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CComBookDoc diagnostics

#ifdef _DEBUG
void CComBookDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CComBookDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CComBookDoc commands

void CComBookDoc::OnEditAdd()
{
	// TODO: Add your command handler code here
	CComBookDialog dlgObject;
	if (dlgObject.DoModal() == IDOK) {
		Add(CEntry(
			dlgObject.m_nYear,
			dlgObject.m_nMonth,
			dlgObject.m_nDay,
			dlgObject.m_nHour,
			dlgObject.m_nMinute,
			dlgObject.m_bDisable,
			dlgObject.m_sText));
	}
}

POSITION CComBookDoc::Add(CEntry &eEntry) {
	CEntry *peNewEntry = new CEntry(eEntry);
	POSITION pNew = m_lEntry.AddTail((void *)peNewEntry);

	SetModifiedFlag();
	UpdateAllViews(0);
	return pNew;
}

void CComBookDoc::Modify(POSITION Index) {
	CEntry *pEntry = (CEntry *)m_lEntry.GetAt(Index);
	if (pEntry == (CEntry *)NULL) {
		return; // Oops-quit
	}
	// Create a dialog object with that entry and display it so that the operator can chagne it
	CComBookDialog dialog(pEntry);
	if (dialog.DoModal() == IDOK) {
		delete pEntry;
		pEntry = new CEntry(
			dialog.m_nYear,
			dialog.m_nMonth,
			dialog.m_nDay,
			dialog.m_nHour,
			dialog.m_nMinute,
			dialog.m_bDisable,
			dialog.m_sText);
		m_lEntry.SetAt(Index, pEntry);
		SetModifiedFlag();
		UpdateAllViews(0);
	}
}

void CComBookDoc::Delete(POSITION Index) {
	CEntry *pEntry;
	pEntry = (CEntry *)m_lEntry.GetAt(Index);
	delete pEntry;
	m_lEntry.RemoveAt(Index);
	SetModifiedFlag();
	UpdateAllViews(0);
}

void CComBookDoc::DeleteAll() {
	POSITION Index;
	while (GetCount() != 0) {
		Index = m_lEntry.GetHeadPosition();
		Delete(Index);
	}
}

CEntry *CComBookDoc::GetFirst(POSITION &Index) {
	// if there aren't any in the list
	if (m_lEntry.IsEmpty()) {
		//... just let him know
		Index = 0;
		return (CEntry *)NULL;
	}
	//  Otherwise, return the heap entry
	Index = m_lEntry.GetHeadPosition();
	return (CEntry *)m_lEntry.GetAt(Index);
}

CEntry *CComBookDoc::GetNext(POSITION &Index) {
	m_lEntry.GetNext(Index);

	if (Index == (POSITION)0) {
		return (CEntry *)NULL;
	}
	return (CEntry *)m_lEntry.GetAt(Index);
}

int CComBookDoc::GetCount() {
	return m_lEntry.GetCount();
}