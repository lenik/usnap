// GaussHatDoc.cpp : implementation of the CGaussHatDoc class
//

#include "stdafx.h"
#include "GaussHat.h"

#include "GaussHatDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGaussHatDoc

IMPLEMENT_DYNCREATE(CGaussHatDoc, CDocument)

BEGIN_MESSAGE_MAP(CGaussHatDoc, CDocument)
	//{{AFX_MSG_MAP(CGaussHatDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGaussHatDoc construction/destruction

CGaussHatDoc::CGaussHatDoc()
{
	// TODO: add one-time construction code here

}

CGaussHatDoc::~CGaussHatDoc()
{
}

BOOL CGaussHatDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGaussHatDoc serialization

void CGaussHatDoc::Serialize(CArchive& ar)
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
// CGaussHatDoc diagnostics

#ifdef _DEBUG
void CGaussHatDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGaussHatDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGaussHatDoc commands
