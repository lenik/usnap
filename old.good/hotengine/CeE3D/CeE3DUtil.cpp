
#include "StdAfx.h"

#include "resource.h"

#include "CeE3D.h"
#include "CeE3DUtil.h"

#include <gl/gl.h>

CeE3DUtil::CeE3DUtil() {}
CeE3DUtil::~CeE3DUtil() {}

STDMETHODIMP
CeE3DUtil::Ortho2D(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top) {
	gluOrtho2D(left, right, bottom, top);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::Perspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar) {
	gluPerspective(fovy, aspect, zNear, zFar);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::PickMatrix(GLdouble x, GLdouble y, GLdouble width, GLdouble height, GLint *viewport) {
	gluPickMatrix(x, y, width, height, viewport);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::LookAt(GLdouble eyex, GLdouble eyey, GLdouble eyez, GLdouble centerx, GLdouble centery, GLdouble centerz, GLdouble upx, GLdouble upy, GLdouble upz) {
	gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::DeleteQuadric(CeE3Dquadric state) {
	gluDeleteQuadric((GLUquadric *)state);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::QuadricNormals(CeE3Dquadric quadObject, GLenum normals) {
	gluQuadricNormals((GLUquadric *)quadObject, normals);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::QuadricTexture(CeE3Dquadric quadObject, GLboolean textureCoords) {
	gluQuadricTexture((GLUquadric *)quadObject, textureCoords);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::QuadricOrientation(CeE3Dquadric quadObject, GLenum orientation) {
	gluQuadricOrientation((GLUquadric *)quadObject, orientation);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::QuadricDrawStyle(CeE3Dquadric quadObject, GLenum drawStyle) {
	gluQuadricDrawStyle((GLUquadric *)quadObject, drawStyle);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::Cylinder(CeE3Dquadric qobj, GLdouble baseRadius, GLdouble topRadius, GLdouble height, GLint slices, GLint stacks) {
	gluCylinder((GLUquadric *)qobj, baseRadius, topRadius, height, slices, stacks);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::Disk(CeE3Dquadric qobj, GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint loops) {
	gluDisk((GLUquadric *)qobj, innerRadius, outerRadius, slices, loops);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::PartialDisk(CeE3Dquadric qobj, GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint loops, GLdouble startAngle, GLdouble sweepAngle) {
	gluPartialDisk((GLUquadric *)qobj, innerRadius, outerRadius, slices, loops, startAngle, sweepAngle);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::Sphere(CeE3Dquadric qobj, GLdouble radius, GLint slices, GLint stacks) {
	gluSphere((GLUquadric *)qobj, radius, slices, stacks);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::DeleteTess(CeE3Dtesselator tess) {
	gluDeleteTess((GLUtesselator *)tess);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::TessBeginPolygon(CeE3Dtesselator tess, BYTE *polygon_data) {
	gluTessBeginPolygon((GLUtesselator *)tess, polygon_data);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::TessBeginContour(CeE3Dtesselator tess) {
	gluTessBeginContour((GLUtesselator *)tess);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::TessVertex(CeE3Dtesselator tess, GLdouble *coords, BYTE *data) {
	gluTessVertex((GLUtesselator *)tess, coords, data);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::TessEndContour(CeE3Dtesselator tess) {
	gluTessEndContour((GLUtesselator *)tess);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::TessEndPolygon(CeE3Dtesselator tess) {
	gluTessEndPolygon((GLUtesselator *)tess);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::TessProperty(CeE3Dtesselator tess, GLenum which, GLdouble value) {
	gluTessProperty((GLUtesselator *)tess, which, value);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::TessNormal(CeE3Dtesselator tess, GLdouble x, GLdouble y, GLdouble z) {
	gluTessNormal((GLUtesselator *)tess, x, y, z);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::GetTessProperty(CeE3Dtesselator tess, GLenum which, GLdouble *value) {
	gluGetTessProperty((GLUtesselator *)tess, which, value);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::DeleteNurbsRenderer(CeE3Dnurbs nobj) {
	gluDeleteNurbsRenderer((GLUnurbs *)nobj);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::BeginSurface(CeE3Dnurbs nobj) {
	gluBeginSurface((GLUnurbs *)nobj);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::BeginCurve(CeE3Dnurbs nobj) {
	gluBeginCurve((GLUnurbs *)nobj);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::EndCurve(CeE3Dnurbs nobj) {
	gluEndCurve((GLUnurbs *)nobj);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::EndSurface(CeE3Dnurbs nobj) {
	gluEndSurface((GLUnurbs *)nobj);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::BeginTrim(CeE3Dnurbs nobj) {
	gluBeginTrim((GLUnurbs *)nobj);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::EndTrim(CeE3Dnurbs nobj) {
	gluEndTrim((GLUnurbs *)nobj);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::PwlCurve(CeE3Dnurbs nobj, GLint count, GLfloat *array, GLint stride, GLenum type) {
	gluPwlCurve((GLUnurbs *)nobj, count, array, stride, type);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::NurbsCurve(CeE3Dnurbs nobj, GLint nknots, GLfloat *knot, GLint stride, GLfloat *ctlarray, GLint order, GLenum type) {
	gluNurbsCurve((GLUnurbs *)nobj, nknots, knot, stride, ctlarray, order, type);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::NurbsSurface(CeE3Dnurbs nobj, GLint sknot_count, float *sknot, GLint tknot_count, GLfloat *tknot, GLint s_stride, GLint t_stride, GLfloat *ctlarray, GLint sorder, GLint torder, GLenum type) {
	gluNurbsSurface((GLUnurbs *)nobj, sknot_count, sknot, tknot_count, tknot, s_stride, t_stride, ctlarray, sorder, torder, type);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::LoadSamplingMatrices(CeE3Dnurbs nobj, GLfloat *modelMatrix, GLfloat *projMatrix, GLint *viewport) {
	gluLoadSamplingMatrices((GLUnurbs *)nobj, modelMatrix, projMatrix, viewport);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::NurbsProperty(CeE3Dnurbs nobj, GLenum property, GLfloat value) {
	gluNurbsProperty((GLUnurbs *)nobj, property, value);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::GetNurbsProperty(CeE3Dnurbs nobj, GLenum property, GLfloat *value) {
	gluGetNurbsProperty((GLUnurbs *)nobj, property, value);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::BeginPolygon(CeE3Dtesselator tess) {
	gluBeginPolygon((GLUtesselator *)tess);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::NextContour(CeE3Dtesselator tess, GLenum type) {
	gluNextContour((GLUtesselator *)tess, type);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::EndPolygon(CeE3Dtesselator tess) {
	gluEndPolygon((GLUtesselator *)tess);
	return NOERROR;
}


STDMETHODIMP
CeE3DUtil::QuadricCallback(CeE3Dquadric qobj, GLenum which, LONG callbackaddr) {
	gluQuadricCallback((GLUquadric *)qobj, which, (void (CALLBACK *)())callbackaddr);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::TessCallback(CeE3Dtesselator tess, GLenum which, LONG callbackaddr) {
	gluTessCallback((GLUtesselator *)tess, which, (void (CALLBACK *)())callbackaddr);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::NurbsCallback(CeE3Dnurbs nobj, GLenum which, LONG callbackaddr) {
	gluNurbsCallback((GLUnurbs *)nobj, which, (void (CALLBACK *)())callbackaddr);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::ErrorString(GLenum errCode, GLubytes *ret) {
	*ret	= (GLubytes)gluErrorString(errCode);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::ErrorUnicodeString(GLenum errCode, BSTR *ret) {
	*ret	= (BSTR)gluErrorUnicodeStringEXT(errCode);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::GetString(GLenum name, BSTR *ret) {
	*ret	= (BSTR)gluGetString(name);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::NewQuadric(CeE3Dquadric *ret) {
	*ret	= (CeE3Dquadric)gluNewQuadric();
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::NewTess(CeE3Dtesselator *ret) {
	*ret	= (CeE3Dtesselator)gluNewTess();
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::NewNurbsRenderer(CeE3Dnurbs *ret) {
	*ret	= (CeE3Dnurbs)gluNewNurbsRenderer();
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::Project(GLdouble objx, GLdouble objy, GLdouble objz, GLdouble *modeMatrix, GLdouble *projMatrix, GLint *viewport, GLdouble *winx, GLdouble *winy, GLdouble *winz, int *ret) {
	*ret	= gluProject(objx, objy, objz, modeMatrix, projMatrix, viewport, winx, winy, winz);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::UnProject(GLdouble winx, GLdouble winy, GLdouble winz, GLdouble *modeMatrix, GLdouble *projMatrix, GLint *viewport, GLdouble *objx, GLdouble *objy, GLdouble *objz, int *ret) {
	*ret	= gluUnProject(winx, winy, winz, modeMatrix, projMatrix, viewport, objx, objy, objz);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::ScaleImage(GLenum format, GLint widthin, GLint heightin, GLenum typein, BYTE *datain, GLint widthout, GLint heightout, GLenum typeout, BYTE *dataout, int *ret) {
	*ret	= gluScaleImage(format, widthin, heightin, typein, datain, widthout, heightout, typeout, dataout);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::Build1DMipmaps(GLenum target, GLint components, GLint width, GLenum format, GLenum type, BYTE *data, int *ret) {
	*ret	= gluBuild1DMipmaps(target, components, width, format, type, data);
	return NOERROR;
}

STDMETHODIMP
CeE3DUtil::Build2DMipmaps(GLenum target, GLint components, GLint width, GLint height, GLenum format, GLenum type, BYTE *data, int *ret) {
	*ret	= gluBuild2DMipmaps(target, components, width, height, format, type, data);
	return NOERROR;
}
