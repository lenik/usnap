// syntestDoc.cpp : implementation of the CSyntestDoc class
//

#include "stdafx.h"
#include "syntest.h"

#include "syntestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSyntestDoc

IMPLEMENT_DYNCREATE(CSyntestDoc, CDocument)

BEGIN_MESSAGE_MAP(CSyntestDoc, CDocument)
	//{{AFX_MSG_MAP(CSyntestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSyntestDoc construction/destruction

CSyntestDoc::CSyntestDoc()
{
	// TODO: add one-time construction code here

}

CSyntestDoc::~CSyntestDoc()
{
}

BOOL CSyntestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSyntestDoc serialization

void CSyntestDoc::Serialize(CArchive& ar)
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
// CSyntestDoc diagnostics

#ifdef _DEBUG
void CSyntestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSyntestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSyntestDoc commands
