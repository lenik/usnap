// TextEditorDoc.cpp : implementation of the CTextEditorDoc class
//

#include "stdafx.h"
#include "TextEditor.h"

#include <FStream.h>

#include "TextEditorDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextEditorDoc

IMPLEMENT_DYNCREATE(CTextEditorDoc, CDocument)

BEGIN_MESSAGE_MAP(CTextEditorDoc, CDocument)
	//{{AFX_MSG_MAP(CTextEditorDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextEditorDoc construction/destruction

CTextEditorDoc::CTextEditorDoc()
{
	// TODO: add one-time construction code here
	m_saText.SetSize(0, 100);
}

CTextEditorDoc::~CTextEditorDoc()
{
}

BOOL CTextEditorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTextEditorDoc serialization

void CTextEditorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTextEditorDoc diagnostics

#ifdef _DEBUG
void CTextEditorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTextEditorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTextEditorDoc commands

BOOL CTextEditorDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO: Add your specialized creation code here
	ifstream iFile(lpszPathName, ios::in | ios::nocreate);
	if (iFile.fail()) { return FALSE; }
	DeleteAll();
	int nLine = 0; char cBuffer[2048];
	while (!iFile.eof()) {
		iFile.getline(cBuffer, sizeof cBuffer - 1);
		m_saText.SetAtGrow(nLine++, CString(cBuffer));
	}
	return TRUE;
}

BOOL CTextEditorDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: Add your specialized code here and/or call the base class
	ofstream oFile(lpszPathName, ios::out | ios::trunc);
	if (oFile.fail()) { return FALSE; }
	int nNoLines = m_saText.GetSize();
	int nLine;
	for (nLine = 0; nLine < nNoLines; nLine++) {
		oFile << String(nLine) << "\n";
	}

	// Clear the dirty flag
	SetModifiedFlag(FALSE);
	return CDocument::OnSaveDocument(lpszPathName);
}

void CTextEditorDoc::AddChar(int &nLine, int &nCharOff, char cChar) {
	int nLineHint = nLine;
	switch (cChar) {
	case '\n':
	case '\r':
		AddNL(nLine, nCharOff);
		break;
	case '\b':
		DeleteCharLeft(nLine, nCharOff);
		break;
	case '\x7':
		DeleteCharRight(nLine, nCharOff, nLineHint);
		break;
	default:
		AddSimpleChar(nLine, nCharOff, cChar);
	}
	SetModifiedFlag();
	// Use the hint to indicate which line changed
	// If more than one line affected...
	if (nLineHint != nLine) {
		nLineHint = min(nLineHint, nLine);
		nLineHint = ~nLineHint;
	}
	UpdateAllViews(0, nLineHint);
}

int CTextEditorDoc::GetLength() {
	return m_saText.GetSize();
}

void CTextEditorDoc::DeleteAll() {
	m_saText.RemoveAll();
}

void CTextEditorDoc::AddSimpleChar(int &nLine, int &nCharOff, char cChar) {
	// Is this the first character of a new line?
	if (nLine > m_saText.GetUpperBound()) {
		// Yes --- okay, do it
		m_saText.SetAtGrow(nLine, CString(cChar));
		nCharOff = 1;
	} else {
		// No --- Add to existing line; split the current
		// line at the insertion point and add your char
		CString sText = m_saText.GetAt(nLine);
		int nLength = sText.GetLength();
		CString sLeft = sText.Left(nCharOff);
		CString sRight = sText.Right(nLength - nCharOff);
		m_saText[nLine] = sLeft + CString(cChar) + sRight;
		nCharOff++;
	}
	return;
}

void CTextEditorDoc::DeleteCharLeft(int &nLine, int &nCharOff) {
	ASSERT(nLine <= m_saText.GetUpperBound());
	// Get the current string and length
	CString &sText = m_saText[nLine];
	int nLength = sText.GetLength();

	// If this is the leftmost charcter...
	if (nCharOff == 0) {
		if (nLine > 0) {
			nCharOff = m_saText[nLine - 1].GetLength();
			m_saText[nLine - 1] += sText;
			// Now move all remaining lines up
			m_saText.RemoveAt(nLine);
			nLine--;
		}
	} else {
		// Otherwise, just lose the char on the left
		CString sLeft = sText.Left(nCharOff - 1);
		CString sRight = sText.Right(nLength - nCharOff);
		m_saText[nLine] = sLeft + sRight;
		nCharOff--;
	}
}

void CTextEditorDoc::AddNL(int &nLine, int &nCharOff) {
	// Split the current string at the current pointer
	CString sText = m_saText[nLine];
	int nLength = sText.GetLength();
	CString sLeft = sText.Left(nCharOff);
	CString sRight = sText.Right(nLength - nCharOff);
	// Leave the lefthand part on this line
		m_saText.SetAt(nLine, sLeft);
	// Put the righthahdnd part on the next line
	// (This string may e null.)
	nLine++;
	m_saText.InsertAt(nLine, sRight);
	nCharOff = 0;
}

CString CTextEditorDoc::String(int nLine) {
	// if this request is off the end...
	if (nLine > m_saText.GetUpperBound()) {
		TRACE("Request off the end of document\n");
		return CString();
	}
	return m_saText[nLine];
}

void CTextEditorDoc::DeleteCharRight(int &nLine, int &nCharOff, int &nLineHint) {
	ASSERT(nLine <= m_saText.GetUpperBound());
	// Get the current string and length
	CString &sText = m_saText[nLine];
	int nLength = sText.GetLength();
	if (nCharOff == nLength) {
		if (nLine < m_saText.GetUpperBound()) {
			m_saText[nLine] += m_saText[nLine + 1];
			m_saText.RemoveAt(nLine + 1);
			nLineHint++;
		}
	} else {
		CString sLeft = sText.Left(nCharOff);
		CString sRight = sText.Right(nLength - nCharOff - 1);
		m_saText[nLine] = sLeft + sRight;
	}
}
