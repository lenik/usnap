// XMLViewerDoc.cpp : implementation of the CXMLViewerDoc class
//

#include "stdafx.h"
#include "XMLViewer.h"

#include "XMLViewerDoc.h"

#include "xmlTool.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXMLViewerDoc

IMPLEMENT_DYNCREATE(CXMLViewerDoc, CDocument)

BEGIN_MESSAGE_MAP(CXMLViewerDoc, CDocument)
	//{{AFX_MSG_MAP(CXMLViewerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXMLViewerDoc construction/destruction

CXMLViewerDoc::CXMLViewerDoc()
{
	// TODO: add one-time construction code here
	this->m_view = L"<B>XML VIEWER!</B>";

}

CXMLViewerDoc::~CXMLViewerDoc()
{
}

BOOL CXMLViewerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CXMLViewerDoc serialization

void CXMLViewerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
		DWORD	length = ar.GetFile()->GetLength();
		BYTE	*lpBuf = new BYTE[length + 1];
		if (lpBuf != NULL) {
			ar.Read((LPVOID)lpBuf, length);
			lpBuf[length] = '\0';

			this->m_pXmlDoc.CreateInstance(
				MSXML::CLSID_DOMDocument,
				m_pXmlDoc);

			m_pXmlDoc->loadXML((_bstr_t)lpBuf);

			xmlTool xt(this->m_pXmlDoc);
			m_view = xt.makeXmlView();

			delete[] lpBuf;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CXMLViewerDoc diagnostics

#ifdef _DEBUG
void CXMLViewerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CXMLViewerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CXMLViewerDoc commands

BOOL CXMLViewerDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO: Add your specialized creation code here

	return TRUE;
}

BOOL CXMLViewerDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: Add your specialized code here and/or call the base class

	return CDocument::OnSaveDocument(lpszPathName);
}
