
#pragma once

class CeE3DUtil:
	public CComObjectRoot,
	public CComCoClass<CeE3DUtil, &CLSID_CeE3DUtil>,
	public IDispatchImpl<ICeE3DUtil, &IID_ICeE3DUtil> {
public:
	CeE3DUtil();
	virtual ~CeE3DUtil();

	STDMETHOD(Ortho2D)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top);
	STDMETHOD(Perspective)(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar);
	STDMETHOD(PickMatrix)(GLdouble x, GLdouble y, GLdouble width, GLdouble height, GLint *viewport);
	STDMETHOD(LookAt)(GLdouble eyex, GLdouble eyey, GLdouble eyez, GLdouble centerx, GLdouble centery, GLdouble centerz, GLdouble upx, GLdouble upy, GLdouble upz);
	STDMETHOD(DeleteQuadric)(CeE3Dquadric state);
	STDMETHOD(QuadricNormals)(CeE3Dquadric quadObject, GLenum normals);
	STDMETHOD(QuadricTexture)(CeE3Dquadric quadObject, GLboolean textureCoords);
	STDMETHOD(QuadricOrientation)(CeE3Dquadric quadObject, GLenum orientation);
	STDMETHOD(QuadricDrawStyle)(CeE3Dquadric quadObject, GLenum drawStyle);
	STDMETHOD(Cylinder)(CeE3Dquadric qobj, GLdouble baseRadius, GLdouble topRadius, GLdouble height, GLint slices, GLint stacks);
	STDMETHOD(Disk)(CeE3Dquadric qobj, GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint loops);
	STDMETHOD(PartialDisk)(CeE3Dquadric qobj, GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint loops, GLdouble startAngle, GLdouble sweepAngle);
	STDMETHOD(Sphere)(CeE3Dquadric qobj, GLdouble radius, GLint slices, GLint stacks);
	STDMETHOD(QuadricCallback)(CeE3Dquadric qobj, GLenum which, LONG callbackaddr);
	STDMETHOD(DeleteTess)(CeE3Dtesselator tess);
	STDMETHOD(TessBeginPolygon)(CeE3Dtesselator tess, BYTE *polygon_data);
	STDMETHOD(TessBeginContour)(CeE3Dtesselator tess);
	STDMETHOD(TessVertex)(CeE3Dtesselator tess,GLdouble *coords, BYTE *data);
	STDMETHOD(TessEndContour)(CeE3Dtesselator tess);
	STDMETHOD(TessEndPolygon)(CeE3Dtesselator tess);
	STDMETHOD(TessProperty)(CeE3Dtesselator tess,GLenum which, GLdouble value);
	STDMETHOD(TessNormal)(CeE3Dtesselator tess, GLdouble x, GLdouble y, GLdouble z);
	STDMETHOD(TessCallback)(CeE3Dtesselator tess,GLenum which, LONG callbackaddr);
	STDMETHOD(GetTessProperty)(CeE3Dtesselator tess,GLenum which, GLdouble *value);
	STDMETHOD(DeleteNurbsRenderer)(CeE3Dnurbs nobj);
	STDMETHOD(BeginSurface)(CeE3Dnurbs nobj);
	STDMETHOD(BeginCurve)(CeE3Dnurbs nobj);
	STDMETHOD(EndCurve)(CeE3Dnurbs nobj);
	STDMETHOD(EndSurface)(CeE3Dnurbs nobj);
	STDMETHOD(BeginTrim)(CeE3Dnurbs nobj);
	STDMETHOD(EndTrim)(CeE3Dnurbs nobj);
	STDMETHOD(PwlCurve)(CeE3Dnurbs nobj, GLint count, GLfloat *array, GLint stride, GLenum type);
	STDMETHOD(NurbsCurve)(CeE3Dnurbs nobj, GLint nknots, GLfloat *knot, GLint stride, GLfloat *ctlarray, GLint order, GLenum type);
	STDMETHOD(NurbsSurface)(CeE3Dnurbs nobj, GLint sknot_count, float *sknot, GLint tknot_count, GLfloat *tknot, GLint s_stride, GLint t_stride, GLfloat *ctlarray, GLint sorder, GLint torder, GLenum type);
	STDMETHOD(LoadSamplingMatrices)(CeE3Dnurbs nobj, GLfloat *modelMatrix, GLfloat *projMatrix, GLint *viewport);
	STDMETHOD(NurbsProperty)(CeE3Dnurbs nobj, GLenum property, GLfloat value);
	STDMETHOD(GetNurbsProperty)(CeE3Dnurbs nobj, GLenum property, GLfloat *value);
	STDMETHOD(NurbsCallback)(CeE3Dnurbs nobj, GLenum which, LONG callbackaddr);

	STDMETHOD(BeginPolygon)(CeE3Dtesselator tess);
	STDMETHOD(NextContour)(CeE3Dtesselator tess,  GLenum type);
	STDMETHOD(EndPolygon)(CeE3Dtesselator tess);

	STDMETHOD(ErrorString)(GLenum errCode, GLubytes *ret);
	STDMETHOD(ErrorUnicodeString)(GLenum errCode, BSTR *ret);
	STDMETHOD(GetString)(GLenum name, BSTR *ret);
	STDMETHOD(NewQuadric)(CeE3Dquadric *ret);
	STDMETHOD(NewTess)(CeE3Dtesselator *ret);
	STDMETHOD(NewNurbsRenderer)(CeE3Dnurbs *ret);
	STDMETHOD(Project)(GLdouble objx, GLdouble objy, GLdouble objz, GLdouble *modelMatrix, GLdouble *projMatrix, GLint *viewport, GLdouble *winx, GLdouble *winy, GLdouble *winz, int *ret);
	STDMETHOD(UnProject)(GLdouble winx, GLdouble winy, GLdouble winz, GLdouble *modelMatrix, GLdouble *projMatrix, GLint *viewport, GLdouble *objx, GLdouble *objy, GLdouble *objz, int *ret);
	STDMETHOD(ScaleImage)(GLenum format, GLint widthin, GLint heightin, GLenum typein, BYTE *datain, GLint widthout, GLint heightout, GLenum typeout, BYTE *dataout, int *ret);
	STDMETHOD(Build1DMipmaps)(GLenum target, GLint components, GLint width, GLenum format, GLenum type, BYTE *data, int *ret);
	STDMETHOD(Build2DMipmaps)(GLenum target, GLint components, GLint width, GLint height, GLenum format, GLenum type, BYTE *data, int *ret);

	BEGIN_COM_MAP(CeE3DUtil)
		COM_INTERFACE_ENTRY2(IDispatch, ICeE3DUtil)
		COM_INTERFACE_ENTRY(ICeE3DUtil)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CeE3DUtil)
	DECLARE_NOT_AGGREGATABLE(CeE3DUtil)

protected:
};

typedef CeE3DUtil	*PCEE3DUTIL, *LPCEE3DUTIL;
