#if !defined(AFX_DOG_H__86153849_92D7_43CD_83BE_BBFFBCCEFAAD__INCLUDED_)
#define AFX_DOG_H__86153849_92D7_43CD_83BE_BBFFBCCEFAAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// dog.h : main header file for DOG.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDogApp : See dog.cpp for implementation.

class CDogApp : public COleControlModule
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

#endif // !defined(AFX_DOG_H__86153849_92D7_43CD_83BE_BBFFBCCEFAAD__INCLUDED)
