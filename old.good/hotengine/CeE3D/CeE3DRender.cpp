
#include "StdAfx.h"

#include "resource.h"

#include "CeE3D.h"
#include "CeE3DRender.h"

#include <gl/gl.h>

CeE3DRender::CeE3DRender() {}
CeE3DRender::~CeE3DRender() {}

STDMETHODIMP
CeE3DRender::ShadeFlat() {
	glShadeModel(GL_FLAT);
	return NOERROR;
}

STDMETHODIMP
CeE3DRender::ShadeSmooth() {
	glShadeModel(GL_SMOOTH);
	return NOERROR;
}

STDMETHODIMP
CeE3DRender::SetDepthFunc(DEPTHFUNCENUM func) {
	glDepthFunc((GLenum)func);
	glEnable(GL_DEPTH_TEST);
	return NOERROR;
}
