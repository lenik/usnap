// D3DIMM.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#ifdef _DEBUG
#define static
#endif

#include "im.h"

int PASCAL WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpszCommandLine,
                     int       nCmdShow)
{
	WNDCLASS	wc;
	HWND		hwnd;
	MSG			msg;

	USE_PARAM(hPrevInstance);

	hAppInstance = hInstance;
	if (*lpszCommandLine != 0) fDebug = TRUE;

	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(hAppInstance, MAKEINTRESOURCE(IDI_APPICON));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASSNAME;

	RegisterClass(&wc);

	hwnd = CreateWindow(
		WINDOW_CLASSNAME,
		WINDOW_TITLE,
		WS_OVERLAPPED | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (TRUE) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message = WM_QUIT) break;
			else {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		} else {
			OnIdle(hwnd);
		}
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	HDC			hdc;
	PAINTSTRUCT ps;
	LRESULT		lResult;
	HRESULT		hRes;
	char		szBuffer[128];

	switch (msg) {
	case WM_CREATE:
			hRes = CreateDirect3D(hwnd);
			if (FAILED(hRes)) {
				ReportError(hwnd, IDS_ERRMSG_CREATEDEVICE, hRes);
				ReleaseDirect3D();
				return -1L;
			}
			hRes = CreatePrimary(hwnd);
			if (FAILED(hRes)) {
				ReportError(hwnd, IDS_ERRMSG_INITSCREEN, hRes);
				ReleasePrimary();
				ReleaseDirect3D();
				return -1L;
			}
			hRes = ChooseDevice();
			if (FAILED(hRes)) {
				ReportError(hwnd, IDS_ERRMSG_NODEVICE, hRes);
				ReleasePrimary();
				ReleaseDirect3D();
				return -1L;
			}
			wsprintf(szBuffer, "%s: %s", WINDOW_TITLE, szDeviceName);
			SetWindowText(hwnd, szBuffer);

			return 0L;
	case WM_MOVE:
		return OnMove(hwnd, (int)LOWORD(lParam), (int)HIWORD(lParam));
	case WM_SIZE:
		return OnSize(hwnd, (int)LOWORD(lParam), (int)HIWORD(lParam));
	case WM_ERASEBKGND:
		return 1L;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		lResult = OnPaint(hwnd, hdc, &ps);
		EndPaint(hwnd, &ps);
		return lResult;
	case WM_ACTIVATEAPP:
		fActive = (BOOL)wParam;
		if (fActive && !fSuspended && (lpddpPalette != NULL)) {
			hRes = lpddsPrimary->SetPalette(lpddpPalette);
			if (FAILED(hRes)) {
				FatalError(hwnd, IDS_ERRMSG_REALIZEPALETTE, hRes);
				return 0L;
			}
		} else {
			InvalidateRect(hwnd, NULL, FALSE);
		}
		return 0L;
	case WM_KEYUP:
		if ((int)wParam == VK_ESCAPE) {
			DestroyWindow(hwnd);
			return 0L;
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		return 0L;
	case WM_DESTROY:
		ReleaseScene();
		ReleaseDevice();
		ReleasePrimary();
		ReleaseDirect3D();

		PostQuitMessage(0);
		return 0L;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

static HRESULT WINAPI EnumDeviceCallback(LPGUID lpGUID,
								  LPSTR lpszDeviceDesc,
								  LPSTR lpszDeviceName,
								  LPD3DDEVICEDESC lpd3dHWDeviceDesc,
								  LPD3DDEVICEDESC lpd3dSWDeviceDesc,
								  LPVOID lpUserArg) {
	BOOL			fIsHardware;
	LPD3DDEVICEDESC	lpd3dDeviceDesc;

	USE_PARAM(lpUserArg);
	if (lpd3dHWDeviceDesc->dcmColorModel == 0)
		fIsHardware = FALSE;
	else
		fIsHardware = TRUE;
	lpd3dDeviceDesc = fIsHardware ? lpd3dHWDeviceDesc : lpd3dSWDeviceDesc;

	if (fDebug && fIsHardware)
		return D3DENUMRET_OK;

	if ((lpd3dDeviceDesc->dwDeviceRenderBitDepth & dwDeviceBitDepth) == 0) {
		return D3DENUMRET_OK;
	}

	if (lpd3dDeviceDesc->dcmColorModel == D3DCOLOR_MONO) {
		if (!(lpd3dDeviceDesc->dpcTriCaps.dwShadeCaps & D3DPSHADECAPS_COLORGOURAUDMONO))
			return D3DENUMRET_OK;
	} else {
		if (!(lpd3dDeviceDesc->dpcTriCaps.dwShadeCaps & D3DPSHADECAPS_COLORGOURAUDRGB))
			return D3DENUMRET_OK;
	}

	if (!fIsHardware && fDeviceFound &&
		(lpd3dDeviceDesc->dcmColorModel == D3DCOLOR_RGB)) {
		return D3DENUMRET_OK;
	}

	fDeviceFound = TRUE;
	CopyMemory(&guidDevice, lpGUID, sizeof(GUID));
	strcpy(szDeviceDesc, lpszDeviceDesc);
	strcpy(szDeviceName, lpszDeviceName);

	if (fIsHardware)
		return D3DENUMRET_CANCEL;

	return D3DENUMRET_OK;
}

static HRESULT ChooseDevice(void) {
	DDSURFACEDESC ddsd;
	HRESULT hRes;

	ASSERT(lpd3d != NULL);
	ASSERT(lpddsPrimary != NULL);

	ZeroMemory(&ddsd, sizeof(ddsd));
	ddsd.dwSize = sizeof(ddsd);
	hRes = lpddsPrimary->GetSurfaceDesc(&ddsd);
	if (FAILED(hRes))
		return hRes;

	dwDeviceBitDepth = BitDepthToFlags(ddsd.ddpfPixelFormat.dwRGBBitCount);

	fDeviceFound = FALSE;
	hRes = lpd3d->EnumDevices(EnumDeviceCallback, &fDeviceFound);

	if (FAILED(hRes)) return hRes;

	if (!fDeviceFound) return DDERR_NOTFOUND;

	return DD_OK;
}

static HRESULT CreatePrimary(HWND hwnd) {
	HRESULT				hRes;
	DDSURFACEDESC		ddsd;
	LPDIRECTDRAWCLIPPER	lpddClipper;
	HDC					hdc;
	int					i;
	PALETTEENTRY		peColorTable[256];

	ASSERT(hwnd != NULL);
	ASSERT(lpdd != NULL);
	ASSERT(lpddsPrimary == NULL);
	ASSERT(lpddpPalette == NULL);

	ZeroMemory(&ddsd, sizeof(ddsd));
	ddsd.dwSize = sizeof(ddsd);
	ddsd.dwFlags = DDSD_CAPS;
	ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
	hRes = lpdd->CreateSurface(&ddsd, &lpddsPrimary, NULL);
	if (FAILED(hRes)) return hRes;
	hRes = lpdd->CreateClipper(0, &lpddClipper, NULL);
	if (FAILED(hRes)) return hRes;
	hRes = lpddClipper->SetHWnd(0, hwnd);
	if (FAILED(hRes)) {
		lpddClipper->Release();
		return hRes;
	}
	if (FAILED(hRes)) return hRes;
	hRes = lpddsPrimary->SetClipper(lpddClipper);
	if (FAILED(hRes)) {
		lpddClipper->Release();
		return hRes;
	}

	lpddClipper->Release();

	ZeroMemory(&ddsd, sizeof(ddsd));
	ddsd.dwSize = sizeof(ddsd);
	hRes = lpddsPrimary->GetSurfaceDesc(&ddsd);
	if (FAILED(hRes)) return hRes;
	if (ddsd.ddpfPixelFormat.dwFlags & DDPF_PALETTEINDEXED8) {
		hdc = GetDC(NULL);
		GetSystemPaletteEntries(hdc, 0, 256, peColorTable);
		ReleaseDC(NULL, hdc);

		for (i = 0; i < 10; i++)
			peColorTable[i].peFlags = D3DPAL_READONLY;
		for (i = 10; i < 246; i++)
			peColorTable[i].peFlags = D3DPAL_FREE | PC_RESERVED;
		for (i = 246; i < 256; i++)
			peColorTable[i].peFlags = D3DPAL_READONLY;

		hRes = lpdd->CreatePalette(DDPCAPS_8BIT, peColorTable, &lpddpPalette, NULL);
		if (FAILED(hRes)) return hRes;
		hRes = lpddsPrimary->SetPalette(lpddpPalette);
		return hRes;
	}
	return DD_OK;
}

static HRESULT CreateDirect3D(HWND hwnd) {
	HRESULT hRes;

	ASSERT(lpdd == NULL);
	ASSERT(lpd3d == NULL);

	hRes = DirectDrawCreate(NULL, &lpdd, NULL);
	if (FAILED(hRes)) return hRes;
	hRes = lpdd->SetCooperativeLevel(hwnd, DDSCL_NORMAL);
	if (FAILED(hRes)) return hRes;

	hRes = lpdd->QueryInterface(IID_IDirect3D, (LPVOID *)&lpd3d);
	if (FAILED(hRes)) return hRes;

	return DD_OK;
}

static HRESULT CreateDevice(DWORD dwWidth, DWORD dwHeight) {
	LPD3DDEVICEDESC	lpd3dDeviceDesc;
	DWORD			dwDeviceMemType;
	DWORD			dwZBufferMemType;
	DDSURFACEDESC	ddsd;
	HRESULT			hRes;
	DWORD			dwZBufferBitDepth;

	ASSERT(lpdd != NULL);
	ASSERT(lpd3d != NULL);
	ASSERT(lpddsPrimary != NULL);
	ASSERT(lpddsDevice == NULL);
	ASSERT(lpd3dDevice == NULL);

	if (d3dHWDeviceDesc.dcmColorModel != 0) {
		lpd3dDeviceDesc = &d3dHWDeviceDesc;

		dwDeviceMemType = DDSCAPS_VIDEOMEMORY;
		dwZBufferMemType = DDSCAPS_VIDEOMEMORY;
	} else {
		lpd3dDeviceDesc = &d3dSWDeviceDesc;

		dwDeviceMemType = (fDebug ? DDSCAPS_SYSTEMMEMORY : 0);
		dwZBufferMemType = DDSCAPS_SYSTEMMEMORY;
	}

	ZeroMemory(&ddsd, sizeof(ddsd));
	ddsd.dwSize = sizeof(ddsd);
	ddsd.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;
	ddsd.dwWidth = dwWidth;
	ddsd.dwHeight = dwHeight;
	ddsd.ddsCaps.dwCaps = DDSCAPS_3DDEVICE | DDSCAPS_OFFSCREENPLAIN | dwDeviceMemType;
	hRes = lpdd->CreateSurface(&ddsd, &lpddsDevice, NULL);
	if (FAILED(hRes)) return hRes;

	if (lpddpPalette != NULL) {
		hRes = lpddsDevice->SetPalette(lpddpPalette);
		if (FAILED(hRes)) return hRes;
	}

	if (lpd3dDeviceDesc->dwDeviceZBufferBitDepth != 0) {
		dwZBufferBitDepth = FlagsToBitDepth(lpd3dDeviceDesc->dwDeviceZBufferBitDepth);
		ZeroMemory(&ddsd, sizeof(ddsd));
		ddsd.dwSize = sizeof(ddsd);
		ddsd.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT | DDSD_ZBUFFERBITDEPTH;
		ddsd.ddsCaps.dwCaps = DDSCAPS_ZBUFFER | dwZBufferMemType;
		ddsd.dwWidth = dwWidth;
		ddsd.dwHeight = dwHeight;
		ddsd.dwZBufferBitDepth = dwZBufferBitDepth;
		hRes = lpdd->CreateSurface(&ddsd, &lpddsZBuffer, NULL);
		if (FAILED(hRes)) return hRes;

		hRes = lpddsDevice->AddAttachedSurface(lpddsZBuffer);
		if (FAILED(hRes)) return hRes;
	}

	hRes = lpddsDevice->QueryInterface(guidDevice, (LPVOID *)&lpd3dDevice);
	if (FAILED(hRes)) return hRes;

	return DD_OK;
}

static HRESULT CreateScene(void) {
	HRESULT hRes;
	D3DMATERIAL				d3dMaterial;
	D3DLIGHT				d3dLight;
	DWORD					dwVertexSize;
	DWORD					dwInstructionSize;
	DWORD					dwExecuteBufferSize;
	D3DEXECUTEBUFFERDESC	d3dExecuteBufferDesc;
	D3DEXECUTEDATA			d3dExecuteData;

	ASSERT(lpd3d != NULL);
	ASSERT(lpd3dDevice != NULL);
	ASSERT(lpd3dViewport == NULL);
	ASSERT(lpd3dMaterial == NULL);
	ASSERT(lpd3dBackgroundMaterial == NULL);
	ASSERT(lpd3dExecuteBuffer == NULL);
	ASSERT(lpd3dLight == NULL);
	ASSERT(hd3dWorldMatrix == 0);
	ASSERT(hd3dViewMatrix == 0);
	ASSERT(hd3dProjMatrix == 0);

	hRes = lpd3d->CreateLight(&lpd3dLight, NULL);
	if (FAILED(hRes)) return hRes;
	ZeroMemory(&d3dLight, sizeof(d3dLight));
	d3dLight.dwSize = sizeof(d3dLight);
	d3dLight.dltType = D3DLIGHT_POINT;
	d3dLight.dcvColor.dvR = D3DVAL(1.0);
	d3dLight.dcvColor.dvG = D3DVAL(1.0);
	d3dLight.dcvColor.dvB = D3DVAL(1.0);
	d3dLight.dcvColor.dvA = D3DVAL(1.0);
	d3dLight.dvPosition.dvX = D3DVAL( 1.0);
	d3dLight.dvPosition.dvY = D3DVAL(-1.0);
	d3dLight.dvPosition.dvZ = D3DVAL(-1.0);
	d3dLight.dvAttenuation0 = D3DVAL(1.0);
	d3dLight.dvAttenuation1 = D3DVAL(0.1);
	d3dLight.dvAttenuation2 = D3DVAL(0.0);
	hRes = lpd3dLight->SetLight(&d3dLight);
	if (FAILED(hRes)) return hRes;

	hRes = lpd3d->CreateMaterial(&lpd3dBackgroundMaterial, NULL);
	if (FAILED(hRes)) return hRes;
	ZeroMemory(&d3dMaterial, sizeof(d3dMaterial));
	d3dMaterial.dwSize = sizeof(d3dMaterial);
	d3dMaterial.dcvDiffuse.r = D3DVAL(0.0);
	d3dMaterial.dcvDiffuse.g = D3DVAL(0.0);
	d3dMaterial.dcvDiffuse.b = D3DVAL(0.0);
	d3dMaterial.dcvAmbient.r = D3DVAL(0.0);
	d3dMaterial.dcvAmbient.g = D3DVAL(0.0);
	d3dMaterial.dcvAmbient.b = D3DVAL(0.0);
	d3dMaterial.dcvSpecular.r = D3DVAL(0.0);
	d3dMaterial.dcvSpecular.g = D3DVAL(0.0);
	d3dMaterial.dcvSpecular.b = D3DVAL(0.0);
	d3dMaterial.dvPower		  = D3DVAL(0.0);
	d3dMaterial.dwRampSize = 1;
	hRes = lpd3dBackgroundMaterial->SetMaterial(&d3dMaterial);
	if (FAILED(hRes)) return hRes;
	hRes = lpd3dBackgroundMaterial->GetHandle(lpd3dDevice, &hd3dBackgroundMaterial);
	if (FAILED(hRes)) return hRes;

	hRes = lpd3d->CreateViewport(&lpd3dViewport, NULL);
	if (FAILED(hRes)) return hRes;
	hRes = lpd3dDevice->AddViewport(lpd3dViewport);
	if (FAILED(hRes)) return hRes;
	hRes = lpd3dViewport->SetBackground(hd3dBackgroundMaterial);
	if (FAILED(hRes)) return hRes;
	hRes = lpd3dViewport->AddLight(lpd3dLight);
	if (FAILED(hRes)) return hRes;

	hRes = lpd3dDevice->CreateMatrix(&hd3dWorldMatrix);
	if (FAILED(hRes)) return hRes;
	hRes = lpd3dDevice->SetMatrix(hd3dWorldMatrix, &d3dWorldMatrix);
	if (FAILED(hRes)) return hRes;
	hRes = lpd3dDevice->CreateMatrix(&hd3dViewMatrix);
	if (FAILED(hRes)) return hRes;
	hRes = lpd3dDevice->SetMatrix(hd3dViewMatrix, &d3dViewMatrix);
	if (FAILED(hRes)) return hRes;
	hRes = lpd3dDevice->CreateMatrix(&hd3dProjMatrix);
	if (FAILED(hRes)) return hRes;
	SetPerspectiveProjection(&d3dProjMatrix, HALF_HEIGHT, FRONT_CLIP, BACK_CLIP);
	hRes = lpd3dDevice->SetMatrix(hd3dProjMatrix, &d3dProjMatrix);
	if (FAILED(hRes)) return hRes;

	hRes = lpd3d->CreateMaterial(&lpd3dMaterial, NULL);
	if (FAILED(hRes)) return hRes;
	ZeroMemory(&d3dMaterial, sizeof(d3dMaterial));
	d3dMaterial.dwSize = sizeof(d3dMaterial);
	d3dMaterial.dcvDiffuse.r = D3DVAL(0.0);
	d3dMaterial.dcvDiffuse.g = D3DVAL(1.0);
	d3dMaterial.dcvDiffuse.b = D3DVAL(0.0);
	d3dMaterial.dcvAmbient.r = D3DVAL(0.0);
	d3dMaterial.dcvAmbient.g = D3DVAL(0.4);
	d3dMaterial.dcvAmbient.b = D3DVAL(0.0);
	d3dMaterial.dcvSpecular.r = D3DVAL(1.0);
	d3dMaterial.dcvSpecular.g = D3DVAL(1.0);
	d3dMaterial.dcvSpecular.b = D3DVAL(1.0);
	d3dMaterial.dvPower		 = D3DVAL(20.0);
	d3dMaterial.dwRampSize	 = 16;
	hRes = lpd3dMaterial->SetMaterial(&d3dMaterial);
	if (FAILED(hRes)) return hRes;
	hRes = lpd3dMaterial->GetHandle(lpd3dDevice, &hd3dSurfaceMaterial);
	if (FAILED(hRes)) return hRes;

	dwVertexSize		= (NUM_VERTICES			* sizeof(D3DVERTEX));
	dwInstructionSize	= (NUM_INSTRUCTIONS		* sizeof(D3DINSTRUCTION))		+
						  (NUM_STATES			* sizeof(D3DSTATE))				+
						  (NUM_PROCESSVERTICES	* sizeof(D3DPROCESSVERTICES))	+
						  (NUM_TRIANGLES		* sizeof(D3DTRIANGLE));
	dwExecuteBufferSize	= dwVertexSize + dwInstructionSize;
	ZeroMemory(&d3dExecuteBufferDesc, sizeof(d3dExecuteBufferDesc));
	d3dExecuteBufferDesc.dwSize			= sizeof(d3dExecuteBufferDesc);
	d3dExecuteBufferDesc.dwFlags		= D3DDEB_BUFSIZE;
	d3dExecuteBufferDesc.dwBufferSize	= dwExecuteBufferSize;
	hRes = lpd3dDevice->CreateExecuteBuffer(&d3dExecuteBufferDesc, &lpd3dExecuteBuffer, NULL);
	if (FAILED(hRes)) return hRes;

	hRes = FillExecuteBuffer();
	if (FAILED(hRes)) return hRes;

	ZeroMemory(&d3dExecuteData, sizeof(d3dExecuteData));
	d3dExecuteData.dwSize				= sizeof(d3dExecuteData);
	d3dExecuteData.dwVertexCount		= NUM_VERTICES;
	d3dExecuteData.dwInstructionOffset	= dwVertexSize;
	d3dExecuteData.dwInstructionLength	= dwInstructionSize;
	hRes = lpd3dExecuteBuffer->SetExecuteData(&d3dExecuteData);
	if (FAILED(hRes)) return hRes;

	return DD_OK;
}

static HRESULT FillExecuteBuffer(void) {
	HRESULT					hRes;
	D3DEXECUTEBUFFERDESC	d3dExeBufDesc;
	LPD3DVERTEX				lpVertex;
	LPD3DINSTRUCTION		lpInstruction;
	LPD3DPROCESSVERTICES	lpProcessVertices;
	LPD3DTRIANGLE			lpTriangle;
	LPD3DSTATE				lpState;

	ASSERT(lpd3dExecuteBuffer != NULL);
	ASSERT(hd3dSurfaceMaterial != 0);
	ASSERT(hd3dWorldMatrix != 0);
	ASSERT(hd3dViewMatrix != 0);
	ASSERT(hd3dProjMatrix != 0);

	ZeroMemory(&d3dExeBufDesc, sizeof(d3dExeBufDesc));
	d3dExeBufDesc.dwSize = sizeof(d3dExeBufDesc);
	hRes = lpd3dExecuteBuffer->Lock(&d3dExeBufDesc);
	if (FAILED(hRes)) return hRes;

	lpVertex = (LPD3DVERTEX)d3dExeBufDesc.lpData;

	lpVertex->dvX	= D3DVAL(0.0);
	lpVertex->dvY	= D3DVAL(1.0);
	lpVertex->dvZ	= D3DVAL(0.0);
	lpVertex->dvNX	= D3DVAL(0.0);
	lpVertex->dvNY	= D3DVAL(0.0);
	lpVertex->dvNZ	= D3DVAL(-1.0);
	lpVertex->dvTU	= D3DVAL(0.0);
	lpVertex->dvTV	= D3DVAL(1.0);
	lpVertex++;

	lpVertex->dvX	= D3DVAL(1.0);
	lpVertex->dvY	= D3DVAL(-1.0);
	lpVertex->dvZ	= D3DVAL(0.0);
	lpVertex->dvNX	= D3DVAL(0.0);
	lpVertex->dvNY	= D3DVAL(0.0);
	lpVertex->dvNZ	= D3DVAL(-1.0);
	lpVertex->dvTU	= D3DVAL(1.0);
	lpVertex->dvTV	= D3DVAL(1.0);
	lpVertex++;

	lpVertex->dvX	= D3DVAL(-1.0);
	lpVertex->dvY	= D3DVAL(-1.0);
	lpVertex->dvZ	= D3DVAL(0.0);
	lpVertex->dvNX	= D3DVAL(0.0);
	lpVertex->dvNY	= D3DVAL(0.0);
	lpVertex->dvNZ	= D3DVAL(-1.0);
	lpVertex->dvTU	= D3DVAL(1.0);
	lpVertex->dvTV	= D3DVAL(0.0);
	lpVertex++;

	lpInstruction			= (LPD3DINSTRUCTION)lpVertex;
	lpInstruction->bOpcode	= D3DOP_STATETRANSFORM;
	lpInstruction->bSize	= sizeof(D3DSTATE);
	lpInstruction->wCount	= 3U;
	lpInstruction++;
	lpState					= (LPD3DSTATE)lpInstruction;
	lpState->dtstTransformStateType	= D3DTRANSFORMSTATE_WORLD;
	lpState->dwArg[0]		= hd3dWorldMatrix;
	lpState++;
	lpState->dtstTransformStateType	= D3DTRANSFORMSTATE_VIEW;
	lpState->dwArg[0]		= hd3dViewMatrix;
	lpState++;
	lpState->dtstTransformStateType	= D3DTRANSFORMSTATE_PROJECTION;
	lpState->dwArg[0]		= hd3dProjMatrix;
	lpState++;

	lpInstruction			= (LPD3DINSTRUCTION)lpState;
	lpInstruction->bOpcode	= D3DOP_STATELIGHT;
	lpInstruction->bSize	= sizeof(D3DSTATE);
	lpInstruction->wCount	= 2U;
	lpInstruction++;
	lpState					= (LPD3DSTATE)lpInstruction;
	lpState->dlstLightStateType		= D3DLIGHTSTATE_MATERIAL;
	lpState->dwArg[0]		= hd3dSurfaceMaterial;
	lpState++;
	lpState->dlstLightStateType		= D3DLIGHTSTATE_AMBIENT;
	lpState->dwArg[0]		= RGBA_MAKE(128, 128, 128, 128);
	lpState++;

	lpInstruction			= (LPD3DINSTRUCTION)lpState;
	lpInstruction->bOpcode	= D3DOP_STATERENDER;
	lpInstruction->bSize	= sizeof(D3DSTATE);
	lpInstruction->wCount	= 3U;
	lpInstruction++;
	lpState					= (LPD3DSTATE)lpInstruction;
	lpState->drstRenderStateType	= D3DRENDERSTATE_FILLMODE;
	lpState->dwArg[0]		= D3DFILL_SOLID;
	lpState++;
	lpState->drstRenderStateType	= D3DRENDERSTATE_SHADEMODE;
	lpState->dwArg[0]		= D3DSHADE_GOURAUD;
	lpState++;
	lpState->drstRenderStateType	= D3DRENDERSTATE_DITHERENABLE;
	lpState->dwArg[0]		= TRUE;
	lpState++;

	lpInstruction			= (LPD3DINSTRUCTION)lpState;
	lpInstruction->bOpcode	= D3DOP_PROCESSVERTICES;
	lpInstruction->bSize	= sizeof(D3DPROCESSVERTICES);
	lpInstruction->wCount	= 1U;
	lpInstruction++;
	lpProcessVertices		= (LPD3DPROCESSVERTICES)lpInstruction;
	lpProcessVertices->dwFlags		= D3DPROCESSVERTICES_TRANSFORMLIGHT;
	lpProcessVertices->wStart		= 0U;
	lpProcessVertices->wDest		= 0U;
	lpProcessVertices->dwCount		= NUM_VERTICES;
	lpProcessVertices->dwReserved	= 0;
	lpProcessVertices++;

	lpInstruction			= (LPD3DINSTRUCTION)lpProcessVertices;
	lpInstruction->bOpcode	= D3DOP_TRIANGLE;
	lpInstruction->bSize	= sizeof(D3DTRIANGLE);
	lpInstruction->wCount	= 1U;
	lpInstruction++;
	lpTriangle				= (LPD3DTRIANGLE)lpInstruction;
	lpTriangle->wV1			= 0U;
	lpTriangle->wV2			= 1U;
	lpTriangle->wV3			= 2U;
	lpTriangle->wFlags		= D3DTRIFLAG_EDGEENABLETRIANGLE;
	lpTriangle++;

	lpInstruction			= (LPD3DINSTRUCTION)lpTriangle;
	lpInstruction->bOpcode	= D3DOP_EXIT;
	lpInstruction->bSize	= 0;
	lpInstruction->wCount	= 0U;

	lpd3dExecuteBuffer->Unlock();

	return DD_OK;
}

static HRESULT AnimateScene(void) {
	HRESULT hRes;

	ASSERT(lpd3dDevice != NULL);
	ASSERT(hd3dWorldMatrix != 0);

	SetRotationAboutY(&d3dWorldMatrix, dAngleOfRotation);
	dAngleOfRotation	+= ROTATE_ANGLE_DELTA;
	hRes = lpd3dDevice->SetMatrix(hd3dWorldMatrix, &d3dWorldMatrix);
	if (FAILED(hRes)) return hRes;

	return DD_OK;
}

static HRESULT RenderScene(void) {
	HRESULT hRes;
	D3DRECT d3dRect;

	ASSERT(lpd3dViewport != NULL);
	ASSERT(lpd3dDevice != NULL);
	ASSERT(lpd3dExecuteBuffer != NULL);

	d3dRect.lX1 = rSrcRect.left;
	d3dRect.lX2 = rSrcRect.right;
	d3dRect.lY1 = rSrcRect.top;
	d3dRect.lY2 = rSrcRect.bottom;
	hRes = lpd3dViewport->Clear(1, &d3dRect, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER);
	if (FAILED(hRes)) return hRes;

	hRes = lpd3dDevice->BeginScene();
	if (FAILED(hRes)) return hRes;

	hRes = lpd3dDevice->Execute(lpd3dExecuteBuffer, lpd3dViewport, D3DEXECUTE_CLIPPED);
	if (FAILED(hRes)) {
		lpd3dDevice->EndScene();
		return hRes;
	}

	hRes = lpd3dDevice->EndScene();
	if (FAILED(hRes)) return hRes;

	return DD_OK;
}

static HRESULT DoFrame(void) {
	HRESULT hRes;

	while (TRUE) {
		hRes = RenderScene();
		if (SUCCEEDED(hRes)) {
			hRes = lpddsPrimary->Blt(&rDstRect, lpddsDevice, &rSrcRect, DDBLT_WAIT, NULL);
			if (SUCCEEDED(hRes)) return hRes;
		}
		while (hRes == DDERR_SURFACELOST) hRes = RestoreSurfaces();
		if (FAILED(hRes)) return hRes;
	}
}

static void SetPerspectiveProjection(LPD3DMATRIX lpd3dMatrix,
									 double dHalfHeight,
									 double dFrontClipping,
									 double dBackClipping) {
	double dTmp1;
	double dTmp2;

	ASSERT(lpd3dMatrix != NULL);

	dTmp1 = dHalfHeight / dFrontClipping;
	dTmp2 = dBackClipping / (dBackClipping - dFrontClipping);

	D3DMATRIX	dmTmp = {
		D3DVAL(2.0), D3DVAL(0.0), D3DVAL(0.0), D3DVAL(0.0),
		D3DVAL(0.0), D3DVAL(2.0), D3DVAL(0.0), D3DVAL(0.0),
		D3DVAL(0.0), D3DVAL(0.0), D3DVAL(dTmp1 + dTmp2),
												D3DVAL(dTmp1),
		D3DVAL(0.0), D3DVAL(0.0), D3DVAL(-dHalfHeight + dTmp2),
												D3DVAL(0.0)
	};

	memcpy(lpd3dMatrix, &dmTmp, sizeof(D3DMATRIX));
}

static void SetRotationAboutY(LPD3DMATRIX lpd3dMatrix, double dAngleOfRotation) {
	D3DVALUE dvCos;
	D3DVALUE dvSin;

	ASSERT(lpd3dMatrix != NULL);

	dvCos = D3DVAL(cos(dAngleOfRotation));
	dvSin = D3DVAL(sin(dAngleOfRotation));

	D3DMATRIX dmTmp = {
		dvCos,			D3DVAL(0.0),	-dvSin,			D3DVAL(0.0),
		D3DVAL(0.0),	D3DVAL(1.0),	D3DVAL(0.0),	D3DVAL(0.0),
		dvSin,			D3DVAL(0.0),	dvCos,			D3DVAL(0.0),
		D3DVAL(0.0),	D3DVAL(0.0),	D3DVAL(0.0),	D3DVAL(1.0)
	};

	memcpy(lpd3dMatrix, &dmTmp, sizeof(D3DMATRIX));
}

static HRESULT RestoreDevice() {
	HRESULT hRes;

	if (lpddsZBuffer != NULL) {
		hRes = lpddsZBuffer->Restore();
		if (FAILED(hRes)) return hRes;
	}
	if (lpddsDevice != NULL) {
		hRes = lpddsDevice->Restore();
		if (FAILED(hRes)) return hRes;
	}

	return DD_OK;
}

static HRESULT RestorePrimary() {
	ASSERT(lpddsPrimary != NULL);
	return lpddsPrimary->Restore();
}

static HRESULT RestoreSurfaces(void) {
	HRESULT hRes;

	hRes = RestorePrimary();
	if (FAILED(hRes)) return hRes;

	hRes = RestoreDevice();
	if (FAILED(hRes)) return hRes;

	return DD_OK;
}

static LRESULT OnMove(HWND hwnd, int x, int y) {
	int		xDelta;
	int		yDelta;
	HRESULT hRes;

	if ((lpd3dDevice != NULL) && !fSuspended) {
		xDelta = x - rDstRect.left;
		yDelta = y - rDstRect.top;

		rDstRect.left	+= xDelta;
		rDstRect.top	+= yDelta;
		rDstRect.right	+= xDelta;
		rDstRect.bottom	+= yDelta;

		hRes = DoFrame();
		if (FAILED(hRes)) {
			FatalError(hwnd, IDS_ERRMSG_RENDERSCENE, hRes);
			return 0L;
		}
	}

	return 0L;
}

static LRESULT OnSize(HWND hwnd, int w, int h) {
	HRESULT			hRes;
	DDSURFACEDESC	ddsd;

	if (!fSuspended) {
		rDstRect.right	= rDstRect.left + w;
		rDstRect.bottom	= rDstRect.top + h;
		rSrcRect.right = w;
		rSrcRect.bottom = h;

		if (lpd3dDevice != NULL) {
			ZeroMemory(&ddsd, sizeof(ddsd));
			ddsd.dwSize = sizeof(ddsd);
			hRes = lpddsDevice->GetSurfaceDesc(&ddsd);
			if (FAILED(hRes)) {
				FatalError(hwnd, IDS_ERRMSG_DEVICESIZE, hRes);
				return 0L;
			}

			if ((w > (int)ddsd.dwWidth) || (h > (int)ddsd.dwHeight)) {
				ReleaseScene();
				ReleaseDevice();
			}
		}

		if (lpd3dDevice == NULL) {
			hRes = CreateDevice((DWORD)w, (DWORD)h);
			if (FAILED(hRes)) {
				FatalError(hwnd, IDS_ERRMSG_CREATEDEVICE, hRes);
				return 0L;
			}
			hRes = CreateScene();
			if (FAILED(hRes)) {
				FatalError(hwnd, IDS_ERRMSG_BUILDSCENE, hRes);
				return 0L;
			}
		}

		hRes = UpdateViewport();
		if (FAILED(hRes)) {
			FatalError(hwnd, IDS_ERRMSG_UPDATEVIEWPORT, hRes);
			return 0L;
		}

		hRes = DoFrame();
		if (FAILED(hRes)) {
			FatalError(hwnd, IDS_ERRMSG_RENDERSCENE, hRes);
			return 0L;
		}
	}
	return 0L;
}

static LRESULT OnPaint(HWND hwnd, HDC hdc, LPPAINTSTRUCT lpps) {
	HRESULT hRes;

	USE_PARAM(lpps);

	if (fActive && !fSuspended && (lpd3dDevice != NULL)) {
		hRes = DoFrame();
		if (FAILED(hRes)) {
			FatalError(hwnd, IDS_ERRMSG_RENDERSCENE, hRes);
			return 0L;
		}
	} else {
		PaintSuspended(hwnd, hdc);
	}
	return 0L;
}

static HRESULT UpdateViewport(void) {
	D3DVIEWPORT d3dViewport;

	ASSERT(lpd3dViewport != NULL);

	ZeroMemory(&d3dViewport, sizeof(d3dViewport));
	d3dViewport.dwSize		= sizeof(d3dViewport);
	d3dViewport.dwX			= 0;
	d3dViewport.dwY			= 0;
	d3dViewport.dwWidth		= (DWORD)rSrcRect.right;
	d3dViewport.dwHeight	= (DWORD)rSrcRect.bottom;
	d3dViewport.dvScaleX	= D3DVAL((float)d3dViewport.dwWidth / 2.0);
	d3dViewport.dvScaleY	= D3DVAL((float)d3dViewport.dwHeight / 2.0);
	d3dViewport.dvMaxX		= D3DVAL(1.0);
	d3dViewport.dvMaxY		= D3DVAL(1.0);
	return lpd3dViewport->SetViewport(&d3dViewport);
}

static HRESULT ReleaseDirect3D(void) {
	if (lpd3d != NULL) {
		lpd3d->Release();
		lpd3d = NULL;
	}

	if (lpdd != NULL) {
		lpdd->Release();
		lpdd = NULL;
	}

	return DD_OK;
}

static HRESULT ReleaseDevice(void) {
	if (lpd3dDevice != NULL) {
		lpd3dDevice->Release();
		lpd3dDevice = NULL;
	}

	if (lpddsZBuffer != NULL) {
		lpddsZBuffer->Release();
		lpddsZBuffer = NULL;
	}

	if (lpddsDevice != NULL) {
		lpddsDevice->Release();
		lpddsDevice = NULL;
	}

	return DD_OK;
}

static HRESULT ReleasePrimary() {
	if (lpddpPalette != NULL) {
		lpddpPalette->Release();
		lpddpPalette = NULL;
	}

	if (lpddsPrimary != NULL) {
		lpddsPrimary->Release();
		lpddsPrimary = NULL;
	}

	return DD_OK;
}

static HRESULT ReleaseScene() {
	if (lpd3dExecuteBuffer != NULL) {
		lpd3dExecuteBuffer->Release();
		lpd3dExecuteBuffer = NULL;
	}

	if (lpd3dBackgroundMaterial != NULL) {
		lpd3dBackgroundMaterial->Release();
		lpd3dBackgroundMaterial = NULL;
	}

	if (lpd3dMaterial != NULL) {
		lpd3dMaterial->Release();
		lpd3dMaterial = NULL;
	}

	if (hd3dWorldMatrix != 0) {
		lpd3dDevice->DeleteMatrix(hd3dWorldMatrix);
		hd3dWorldMatrix = 0;
	}

	if (hd3dViewMatrix != 0) {
		lpd3dDevice->DeleteMatrix(hd3dViewMatrix);
		hd3dViewMatrix = 0;
	}

	if (hd3dProjMatrix != 0) {
		lpd3dDevice->DeleteMatrix(hd3dProjMatrix);
		hd3dProjMatrix = 0;
	}

	if (lpd3dLight != NULL) {
		lpd3dLight->Release();
		lpd3dLight = NULL;
	}

	if (lpd3dViewport != NULL) {
		lpd3dViewport->Release();
		lpd3dViewport = NULL;
	}

	return DD_OK;
}

static LRESULT OnIdle(HWND hwnd) {
	HRESULT hRes;

	if (fActive && !fSuspended && (lpd3dDevice != NULL)) {
		hRes = AnimateScene();
		if (FAILED(hRes)) {
			FatalError(hwnd, IDS_ERRMSG_ANIMATESCENE, hRes);
			return 0L;
		}

		hRes = DoFrame();
		if (FAILED(hRes)) {
			FatalError(hwnd, IDS_ERRMSG_RENDERSCENE, hRes);
			return 0L;
		}
	}

	return 0L;
}

static void ReportError(HWND hwnd, int nMessage, HRESULT hRes) {
	HDC hdc;
	char szBuffer[256];
	char szMessage[128];
	char szError[128];
	int nStrID;

	fSuspended = TRUE;

	LoadString(hAppInstance, nMessage, szMessage, sizeof(szMessage));

	switch (hRes) {
	case DDERR_EXCEPTION:
		nStrID = IDS_ERR_EXCEPTION; break;
	case DDERR_GENERIC:
		nStrID = IDS_ERR_GENERIC; break;
	case DDERR_OUTOFMEMORY:
		nStrID = IDS_ERR_OUTOFMEMORY; break;
	case DDERR_OUTOFVIDEOMEMORY:
		nStrID = IDS_ERR_OUTOFVIDEOMEMORY; break;
	case DDERR_SURFACEBUSY:
		nStrID = IDS_ERR_SURFACEBUSY; break;
	case DDERR_SURFACELOST:
		nStrID = IDS_ERR_SURFACELOST; break;
	case DDERR_WRONGMODE:
		nStrID = IDS_ERR_WRONGMODE; break;
	default:
		nStrID = IDS_ERR_INTERNALERROR; break;
	}

	LoadString(hAppInstance, nStrID, szError, sizeof(szError));

	hdc = GetDC(hwnd);
	PaintSuspended(hwnd, hdc);
	ReleaseDC(hwnd, hdc);

	wsprintf(szBuffer, "%s\n%s (Error #%d)", szMessage, szError, CODEFROMHRESULT(hRes));
	MessageBox(hwnd, szBuffer, WINDOW_TITLE, MB_OK | MB_APPLMODAL);
	fSuspended = FALSE;
}

static void FatalError(HWND hwnd, int nMessage, HRESULT hRes) {
	ReportError(hwnd, nMessage, hRes);
	fSuspended = TRUE;

	DestroyWindow(hwnd);
}

static void PaintSuspended(HWND hwnd, HDC hdc) {
	HPEN hOldPen;
	HBRUSH hOldBrush;
	COLORREF crOldTextColor;
	int oldMode;

	int x;
	int y;
	SIZE size;
	RECT rect;
	int nStrLen;

	hOldPen = (HPEN)SelectObject(hdc, GetStockObject(NULL_PEN));
	hOldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(BLACK_BRUSH));

	oldMode = SetBkMode(hdc, TRANSPARENT);
	crOldTextColor = SetTextColor(hdc, RGB(255, 255, 255));

	GetClientRect(hwnd, &rect);

	Rectangle(hdc, rect.left, rect.top, rect.right + 1, rect.bottom + 1);

	nStrLen = strlen(PAUSED_STRING);
	GetTextExtentPoint32(hdc, PAUSED_STRING, nStrLen, &size);
	x = (rect.right - size.cx) / 2;
	y = (rect.bottom - size.cy) / 2;
	TextOut(hdc, x, y, PAUSED_STRING, nStrLen);

	SetTextColor(hdc, crOldTextColor);
	SetBkMode(hdc, oldMode);

	SelectObject(hdc, hOldBrush);
	SelectObject(hdc, hOldPen);
}

static DWORD BitDepthToFlags(DWORD dwBitDepth) {
	switch (dwBitDepth) {
	case 1: return DDBD_1;
	case 2: return DDBD_2;
	case 4: return DDBD_4;
	case 8: return DDBD_8;
	case 16: return DDBD_16;
	case 24: return DDBD_24;
	case 32: return DDBD_32;
	default: return 0;
	}

}

static DWORD FlagsToBitDepth(DWORD dwFlags) {
	if (dwFlags & DDBD_1) return 1;
	else if (dwFlags & DDBD_2) return 2;
	else if (dwFlags & DDBD_4) return 4;
	else if (dwFlags & DDBD_8) return 8;
	else if (dwFlags & DDBD_16) return 16;
	else if (dwFlags & DDBD_24) return 24;
	else if (dwFlags & DDBD_32) return 32;
	else return 0;
}
