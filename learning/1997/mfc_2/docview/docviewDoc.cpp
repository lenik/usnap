// docviewDoc.cpp : implementation of the CDocviewDoc class
//

#include "stdafx.h"
#include "docview.h"

#include "docviewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDocviewDoc

IMPLEMENT_DYNCREATE(CDocviewDoc, CDocument)

BEGIN_MESSAGE_MAP(CDocviewDoc, CDocument)
	//{{AFX_MSG_MAP(CDocviewDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDocviewDoc construction/destruction

CDocviewDoc::CDocviewDoc()
{
	// TODO: add one-time construction code here

}

CDocviewDoc::~CDocviewDoc()
{
}

BOOL CDocviewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDocviewDoc serialization

void CDocviewDoc::Serialize(CArchive& ar)
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
// CDocviewDoc diagnostics

#ifdef _DEBUG
void CDocviewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDocviewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDocviewDoc commands
