// winc_simple.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define onum(x)		printf("%d", x);

class IA {
public:
	virtual void _stdcall method1() = 0;
};


class CAimp1 : public IA {
public:
	virtual void _stdcall method1();
};
void CAimp1::method1() {
	MessageBox(NULL, "CAimp1::method1", NULL, MB_OK);
}

class CA : public IA {
public:
	virtual void _stdcall method1();
public:
	virtual void _stdcall Af1();
};
void _stdcall CA::method1() {
	printf("an implementation of IA::method1()\n");
}
void _stdcall CA::Af1() {
	printf("(exported) Af1\n"); ;
}

void	_stdcall	ef1() {
	printf("EF1\n");
}
void			ef2() {
	printf("EF2\n");
}
_declspec(dllexport)  void  ef3() {
	printf("EF3\n");
}

class CB {
public:
	virtual void Bf1() { printf("Bf1\n"); }
};
class CAB : public CA, public CB {
public:
	virtual void ABf1() { printf("ABf1\n"); }
};

void F1(CA a) {
	a.Af1();
}
void F2(CB b) {
	b.Bf1();
}

typedef IA * (_stdcall *IAProc)(void);

CAimp1 * _stdcall DLL_geneIA_1();
IA *	_stdcall DLL_geneIA_2();
IA *	_stdcall DLL_geneIA_NULL();

void	_stdcall DLL_prob();

IAProc	pDLL_geneIA_1;
IAProc	pDLL_geneIA_2;
IAProc	pDLL_geneIA_NULL;

void main() {
	char	_path[512];
	GetEnvironmentVariable("PATH", _path, 500);
	strcat(_path, ";V:\\temp\\DLL_Research\\DLL_E1\\Debug");
	SetEnvironmentVariable("PATH", _path);

	HMODULE	hDLL;
	hDLL		= LoadLibrary("DLL_E1.exe");

	if (hDLL == NULL) {
		MessageBox(NULL, "couldn't load library DLL_E1.exe!", NULL, MB_OKCANCEL);
		return;
	}

	pDLL_geneIA_1	= (IAProc)GetProcAddress(hDLL, "DLL_geneIA_1");
	pDLL_geneIA_2	= (IAProc)GetProcAddress(hDLL, "DLL_geneIA_2");
	pDLL_geneIA_NULL= (IAProc)GetProcAddress(hDLL, "DLL_geneIA_NULL");

	IA	*pA = new CAimp1;
	pA->method1();

	pA = pDLL_geneIA_NULL();
	if (pA != NULL) {
		pA->method1();
	}

	DLL_prob();

	CAimp1	*pA1;
	pA1 = DLL_geneIA_1();
	pA1->method1();

	pA = DLL_geneIA_2();
	pA->method1();

	FreeLibrary(hDLL);
}

/*
int main() {
	CAB ab;
	F1(ab);
	F2(ab);
	return 0;
	IStorage *pStg;
	IEnumSTATSTG *ppenum;
	pStg->EnumElements(0, NULL, 0, &ppenum);

	ppenum->Reset();
	ppenum->Next(1, &rgelt, &pc);
	IPersistStorage *ps;

}
*/
/*
int main(int argc, char* argv[])
{
	HRESULT hr;
	LPMALLOC pMalloc;

	//hr = CoCreateInstance(CLSID_ICONSOLE, NULL, 0, IID_ICONSOLE, (LPVOID)&pCon);

	hr = CoGetMalloc(MEMCTX_TASK, &pMalloc);
	if (SUCCEEDED(hr)) {
		printf("succ in get malloc. ");
		onum(pMalloc->AddRef());
		pMalloc->Release();
	} else {
		printf("Error in get malloc. ");
	}

	return 0;
}
*/
