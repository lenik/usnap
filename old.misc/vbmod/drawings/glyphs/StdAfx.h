// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__6257D253_CFAF_4F8A_8FBA_44F69F022562__INCLUDED_)
#define AFX_STDAFX_H__6257D253_CFAF_4F8A_8FBA_44F69F022562__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>


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


#define typedef_strict(t, s) \
    typedef struct { t v; } s;

typedef float f64_t;

    typedef struct _f64p_t { f64_t x, y; } f64p_t;
    typedef struct _f64v_t { f64_t x, y, z; } f64v_t;
    typedef struct _f64w_t { f64_t x, y, z, w; } f64w_t;
    typedef struct _f64P_t { f64_t
        x0, y0,
        x1, y1; } f64P_t;
    typedef struct _f64V_t { f64_t
        x0, y0, z0,
        x1, y1, z1,
        x2, y2, z2; } f64V_t;
    typedef struct _f64W_t { f64_t
        x0, y0, z0, w0,
        x1, y1, z1, w1,
        x2, y2, z2, w2,
        x3, y3, z3, w3; } f64W_t;


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__6257D253_CFAF_4F8A_8FBA_44F69F022562__INCLUDED)
