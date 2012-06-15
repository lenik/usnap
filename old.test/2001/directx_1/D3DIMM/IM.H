
#define INITGUID

#include <math.h>
#include <assert.h>
#include <ddraw.h>
#include <d3d.h>

#include "resource.h"

#define WINDOW_CLASSNAME		"D3DImmediateModeWindowClass"
#define WINDOW_TITLE			"Direct 3D Immediate Mode Example"
#define PAUSED_STRING			"Paused"

#define HALF_HEIGHT				D3DVAL(0.5)
#define FRONT_CLIP				D3DVAL(1.0)
#define BACK_CLIP				D3DVAL(1000.0)
#define WINDOW_WIDTH			320
#define WINDOW_HEIGHT			200

#define MAX_DEVICE_NAME			256
#define MAX_DEVICE_DESC			256

#define M_PI					3.14159265358979
#define M_2PI					6.28318530718
#define ROTATE_ANGLE_DELTA		(M_2PI / 360.0)

#define NUM_VERTICES			3
#define NUM_INSTRUCTIONS		6
#define NUM_STATES				7
#define NUM_PROCESSVERTICES		1
#define NUM_TRIANGLES			1

#define CODEFROMHRESULT(hRes)	((hRes) & 0x0000FFFF)

#ifdef _DEBUG
#	define ASSERT(x)			assert(x)
#else
#	define ASSERT(x)
#endif

#define USE_PARAM(x)			(x) = (x)

static HINSTANCE	hAppInstance	= NULL;
static BOOL			fDebug			= FALSE;
static BOOL			fActive			= TRUE;
static BOOL			fSuspended		= FALSE;

static LPDIRECTDRAW				lpdd					= NULL;
static LPDIRECTDRAWSURFACE		lpddsPrimary			= NULL;
static LPDIRECTDRAWSURFACE		lpddsDevice				= NULL;
static LPDIRECTDRAWSURFACE		lpddsZBuffer			= NULL;
static LPDIRECTDRAWPALETTE		lpddpPalette			= NULL;

static LPDIRECT3D				lpd3d					= NULL;
static LPDIRECT3DDEVICE			lpd3dDevice				= NULL;
static LPDIRECT3DMATERIAL		lpd3dMaterial			= NULL;
static LPDIRECT3DMATERIAL		lpd3dBackgroundMaterial	= NULL;
static LPDIRECT3DVIEWPORT		lpd3dViewport			= NULL;
static LPDIRECT3DLIGHT			lpd3dLight				= NULL;
static LPDIRECT3DEXECUTEBUFFER	lpd3dExecuteBuffer		= NULL;

static D3DMATRIXHANDLE			hd3dWorldMatrix			= 0;
static D3DMATRIXHANDLE			hd3dViewMatrix			= 0;
static D3DMATRIXHANDLE			hd3dProjMatrix			= 0;
static D3DMATERIALHANDLE		hd3dSurfaceMaterial		= 0;
static D3DMATERIALHANDLE		hd3dBackgroundMaterial	= 0;

static BOOL						fDeviceFound			= FALSE;
static DWORD					dwDeviceBitDepth		= 0;
static GUID						guidDevice;
static char						szDeviceName[MAX_DEVICE_NAME];
static char						szDeviceDesc[MAX_DEVICE_DESC];
static D3DDEVICEDESC			d3dHWDeviceDesc;
static D3DDEVICEDESC			d3dSWDeviceDesc;

static RECT						rDstRect;
static RECT						rSrcRect;

static double					dAngleOfRotation		= 0.0;

static D3DMATRIX				d3dWorldMatrix			= {
	D3DVAL(1.0), D3DVAL(0.0), D3DVAL(0.0), D3DVAL(0.0),
	D3DVAL(0.0), D3DVAL(1.0), D3DVAL(0.0), D3DVAL(0.0),
	D3DVAL(0.0), D3DVAL(0.0), D3DVAL(1.0), D3DVAL(0.0),
	D3DVAL(0.0), D3DVAL(0.0), D3DVAL(0.0), D3DVAL(1.0)
};

static D3DMATRIX				d3dViewMatrix			= {
	D3DVAL(1.0), D3DVAL(0.0), D3DVAL(0.0), D3DVAL(0.0),
	D3DVAL(0.0), D3DVAL(1.0), D3DVAL(0.0), D3DVAL(0.0),
	D3DVAL(0.0), D3DVAL(0.0), D3DVAL(1.0), D3DVAL(0.0),
	D3DVAL(0.0), D3DVAL(0.0), D3DVAL(5.0), D3DVAL(1.0)
};

static D3DMATRIX				d3dProjMatrix			= {
	D3DVAL(2.0), D3DVAL(0.0), D3DVAL(0.0), D3DVAL(0.0),
	D3DVAL(0.0), D3DVAL(2.0), D3DVAL(0.0), D3DVAL(0.0),
	D3DVAL(0.0), D3DVAL(0.0), D3DVAL(1.0), D3DVAL(1.0),
	D3DVAL(0.0), D3DVAL(0.0), D3DVAL(-1.0), D3DVAL(1.0)
};

static void ReportError(HWND hwnd, int nMessage, HRESULT hRes);
static void FatalError(HWND hwnd, int nMessage, HRESULT hRes);

static DWORD BitDepthToFlags(DWORD dwBitDepth);
static DWORD FlagsToBitDepth(DWORD dwFlags);

static void SetPerspectiveProjection(LPD3DMATRIX lpd3dMatrix,
									 double dHalfHeight,
									 double dFrontClipping,
									 double dBackClipping);
static void SetRotationAboutY(LPD3DMATRIX lpd3dMatrix,
							  double dAngleOfRotation);

static HRESULT CreateDirect3D(HWND hwnd);
static HRESULT ReleaseDirect3D(void);

static HRESULT CreatePrimary(HWND hwnd);
static HRESULT RestorePrimary(void);
static HRESULT ReleasePrimary(void);

static HRESULT WINAPI EnumDeviceCallback(LPGUID lpGUID,
										 LPSTR lpszDeviceDesc,
										 LPSTR lpszDeviceName,
										 LPD3DDEVICEDESC lpd3dHWDeviceDesc,
										 LPD3DDEVICEDESC lpd3dSWDeviceDesc,
										 LPVOID lpUserArg);
static HRESULT ChooseDevice(void);

static HRESULT CreateDevice(DWORD dwWidth, DWORD dwHeight);
static HRESULT RestoreDevice(void);
static HRESULT ReleaseDevice(void);

static LRESULT RestoreSurfaces(void);

static HRESULT FillExecuteBuffer(void);
static HRESULT CreateScene(void);
static HRESULT ReleaseScene(void);
static HRESULT AnimateScene(void);

static HRESULT UpdateViewport(void);

static HRESULT RenderScene(void);
static HRESULT DoFrame(void);
static void PaintSuspended(HWND hwnd, HDC hdc);

static LRESULT OnMove(HWND hwnd, int x, int y);
static LRESULT OnSize(HWND hwnd, int w, int h);
static LRESULT OnPaint(HWND hwnd, HDC hdc, LPPAINTSTRUCT Lpps);
static LRESULT OnIdle(HWND hwnd);

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
int PASCAL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCommandLine, int cmdShow);
