// EventByref_client1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "EBSink1.h"

CComModule _Module;

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	CoInitialize(NULL);

	EBSink1		s1;
	s1.connect();
	s1.m_eb1->makeEventTest();
	s1.m_eb1->makeEvent1();
	s1.m_eb1->makeEvent2();
	s1.disconnect();

	s1.~EBSink1();

	CoUninitialize();
	return 0;
}
