
#pragma once

class CeE3DAux :
	public CComObjectRoot,
	public CComCoClass<CeE3DAux, &CLSID_CeE3DAux>,
	public IDispatchImpl<ICeE3DAux, &IID_ICeE3DAux> {
public:
	CeE3DAux();
	virtual ~CeE3DAux();

	STDMETHOD(get_hE3D)(HGLRC *hglrc);
	STDMETHOD(get_PixelFormatDescriptor)(LPPIXELFORMATDESCRIPTOR ppfd);
	STDMETHOD(put_PixelFormatDescriptor)(LPPIXELFORMATDESCRIPTOR ppfd);
	STDMETHOD(get_PFlags)(LONG *pFlags);
	STDMETHOD(put_PFlags)(LONG flags);

	STDMETHOD(InitDC)(HDC hDC, BOOL *ret);
	STDMETHOD(Endup)();

	STDMETHOD(SetPixelFormat)(HDC hDC, LPPIXELFORMATDESCRIPTOR ppfd, BOOL *ret);
	STDMETHOD(GetPixelFormat)(HDC hDC, LONG index, BOOL *ret);
	STDMETHOD(ApplyPixelFormatTo)(HDC hDC, BOOL *ret);

	STDMETHOD(DrawBegin)(HDC hDC, BOOL *ret);
	STDMETHOD(DrawEnd)(HDC hDC, BOOL *ret);

	STDMETHOD(ClearAll)();

	STDMETHOD(InitDisplayMode)(GLenum);
	STDMETHOD(InitPosition)(LONG, LONG, LONG, LONG);
	STDMETHOD(InitWindow)(BSTR, GLenum *retval);

	STDMETHOD(CloseWindow)();
	STDMETHOD(Quit)();
	STDMETHOD(SwapBuffers)();

	STDMETHOD(MainLoop)(CEE3DMAINPROC);
	STDMETHOD(ExposeFunc)(CEE3DEXPOSEPROC);
	STDMETHOD(ReshapeFunc)(CEE3DRESHAPEPROC);
	STDMETHOD(IdleFunc)(CEE3DIDLEPROC);
	STDMETHOD(KeyFunc)(int, CEE3DKEYPROC);
	STDMETHOD(MouseFunc)(int, int, CEE3DMOUSEPROC);

	STDMETHOD(GetColorMapSize)(LONG *);
	STDMETHOD(GetMouseLoc)(LONG *, LONG *);
	STDMETHOD(SetOneColor)(LONG, float, float, float);
	STDMETHOD(SetFogRamp)(LONG, LONG);
	STDMETHOD(SetGreyRamp)();
	STDMETHOD(SetRGBMap)(LONG, float *);

	STDMETHOD(CreateFont)();

	STDMETHOD(DrawStr)(BSTR);
	STDMETHOD(DrawWireSphere)(GLdouble);
	STDMETHOD(DrawSolidSphere)(GLdouble);
	STDMETHOD(DrawWireCube)(GLdouble);
	STDMETHOD(DrawSolidCube)(GLdouble);
	STDMETHOD(DrawWireBox)(GLdouble, GLdouble, GLdouble);
	STDMETHOD(DrawSolidBox)(GLdouble, GLdouble, GLdouble);
	STDMETHOD(DrawWireTorus)(GLdouble, GLdouble);
	STDMETHOD(DrawSolidTorus)(GLdouble, GLdouble);
	STDMETHOD(DrawWireCylinder)(GLdouble, GLdouble);
	STDMETHOD(DrawSolidCylinder)(GLdouble, GLdouble);
	STDMETHOD(DrawWireIcosahedron)(GLdouble);
	STDMETHOD(DrawSolidIcosahedron)(GLdouble);
	STDMETHOD(DrawWireOctahedron)(GLdouble);
	STDMETHOD(DrawSolidOctahedron)(GLdouble);
	STDMETHOD(DrawWireTetrahedron)(GLdouble);
	STDMETHOD(DrawSolidTetrahedron)(GLdouble);
	STDMETHOD(DrawWireDodecahedron)(GLdouble);
	STDMETHOD(DrawSolidDodecahedron)(GLdouble);
	STDMETHOD(DrawWireCone)(GLdouble, GLdouble);
	STDMETHOD(DrawSolidCone)(GLdouble, GLdouble);
	STDMETHOD(DrawWireTeapot)(GLdouble);
	STDMETHOD(DrawSolidTeapot)(GLdouble);

	STDMETHOD(GetHWND)(HWND *);
	STDMETHOD(GetHDC)(HDC *);
	STDMETHOD(GetHGLRC)(HGLRC *);

	STDMETHOD(InitDisplayModePolicy)(GLenum);
	STDMETHOD(InitDisplayModeID)(GLint, GLenum *);
	STDMETHOD(GetDisplayModePolicy)(GLenum *);
	STDMETHOD(GetDisplayModeID)(GLint *);
	STDMETHOD(GetDisplayMode)(GLenum *);

	BEGIN_COM_MAP(CeE3DAux)
		COM_INTERFACE_ENTRY2(IDispatch, ICeE3DAux)
		COM_INTERFACE_ENTRY(ICeE3DAux)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CeE3DAux)
	DECLARE_NOT_AGGREGATABLE(CeE3DAux)

protected:
	HDC	m_hDC;
	HGLRC	m_hglrc;
	PIXELFORMATDESCRIPTOR	m_pfd;
};

typedef CeE3DAux	*PCEE3DAUX, *LPCEE3DAUX;
