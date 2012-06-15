
#pragma once

#import <msxml.dll> named_guids rename_namespace("MSXML")

#define FONT_LITERAL		_T("COLOR=\"#000000\" STYLE=\"font-weight:bold\"")
#define FONT_SYMBOL		_T("COLOR=\"#0000FF\"")
#define FONT_IDENTIFIER		_T("COLOR=\"#AA4040\"")
#define FONT_INVALID		_T("COLOR=\"#FF0000\"")

#define CHAR_LT			_T("<FONT COLOR=\"#0000FF\">&lt;</FONT>")
#define CHAR_GT			_T("<FONT COLOR=\"#0000FF\">&gt;</FONT>")

class xmlTool {
	BSTR	m_strXmlView;
	MSXML::IXMLDOMDocumentPtr	m_pXml;
public:
	xmlTool(MSXML::IXMLDOMDocumentPtr pxml);
	virtual ~xmlTool();

public:
	BSTR	makeXmlView();

protected:
	BSTR	makeXmlView1(MSXML::IXMLDOMNodePtr node);

	BSTR	makeHashView(BSTR hName, BSTR hVal);
	BSTR	makeLiteral(BSTR str);
	BSTR	makeSymbol(BSTR str);
	BSTR	makeIdentifier(BSTR str);
	BSTR	makeInvalid(BSTR str);
};
