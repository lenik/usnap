
#include "StdAfx.h"

#include "resource.h"

#include "CeE3D.h"
#include "CeE3DModel.h"

#include <gl/gl.h>

CeE3DModel::CeE3DModel() {}
CeE3DModel::~CeE3DModel() {}

#define _SAME0(f)								\
	STDMETHODIMP								\
	CeE3DModel::f() {							\
		::gl##f();							\
		return NOERROR;							\
	}

#define _SAME1(f, p1T, p1N)							\
	STDMETHODIMP								\
	CeE3DModel::f(p1T p1N) {						\
		::gl##f(p1N);							\
		return NOERROR;							\
	}

#define _SAME2(f, p1T, p1N, p2T, p2N)						\
	STDMETHODIMP								\
	CeE3DModel::f(p1T p1N, p2T p2N) {					\
		::gl##f(p1N, p2N);						\
		return NOERROR;							\
	}

#define _SAME3(f, p1T, p1N, p2T, p2N, p3T, p3N)					\
	STDMETHODIMP								\
	CeE3DModel::f(p1T p1N, p2T p2N, p3T p3N) {				\
		::gl##f(p1N, p2N, p3N);						\
		return NOERROR;							\
	}

#define _SAME4(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N) 			\
	STDMETHODIMP								\
	CeE3DModel::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N) {			\
		::gl##f(p1N, p2N, p3N, p4N);					\
		return NOERROR;							\
	}

#define _SAME5(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N) 		\
	STDMETHODIMP								\
	CeE3DModel::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N) {		\
		::gl##f(p1N, p2N, p3N, p4N, p5N);				\
		return NOERROR;							\
	}

#define _SAME6(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N, p6T, p6N) 									\
	STDMETHODIMP																\
	CeE3DModel::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N, p6T p6N) {									\
		::gl##f(p1N, p2N, p3N, p4N, p5N, p6N);												\
		return NOERROR;															\
	}

#define _SAME7(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N, p6T, p6N, p7T, p7N)								\
	STDMETHODIMP																\
	CeE3DModel::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N, p6T p6N, p7T p7N) {								\
		::gl##f(p1N, p2N, p3N, p4N, p5N, p6N, p7N);											\
		return NOERROR;															\
	}

#define _SAME8(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N, p6T, p6N, p7T, p7N, p8T, p8N) 						\
	STDMETHODIMP																\
	CeE3DModel::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N, p6T p6N, p7T p7N, p8T p8N) {							\
		::gl##f(p1N, p2N, p3N, p4N, p5N, p6N, p7N, p8N);										\
		return NOERROR;															\
	}

#define _SAME9(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N, p6T, p6N, p7T, p7N, p8T, p8N, p9T, p9N) 					\
	STDMETHODIMP																\
	CeE3DModel::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N, p6T p6N, p7T p7N, p8T p8N, p9T p9N) {					\
		::gl##f(p1N, p2N, p3N, p4N, p5N, p6N, p7N, p8N, p9N);										\
		return NOERROR;															\
	}

#define _SAME10(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N, p6T, p6N, p7T, p7N, p8T, p8N, p9T, p9N, p10T, p10N) 			\
	STDMETHODIMP																\
	CeE3DModel::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N, p6T p6N, p7T p7N, p8T p8N, p9T p9N, p10T p10N) {				\
		::gl##f(p1N, p2N, p3N, p4N, p5N, p6N, p7N, p8N, p9N, p10N);									\
		return NOERROR;															\
	}

_SAME2(Fogf,			GLenum, pname, GLfloat, param);
_SAME2(Fogfv,			GLenum, pname, GLfloat *, params);
_SAME2(Fogi,			GLenum, pname, GLint, param);
_SAME2(Fogiv,			GLenum, pname, GLint *, params);

_SAME3(Lightf,			GLenum, light, GLenum, pname, GLfloat, param);
_SAME3(Lightfv,			GLenum, light, GLenum, pname, GLfloat *, params);
_SAME3(Lighti,			GLenum, light, GLenum, pname, GLint, param);
_SAME3(Lightiv,			GLenum, light, GLenum, pname, GLint *, params);

_SAME3(Normal3b,		GLbyte, nx, GLbyte, ny, GLbyte, nz);
_SAME1(Normal3bv,		GLbyte *, v);
_SAME3(Normal3d,		GLdouble, nx, GLdouble, ny, GLdouble, nz);
_SAME1(Normal3dv,		GLdouble *, v);
_SAME3(Normal3f,		GLfloat, nx, GLfloat, ny, GLfloat, nz);
_SAME1(Normal3fv,		GLfloat *, v);
_SAME3(Normal3i,		GLint, nx, GLint, ny, GLint, nz);
_SAME1(Normal3iv,		GLint *, v);
_SAME3(Normal3s,		GLshort, nx, GLshort, ny, GLshort, nz);
_SAME1(Normal3sv,		GLshort *, v);
_SAME3(NormalPointer,		GLenum, type, GLsizei, stride, BYTE *, pointer);

_SAME2(RasterPos2d,		GLdouble, x, GLdouble, y);
_SAME1(RasterPos2dv,		GLdouble *, v);
_SAME2(RasterPos2f,		GLfloat, x, GLfloat, y);
_SAME1(RasterPos2fv,		GLfloat *, v);
_SAME2(RasterPos2i,		GLint, x, GLint, y);
_SAME1(RasterPos2iv,		GLint *, v);
_SAME2(RasterPos2s,		GLshort, x, GLshort, y);
_SAME1(RasterPos2sv,		GLshort *, v);
_SAME3(RasterPos3d,		GLdouble, x, GLdouble, y, GLdouble, z);
_SAME1(RasterPos3dv,		GLdouble *, v);
_SAME3(RasterPos3f,		GLfloat, x, GLfloat, y, GLfloat, z);
_SAME1(RasterPos3fv,		GLfloat *, v);
_SAME3(RasterPos3i,		GLint, x, GLint, y, GLint, z);
_SAME1(RasterPos3iv,		GLint *, v);
_SAME3(RasterPos3s,		GLshort, x, GLshort, y, GLshort, z);
_SAME1(RasterPos3sv,		GLshort *, v);
_SAME4(RasterPos4d,		GLdouble, x, GLdouble, y, GLdouble, z, GLdouble, w);
_SAME1(RasterPos4dv,		GLdouble *, v);
_SAME4(RasterPos4f,		GLfloat, x, GLfloat, y, GLfloat, z, GLfloat, w);
_SAME1(RasterPos4fv,		GLfloat *, v);
_SAME4(RasterPos4i,		GLint, x, GLint, y, GLint, z, GLint, w);
_SAME1(RasterPos4iv,		GLint *, v);
_SAME4(RasterPos4s,		GLshort, x, GLshort, y, GLshort, z, GLshort, w);
_SAME1(RasterPos4sv,		GLshort *, v);

_SAME4(Rectd,			GLdouble, x1, GLdouble, y1, GLdouble, x2, GLdouble, y2);
_SAME2(Rectdv,			GLdouble *, v1, GLdouble *, v2);
_SAME4(Rectf,			GLfloat, x1, GLfloat, y1, GLfloat, x2, GLfloat, y2);
_SAME2(Rectfv,			GLfloat *, v1, GLfloat *, v2);
_SAME4(Recti,			GLint, x1, GLint, y1, GLint, x2, GLint, y2);
_SAME2(Rectiv,			GLint *, v1, GLint *, v2);
_SAME4(Rects,			GLshort, x1, GLshort, y1, GLshort, x2, GLshort, y2);
_SAME2(Rectsv,			GLshort *, v1, GLshort *, v2);

_SAME1(TexCoord1d,		GLdouble, s);
_SAME1(TexCoord1dv,		GLdouble *, v);
_SAME1(TexCoord1f,		GLfloat, s);
_SAME1(TexCoord1fv,		GLfloat *, v);
_SAME1(TexCoord1i,		GLint, s);
_SAME1(TexCoord1iv,		GLint *, v);
_SAME1(TexCoord1s,		GLshort, s);
_SAME1(TexCoord1sv,		GLshort *, v);
_SAME2(TexCoord2d,		GLdouble, s, GLdouble, t);
_SAME1(TexCoord2dv,		GLdouble *, v);
_SAME2(TexCoord2f,		GLfloat, s, GLfloat, t);
_SAME1(TexCoord2fv,		GLfloat *, v);
_SAME2(TexCoord2i,		GLint, s, GLint, t);
_SAME1(TexCoord2iv,		GLint *, v);
_SAME2(TexCoord2s,		GLshort, s, GLshort, t);
_SAME1(TexCoord2sv,		GLshort *, v);
_SAME3(TexCoord3d,		GLdouble, s, GLdouble, t, GLdouble, r);
_SAME1(TexCoord3dv,		GLdouble *, v);
_SAME3(TexCoord3f,		GLfloat, s, GLfloat, t, GLfloat, r);
_SAME1(TexCoord3fv,		GLfloat *, v);
_SAME3(TexCoord3i,		GLint, s, GLint, t, GLint, r);
_SAME1(TexCoord3iv,		GLint *, v);
_SAME3(TexCoord3s,		GLshort, s, GLshort, t, GLshort, r);
_SAME1(TexCoord3sv,		GLshort *, v);
_SAME4(TexCoord4d,		GLdouble, s, GLdouble, t, GLdouble, r, GLdouble, q);
_SAME1(TexCoord4dv,		GLdouble *, v);
_SAME4(TexCoord4f,		GLfloat, s, GLfloat, t, GLfloat, r, GLfloat, q);
_SAME1(TexCoord4fv,		GLfloat *, v);
_SAME4(TexCoord4i,		GLint, s, GLint, t, GLint, r, GLint, q);
_SAME1(TexCoord4iv,		GLint *, v);
_SAME4(TexCoord4s,		GLshort, s, GLshort, t, GLshort, r, GLshort, q);
_SAME1(TexCoord4sv,		GLshort *, v);
_SAME4(TexCoordPointer,		GLint, size, GLenum, type, GLsizei, stride, BYTE *, pointer);

_SAME2(Vertex2d,		GLdouble, x, GLdouble, y);
_SAME1(Vertex2dv,		GLdouble *, v);
_SAME2(Vertex2f,		GLfloat, x, GLfloat, y);
_SAME1(Vertex2fv,		GLfloat *, v);
_SAME2(Vertex2i,		GLint, x, GLint, y);
_SAME1(Vertex2iv,		GLint *, v);
_SAME2(Vertex2s,		GLshort, x, GLshort, y);
_SAME1(Vertex2sv,		GLshort *, v);
_SAME3(Vertex3d,		GLdouble, x, GLdouble, y, GLdouble, z);
_SAME1(Vertex3dv,		GLdouble *, v);
_SAME3(Vertex3f,		GLfloat, x, GLfloat, y, GLfloat, z);
_SAME1(Vertex3fv,		GLfloat *, v);
_SAME3(Vertex3i,		GLint, x, GLint, y, GLint, z);
_SAME1(Vertex3iv,		GLint *, v);
_SAME3(Vertex3s,		GLshort, x, GLshort, y, GLshort, z);
_SAME1(Vertex3sv,		GLshort *, v);
_SAME4(Vertex4d,		GLdouble, x, GLdouble, y, GLdouble, z, GLdouble, w);
_SAME1(Vertex4dv,		GLdouble *, v);
_SAME4(Vertex4f,		GLfloat, x, GLfloat, y, GLfloat, z, GLfloat, w);
_SAME1(Vertex4fv,		GLfloat *, v);
_SAME4(Vertex4i,		GLint, x, GLint, y, GLint, z, GLint, w);
_SAME1(Vertex4iv,		GLint *, v);
_SAME4(Vertex4s,		GLshort, x, GLshort, y, GLshort, z, GLshort, w);
_SAME1(Vertex4sv,		GLshort *, v);
_SAME4(VertexPointer,		GLint, size, GLenum, type, GLsizei, stride, BYTE *, pointer);

#undef _SAME0
#undef _SAME1
#undef _SAME2
#undef _SAME3
#undef _SAME4
#undef _SAME5
#undef _SAME6
#undef _SAME7
#undef _SAME8
#undef _SAME9
#undef _SAME10
