// wmfviewDoc.cpp : implementation of the CWmfviewDoc class
//

#include "stdafx.h"
#include "wmfview.h"

#include "wmfviewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWmfviewDoc

IMPLEMENT_DYNCREATE(CWmfviewDoc, CDocument)

BEGIN_MESSAGE_MAP(CWmfviewDoc, CDocument)
	//{{AFX_MSG_MAP(CWmfviewDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWmfviewDoc construction/destruction

CWmfviewDoc::CWmfviewDoc()
{
}

CWmfviewDoc::~CWmfviewDoc()
{
}

BOOL CWmfviewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return FALSE;
}



/////////////////////////////////////////////////////////////////////////////
// CWmfviewDoc serialization

void CWmfviewDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWmfviewDoc diagnostics

#ifdef _DEBUG
void CWmfviewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWmfviewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWmfviewDoc commands

BOOL CWmfviewDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO: Add your specialized creation code here
	return m_file.Open(lpszPathName, CFile::modeRead | CFile::typeBinary | CFile::shareDenyNone);
}

void CWmfviewDoc::OnCloseDocument()
{
	// TODO: Add your specialized code here and/or call the base class
	if (m_file.m_hFile != CFile::hFileNull) m_file.Close();
	CDocument::OnCloseDocument();
}
