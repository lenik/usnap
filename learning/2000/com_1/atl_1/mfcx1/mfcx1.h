#if !defined(AFX_MFCX1_H__F3B3856E_80EB_470F_A46E_B2FF5954B98C__INCLUDED_)
#define AFX_MFCX1_H__F3B3856E_80EB_470F_A46E_B2FF5954B98C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// mfcx1.h : main header file for MFCX1.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols
#include "Mfcx1_i.h"

/////////////////////////////////////////////////////////////////////////////
// CMfcx1App : See mfcx1.cpp for implementation.

class CMfcx1App : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
private:
	BOOL InitATL();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCX1_H__F3B3856E_80EB_470F_A46E_B2FF5954B98C__INCLUDED)
