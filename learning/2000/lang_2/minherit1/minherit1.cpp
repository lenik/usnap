// minherit1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "minherit1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;


class I1 {
public:
	virtual void f1() = 0;
};

class N_I1 {
public:
	virtual void N_f1() = 0;
};


#define __OFF_P		8
#define _off(cls, basecls)  ((int)(static_cast<basecls *>((cls *)__OFF_P)) - __OFF_P)

/*
#define offsetofclass(base, derived)
(
	(DWORD)(
		static_cast<base*>(
			(derived*)_ATL_PACKING
		)
	) - _ATL_PACKING
)
*/

class A : public N_I1 {
public:
	virtual void N_f1() {
		cout << "A - N_I1		@" << _off(A, N_I1) << endl;
	}
};

class B : public I1, public A {
public:
	virtual void f1() {
		cout << "B - I1			@" << _off(B, I1) << endl;
		N_f1();
	}
	virtual void N_f1() {
		cout << "B - N_I1		@" << _off(B, N_I1) << endl;
		A::N_f1();
	}
};

class I2 : public I1 {
public:
	virtual void f1() = 0;
};

class D : public I2, public B {
public:
	virtual void f1() {
		cout << "D - I2			@" << _off(D, I2) << endl;
		N_f1();
		I2::f1();
	}
	virtual void N_f1() {
		cout << "D - N_I1		@" << _off(D, N_I1) << endl;
		B::N_f1();
	}
};

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		D x;
		x.f1();
	}

	return nRetCode;
}
