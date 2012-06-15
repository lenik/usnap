// TestCom_Client1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#import "..\Debug\TestCom.ocx"
#import "S:\Lib\CampoEngine\Working\CeE3D\Debug\CeE3D.dll"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.
	HRESULT hr;
	hr = CoInitialize(NULL);

	CaTestComLib::_DTestComPtr pc;
	hr = pc.CreateInstance("TestCom.TestComCtrl.1");
	hr = pc->AboutBox();
	pc = NULL;

	CoUninitialize();
	return 0;
}