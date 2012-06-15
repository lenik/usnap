
#pragma once


typedef BOOL (_stdcall *HOOKUSER)(int code, WPARAM, LPARAM, HOOKINFO *);

struct HOOKINFO {
	HOOKINFO *m_pNext;
	HOOKTYPE m_Type;
	HHOOK m_hhk;
	HOOKPROC m_pfParent;
	HOOKPROC m_pfThis;
	HOOKUSER m_pfUser;
	DWORD m_dwMaskWparam;	// Bit: 0 nonblock, 1 blocked.
	DWORD m_dwMaskLparam;
	BOOL m_bEnabled;
	BOOL m_bCallUser;
	int m_nInvokes;
	DWORD m_dwUser;
};

struct HOOKMODULE {
	HANDLE hModule;
	HOOKINFO *pHooks;
	HINSTANCE hAppInst;
	DWORD dwUser;
};
