// dr_guiDoc.cpp : implementation of the CDr_guiDoc class
//

#include "stdafx.h"
#include "dr_gui.h"

#include "dr_guiDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDr_guiDoc

IMPLEMENT_DYNCREATE(CDr_guiDoc, CDocument)

BEGIN_MESSAGE_MAP(CDr_guiDoc, CDocument)
	//{{AFX_MSG_MAP(CDr_guiDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDr_guiDoc construction/destruction

CDr_guiDoc::CDr_guiDoc()
{
	// TODO: add one-time construction code here

}

CDr_guiDoc::~CDr_guiDoc()
{
}

BOOL CDr_guiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDr_guiDoc serialization

void CDr_guiDoc::Serialize(CArchive& ar)
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
// CDr_guiDoc diagnostics

#ifdef _DEBUG
void CDr_guiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr_guiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDr_guiDoc commands
