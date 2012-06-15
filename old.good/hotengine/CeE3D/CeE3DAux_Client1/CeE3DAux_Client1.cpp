// CeE3DAux_Client1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "..\CeE3DInproc\CeE3DInproc.h"
#include "..\CeE3D\CeE3D.h"
#include "..\CeE3D\CeE3D_i.c"

#define _USE_COM

ICeE3DAux	*pAux	= NULL;
ICeE3DBase	*pBase	= NULL;

void CALLBACK display() {
	pBase->Clear(GL_COLOR_BUFFER_BIT);
	pBase->Color4f(0.2f, 0.8f, 1.0f, 1.0f);
	pAux->DrawWireCube(1.0f);
	pAux->DrawWireTeapot(0.5f);
	pBase->Flush();
}

void CALLBACK myReshape(GLsizei w, GLsizei h) {
	pBase->Viewport(0, 0, w, h);
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	CoInitializeEx(NULL, COINIT_MULTITHREADED);

	HRESULT hr;
	GLenum mod = AUX_SINGLE | AUX_RGBA;

	hr	= CoCreateInstance(
		CLSID_CeE3DAux,
		NULL,
		CLSCTX_SERVER,
		IID_ICeE3DAux,
		(LPVOID *)&pAux);
	if (FAILED(hr)) goto err1;

	hr	= CoCreateInstance(
		CLSID_CeE3DBase,
		NULL,
		CLSCTX_SERVER,
		IID_ICeE3DBase,
		(LPVOID *)&pBase);
	if (FAILED(hr)) goto err2;

	GLenum	enum1;

	pAux->InitDisplayMode(AUX_SINGLE | AUX_RGBA);
	pAux->InitPosition(0, 0, 400, 400);
	pAux->InitWindowA("openglsample.c", &enum1);
	pBase->ClearColor(0, 0, 0, 0);

	pAux->ReshapeFunc(myReshape);
	pAux->MainLoop(display);

	pBase->Release();
err2:
	pAux->Release();
err1:
	CoUninitialize();
	return 0;
}