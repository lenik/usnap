// myObjectsDoc.cpp : implementation of the CMyObjectsDoc class
//

#include "stdafx.h"
#include "myObjects.h"

#include "myObjectsDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyObjectsDoc

IMPLEMENT_DYNCREATE(CMyObjectsDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyObjectsDoc, CDocument)
	//{{AFX_MSG_MAP(CMyObjectsDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyObjectsDoc construction/destruction

CMyObjectsDoc::CMyObjectsDoc()
{
	// TODO: add one-time construction code here

}

CMyObjectsDoc::~CMyObjectsDoc()
{
}

BOOL CMyObjectsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyObjectsDoc serialization

void CMyObjectsDoc::Serialize(CArchive& ar)
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
// CMyObjectsDoc diagnostics

#ifdef _DEBUG
void CMyObjectsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyObjectsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyObjectsDoc commands
