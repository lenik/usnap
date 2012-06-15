

#pragma once


#pragma pack(push, 4)

enum OTMSG_TYPE {
	OTM_DLL_CALL,
	OTM_COCREATEINSTANCE,
	OTM_QUERY_INTERFACE,
	OTM_INVOKE,
	OTM_VTBL_CALL,
};


template<int n>
struct _IntContainer {
	int theInt;
	_IntContainer : theInt(n) {}
};

struct OTI_DllCall {
	typedef _IntContainer<OTM_DLL_CALL>	msg_type;
	LPCTSTR		m_szDllName;
	LPCTSTR		m_szProcName;
	void *		m_localAddr;
};

struct OTI_CoCreateInstance {
	//
};
struct OTI_QueryInterface {
};
struct OTI_Invoke {
};
struct OTI_VtblCall {

	int		m_Offset;
	DWORD		m_stack[32];
};


template<typename _body>
struct OTMSG {
	_body::msg_type type;
	_body body;
};

#pragma pack(pop)
