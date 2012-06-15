// DLL_E1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

typedef int (_stdcall *INTFUNC)(void);

#define MSG(s)		MessageBox(NULL, s, NULL, 0)
#define MSGB(s)		MSG(s)

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.
	HMODULE hm;
	INTFUNC f1;

	hm = LoadLibrary("DLL_E1.exe");
	if (hm == NULL) {
		MSG("error load library");
	} else {
		f1 = GetProcAddress(hm, "dllFunc2");
		if (f1 == NULL) {
			MSG("error get proc address. ");
		} else {
			(*f1)();
		}
	}
	return 0;
}


BOOL WINAPI DllMain(HANDLE hInstance, DWORD dwReason, LPVOID) {
	return TRUE;
}

int _stdcall dllFunc1() {
	return 0x1000;
}

int _stdcall dllFunc2() {
	MessageBox(NULL, "Oh, i was waked up!", NULL, 0);
	return -1;
}

class IA {
public:
	virtual void _stdcall method1() = 0;
};

class CAimp1 : public IA {
public:
	virtual void _stdcall method1();
};
void CAimp1::method1() {
	MSGB("CAimp1::method1");
}

class CAimp2 : public IA {
public:
	virtual void _stdcall method1_0();
	virtual void _stdcall method1();
	virtual void _stdcall method2();
};

void CAimp2::method1_0() {
	MSGB("CAimp2::method1_0");
}
void CAimp2::method1() {
	MSGB("CAimp2::method1");
}
void CAimp2::method2() {
	MSGB("CAimp2::method2");
}

static CAimp1		externalImp1;
static CAimp1		*pExtImp1	= &externalImp1;

CAimp1 * _stdcall DLL_geneIA_1() {
	CAimp1	imp1;

	return pExtImp1;

	CAimp1 *p1 = new CAimp1;

	IA *pp = new CAimp1;
	//return pp;
}
IA * _stdcall	DLL_geneIA_2() {
	return new CAimp2;
}

IA * _stdcall	DLL_geneIA_NULL() {
	return NULL;
}

void _stdcall	DLL_prob() {
	int	*i = new int;
	*i	= 1234;
	delete i;
	return;
}
