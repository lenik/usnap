// mherit2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "mherit2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

using namespace std;




#define IActiveDesigner_GetRuntimeClassID(This,pclsid)	\
    (This)->lpVtbl -> GetRuntimeClassID(This,pclsid)


class I1 {
public:
	virtual int f1() = 0;
};

class I2 {
public:
	virtual int f1() = 0;
};

class C
	: public I1,
	public I2 {
public:
	virtual int f1() {
		return 1;
	}
public:
	C::C() {
		m_1 = 0x01234567;
		m_2 = 0x89ABCDEF;
	}
	int m_1;
	int m_2;
};


int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	C *pC = new C;
	int l;

	l = ((I1 *)(pC))->f1();

	l = sizeof(C);
}
