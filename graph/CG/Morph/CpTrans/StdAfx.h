// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__29DCD678_CAD2_4E05_ACD4_4F33AC92E6C2__INCLUDED_)
#define AFX_STDAFX_H__29DCD678_CAD2_4E05_ACD4_4F33AC92E6C2__INCLUDED_

#if defined(WIN32) || defined(_WINDOWS)

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#else

#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <string.h>
#include <graphics.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <dos.h>
#include <ctype.h>

#endif

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__29DCD678_CAD2_4E05_ACD4_4F33AC92E6C2__INCLUDED_)
