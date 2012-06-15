
#include "StdAfx.h"

#include "resource.h"

#include "CeE3D.h"
#include "CeE3DBase.h"

#include <gl/gl.h>

CeE3DBase::CeE3DBase() {}
CeE3DBase::~CeE3DBase() {}

#define _SAME0(f)								\
	STDMETHODIMP								\
	CeE3DBase::f() {							\
		::gl##f();							\
		return NOERROR;							\
	}

#define _SAME1(f, p1T, p1N)							\
	STDMETHODIMP								\
	CeE3DBase::f(p1T p1N) {							\
		::gl##f(p1N);							\
		return NOERROR;							\
	}

#define _SAME2(f, p1T, p1N, p2T, p2N)						\
	STDMETHODIMP								\
	CeE3DBase::f(p1T p1N, p2T p2N) {					\
		::gl##f(p1N, p2N);						\
		return NOERROR;							\
	}

#define _SAME3(f, p1T, p1N, p2T, p2N, p3T, p3N)					\
	STDMETHODIMP								\
	CeE3DBase::f(p1T p1N, p2T p2N, p3T p3N) {				\
		::gl##f(p1N, p2N, p3N);						\
		return NOERROR;							\
	}

#define _SAME4(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N) 			\
	STDMETHODIMP								\
	CeE3DBase::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N) {			\
		::gl##f(p1N, p2N, p3N, p4N);					\
		return NOERROR;							\
	}

#define _SAME5(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N) 		\
	STDMETHODIMP								\
	CeE3DBase::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N) {		\
		::gl##f(p1N, p2N, p3N, p4N, p5N);				\
		return NOERROR;							\
	}

#define _SAME6(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N, p6T, p6N) 									\
	STDMETHODIMP																\
	CeE3DBase::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N, p6T p6N) {									\
		::gl##f(p1N, p2N, p3N, p4N, p5N, p6N);												\
		return NOERROR;															\
	}

#define _SAME7(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N, p6T, p6N, p7T, p7N)								\
	STDMETHODIMP																\
	CeE3DBase::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N, p6T p6N, p7T p7N) {								\
		::gl##f(p1N, p2N, p3N, p4N, p5N, p6N, p7N);											\
		return NOERROR;															\
	}

#define _SAME8(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N, p6T, p6N, p7T, p7N, p8T, p8N) 						\
	STDMETHODIMP																\
	CeE3DBase::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N, p6T p6N, p7T p7N, p8T p8N) {							\
		::gl##f(p1N, p2N, p3N, p4N, p5N, p6N, p7N, p8N);										\
		return NOERROR;															\
	}

#define _SAME9(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N, p6T, p6N, p7T, p7N, p8T, p8N, p9T, p9N) 					\
	STDMETHODIMP																\
	CeE3DBase::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N, p6T p6N, p7T p7N, p8T p8N, p9T p9N) {						\
		::gl##f(p1N, p2N, p3N, p4N, p5N, p6N, p7N, p8N, p9N);										\
		return NOERROR;															\
	}

#define _SAME10(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N, p6T, p6N, p7T, p7N, p8T, p8N, p9T, p9N, p10T, p10N) 			\
	STDMETHODIMP																\
	CeE3DBase::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N, p6T p6N, p7T p7N, p8T p8N, p9T p9N, p10T p10N) {				\
		::gl##f(p1N, p2N, p3N, p4N, p5N, p6N, p7N, p8N, p9N, p10N);									\
		return NOERROR;															\
	}

_SAME2(Accum,			GLenum, op, GLfloat, value)
_SAME2(AlphaFunc,		GLenum, func, GLclampf, ref);
_SAME1(ArrayElement,		GLint, i)
_SAME1(Begin,			GLenum, mode)
_SAME2(BindTexture,		GLenum, target, GLuint, texture)
_SAME7(Bitmap,			GLsizei, width, GLsizei, height, GLfloat, xorig, GLfloat, yorig, GLfloat, xmove, GLfloat, ymove, GLubyte *, bitmap);
_SAME2(BlendFunc,		GLenum, sfactor, GLenum, dfactor);
_SAME1(CallList,		GLuint, list);
_SAME3(CallLists,		GLsizei, n, GLenum, type, BYTE *, lists);
_SAME1(Clear,			GLbitfield, mask);
_SAME4(ClearAccum,		GLfloat, red, GLfloat, green, GLfloat, blue, GLfloat, alpha);
_SAME4(ClearColor,		GLclampf, red, GLclampf, green, GLclampf, blue, GLclampf, alpha);
_SAME1(ClearDepth,		GLclampd, depth);
_SAME1(ClearIndex,		GLfloat, c);
_SAME1(ClearStencil,		GLint, s);
_SAME2(ClipPlane,		GLenum, plane, GLdouble*, equation);
_SAME3(Color3b,			GLbyte, red, GLbyte, green, GLbyte, blue);
_SAME1(Color3bv,		GLbyte *, v);
_SAME3(Color3d,			GLdouble, red, GLdouble, green, GLdouble, blue);
_SAME1(Color3dv,		GLdouble *, v);
_SAME3(Color3f,			GLfloat, red, GLfloat, green, GLfloat, blue);
_SAME1(Color3fv,		GLfloat *, v);
_SAME3(Color3i,			GLint, red, GLint, green, GLint, blue);
_SAME1(Color3iv,		GLint *, v);
_SAME3(Color3s,			GLshort, red, GLshort, green, GLshort, blue);
_SAME1(Color3sv,		GLshort *, v);
_SAME3(Color3ub,		GLubyte, red, GLubyte, green, GLubyte, blue);
_SAME1(Color3ubv,		GLubyte *, v);
_SAME3(Color3ui,		GLuint, red, GLuint, green, GLuint, blue);
_SAME1(Color3uiv,		GLuint *, v);
_SAME3(Color3us,		GLushort, red, GLushort, green, GLushort, blue);
_SAME1(Color3usv,		GLushort *, v);
_SAME4(Color4b,			GLbyte, red, GLbyte, green, GLbyte, blue, GLbyte, alpha);
_SAME1(Color4bv,		GLbyte *, v);
_SAME4(Color4d,			GLdouble, red, GLdouble, green, GLdouble, blue, GLdouble, alpha);
_SAME1(Color4dv,		GLdouble *, v);
_SAME4(Color4f,			GLfloat, red, GLfloat, green, GLfloat, blue, GLfloat, alpha);
_SAME1(Color4fv,		GLfloat *, v);
_SAME4(Color4i,			GLint, red, GLint, green, GLint, blue, GLint, alpha);
_SAME1(Color4iv,		GLint *, v);
_SAME4(Color4s,			GLshort, red, GLshort, green, GLshort, blue, GLshort, alpha);
_SAME1(Color4sv,		GLshort *, v);
_SAME4(Color4ub,		GLubyte, red, GLubyte, green, GLubyte, blue, GLubyte, alpha);
_SAME1(Color4ubv,		GLubyte *, v);
_SAME4(Color4ui,		GLuint, red, GLuint, green, GLuint, blue, GLuint, alpha);
_SAME1(Color4uiv,		GLuint *, v);
_SAME4(Color4us,		GLushort, red, GLushort, green, GLushort, blue, GLushort, alpha);
_SAME1(Color4usv,		GLushort *, v);
_SAME4(ColorMask,		GLboolean, red, GLboolean, green, GLboolean, blue, GLboolean, alpha);
_SAME2(ColorMaterial,		GLenum, face, GLenum, mode);
_SAME4(ColorPointer,		GLint, size, GLenum, type, GLsizei, stride, BYTE *, pointer);
_SAME5(CopyPixels,		GLint, x, GLint, y, GLsizei, width, GLsizei, height, GLenum, type);
_SAME7(CopyTexImage1D,		GLenum, target, GLint, level, GLenum, internalFormat, GLint, x, GLint, y, GLsizei, width, GLint, border);
_SAME8(CopyTexImage2D,		GLenum, target, GLint, level, GLenum, internalFormat, GLint, x, GLint, y, GLsizei, width, GLsizei, height, GLint, border);
_SAME6(CopyTexSubImage1D,	GLenum, target, GLint, level, GLint, xoffset, GLint, x, GLint, y, GLsizei, width);
_SAME8(CopyTexSubImage2D,	GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLint, x, GLint, y, GLsizei, width, GLsizei, height);
_SAME1(CullFace,		GLenum, mode);
_SAME2(DeleteLists,		GLuint, list, GLsizei, range);
_SAME2(DeleteTextures,		GLsizei, n, GLuint *, textures);
_SAME1(DepthFunc,		GLenum, func);
_SAME1(DepthMask,		GLboolean, flag);
_SAME2(DepthRange,		GLclampd, zNear, GLclampd, zFar);
_SAME1(Disable,			GLenum, cap);
_SAME1(DisableClientState,	GLenum, array);
_SAME3(DrawArrays,		GLenum, mode, GLint, first, GLsizei, count);
_SAME1(DrawBuffer,		GLenum, mode);
_SAME4(DrawElements,		GLenum, mode, GLsizei, count, GLenum, type, BYTE *, indices);
_SAME5(DrawPixels,		GLsizei, width, GLsizei, height, GLenum, format, GLenum, type, BYTE *, pixels);
_SAME1(EdgeFlag,		GLboolean, flag);
_SAME2(EdgeFlagPointer,		GLsizei, stride, BYTE *, pointer);
_SAME1(EdgeFlagv,		GLboolean *, flag);
_SAME1(Enable,			GLenum, cap);
_SAME1(EnableClientState,	GLenum, array);
_SAME0(End);
_SAME0(EndList);
_SAME1(EvalCoord1d,		GLdouble, u);
_SAME1(EvalCoord1dv,		GLdouble *, u);
_SAME1(EvalCoord1f,		GLfloat, u);
_SAME1(EvalCoord1fv,		GLfloat *, u);
_SAME2(EvalCoord2d,		GLdouble, u, GLdouble, v);
_SAME1(EvalCoord2dv,		GLdouble *, u);
_SAME2(EvalCoord2f,		GLfloat, u, GLfloat, v);
_SAME1(EvalCoord2fv,		GLfloat *, u);
_SAME3(EvalMesh1,		GLenum, mode, GLint, i1, GLint, i2);
_SAME5(EvalMesh2,		GLenum, mode, GLint, i1, GLint, i2, GLint, j1, GLint, j2);
_SAME1(EvalPoint1,		GLint, i);
_SAME2(EvalPoint2,		GLint, i, GLint, j);
_SAME3(FeedbackBuffer,		GLsizei, size, GLenum, type, GLfloat *, buffer);
_SAME0(Finish);
_SAME0(Flush);
_SAME1(FrontFace,		GLenum, mode);
_SAME6(Frustum,			GLdouble, left, GLdouble, right, GLdouble, bottom, GLdouble, top, GLdouble, zNear, GLdouble, zFar);
_SAME2(GenTextures,		GLsizei, n, GLuint *, textures);
_SAME2(Hint,			GLenum, target, GLenum, mode);
_SAME1(IndexMask,		GLuint, mask);
_SAME3(IndexPointer,		GLenum, type, GLsizei, stride, BYTE *, pointer);
_SAME1(Indexd,			GLdouble, c);
_SAME1(Indexdv,			GLdouble *, c);
_SAME1(Indexf,			GLfloat, c);
_SAME1(Indexfv,			GLfloat *, c);
_SAME1(Indexi,			GLint, c);
_SAME1(Indexiv,			GLint *, c);
_SAME1(Indexs,			GLshort, c);
_SAME1(Indexsv,			GLshort *, c);
_SAME1(Indexub,			GLubyte, c);
_SAME1(Indexubv,		GLubyte *, c);
_SAME0(InitNames);
_SAME3(InterleavedArrays,	GLenum, format, GLsizei, stride, BYTE *, pointer);

_SAME2(LightModelf,		GLenum, pname, GLfloat, param);
_SAME2(LightModelfv,		GLenum, pname, GLfloat *, params);
_SAME2(LightModeli,		GLenum, pname, GLint, param);
_SAME2(LightModeliv,		GLenum, pname, GLint *, params);

_SAME2(LineStipple,		GLint, factor, GLushort, pattern);
_SAME1(LineWidth,		GLfloat, width);
_SAME1(ListBase,		GLuint, base);
_SAME0(LoadIdentity);
_SAME1(LoadMatrixd,		GLdouble *, m);
_SAME1(LoadMatrixf,		GLfloat *, m);
_SAME1(LoadName,		GLuint, name);
_SAME1(LogicOp,			GLenum, opcode);
_SAME6(Map1d,			GLenum, target, GLdouble, u1, GLdouble, u2, GLint, stride, GLint, order, GLdouble *, points);
_SAME6(Map1f,			GLenum, target, GLfloat, u1, GLfloat, u2, GLint, stride, GLint, order, GLfloat *, points);
_SAME10(Map2d,			GLenum, target, GLdouble, u1, GLdouble, u2, GLint, ustride, GLint, uorder, GLdouble, v1, GLdouble, v2, GLint, vstride, GLint, vorder, GLdouble *, points);
_SAME10(Map2f,			GLenum, target, GLfloat, u1, GLfloat, u2, GLint, ustride, GLint, uorder, GLfloat, v1, GLfloat, v2, GLint, vstride, GLint, vorder, GLfloat *, points);
_SAME3(MapGrid1d,		GLint, un, GLdouble, u1, GLdouble, u2);
_SAME3(MapGrid1f,		GLint, un, GLfloat, u1, GLfloat, u2);
_SAME6(MapGrid2d,		GLint, un, GLdouble, u1, GLdouble, u2, GLint, vn, GLdouble, v1, GLdouble, v2);
_SAME6(MapGrid2f,		GLint, un, GLfloat, u1, GLfloat, u2, GLint, vn, GLfloat, v1, GLfloat, v2);
_SAME3(Materialf,		GLenum, face, GLenum, pname, GLfloat, param);
_SAME3(Materialfv,		GLenum, face, GLenum, pname, GLfloat *, params);
_SAME3(Materiali,		GLenum, face, GLenum, pname, GLint, param);
_SAME3(Materialiv,		GLenum, face, GLenum, pname, GLint *, params);
_SAME1(MatrixMode,		GLenum, mode);
_SAME1(MultMatrixd,		GLdouble *, m);
_SAME1(MultMatrixf,		GLfloat *, m);
_SAME2(NewList,			GLuint, list, GLenum, mode);
_SAME6(Ortho,			GLdouble, left, GLdouble, right, GLdouble, bottom, GLdouble, top, GLdouble, zNear, GLdouble, zFar);
_SAME1(PassThrough,		GLfloat, token);
_SAME3(PixelMapfv,		GLenum, map, GLsizei, mapsize, GLfloat *, values);
_SAME3(PixelMapuiv,		GLenum, map, GLsizei, mapsize, GLuint *, values);
_SAME3(PixelMapusv,		GLenum, map, GLsizei, mapsize, GLushort *, values);
_SAME2(PixelStoref,		GLenum, pname, GLfloat, param);
_SAME2(PixelStorei,		GLenum, pname, GLint, param);
_SAME2(PixelTransferf,		GLenum, pname, GLfloat, param);
_SAME2(PixelTransferi,		GLenum, pname, GLint, param);
_SAME2(PixelZoom,		GLfloat, xfactor, GLfloat, yfactor);
_SAME1(PointSize,		GLfloat, size);
_SAME2(PolygonMode,		GLenum, face, GLenum, mode);
_SAME2(PolygonOffset,		GLfloat, factor, GLfloat, units);
_SAME1(PolygonStipple,		GLubyte *, mask);
_SAME0(PopAttrib);
_SAME0(PopClientAttrib);
_SAME0(PopMatrix);
_SAME0(PopName);
_SAME3(PrioritizeTextures,	GLsizei, n, GLuint *, textures, GLclampf *, priorities);
_SAME1(PushAttrib,		GLbitfield, mask);
_SAME1(PushClientAttrib,	GLbitfield, mask);
_SAME0(PushMatrix);
_SAME1(PushName,		GLuint, name);
_SAME1(ReadBuffer,		GLenum, mode);
_SAME7(ReadPixels,		GLint, x, GLint, y, GLsizei, width, GLsizei, height, GLenum, format, GLenum, type, BYTE *, pixels);
_SAME4(Rotated,			GLdouble, angle, GLdouble, x, GLdouble, y, GLdouble, z);
_SAME4(Rotatef,			GLfloat, angle, GLfloat, x, GLfloat, y, GLfloat, z);
_SAME3(Scaled,			GLdouble, x, GLdouble, y, GLdouble, z);
_SAME3(Scalef,			GLfloat, x, GLfloat, y, GLfloat, z);
_SAME4(Scissor,			GLint, x, GLint, y, GLsizei, width, GLsizei, height);
_SAME2(SelectBuffer,		GLsizei, size, GLuint *, buffer);
_SAME1(ShadeModel,		GLenum, mode);
_SAME3(StencilFunc,		GLenum, func, GLint, ref, GLuint, mask);
_SAME1(StencilMask,		GLuint, mask);
_SAME3(StencilOp,		GLenum, fail, GLenum, zfail, GLenum, zpass);

_SAME3(TexEnvf,			GLenum, target, GLenum, pname, GLfloat, param);
_SAME3(TexEnvfv,		GLenum, target, GLenum, pname, GLfloat *, params);
_SAME3(TexEnvi,			GLenum, target, GLenum, pname, GLint, param);
_SAME3(TexEnviv,		GLenum, target, GLenum, pname, GLint *, params);
_SAME3(TexGend,			GLenum, coord, GLenum, pname, GLdouble, param);
_SAME3(TexGendv,		GLenum, coord, GLenum, pname, GLdouble *, params);
_SAME3(TexGenf,			GLenum, coord, GLenum, pname, GLfloat, param);
_SAME3(TexGenfv,		GLenum, coord, GLenum, pname, GLfloat *, params);
_SAME3(TexGeni,			GLenum, coord, GLenum, pname, GLint, param);
_SAME3(TexGeniv,		GLenum, coord, GLenum, pname, GLint *, params);
_SAME8(TexImage1D,		GLenum, target, GLint, level, GLint, internalformat, GLsizei, width, GLint, border, GLenum, format, GLenum, type, BYTE *, pixels);
_SAME9(TexImage2D,		GLenum, target, GLint, level, GLint, internalformat, GLsizei, width, GLsizei, height, GLint, border, GLenum, format, GLenum, type, BYTE *, pixels);
_SAME3(TexParameterf,		GLenum, target, GLenum, pname, GLfloat, param);
_SAME3(TexParameterfv,		GLenum, target, GLenum, pname, GLfloat *, params);
_SAME3(TexParameteri,		GLenum, target, GLenum, pname, GLint, param);
_SAME3(TexParameteriv,		GLenum, target, GLenum, pname, GLint *, params);
_SAME7(TexSubImage1D,		GLenum, target, GLint, level, GLint, xoffset, GLsizei, width, GLenum, format, GLenum, type, BYTE *, pixels);
_SAME9(TexSubImage2D,		GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLsizei, width, GLsizei, height, GLenum, format, GLenum, type, BYTE *, pixels);
_SAME3(Translated,		GLdouble, x, GLdouble, y, GLdouble, z);
_SAME3(Translatef,		GLfloat, x, GLfloat, y, GLfloat, z);
_SAME4(Viewport,		GLint, x, GLint, y, GLsizei, width, GLsizei, height);

STDMETHODIMP
CeE3DBase::AreTexturesResident(GLsizei n, GLuint *textures, GLboolean *residences, GLboolean *retval) {
	*retval = glAreTexturesResident(n, textures, residences);
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GenLists(GLsizei range, GLuint *retval) {
	*retval = glGenLists(range);
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetBooleanv(GLenum pname, GLboolean *ret) {
	GLboolean r;
	glGetBooleanv(pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetClipPlane(GLenum pname, GLdouble *ret) {
	GLdouble r;
	glGetClipPlane(pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetDoublev(GLenum pname, GLdouble *ret) {
	GLdouble r;
	glGetDoublev(pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetFloatv(GLenum pname, GLfloat *ret) {
	GLfloat r;
	glGetFloatv(pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetIntegerv(GLenum pname, GLint *ret) {
	GLint r;
	glGetIntegerv(pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetLightfv(GLenum light, GLenum pname, GLfloat *ret) {
	GLfloat r;
	glGetLightfv(light, pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetLightiv(GLenum light, GLenum pname, GLint *ret) {
	GLint r;
	glGetLightiv(light, pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetMapdv(GLenum target, GLenum query, GLdouble *ret) {
	GLdouble r;
	glGetMapdv(target, query, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetMapfv(GLenum target, GLenum query, GLfloat *ret) {
	GLfloat r;
	glGetMapfv(target, query, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetMapiv(GLenum target, GLenum query, GLint *ret) {
	GLint r;
	glGetMapiv(target, query, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetMaterialfv(GLenum face, GLenum pname, GLfloat *ret) {
	GLfloat r;
	glGetMaterialfv(face, pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetMaterialiv(GLenum face, GLenum pname, GLint *ret) {
	GLint r;
	glGetMaterialiv(face, pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetPixelMapfv(GLenum map, GLfloat *ret) {
	GLfloat r;
	glGetPixelMapfv(map, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetPixelMapuiv(GLenum map, GLuint *ret) {
	GLuint r;
	glGetPixelMapuiv(map, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetPixelMapusv(GLenum map, GLushort *ret) {
	GLushort r;
	glGetPixelMapusv(map, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetPolygonStipple(GLubyte *ret) {
	GLubyte r;
	glGetPolygonStipple(&r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetTexEnvfv(GLenum target, GLenum pname, GLfloat *ret) {
	GLfloat r;
	glGetTexEnvfv(target, pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetTexEnviv(GLenum target, GLenum pname, GLint *ret) {
	GLint r;
	glGetTexEnviv(target, pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetTexGendv(GLenum coord, GLenum pname, GLdouble *ret) {
	GLdouble r;
	glGetTexGendv(coord, pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetTexGenfv(GLenum coord, GLenum pname, GLfloat *ret) {
	GLfloat r;
	glGetTexGenfv(coord, pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetTexGeniv(GLenum coord, GLenum pname, GLint *ret) {
	GLint r;
	glGetTexGeniv(coord, pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetTexImage(GLenum target, GLint level, GLenum format, GLenum type, BYTE *ret) {
	GLbyte r;
	glGetTexImage(target, level, format, type, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *ret) {
	GLfloat r;
	glGetTexLevelParameterfv(target, level, pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *ret) {
	GLint r;
	glGetTexLevelParameteriv(target, level, pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetTexParameterfv(GLenum target, GLenum pname, GLfloat *ret) {
	GLfloat r;
	glGetTexParameterfv(target, pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetTexParameteriv(GLenum target, GLenum pname, GLint *ret) {
	GLint r;
	glGetTexParameteriv(target, pname, &r);
	*ret = r;
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetError(GLenum *retval) {
	*retval = glGetError();
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetString(GLenum name, BSTR *retval) {
	*retval = (BSTR)glGetString(name);
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::IsEnabled(GLenum cap, GLboolean *retval) {
	*retval = glIsEnabled(cap);
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::IsList(GLuint list, GLboolean *retval) {
	*retval = glIsList(list);
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::IsTexture(GLuint texture, GLboolean *retval) {
	*retval = glIsTexture(texture);
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::RenderMode(GLenum mode, GLint *retval) {
	*retval = glRenderMode(mode);
	return NOERROR;
}

STDMETHODIMP
CeE3DBase::GetPointerv(GLenum pname, LONG *params) {
	glGetPointerv(pname, (LPVOID *)params);
	return NOERROR;
}

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
