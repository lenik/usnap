// myFontDoc.cpp : implementation of the CMyFontDoc class
//

#include "stdafx.h"
#include "myFont.h"

#include "myFontDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyFontDoc

IMPLEMENT_DYNCREATE(CMyFontDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyFontDoc, CDocument)
	//{{AFX_MSG_MAP(CMyFontDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyFontDoc construction/destruction

CMyFontDoc::CMyFontDoc()
{
	// TODO: add one-time construction code here

}

CMyFontDoc::~CMyFontDoc()
{
}

BOOL CMyFontDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyFontDoc serialization

void CMyFontDoc::Serialize(CArchive& ar)
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
// CMyFontDoc diagnostics

#ifdef _DEBUG
void CMyFontDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyFontDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyFontDoc commands
