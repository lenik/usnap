#if !defined(AFX_MFC_COM2_H__68F7773F_0B42_4FBC_94AF_DBDB2A00F119__INCLUDED_)
#define AFX_MFC_COM2_H__68F7773F_0B42_4FBC_94AF_DBDB2A00F119__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// mfc_com2.h : main header file for MFC_COM2.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMfc_com2App : See mfc_com2.cpp for implementation.

class CMfc_com2App : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_COM2_H__68F7773F_0B42_4FBC_94AF_DBDB2A00F119__INCLUDED)
