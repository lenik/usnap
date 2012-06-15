
#pragma once

class CeE3DControl :
	public CComObjectRoot,
	public CComCoClass<CeE3DControl, &CLSID_CeE3DControl>,
	public IDispatchImpl<ICeE3DControl, &IID_ICeE3DControl> {
public:
	CeE3DControl();
	virtual ~CeE3DControl();

	// ��ǰ����ɫ, Ĭ��ֵΪ0.
	STDMETHOD(get_CurrentColorIndexi)(LONG *retLONG);
	STDMETHOD(put_CurrentColorIndexi)(LONG newLONG);

	// ��ǰ����ɫ, Ĭ��ֵΪ0.
	STDMETHOD(get_CurrentColorIndexf)(float *retfloat);
	STDMETHOD(put_CurrentColorIndexf)(float newfloat);

	// ��ǰ��������, Ĭ��ֵΪ0,0,1.
	STDMETHOD(get_CurrentTextureCoords)(float *retfloat);
	STDMETHOD(put_CurrentTextureCoords)(float newfloat);

	// ��ǰ����, Ĭ��ֵΪ0,1.
	STDMETHOD(get_CurrentNormal)(float *retfloat);
	STDMETHOD(put_CurrentNormal)(float newfloat);

	// ��ǰ��դ����, Ĭ��ֵΪ0,0,1.
	STDMETHOD(get_CurrentRasterPosition)(float *retfloat);
	STDMETHOD(put_CurrentRasterPosition)(float newfloat);

	// ��ǰ��դ�������, Ĭ��ֵΪ0.
	STDMETHOD(get_CurrentRasterDistance)(float *retfloat);

	// ��ǰ��դ����RGBAֵ, Ĭ��ֵΪ1,1,1,1.
	STDMETHOD(get_CurrentRasterColori)(LONG *retLONG);

	// ��ǰ��դ����RGBAֵ, Ĭ��ֵΪ1,1,1,2.
	STDMETHOD(get_CurrentRasterColorf)(float *retfloat);

	// ��ǰ��դ��������ɫ, Ĭ��ֵΪ1.
	STDMETHOD(get_CurrentRasterIndexi)(LONG *retLONG);

	// ��ǰ��դ��������ɫ, Ĭ��ֵΪ2.
	STDMETHOD(get_CurrentRasterIndexf)(float *retfloat);

	// ��ǰ��դ������������, Ĭ��ֵΪ0,0,0.
	STDMETHOD(get_CurrentRasterTexture)(float *retfloat);
	STDMETHOD(put_CurrentRasterTexture)(float newfloat);

	// ��ǰ��դ�����Ƿ���Ч, Ĭ��ֵΪCEE3D_TRUE.
	STDMETHOD(get_CurrentRasterPositionValid)(BOOL *retBOOL);

	// ��ǰ��Ե��־, Ĭ��ֵΪCEE3D_TRUE.
	STDMETHOD(get_CurrentEdgeFlag)(BOOL *retBOOL);
	STDMETHOD(put_CurrentEdgeFlag)(BOOL newBOOL);

	// ģ��ȡ�������ջ, Ĭ��ֵΪ��λ����.
	STDMETHOD(get_MatrixModelView)(float *retfloat);

	// ͶӰ�����ջ, Ĭ��ֵΪ��λ����.
	STDMETHOD(get_MatrixProjection)(float *retfloat);

	// ��������ջ, Ĭ��ֵΪ��λ����.
	STDMETHOD(get_MatrixTexutre)(float *retfloat);

	// �Ӵ�����, Ĭ��ֵΪ��.
	STDMETHOD(get_Viewport)(LONG *retLONG);

	// ��Ȼ�������Χ, Ĭ��ֵΪ1.
	STDMETHOD(GetDepthRange)(float *r1, float *r2);
	STDMETHOD(SetDepthRange)(float r1, float r2);

	// ģ��ȡӰ�����ջָ��, Ĭ��ֵΪ1.
	STDMETHOD(get_ModelViewStackDepth)(LONG *retLONG);

	// ͶӰ�����ջָ��, Ĭ��ֵΪ1.
	STDMETHOD(get_ProjectionStackDepth)(LONG *retLONG);

	// ��ǰ��������, Ĭ��ֵΪCEE3D_MODELVIEW.
	STDMETHOD(get_CurrentMatrixMode)(LONG *retLONG);
	STDMETHOD(put_CurrentMatrixMode)(LONG newLONG);

	// ��ǰ���߹��, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_Normalize)(BOOL *retBOOL);
	STDMETHOD(put_Normalize)(BOOL newBOOL);

	// ʹ�ü���Ĳü�ƽ��, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseClipPlane)(LONG index, BOOL *retBOOL);
	STDMETHOD(put_UseClipPlane)(LONG index, BOOL newBOOL);

	// ����ɫ, Ĭ��ֵΪ0,0,0.
	STDMETHOD(get_FogColor)(float *retfloat);
	STDMETHOD(put_FogColor)(float newfloat);

	// �������ɫ, Ĭ��ֵΪ0.
	STDMETHOD(get_FogColorIndex)(float *retfloat);
	STDMETHOD(put_FogColorIndex)(float newfloat);

	// ��Ũ��ָ��, Ĭ��ֵΪ1.
	STDMETHOD(get_FogDensity)(float *retfloat);
	STDMETHOD(put_FogDensity)(float newfloat);

	// �����ͷ��̵Ŀ�ʼ, Ĭ��ֵΪ0.
	STDMETHOD(get_FogStart)(float *retfloat);
	STDMETHOD(put_FogStart)(float newfloat);

	// �����ͷ��̵Ľ���, Ĭ��ֵΪ1.
	STDMETHOD(get_FogEnd)(float *retfloat);
	STDMETHOD(put_FogEnd)(float newfloat);

	// ��ģʽ, Ĭ��ֵΪCEE3D_EXP.
	STDMETHOD(get_CurrentFogMode)(LONG *retLONG);
	STDMETHOD(put_CurrentFogMode)(LONG newLONG);

	// �Ƿ������Ч������, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseFog)(BOOL *retBOOL);
	STDMETHOD(put_UseFog)(BOOL newBOOL);

	// ��Ӱ����ģʽ, Ĭ��ֵΪCEE3D_SMOOTH.
	STDMETHOD(get_ShadeModel)(LONG *retLONG);
	STDMETHOD(put_ShadeModel)(LONG newLONG);

	// ����ʹ�ù���, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseLighting)(BOOL *retBOOL);
	STDMETHOD(put_UseLighting)(BOOL newBOOL);

	// ����ϵ��, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseColorMaterial)(BOOL *retBOOL);
	STDMETHOD(put_UseColorMaterial)(BOOL newBOOL);

	// ���ٵ�ǰ��ɫ�Ĳ���ϵ��, Ĭ��ֵΪCEE3D_AMBIENT_AND_DIFFUSE.
	STDMETHOD(get_ColorMaterialParameter)(LONG face, LONG *retLONG);

	// ����ɫ����Ӱ������, Ĭ��ֵΪCEE3D_FRONT_AND_BACK.
	STDMETHOD(get_ColorMaterialFace)(LONG face, LONG *retLONG);
	STDMETHOD(put_ColorMaterialFace)(LONG face, LONG newLONG);

	// ��������ǿ��, Ĭ��ֵΪ.2,.2,.2,1.
	STDMETHOD(get_LightModelAmbient)(float *retfloat);
	STDMETHOD(put_LightModelAmbient)(float newfloat);

	// �۲���Ƿ��ڳ���, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_LightModelUseLocalViewer)(BOOL *retBOOL);
	STDMETHOD(put_LightModelUseLocalViewer)(BOOL newBOOL);

	// ����˫�����, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_LightModeUseTwoSide)(BOOL *retBOOL);
	STDMETHOD(put_LightModeUseTwoSide)(BOOL newBOOL);

	// ʹ���ƶ���Դ, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseLight)(LONG whichlight, BOOL *retBOOL);
	STDMETHOD(put_UseLight)(LONG whichlight, BOOL newBOOL);

	// ��Դ����ɫ, Ĭ��ֵΪ1,1.
	STDMETHOD(get_LightColorIndexes)(float *retfloat);
	STDMETHOD(put_LightColorIndexes)(float newfloat);

	// ��ߴ�, Ĭ��ֵΪ1.
	STDMETHOD(get_PointSize)(float *retfloat);
	STDMETHOD(put_PointSize)(float newfloat);

	// �㷴����, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseSmoothPoint)(BOOL *retBOOL);
	STDMETHOD(put_UseSmoothPoint)(BOOL newBOOL);

	// �߿�, Ĭ��ֵΪ1.
	STDMETHOD(get_LineWidth)(float *retfloat);
	STDMETHOD(put_LineWidth)(float newfloat);

	// �߷�����, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseSmoothLine)(BOOL *retBOOL);
	STDMETHOD(put_UseSmoothLine)(BOOL newBOOL);

	// �����ͼ��, Ĭ��ֵΪ1S.
	STDMETHOD(get_StippleLinePattern)(LONG *retLONG);
	STDMETHOD(SetStippleLinePattern)(LONG factor, LONG newLONG);

	// �ظ������ͼ��, Ĭ��ֵΪ1.
	STDMETHOD(get_StippleLineRepeat)(LONG *retLONG);

	// �Ƿ������, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseStippleLine)(BOOL *retBOOL);
	STDMETHOD(put_UseStippleLine)(BOOL newBOOL);

	// �Ƿ��޳������, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseCullFace)(BOOL *retBOOL);
	STDMETHOD(put_UseCullFace)(BOOL newBOOL);

	// �޳�����ε���, Ĭ��ֵΪCEE3D_BACK.
	STDMETHOD(get_CullFaceMode)(LONG *retLONG);
	STDMETHOD(put_CullFaceMode)(LONG newLONG);

	// ����γ�ǰ�����˳��ʱ��, Ĭ��ֵΪCEE3D_CCW.
	STDMETHOD(get_FrontFaceDirection)(LONG *retLONG);
	STDMETHOD(put_FrontFaceDirection)(LONG newLONG);

	// ����η�����, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseSmoothPolygon)(BOOL *retBOOL);
	STDMETHOD(put_UseSmoothPolygon)(BOOL newBOOL);

	// ����ι�դ��ģʽ, Ĭ��ֵΪCEE3D_FILL.
	STDMETHOD(get_PolygonMode)(LONG *retLONG);
	STDMETHOD(SetPolygonMode)(LONG face, LONG newLONG);

	// ��������ͼ��, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_StipplePolygonPattern)(BOOL *retBOOL);
	STDMETHOD(put_StipplePolygonPattern)(BOOL newBOOL);

	// �ü�����, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseScissor)(BOOL *retBOOL);
	STDMETHOD(put_UseScissor)(BOOL newBOOL);

	// �ü���, Ĭ��ֵΪ��.
	STDMETHOD(get_ScissorBox)(LONG *retLONG);
	STDMETHOD(SetScissorBox)(LONG x, LONG y, LONG width, LONG height);

	// ģ�����, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseStencil)(BOOL *retBOOL);
	STDMETHOD(put_UseStencil)(BOOL newBOOL);

	// ģ�湦��, Ĭ��ֵΪCEE3D_ALWAYS.
	STDMETHOD(get_StencilFunc)(LONG *retLONG);
	STDMETHOD(put_StencilFunc)(LONG newLONG);

	// ģ���ʶ, Ĭ��ֵΪ1.....
	STDMETHOD(get_StencilValueMask)(LONG *retLONG);
	STDMETHOD(put_StencilValueMask)(LONG newLONG);

	// ģ�����ο�ֵ, Ĭ��ֵΪ0.
	STDMETHOD(get_StencilReference)(LONG *retLONG);
	STDMETHOD(put_StencilReference)(LONG newLONG);

	// ģ�����ʧ��, Ĭ��ֵΪCEE3D_KEEP.
	STDMETHOD(get_StencilFailure)(LONG *retLONG);
	STDMETHOD(put_StencilFailure)(LONG newLONG);

	// ģ�����ͨ��,��ȼ���ʧ��, Ĭ��ֵΪCEE3D_KEEP.
	STDMETHOD(get_StencilPassFailDepth)(LONG *retLONG);
	STDMETHOD(put_StencilPassFailDepth)(LONG newLONG);

	// ģ��,��ȼ���ͨ��, Ĭ��ֵΪCEE3D_KEEP.
	STDMETHOD(get_StencilPassPassDepth)(LONG *retLONG);
	STDMETHOD(put_StencilPassPassDepth)(LONG newLONG);

	// ���������, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseAlpha)(BOOL *retBOOL);
	STDMETHOD(put_UseAlpha)(BOOL newBOOL);

	// �����麯��, Ĭ��ֵΪCEE3D_ALWAYS.
	STDMETHOD(get_AlphaTestFunc)(LONG *retLONG);
	STDMETHOD(put_AlphaTestFunc)(LONG newLONG);

	// ������ο�ֵ, Ĭ��ֵΪ0.
	STDMETHOD(get_AlphaTestReference)(float *retfloat);
	STDMETHOD(put_AlphaTestReference)(float newfloat);

	// ��ȼ��麯��, Ĭ��ֵΪCEE3D_LESS.
	STDMETHOD(get_DepthFunc)(LONG *retLONG);
	STDMETHOD(put_DepthFunc)(LONG newLONG);

	// �ں�����, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseBlend)(BOOL *retBOOL);
	STDMETHOD(put_UseBlend)(BOOL newBOOL);

	// Դ�ں�����, Ĭ��ֵΪCEE3D_ONE.
	// Ŀ���ںϺ���, Ĭ��ֵΪCEE3D_ZERO.
	STDMETHOD(get_BlendSourceSfactor)(LONG *retLONG);
	STDMETHOD(get_BlendSourceDfactor)(LONG *retLONG);
	STDMETHOD(put_BlendSource)(LONG sfactor, LONG dfactor);

	// �߼�����, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseLogicOperation)(BOOL *retBOOL);
	STDMETHOD(put_UseLogicOperation)(BOOL newBOOL);

	// �߼�����ģʽ, Ĭ��ֵΪCEE3D_COPY.
	STDMETHOD(get_LogicOperationMode)(LONG *retLONG);
	STDMETHOD(put_LogicOperationMode)(LONG newLONG);

	// ��������, Ĭ��ֵΪCEE3D_TRUE.
	STDMETHOD(get_UseDither)(BOOL *retBOOL);
	STDMETHOD(put_UseDither)(BOOL newBOOL);

	// Ҫд��Ļ�����, Ĭ��ֵΪ��.
	STDMETHOD(get_DrawBuffer)(LONG *retLONG);
	STDMETHOD(put_DrawBuffer)(LONG newLONG);

	// ����ɫ������λƽ���д����, Ĭ��ֵΪ1.....
	STDMETHOD(get_ColorIndexWriteMask)(LONG *retLONG);
	STDMETHOD(put_ColorIndexWriteMask)(LONG newLONG);

	// д����Ȼ���, Ĭ��ֵΪCEE3D_TRUE.
	STDMETHOD(get_DepthWriteMask)(BOOL *retBOOL);
	STDMETHOD(put_DepthWriteMask)(BOOL newBOOL);

	// д��ģ�滺��, Ĭ��ֵΪ1.....
	STDMETHOD(get_StencilWriteMask)(LONG *retLONG);
	STDMETHOD(put_StencilWriteMask)(LONG newLONG);

	// �����ɫ����RGBAֵ, Ĭ��ֵΪ0,0,0.
	STDMETHOD(get_ColorClearValue)(LONG RGBA_select, float *retfloat);
	STDMETHOD(SetColorClearValue)(float r, float g, float b, float a);

	// �����ɫָ��ֵ, Ĭ��ֵΪ0.
	STDMETHOD(get_ColorIndexClearValue)(float *retfloat);
	STDMETHOD(put_ColorIndexClearValue)(float newfloat);

	// �����Ȼ���ֵ, Ĭ��ֵΪ1.
	STDMETHOD(get_DepthClearValue)(LONG *retLONG);
	STDMETHOD(put_DepthClearValue)(LONG newLONG);

	// ���ģ�滺��ֵ, Ĭ��ֵΪ0.
	STDMETHOD(get_StencilClearValue)(LONG *retLONG);
	STDMETHOD(put_StencilClearValue)(LONG newLONG);

	// ����ۼӻ���ֵ, Ĭ��ֵΪ0.
	STDMETHOD(get_AccumClearValue)(float *retfloat);
	STDMETHOD(put_AccumClearValue)(float newfloat);

	// δ�����������, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UnpackSwapBytes)(BOOL *retBOOL);
	STDMETHOD(put_UnpackSwapBytes)(BOOL newBOOL);

	// δ����г���, Ĭ��ֵΪ0.
	STDMETHOD(get_UnpackRowLength)(LONG *retLONG);
	STDMETHOD(put_UnpackRowLength)(LONG newLONG);

	// δ���������, Ĭ��ֵΪ0.
	STDMETHOD(get_UnpackSkipRows)(LONG *retLONG);
	STDMETHOD(put_UnpackSkipRows)(LONG newLONG);

	// δ�����������, Ĭ��ֵΪ0.
	STDMETHOD(get_UnpackSkipPixels)(LONG *retLONG);
	STDMETHOD(put_UnpackSkipPixels)(LONG newLONG);

	// δ�������, Ĭ��ֵΪ4.
	STDMETHOD(get_UnpackAlignment)(LONG *retLONG);
	STDMETHOD(put_UnpackAlignment)(LONG newLONG);

	// �����������, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_PackSwapBytes)(BOOL *retBOOL);
	STDMETHOD(put_PackSwapBytes)(BOOL newBOOL);

	// �����һ��LSB, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_PackLSBFirst)(BOOL *retBOOL);
	STDMETHOD(put_PackLSBFirst)(BOOL newBOOL);

	// ����г���, Ĭ��ֵΪ0.
	STDMETHOD(get_PackRowLength)(LONG *retLONG);
	STDMETHOD(put_PackRowLength)(LONG newLONG);

	// ���������, Ĭ��ֵΪ0.
	STDMETHOD(get_PackSkipRows)(LONG *retLONG);
	STDMETHOD(put_PackSkipRows)(LONG newLONG);

	// �����������, Ĭ��ֵΪ0.
	STDMETHOD(get_PackSkipPixels)(LONG *retLONG);
	STDMETHOD(put_PackSkipPixels)(LONG newLONG);

	// �������, Ĭ��ֵΪ4.
	STDMETHOD(get_PackAlignment)(LONG *retLONG);
	STDMETHOD(put_PackAlignment)(LONG newLONG);

	// �Ƿ��ò�Ա������ɫ������ɫ, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseColorMap)(BOOL *retBOOL);
	STDMETHOD(put_UseColorMap)(BOOL newBOOL);

	// �Ƿ��ò�Ա����ģ��, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseStencilMap)(BOOL *retBOOL);
	STDMETHOD(put_UseStencilMap)(BOOL newBOOL);

	// ������λ, Ĭ��ֵΪ0.
	STDMETHOD(get_IndexShift)(LONG *retLONG);
	STDMETHOD(put_IndexShift)(LONG newLONG);

	// ����ƫ��, Ĭ��ֵΪ0.
	STDMETHOD(get_IndexOffset)(LONG *retLONG);
	STDMETHOD(put_IndexOffset)(LONG newLONG);

	// X���ص���������, Ĭ��ֵΪ.
	STDMETHOD(get_ZoomX)(float *retfloat);
	STDMETHOD(put_ZoomX)(float newfloat);

	// Y���ص���������, Ĭ��ֵΪ.
	STDMETHOD(get_ZoomY)(float *retfloat);
	STDMETHOD(put_ZoomY)(float newfloat);

	// ��ȡ��������Դ, Ĭ��ֵΪ��.
	STDMETHOD(get_ReadBuffer)(LONG *retLONG);
	STDMETHOD(put_ReadBuffer)(LONG newLONG);

	// ����һάӳ��, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseMap1)(BOOL *retBOOL);
	STDMETHOD(put_UseMap1)(BOOL newBOOL);

	// �����άӳ��, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_UseMap2)(BOOL *retBOOL);
	STDMETHOD(put_UseMap2)(BOOL newBOOL);

	// ��άӳ���������ڵ�, Ĭ��ֵΪ1;0,1.
	STDMETHOD(get_Map2GridDomain)(float *retfloat);

	// һάӳ���������ļ����Ŀ, Ĭ��ֵΪ1.
	STDMETHOD(get_Map1GridSegments)(float *retfloat);

	// ��άӳ���������ļ����Ŀ, Ĭ��ֵΪ1,1.
	STDMETHOD(get_Map2GridSegments)(float *retfloat);

	// �Ƿ������Զ���ⷨ����, Ĭ��ֵΪCEE3D_FALSE.
	STDMETHOD(get_AutoNormalize)(BOOL *retBOOL);
	STDMETHOD(put_AutoNormalize)(BOOL newBOOL);

	// ͸��У��������ģʽ, Ĭ��ֵΪCEE3D_DONT_CARE.
	STDMETHOD(get_PerspectiveCorrectionHint)(LONG *retLONG);
	STDMETHOD(put_PerspectiveCorrectionHint)(LONG newLONG);

	// �������������ģʽ, Ĭ��ֵΪCEE3D_DONT_CARE.
	STDMETHOD(get_PointSmoothHint)(LONG *retLONG);

	// �������ߵ�����ģʽ, Ĭ��ֵΪCEE3D_DONT_CARE.
	STDMETHOD(get_LineSmoothHint)(LONG *retLONG);

	// ����������ε�����ģʽ, Ĭ��ֵΪCEE3D_DONT_CARE.
	STDMETHOD(get_PolygonSmoothHint)(LONG *retLONG);

	// �������ģʽ, Ĭ��ֵΪCEE3D_DONT_CARE.
	STDMETHOD(get_FogHint)(LONG *retLONG);

	// ��Դ��Ŀ�����ֵ, Ĭ��ֵΪ8.
	STDMETHOD(get_MaxLights)(LONG *retLONG);

	// ����ƽ������ֵ, Ĭ��ֵΪ6.
	STDMETHOD(get_MaxClipPlanes)(LONG *retLONG);

	// ģ��ȡ�������ջ��������, Ĭ��ֵΪ32.
	STDMETHOD(get_MaxModelViewStackDepth)(LONG *retLONG);

	// ͶӰ�����ջ��������, Ĭ��ֵΪ2.
	STDMETHOD(get_MaxProjectionStackDepth)(LONG *retLONG);

	// ��������ջ��������, Ĭ��ֵΪ2.
	STDMETHOD(get_MaxTextureStackDepth)(LONG *retLONG);

	// �����ص���λ��, Ĭ��ֵΪ4.
	STDMETHOD(get_SubPixelBits)(LONG *retLONG);

	// ����ͼ������ߴ�, Ĭ��ֵΪ64.
	STDMETHOD(get_MaxTextureSize)(LONG *retLONG);

	// ��ʾ�б�Ƕ�׵�������, Ĭ��ֵΪ64.
	STDMETHOD(get_MaxListNesting)(LONG *retLONG);

	// ��ֵ��֧�ֵ���󷽳̽���, Ĭ��ֵΪ8.
	STDMETHOD(get_MaxEvalOrder)(LONG *retLONG);

	// �Ӵ�֧�ֵ����ߴ�, Ĭ��ֵΪ��.
	STDMETHOD(get_MaxViewportDims)(LONG *retLONG);

	// ���Զ�ջ������, Ĭ��ֵΪ16.
	STDMETHOD(get_MaxAttribStackDepth)(LONG *retLONG);

	// ��ɫ״̬, Ĭ��ֵΪ��.
	STDMETHOD(get_InRGBAMode)(BOOL *retBOOL);
	STDMETHOD(put_InRGBAMode)(BOOL newBOOL);

	// ����ɫ״̬, Ĭ��ֵΪ��.
	STDMETHOD(get_InColorIndexMode)(BOOL *retBOOL);
	STDMETHOD(put_InColorIndexMode)(BOOL newBOOL);

	// �Ƿ�֧��˫������, Ĭ��ֵΪ��.
	STDMETHOD(get_SupportDoubleBuffer)(BOOL *retBOOL);
	STDMETHOD(put_SupportDoubleBuffer)(BOOL newBOOL);

	// �Ƿ�֧�����һ�����, Ĭ��ֵΪ��.
	STDMETHOD(get_SupportStereo)(BOOL *retBOOL);

	// ��������ĳߴ緶Χ, Ĭ��ֵΪ1,1.
	STDMETHOD(get_PointSizeRange)(float *retfloat);

	// �����������ڳߴ�Ĳ��, Ĭ��ֵΪ��.
	STDMETHOD(get_PointSizeGranularity)(float *retfloat);

	// �������ߵĳߴ緶Χ, Ĭ��ֵΪ1,1.
	STDMETHOD(get_LineWidthRange)(float *retfloat);

	// �����������ڳߴ�Ĳ��, Ĭ��ֵΪ��.
	STDMETHOD(get_LineWidthGranularity)(float *retfloat);

	// ��ɫ�������ĺ�ɫλƽ����Ŀ, Ĭ��ֵΪ��.
	STDMETHOD(get_RedBits)(LONG *retLONG);

	// ��ɫ����������ɫλƽ����Ŀ, Ĭ��ֵΪ��.
	STDMETHOD(get_GreenBits)(LONG *retLONG);

	// ��ɫ����������ɫλƽ����Ŀ, Ĭ��ֵΪ��.
	STDMETHOD(get_BlueBits)(LONG *retLONG);

	// ��ɫ�������Ħ�λƽ����Ŀ, Ĭ��ֵΪ��.
	STDMETHOD(get_AlphaBits)(LONG *retLONG);

	// ����ɫ��������λƽ����Ŀ, Ĭ��ֵΪ��.
	STDMETHOD(get_IndexBits)(LONG *retLONG);

	// ��Ȼ�������λƽ����Ŀ, Ĭ��ֵΪ��.
	STDMETHOD(get_DepthBits)(LONG *retLONG);

	// ģ�滺������λƽ����Ŀ, Ĭ��ֵΪ��.
	STDMETHOD(get_StencilBits)(LONG *retLONG);

	// �ۼӻ������ĺ�ɫλƽ����Ŀ, Ĭ��ֵΪ��.
	STDMETHOD(get_AccumRedBits)(LONG *retLONG);

	// �ۼӻ���������ɫλƽ����Ŀ, Ĭ��ֵΪ��.
	STDMETHOD(get_AccumGreenBits)(LONG *retLONG);

	// �ۼӻ���������ɫλƽ����Ŀ, Ĭ��ֵΪ��.
	STDMETHOD(get_AccumBlueBits)(LONG *retLONG);

	// �ۼӻ������Ħ�λƽ����Ŀ, Ĭ��ֵΪ��.
	STDMETHOD(get_AccumAlphaBits)(LONG *retLONG);

	// ��ʾ�б�����, Ĭ��ֵΪ0.
	STDMETHOD(get_CallListBase)(LONG *retLONG);

	// ��ǰ��ʾ�б�����, Ĭ��ֵΪ0.
	STDMETHOD(get_CallListIndex)(LONG *retLONG);
	STDMETHOD(put_CallListIndex)(LONG newLONG);

	// �������ʾ�б�ģʽ, Ĭ��ֵΪ0.
	STDMETHOD(get_CallListMode)(LONG *retLONG);
	STDMETHOD(put_CallListMode)(LONG newLONG);

	// ���Զ�ջ���ָ��, Ĭ��ֵΪ0.
	STDMETHOD(get_CurrentAttribStackDepth)(LONG *retLONG);

	// ���ƶ�ջ���, Ĭ��ֵΪ0.
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
