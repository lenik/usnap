// solarsysDoc.cpp : implementation of the CSolarsysDoc class
//

#include "stdafx.h"
#include "solarsys.h"

#include "solarsysDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSolarsysDoc

IMPLEMENT_DYNCREATE(CSolarsysDoc, CDocument)

BEGIN_MESSAGE_MAP(CSolarsysDoc, CDocument)
	//{{AFX_MSG_MAP(CSolarsysDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSolarsysDoc construction/destruction

CSolarsysDoc::CSolarsysDoc()
{
	// TODO: add one-time construction code here

}

CSolarsysDoc::~CSolarsysDoc()
{
}

BOOL CSolarsysDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSolarsysDoc serialization

void CSolarsysDoc::Serialize(CArchive& ar)
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
// CSolarsysDoc diagnostics

#ifdef _DEBUG
void CSolarsysDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSolarsysDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSolarsysDoc commands
