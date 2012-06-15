// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__5491A9BF_5DB0_4B44_93C7_F18A8CE51D1C__INCLUDED_)
#define AFX_STDAFX_H__5491A9BF_5DB0_4B44_93C7_F18A8CE51D1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#pragma warning(disable: 4100)       // unreferenced formal parameter
#pragma warning(disable: 4127)       // condition is constant
#pragma warning(disable: 4786)       // symbol long in debug info
#pragma warning(disable: 4530)       // exception with /GX

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <windows.h>
#include <windowsx.h>
#include <commdlg.h>
#include <tlhelp32.h>

#   pragma comment(lib, "comsupp.lib")
#   include <comutil.h>

#ifdef _DEBUG
#   include <assert.h>
#   ifndef _assert_
#       define _assert_(x) assert(x)
#   endif
#   ifndef _verify_
#       define _verify_(x) assert(x)
#   endif
#   ifndef _debug_
#       define _debug_(x) x
#   endif
#else
#   ifndef _assert_
#       define _assert_(x)
#   endif
#   ifndef _verify_
#       define _verify_(x) x
#   endif
#   ifndef _debug_
#       define _debug_(x)
#   endif
#endif

#define SAFE_DELETE(p)       if (p) { delete (p); (p) = NULL; }
#define SAFE_DELETE_ARRAY(p) if(p) { delete[] (p); (p) = NULL; }
#define SAFE_DEREF_(p, def)  ((p) == 0 ? (def) : *(p))
#define SAFE_DEREF(p)        SAFE_DEREF_(p, 0)
#define SAFE_ADDREF(p)       if (p) { (p)->AddRef(); }
#define SAFE_RELEASE(p)      if (p) { (p)->Release(); (p) = NULL; }
#define SAFE_RC(p)           ((p) ? ((p)->AddRef() - 1, (p)->Release()) : 0)

#   include <iostream>
#   include <strstream>
#   include <vector>
#   include <list>
#   include <utility>

#include <objbase.h>
//#import "../Debug/codec.dll"

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__5491A9BF_5DB0_4B44_93C7_F18A8CE51D1C__INCLUDED_)
