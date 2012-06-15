
#include "StdAfx.h"

#include "resource.h"

#include "CeE3D.h"
#include "CeE3DControlIdl.h"
#include "CeE3DControl.h"

#include <gl/gl.h>


CeE3DControl::CeE3DControl() {}

CeE3DControl::~CeE3DControl() {}


// ��ǰ����ɫ, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_CurrentColorIndexi(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_CURRENT_INDEX, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_CurrentColorIndexi(LONG newLONG) {
	glIndexi(newLONG);
	return NOERROR;
}


// ��ǰ����ɫ, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_CurrentColorIndexf(float *retfloat) {
	glGetFloatv(GL_CURRENT_INDEX, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_CurrentColorIndexf(float newfloat) {
	glIndexf(newfloat);
	return NOERROR;
}


// ��ǰ��������, Ĭ��ֵΪ0,0,1

STDMETHODIMP
CeE3DControl::get_CurrentTextureCoords(float *retfloat) {
	glGetFloatv(GL_CURRENT_TEXTURE_COORDS, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_CurrentTextureCoords(float newfloat) {
	//glTexCoord3f(newfloat);
	return NOERROR;
}


// ��ǰ����, Ĭ��ֵΪ0,1

STDMETHODIMP
CeE3DControl::get_CurrentNormal(float *retfloat) {
	glGetFloatv(GL_CURRENT_NORMAL, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_CurrentNormal(float newfloat) {
	//glNormal3f(newfloat);
	return NOERROR;
}


// ��ǰ��դ����, Ĭ��ֵΪ0,0,1

STDMETHODIMP
CeE3DControl::get_CurrentRasterPosition(float *retfloat) {
	glGetFloatv(GL_CURRENT_RASTER_POSITION, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_CurrentRasterPosition(float newfloat) {
	//glRasterPos3f(newfloat);
	return NOERROR;
}


// ��ǰ��դ�������, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_CurrentRasterDistance(float *retfloat) {
	glGetFloatv(GL_CURRENT_RASTER_DISTANCE, retfloat);
	return NOERROR;
}


// ��ǰ��դ����RGBAֵ, Ĭ��ֵΪ1,1,1,1

STDMETHODIMP
CeE3DControl::get_CurrentRasterColori(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_CURRENT_RASTER_COLOR, (GLint *)retLONG);
	return NOERROR;
}


// ��ǰ��դ����RGBAֵ, Ĭ��ֵΪ1,1,1,2

STDMETHODIMP
CeE3DControl::get_CurrentRasterColorf(float *retfloat) {
	glGetFloatv(GL_CURRENT_RASTER_COLOR, retfloat);
	return NOERROR;
}


// ��ǰ��դ��������ɫ, Ĭ��ֵΪ1

STDMETHODIMP
CeE3DControl::get_CurrentRasterIndexi(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_CURRENT_RASTER_INDEX, (GLint *)retLONG);
	return NOERROR;
}


// ��ǰ��դ��������ɫ, Ĭ��ֵΪ2

STDMETHODIMP
CeE3DControl::get_CurrentRasterIndexf(float *retfloat) {
	glGetFloatv(GL_CURRENT_RASTER_INDEX, retfloat);
	return NOERROR;
}


// ��ǰ��դ������������, Ĭ��ֵΪ0,0,0

STDMETHODIMP
CeE3DControl::get_CurrentRasterTexture(float *retfloat) {
	glGetFloatv(GL_CURRENT_RASTER_TEXTURE_COORDS, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_CurrentRasterTexture(float newfloat) {
	//glTexCoord3f(newfloat);
	return NOERROR;
}


// ��ǰ��դ�����Ƿ���Ч, Ĭ��ֵΪCEE3D_TRUE

STDMETHODIMP
CeE3DControl::get_CurrentRasterPositionValid(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_CURRENT_RASTER_POSITION_VALID, (GLboolean *)retBOOL);
	return NOERROR;
}


// ��ǰ��Ե��־, Ĭ��ֵΪCEE3D_TRUE

STDMETHODIMP
CeE3DControl::get_CurrentEdgeFlag(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_EDGE_FLAG, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_CurrentEdgeFlag(BOOL newBOOL) {
	glEdgeFlag(newBOOL);
	return NOERROR;
}


// ģ��ȡ�������ջ, Ĭ��ֵΪ��λ����

STDMETHODIMP
CeE3DControl::get_MatrixModelView(float *retfloat) {
	glGetFloatv(GL_MODELVIEW_MATRIX, retfloat);
	return NOERROR;
}


// ͶӰ�����ջ, Ĭ��ֵΪ��λ����

STDMETHODIMP
CeE3DControl::get_MatrixProjection(float *retfloat) {
	glGetFloatv(GL_PROJECTION_MATRIX, retfloat);
	return NOERROR;
}


// ��������ջ, Ĭ��ֵΪ��λ����

STDMETHODIMP
CeE3DControl::get_MatrixTexutre(float *retfloat) {
	glGetFloatv(GL_TEXTURE_MATRIX, retfloat);
	return NOERROR;
}


// �Ӵ�����, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_Viewport(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_VIEWPORT, (GLint *)retLONG);
	return NOERROR;
}


// ��Ȼ�������Χ, Ĭ��ֵΪ1

STDMETHODIMP
CeE3DControl::GetDepthRange(float *r1, float *r2) {
	float gr[2];
	glGetFloatv(GL_DEPTH_RANGE, gr);
	*r1 = gr[0];
	*r2 = gr[1];
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::SetDepthRange(float r1, float r2) {
	glDepthRange(r1, r2);
	return NOERROR;
}


// ģ��ȡӰ�����ջָ��, Ĭ��ֵΪ1

STDMETHODIMP
CeE3DControl::get_ModelViewStackDepth(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MODELVIEW_STACK_DEPTH, (GLint *)retLONG);
	return NOERROR;
}


// ͶӰ�����ջָ��, Ĭ��ֵΪ1

STDMETHODIMP
CeE3DControl::get_ProjectionStackDepth(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_PROJECTION_STACK_DEPTH, (GLint *)retLONG);
	return NOERROR;
}


// ��ǰ��������, Ĭ��ֵΪCEE3D_MODELVIEW

STDMETHODIMP
CeE3DControl::get_CurrentMatrixMode(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MATRIX_MODE, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_CurrentMatrixMode(LONG newLONG) {
	glMatrixMode(newLONG);
	return NOERROR;
}


// ��ǰ���߹��, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_Normalize(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_NORMALIZE, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_Normalize(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_NORMALIZE);
	} else {
		glDisable(GL_NORMALIZE);
	}
	return NOERROR;
}


// ʹ�ü���Ĳü�ƽ��, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseClipPlane(LONG index, BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_CLIP_PLANE0 + index, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseClipPlane(LONG index, BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_CLIP_PLANE0 + index);
	} else {
		glDisable(GL_CLIP_PLANE0 + index);
	}
	return NOERROR;
}


// ����ɫ, Ĭ��ֵΪ0,0,0

STDMETHODIMP
CeE3DControl::get_FogColor(float *retfloat) {
	glGetFloatv(GL_FOG_COLOR, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_FogColor(float newfloat) {
	glFogf(GL_FOG_COLOR, newfloat);
	return NOERROR;
}


// �������ɫ, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_FogColorIndex(float *retfloat) {
	glGetFloatv(GL_FOG_INDEX, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_FogColorIndex(float newfloat) {
	glFogf(GL_FOG_INDEX, newfloat);
	return NOERROR;
}


// ��Ũ��ָ��, Ĭ��ֵΪ1

STDMETHODIMP
CeE3DControl::get_FogDensity(float *retfloat) {
	glGetFloatv(GL_FOG_DENSITY, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_FogDensity(float newfloat) {
	glFogf(GL_FOG_DENSITY, newfloat);
	return NOERROR;
}


// �����ͷ��̵Ŀ�ʼ, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_FogStart(float *retfloat) {
	glGetFloatv(GL_FOG_START, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_FogStart(float newfloat) {
	glFogf(GL_FOG_START, newfloat);
	return NOERROR;
}


// �����ͷ��̵Ľ���, Ĭ��ֵΪ1

STDMETHODIMP
CeE3DControl::get_FogEnd(float *retfloat) {
	glGetFloatv(GL_FOG_END, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_FogEnd(float newfloat) {
	glFogf(GL_FOG_START, newfloat);
	return NOERROR;
}


// ��ģʽ, Ĭ��ֵΪCEE3D_EXP

STDMETHODIMP
CeE3DControl::get_CurrentFogMode(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_FOG_MODE, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_CurrentFogMode(LONG newLONG) {
	glFogi(GL_FOG_MODE, newLONG);
	return NOERROR;
}


// �Ƿ������Ч������, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseFog(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_FOG, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseFog(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_FOG);
	} else {
		glDisable(GL_FOG);
	}
	return NOERROR;
}


// ��Ӱ����ģʽ, Ĭ��ֵΪCEE3D_SMOOTH

STDMETHODIMP
CeE3DControl::get_ShadeModel(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_SHADE_MODEL, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_ShadeModel(LONG newLONG) {
	glShadeModel(newLONG);
	return NOERROR;
}


// ����ʹ�ù���, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseLighting(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_LIGHTING, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseLighting(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_LIGHTING);
	} else {
		glDisable(GL_LIGHTING);
	}
	return NOERROR;
}


// ����ϵ��, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseColorMaterial(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_COLOR_MATERIAL, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseColorMaterial(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_COLOR_MATERIAL);
	} else {
		glDisable(GL_COLOR_MATERIAL);
	}
	return NOERROR;
}


// ���ٵ�ǰ��ɫ�Ĳ���ϵ��, Ĭ��ֵΪCEE3D_AMBIENT_AND_DIFFUSE

STDMETHODIMP
CeE3DControl::get_ColorMaterialParameter(LONG face, LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_COLOR_MATERIAL_PARAMETER, (GLint *)retLONG);
	return NOERROR;
}


// ����ɫ����Ӱ������, Ĭ��ֵΪCEE3D_FRONT_AND_BACK

STDMETHODIMP
CeE3DControl::get_ColorMaterialFace(LONG face, LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_COLOR_MATERIAL_FACE, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_ColorMaterialFace(LONG face, LONG newLONG) {
	glColorMaterial(face, newLONG);
	return NOERROR;
}


// ��������ǿ��, Ĭ��ֵΪ.2,.2,.2,1

STDMETHODIMP
CeE3DControl::get_LightModelAmbient(float *retfloat) {
	glGetFloatv(GL_LIGHT_MODEL_AMBIENT, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_LightModelAmbient(float newfloat) {
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, &newfloat);
	return NOERROR;
}


// �۲���Ƿ��ڳ���, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_LightModelUseLocalViewer(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_LIGHT_MODEL_LOCAL_VIEWER, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_LightModelUseLocalViewer(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_LIGHT_MODEL_LOCAL_VIEWER);
	} else {
		glDisable(GL_LIGHT_MODEL_LOCAL_VIEWER);
	}
	return NOERROR;
}


// ����˫�����, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_LightModeUseTwoSide(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_LIGHT_MODEL_TWO_SIDE, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_LightModeUseTwoSide(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_LIGHT_MODEL_TWO_SIDE);
	} else {
		glDisable(GL_LIGHT_MODEL_TWO_SIDE);
	}
	return NOERROR;
}


// ʹ���ƶ���Դ, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseLight(LONG whichlight, BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_LIGHT0 + whichlight, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseLight(LONG whichlight, BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_LIGHT0 + whichlight);
	} else {
		glDisable(GL_LIGHT0 + whichlight);
	}
	return NOERROR;
}


// ��Դ����ɫ, Ĭ��ֵΪ1,1

STDMETHODIMP
CeE3DControl::get_LightColorIndexes(float *retfloat) {
	glGetFloatv(GL_COLOR_INDEXES, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_LightColorIndexes(float newfloat) {
	return NOERROR;
}


// ��ߴ�, Ĭ��ֵΪ1

STDMETHODIMP
CeE3DControl::get_PointSize(float *retfloat) {
	glGetFloatv(GL_POINT_SIZE, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_PointSize(float newfloat) {
	glPointSize(newfloat);
	return NOERROR;
}


// �㷴����, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseSmoothPoint(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_POINT_SMOOTH, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseSmoothPoint(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_POINT_SMOOTH);
	} else {
		glDisable(GL_POINT_SMOOTH);
	}
	return NOERROR;
}


// �߿�, Ĭ��ֵΪ1

STDMETHODIMP
CeE3DControl::get_LineWidth(float *retfloat) {
	glGetFloatv(GL_LINE_WIDTH, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_LineWidth(float newfloat) {
	glLineWidth(newfloat);
	return NOERROR;
}


// �߷�����, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseSmoothLine(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_LINE_SMOOTH, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseSmoothLine(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_LINE_SMOOTH);
	} else {
		glDisable(GL_LINE_SMOOTH);
	}
	return NOERROR;
}


// �����ͼ��, Ĭ��ֵΪ1S

STDMETHODIMP
CeE3DControl::get_StippleLinePattern(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_LINE_STIPPLE_PATTERN, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::SetStippleLinePattern(LONG factor, LONG newLONG) {
	glLineStipple((GLint)factor, (GLint)newLONG);
	return NOERROR;
}


// �ظ������ͼ��, Ĭ��ֵΪ1

STDMETHODIMP
CeE3DControl::get_StippleLineRepeat(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_LINE_STIPPLE_REPEAT, (GLint *)retLONG);
	return NOERROR;
}


// �Ƿ������, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseStippleLine(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_LINE_STIPPLE, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseStippleLine(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_LINE_STIPPLE);
	} else {
		glDisable(GL_LINE_STIPPLE);
	}
	return NOERROR;
}


// �Ƿ��޳������, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseCullFace(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_CULL_FACE, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseCullFace(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_CULL_FACE);
	} else {
		glDisable(GL_CULL_FACE);
	}
	return NOERROR;
}


// �޳�����ε���, Ĭ��ֵΪCEE3D_BACK

STDMETHODIMP
CeE3DControl::get_CullFaceMode(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_CULL_FACE_MODE, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_CullFaceMode(LONG newLONG) {
	glCullFace(newLONG);
	return NOERROR;
}


// ����γ�ǰ�����˳��ʱ��, Ĭ��ֵΪCEE3D_CCW

STDMETHODIMP
CeE3DControl::get_FrontFaceDirection(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_FRONT_FACE, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_FrontFaceDirection(LONG newLONG) {
	glFrontFace(newLONG);
	return NOERROR;
}


// ����η�����, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseSmoothPolygon(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_POLYGON_SMOOTH, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseSmoothPolygon(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_POLYGON_SMOOTH);
	} else {
		glDisable(GL_POLYGON_SMOOTH);
	}
	return NOERROR;
}


// ����ι�դ��ģʽ, Ĭ��ֵΪCEE3D_FILL

STDMETHODIMP
CeE3DControl::get_PolygonMode(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_POLYGON_MODE, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::SetPolygonMode(LONG face, LONG newLONG) {
	glPolygonMode(face, newLONG);
	return NOERROR;
}


// ��������ͼ��, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_StipplePolygonPattern(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_POLYGON_STIPPLE, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_StipplePolygonPattern(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_POLYGON_STIPPLE);
	} else {
		glDisable(GL_POLYGON_STIPPLE);
	}
	return NOERROR;
}


// �ü�����, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseScissor(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_SCISSOR_TEST, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseScissor(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_SCISSOR_TEST);
	} else {
		glDisable(GL_SCISSOR_TEST);
	}
	return NOERROR;
}


// �ü���, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_ScissorBox(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_SCISSOR_BOX, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::SetScissorBox(LONG x, LONG y, LONG width, LONG height) {
	glScissor(x, y, width, height);
	return NOERROR;
}


// ģ�����, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseStencil(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_STENCIL_TEST, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseStencil(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_STENCIL_TEST);
	} else {
		glDisable(GL_STENCIL_TEST);
	}
	return NOERROR;
}


// ģ�湦��, Ĭ��ֵΪCEE3D_ALWAYS

STDMETHODIMP
CeE3DControl::get_StencilFunc(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_STENCIL_FUNC, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_StencilFunc(LONG newLONG) {
	//glStencilFunc(newLONG);
	return NOERROR;
}


// ģ���ʶ, Ĭ��ֵΪ1....

STDMETHODIMP
CeE3DControl::get_StencilValueMask(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_STENCIL_VALUE_MASK, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_StencilValueMask(LONG newLONG) {
	glStencilMask(newLONG);
	return NOERROR;
}


// ģ�����ο�ֵ, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_StencilReference(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_STENCIL_REF, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_StencilReference(LONG newLONG) {
	LONG func;
	LONG mask;
	get_StencilFunc(&func);
	get_StencilValueMask(&mask);
	glStencilFunc(func, newLONG, mask);
	return NOERROR;
}


// ģ�����ʧ��, Ĭ��ֵΪCEE3D_KEEP

STDMETHODIMP
CeE3DControl::get_StencilFailure(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_STENCIL_FAIL, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_StencilFailure(LONG newLONG) {
	LONG fail;
	LONG zfail;
	LONG zpass;
	fail = newLONG;
	get_StencilPassFailDepth(&zfail);
	get_StencilPassPassDepth(&zpass);
	glStencilOp(fail, zfail, zpass);
	return NOERROR;
}


// ģ�����ͨ��,��ȼ���ʧ��, Ĭ��ֵΪCEE3D_KEEP

STDMETHODIMP
CeE3DControl::get_StencilPassFailDepth(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_STENCIL_PASS_DEPTH_FAIL, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_StencilPassFailDepth(LONG newLONG) {
	LONG fail;
	LONG zfail;
	LONG zpass;
	get_StencilFailure(&fail);
	zfail = newLONG;
	get_StencilPassPassDepth(&zpass);
	glStencilOp(fail, zfail, zpass);
	return NOERROR;
}


// ģ��,��ȼ���ͨ��, Ĭ��ֵΪCEE3D_KEEP

STDMETHODIMP
CeE3DControl::get_StencilPassPassDepth(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_STENCIL_PASS_DEPTH_PASS, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_StencilPassPassDepth(LONG newLONG) {
	LONG fail;
	LONG zfail;
	LONG zpass;
	get_StencilFailure(&fail);
	get_StencilPassFailDepth(&zfail);
	zpass = newLONG;
	glStencilOp(fail, zfail, zpass);
	return NOERROR;
}


// ���������, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseAlpha(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_ALPHA_TEST, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseAlpha(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_ALPHA_TEST);
	} else {
		glDisable(GL_ALPHA_TEST);
	}
	return NOERROR;
}


// �����麯��, Ĭ��ֵΪCEE3D_ALWAYS

STDMETHODIMP
CeE3DControl::get_AlphaTestFunc(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_ALPHA_TEST_FUNC, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_AlphaTestFunc(LONG newLONG) {
	LONG func;
	GLclampf ref;
	func = newLONG;
	get_AlphaTestReference(&ref);
	glAlphaFunc((GLint)func, ref);
	return NOERROR;
}


// ������ο�ֵ, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_AlphaTestReference(float *retfloat) {
	glGetFloatv(GL_ALPHA_TEST_REF, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_AlphaTestReference(float newfloat) {
	LONG func;
	GLclampf ref;
	get_AlphaTestFunc(&func);
	ref = newfloat;
	glAlphaFunc((GLint)func, ref);
	return NOERROR;
}


// ��ȼ��麯��, Ĭ��ֵΪCEE3D_LESS

STDMETHODIMP
CeE3DControl::get_DepthFunc(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_DEPTH_FUNC, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_DepthFunc(LONG newLONG) {
	glDepthFunc(newLONG);
	return NOERROR;
}


// �ں�����, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseBlend(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_BLEND, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseBlend(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_BLEND);
	} else {
		glDisable(GL_BLEND);
	}
	return NOERROR;
}


// Դ�ں�����, Ĭ��ֵΪCEE3D_ONE
// Ŀ���ںϺ���, Ĭ��ֵΪCEE3D_ZERO

STDMETHODIMP
CeE3DControl::get_BlendSourceSfactor(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_BLEND_SRC, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::get_BlendSourceDfactor(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_BLEND_SRC, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_BlendSource(LONG sfactor, LONG dfactor) {
	glBlendFunc(sfactor, dfactor);
	return NOERROR;
}


// �߼�����, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseLogicOperation(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_LOGIC_OP, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseLogicOperation(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_LOGIC_OP);
	} else {
		glDisable(GL_LOGIC_OP);
	}
	return NOERROR;
}


// �߼�����ģʽ, Ĭ��ֵΪCEE3D_COPY

STDMETHODIMP
CeE3DControl::get_LogicOperationMode(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_LOGIC_OP_MODE, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_LogicOperationMode(LONG newLONG) {
	glLogicOp(newLONG);
	return NOERROR;
}


// ��������, Ĭ��ֵΪCEE3D_TRUE

STDMETHODIMP
CeE3DControl::get_UseDither(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_DITHER, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseDither(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_DITHER);
	} else {
		glDisable(GL_DITHER);
	}
	return NOERROR;
}


// Ҫд��Ļ�����, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_DrawBuffer(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_DRAW_BUFFER, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_DrawBuffer(LONG newLONG) {
	glDrawBuffer(newLONG);
	return NOERROR;
}


// ����ɫ������λƽ���д����, Ĭ��ֵΪ1....

STDMETHODIMP
CeE3DControl::get_ColorIndexWriteMask(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_INDEX_WRITEMASK, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_ColorIndexWriteMask(LONG newLONG) {
	glIndexMask(newLONG);
	return NOERROR;
}


// д����Ȼ���, Ĭ��ֵΪCEE3D_TRUE

STDMETHODIMP
CeE3DControl::get_DepthWriteMask(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_DEPTH_WRITEMASK, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_DepthWriteMask(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_DEPTH_WRITEMASK);
	} else {
		glDisable(GL_DEPTH_WRITEMASK);
	}
	return NOERROR;
}


// д��ģ�滺��, Ĭ��ֵΪ1....

STDMETHODIMP
CeE3DControl::get_StencilWriteMask(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_STENCIL_WRITEMASK, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_StencilWriteMask(LONG newLONG) {
	glStencilMask(newLONG);
	return NOERROR;
}


// �����ɫ����RGBAֵ, Ĭ��ֵΪ0,0,0

STDMETHODIMP
CeE3DControl::get_ColorClearValue(LONG RGBA_index, float *retfloat) {
	float rgba[4];
	glGetFloatv(GL_COLOR_CLEAR_VALUE, rgba);
	*retfloat = rgba[RGBA_index];
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::SetColorClearValue(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
	return NOERROR;
}


// �����ɫָ��ֵ, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_ColorIndexClearValue(float *retfloat) {
	glGetFloatv(GL_INDEX_CLEAR_VALUE, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_ColorIndexClearValue(float newfloat) {
	glClearIndex(newfloat);
	return NOERROR;
}


// �����Ȼ���ֵ, Ĭ��ֵΪ1

STDMETHODIMP
CeE3DControl::get_DepthClearValue(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_DEPTH_CLEAR_VALUE, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_DepthClearValue(LONG newLONG) {
	glClearDepth(newLONG);
	return NOERROR;
}


// ���ģ�滺��ֵ, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_StencilClearValue(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_STENCIL_CLEAR_VALUE, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_StencilClearValue(LONG newLONG) {
	glClearStencil(newLONG);
	return NOERROR;
}


// ����ۼӻ���ֵ, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_AccumClearValue(float *retfloat) {
	glGetFloatv(GL_ACCUM_CLEAR_VALUE, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_AccumClearValue(float newfloat) {
	glClearAccum(newfloat, newfloat, newfloat, newfloat);
	return NOERROR;
}


// δ�����������, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UnpackSwapBytes(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_UNPACK_SWAP_BYTES, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UnpackSwapBytes(BOOL newBOOL) {
	glPixelStorei(GL_UNPACK_SWAP_BYTES, newBOOL);
	return NOERROR;
}


// δ����г���, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_UnpackRowLength(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_UNPACK_ROW_LENGTH, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UnpackRowLength(LONG newLONG) {
	glPixelStorei(GL_UNPACK_ROW_LENGTH, newLONG);
	return NOERROR;
}


// δ���������, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_UnpackSkipRows(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_UNPACK_SKIP_ROWS, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UnpackSkipRows(LONG newLONG) {
	glPixelStorei(GL_UNPACK_SKIP_ROWS, newLONG);
	return NOERROR;
}


// δ�����������, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_UnpackSkipPixels(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_UNPACK_SKIP_PIXELS, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UnpackSkipPixels(LONG newLONG) {
	glPixelStorei(GL_UNPACK_SKIP_PIXELS, newLONG);
	return NOERROR;
}


// δ�������, Ĭ��ֵΪ4

STDMETHODIMP
CeE3DControl::get_UnpackAlignment(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_UNPACK_ALIGNMENT, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UnpackAlignment(LONG newLONG) {
	glPixelStorei(GL_UNPACK_ALIGNMENT, newLONG);
	return NOERROR;
}


// �����������, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_PackSwapBytes(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_PACK_SWAP_BYTES, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_PackSwapBytes(BOOL newBOOL) {
	glPixelStorei(GL_PACK_SWAP_BYTES, newBOOL);
	return NOERROR;
}


// �����һ��LSB, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_PackLSBFirst(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_PACK_LSB_FIRST, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_PackLSBFirst(BOOL newBOOL) {
	glPixelStorei(GL_PACK_LSB_FIRST, newBOOL);
	return NOERROR;
}


// ����г���, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_PackRowLength(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_PACK_ROW_LENGTH, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_PackRowLength(LONG newLONG) {
	glPixelStorei(GL_PACK_ROW_LENGTH, newLONG);
	return NOERROR;
}


// ���������, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_PackSkipRows(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_PACK_SKIP_ROWS, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_PackSkipRows(LONG newLONG) {
	glPixelStorei(GL_PACK_SKIP_ROWS, newLONG);
	return NOERROR;
}


// �����������, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_PackSkipPixels(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_PACK_SKIP_PIXELS, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_PackSkipPixels(LONG newLONG) {
	glPixelStorei(GL_PACK_SKIP_PIXELS, newLONG);
	return NOERROR;
}


// �������, Ĭ��ֵΪ4

STDMETHODIMP
CeE3DControl::get_PackAlignment(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_PACK_ALIGNMENT, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_PackAlignment(LONG newLONG) {
	glPixelStorei(GL_PACK_ALIGNMENT, newLONG);
	return NOERROR;
}


// �Ƿ��ò�Ա������ɫ������ɫ, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseColorMap(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_MAP_COLOR, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseColorMap(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_MAP_COLOR);
	} else {
		glDisable(GL_MAP_COLOR);
	}
	return NOERROR;
}


// �Ƿ��ò�Ա����ģ��, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseStencilMap(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_MAP_STENCIL, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseStencilMap(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_MAP_STENCIL);
	} else {
		glDisable(GL_MAP_STENCIL);
	}
	return NOERROR;
}


// ������λ, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_IndexShift(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_INDEX_SHIFT, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_IndexShift(LONG newLONG) {
	glPixelTransferi(GL_INDEX_SHIFT, newLONG);
	return NOERROR;
}


// ����ƫ��, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_IndexOffset(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_INDEX_OFFSET, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_IndexOffset(LONG newLONG) {
	glPixelTransferi(GL_INDEX_OFFSET, newLONG);
	return NOERROR;
}


// X���ص���������, Ĭ��ֵΪ

STDMETHODIMP
CeE3DControl::get_ZoomX(float *retfloat) {
	glGetFloatv(GL_ZOOM_X, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_ZoomX(float newfloat) {
	float ZoomY;
	get_ZoomY(&ZoomY);
	glPixelZoom(newfloat, ZoomY);
	return NOERROR;
}


// Y���ص���������, Ĭ��ֵΪ

STDMETHODIMP
CeE3DControl::get_ZoomY(float *retfloat) {
	glGetFloatv(GL_ZOOM_Y, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_ZoomY(float newfloat) {
	float ZoomX;
	get_ZoomX(&ZoomX);
	glPixelZoom(ZoomX, newfloat);
	return NOERROR;
}


// ��ȡ��������Դ, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_ReadBuffer(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_READ_BUFFER, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_ReadBuffer(LONG newLONG) {
	glReadBuffer(newLONG);
	return NOERROR;
}


// ����һάӳ��, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseMap1(BOOL *retBOOL) {
	//glGetBooleanv(GL_MAP1, retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseMap1(BOOL newBOOL) {
	if (newBOOL) {
		//glEnable(GL_MAP1_x);
	} else {
		//glDisable(GL_MAP1_x);
	}
	return NOERROR;
}


// �����άӳ��, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_UseMap2(BOOL *retBOOL) {
	//glGetBooleanv(GL_MAP2_x, retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_UseMap2(BOOL newBOOL) {
	if (newBOOL) {
		//glEnable(GL_MAP2_x);
	} else {
		//glDisable(GL_MAP2_x);
	}
	return NOERROR;
}


// ��άӳ���������ڵ�, Ĭ��ֵΪ1;0,1

STDMETHODIMP
CeE3DControl::get_Map2GridDomain(float *retfloat) {
	glGetFloatv(GL_MAP2_GRID_DOMAIN, retfloat);
	return NOERROR;
}


// һάӳ���������ļ����Ŀ, Ĭ��ֵΪ1

STDMETHODIMP
CeE3DControl::get_Map1GridSegments(float *retfloat) {
	glGetFloatv(GL_MAP1_GRID_SEGMENTS, retfloat);
	return NOERROR;
}


// ��άӳ���������ļ����Ŀ, Ĭ��ֵΪ1,1

STDMETHODIMP
CeE3DControl::get_Map2GridSegments(float *retfloat) {
	glGetFloatv(GL_MAP2_GRID_SEGMENTS, retfloat);
	return NOERROR;
}


// �Ƿ������Զ���ⷨ����, Ĭ��ֵΪCEE3D_FALSE

STDMETHODIMP
CeE3DControl::get_AutoNormalize(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_AUTO_NORMAL, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_AutoNormalize(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_AUTO_NORMAL);
	} else {
		glDisable(GL_AUTO_NORMAL);
	}
	return NOERROR;
}


// ͸��У��������ģʽ, Ĭ��ֵΪCEE3D_DONT_CARE

STDMETHODIMP
CeE3DControl::get_PerspectiveCorrectionHint(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_PERSPECTIVE_CORRECTION_HINT, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_PerspectiveCorrectionHint(LONG newLONG) {
	//gl
	return NOERROR;
}

// �������������ģʽ, Ĭ��ֵΪCEE3D_DONT_CARE

STDMETHODIMP
CeE3DControl::get_PointSmoothHint(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_POINT_SMOOTH_HINT, (GLint *)retLONG);
	return NOERROR;
}


// �������ߵ�����ģʽ, Ĭ��ֵΪCEE3D_DONT_CARE

STDMETHODIMP
CeE3DControl::get_LineSmoothHint(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_LINE_SMOOTH_HINT, (GLint *)retLONG);
	return NOERROR;
}


// ����������ε�����ģʽ, Ĭ��ֵΪCEE3D_DONT_CARE

STDMETHODIMP
CeE3DControl::get_PolygonSmoothHint(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_POLYGON_SMOOTH_HINT, (GLint *)retLONG);
	return NOERROR;
}


// �������ģʽ, Ĭ��ֵΪCEE3D_DONT_CARE

STDMETHODIMP
CeE3DControl::get_FogHint(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_FOG_HINT, (GLint *)retLONG);
	return NOERROR;
}


// ��Դ��Ŀ�����ֵ, Ĭ��ֵΪ8

STDMETHODIMP
CeE3DControl::get_MaxLights(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_LIGHTS, (GLint *)retLONG);
	return NOERROR;
}


// ����ƽ������ֵ, Ĭ��ֵΪ6

STDMETHODIMP
CeE3DControl::get_MaxClipPlanes(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_CLIP_PLANES, (GLint *)retLONG);
	return NOERROR;
}


// ģ��ȡ�������ջ��������, Ĭ��ֵΪ32

STDMETHODIMP
CeE3DControl::get_MaxModelViewStackDepth(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_MODELVIEW_STACK_DEPTH, (GLint *)retLONG);
	return NOERROR;
}


// ͶӰ�����ջ��������, Ĭ��ֵΪ2

STDMETHODIMP
CeE3DControl::get_MaxProjectionStackDepth(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_PROJECTION_STACK_DEPTH, (GLint *)retLONG);
	return NOERROR;
}


// ��������ջ��������, Ĭ��ֵΪ2

STDMETHODIMP
CeE3DControl::get_MaxTextureStackDepth(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_TEXTURE_STACK_DEPTH, (GLint *)retLONG);
	return NOERROR;
}


// �����ص���λ��, Ĭ��ֵΪ4

STDMETHODIMP
CeE3DControl::get_SubPixelBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_SUBPIXEL_BITS, (GLint *)retLONG);
	return NOERROR;
}


// ����ͼ������ߴ�, Ĭ��ֵΪ64

STDMETHODIMP
CeE3DControl::get_MaxTextureSize(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_TEXTURE_SIZE, (GLint *)retLONG);
	return NOERROR;
}


// ��ʾ�б�Ƕ�׵�������, Ĭ��ֵΪ64

STDMETHODIMP
CeE3DControl::get_MaxListNesting(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_LIST_NESTING, (GLint *)retLONG);
	return NOERROR;
}


// ��ֵ��֧�ֵ���󷽳̽���, Ĭ��ֵΪ8

STDMETHODIMP
CeE3DControl::get_MaxEvalOrder(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_EVAL_ORDER, (GLint *)retLONG);
	return NOERROR;
}


// �Ӵ�֧�ֵ����ߴ�, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_MaxViewportDims(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_VIEWPORT_DIMS, (GLint *)retLONG);
	return NOERROR;
}


// ���Զ�ջ������, Ĭ��ֵΪ16

STDMETHODIMP
CeE3DControl::get_MaxAttribStackDepth(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_ATTRIB_STACK_DEPTH, (GLint *)retLONG);
	return NOERROR;
}


// ��ɫ״̬, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_InRGBAMode(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_RGBA_MODE, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_InRGBAMode(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_RGBA_MODE);
	} else {
		glDisable(GL_RGBA_MODE);
	}
	return NOERROR;
}


// ����ɫ״̬, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_InColorIndexMode(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_INDEX_MODE, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_InColorIndexMode(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_INDEX_MODE);
	} else {
		glDisable(GL_INDEX_MODE);
	}
	return NOERROR;
}


// �Ƿ�֧��˫������, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_SupportDoubleBuffer(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_DOUBLEBUFFER, (GLboolean *)retBOOL);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_SupportDoubleBuffer(BOOL newBOOL) {
	if (newBOOL) {
		glEnable(GL_DOUBLEBUFFER);
	} else {
		glDisable(GL_DOUBLEBUFFER);
	}
	return NOERROR;
}


// �Ƿ�֧�����һ�����, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_SupportStereo(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_STEREO, (GLboolean *)retBOOL);
	return NOERROR;
}


// ��������ĳߴ緶Χ, Ĭ��ֵΪ1,1

STDMETHODIMP
CeE3DControl::get_PointSizeRange(float *retfloat) {
	glGetFloatv(GL_POINT_SIZE_RANGE, retfloat);
	return NOERROR;
}


// �����������ڳߴ�Ĳ��, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_PointSizeGranularity(float *retfloat) {
	glGetFloatv(GL_POINT_SIZE_GRANULARITY, retfloat);
	return NOERROR;
}


// �������ߵĳߴ緶Χ, Ĭ��ֵΪ1,1

STDMETHODIMP
CeE3DControl::get_LineWidthRange(float *retfloat) {
	glGetFloatv(GL_LINE_WIDTH_RANGE, retfloat);
	return NOERROR;
}


// �����������ڳߴ�Ĳ��, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_LineWidthGranularity(float *retfloat) {
	glGetFloatv(GL_LINE_WIDTH_GRANULARITY, retfloat);
	return NOERROR;
}


// ��ɫ�������ĺ�ɫλƽ����Ŀ, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_RedBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_RED_BITS, (GLint *)retLONG);
	return NOERROR;
}


// ��ɫ����������ɫλƽ����Ŀ, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_GreenBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_GREEN_BITS, (GLint *)retLONG);
	return NOERROR;
}


// ��ɫ����������ɫλƽ����Ŀ, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_BlueBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_BLUE_BITS, (GLint *)retLONG);
	return NOERROR;
}


// ��ɫ�������Ħ�λƽ����Ŀ, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_AlphaBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_ALPHA_BITS, (GLint *)retLONG);
	return NOERROR;
}


// ����ɫ��������λƽ����Ŀ, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_IndexBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_INDEX_BITS, (GLint *)retLONG);
	return NOERROR;
}


// ��Ȼ�������λƽ����Ŀ, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_DepthBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_DEPTH_BITS, (GLint *)retLONG);
	return NOERROR;
}


// ģ�滺������λƽ����Ŀ, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_StencilBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_STENCIL_BITS, (GLint *)retLONG);
	return NOERROR;
}


// �ۼӻ������ĺ�ɫλƽ����Ŀ, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_AccumRedBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_ACCUM_RED_BITS, (GLint *)retLONG);
	return NOERROR;
}


// �ۼӻ���������ɫλƽ����Ŀ, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_AccumGreenBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_ACCUM_GREEN_BITS, (GLint *)retLONG);
	return NOERROR;
}


// �ۼӻ���������ɫλƽ����Ŀ, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_AccumBlueBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_ACCUM_BLUE_BITS, (GLint *)retLONG);
	return NOERROR;
}


// �ۼӻ������Ħ�λƽ����Ŀ, Ĭ��ֵΪ��

STDMETHODIMP
CeE3DControl::get_AccumAlphaBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_ACCUM_ALPHA_BITS, (GLint *)retLONG);
	return NOERROR;
}


// ��ʾ�б�����, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_CallListBase(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_LIST_BASE, (GLint *)retLONG);
	return NOERROR;
}


// ��ǰ��ʾ�б�����, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_CallListIndex(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_LIST_INDEX, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_CallListIndex(LONG newLONG) {
//	glListIndex(newLONG);
	return NOERROR;
}


// �������ʾ�б�ģʽ, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_CallListMode(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_LIST_MODE, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_CallListMode(LONG newLONG) {
	//glListMode(newLONG);
	return NOERROR;
}


// ���Զ�ջ���ָ��, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_CurrentAttribStackDepth(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_ATTRIB_STACK_DEPTH, (GLint *)retLONG);
	return NOERROR;
}


// ���ƶ�ջ���, Ĭ��ֵΪ0

STDMETHODIMP
CeE3DControl::get_CurrentNameStackDepth(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_NAME_STACK_DEPTH, (GLint *)retLONG);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_CurrentNameStackDepth(LONG newLONG) {
	//glNameStackDepth(newLONG);
	return NOERROR;
}
