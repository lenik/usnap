// Joystick.h : main header file for the JOYSTICK application
//

#if !defined(AFX_JOYSTICK_H__E26F3334_C088_11D3_8278_484C0001E209__INCLUDED_)
#define AFX_JOYSTICK_H__E26F3334_C088_11D3_8278_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#include "mmsystem.h"

/////////////////////////////////////////////////////////////////////////////
// CJoystickApp:
// See Joystick.cpp for the implementation of this class
//

class CJoystickApp : public CWinApp
{
public:
	CJoystickApp();
public:
	JOYINFO joyinfo;
	JOYCAPS joycaps;
	UINT wNumDevs, wDeviceID;
	BOOL bDev1Attached, bDev2Attached;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJoystickApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL InitApplication();
	//}}AFX_VIRTUAL
	MMRESULT InitJoystick();
	MMRESULT CapsJoystick();
// Implementation

	//{{AFX_MSG(CJoystickApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
extern CJoystickApp *app;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JOYSTICK_H__E26F3334_C088_11D3_8278_484C0001E209__INCLUDED_)
