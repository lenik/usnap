// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__FD9C954F_84C3_4AB3_B9D2_06A3C4C95D88__INCLUDED_)
#define AFX_STDAFX_H__FD9C954F_84C3_4AB3_B9D2_06A3C4C95D88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef STRICT
#define STRICT
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>

#include <gl/gl.h>
#include <gl/glu.h>
#include "../CeE3DInproc/CeE3DInproc.h"

#include <startinc.h>

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__FD9C954F_84C3_4AB3_B9D2_06A3C4C95D88__INCLUDED)
