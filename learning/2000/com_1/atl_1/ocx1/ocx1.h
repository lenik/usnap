#if !defined(AFX_OCX1_H__5D742D2E_F5F2_4344_8950_90BB6257B859__INCLUDED_)
#define AFX_OCX1_H__5D742D2E_F5F2_4344_8950_90BB6257B859__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// ocx1.h : main header file for OCX1.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols
#include "Ocx1_i.h"

/////////////////////////////////////////////////////////////////////////////
// COcx1App : See ocx1.cpp for implementation.

class COcx1App : public COleControlModule
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

#endif // !defined(AFX_OCX1_H__5D742D2E_F5F2_4344_8950_90BB6257B859__INCLUDED)
