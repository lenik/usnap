// EditorAppDoc.cpp : implementation of the CEditorAppDoc class
//

#include "stdafx.h"
#include "EditorApp.h"

#include "EditorAppDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditorAppDoc

IMPLEMENT_DYNCREATE(CEditorAppDoc, CDocument)

BEGIN_MESSAGE_MAP(CEditorAppDoc, CDocument)
	//{{AFX_MSG_MAP(CEditorAppDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CEditorAppDoc, CDocument)
	//{{AFX_DISPATCH_MAP(CEditorAppDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IEditorApp to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the
//  dispinterface in the .ODL file.

// {4DE58EFB-7E31-4EC0-BAD3-E2CBFFD96659}
static const IID IID_IEditorApp =
{ 0x4de58efb, 0x7e31, 0x4ec0, { 0xba, 0xd3, 0xe2, 0xcb, 0xff, 0xd9, 0x66, 0x59 } };

BEGIN_INTERFACE_MAP(CEditorAppDoc, CDocument)
	INTERFACE_PART(CEditorAppDoc, IID_IEditorApp, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditorAppDoc construction/destruction

CEditorAppDoc::CEditorAppDoc()
{
	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();
}

CEditorAppDoc::~CEditorAppDoc()
{
	AfxOleUnlockApp();
}

BOOL CEditorAppDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEditorAppDoc serialization

void CEditorAppDoc::Serialize(CArchive& ar)
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
// CEditorAppDoc diagnostics

#ifdef _DEBUG
void CEditorAppDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEditorAppDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEditorAppDoc commands
