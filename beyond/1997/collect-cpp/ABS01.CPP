
#include <iostream.h>

#define interface	struct

interface IUnknown {
	virtual long AddRef() = 0;
};

interface IX : IUnknown {
	virtual void Fx() = 0;
};

interface IY : IUnknown {
	virtual void Fy() = 0;
};

interface IDeleUnknown {
	virtual long DeleAddRef() = 0;
};

class CA : public IX, public IY {
public:

	virtual long AddRef() { return 123; }

	virtual void Fx() { cout << "\tFx" << endl; }
	virtual void Fy() { cout << "\tFy" << endl; }
};

class CB : public IY, public IDeleUnknown {
public:
	virtual long AddRef() { return 567; }
	virtual long DeleAddRef() { return 1000; }

	virtual void Fy() { cout << "\tFx2" << endl; }


};

void main() {

	CA *ins01;

	CB *insb;
	IX *pIX;

	ins01 = new CA;
	insb = new CB;

	pIX = (IX *)insb;
}
