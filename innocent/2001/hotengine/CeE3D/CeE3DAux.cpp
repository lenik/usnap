
#include "StdAfx.h"

#include "resource.h"

#include "CeE3D.h"
#include "CeE3DAux.h"

CeE3DAux::CeE3DAux() {
	m_pfd.nSize		= sizeof(m_pfd);
	m_pfd.nVersion		= 1;
	m_pfd.dwFlags		= PFD_DRAW_TO_WINDOW
					| PFD_SUPPORT_OPENGL;
	m_pfd.iPixelType	= PFD_TYPE_RGBA;
	m_pfd.cColorBits	= 24;
	m_pfd.cRedBits		= 0;
	m_pfd.cRedShift		= 0;
	m_pfd.cGreenBits	= 0;
	m_pfd.cGreenShift	= 0;
	m_pfd.cBlueBits		= 0;
	m_pfd.cBlueShift	= 0;
	m_pfd.cAlphaBits	= 0;
	m_pfd.cAlphaShift	= 0;
	m_pfd.cAccumBits	= 0;
	m_pfd.cAccumRedBits	= 0;
	m_pfd.cAccumGreenBits	= 0;
	m_pfd.cAccumBlueBits	= 0;
	m_pfd.cAccumAlphaBits	= 0;
	m_pfd.cDepthBits	= 32;
	m_pfd.cStencilBits	= 0;
	m_pfd.cAuxBuffers	= 0;
	m_pfd.iLayerType	= PFD_MAIN_PLANE;
	m_pfd.bReserved		= 0;
	m_pfd.dwLayerMask	= 0;
	m_pfd.dwVisibleMask	= 0;
	m_pfd.dwDamageMask	= 0;

	m_hglrc			= NULL;
};

CeE3DAux::~CeE3DAux() {
	if (m_hglrc != NULL) {
		Endup();
	}
}

STDMETHODIMP
CeE3DAux::get_hE3D(HGLRC *hglrc) {
	*hglrc	= m_hglrc;
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::get_PixelFormatDescriptor(LPPIXELFORMATDESCRIPTOR ppfd) {
	memcpy((LPVOID)ppfd, (LPVOID)&m_pfd, sizeof(PIXELFORMATDESCRIPTOR));
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::put_PixelFormatDescriptor(LPPIXELFORMATDESCRIPTOR ppfd) {
	memcpy((LPVOID)&m_pfd, (LPVOID)ppfd, sizeof(PIXELFORMATDESCRIPTOR));
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::get_PFlags(LONG *pFlags) {
	*pFlags = this->m_pfd.dwFlags;
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::put_PFlags(LONG flags) {
	this->m_pfd.dwFlags = flags;
	return NOERROR;
}


STDMETHODIMP
CeE3DAux::InitDC(HDC hDC, BOOL *ret) {
	ApplyPixelFormatTo(hDC, ret);
	if (*ret) {
		m_hglrc = wglCreateContext(hDC);
		if (m_hglrc != NULL) {
			*ret = TRUE;
		}
	}
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::Endup() {
	if (m_hglrc != NULL) {
		wglDeleteContext(m_hglrc);
	}

	return NOERROR;
}

STDMETHODIMP
CeE3DAux::SetPixelFormat(HDC hDC, LPPIXELFORMATDESCRIPTOR ppfd, BOOL *ret) {
	if (hDC == NULL || ppfd == NULL) {
		*ret = FALSE;
	} else {
		memcpy((LPVOID)&m_pfd, (LPVOID)ppfd, sizeof(PIXELFORMATDESCRIPTOR));
		ApplyPixelFormatTo(hDC, ret);
	}
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::GetPixelFormat(HDC hDC, LONG index, BOOL *ret) {
	LONG maxindex;
	*ret = TRUE;
	if (hDC == NULL || index < 0) {
		*ret = FALSE;
	} else {
		maxindex = DescribePixelFormat(hDC, 0, 0, NULL);
		if (index > maxindex) {
			*ret = FALSE;
		} else {
			DescribePixelFormat(hDC, index, sizeof(m_pfd), &m_pfd);
		}
	}

	return NOERROR;
}

STDMETHODIMP
CeE3DAux::ApplyPixelFormatTo(HDC hDC, BOOL *ret) {
	int PixelFormat = ChoosePixelFormat(hDC, &m_pfd);
	*ret = ::SetPixelFormat(hDC, PixelFormat, &m_pfd);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawBegin(HDC hDC, BOOL *ret) {
	*ret = wglMakeCurrent(hDC, m_hglrc);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawEnd(HDC hDC, BOOL *ret) {
	*ret = wglMakeCurrent(hDC, NULL);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::ClearAll() {
	glClear(GL_COLOR_BUFFER_BIT |
		GL_DEPTH_BUFFER_BIT |
		GL_STENCIL_BUFFER_BIT |
		GL_ACCUM_BUFFER_BIT);
	return NOERROR;
}

// delegation...

STDMETHODIMP
CeE3DAux::InitDisplayMode(GLenum mode) {
	CeE3DInitDisplayMode(mode);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::InitPosition(LONG x1, LONG y1, LONG x2, LONG y2) {
	CeE3DInitPosition(x1, y1, x2, y2);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::InitWindow(BSTR lpCaption, GLenum *retval) {
	*retval = CeE3DInitWindowW(lpCaption);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::CloseWindow() {
	CeE3DCloseWindow();
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::Quit() {
	CeE3DQuit();
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::SwapBuffers() {
	CeE3DSwapBuffers();
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::GetColorMapSize(LONG *retval) {
	*retval = CeE3DGetColorMapSize();
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::GetMouseLoc(LONG *px, LONG *py) {
	CeE3DGetMouseLoc((LPINT)px, (LPINT)py);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::SetOneColor(LONG index, float r, float g, float b) {
	CeE3DSetOneColor(index, r, g, b);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::SetFogRamp(LONG a, LONG b) {
	CeE3DSetFogRamp(a, b);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::SetGreyRamp() {
	CeE3DSetGreyRamp();
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::SetRGBMap(LONG l, float *pf) {
	CeE3DSetRGBMap(l, pf);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::MainLoop(CEE3DMAINPROC proc) {
	CeE3DMainLoop(proc);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::ExposeFunc(CEE3DEXPOSEPROC proc) {
	CeE3DExposeFunc(proc);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::ReshapeFunc(CEE3DRESHAPEPROC proc) {
	CeE3DReshapeFunc(proc);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::IdleFunc(CEE3DIDLEPROC proc) {
	CeE3DIdleFunc(proc);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::KeyFunc(int k, CEE3DKEYPROC proc) {
	CeE3DKeyFunc(k, proc);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::MouseFunc(int ma, int mb, CEE3DMOUSEPROC proc) {
	CeE3DMouseFunc(ma, mb, proc);
	return NOERROR;
}


STDMETHODIMP
CeE3DAux::CreateFont() {
	CeE3DCreateFont();
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawStr(BSTR pstr) {
	CeE3DDrawStrW(pstr);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawWireSphere(GLdouble r) {
	CeE3DWireSphere(r);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawSolidSphere(GLdouble r) {
	CeE3DSolidSphere(r);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawWireCube(GLdouble a) {
	CeE3DWireCube(a);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawSolidCube(GLdouble a) {
	CeE3DSolidCube(a);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawWireBox(GLdouble a, GLdouble b, GLdouble c) {
	CeE3DWireBox(a, b, c);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawSolidBox(GLdouble a, GLdouble b, GLdouble c) {
	CeE3DSolidBox(a, b, c);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawWireTorus(GLdouble a, GLdouble b) {
	CeE3DWireTorus(a, b);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawSolidTorus(GLdouble a, GLdouble b) {
	CeE3DSolidTorus(a, b);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawWireCylinder(GLdouble a, GLdouble b) {
	CeE3DWireCylinder(a, b);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawSolidCylinder(GLdouble a, GLdouble b) {
	CeE3DSolidCylinder(a, b);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawWireIcosahedron(GLdouble a) {
	CeE3DWireIcosahedron(a);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawSolidIcosahedron(GLdouble a) {
	CeE3DSolidIcosahedron(a);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawWireOctahedron(GLdouble a) {
	CeE3DWireOctahedron(a);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawSolidOctahedron(GLdouble a) {
	CeE3DSolidOctahedron(a);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawWireTetrahedron(GLdouble a) {
	CeE3DWireTetrahedron(a);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawSolidTetrahedron(GLdouble a) {
	CeE3DSolidTetrahedron(a);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawWireDodecahedron(GLdouble a) {
	CeE3DWireDodecahedron(a);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawSolidDodecahedron(GLdouble a) {
	CeE3DSolidDodecahedron(a);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawWireCone(GLdouble a, GLdouble b) {
	CeE3DWireCone(a, b);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawSolidCone(GLdouble a, GLdouble b) {
	CeE3DSolidCone(a, b);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawWireTeapot(GLdouble a) {
	CeE3DWireTeapot(a);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::DrawSolidTeapot(GLdouble a) {
	CeE3DSolidTeapot(a);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::GetHWND(HWND *hWnd) {
	*hWnd = CeE3DGetHWND();
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::GetHDC(HDC *hDC) {
	*hDC = CeE3DGetHDC();
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::GetHGLRC(HGLRC *hGLRC) {
	*hGLRC = CeE3DGetHGLRC();
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::InitDisplayModePolicy(GLenum i) {
	CeE3DInitDisplayModePolicy(i);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::InitDisplayModeID(GLint id, GLenum *retval) {
	*retval = CeE3DInitDisplayModeID(id);
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::GetDisplayModePolicy(GLenum *retval) {
	*retval = CeE3DGetDisplayModePolicy();
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::GetDisplayModeID(GLint *retval) {
	*retval = CeE3DGetDisplayModeID();
	return NOERROR;
}

STDMETHODIMP
CeE3DAux::GetDisplayMode(GLenum *retval) {
	*retval = CeE3DGetDisplayMode();
	return NOERROR;
}
