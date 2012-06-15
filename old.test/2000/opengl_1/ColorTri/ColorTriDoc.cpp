// ColorTriDoc.cpp : implementation of the CColorTriDoc class
//

#include "stdafx.h"
#include "ColorTri.h"

#include "ColorTriDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorTriDoc

IMPLEMENT_DYNCREATE(CColorTriDoc, CDocument)

BEGIN_MESSAGE_MAP(CColorTriDoc, CDocument)
	//{{AFX_MSG_MAP(CColorTriDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorTriDoc construction/destruction

CColorTriDoc::CColorTriDoc()
{
	// TODO: add one-time construction code here

}

CColorTriDoc::~CColorTriDoc()
{
}

BOOL CColorTriDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CColorTriDoc serialization

void CColorTriDoc::Serialize(CArchive& ar)
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
// CColorTriDoc diagnostics

#ifdef _DEBUG
void CColorTriDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CColorTriDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CColorTriDoc commands
