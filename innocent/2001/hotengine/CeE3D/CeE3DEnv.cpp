
#include "StdAfx.h"

#include "resource.h"

#include "CeE3D.h"
#include "CeE3DEnv.h"

#include <gl/gl.h>

CeE3DEnv::CeE3DEnv() {
	m_bLightingEnabled	= glIsEnabled(GL_LIGHTING);
	for (int i = 0; i < 32; i++) {	// 8 light minimum supports
		m_bLightEnabled[i]	= glIsEnabled(GL_LIGHT0 + i);
	}
}

CeE3DEnv::~CeE3DEnv() {
}

STDMETHODIMP
CeE3DEnv::StartLighting(BOOL *ret) {
	glEnable(GL_LIGHTING);
	*ret = TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE3DEnv::EndLighting(BOOL *ret) {
	glDisable(GL_LIGHTING);
	*ret = TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE3DEnv::EnableLight(GLint whichlight, BOOL *ret) {
	glEnable(GL_LIGHT0 + whichlight);
	*ret = TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE3DEnv::DisableLight(GLint whichlight, BOOL *ret) {
	glDisable(GL_LIGHT0 + whichlight);
	*ret = TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE3DEnv::SetAmbientModelfv(GLfloat *params, BOOL *ret) {
	if (params == NULL) {
		*ret = FALSE;
		return NOERROR;
	}
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, params);
	*ret = TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE3DEnv::SetLocalViewerModel(BOOL enable, BOOL *ret) {
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, enable ? GL_TRUE : GL_FALSE);
	*ret = TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE3DEnv::SetTwoSideModel(BOOL enable, BOOL *ret) {
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, enable ? GL_TRUE : GL_FALSE);
	*ret = TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE3DEnv::SetLightAmbientf(GLint whichlight, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, BOOL *ret) {
	float	fv[] = { red, green, blue, alpha };
	glLightfv(GL_LIGHT0 + whichlight, GL_AMBIENT, fv);
	*ret = TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE3DEnv::SetLightDiffusef(GLint whichlight, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, BOOL *ret) {
	float	fv[] = { red, green, blue, alpha };
	glLightfv(GL_LIGHT0 + whichlight, GL_DIFFUSE, fv);
	*ret = TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE3DEnv::SetLightSpecularf(GLint whichlight, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, BOOL *ret) {
	float	fv[] = { red, green, blue, alpha };
	glLightfv(GL_LIGHT0 + whichlight, GL_SPECULAR, fv);
	*ret = TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE3DEnv::SetLightPositionf(GLint whichlight, GLfloat x, GLfloat y, GLfloat z, GLfloat w, BOOL *ret) {
	float	pos[] = { x, y, z, w };
	glLightfv(GL_LIGHT0 + whichlight, GL_POSITION, pos);
	*ret = TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE3DEnv::SetLightSpotDirectionf(GLint whichlight, GLfloat x, GLfloat y, GLfloat z, BOOL *ret) {
	float	direction[] = { x, y, z };
	glLightfv(GL_LIGHT0 + whichlight, GL_SPOT_DIRECTION, direction);
	*ret = TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE3DEnv::SetLightSpotExponentf(GLint whichlight, GLfloat exponent, BOOL *ret) {
	glLightf(GL_LIGHT0 + whichlight, GL_SPOT_EXPONENT, exponent);
	*ret = TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE3DEnv::SetLightSpotCutofff(GLint whichlight, GLfloat cutoff, BOOL *ret) {
	glLightf(GL_LIGHT0 + whichlight, GL_SPOT_CUTOFF, cutoff);
	*ret = TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE3DEnv::SetLightAttenuationf(GLint whichlight, GLfloat quadratic, GLfloat linear, GLfloat constant, BOOL *ret) {
	glLightf(GL_LIGHT0 + whichlight, GL_QUADRATIC_ATTENUATION, quadratic);
	glLightf(GL_LIGHT0 + whichlight, GL_LINEAR_ATTENUATION, linear);
	glLightf(GL_LIGHT0 + whichlight, GL_CONSTANT_ATTENUATION, constant);
	*ret = TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE3DEnv::SetLightConstantAttenuationf(GLint whichlight, GLfloat attenuation, BOOL *ret) {
	glLightf(GL_LIGHT0 + whichlight, GL_CONSTANT_ATTENUATION, attenuation);
	*ret = TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE3DEnv::SetLightLinearAttenuationf(GLint whichlight, GLfloat attenuation, BOOL *ret) {
	glLightf(GL_LIGHT0 + whichlight, GL_LINEAR_ATTENUATION, attenuation);
	*ret = TRUE;
	return NOERROR;
}

STDMETHODIMP
CeE3DEnv::SetLightQuadraticAttenuationf(GLint whichlight, GLfloat attenuation, BOOL *ret) {
	glLightf(GL_LIGHT0 + whichlight, GL_QUADRATIC_ATTENUATION, attenuation);
	*ret = TRUE;
	return NOERROR;
}
