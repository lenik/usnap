
#include "StdAfx.h"

#include "resource.h"

#include "CeE3D.h"
#include "CeE3DControlIdl.h"
#include "CeE3DControl.h"

#include <gl/gl.h>


CeE3DControl::CeE3DControl() {}

CeE3DControl::~CeE3DControl() {}


// 当前索引色, 默认值为0

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


// 当前索引色, 默认值为0

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


// 当前纹理坐标, 默认值为0,0,1

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


// 当前法线, 默认值为0,1

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


// 当前光栅坐标, 默认值为0,0,1

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


// 当前光栅坐标距离, 默认值为0

STDMETHODIMP
CeE3DControl::get_CurrentRasterDistance(float *retfloat) {
	glGetFloatv(GL_CURRENT_RASTER_DISTANCE, retfloat);
	return NOERROR;
}


// 当前光栅坐标RGBA值, 默认值为1,1,1,1

STDMETHODIMP
CeE3DControl::get_CurrentRasterColori(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_CURRENT_RASTER_COLOR, (GLint *)retLONG);
	return NOERROR;
}


// 当前光栅坐标RGBA值, 默认值为1,1,1,2

STDMETHODIMP
CeE3DControl::get_CurrentRasterColorf(float *retfloat) {
	glGetFloatv(GL_CURRENT_RASTER_COLOR, retfloat);
	return NOERROR;
}


// 当前光栅坐标索引色, 默认值为1

STDMETHODIMP
CeE3DControl::get_CurrentRasterIndexi(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_CURRENT_RASTER_INDEX, (GLint *)retLONG);
	return NOERROR;
}


// 当前光栅坐标索引色, 默认值为2

STDMETHODIMP
CeE3DControl::get_CurrentRasterIndexf(float *retfloat) {
	glGetFloatv(GL_CURRENT_RASTER_INDEX, retfloat);
	return NOERROR;
}


// 当前光栅坐标纹理坐标, 默认值为0,0,0

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


// 当前光栅坐标是否有效, 默认值为CEE3D_TRUE

STDMETHODIMP
CeE3DControl::get_CurrentRasterPositionValid(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_CURRENT_RASTER_POSITION_VALID, (GLboolean *)retBOOL);
	return NOERROR;
}


// 当前边缘标志, 默认值为CEE3D_TRUE

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


// 模型取景矩阵堆栈, 默认值为单位矩阵

STDMETHODIMP
CeE3DControl::get_MatrixModelView(float *retfloat) {
	glGetFloatv(GL_MODELVIEW_MATRIX, retfloat);
	return NOERROR;
}


// 投影矩阵堆栈, 默认值为单位矩阵

STDMETHODIMP
CeE3DControl::get_MatrixProjection(float *retfloat) {
	glGetFloatv(GL_PROJECTION_MATRIX, retfloat);
	return NOERROR;
}


// 纹理矩阵堆栈, 默认值为单位矩阵

STDMETHODIMP
CeE3DControl::get_MatrixTexutre(float *retfloat) {
	glGetFloatv(GL_TEXTURE_MATRIX, retfloat);
	return NOERROR;
}


// 视窗坐标, 默认值为无

STDMETHODIMP
CeE3DControl::get_Viewport(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_VIEWPORT, (GLint *)retLONG);
	return NOERROR;
}


// 深度缓冲区范围, 默认值为1

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


// 模型取影矩阵堆栈指针, 默认值为1

STDMETHODIMP
CeE3DControl::get_ModelViewStackDepth(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MODELVIEW_STACK_DEPTH, (GLint *)retLONG);
	return NOERROR;
}


// 投影矩阵堆栈指针, 默认值为1

STDMETHODIMP
CeE3DControl::get_ProjectionStackDepth(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_PROJECTION_STACK_DEPTH, (GLint *)retLONG);
	return NOERROR;
}


// 当前矩阵类型, 默认值为CEE3D_MODELVIEW

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


// 当前法线规格化, 默认值为CEE3D_FALSE

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


// 使用激活的裁减平面, 默认值为CEE3D_FALSE

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


// 雾颜色, 默认值为0,0,0

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


// 雾的索引色, 默认值为0

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


// 雾浓度指数, 默认值为1

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


// 雾线型方程的开始, 默认值为0

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


// 雾线型方程的结束, 默认值为1

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


// 雾模式, 默认值为CEE3D_EXP

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


// 是否进行雾效果计算, 默认值为CEE3D_FALSE

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


// 阴影处理模式, 默认值为CEE3D_SMOOTH

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


// 允许使用光照, 默认值为CEE3D_FALSE

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


// 材质系数, 默认值为CEE3D_FALSE

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


// 跟踪当前颜色的材质系数, 默认值为CEE3D_AMBIENT_AND_DIFFUSE

STDMETHODIMP
CeE3DControl::get_ColorMaterialParameter(LONG face, LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_COLOR_MATERIAL_PARAMETER, (GLint *)retLONG);
	return NOERROR;
}


// 受颜色跟踪影响的外观, 默认值为CEE3D_FRONT_AND_BACK

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


// 场景泛光强度, 默认值为.2,.2,.2,1

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


// 观察点是否在场内, 默认值为CEE3D_FALSE

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


// 采用双面光照, 默认值为CEE3D_FALSE

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


// 使用制定光源, 默认值为CEE3D_FALSE

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


// 光源索引色, 默认值为1,1

STDMETHODIMP
CeE3DControl::get_LightColorIndexes(float *retfloat) {
	glGetFloatv(GL_COLOR_INDEXES, retfloat);
	return NOERROR;
}

STDMETHODIMP
CeE3DControl::put_LightColorIndexes(float newfloat) {
	return NOERROR;
}


// 点尺寸, 默认值为1

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


// 点反走样, 默认值为CEE3D_FALSE

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


// 线宽, 默认值为1

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


// 线反走样, 默认值为CEE3D_FALSE

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


// 线填充图案, 默认值为1S

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


// 重复线填充图案, 默认值为1

STDMETHODIMP
CeE3DControl::get_StippleLineRepeat(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_LINE_STIPPLE_REPEAT, (GLint *)retLONG);
	return NOERROR;
}


// 是否线填充, 默认值为CEE3D_FALSE

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


// 是否剔除多边形, 默认值为CEE3D_FALSE

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


// 剔除多边形的面, 默认值为CEE3D_BACK

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


// 多边形朝前的面的顺逆时针, 默认值为CEE3D_CCW

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


// 多边形反走样, 默认值为CEE3D_FALSE

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


// 多边形光栅化模式, 默认值为CEE3D_FILL

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


// 多边形填充图案, 默认值为CEE3D_FALSE

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


// 裁减检验, 默认值为CEE3D_FALSE

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


// 裁减框, 默认值为无

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


// 模版检验, 默认值为CEE3D_FALSE

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


// 模版功能, 默认值为CEE3D_ALWAYS

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


// 模版标识, 默认值为1....

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


// 模版检验参考值, 默认值为0

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


// 模版检验失败, 默认值为CEE3D_KEEP

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


// 模版检验通过,深度检验失败, 默认值为CEE3D_KEEP

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


// 模版,深度检验通过, 默认值为CEE3D_KEEP

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


// 允许α检验, 默认值为CEE3D_FALSE

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


// α检验函数, 默认值为CEE3D_ALWAYS

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


// α检验参考值, 默认值为0

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


// 深度检验函数, 默认值为CEE3D_LESS

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


// 融合运算, 默认值为CEE3D_FALSE

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


// 源融合运算, 默认值为CEE3D_ONE
// 目标融合函数, 默认值为CEE3D_ZERO

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


// 逻辑操作, 默认值为CEE3D_FALSE

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


// 逻辑操作模式, 默认值为CEE3D_COPY

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


// 抖动操作, 默认值为CEE3D_TRUE

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


// 要写入的缓冲区, 默认值为无

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


// 索引色缓存区位平面的写屏蔽, 默认值为1....

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


// 写入深度缓存, 默认值为CEE3D_TRUE

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


// 写入模版缓存, 默认值为1....

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


// 清除颜色缓存RGBA值, 默认值为0,0,0

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


// 清除颜色指数值, 默认值为0

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


// 清除深度缓存值, 默认值为1

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


// 清除模版缓存值, 默认值为0

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


// 清除累加缓存值, 默认值为0

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


// 未打包交换比特, 默认值为CEE3D_FALSE

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


// 未打包行长度, 默认值为0

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


// 未打包忽略行, 默认值为0

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


// 未打包忽略像素, 默认值为0

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


// 未打包对齐, 默认值为4

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


// 打包交换比特, 默认值为CEE3D_FALSE

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


// 打包第一个LSB, 默认值为CEE3D_FALSE

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


// 打包行长度, 默认值为0

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


// 打包忽略行, 默认值为0

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


// 打包忽略像素, 默认值为0

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


// 打包对齐, 默认值为4

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


// 是否用查对表代替颜色或索引色, 默认值为CEE3D_FALSE

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


// 是否用查对表代替模版, 默认值为CEE3D_FALSE

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


// 索引移位, 默认值为0

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


// 索引偏移, 默认值为0

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


// X像素的缩放因子, 默认值为

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


// Y像素的缩放因子, 默认值为

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


// 读取缓存区资源, 默认值为无

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


// 允许一维映射, 默认值为CEE3D_FALSE

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


// 允许二维映射, 默认值为CEE3D_FALSE

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


// 二维映射的网格与节点, 默认值为1;0,1

STDMETHODIMP
CeE3DControl::get_Map2GridDomain(float *retfloat) {
	glGetFloatv(GL_MAP2_GRID_DOMAIN, retfloat);
	return NOERROR;
}


// 一维映射的网格域的间隔数目, 默认值为1

STDMETHODIMP
CeE3DControl::get_Map1GridSegments(float *retfloat) {
	glGetFloatv(GL_MAP1_GRID_SEGMENTS, retfloat);
	return NOERROR;
}


// 二维映射的网格域的间隔数目, 默认值为1,1

STDMETHODIMP
CeE3DControl::get_Map2GridSegments(float *retfloat) {
	glGetFloatv(GL_MAP2_GRID_SEGMENTS, retfloat);
	return NOERROR;
}


// 是否允许自动求解法向量, 默认值为CEE3D_FALSE

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


// 透视校正的隐含模式, 默认值为CEE3D_DONT_CARE

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

// 反走样点的隐含模式, 默认值为CEE3D_DONT_CARE

STDMETHODIMP
CeE3DControl::get_PointSmoothHint(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_POINT_SMOOTH_HINT, (GLint *)retLONG);
	return NOERROR;
}


// 反走样线的隐含模式, 默认值为CEE3D_DONT_CARE

STDMETHODIMP
CeE3DControl::get_LineSmoothHint(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_LINE_SMOOTH_HINT, (GLint *)retLONG);
	return NOERROR;
}


// 反走样多边形的隐含模式, 默认值为CEE3D_DONT_CARE

STDMETHODIMP
CeE3DControl::get_PolygonSmoothHint(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_POLYGON_SMOOTH_HINT, (GLint *)retLONG);
	return NOERROR;
}


// 雾的隐含模式, 默认值为CEE3D_DONT_CARE

STDMETHODIMP
CeE3DControl::get_FogHint(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_FOG_HINT, (GLint *)retLONG);
	return NOERROR;
}


// 光源数目的最大值, 默认值为8

STDMETHODIMP
CeE3DControl::get_MaxLights(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_LIGHTS, (GLint *)retLONG);
	return NOERROR;
}


// 剪裁平面的最大值, 默认值为6

STDMETHODIMP
CeE3DControl::get_MaxClipPlanes(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_CLIP_PLANES, (GLint *)retLONG);
	return NOERROR;
}


// 模型取景矩阵堆栈的最大深度, 默认值为32

STDMETHODIMP
CeE3DControl::get_MaxModelViewStackDepth(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_MODELVIEW_STACK_DEPTH, (GLint *)retLONG);
	return NOERROR;
}


// 投影矩阵堆栈的最大深度, 默认值为2

STDMETHODIMP
CeE3DControl::get_MaxProjectionStackDepth(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_PROJECTION_STACK_DEPTH, (GLint *)retLONG);
	return NOERROR;
}


// 纹理矩阵堆栈的最大深度, 默认值为2

STDMETHODIMP
CeE3DControl::get_MaxTextureStackDepth(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_TEXTURE_STACK_DEPTH, (GLint *)retLONG);
	return NOERROR;
}


// 亚像素的字位数, 默认值为4

STDMETHODIMP
CeE3DControl::get_SubPixelBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_SUBPIXEL_BITS, (GLint *)retLONG);
	return NOERROR;
}


// 纹理图像的最大尺寸, 默认值为64

STDMETHODIMP
CeE3DControl::get_MaxTextureSize(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_TEXTURE_SIZE, (GLint *)retLONG);
	return NOERROR;
}


// 显示列表嵌套的最大深度, 默认值为64

STDMETHODIMP
CeE3DControl::get_MaxListNesting(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_LIST_NESTING, (GLint *)retLONG);
	return NOERROR;
}


// 求值其支持的最大方程阶数, 默认值为8

STDMETHODIMP
CeE3DControl::get_MaxEvalOrder(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_EVAL_ORDER, (GLint *)retLONG);
	return NOERROR;
}


// 视窗支持的最大尺寸, 默认值为无

STDMETHODIMP
CeE3DControl::get_MaxViewportDims(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_VIEWPORT_DIMS, (GLint *)retLONG);
	return NOERROR;
}


// 属性堆栈最大深度, 默认值为16

STDMETHODIMP
CeE3DControl::get_MaxAttribStackDepth(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_MAX_ATTRIB_STACK_DEPTH, (GLint *)retLONG);
	return NOERROR;
}


// 颜色状态, 默认值为无

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


// 索引色状态, 默认值为无

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


// 是否支持双缓存区, 默认值为无

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


// 是否支持左右缓存区, 默认值为无

STDMETHODIMP
CeE3DControl::get_SupportStereo(BOOL *retBOOL) {
	*retBOOL = 0;
	glGetBooleanv(GL_STEREO, (GLboolean *)retBOOL);
	return NOERROR;
}


// 反走样点的尺寸范围, 默认值为1,1

STDMETHODIMP
CeE3DControl::get_PointSizeRange(float *retfloat) {
	glGetFloatv(GL_POINT_SIZE_RANGE, retfloat);
	return NOERROR;
}


// 反走样点相邻尺寸的差别, 默认值为无

STDMETHODIMP
CeE3DControl::get_PointSizeGranularity(float *retfloat) {
	glGetFloatv(GL_POINT_SIZE_GRANULARITY, retfloat);
	return NOERROR;
}


// 反走样线的尺寸范围, 默认值为1,1

STDMETHODIMP
CeE3DControl::get_LineWidthRange(float *retfloat) {
	glGetFloatv(GL_LINE_WIDTH_RANGE, retfloat);
	return NOERROR;
}


// 反走样线相邻尺寸的差别, 默认值为无

STDMETHODIMP
CeE3DControl::get_LineWidthGranularity(float *retfloat) {
	glGetFloatv(GL_LINE_WIDTH_GRANULARITY, retfloat);
	return NOERROR;
}


// 颜色缓冲区的红色位平面数目, 默认值为无

STDMETHODIMP
CeE3DControl::get_RedBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_RED_BITS, (GLint *)retLONG);
	return NOERROR;
}


// 颜色缓冲区的绿色位平面数目, 默认值为无

STDMETHODIMP
CeE3DControl::get_GreenBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_GREEN_BITS, (GLint *)retLONG);
	return NOERROR;
}


// 颜色缓冲区的蓝色位平面数目, 默认值为无

STDMETHODIMP
CeE3DControl::get_BlueBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_BLUE_BITS, (GLint *)retLONG);
	return NOERROR;
}


// 颜色缓冲区的α位平面数目, 默认值为无

STDMETHODIMP
CeE3DControl::get_AlphaBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_ALPHA_BITS, (GLint *)retLONG);
	return NOERROR;
}


// 索引色缓冲区的位平面数目, 默认值为无

STDMETHODIMP
CeE3DControl::get_IndexBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_INDEX_BITS, (GLint *)retLONG);
	return NOERROR;
}


// 深度缓冲区的位平面数目, 默认值为无

STDMETHODIMP
CeE3DControl::get_DepthBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_DEPTH_BITS, (GLint *)retLONG);
	return NOERROR;
}


// 模版缓冲区的位平面数目, 默认值为无

STDMETHODIMP
CeE3DControl::get_StencilBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_STENCIL_BITS, (GLint *)retLONG);
	return NOERROR;
}


// 累加缓冲区的红色位平面数目, 默认值为无

STDMETHODIMP
CeE3DControl::get_AccumRedBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_ACCUM_RED_BITS, (GLint *)retLONG);
	return NOERROR;
}


// 累加缓冲区的绿色位平面数目, 默认值为无

STDMETHODIMP
CeE3DControl::get_AccumGreenBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_ACCUM_GREEN_BITS, (GLint *)retLONG);
	return NOERROR;
}


// 累加缓冲区的蓝色位平面数目, 默认值为无

STDMETHODIMP
CeE3DControl::get_AccumBlueBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_ACCUM_BLUE_BITS, (GLint *)retLONG);
	return NOERROR;
}


// 累加缓冲区的α位平面数目, 默认值为无

STDMETHODIMP
CeE3DControl::get_AccumAlphaBits(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_ACCUM_ALPHA_BITS, (GLint *)retLONG);
	return NOERROR;
}


// 显示列表矩阵基, 默认值为0

STDMETHODIMP
CeE3DControl::get_CallListBase(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_LIST_BASE, (GLint *)retLONG);
	return NOERROR;
}


// 当前显示列表索引, 默认值为0

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


// 构造的显示列表模式, 默认值为0

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


// 属性堆栈深度指针, 默认值为0

STDMETHODIMP
CeE3DControl::get_CurrentAttribStackDepth(LONG *retLONG) {
	*retLONG = 0;
	glGetIntegerv(GL_ATTRIB_STACK_DEPTH, (GLint *)retLONG);
	return NOERROR;
}


// 名称堆栈深度, 默认值为0

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
