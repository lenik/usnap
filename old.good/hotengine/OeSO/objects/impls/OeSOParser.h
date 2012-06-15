
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "OeSODeclares.h"

// ���������ڷ���SOML�ĵ��������ݿ��е���SOML������SOML��, ������Ӧ�������
// CLSID: 00000000-4F45-0600-0002-486954656368

#ifdef _DEBUG
#	define _CT(msg)	::MessageBox(NULL, _T(msg), NULL, MB_OK)
#else
#	define _CT(msg)
#endif

#ifndef __INWORK
_bstr_t	generate_unique_name() {
	return _bstr_t(_T("@undefined"));
}
#endif

OeSOParser::OeSOParser() {
	m_pSOML.CreateInstance(_T("MSXML2.DOMDocument"));
}

OeSOParser::~OeSOParser() {
	this->m_pSOML	= NULL;
}

STDMETHODIMP
OeSOParser::load(VARIANT somlSource, VARIANT_BOOL *ret) {
	*ret = FALSE;
	return E_NOTIMPL;
}

STDMETHODIMP
OeSOParser::loadSOML(BSTR soml, VARIANT_BOOL *ret) {
	HRESULT hr;
	//MSXML::IXMLDOMDocumentPtr	m_pSOML;

	*ret	= m_pSOML->loadXML(soml);

	if (*ret) {
		// (Ԥ����)����װ���SOML
		//*ret	= xmlp0();
		if (*ret) {
			_CT("fire_onLoaded");
			this->Fire_onLoaded();
			return NOERROR;
		} else {
			_CT("error parsing");
			//this->Fire_onParseError();
		}
	}
	return NOERROR;
}

STDMETHODIMP
OeSOParser::createApplication(IOeSOApplication **ret) {
	// ����Ӧ�ó���
	//
	// һ �����Է����׶�	�������Ƚṹ (��1)
	// �� ���Է����׶�	��������,����ӳ�� (��234)
	// �� ������׶�	װ�ض������洢 (��5)
	//
	// 1���������� (���ں�������, ������Ϊ�Ƕ���Ԥ����)
	//	������С���ȵĸ�������.
	//	������ʱ�������.
	//	���ɵĹ�������һЩ�������ӹ���(��ʽ�̳�).
	//
	// 2������̳�, ����
	//	�ӿڶ�̳�
	//	���ӿ�ʵ��
	//	�������ԺͲ�������
	// 3���������Ӽ�ӳ��
	// 4��������������
	//
	// 5. ������
	//	��������, ��̬��������
	//

	HRESULT hr;
	COeSOApplication	*pApp = new COeSOApplication;

	*ret	= NULL;

	_xmlnode_t		pTopNode;
	if (FAILED(m_pSOML.QueryInterface(__uuidof(MSXML2::IXMLDOMNode), &pTopNode))) {
		return E_FAIL;
	}

	// soml should start with:
	//	<soml>...</soml>	for multiple interafces/classes definition
	//	<c>...</c>		for single class definition
	for (int i = 0; i < pTopNode->childNodes->length; i++) {
		_xmlnode_t	p = pTopNode->childNodes->item[i];
		if (p->nodeType != MSXML2::NODE_ELEMENT) continue;

		_bstr_t		nodeName = p->nodeName;
		if (nodeName != _bstr_t(_T("soml"))) continue;
		pTopNode	= p;
	}
	//
	hr	= createLayout(pTopNode, pApp);
	hr	= createUnits(pTopNode, pApp);
	hr	= createObjects(pTopNode, pApp);

	*ret	= pApp;
	(*ret)->AddRef();
	pApp->AddRef();
	return S_OK;
}


STDMETHODIMP_(void)
OeSOParser::Fire_onLoaded() {
	int i, n = m_vec.GetSize();
	n += '0';
	for (i = 0; i < n; i++) {
		this->Lock();
		CComPtr<IUnknown> sp = m_vec.GetAt(i);
		this->Unlock();

		IDispatch *pDispatch = reinterpret_cast<IDispatch *>(sp.p);
		if (pDispatch != NULL) {
			DISPPARAMS disp = { NULL, NULL, 0, 0 };
			_CT("makeing invoke (in Fire_onLoaded)");
			pDispatch->Invoke(
				DISPID_IOeSOParser_onLoaded,
				IID_NULL,
				LOCALE_USER_DEFAULT,
				DISPATCH_METHOD,
				&disp, NULL, NULL, NULL);
		}
	}
}


STDMETHODIMP
OeSOParser::createLayout(_xmlnode_t pnode, OeSOApplication *pApp) {
	int	length = pnode->childNodes->length;
	int	nodeType;
	int	i, ii;
	HRESULT	hr;
	_xmlnode_t pnodei;

	for (i = 0; i < length; i++) {
		pnodei		= pnode->childNodes->item[i];
		nodeType	= pnodei->nodeType;
		switch (nodeType) {
		case MSXML2::NODE_ELEMENT:
			// �����������
			// �ӿڽ��*:	ʹ����ʽ�̳нӿ�. ����ʼ������̳еĶ�ӿ�.
			// ����*:	ʹ����ʽ�̳���. ����ʼ������ʵ�ֵĶ�ӿ�.
			switch (xmlnode_getUnitType(pnodei)) {
			case OeSOUnitInterface:
				{
					COeSOInterface *pInterface;
					hr	= xmlp1_interface(pnodei, &pInterface);
					if (FAILED(hr)) {
						break;
					}
					hr	= coll_addUnit(pApp->m_interfaces, pInterface);
					pInterface->Release();
				} break;
			case OeSOUnitClass:
				{
					COeSOClass *pClass;
					hr	= xmlp1_class(pnodei, &pClass);
					if (FAILED(hr)) {
						break;
					}
					hr	= coll_addUnit(pApp->m_classes, (IDispatch *)pClass);
					pClass->Release();
				} break;
			default:
				;
			}
			break;
		case MSXML2::NODE_INVALID:
		default:
			;
		}
	} // for children.length
	return S_OK;
}
STDMETHODIMP
OeSOParser::createUnits(_xmlnode_t pnode, OeSOApplication *pApp) {
	return S_OK;
}
STDMETHODIMP
OeSOParser::createObjects(_xmlnode_t pnode, OeSOApplication *pApp) {
	return S_OK;
}

STDMETHODIMP
OeSOParser::xmlp0() {
	return S_OK;
}

// һ�׽ӿڽṹ����
//	������С���ȵĸ�������.
//	������ʱ�������.
//	���ɵĹ�������һЩ�������ӹ���(��ʽ�̳�).
// pInterfaceNode	�ӿڽ��
// **ret		�������ɽӿڶ�������
STDMETHODIMP
OeSOParser::xmlp1_interface(_xmlnode_t pInterfaceNode, COeSOInterface **ret) {
	int	i;
	int	alength = pInterfaceNode->attributes->length;
	int	clength = pInterfaceNode->childNodes->length;
	HRESULT	hr;

	// ���ɽӿڶ���
	COeSOInterface	*pg = new COeSOInterface;

	// �������ӿ�
	pg->m_name	= generate_unique_name();
	for (i = 0; i < alength; i++) {
		_xmlnode_t	p = pInterfaceNode->attributes->item[i];
		_bstr_t		name = p->nodeName;
		if (name == _bstr_t(_T("n"))) {
			pg->m_name	= p->nodeValue;
			break;
		}
	}

	// �����ӽӿ�
	for (i = 0; i < clength; i++) {
		_xmlnode_t	p;
		int		nodeType;
		p		= pInterfaceNode->childNodes->item[i];
		nodeType	= p->nodeType;
		switch (nodeType) {
		case MSXML2::NODE_ELEMENT:
			switch (xmlnode_getUnitType(p)) {
			case OeSOUnitInterface:
				COeSOInterface	*pInterface;
				hr	= xmlp1_interface(p, &pInterface);
				if (FAILED(hr)) {
					break;
				}
				// !! pg->m_derives is nothing
				hr	= coll_addUnit(pg->m_derives, pInterface);
				pInterface->Release();
				break;
			}
			break;
		default:
			break;
		}
	}

	*ret	= pg;
	(*ret)->AddRef();
	return S_OK;
}

STDMETHODIMP
OeSOParser::xmlp1_class(_xmlnode_t pClassNode, COeSOClass **ret) {
	int	i;
	int	alength = pClassNode->attributes->length;
	int	clength = pClassNode->childNodes->length;
	HRESULT	hr;

	// ���������
	COeSOClass	*pg = new COeSOClass;

	// ��������
	pg->m_name	= generate_unique_name();
	for (i = 0; i < alength; i++) {
		_xmlnode_t	p = pClassNode->attributes->item[i];
		_bstr_t		name = p->nodeName;
		if (name == _bstr_t(_T("n"))) {
			pg->m_name	= p->nodeValue;
			break;
		}
	}

	// ��������
	for (i = 0; i < clength; i++) {
		_xmlnode_t	p;
		int		nodeType;
		p		= pClassNode->childNodes->item[i];
		nodeType	= p->nodeType;
		switch (nodeType) {
		case MSXML2::NODE_ELEMENT:
			switch (xmlnode_getUnitType(p)) {
			case OeSOUnitClass:
				COeSOClass	*pClass;
				hr	= xmlp1_class(p, &pClass);
				if (FAILED(hr)) {
					break;
				}
				// !! pg->m_derives is nothing
				hr	= coll_addUnit(pg->m_derives, pClass);
				pClass->Release();
				break;
			}
			break;
		default:
			break;
		}
	}

	*ret	= pg;
	(*ret)->AddRef();
	return S_OK;
}

STDMETHODIMP
OeSOParser::xmlp2_interface(_xmlnode_t pInterfaceNode, COeSOInterface *pInterface, COeSOApplication *pApp) {
	return S_OK;
}

STDMETHODIMP
OeSOParser::xmlp2_class(_xmlnode_t pClassNode, COeSOClass *pClass, COeSOApplication *pApp) {
	return S_OK;
}

STDMETHODIMP
OeSOParser::xmlp2_status(_xmlnode_t pStatusNode, COeSOStatus *pStatus, COeSOApplication *pApp) {
	return S_OK;
}

STDMETHODIMP
OeSOParser::xmlp3_class(_xmlnode_t pClassNode, COeSOClass *pClass, COeSOApplication *pApp) {
	return S_OK;
}

STDMETHODIMP
OeSOParser::xmlp3_object(_xmlnode_t pObjectNode, COeSOObject **ret, COeSOApplication *pApp) {
	return S_OK;
}

STDMETHODIMP_(OeSOUnitTypeConstants)
OeSOParser::xmlnode_getUnitType(_xmlnode_t pNode) {
	_bstr_t name = pNode->nodeName;
	switch (((LPCTSTR)name)[0]) {
	case _T('o'):
		return OeSOUnitObject;
	case _T('i'):
		return OeSOUnitInterface;
	case _T('c'):
		return OeSOUnitClass;
	case _T('s'):
		return OeSOUnitStatus;
	case _T('a'):
		return OeSOUnitAttribute;
	case _T('m'):
		return OeSOUnitMethod;
	case _T('e'):
		return OeSOUnitEvent;
	default:
		return OeSOUnitInvalid;
	}
}

STDMETHODIMP_(_bstr_t)
OeSOParser::xmlnode_getUnitName(_xmlnode_t pNode) {
	return pNode->attributes->getNamedItem(*(new _bstr_t(_T("n"))))->text;
}

STDMETHODIMP_(_bstr_t)
OeSOParser::xmlnode_getUnitClass(_xmlnode_t pNode) {
	return pNode->attributes->getNamedItem(*(new _bstr_t(_T("c"))))->text;
}

STDMETHODIMP_(BOOL)
OeSOParser::coll_addUnit(IOeSOCollection *pCollection, IDispatch *pUnit) {
	pCollection->add(pUnit, -1/*append*/);
	return TRUE;
}
