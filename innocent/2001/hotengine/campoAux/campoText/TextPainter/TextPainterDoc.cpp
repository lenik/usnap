// TextPainterDoc.cpp : implementation of the CTextPainterDoc class
//

#include "stdafx.h"
#include "TextPainter.h"

#include "TextPainterDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextPainterDoc

IMPLEMENT_DYNCREATE(CTextPainterDoc, CDocument)

BEGIN_MESSAGE_MAP(CTextPainterDoc, CDocument)
	//{{AFX_MSG_MAP(CTextPainterDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextPainterDoc construction/destruction

CTextPainterDoc::CTextPainterDoc()
{
}

CTextPainterDoc::~CTextPainterDoc()
{
}

BOOL CTextPainterDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	ctElement *ele		= new ctElement;
	ele->color.color	= 0x00123456;
	ele->position.x		= 50;
	ele->position.y		= 0;
	ele->align.h		= ctAlign::center;

	ele->text.Add("Hello, world!");
	ele->text.Add("What ever youdo!");
	ele->text.Add("Oh, !!");
	ele->text.Add("|");
	text.textList.AddHead(ele);
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CTextPainterDoc serialization

void CTextPainterDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTextPainterDoc diagnostics

#ifdef _DEBUG
void CTextPainterDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTextPainterDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTextPainterDoc commands
