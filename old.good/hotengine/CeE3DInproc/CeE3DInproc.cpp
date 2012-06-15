// CeE3DInproc.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include "CeE3DInproc.h"

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}

CEE3DINPROC_API void _stdcall CeE3DInitDisplayMode(GLenum m) {
	auxInitDisplayMode(m);
}
CEE3DINPROC_API void _stdcall CeE3DInitPosition(int x0, int y0, int width, int height) {
	auxInitPosition(x0, y0, width, height);
}

GLenum CEE3DINPROC_API _stdcall CeE3DInitWindowA(LPCSTR lpCaption) {
	return auxInitWindowA(lpCaption);
}
GLenum CEE3DINPROC_API _stdcall CeE3DInitWindowW(LPCWSTR lpCaption) {
	return auxInitWindowW(lpCaption);
}

CEE3DINPROC_API void _stdcall CeE3DCloseWindow() {
	auxCloseWindow();
}
CEE3DINPROC_API void _stdcall CeE3DQuit() {
	auxQuit();
}
CEE3DINPROC_API void _stdcall CeE3DSwapBuffers() {
	auxSwapBuffers();
}

CEE3DINPROC_API void _stdcall CeE3DMainLoop(CEE3DMAINPROC proc) {
	auxMainLoop(proc);
}
CEE3DINPROC_API void _stdcall CeE3DExposeFunc(CEE3DEXPOSEPROC proc) {
	auxExposeFunc(proc);
}
CEE3DINPROC_API void _stdcall CeE3DReshapeFunc(CEE3DRESHAPEPROC proc) {
	auxReshapeFunc(proc);
}
CEE3DINPROC_API void _stdcall CeE3DIdleFunc(CEE3DIDLEPROC proc) {
	auxIdleFunc(proc);
}
CEE3DINPROC_API void _stdcall CeE3DKeyFunc(int k, CEE3DKEYPROC proc) {
	auxKeyFunc(k, proc);
}
CEE3DINPROC_API void _stdcall CeE3DMouseFunc(int m1, int m2, CEE3DMOUSEPROC proc) {
	auxMouseFunc(m1, m2, (AUXMOUSEPROC)proc);
}

CEE3DINPROC_API int  _stdcall CeE3DGetColorMapSize() {
	return auxGetColorMapSize();
}
CEE3DINPROC_API void _stdcall CeE3DGetMouseLoc(int *px, int *py) {
	auxGetMouseLoc(px, py);
}
CEE3DINPROC_API void _stdcall CeE3DSetOneColor(int index, float r, float g, float b) {
	auxSetOneColor(index, r, g, b);
}
CEE3DINPROC_API void _stdcall CeE3DSetFogRamp(int a, int b) {
	auxSetFogRamp(a, b);
}
CEE3DINPROC_API void _stdcall CeE3DSetGreyRamp() {
	auxSetGreyRamp();
}
CEE3DINPROC_API void _stdcall CeE3DSetRGBMap(int i, float *map) {
	auxSetRGBMap(i, map);
}

CEE3DINPROC_API CEE3D_RGBImageRec * _stdcall CeE3DRGBImageLoadA(LPCSTR lpName) {
	return (CEE3D_RGBImageRec *)auxRGBImageLoadA(lpName);
}
CEE3DINPROC_API CEE3D_RGBImageRec * _stdcall CeE3DRGBImageLoadW(LPCWSTR lpName) {
	return (CEE3D_RGBImageRec *)auxRGBImageLoadW(lpName);
}
CEE3DINPROC_API CEE3D_RGBImageRec * _stdcall CeE3DDIBImageLoadA(LPCSTR lpName) {
	return (CEE3D_RGBImageRec *)auxDIBImageLoadA(lpName);
}
CEE3DINPROC_API CEE3D_RGBImageRec * _stdcall CeE3DDIBImageLoadW(LPCWSTR lpName) {
	return (CEE3D_RGBImageRec *)auxDIBImageLoadW(lpName);
}

CEE3DINPROC_API void _stdcall CeE3DCreateFont() {
	auxCreateFont();
}
CEE3DINPROC_API void _stdcall CeE3DDrawStrA(LPCSTR lpText) {
	auxDrawStrA(lpText);
}
CEE3DINPROC_API void _stdcall CeE3DDrawStrW(LPCWSTR lpText) {
	auxDrawStrW(lpText);
}

CEE3DINPROC_API void _stdcall CeE3DWireSphere(GLdouble a) {
	auxWireSphere(a);
}
CEE3DINPROC_API void _stdcall CeE3DSolidSphere(GLdouble a) {
	auxSolidSphere(a);
}
CEE3DINPROC_API void _stdcall CeE3DWireCube(GLdouble a) {
	auxWireCube(a);
}
CEE3DINPROC_API void _stdcall CeE3DSolidCube(GLdouble a) {
	auxSolidCube(a);
}
CEE3DINPROC_API void _stdcall CeE3DWireBox(GLdouble a, GLdouble b, GLdouble c) {
	auxWireBox(a, b, c);
}
CEE3DINPROC_API void _stdcall CeE3DSolidBox(GLdouble a, GLdouble b, GLdouble c) {
	auxSolidBox(a, b, c);
}
CEE3DINPROC_API void _stdcall CeE3DWireTorus(GLdouble a, GLdouble b) {
	auxWireTorus(a, b);
}
CEE3DINPROC_API void _stdcall CeE3DSolidTorus(GLdouble a, GLdouble b) {
	auxSolidTorus(a, b);
}
CEE3DINPROC_API void _stdcall CeE3DWireCylinder(GLdouble a, GLdouble b) {
	auxWireCylinder(a, b);
}
CEE3DINPROC_API void _stdcall CeE3DSolidCylinder(GLdouble a, GLdouble b) {
	auxSolidCylinder(a, b);
}
CEE3DINPROC_API void _stdcall CeE3DWireIcosahedron(GLdouble a) {
	auxWireIcosahedron(a);
}
CEE3DINPROC_API void _stdcall CeE3DSolidIcosahedron(GLdouble a) {
	auxSolidIcosahedron(a);
}
CEE3DINPROC_API void _stdcall CeE3DWireOctahedron(GLdouble a) {
	auxWireOctahedron(a);
}
CEE3DINPROC_API void _stdcall CeE3DSolidOctahedron(GLdouble a) {
	auxSolidOctahedron(a);
}
CEE3DINPROC_API void _stdcall CeE3DWireTetrahedron(GLdouble a) {
	auxWireTetrahedron(a);
}
CEE3DINPROC_API void _stdcall CeE3DSolidTetrahedron(GLdouble a) {
	auxSolidTetrahedron(a);
}
CEE3DINPROC_API void _stdcall CeE3DWireDodecahedron(GLdouble a) {
	auxWireDodecahedron(a);
}
CEE3DINPROC_API void _stdcall CeE3DSolidDodecahedron(GLdouble a) {
	auxSolidDodecahedron(a);
}
CEE3DINPROC_API void _stdcall CeE3DWireCone(GLdouble a, GLdouble b) {
	auxWireCone(a, b);
}
CEE3DINPROC_API void _stdcall CeE3DSolidCone(GLdouble a, GLdouble b) {
	auxSolidCone(a, b);
}
CEE3DINPROC_API void _stdcall CeE3DWireTeapot(GLdouble a) {
	auxWireTeapot(a);
}
CEE3DINPROC_API void _stdcall CeE3DSolidTeapot(GLdouble a) {
	auxSolidTeapot(a);
}
CEE3DINPROC_API HWND _stdcall CeE3DGetHWND() {
	return auxGetHWND();
}
CEE3DINPROC_API HDC  _stdcall CeE3DGetHDC() {
	return auxGetHDC();
}
CEE3DINPROC_API HGLRC _stdcall CeE3DGetHGLRC() {
	return auxGetHGLRC();
}
CEE3DINPROC_API void _stdcall CeE3DInitDisplayModePolicy(GLenum m) {
	auxInitDisplayModePolicy(m);
}
CEE3DINPROC_API GLenum _stdcall CeE3DInitDisplayModeID(GLint id) {
	return auxInitDisplayModeID(id);
}
CEE3DINPROC_API GLenum _stdcall CeE3DGetDisplayModePolicy() {
	return auxGetDisplayModePolicy();
}
CEE3DINPROC_API GLint _stdcall CeE3DGetDisplayModeID() {
	return auxGetDisplayModeID();
}
CEE3DINPROC_API GLenum _stdcall CeE3DGetDisplayMode() {
	return auxGetDisplayMode();
}
