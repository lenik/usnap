// Plane.cpp : Implementation of DLL Exports.

// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL,
//      run nmake -f Planeps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
// The module attribute causes DllMain, DllRegisterServer and DllUnregisterServer to be automatically implemented for you
[ module(dll, uuid = "{18FF5FFE-7F6C-4D4C-A909-6F5979F5F98C}",
		 name = "Plane",
		 helpstring = "Plane 1.0 Type Library",
		 service_name = "IDR_PLANE") ];
