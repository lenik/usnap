
#include "StdAfx.h"

#include "xmltool.h"

xmlTool::xmlTool(MSXML::IXMLDOMDocumentPtr pxml) {
	this->m_pXml = pxml;
}

xmlTool::~xmlTool() {
	this->m_pXml = NULL;
}

BSTR xmlTool::makeXmlView() {
	CString	r;
	int	i;

	r	= _T("<HTML><HEAD><TITLE>Xml结构视图</TITLE>"
			"<META GENERATOR=\"XmlTool01\">"
			"</HEAD>"
			"<BODY><FONT name=\"宋体\">"
			"<P><H2>XML结构视图</H2></P>"
			);
	for (i = 0; i < this->m_pXml->childNodes->length - 1; i++) {
		r	+= "<DL>";
		r	+= this->makeXmlView1(this->m_pXml->childNodes->item[i]);
		r	+= "</DL>";
	}

	r	+= _T("</FONT></BODY></HTML>");

	this->m_strXmlView	= r.AllocSysString();
	return this->m_strXmlView;
}

BSTR	xmlTool::makeXmlView1(MSXML::IXMLDOMNodePtr node) {
	int	i;
	CString	r;
	MSXML::DOMNodeType t;

	t = node->nodeType;

	switch (t) {
	case MSXML::NODE_INVALID:
		r	= makeInvalid(L"!Invalid!");
		break;
	case MSXML::NODE_ELEMENT:
		r	= CHAR_LT;
		r	+= makeIdentifier(node->baseName);
		for (i = 0; i < node->attributes->length - 1; i++) {
			r	+= " ";
			r	+= makeXmlView1(node->attributes->item[i]);
		}
		r	+= CHAR_GT;
		for (i = 0; i < node->childNodes->length - 1; i++) {
			r	+= "<DL>";
			r	+= makeXmlView1(node->childNodes->item[0]);
			r	+= "</DL>";
		}
		r	+= CHAR_LT;
		r	+= makeSymbol(L"/");
		r	+= makeIdentifier(node->baseName);
		r	+= CHAR_GT;
		break;
	case MSXML::NODE_ATTRIBUTE:
		//r	= makeHashView(node->nodeName, node->get_nodeValue(&val));
		break;
	case MSXML::NODE_TEXT:
		r	= makeLiteral(node->text);
		break;
	case MSXML::NODE_PROCESSING_INSTRUCTION:
		r	= "&lt;?xml ";
		r	+= node->text;
		r	+= "?&gt;";
		r	= makeSymbol(r.AllocSysString());
		break;
	}
	return r.AllocSysString();
}

BSTR	xmlTool::makeHashView(BSTR hName, BSTR hVal) {
	CString r;
	r	= makeIdentifier(hName);
	r	+= makeSymbol(L"=\"");
	r	+= makeLiteral(hVal);
	r	+= makeSymbol(L"\"");
	return r.AllocSysString();
}

BSTR	xmlTool::makeLiteral(BSTR str) {
	CString r;
	r	= "<FONT ";
	r	+= FONT_LITERAL;
	r	+= ">";
	r	+= str;
	r	+= "</FONT>";
	return r.AllocSysString();
}

BSTR	xmlTool::makeSymbol(BSTR str) {
	CString r;
	r	= "<FONT ";
	r	+= FONT_SYMBOL;
	r	+= ">";
	r	+= str;
	r	+= "</FONT>";
	return r.AllocSysString();
}

BSTR	xmlTool::makeIdentifier(BSTR str) {
	CString r;
	r	= "<FONT ";
	r	+= FONT_IDENTIFIER;
	r	+= ">";
	r	+= str;
	r	+= "</FONT>";
	return r.AllocSysString();
}

BSTR	xmlTool::makeInvalid(BSTR str) {
	CString r;
	r	= "<FONT ";
	r	+= FONT_INVALID;
	r	+= ">";
	r	+= str;
	r	+= "</FONT>";
	return r.AllocSysString();
}
