#if !defined(AFX_HEXEDITCTL_H__7078B8FF_DCC2_409F_BDA0_77161FFAED37__INCLUDED_)
#define AFX_HEXEDITCTL_H__7078B8FF_DCC2_409F_BDA0_77161FFAED37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// HexEditCtl.h : main header file for HEXEDITCTL.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols
#include "HexEditCtl_i.h"

/////////////////////////////////////////////////////////////////////////////
// CHexEditCtlApp : See HexEditCtl.cpp for implementation.

class CHexEditCtlApp : public COleControlModule
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

#endif // !defined(AFX_HEXEDITCTL_H__7078B8FF_DCC2_409F_BDA0_77161FFAED37__INCLUDED)
