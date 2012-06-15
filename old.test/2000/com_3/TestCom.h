#if !defined(AFX_TESTCOM_H__0401AA2A_39AA_41CF_A817_73382EB2ACFB__INCLUDED_)
#define AFX_TESTCOM_H__0401AA2A_39AA_41CF_A817_73382EB2ACFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// TestCom.h : main header file for TESTCOM2.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestComApp : See TestCom.cpp for implementation.

class CTestComApp : public COleControlModule
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

#endif // !defined(AFX_TESTCOM_H__0401AA2A_39AA_41CF_A817_73382EB2ACFB__INCLUDED)
