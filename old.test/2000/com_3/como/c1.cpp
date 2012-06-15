
#pragma once

#include "stdafx.h"
#include "como.h"
#include "resource.h"

class AbstractClass1 :
	public CComObjectRoot,
	public CComCoClass<AbstractClass1, &CLSID_Como1>,
	public IDispatchImpl<IComo1, &IID_IComo1> {
public:
	AbstractClass1();
	virtual ~AbstractClass1() {}

public:
	STDMETHOD(f1)();
	STDMETHOD(f2)();

public:
	BEGIN_COM_MAP(AbstractClass1)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IComo1)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_Como1)
	DECLARE_NOT_AGGREGATABLE(AbstractClass1)

protected:
};

typedef CComObject<AbstractClass1>	AbstractClass1Impl;

STDMETHODIMP
AbstractClass1::f1() {
	return S_OK;
}

STDMETHODIMP
AbstractClass1::f2() {
	this->AddRef();
	return S_OK;
}

AbstractClass1::AbstractClass1() {
	((AbstractClass1Impl *)this)->AddRef();
}

/*
class ConcreteClass1 :
	public AbstractClass1,
	public CC
*/

class AbsC1 {
public:
	AbsC1() {
		f1();
	//	f2();
		f3();
	}

	void virtual f1() {}
	void virtual f2() = 0;

	void virtual f3() {
		f1();
	//	f2();
	}

};

class IC1 : public AbsC1 {
	void virtual f2() {}
};

IC1 g_ic1_1;
