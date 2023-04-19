
#pragma once

class CeE3DControl :
	public CComObjectRoot,
	public CComCoClass<CeE3DControl, &CLSID_CeE3DControl>,
	public IDispatchImpl<ICeE3DControl, &IID_ICeE3DControl> {
public:
	CeE3DControl();
	virtual ~CeE3DControl();

	// 当前索引色, 默认值为0.
	STDMETHOD(get_CurrentColorIndexi)(LONG *retLONG);
	STDMETHOD(put_CurrentColorIndexi)(LONG newLONG);

	// 当前索引色, 默认值为0.
	STDMETHOD(get_CurrentColorIndexf)(float *retfloat);
	STDMETHOD(put_CurrentColorIndexf)(float newfloat);

	// 当前纹理坐标, 默认值为0,0,1.
	STDMETHOD(get_CurrentTextureCoords)(float *retfloat);
	STDMETHOD(put_CurrentTextureCoords)(float newfloat);

	// 当前法线, 默认值为0,1.
	STDMETHOD(get_CurrentNormal)(float *retfloat);
	STDMETHOD(put_CurrentNormal)(float newfloat);

	// 当前光栅坐标, 默认值为0,0,1.
	STDMETHOD(get_CurrentRasterPosition)(float *retfloat);
	STDMETHOD(put_CurrentRasterPosition)(float newfloat);

	// 当前光栅坐标距离, 默认值为0.
	STDMETHOD(get_CurrentRasterDistance)(float *retfloat);

	// 当前光栅坐标RGBA值, 默认值为1,1,1,1.
	STDMETHOD(get_CurrentRasterColori)(LONG *retLONG);

	// 当前光栅坐标RGBA值, 默认值为1,1,1,2.
	STDMETHOD(get_CurrentRasterColorf)(float *retfloat);

	// 当前光栅坐标索引色, 默认值为1.
	STDMETHOD(get_CurrentRasterIndexi)(LONG *retLONG);

	// 当前光栅坐标索引色, 默认值为2.
	STDMETHOD(get_CurrentRasterIndexf)(float *retfloat);

	// 当前光栅坐标纹理坐标, 默认值为0,0,0.
	STDMETHOD(get_CurrentRasterTexture)(float *retfloat);
	STDMETHOD(put_CurrentRasterTexture)(float newfloat);

	// 当前光栅坐标是否有效, 默认值为CEE3D_TRUE.
	STDMETHOD(get_CurrentRasterPositionValid)(BOOL *retBOOL);

	// 当前边缘标志, 默认值为CEE3D_TRUE.
	STDMETHOD(get_CurrentEdgeFlag)(BOOL *retBOOL);
	STDMETHOD(put_CurrentEdgeFlag)(BOOL newBOOL);

	// 模型取景矩阵堆栈, 默认值为单位矩阵.
	STDMETHOD(get_MatrixModelView)(float *retfloat);

	// 投影矩阵堆栈, 默认值为单位矩阵.
	STDMETHOD(get_MatrixProjection)(float *retfloat);

	// 纹理矩阵堆栈, 默认值为单位矩阵.
	STDMETHOD(get_MatrixTexutre)(float *retfloat);

	// 视窗坐标, 默认值为无.
	STDMETHOD(get_Viewport)(LONG *retLONG);

	// 深度缓冲区范围, 默认值为1.
	STDMETHOD(GetDepthRange)(float *r1, float *r2);
	STDMETHOD(SetDepthRange)(float r1, float r2);

	// 模型取影矩阵堆栈指针, 默认值为1.
	STDMETHOD(get_ModelViewStackDepth)(LONG *retLONG);

	// 投影矩阵堆栈指针, 默认值为1.
	STDMETHOD(get_ProjectionStackDepth)(LONG *retLONG);

	// 当前矩阵类型, 默认值为CEE3D_MODELVIEW.
	STDMETHOD(get_CurrentMatrixMode)(LONG *retLONG);
	STDMETHOD(put_CurrentMatrixMode)(LONG newLONG);

	// 当前法线规格化, 默认值为CEE3D_FALSE.
	STDMETHOD(get_Normalize)(BOOL *retBOOL);
	STDMETHOD(put_Normalize)(BOOL newBOOL);

	// 使用激活的裁减平面, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseClipPlane)(LONG index, BOOL *retBOOL);
	STDMETHOD(put_UseClipPlane)(LONG index, BOOL newBOOL);

	// 雾颜色, 默认值为0,0,0.
	STDMETHOD(get_FogColor)(float *retfloat);
	STDMETHOD(put_FogColor)(float newfloat);

	// 雾的索引色, 默认值为0.
	STDMETHOD(get_FogColorIndex)(float *retfloat);
	STDMETHOD(put_FogColorIndex)(float newfloat);

	// 雾浓度指数, 默认值为1.
	STDMETHOD(get_FogDensity)(float *retfloat);
	STDMETHOD(put_FogDensity)(float newfloat);

	// 雾线型方程的开始, 默认值为0.
	STDMETHOD(get_FogStart)(float *retfloat);
	STDMETHOD(put_FogStart)(float newfloat);

	// 雾线型方程的结束, 默认值为1.
	STDMETHOD(get_FogEnd)(float *retfloat);
	STDMETHOD(put_FogEnd)(float newfloat);

	// 雾模式, 默认值为CEE3D_EXP.
	STDMETHOD(get_CurrentFogMode)(LONG *retLONG);
	STDMETHOD(put_CurrentFogMode)(LONG newLONG);

	// 是否进行雾效果计算, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseFog)(BOOL *retBOOL);
	STDMETHOD(put_UseFog)(BOOL newBOOL);

	// 阴影处理模式, 默认值为CEE3D_SMOOTH.
	STDMETHOD(get_ShadeModel)(LONG *retLONG);
	STDMETHOD(put_ShadeModel)(LONG newLONG);

	// 允许使用光照, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseLighting)(BOOL *retBOOL);
	STDMETHOD(put_UseLighting)(BOOL newBOOL);

	// 材质系数, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseColorMaterial)(BOOL *retBOOL);
	STDMETHOD(put_UseColorMaterial)(BOOL newBOOL);

	// 跟踪当前颜色的材质系数, 默认值为CEE3D_AMBIENT_AND_DIFFUSE.
	STDMETHOD(get_ColorMaterialParameter)(LONG face, LONG *retLONG);

	// 受颜色跟踪影响的外观, 默认值为CEE3D_FRONT_AND_BACK.
	STDMETHOD(get_ColorMaterialFace)(LONG face, LONG *retLONG);
	STDMETHOD(put_ColorMaterialFace)(LONG face, LONG newLONG);

	// 场景泛光强度, 默认值为.2,.2,.2,1.
	STDMETHOD(get_LightModelAmbient)(float *retfloat);
	STDMETHOD(put_LightModelAmbient)(float newfloat);

	// 观察点是否在场内, 默认值为CEE3D_FALSE.
	STDMETHOD(get_LightModelUseLocalViewer)(BOOL *retBOOL);
	STDMETHOD(put_LightModelUseLocalViewer)(BOOL newBOOL);

	// 采用双面光照, 默认值为CEE3D_FALSE.
	STDMETHOD(get_LightModeUseTwoSide)(BOOL *retBOOL);
	STDMETHOD(put_LightModeUseTwoSide)(BOOL newBOOL);

	// 使用制定光源, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseLight)(LONG whichlight, BOOL *retBOOL);
	STDMETHOD(put_UseLight)(LONG whichlight, BOOL newBOOL);

	// 光源索引色, 默认值为1,1.
	STDMETHOD(get_LightColorIndexes)(float *retfloat);
	STDMETHOD(put_LightColorIndexes)(float newfloat);

	// 点尺寸, 默认值为1.
	STDMETHOD(get_PointSize)(float *retfloat);
	STDMETHOD(put_PointSize)(float newfloat);

	// 点反走样, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseSmoothPoint)(BOOL *retBOOL);
	STDMETHOD(put_UseSmoothPoint)(BOOL newBOOL);

	// 线宽, 默认值为1.
	STDMETHOD(get_LineWidth)(float *retfloat);
	STDMETHOD(put_LineWidth)(float newfloat);

	// 线反走样, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseSmoothLine)(BOOL *retBOOL);
	STDMETHOD(put_UseSmoothLine)(BOOL newBOOL);

	// 线填充图案, 默认值为1S.
	STDMETHOD(get_StippleLinePattern)(LONG *retLONG);
	STDMETHOD(SetStippleLinePattern)(LONG factor, LONG newLONG);

	// 重复线填充图案, 默认值为1.
	STDMETHOD(get_StippleLineRepeat)(LONG *retLONG);

	// 是否线填充, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseStippleLine)(BOOL *retBOOL);
	STDMETHOD(put_UseStippleLine)(BOOL newBOOL);

	// 是否剔除多边形, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseCullFace)(BOOL *retBOOL);
	STDMETHOD(put_UseCullFace)(BOOL newBOOL);

	// 剔除多边形的面, 默认值为CEE3D_BACK.
	STDMETHOD(get_CullFaceMode)(LONG *retLONG);
	STDMETHOD(put_CullFaceMode)(LONG newLONG);

	// 多边形朝前的面的顺逆时针, 默认值为CEE3D_CCW.
	STDMETHOD(get_FrontFaceDirection)(LONG *retLONG);
	STDMETHOD(put_FrontFaceDirection)(LONG newLONG);

	// 多边形反走样, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseSmoothPolygon)(BOOL *retBOOL);
	STDMETHOD(put_UseSmoothPolygon)(BOOL newBOOL);

	// 多边形光栅化模式, 默认值为CEE3D_FILL.
	STDMETHOD(get_PolygonMode)(LONG *retLONG);
	STDMETHOD(SetPolygonMode)(LONG face, LONG newLONG);

	// 多边形填充图案, 默认值为CEE3D_FALSE.
	STDMETHOD(get_StipplePolygonPattern)(BOOL *retBOOL);
	STDMETHOD(put_StipplePolygonPattern)(BOOL newBOOL);

	// 裁减检验, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseScissor)(BOOL *retBOOL);
	STDMETHOD(put_UseScissor)(BOOL newBOOL);

	// 裁减框, 默认值为无.
	STDMETHOD(get_ScissorBox)(LONG *retLONG);
	STDMETHOD(SetScissorBox)(LONG x, LONG y, LONG width, LONG height);

	// 模版检验, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseStencil)(BOOL *retBOOL);
	STDMETHOD(put_UseStencil)(BOOL newBOOL);

	// 模版功能, 默认值为CEE3D_ALWAYS.
	STDMETHOD(get_StencilFunc)(LONG *retLONG);
	STDMETHOD(put_StencilFunc)(LONG newLONG);

	// 模版标识, 默认值为1.....
	STDMETHOD(get_StencilValueMask)(LONG *retLONG);
	STDMETHOD(put_StencilValueMask)(LONG newLONG);

	// 模版检验参考值, 默认值为0.
	STDMETHOD(get_StencilReference)(LONG *retLONG);
	STDMETHOD(put_StencilReference)(LONG newLONG);

	// 模版检验失败, 默认值为CEE3D_KEEP.
	STDMETHOD(get_StencilFailure)(LONG *retLONG);
	STDMETHOD(put_StencilFailure)(LONG newLONG);

	// 模版检验通过,深度检验失败, 默认值为CEE3D_KEEP.
	STDMETHOD(get_StencilPassFailDepth)(LONG *retLONG);
	STDMETHOD(put_StencilPassFailDepth)(LONG newLONG);

	// 模版,深度检验通过, 默认值为CEE3D_KEEP.
	STDMETHOD(get_StencilPassPassDepth)(LONG *retLONG);
	STDMETHOD(put_StencilPassPassDepth)(LONG newLONG);

	// 允许α检验, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseAlpha)(BOOL *retBOOL);
	STDMETHOD(put_UseAlpha)(BOOL newBOOL);

	// α检验函数, 默认值为CEE3D_ALWAYS.
	STDMETHOD(get_AlphaTestFunc)(LONG *retLONG);
	STDMETHOD(put_AlphaTestFunc)(LONG newLONG);

	// α检验参考值, 默认值为0.
	STDMETHOD(get_AlphaTestReference)(float *retfloat);
	STDMETHOD(put_AlphaTestReference)(float newfloat);

	// 深度检验函数, 默认值为CEE3D_LESS.
	STDMETHOD(get_DepthFunc)(LONG *retLONG);
	STDMETHOD(put_DepthFunc)(LONG newLONG);

	// 融合运算, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseBlend)(BOOL *retBOOL);
	STDMETHOD(put_UseBlend)(BOOL newBOOL);

	// 源融合运算, 默认值为CEE3D_ONE.
	// 目标融合函数, 默认值为CEE3D_ZERO.
	STDMETHOD(get_BlendSourceSfactor)(LONG *retLONG);
	STDMETHOD(get_BlendSourceDfactor)(LONG *retLONG);
	STDMETHOD(put_BlendSource)(LONG sfactor, LONG dfactor);

	// 逻辑操作, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseLogicOperation)(BOOL *retBOOL);
	STDMETHOD(put_UseLogicOperation)(BOOL newBOOL);

	// 逻辑操作模式, 默认值为CEE3D_COPY.
	STDMETHOD(get_LogicOperationMode)(LONG *retLONG);
	STDMETHOD(put_LogicOperationMode)(LONG newLONG);

	// 抖动操作, 默认值为CEE3D_TRUE.
	STDMETHOD(get_UseDither)(BOOL *retBOOL);
	STDMETHOD(put_UseDither)(BOOL newBOOL);

	// 要写入的缓冲区, 默认值为无.
	STDMETHOD(get_DrawBuffer)(LONG *retLONG);
	STDMETHOD(put_DrawBuffer)(LONG newLONG);

	// 索引色缓存区位平面的写屏蔽, 默认值为1.....
	STDMETHOD(get_ColorIndexWriteMask)(LONG *retLONG);
	STDMETHOD(put_ColorIndexWriteMask)(LONG newLONG);

	// 写入深度缓存, 默认值为CEE3D_TRUE.
	STDMETHOD(get_DepthWriteMask)(BOOL *retBOOL);
	STDMETHOD(put_DepthWriteMask)(BOOL newBOOL);

	// 写入模版缓存, 默认值为1.....
	STDMETHOD(get_StencilWriteMask)(LONG *retLONG);
	STDMETHOD(put_StencilWriteMask)(LONG newLONG);

	// 清除颜色缓存RGBA值, 默认值为0,0,0.
	STDMETHOD(get_ColorClearValue)(LONG RGBA_select, float *retfloat);
	STDMETHOD(SetColorClearValue)(float r, float g, float b, float a);

	// 清除颜色指数值, 默认值为0.
	STDMETHOD(get_ColorIndexClearValue)(float *retfloat);
	STDMETHOD(put_ColorIndexClearValue)(float newfloat);

	// 清除深度缓存值, 默认值为1.
	STDMETHOD(get_DepthClearValue)(LONG *retLONG);
	STDMETHOD(put_DepthClearValue)(LONG newLONG);

	// 清除模版缓存值, 默认值为0.
	STDMETHOD(get_StencilClearValue)(LONG *retLONG);
	STDMETHOD(put_StencilClearValue)(LONG newLONG);

	// 清除累加缓存值, 默认值为0.
	STDMETHOD(get_AccumClearValue)(float *retfloat);
	STDMETHOD(put_AccumClearValue)(float newfloat);

	// 未打包交换比特, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UnpackSwapBytes)(BOOL *retBOOL);
	STDMETHOD(put_UnpackSwapBytes)(BOOL newBOOL);

	// 未打包行长度, 默认值为0.
	STDMETHOD(get_UnpackRowLength)(LONG *retLONG);
	STDMETHOD(put_UnpackRowLength)(LONG newLONG);

	// 未打包忽略行, 默认值为0.
	STDMETHOD(get_UnpackSkipRows)(LONG *retLONG);
	STDMETHOD(put_UnpackSkipRows)(LONG newLONG);

	// 未打包忽略像素, 默认值为0.
	STDMETHOD(get_UnpackSkipPixels)(LONG *retLONG);
	STDMETHOD(put_UnpackSkipPixels)(LONG newLONG);

	// 未打包对齐, 默认值为4.
	STDMETHOD(get_UnpackAlignment)(LONG *retLONG);
	STDMETHOD(put_UnpackAlignment)(LONG newLONG);

	// 打包交换比特, 默认值为CEE3D_FALSE.
	STDMETHOD(get_PackSwapBytes)(BOOL *retBOOL);
	STDMETHOD(put_PackSwapBytes)(BOOL newBOOL);

	// 打包第一个LSB, 默认值为CEE3D_FALSE.
	STDMETHOD(get_PackLSBFirst)(BOOL *retBOOL);
	STDMETHOD(put_PackLSBFirst)(BOOL newBOOL);

	// 打包行长度, 默认值为0.
	STDMETHOD(get_PackRowLength)(LONG *retLONG);
	STDMETHOD(put_PackRowLength)(LONG newLONG);

	// 打包忽略行, 默认值为0.
	STDMETHOD(get_PackSkipRows)(LONG *retLONG);
	STDMETHOD(put_PackSkipRows)(LONG newLONG);

	// 打包忽略像素, 默认值为0.
	STDMETHOD(get_PackSkipPixels)(LONG *retLONG);
	STDMETHOD(put_PackSkipPixels)(LONG newLONG);

	// 打包对齐, 默认值为4.
	STDMETHOD(get_PackAlignment)(LONG *retLONG);
	STDMETHOD(put_PackAlignment)(LONG newLONG);

	// 是否用查对表代替颜色或索引色, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseColorMap)(BOOL *retBOOL);
	STDMETHOD(put_UseColorMap)(BOOL newBOOL);

	// 是否用查对表代替模版, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseStencilMap)(BOOL *retBOOL);
	STDMETHOD(put_UseStencilMap)(BOOL newBOOL);

	// 索引移位, 默认值为0.
	STDMETHOD(get_IndexShift)(LONG *retLONG);
	STDMETHOD(put_IndexShift)(LONG newLONG);

	// 索引偏移, 默认值为0.
	STDMETHOD(get_IndexOffset)(LONG *retLONG);
	STDMETHOD(put_IndexOffset)(LONG newLONG);

	// X像素的缩放因子, 默认值为.
	STDMETHOD(get_ZoomX)(float *retfloat);
	STDMETHOD(put_ZoomX)(float newfloat);

	// Y像素的缩放因子, 默认值为.
	STDMETHOD(get_ZoomY)(float *retfloat);
	STDMETHOD(put_ZoomY)(float newfloat);

	// 读取缓存区资源, 默认值为无.
	STDMETHOD(get_ReadBuffer)(LONG *retLONG);
	STDMETHOD(put_ReadBuffer)(LONG newLONG);

	// 允许一维映射, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseMap1)(BOOL *retBOOL);
	STDMETHOD(put_UseMap1)(BOOL newBOOL);

	// 允许二维映射, 默认值为CEE3D_FALSE.
	STDMETHOD(get_UseMap2)(BOOL *retBOOL);
	STDMETHOD(put_UseMap2)(BOOL newBOOL);

	// 二维映射的网格与节点, 默认值为1;0,1.
	STDMETHOD(get_Map2GridDomain)(float *retfloat);

	// 一维映射的网格域的间隔数目, 默认值为1.
	STDMETHOD(get_Map1GridSegments)(float *retfloat);

	// 二维映射的网格域的间隔数目, 默认值为1,1.
	STDMETHOD(get_Map2GridSegments)(float *retfloat);

	// 是否允许自动求解法向量, 默认值为CEE3D_FALSE.
	STDMETHOD(get_AutoNormalize)(BOOL *retBOOL);
	STDMETHOD(put_AutoNormalize)(BOOL newBOOL);

	// 透视校正的隐含模式, 默认值为CEE3D_DONT_CARE.
	STDMETHOD(get_PerspectiveCorrectionHint)(LONG *retLONG);
	STDMETHOD(put_PerspectiveCorrectionHint)(LONG newLONG);

	// 反走样点的隐含模式, 默认值为CEE3D_DONT_CARE.
	STDMETHOD(get_PointSmoothHint)(LONG *retLONG);

	// 反走样线的隐含模式, 默认值为CEE3D_DONT_CARE.
	STDMETHOD(get_LineSmoothHint)(LONG *retLONG);

	// 反走样多边形的隐含模式, 默认值为CEE3D_DONT_CARE.
	STDMETHOD(get_PolygonSmoothHint)(LONG *retLONG);

	// 雾的隐含模式, 默认值为CEE3D_DONT_CARE.
	STDMETHOD(get_FogHint)(LONG *retLONG);

	// 光源数目的最大值, 默认值为8.
	STDMETHOD(get_MaxLights)(LONG *retLONG);

	// 剪裁平面的最大值, 默认值为6.
	STDMETHOD(get_MaxClipPlanes)(LONG *retLONG);

	// 模型取景矩阵堆栈的最大深度, 默认值为32.
	STDMETHOD(get_MaxModelViewStackDepth)(LONG *retLONG);

	// 投影矩阵堆栈的最大深度, 默认值为2.
	STDMETHOD(get_MaxProjectionStackDepth)(LONG *retLONG);

	// 纹理矩阵堆栈的最大深度, 默认值为2.
	STDMETHOD(get_MaxTextureStackDepth)(LONG *retLONG);

	// 亚像素的字位数, 默认值为4.
	STDMETHOD(get_SubPixelBits)(LONG *retLONG);

	// 纹理图像的最大尺寸, 默认值为64.
	STDMETHOD(get_MaxTextureSize)(LONG *retLONG);

	// 显示列表嵌套的最大深度, 默认值为64.
	STDMETHOD(get_MaxListNesting)(LONG *retLONG);

	// 求值其支持的最大方程阶数, 默认值为8.
	STDMETHOD(get_MaxEvalOrder)(LONG *retLONG);

	// 视窗支持的最大尺寸, 默认值为无.
	STDMETHOD(get_MaxViewportDims)(LONG *retLONG);

	// 属性堆栈最大深度, 默认值为16.
	STDMETHOD(get_MaxAttribStackDepth)(LONG *retLONG);

	// 颜色状态, 默认值为无.
	STDMETHOD(get_InRGBAMode)(BOOL *retBOOL);
	STDMETHOD(put_InRGBAMode)(BOOL newBOOL);

	// 索引色状态, 默认值为无.
	STDMETHOD(get_InColorIndexMode)(BOOL *retBOOL);
	STDMETHOD(put_InColorIndexMode)(BOOL newBOOL);

	// 是否支持双缓存区, 默认值为无.
	STDMETHOD(get_SupportDoubleBuffer)(BOOL *retBOOL);
	STDMETHOD(put_SupportDoubleBuffer)(BOOL newBOOL);

	// 是否支持左右缓存区, 默认值为无.
	STDMETHOD(get_SupportStereo)(BOOL *retBOOL);

	// 反走样点的尺寸范围, 默认值为1,1.
	STDMETHOD(get_PointSizeRange)(float *retfloat);

	// 反走样点相邻尺寸的差别, 默认值为无.
	STDMETHOD(get_PointSizeGranularity)(float *retfloat);

	// 反走样线的尺寸范围, 默认值为1,1.
	STDMETHOD(get_LineWidthRange)(float *retfloat);

	// 反走样线相邻尺寸的差别, 默认值为无.
	STDMETHOD(get_LineWidthGranularity)(float *retfloat);

	// 颜色缓冲区的红色位平面数目, 默认值为无.
	STDMETHOD(get_RedBits)(LONG *retLONG);

	// 颜色缓冲区的绿色位平面数目, 默认值为无.
	STDMETHOD(get_GreenBits)(LONG *retLONG);

	// 颜色缓冲区的蓝色位平面数目, 默认值为无.
	STDMETHOD(get_BlueBits)(LONG *retLONG);

	// 颜色缓冲区的α位平面数目, 默认值为无.
	STDMETHOD(get_AlphaBits)(LONG *retLONG);

	// 索引色缓冲区的位平面数目, 默认值为无.
	STDMETHOD(get_IndexBits)(LONG *retLONG);

	// 深度缓冲区的位平面数目, 默认值为无.
	STDMETHOD(get_DepthBits)(LONG *retLONG);

	// 模版缓冲区的位平面数目, 默认值为无.
	STDMETHOD(get_StencilBits)(LONG *retLONG);

	// 累加缓冲区的红色位平面数目, 默认值为无.
	STDMETHOD(get_AccumRedBits)(LONG *retLONG);

	// 累加缓冲区的绿色位平面数目, 默认值为无.
	STDMETHOD(get_AccumGreenBits)(LONG *retLONG);

	// 累加缓冲区的蓝色位平面数目, 默认值为无.
	STDMETHOD(get_AccumBlueBits)(LONG *retLONG);

	// 累加缓冲区的α位平面数目, 默认值为无.
	STDMETHOD(get_AccumAlphaBits)(LONG *retLONG);

	// 显示列表矩阵基, 默认值为0.
	STDMETHOD(get_CallListBase)(LONG *retLONG);

	// 当前显示列表索引, 默认值为0.
	STDMETHOD(get_CallListIndex)(LONG *retLONG);
	STDMETHOD(put_CallListIndex)(LONG newLONG);

	// 构造的显示列表模式, 默认值为0.
	STDMETHOD(get_CallListMode)(LONG *retLONG);
	STDMETHOD(put_CallListMode)(LONG newLONG);

	// 属性堆栈深度指针, 默认值为0.
	STDMETHOD(get_CurrentAttribStackDepth)(LONG *retLONG);

	// 名称堆栈深度, 默认值为0.
	STDMETHOD(get_CurrentNameStackDepth)(LONG *retLONG);
	STDMETHOD(put_CurrentNameStackDepth)(LONG newLONG);

	BEGIN_COM_MAP(CeE3DControl)
		COM_INTERFACE_ENTRY2(IDispatch, ICeE3DControl)
		COM_INTERFACE_ENTRY(ICeE3DControl)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CeE3DControl)
	DECLARE_NOT_AGGREGATABLE(CeE3DControl)

protected:
};

typedef CeE3DControl	*PCEE3DControl, *LPCEE3DControl;
