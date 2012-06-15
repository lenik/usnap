// dv01Doc.cpp : implementation of the CDv01Doc class
//

#include "stdafx.h"
#include "dv01.h"

#include "dv01Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDv01Doc

IMPLEMENT_DYNCREATE(CDv01Doc, CDocument)

BEGIN_MESSAGE_MAP(CDv01Doc, CDocument)
	//{{AFX_MSG_MAP(CDv01Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDv01Doc construction/destruction

CDv01Doc::CDv01Doc()
{
	// TODO: add one-time construction code here
	m_MousePositions.SetSize(0, 100);
	m_MouseButtons.SetSize(0, 100);
	m_bNoUpdate = FALSE;

}

CDv01Doc::~CDv01Doc()
{
	ClearList();
}

UINT CDv01Doc::GetSize() {
	return m_MousePositions.GetSize();
}

CPoint *CDv01Doc::GetMPosition(UINT index) {
	return (CPoint *)m_MousePositions[index];
}

int CDv01Doc::GetMButton(UINT index) {
	return (int)m_MouseButtons[index];
}

void CDv01Doc::ClearList() {
	int i;
	CPoint *pPoint;
	int n_Size = m_MousePositions.GetSize();
	for (i = 0; i < n_Size; i++) {
		pPoint = (CPoint *)m_MousePositions[i];
		delete pPoint;
	}
	m_MousePositions.RemoveAll();
	m_MouseButtons.RemoveAll();
}

void CDv01Doc::AddList(CPoint point, UINT nButton) {
	if (m_bNoUpdate) {
		return;
	}
	CPoint *pNewPoint = new CPoint(point);
	m_MousePositions.Add((void *)pNewPoint);
	m_MouseButtons.Add(nButton);
	SetModifiedFlag();
}

void CDv01Doc::EnableUpdate() {
	m_bNoUpdate = FALSE;
}

BOOL CDv01Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	ClearList();
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDv01Doc serialization

void CDv01Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		Save(ar);
	}
	else
	{
		// TODO: add loading code here
		Restore(ar);
	}
}

void CDv01Doc::Save(CArchive &ar) {
	WORD nPositions;
	nPositions = GetSize();
	ar << nPositions;

	// Now save mouse movement in list
	WORD i, wTemp;
	CPoint *pPoint;
	for (i = 0; i < nPositions; i++) {
		ar << (WORD)GetMButton(i);
		pPoint = GetMPosition(i);
		ar << (WORD)pPoint->x;
		ar << (WORD)pPoint->y;
	}
}

void CDv01Doc::Restore(CArchive &ar) {
	ClearList();

	WORD nPositions;
	ar >> nPositions;

	WORD i, wButton, wX, wY;
	for (i = 0; i < nPositions; i++) {
		ar >> wButton;
		ar >> wX;
		ar >> wY;

		AddList(CPoint(wX, wY), wButton);
	}

	m_bNoUpdate = TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CDv01Doc diagnostics

#ifdef _DEBUG
void CDv01Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDv01Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDv01Doc commands
