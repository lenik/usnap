#if !defined(AFX_XEDITBOX_H__D44CB2B8_5845_4759_A476_83D436EDDA4E__INCLUDED_)
#define AFX_XEDITBOX_H__D44CB2B8_5845_4759_A476_83D436EDDA4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// XEditBox.h : main header file for XEDITBOX.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CXEditBoxApp : See XEditBox.cpp for implementation.

class CXEditBoxApp : public COleControlModule
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

#endif // !defined(AFX_XEDITBOX_H__D44CB2B8_5845_4759_A476_83D436EDDA4E__INCLUDED)
