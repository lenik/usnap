
#include "im.h"
void
ReportError(HWND hwnd, int nMessage, HRESULT hRes)
{
    HDC  hdc;
    char szBuffer[256];
    char szMessage[128];
    char szError[128];
    int  nStrID;
        fSuspended = TRUE;
        LoadString(hAppInstance, nMessage, szMessage, sizeof(szMessage));
        switch (hRes)
    {
        case DDERR_EXCEPTION:        nStrID = IDS_ERR_EXCEPTION;        break;
        case DDERR_GENERIC:          nStrID = IDS_ERR_GENERIC;          break;
        case DDERR_OUTOFMEMORY:      nStrID = IDS_ERR_OUTOFMEMORY;      break;
        case DDERR_OUTOFVIDEOMEMORY: nStrID = IDS_ERR_OUTOFVIDEOMEMORY; break;
        case DDERR_SURFACEBUSY:      nStrID = IDS_ERR_SURFACEBUSY;      break;
        case DDERR_SURFACELOST:      nStrID = IDS_ERR_SURFACELOST;      break;
		case DDERR_WRONGMODE:		 nStrID = IDS_ERR_WRONGMODE;		break;
        default:                     nStrID = IDS_ERR_INTERNALERROR;    break;
    }
    LoadString(hAppInstance, nStrID, szError, sizeof(szError));
        hdc = GetDC(hwnd);
    PaintSuspended(hwnd, hdc);
    ReleaseDC(hwnd, hdc);
        wsprintf(szBuffer, "%s\n%s (Error #%d)", szMessage, szError, CODEFROMHRESULT(hRes));
    MessageBox(hwnd, szBuffer, WINDOW_TITLE, MB_OK | MB_APPLMODAL);
    fSuspended = FALSE;
}
void
FatalError(HWND hwnd, int nMessage, HRESULT hRes)
{
        ReportError(hwnd, nMessage, hRes);
    fSuspended = TRUE;
        DestroyWindow(hwnd);
}
DWORD
BitDepthToFlags(DWORD dwBitDepth)
{
    switch (dwBitDepth)
    {
        case  1UL: return DDBD_1;
        case  2UL: return DDBD_2;
        case  4UL: return DDBD_4;
        case  8UL: return DDBD_8;
        case 16UL: return DDBD_16;
        case 24UL: return DDBD_24;
        case 32UL: return DDBD_32;
        default:   return 0UL;
         }
}
DWORD
FlagsToBitDepth(DWORD dwFlags)
{
    if (dwFlags & DDBD_1)
        return 1UL;
    else if (dwFlags & DDBD_2)
        return 2UL;
    else if (dwFlags & DDBD_4)
        return 4UL;
    else if (dwFlags & DDBD_8)
        return 8UL;
    else if (dwFlags & DDBD_16)
        return 16UL;
    else if (dwFlags & DDBD_24)
        return 24UL;
    else if (dwFlags & DDBD_32)
        return 32UL;
    else
        return 0UL;
 }
void
SetPerspectiveProjection(LPD3DMATRIX lpd3dMatrix,
                         double      dHalfHeight,
                         double      dFrontClipping,
                         double      dBackClipping)
{
    double dTmp1;
    double dTmp2;
    ASSERT(NULL != lpd3dMatrix);
    dTmp1 = dHalfHeight / dFrontClipping;
    dTmp2 = dBackClipping / (dBackClipping - dFrontClipping);
    lpd3dMatrix->_11 =  D3DVAL(2.0);
    lpd3dMatrix->_12 =  D3DVAL(0.0);
    lpd3dMatrix->_13 =  D3DVAL(0.0);
    lpd3dMatrix->_14 =  D3DVAL(0.0);
    lpd3dMatrix->_21 =  D3DVAL(0.0);
    lpd3dMatrix->_22 =  D3DVAL(2.0);
    lpd3dMatrix->_23 =  D3DVAL(0.0);
    lpd3dMatrix->_24 =  D3DVAL(0.0);
    lpd3dMatrix->_31 =  D3DVAL(0.0);
    lpd3dMatrix->_32 =  D3DVAL(0.0);
    lpd3dMatrix->_33 =  D3DVAL(dTmp1 * dTmp2);
    lpd3dMatrix->_34 =  D3DVAL(dTmp1);
    lpd3dMatrix->_41 =  D3DVAL(0.0);
    lpd3dMatrix->_42 =  D3DVAL(0.0);
    lpd3dMatrix->_43 =  D3DVAL(-dHalfHeight * dTmp2);
    lpd3dMatrix->_44 =  D3DVAL(0.0);
}
void
SetRotationAboutY(LPD3DMATRIX lpd3dMatrix, double dAngleOfRotation)
{
    D3DVALUE dvCos;
    D3DVALUE dvSin;
    ASSERT(NULL != lpd3dMatrix);
    dvCos = D3DVAL(cos(dAngleOfRotation));
    dvSin = D3DVAL(sin(dAngleOfRotation));
    lpd3dMatrix->_11 =  dvCos;
    lpd3dMatrix->_12 =  D3DVAL(0.0);
    lpd3dMatrix->_13 = -dvSin;
    lpd3dMatrix->_14 =  D3DVAL(0.0);
    lpd3dMatrix->_21 =  D3DVAL(0.0);
    lpd3dMatrix->_22 =  D3DVAL(1.0);
    lpd3dMatrix->_23 =  D3DVAL(0.0);
    lpd3dMatrix->_24 =  D3DVAL(0.0);
    lpd3dMatrix->_31 =  dvSin;
    lpd3dMatrix->_32 =  D3DVAL(0.0);
    lpd3dMatrix->_33 =  dvCos;
    lpd3dMatrix->_34 =  D3DVAL(0.0);
    lpd3dMatrix->_41 =  D3DVAL(0.0);
    lpd3dMatrix->_42 =  D3DVAL(0.0);
    lpd3dMatrix->_43 =  D3DVAL(0.0);
    lpd3dMatrix->_44 =  D3DVAL(1.0);
}
HRESULT
CreateDirect3D(HWND hwnd)
{
    HRESULT hRes;
    ASSERT(NULL == lpdd);
    ASSERT(NULL == lpd3d);
        hRes = DirectDrawCreate(NULL, &lpdd, NULL);
    if (FAILED(hRes))
        return hRes;
        hRes = lpdd->lpVtbl->SetCooperativeLevel(lpdd, hwnd, DDSCL_NORMAL);
    if (FAILED(hRes))
        return hRes;
        hRes = lpdd->lpVtbl->QueryInterface(lpdd, &IID_IDirect3D, &lpd3d);
    if (FAILED(hRes))
        return hRes;
    return DD_OK;
}
HRESULT
ReleaseDirect3D(void)
{
    if (NULL != lpd3d)
    {
        lpd3d->lpVtbl->Release(lpd3d);
        lpd3d = NULL;
    }
    if (NULL != lpdd)
    {
        lpdd->lpVtbl->Release(lpdd);
        lpdd = NULL;
    }
    return DD_OK;
}
HRESULT
CreatePrimary(HWND hwnd)
{
    HRESULT             hRes;
    DDSURFACEDESC       ddsd;
    LPDIRECTDRAWCLIPPER lpddClipper;
    HDC                 hdc;
    int                 i;
    PALETTEENTRY        peColorTable[256];
    ASSERT(NULL != hwnd);
    ASSERT(NULL != lpdd);
    ASSERT(NULL == lpddsPrimary);
    ASSERT(NULL == lpddpPalette);
        ZeroMemory(&ddsd, sizeof(ddsd));
    ddsd.dwSize         = sizeof(ddsd);
    ddsd.dwFlags        = DDSD_CAPS;
    ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
    hRes = lpdd->lpVtbl->CreateSurface(lpdd, &ddsd, &lpddsPrimary, NULL);
    if (FAILED(hRes))
        return hRes;
        hRes = DirectDrawCreateClipper(0UL, &lpddClipper, NULL);
    if (FAILED(hRes))
        return hRes;
    hRes = lpddClipper->lpVtbl->SetHWnd(lpddClipper, 0UL, hwnd);
    if (FAILED(hRes))
    {
        lpddClipper->lpVtbl->Release(lpddClipper);
        return hRes;
    }
    hRes = lpddsPrimary->lpVtbl->SetClipper(lpddsPrimary, lpddClipper);
    if (FAILED(hRes))
    {
        lpddClipper->lpVtbl->Release(lpddClipper);
        return hRes;
    }
        lpddClipper->lpVtbl->Release(lpddClipper);
        ZeroMemory(&ddsd, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    hRes = lpddsPrimary->lpVtbl->GetSurfaceDesc(lpddsPrimary, &ddsd);
    if (FAILED(hRes))
        return hRes;
    if (ddsd.ddpfPixelFormat.dwFlags & DDPF_PALETTEINDEXED8)
    {
                hdc = GetDC(NULL);
        GetSystemPaletteEntries(hdc, 0, 256, peColorTable);
        ReleaseDC(NULL, hdc);
        for (i = 0; i < 10; i++)
            peColorTable[i].peFlags = D3DPAL_READONLY;
        for (i = 10; i < 246; i++)
            peColorTable[i].peFlags = D3DPAL_FREE | PC_RESERVED;
        for (i = 246; i < 256; i++)
            peColorTable[i].peFlags = D3DPAL_READONLY;
        hRes = lpdd->lpVtbl->CreatePalette(lpdd,
                                           DDPCAPS_8BIT,
                                           peColorTable,
                                           &lpddpPalette,
                                           NULL);
        if (FAILED(hRes))
            return hRes;
        hRes = lpddsPrimary->lpVtbl->SetPalette(lpddsPrimary, lpddpPalette);
            return hRes;
    }
    return DD_OK;
}
HRESULT
RestorePrimary(void)
{
    ASSERT(NULL != lpddsPrimary);
    return lpddsPrimary->lpVtbl->Restore(lpddsPrimary);
}
HRESULT
ReleasePrimary(void)
{
    if (NULL != lpddpPalette)
    {
        lpddpPalette->lpVtbl->Release(lpddpPalette);
        lpddpPalette = NULL;
    }
    if (NULL != lpddsPrimary)
    {
        lpddsPrimary->lpVtbl->Release(lpddsPrimary);
        lpddsPrimary = NULL;
    }
    return DD_OK;
}
HRESULT WINAPI
EnumDeviceCallback(LPGUID          lpGUID,
                    LPSTR           lpszDeviceDesc,
                   LPSTR           lpszDeviceName,
                   LPD3DDEVICEDESC lpd3dHWDeviceDesc,
                   LPD3DDEVICEDESC lpd3dSWDeviceDesc,
                   LPVOID          lpUserArg)
{
    BOOL            fIsHardware;
    LPD3DDEVICEDESC lpd3dDeviceDesc;
        USE_PARAM(lpUserArg);
        fIsHardware     = (0UL != lpd3dHWDeviceDesc->dcmColorModel);
    lpd3dDeviceDesc = (fIsHardware ? lpd3dHWDeviceDesc : lpd3dSWDeviceDesc);
        if (fDebug && fIsHardware)
        return D3DENUMRET_OK;
        if (0UL == (lpd3dDeviceDesc->dwDeviceRenderBitDepth & dwDeviceBitDepth))
    {
                return D3DENUMRET_OK;
    }
        if (D3DCOLOR_MONO == lpd3dDeviceDesc->dcmColorModel)
    {
        if (!(lpd3dDeviceDesc->dpcTriCaps.dwShadeCaps & D3DPSHADECAPS_COLORGOURAUDMONO))
        {
                        return D3DENUMRET_OK;
        }
    }
    else
    {
        if (!(lpd3dDeviceDesc->dpcTriCaps.dwShadeCaps & D3DPSHADECAPS_COLORGOURAUDRGB))
        {
                        return D3DENUMRET_OK;
        }
    }
    if (!fIsHardware && fDeviceFound && (D3DCOLOR_RGB == lpd3dDeviceDesc->dcmColorModel))
    {
                return D3DENUMRET_OK;
    }
        fDeviceFound = TRUE;
    CopyMemory(&guidDevice, lpGUID, sizeof(GUID));
    strcpy(szDeviceDesc, lpszDeviceDesc);
    strcpy(szDeviceName, lpszDeviceName);
    CopyMemory(&d3dHWDeviceDesc, lpd3dHWDeviceDesc, sizeof(D3DDEVICEDESC));
    CopyMemory(&d3dSWDeviceDesc, lpd3dSWDeviceDesc, sizeof(D3DDEVICEDESC));
        if (fIsHardware)
        return D3DENUMRET_CANCEL;
        return D3DENUMRET_OK;
}
                            HRESULT
ChooseDevice(void)
{
    DDSURFACEDESC ddsd;
    HRESULT       hRes;
    ASSERT(NULL != lpd3d);
    ASSERT(NULL != lpddsPrimary);
        ZeroMemory(&ddsd, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    hRes = lpddsPrimary->lpVtbl->GetSurfaceDesc(lpddsPrimary, &ddsd);
    if (FAILED(hRes))
        return hRes;
    dwDeviceBitDepth = BitDepthToFlags(ddsd.ddpfPixelFormat.dwRGBBitCount);
        fDeviceFound = FALSE;
    hRes = lpd3d->lpVtbl->EnumDevices(lpd3d, EnumDeviceCallback, &fDeviceFound);
    if (FAILED(hRes))
        return hRes;
    if (!fDeviceFound)
    {
                return DDERR_NOTFOUND;
    }
    return DD_OK;
}
HRESULT
CreateDevice(DWORD dwWidth, DWORD dwHeight)
{
    LPD3DDEVICEDESC lpd3dDeviceDesc;
    DWORD           dwDeviceMemType;
    DWORD           dwZBufferMemType;
    DDSURFACEDESC   ddsd;
    HRESULT         hRes;
    DWORD           dwZBufferBitDepth;
    ASSERT(NULL != lpdd);
    ASSERT(NULL != lpd3d);
    ASSERT(NULL != lpddsPrimary);
    ASSERT(NULL == lpddsDevice);
    ASSERT(NULL == lpd3dDevice);
        if (0UL != d3dHWDeviceDesc.dcmColorModel)
    {
        lpd3dDeviceDesc = &d3dHWDeviceDesc;
                dwDeviceMemType  = DDSCAPS_VIDEOMEMORY;
        dwZBufferMemType = DDSCAPS_VIDEOMEMORY;
    }
    else
    {
        lpd3dDeviceDesc = &d3dSWDeviceDesc;
                dwDeviceMemType  = (fDebug ? DDSCAPS_SYSTEMMEMORY : 0UL);
        dwZBufferMemType = DDSCAPS_SYSTEMMEMORY;
    }
        ZeroMemory(&ddsd, sizeof(ddsd));
    ddsd.dwSize         = sizeof(ddsd);
    ddsd.dwFlags        = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;
    ddsd.dwWidth        = dwWidth;
    ddsd.dwHeight       = dwHeight;
    ddsd.ddsCaps.dwCaps = DDSCAPS_3DDEVICE | DDSCAPS_OFFSCREENPLAIN | dwDeviceMemType;
    hRes = lpdd->lpVtbl->CreateSurface(lpdd, &ddsd, &lpddsDevice, NULL);
    if (FAILED(hRes))
        return hRes;
        if (NULL != lpddpPalette)
    {
        hRes = lpddsDevice->lpVtbl->SetPalette(lpddsDevice, lpddpPalette);
        if (FAILED(hRes))
            return hRes;
    }
        if (0UL != lpd3dDeviceDesc->dwDeviceZBufferBitDepth)
    {
                dwZBufferBitDepth = FlagsToBitDepth(lpd3dDeviceDesc->dwDeviceZBufferBitDepth);
                ZeroMemory(&ddsd, sizeof(ddsd));
        ddsd.dwSize            = sizeof(ddsd);
        ddsd.dwFlags           = DDSD_CAPS   |
                                 DDSD_WIDTH  |
                                 DDSD_HEIGHT |
                                 DDSD_ZBUFFERBITDEPTH;
        ddsd.ddsCaps.dwCaps    = DDSCAPS_ZBUFFER | dwZBufferMemType;
        ddsd.dwWidth           = dwWidth;
        ddsd.dwHeight          = dwHeight;
        ddsd.dwZBufferBitDepth = dwZBufferBitDepth;
        hRes = lpdd->lpVtbl->CreateSurface(lpdd, &ddsd, &lpddsZBuffer, NULL);
        if (FAILED(hRes))
            return hRes;
                hRes = lpddsDevice->lpVtbl->AddAttachedSurface(lpddsDevice, lpddsZBuffer);
        if (FAILED(hRes))
            return hRes;
    }
        hRes = lpddsDevice->lpVtbl->QueryInterface(lpddsDevice,
                                              &guidDevice,
                                              &lpd3dDevice);
    if (FAILED(hRes))
        return hRes;
    return DD_OK;
}
HRESULT
RestoreDevice(void)
{
    HRESULT hRes;
    if (NULL != lpddsZBuffer)
    {
        hRes = lpddsZBuffer->lpVtbl->Restore(lpddsZBuffer);
        if (FAILED(hRes))
            return hRes;
    }
    if (NULL != lpddsDevice)
    {
        hRes = lpddsDevice->lpVtbl->Restore(lpddsDevice);
        if (FAILED(hRes))
            return hRes;
    }
    return DD_OK;
}
HRESULT
ReleaseDevice(void)
{
    if (NULL != lpd3dDevice)
    {
        lpd3dDevice->lpVtbl->Release(lpd3dDevice);
        lpd3dDevice = NULL;
    }
    if (NULL != lpddsZBuffer)
    {
        lpddsZBuffer->lpVtbl->Release(lpddsZBuffer);
        lpddsZBuffer = NULL;
    }
    if (NULL != lpddsDevice)
    {
        lpddsDevice->lpVtbl->Release(lpddsDevice);
        lpddsDevice = NULL;
    }
    return DD_OK;
}
LRESULT
RestoreSurfaces(void)
{
    HRESULT hRes;
    hRes = RestorePrimary();
    if (FAILED(hRes))
        return hRes;
    hRes = RestoreDevice();
    if (FAILED(hRes))
        return hRes;
    return DD_OK;
}
HRESULT
FillExecuteBuffer(void)
{
    HRESULT              hRes;
    D3DEXECUTEBUFFERDESC d3dExeBufDesc;
    LPD3DVERTEX          lpVertex;
    LPD3DINSTRUCTION     lpInstruction;
    LPD3DPROCESSVERTICES lpProcessVertices;
    LPD3DTRIANGLE        lpTriangle;
    LPD3DSTATE           lpState;
    ASSERT(NULL != lpd3dExecuteBuffer);
    ASSERT(0UL  != hd3dSurfaceMaterial);
    ASSERT(0UL  != hd3dWorldMatrix);
    ASSERT(0UL  != hd3dViewMatrix);
    ASSERT(0UL  != hd3dProjMatrix);
        ZeroMemory(&d3dExeBufDesc, sizeof(d3dExeBufDesc));
    d3dExeBufDesc.dwSize = sizeof(d3dExeBufDesc);
    hRes = lpd3dExecuteBuffer->lpVtbl->Lock(lpd3dExecuteBuffer, &d3dExeBufDesc);
    if (FAILED(hRes))
        return hRes;
        lpVertex = (LPD3DVERTEX)d3dExeBufDesc.lpData;
        lpVertex->dvX  = D3DVAL( 0.0);
     lpVertex->dvY  = D3DVAL( 1.0);
    lpVertex->dvZ  = D3DVAL( 0.0);
    lpVertex->dvNX = D3DVAL( 0.0);
     lpVertex->dvNY = D3DVAL( 0.0);
    lpVertex->dvNZ = D3DVAL(-1.0);
    lpVertex->dvTU = D3DVAL( 0.0);
     lpVertex->dvTV = D3DVAL( 1.0);
    lpVertex++;
        lpVertex->dvX  = D3DVAL( 1.0);
     lpVertex->dvY  = D3DVAL(-1.0);
    lpVertex->dvZ  = D3DVAL( 0.0);
    lpVertex->dvNX = D3DVAL( 0.0);
     lpVertex->dvNY = D3DVAL( 0.0);
    lpVertex->dvNZ = D3DVAL(-1.0);
    lpVertex->dvTU = D3DVAL( 1.0);
     lpVertex->dvTV = D3DVAL( 1.0);
    lpVertex++;
        lpVertex->dvX  = D3DVAL(-1.0);
     lpVertex->dvY  = D3DVAL(-1.0);
    lpVertex->dvZ  = D3DVAL( 0.0);
    lpVertex->dvNX = D3DVAL( 0.0);
     lpVertex->dvNY = D3DVAL( 0.0);
    lpVertex->dvNZ = D3DVAL(-1.0);
    lpVertex->dvTU = D3DVAL( 1.0);
     lpVertex->dvTV = D3DVAL( 0.0);
    lpVertex++;
        lpInstruction = (LPD3DINSTRUCTION)lpVertex;
    lpInstruction->bOpcode = D3DOP_STATETRANSFORM;
    lpInstruction->bSize   = sizeof(D3DSTATE);
    lpInstruction->wCount  = 3U;
    lpInstruction++;
    lpState = (LPD3DSTATE)lpInstruction;
    lpState->dtstTransformStateType = D3DTRANSFORMSTATE_WORLD;
    lpState->dwArg[0] = hd3dWorldMatrix;
    lpState++;
    lpState->dtstTransformStateType = D3DTRANSFORMSTATE_VIEW;
    lpState->dwArg[0] = hd3dViewMatrix;
    lpState++;
    lpState->dtstTransformStateType = D3DTRANSFORMSTATE_PROJECTION;
    lpState->dwArg[0] = hd3dProjMatrix;
    lpState++;
        lpInstruction = (LPD3DINSTRUCTION)lpState;
    lpInstruction->bOpcode = D3DOP_STATELIGHT;
    lpInstruction->bSize   = sizeof(D3DSTATE);
    lpInstruction->wCount  = 2U;
    lpInstruction++;
    lpState = (LPD3DSTATE)lpInstruction;
    lpState->dlstLightStateType = D3DLIGHTSTATE_MATERIAL;
    lpState->dwArg[0] = hd3dSurfaceMaterial;
    lpState++;
    lpState->dlstLightStateType = D3DLIGHTSTATE_AMBIENT;
    lpState->dwArg[0] = RGBA_MAKE(128, 128, 128, 128);
    lpState++;
        lpInstruction = (LPD3DINSTRUCTION)lpState;
    lpInstruction->bOpcode = D3DOP_STATERENDER;
    lpInstruction->bSize = sizeof(D3DSTATE);
    lpInstruction->wCount = 3U;
    lpInstruction++;
    lpState = (LPD3DSTATE)lpInstruction;
    lpState->drstRenderStateType = D3DRENDERSTATE_FILLMODE;
    lpState->dwArg[0] = D3DFILL_SOLID;
    lpState++;
    lpState->drstRenderStateType = D3DRENDERSTATE_SHADEMODE;
    lpState->dwArg[0] = D3DSHADE_GOURAUD;
    lpState++;
    lpState->drstRenderStateType = D3DRENDERSTATE_DITHERENABLE;
    lpState->dwArg[0] = TRUE;
    lpState++;
        lpInstruction = (LPD3DINSTRUCTION)lpState;
    lpInstruction->bOpcode = D3DOP_PROCESSVERTICES;
    lpInstruction->bSize   = sizeof(D3DPROCESSVERTICES);
    lpInstruction->wCount  = 1U;
    lpInstruction++;
    lpProcessVertices = (LPD3DPROCESSVERTICES)lpInstruction;
    lpProcessVertices->dwFlags    = D3DPROCESSVERTICES_TRANSFORMLIGHT;
    lpProcessVertices->wStart     = 0U;
               lpProcessVertices->wDest      = 0U;
    lpProcessVertices->dwCount    = NUM_VERTICES;
     lpProcessVertices->dwReserved = 0UL;
    lpProcessVertices++;
        lpInstruction = (LPD3DINSTRUCTION)lpProcessVertices;
    lpInstruction->bOpcode = D3DOP_TRIANGLE;
    lpInstruction->bSize   = sizeof(D3DTRIANGLE);
    lpInstruction->wCount  = 1U;
    lpInstruction++;
    lpTriangle = (LPD3DTRIANGLE)lpInstruction;
    lpTriangle->wV1    = 0U;
     lpTriangle->wV2    = 1U;
    lpTriangle->wV3    = 2U;
    lpTriangle->wFlags = D3DTRIFLAG_EDGEENABLETRIANGLE;
    lpTriangle++;
        lpInstruction = (LPD3DINSTRUCTION)lpTriangle;
    lpInstruction->bOpcode = D3DOP_EXIT;
    lpInstruction->bSize   = 0UL;
    lpInstruction->wCount  = 0U;
        lpd3dExecuteBuffer->lpVtbl->Unlock(lpd3dExecuteBuffer);
    return DD_OK;
}
HRESULT
CreateScene(void)
{
    HRESULT              hRes;
    D3DMATERIAL          d3dMaterial;
    D3DLIGHT             d3dLight;
    DWORD                dwVertexSize;
    DWORD                dwInstructionSize;
    DWORD                dwExecuteBufferSize;
    D3DEXECUTEBUFFERDESC d3dExecuteBufferDesc;
    D3DEXECUTEDATA       d3dExecuteData;
    ASSERT(NULL != lpd3d);
    ASSERT(NULL != lpd3dDevice);
    ASSERT(NULL == lpd3dViewport);
    ASSERT(NULL == lpd3dMaterial);
    ASSERT(NULL == lpd3dBackgroundMaterial);
    ASSERT(NULL == lpd3dExecuteBuffer);
    ASSERT(NULL == lpd3dLight);
    ASSERT(0UL  == hd3dWorldMatrix);
    ASSERT(0UL  == hd3dViewMatrix);
    ASSERT(0UL  == hd3dProjMatrix);
        hRes = lpd3d->lpVtbl->CreateLight(lpd3d, &lpd3dLight, NULL);
    if (FAILED(hRes))
        return hRes;
    ZeroMemory(&d3dLight, sizeof(d3dLight));
    d3dLight.dwSize = sizeof(d3dLight);
    d3dLight.dltType = D3DLIGHT_POINT;
    d3dLight.dcvColor.dvR    = D3DVAL( 1.0);
    d3dLight.dcvColor.dvG    = D3DVAL( 1.0);
    d3dLight.dcvColor.dvB    = D3DVAL( 1.0);
    d3dLight.dcvColor.dvA    = D3DVAL( 1.0);
    d3dLight.dvPosition.dvX  = D3DVAL( 1.0);
    d3dLight.dvPosition.dvY  = D3DVAL(-1.0);
    d3dLight.dvPosition.dvZ  = D3DVAL(-1.0);
    d3dLight.dvAttenuation0  = D3DVAL( 1.0);
    d3dLight.dvAttenuation1  = D3DVAL( 0.1);
    d3dLight.dvAttenuation2  = D3DVAL( 0.0);
    hRes = lpd3dLight->lpVtbl->SetLight(lpd3dLight, &d3dLight);
    if (FAILED(hRes))
        return hRes;
        hRes = lpd3d->lpVtbl->CreateMaterial(lpd3d, &lpd3dBackgroundMaterial, NULL);
    if (FAILED(hRes))
        return hRes;
    ZeroMemory(&d3dMaterial, sizeof(d3dMaterial));
    d3dMaterial.dwSize = sizeof(d3dMaterial);
    d3dMaterial.dcvDiffuse.r  = D3DVAL(0.0);
    d3dMaterial.dcvDiffuse.g  = D3DVAL(0.0);
    d3dMaterial.dcvDiffuse.b  = D3DVAL(0.0);
    d3dMaterial.dcvAmbient.r  = D3DVAL(0.0);
    d3dMaterial.dcvAmbient.g  = D3DVAL(0.0);
    d3dMaterial.dcvAmbient.b  = D3DVAL(0.0);
    d3dMaterial.dcvSpecular.r = D3DVAL(0.0);
    d3dMaterial.dcvSpecular.g = D3DVAL(0.0);
    d3dMaterial.dcvSpecular.b = D3DVAL(0.0);
    d3dMaterial.dvPower       = D3DVAL(0.0);
        d3dMaterial.dwRampSize    = 1UL;
        hRes = lpd3dBackgroundMaterial->lpVtbl->SetMaterial(lpd3dBackgroundMaterial,
                                                        &d3dMaterial);
    if (FAILED(hRes))
        return hRes;
    hRes = lpd3dBackgroundMaterial->lpVtbl->GetHandle(lpd3dBackgroundMaterial,
                                                      lpd3dDevice,
                                                      &hd3dBackgroundMaterial);
    if (FAILED(hRes))
        return hRes;
        hRes = lpd3d->lpVtbl->CreateViewport(lpd3d, &lpd3dViewport, NULL);
    if (FAILED(hRes))
        return hRes;
    hRes = lpd3dDevice->lpVtbl->AddViewport(lpd3dDevice, lpd3dViewport);
    if (FAILED(hRes))
        return hRes;
    hRes = lpd3dViewport->lpVtbl->SetBackground(lpd3dViewport, hd3dBackgroundMaterial);
    if (FAILED(hRes))
        return hRes;
    hRes = lpd3dViewport->lpVtbl->AddLight(lpd3dViewport, lpd3dLight);
    if (FAILED(hRes))
        return hRes;
        hRes = lpd3dDevice->lpVtbl->CreateMatrix(lpd3dDevice, &hd3dWorldMatrix);
    if (FAILED(hRes))
        return hRes;
    hRes = lpd3dDevice->lpVtbl->SetMatrix(lpd3dDevice, hd3dWorldMatrix, &d3dWorldMatrix);
    if (FAILED(hRes))
        return hRes;
    hRes = lpd3dDevice->lpVtbl->CreateMatrix(lpd3dDevice, &hd3dViewMatrix);
    if (FAILED(hRes))
        return hRes;
    hRes = lpd3dDevice->lpVtbl->SetMatrix(lpd3dDevice, hd3dViewMatrix, &d3dViewMatrix);
    if (FAILED(hRes))
        return hRes;
    hRes = lpd3dDevice->lpVtbl->CreateMatrix(lpd3dDevice, &hd3dProjMatrix);
    if (FAILED(hRes))
        return hRes;
    SetPerspectiveProjection(&d3dProjMatrix, HALF_HEIGHT, FRONT_CLIP, BACK_CLIP);
    hRes = lpd3dDevice->lpVtbl->SetMatrix(lpd3dDevice, hd3dProjMatrix, &d3dProjMatrix);
    if (FAILED(hRes))
        return hRes;
        hRes = lpd3d->lpVtbl->CreateMaterial(lpd3d, &lpd3dMaterial, NULL);
    if (FAILED(hRes))
        return hRes;
    ZeroMemory(&d3dMaterial, sizeof(d3dMaterial));
    d3dMaterial.dwSize = sizeof(d3dMaterial);
        d3dMaterial.dcvDiffuse.r  = D3DVAL(0.0);
    d3dMaterial.dcvDiffuse.g  = D3DVAL(1.0);
    d3dMaterial.dcvDiffuse.b  = D3DVAL(0.0);
    d3dMaterial.dcvAmbient.r  = D3DVAL(0.0);
    d3dMaterial.dcvAmbient.g  = D3DVAL(0.4);
    d3dMaterial.dcvAmbient.b  = D3DVAL(0.0);
    d3dMaterial.dcvSpecular.r = D3DVAL(1.0);
    d3dMaterial.dcvSpecular.g = D3DVAL(1.0);
    d3dMaterial.dcvSpecular.b = D3DVAL(1.0);
    d3dMaterial.dvPower       = D3DVAL(20.0);
    d3dMaterial.dwRampSize    = 16UL;
        hRes = lpd3dMaterial->lpVtbl->SetMaterial(lpd3dMaterial, &d3dMaterial);
    if (FAILED(hRes))
        return hRes;
    hRes = lpd3dMaterial->lpVtbl->GetHandle(lpd3dMaterial, lpd3dDevice, &hd3dSurfaceMaterial);
    if (FAILED(hRes))
        return hRes;
        dwVertexSize        = (NUM_VERTICES        * sizeof(D3DVERTEX));
    dwInstructionSize   = (NUM_INSTRUCTIONS    * sizeof(D3DINSTRUCTION))     +
                          (NUM_STATES          * sizeof(D3DSTATE))           +
                          (NUM_PROCESSVERTICES * sizeof(D3DPROCESSVERTICES)) +
                          (NUM_TRIANGLES       * sizeof(D3DTRIANGLE));
    dwExecuteBufferSize = dwVertexSize + dwInstructionSize;
    ZeroMemory(&d3dExecuteBufferDesc, sizeof(d3dExecuteBufferDesc));
    d3dExecuteBufferDesc.dwSize       = sizeof(d3dExecuteBufferDesc);
    d3dExecuteBufferDesc.dwFlags      = D3DDEB_BUFSIZE;
    d3dExecuteBufferDesc.dwBufferSize = dwExecuteBufferSize;
    hRes = lpd3dDevice->lpVtbl->CreateExecuteBuffer(lpd3dDevice,
                                                    &d3dExecuteBufferDesc,
                                                    &lpd3dExecuteBuffer,
                                                    NULL);
    if (FAILED(hRes))
        return hRes;
        hRes = FillExecuteBuffer();
    if (FAILED(hRes))
        return hRes;
        ZeroMemory(&d3dExecuteData, sizeof(d3dExecuteData));
    d3dExecuteData.dwSize = sizeof(d3dExecuteData);
    d3dExecuteData.dwVertexCount       = NUM_VERTICES;
    d3dExecuteData.dwInstructionOffset = dwVertexSize;
    d3dExecuteData.dwInstructionLength = dwInstructionSize;
    hRes = lpd3dExecuteBuffer->lpVtbl->SetExecuteData(lpd3dExecuteBuffer, &d3dExecuteData);
    if (FAILED(hRes))
        return hRes;
    return DD_OK;
}
HRESULT
ReleaseScene(void)
{
    if (NULL != lpd3dExecuteBuffer)
    {
        lpd3dExecuteBuffer->lpVtbl->Release(lpd3dExecuteBuffer);
        lpd3dExecuteBuffer = NULL;
    }
    if (NULL != lpd3dBackgroundMaterial)
    {
        lpd3dBackgroundMaterial->lpVtbl->Release(lpd3dBackgroundMaterial);
        lpd3dBackgroundMaterial = NULL;
    }
    if (NULL != lpd3dMaterial)
    {
        lpd3dMaterial->lpVtbl->Release(lpd3dMaterial);
        lpd3dMaterial = NULL;
    }
    if (0UL != hd3dWorldMatrix)
    {
        lpd3dDevice->lpVtbl->DeleteMatrix(lpd3dDevice, hd3dWorldMatrix);
        hd3dWorldMatrix = 0UL;
    }
    if (0UL != hd3dViewMatrix)
    {
        lpd3dDevice->lpVtbl->DeleteMatrix(lpd3dDevice, hd3dViewMatrix);
        hd3dViewMatrix = 0UL;
    }
    if (0UL != hd3dProjMatrix)
    {
        lpd3dDevice->lpVtbl->DeleteMatrix(lpd3dDevice, hd3dProjMatrix);
        hd3dProjMatrix = 0UL;
    }
    if (NULL != lpd3dLight)
    {
        lpd3dLight->lpVtbl->Release(lpd3dLight);
        lpd3dLight = NULL;
    }
    if (NULL != lpd3dViewport)
    {
        lpd3dViewport->lpVtbl->Release(lpd3dViewport);
        lpd3dViewport = NULL;
    }
    return DD_OK;
}
HRESULT
AnimateScene(void)
{
    HRESULT hRes;
    ASSERT(NULL != lpd3dDevice);
    ASSERT(0UL  != hd3dWorldMatrix);
        SetRotationAboutY(&d3dWorldMatrix, dAngleOfRotation);
    dAngleOfRotation += ROTATE_ANGLE_DELTA;
    hRes = lpd3dDevice->lpVtbl->SetMatrix(lpd3dDevice,
                                          hd3dWorldMatrix,
                                          &d3dWorldMatrix);
    if (FAILED(hRes))
        return hRes;
    return DD_OK;
}
HRESULT
UpdateViewport(void)
{
    D3DVIEWPORT d3dViewport;
    ASSERT(NULL != lpd3dViewport);
    ZeroMemory(&d3dViewport, sizeof(d3dViewport));
    d3dViewport.dwSize   = sizeof(d3dViewport);
    d3dViewport.dwX      = 0UL;
    d3dViewport.dwY      = 0UL;
    d3dViewport.dwWidth  = (DWORD)rSrcRect.right;
    d3dViewport.dwHeight = (DWORD)rSrcRect.bottom;
    d3dViewport.dvScaleX = D3DVAL((float)d3dViewport.dwWidth / 2.0);
    d3dViewport.dvScaleY = D3DVAL((float)d3dViewport.dwHeight / 2.0);
    d3dViewport.dvMaxX   = D3DVAL(1.0);
    d3dViewport.dvMaxY   = D3DVAL(1.0);
    return lpd3dViewport->lpVtbl->SetViewport(lpd3dViewport, &d3dViewport);
}
HRESULT
RenderScene(void)
{
    HRESULT hRes;
    D3DRECT d3dRect;
    ASSERT(NULL != lpd3dViewport);
    ASSERT(NULL != lpd3dDevice);
    ASSERT(NULL != lpd3dExecuteBuffer);
        d3dRect.lX1 = rSrcRect.left;
    d3dRect.lX2 = rSrcRect.right;
    d3dRect.lY1 = rSrcRect.top;
    d3dRect.lY2 = rSrcRect.bottom;
    hRes = lpd3dViewport->lpVtbl->Clear(lpd3dViewport,
                                        1UL,
                                        &d3dRect,
                                        D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER);
    if (FAILED(hRes))
        return hRes;
        hRes = lpd3dDevice->lpVtbl->BeginScene(lpd3dDevice);
    if (FAILED(hRes))
        return hRes;
        hRes = lpd3dDevice->lpVtbl->Execute(lpd3dDevice,
                                        lpd3dExecuteBuffer,
                                        lpd3dViewport,
                                        D3DEXECUTE_CLIPPED);
    if (FAILED(hRes))
    {
        lpd3dDevice->lpVtbl->EndScene(lpd3dDevice);
        return hRes;
    }
        hRes = lpd3dDevice->lpVtbl->EndScene(lpd3dDevice);
    if (FAILED(hRes))
        return hRes;
        return DD_OK;
}
HRESULT
DoFrame(HWND hwnd)
{
    HRESULT hRes;
        while (TRUE)
    {
        hRes = RenderScene();
        if (SUCCEEDED(hRes))
        {
	    POINT pt;
	    RECT rTmp;
	    pt.x = pt.y = 0;
	    ClientToScreen( hwnd, &pt );
	    rTmp = rDstRect;
	    OffsetRect(&rTmp, pt.x, pt.y);
            hRes = lpddsPrimary->lpVtbl->Blt(lpddsPrimary,
                                            &rTmp,
                                            lpddsDevice,
                                            &rSrcRect,
                                            DDBLT_WAIT,
                                            NULL);
            if (SUCCEEDED(hRes))
                                return hRes;
        }
        while (DDERR_SURFACELOST == hRes)
                        hRes = RestoreSurfaces();
        if (FAILED(hRes))
                        return hRes;
    }
}
void
PaintSuspended(HWND hwnd, HDC hdc)
{
    HPEN     hOldPen;
    HBRUSH   hOldBrush;
    COLORREF crOldTextColor;
    int      oldMode;
    int      x;
    int      y;
    SIZE     size;
    RECT     rect;
    int      nStrLen;
        hOldPen   = SelectObject(hdc, GetStockObject(NULL_PEN));
    hOldBrush = SelectObject(hdc, GetStockObject(BLACK_BRUSH));
        oldMode = SetBkMode(hdc, TRANSPARENT);
    crOldTextColor = SetTextColor(hdc, RGB(255, 255, 255));
    GetClientRect(hwnd, &rect);
        Rectangle(hdc, rect.left, rect.top, rect.right + 1, rect.bottom + 1);
        nStrLen = strlen(PAUSED_STRING);
    GetTextExtentPoint32(hdc, PAUSED_STRING, nStrLen, &size);
    x = (rect.right  - size.cx) / 2;
    y = (rect.bottom - size.cy) / 2;
    TextOut(hdc, x, y, PAUSED_STRING, nStrLen);
    SetTextColor(hdc, crOldTextColor);
    SetBkMode(hdc, oldMode);
    SelectObject(hdc, hOldBrush);
    SelectObject(hdc, hOldPen);
}
LRESULT
OnMove(HWND hwnd, int x, int y)
{
    HRESULT hRes;
        if ((NULL != lpd3dDevice) && !fSuspended)
    {
                hRes = DoFrame(hwnd);
        if (FAILED(hRes))
        {
            FatalError(hwnd, IDS_ERRMSG_RENDERSCENE, hRes);
            return 0L;
        }
    }
    return 0L;
}
LRESULT
OnSize(HWND hwnd, int w, int h)
{
    HRESULT       hRes;
    DDSURFACEDESC ddsd;
        if (!fSuspended)
    {
                rDstRect.right  = rDstRect.left + w;
        rDstRect.bottom = rDstRect.top  + h;
        rSrcRect.right  = w;
        rSrcRect.bottom = h;
        if (NULL != lpd3dDevice)
        {
                        ZeroMemory(&ddsd, sizeof(ddsd));
            ddsd.dwSize = sizeof(ddsd);
            hRes = lpddsDevice->lpVtbl->GetSurfaceDesc(lpddsDevice, &ddsd);
            if (FAILED(hRes))
            {
                FatalError(hwnd, IDS_ERRMSG_DEVICESIZE, hRes);
                return 0L;
            }
                if ((w > (int)ddsd.dwWidth) || (h > (int)ddsd.dwHeight))
            {
                                                ReleaseScene();
                ReleaseDevice();
            }
        }
        if (NULL == lpd3dDevice)
        {
                        hRes = CreateDevice((DWORD)w, (DWORD)h);
            if (FAILED(hRes))
            {
                FatalError(hwnd, IDS_ERRMSG_CREATEDEVICE, hRes);
                return 0L;
            }
            hRes = CreateScene();
            if (FAILED(hRes))
            {
                FatalError(hwnd, IDS_ERRMSG_BUILDSCENE, hRes);
                return 0L;
            }
        }
        hRes = UpdateViewport();
        if (FAILED(hRes))
        {
            FatalError(hwnd, IDS_ERRMSG_UPDATEVIEWPORT, hRes);
            return 0L;
        }
                hRes = DoFrame(hwnd);
        if (FAILED(hRes))
        {
            FatalError(hwnd, IDS_ERRMSG_RENDERSCENE, hRes);
            return 0L;
        }
    }
    return 0L;
}
LRESULT
OnPaint(HWND hwnd, HDC hdc, LPPAINTSTRUCT lpps)
{
    HRESULT hRes;
    USE_PARAM(lpps);
    if (fActive && !fSuspended && (NULL != lpd3dDevice))
    {
                hRes = DoFrame(hwnd);
        if (FAILED(hRes))
        {
            FatalError(hwnd, IDS_ERRMSG_RENDERSCENE, hRes);
            return 0L;
        }
    }
    else
    {
                PaintSuspended(hwnd, hdc);
    }
    return 0L;
}
LRESULT
OnIdle(HWND hwnd)
{
    HRESULT hRes;
        if (fActive && !fSuspended && (NULL != lpd3dDevice))
    {
        hRes = AnimateScene();
        if (FAILED(hRes))
        {
            FatalError(hwnd, IDS_ERRMSG_ANIMATESCENE, hRes);
            return 0L;
        }
        hRes = DoFrame(hwnd);
        if (FAILED(hRes))
        {
            FatalError(hwnd, IDS_ERRMSG_RENDERSCENE, hRes);
            return 0L;
        }
    }
    return 0L;
}
LRESULT CALLBACK
WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    HDC         hdc;
    PAINTSTRUCT ps;
    LRESULT     lResult;
    HRESULT     hRes;
    char        szBuffer[128];
    switch (msg)
    {
        case WM_CREATE:
            hRes = CreateDirect3D(hwnd);
            if (FAILED(hRes))
            {
                ReportError(hwnd, IDS_ERRMSG_CREATEDEVICE, hRes);
                ReleaseDirect3D();
                return -1L;
            }
            hRes = CreatePrimary(hwnd);
            if (FAILED(hRes))
            {
                ReportError(hwnd, IDS_ERRMSG_INITSCREEN, hRes);
                ReleasePrimary();
                ReleaseDirect3D();
                return -1L;
            }
            hRes = ChooseDevice();
            if (FAILED(hRes))
            {
                ReportError(hwnd, IDS_ERRMSG_NODEVICE, hRes);
                ReleasePrimary();
                ReleaseDirect3D();
                return -1L;
            }
                        wsprintf(szBuffer, "%s: %s", WINDOW_TITLE, szDeviceName);
            SetWindowText(hwnd, szBuffer);
            return 0L;
        case WM_MOVE:
            return OnMove(hwnd, (int)(signed short)LOWORD(lParam), (int)(signed short)HIWORD(lParam));
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
            if (fActive && !fSuspended && (NULL != lpddpPalette))
            {
                                hRes = lpddsPrimary->lpVtbl->SetPalette(lpddsPrimary, lpddpPalette);
                if (FAILED(hRes))
                {
                    FatalError(hwnd, IDS_ERRMSG_REALIZEPALETTE, hRes);
                    return 0L;
                }
            }
            else
            {
                                InvalidateRect(hwnd, NULL, FALSE);
            }
            return 0L;
        case WM_KEYUP:
                        if (VK_ESCAPE == (int)wParam)
            {
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
                        int PASCAL
WinMain(HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR     lpszCommandLine,
        int       cmdShow)
{
    WNDCLASS wndClass;
    HWND     hwnd;
    MSG      msg;
    USE_PARAM(hPrevInstance);
        hAppInstance = hInstance;
        if (0 != *lpszCommandLine)
        fDebug = TRUE;
        wndClass.style         = 0;
    wndClass.lpfnWndProc   = WndProc;
    wndClass.cbClsExtra    = 0;
    wndClass.cbWndExtra    = 0;
    wndClass.hInstance     = hInstance;
    wndClass.hIcon         = LoadIcon(hAppInstance, MAKEINTRESOURCE(IDI_APPICON));
    wndClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wndClass.hbrBackground = GetStockObject(WHITE_BRUSH);
    wndClass.lpszMenuName  = NULL;
    wndClass.lpszClassName = WINDOW_CLASSNAME;
    RegisterClass(&wndClass);
        hwnd = CreateWindow(WINDOW_CLASSNAME,
                        WINDOW_TITLE,
                        WS_OVERLAPPED | WS_SYSMENU,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        WINDOW_WIDTH, WINDOW_HEIGHT,
                        NULL,
                        NULL,
                        hInstance,
                        NULL);
    ShowWindow(hwnd, cmdShow);
    UpdateWindow(hwnd);
        while (TRUE)
    {
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
                        if (WM_QUIT == msg.message)
            {
                break;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
                        OnIdle(hwnd);
        }
    }
    return msg.wParam;
}