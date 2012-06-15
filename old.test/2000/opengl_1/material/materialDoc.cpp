// materialDoc.cpp : implementation of the CMaterialDoc class
//

#include "stdafx.h"
#include "material.h"

#include "materialDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMaterialDoc

IMPLEMENT_DYNCREATE(CMaterialDoc, CDocument)

BEGIN_MESSAGE_MAP(CMaterialDoc, CDocument)
	//{{AFX_MSG_MAP(CMaterialDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMaterialDoc construction/destruction

CMaterialDoc::CMaterialDoc()
{
	// TODO: add one-time construction code here

}

CMaterialDoc::~CMaterialDoc()
{
}

BOOL CMaterialDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMaterialDoc serialization

void CMaterialDoc::Serialize(CArchive& ar)
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
// CMaterialDoc diagnostics

#ifdef _DEBUG
void CMaterialDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMaterialDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMaterialDoc commands
