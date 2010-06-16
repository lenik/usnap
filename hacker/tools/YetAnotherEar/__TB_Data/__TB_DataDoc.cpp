// __TB_DataDoc.cpp : implementation of the C__TB_DataDoc class
//

#include "stdafx.h"
#include "__TB_Data.h"

#include "__TB_DataDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// C__TB_DataDoc

IMPLEMENT_DYNCREATE(C__TB_DataDoc, CDocument)

BEGIN_MESSAGE_MAP(C__TB_DataDoc, CDocument)
	//{{AFX_MSG_MAP(C__TB_DataDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(C__TB_DataDoc, CDocument)
	//{{AFX_DISPATCH_MAP(C__TB_DataDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_I__TB_Data to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the
//  dispinterface in the .ODL file.

// {C023CBD8-6F5C-4C93-8500-5C1125BF4A12}
static const IID IID_I__TB_Data =
{ 0xc023cbd8, 0x6f5c, 0x4c93, { 0x85, 0x0, 0x5c, 0x11, 0x25, 0xbf, 0x4a, 0x12 } };

BEGIN_INTERFACE_MAP(C__TB_DataDoc, CDocument)
	INTERFACE_PART(C__TB_DataDoc, IID_I__TB_Data, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// C__TB_DataDoc construction/destruction

C__TB_DataDoc::C__TB_DataDoc()
{
	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();
}

C__TB_DataDoc::~C__TB_DataDoc()
{
	AfxOleUnlockApp();
}

BOOL C__TB_DataDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// C__TB_DataDoc serialization

void C__TB_DataDoc::Serialize(CArchive& ar)
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
// C__TB_DataDoc diagnostics

#ifdef _DEBUG
void C__TB_DataDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void C__TB_DataDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// C__TB_DataDoc commands
