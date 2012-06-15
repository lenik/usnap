
interface IX : IUnknown {
	virtual void _stdcall Fx() = 0;
};
interface IY : IUnknown {
	virtual void _stdcall Fy() = 0;
};
interface IZ : IUnknown {
	virtual void _stdcall Fz() = 0;
};

extern "C" const IID	IID_IX;
extern "C" const IID	IID_IY;
extern "C" const IID	IID_IZ;
extern "C" const CLSID	CLSID_Component1;
extern "C" const CLSID	CLSID_Component2;
