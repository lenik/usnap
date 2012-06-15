// shit.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#import <dog001.ocx>


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{

    CoInitialize(NULL);

    HRESULT hr;

    DOGLib::_DDog *pDog = NULL;
    hr = CoCreateInstance(__uuidof(::DOGLib::Dog), NULL, CLSCTX_INPROC_SERVER,
        __uuidof(::DOGLib::_DDog), (void **)&pDog);

    //ASSERT(pDog);

    hr = pDog->ShowName();

    pDog->Release();


    return 0;
}
