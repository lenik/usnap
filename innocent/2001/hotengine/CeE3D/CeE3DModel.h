
#pragma once

class CeE3DModel :
	public CComObjectRoot,
	public CComCoClass<CeE3DModel, &CLSID_CeE3DModel>,
	public IDispatchImpl<ICeE3DModel, &IID_ICeE3DModel> {
public:
	CeE3DModel();
	virtual ~CeE3DModel();

	STDMETHOD(Fogf)(GLenum pname, GLfloat param);
	STDMETHOD(Fogfv)(GLenum pname, GLfloat *params);
	STDMETHOD(Fogi)(GLenum pname, GLint param);
	STDMETHOD(Fogiv)(GLenum pname, GLint *params);

	STDMETHOD(Lightf)(GLenum light, GLenum pname, GLfloat param);
	STDMETHOD(Lightfv)(GLenum light, GLenum pname, GLfloat *params);
	STDMETHOD(Lighti)(GLenum light, GLenum pname, GLint param);
	STDMETHOD(Lightiv)(GLenum light, GLenum pname, GLint *params);

	STDMETHOD(Normal3b)(GLbyte nx, GLbyte ny, GLbyte nz);
	STDMETHOD(Normal3bv)(GLbyte *v);
	STDMETHOD(Normal3d)(GLdouble nx, GLdouble ny, GLdouble nz);
	STDMETHOD(Normal3dv)(GLdouble *v);
	STDMETHOD(Normal3f)(GLfloat nx, GLfloat ny, GLfloat nz);
	STDMETHOD(Normal3fv)(GLfloat *v);
	STDMETHOD(Normal3i)(GLint nx, GLint ny, GLint nz);
	STDMETHOD(Normal3iv)(GLint *v);
	STDMETHOD(Normal3s)(GLshort nx, GLshort ny, GLshort nz);
	STDMETHOD(Normal3sv)(GLshort *v);
	STDMETHOD(NormalPointer)(GLenum type, GLsizei stride, BYTE *pointer);

	STDMETHOD(RasterPos2d)(GLdouble x, GLdouble y);
	STDMETHOD(RasterPos2dv)(GLdouble *v);
	STDMETHOD(RasterPos2f)(GLfloat x, GLfloat y);
	STDMETHOD(RasterPos2fv)(GLfloat *v);
	STDMETHOD(RasterPos2i)(GLint x, GLint y);
	STDMETHOD(RasterPos2iv)(GLint *v);
	STDMETHOD(RasterPos2s)(GLshort x, GLshort y);
	STDMETHOD(RasterPos2sv)(GLshort *v);
	STDMETHOD(RasterPos3d)(GLdouble x, GLdouble y, GLdouble z);
	STDMETHOD(RasterPos3dv)(GLdouble *v);
	STDMETHOD(RasterPos3f)(GLfloat x, GLfloat y, GLfloat z);
	STDMETHOD(RasterPos3fv)(GLfloat *v);
	STDMETHOD(RasterPos3i)(GLint x, GLint y, GLint z);
	STDMETHOD(RasterPos3iv)(GLint *v);
	STDMETHOD(RasterPos3s)(GLshort x, GLshort y, GLshort z);
	STDMETHOD(RasterPos3sv)(GLshort *v);
	STDMETHOD(RasterPos4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	STDMETHOD(RasterPos4dv)(GLdouble *v);
	STDMETHOD(RasterPos4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	STDMETHOD(RasterPos4fv)(GLfloat *v);
	STDMETHOD(RasterPos4i)(GLint x, GLint y, GLint z, GLint w);
	STDMETHOD(RasterPos4iv)(GLint *v);
	STDMETHOD(RasterPos4s)(GLshort x, GLshort y, GLshort z, GLshort w);
	STDMETHOD(RasterPos4sv)(GLshort *v);

	STDMETHOD(Rectd)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
	STDMETHOD(Rectdv)(GLdouble *v1, GLdouble *v2);
	STDMETHOD(Rectf)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
	STDMETHOD(Rectfv)(GLfloat *v1, GLfloat *v2);
	STDMETHOD(Recti)(GLint x1, GLint y1, GLint x2, GLint y2);
	STDMETHOD(Rectiv)(GLint *v1, GLint *v2);
	STDMETHOD(Rects)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
	STDMETHOD(Rectsv)(GLshort *v1, GLshort *v2);

	STDMETHOD(TexCoord1d)(GLdouble s);
	STDMETHOD(TexCoord1dv)(GLdouble *v);
	STDMETHOD(TexCoord1f)(GLfloat s);
	STDMETHOD(TexCoord1fv)(GLfloat *v);
	STDMETHOD(TexCoord1i)(GLint s);
	STDMETHOD(TexCoord1iv)(GLint *v);
	STDMETHOD(TexCoord1s)(GLshort s);
	STDMETHOD(TexCoord1sv)(GLshort *v);
	STDMETHOD(TexCoord2d)(GLdouble s, GLdouble t);
	STDMETHOD(TexCoord2dv)(GLdouble *v);
	STDMETHOD(TexCoord2f)(GLfloat s, GLfloat t);
	STDMETHOD(TexCoord2fv)(GLfloat *v);
	STDMETHOD(TexCoord2i)(GLint s, GLint t);
	STDMETHOD(TexCoord2iv)(GLint *v);
	STDMETHOD(TexCoord2s)(GLshort s, GLshort t);
	STDMETHOD(TexCoord2sv)(GLshort *v);
	STDMETHOD(TexCoord3d)(GLdouble s, GLdouble t, GLdouble r);
	STDMETHOD(TexCoord3dv)(GLdouble *v);
	STDMETHOD(TexCoord3f)(GLfloat s, GLfloat t, GLfloat r);
	STDMETHOD(TexCoord3fv)(GLfloat *v);
	STDMETHOD(TexCoord3i)(GLint s, GLint t, GLint r);
	STDMETHOD(TexCoord3iv)(GLint *v);
	STDMETHOD(TexCoord3s)(GLshort s, GLshort t, GLshort r);
	STDMETHOD(TexCoord3sv)(GLshort *v);
	STDMETHOD(TexCoord4d)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
	STDMETHOD(TexCoord4dv)(GLdouble *v);
	STDMETHOD(TexCoord4f)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
	STDMETHOD(TexCoord4fv)(GLfloat *v);
	STDMETHOD(TexCoord4i)(GLint s, GLint t, GLint r, GLint q);
	STDMETHOD(TexCoord4iv)(GLint *v);
	STDMETHOD(TexCoord4s)(GLshort s, GLshort t, GLshort r, GLshort q);
	STDMETHOD(TexCoord4sv)(GLshort *v);
	STDMETHOD(TexCoordPointer)(GLint size, GLenum type, GLsizei stride, BYTE *pointer);

	STDMETHOD(Vertex2d)(GLdouble x, GLdouble y);
	STDMETHOD(Vertex2dv)(GLdouble *v);
	STDMETHOD(Vertex2f)(GLfloat x, GLfloat y);
	STDMETHOD(Vertex2fv)(GLfloat *v);
	STDMETHOD(Vertex2i)(GLint x, GLint y);
	STDMETHOD(Vertex2iv)(GLint *v);
	STDMETHOD(Vertex2s)(GLshort x, GLshort y);
	STDMETHOD(Vertex2sv)(GLshort *v);
	STDMETHOD(Vertex3d)(GLdouble x, GLdouble y, GLdouble z);
	STDMETHOD(Vertex3dv)(GLdouble *v);
	STDMETHOD(Vertex3f)(GLfloat x, GLfloat y, GLfloat z);
	STDMETHOD(Vertex3fv)(GLfloat *v);
	STDMETHOD(Vertex3i)(GLint x, GLint y, GLint z);
	STDMETHOD(Vertex3iv)(GLint *v);
	STDMETHOD(Vertex3s)(GLshort x, GLshort y, GLshort z);
	STDMETHOD(Vertex3sv)(GLshort *v);
	STDMETHOD(Vertex4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	STDMETHOD(Vertex4dv)(GLdouble *v);
	STDMETHOD(Vertex4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	STDMETHOD(Vertex4fv)(GLfloat *v);
	STDMETHOD(Vertex4i)(GLint x, GLint y, GLint z, GLint w);
	STDMETHOD(Vertex4iv)(GLint *v);
	STDMETHOD(Vertex4s)(GLshort x, GLshort y, GLshort z, GLshort w);
	STDMETHOD(Vertex4sv)(GLshort *v);
	STDMETHOD(VertexPointer)(GLint size, GLenum type, GLsizei stride, BYTE *pointer);

	BEGIN_COM_MAP(CeE3DModel)
		COM_INTERFACE_ENTRY2(IDispatch, ICeE3DModel)
		COM_INTERFACE_ENTRY(ICeE3DModel)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CeE3DModel)
	DECLARE_NOT_AGGREGATABLE(CeE3DModel);

protected:
};

typedef CeE3DModel	*PCEE3DMODEL, *LPCEE3DMODEL;
