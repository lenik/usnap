
// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the CEE3DINPROC_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// CEE3DINPROC_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef CEE3DINPROC_EXPORTS
#define CEE3DINPROC_API __declspec(dllexport)
#else
#define CEE3DINPROC_API __declspec(dllimport)
#endif

typedef struct _CEE3D_EVENTREC {
    GLint event;
    GLint data[4];
} CEE3D_EVENTREC;

typedef void (_stdcall* CEE3DMAINPROC)(void);
typedef void (_stdcall* CEE3DEXPOSEPROC)(int, int);
typedef void (_stdcall* CEE3DRESHAPEPROC)(GLsizei, GLsizei);
typedef void (_stdcall* CEE3DIDLEPROC)(void);
typedef void (_stdcall* CEE3DKEYPROC)(void);
typedef void (_stdcall* CEE3DMOUSEPROC)(CEE3D_EVENTREC *);

typedef struct _CEE3D_RGBImageRec {
    GLint sizeX, sizeY;
    unsigned char *data;
} CEE3D_RGBImageRec;

CEE3DINPROC_API void _stdcall CeE3DInitDisplayMode(GLenum);
CEE3DINPROC_API void _stdcall CeE3DInitPosition(int, int, int, int);

GLenum CEE3DINPROC_API _stdcall CeE3DInitWindowA(LPCSTR);
GLenum CEE3DINPROC_API _stdcall CeE3DInitWindowW(LPCWSTR);

CEE3DINPROC_API void _stdcall CeE3DCloseWindow();
CEE3DINPROC_API void _stdcall CeE3DQuit();
CEE3DINPROC_API void _stdcall CeE3DSwapBuffers();

CEE3DINPROC_API void _stdcall CeE3DMainLoop(CEE3DMAINPROC);
CEE3DINPROC_API void _stdcall CeE3DExposeFunc(CEE3DEXPOSEPROC);
CEE3DINPROC_API void _stdcall CeE3DReshapeFunc(CEE3DRESHAPEPROC);
CEE3DINPROC_API void _stdcall CeE3DIdleFunc(CEE3DIDLEPROC);
CEE3DINPROC_API void _stdcall CeE3DKeyFunc(int, CEE3DKEYPROC);
CEE3DINPROC_API void _stdcall CeE3DMouseFunc(int, int, CEE3DMOUSEPROC);

CEE3DINPROC_API int  _stdcall CeE3DGetColorMapSize();
CEE3DINPROC_API void _stdcall CeE3DGetMouseLoc(int *, int *);
CEE3DINPROC_API void _stdcall CeE3DSetOneColor(int, float, float, float);
CEE3DINPROC_API void _stdcall CeE3DSetFogRamp(int, int);
CEE3DINPROC_API void _stdcall CeE3DSetGreyRamp();
CEE3DINPROC_API void _stdcall CeE3DSetRGBMap(int, float *);

CEE3DINPROC_API CEE3D_RGBImageRec * _stdcall CeE3DRGBImageLoadA(LPCSTR);
CEE3DINPROC_API CEE3D_RGBImageRec * _stdcall CeE3DRGBImageLoadW(LPCWSTR);
CEE3DINPROC_API CEE3D_RGBImageRec * _stdcall CeE3DDIBImageLoadA(LPCSTR);
CEE3DINPROC_API CEE3D_RGBImageRec * _stdcall CeE3DDIBImageLoadW(LPCWSTR);

CEE3DINPROC_API void _stdcall CeE3DCreateFont();
CEE3DINPROC_API void _stdcall CeE3DDrawStrA(LPCSTR);
CEE3DINPROC_API void _stdcall CeE3DDrawStrW(LPCWSTR);

CEE3DINPROC_API void _stdcall CeE3DWireSphere(GLdouble);
CEE3DINPROC_API void _stdcall CeE3DSolidSphere(GLdouble);
CEE3DINPROC_API void _stdcall CeE3DWireCube(GLdouble);
CEE3DINPROC_API void _stdcall CeE3DSolidCube(GLdouble);
CEE3DINPROC_API void _stdcall CeE3DWireBox(GLdouble, GLdouble, GLdouble);
CEE3DINPROC_API void _stdcall CeE3DSolidBox(GLdouble, GLdouble, GLdouble);
CEE3DINPROC_API void _stdcall CeE3DWireTorus(GLdouble, GLdouble);
CEE3DINPROC_API void _stdcall CeE3DSolidTorus(GLdouble, GLdouble);
CEE3DINPROC_API void _stdcall CeE3DWireCylinder(GLdouble, GLdouble);
CEE3DINPROC_API void _stdcall CeE3DSolidCylinder(GLdouble, GLdouble);
CEE3DINPROC_API void _stdcall CeE3DWireIcosahedron(GLdouble);
CEE3DINPROC_API void _stdcall CeE3DSolidIcosahedron(GLdouble);
CEE3DINPROC_API void _stdcall CeE3DWireOctahedron(GLdouble);
CEE3DINPROC_API void _stdcall CeE3DSolidOctahedron(GLdouble);
CEE3DINPROC_API void _stdcall CeE3DWireTetrahedron(GLdouble);
CEE3DINPROC_API void _stdcall CeE3DSolidTetrahedron(GLdouble);
CEE3DINPROC_API void _stdcall CeE3DWireDodecahedron(GLdouble);
CEE3DINPROC_API void _stdcall CeE3DSolidDodecahedron(GLdouble);
CEE3DINPROC_API void _stdcall CeE3DWireCone(GLdouble, GLdouble);
CEE3DINPROC_API void _stdcall CeE3DSolidCone(GLdouble, GLdouble);
CEE3DINPROC_API void _stdcall CeE3DWireTeapot(GLdouble);
CEE3DINPROC_API void _stdcall CeE3DSolidTeapot(GLdouble);
CEE3DINPROC_API HWND _stdcall CeE3DGetHWND();
CEE3DINPROC_API HDC  _stdcall CeE3DGetHDC();
CEE3DINPROC_API HGLRC _stdcall CeE3DGetHGLRC();
CEE3DINPROC_API void _stdcall CeE3DInitDisplayModePolicy(GLenum);
CEE3DINPROC_API GLenum _stdcall CeE3DInitDisplayModeID(GLint);
CEE3DINPROC_API GLenum _stdcall CeE3DGetDisplayModePolicy();
CEE3DINPROC_API GLint _stdcall CeE3DGetDisplayModeID();
CEE3DINPROC_API GLenum _stdcall CeE3DGetDisplayMode();
