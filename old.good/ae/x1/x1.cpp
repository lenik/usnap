// x1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

#include <pos/pos.h>
using namespace pos;

#include <list>
#include <vector>



	struct XX {
		int a;
		int b;
		int c;

		int f1() { return 1; }
		int f2() { return 2; }
		int f3() { return 3; }
		int f(int);
		// C2800
		// int operator sizeof() { return 100; }
	};

	int XX::f(int i) {
		int (XX::*_f)();
		int (XX::**_pf)() = (int (XX::**)())&i;
		_f = *_pf;
		return (this->*_f)();
	}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{

	util::vars v;

	matrix_t m;
	v.i = sizeof(m);

	v.a = pvt_c16_33;

	char * const const_str = "abcd";
	const char * str_const = const_str;

	{
		XX sx1;
		int XX::*pXX_b = &XX::b;	// = 4
		sx1.*pXX_b = 3;
		XX *psx1 = &sx1;
		int XX::*bb = (int XX::*)(&XX::b);
		int prel = (int)*(void **)&bb;
		psx1->*(&XX::c) = 5;
		v.a = sx1.b;
		v.b = sx1.c;
	}


	class _C1 {
	private:
		int i1, i2, i3, i4, i5, i6, i7, i8;
	public:
		int d1, d2;
	};
	class _C2 : private _C1 {
	public:
		void _f1() {}
	};

	_C1 c1x;
	_C2 c2x;

	v.a = sizeof(c1x);
	v.b = sizeof(c2x);

	typedef std::list<XX> xxs;
	xxs x1;

	int a;
	a = sizeof(x1);
	a = sizeof(xxs::allocator_type);



	 {
//		PVT a = _pvt(uint8);
		//void *pv = _alloc_auto_pvt(sizeof(_pos_variant::_t_uint8), pvt_uint8);
		//PVT& pa = *(PVT *)pv;

#ifndef _DEBUG
		_asm int 3
#endif

		auto_pvt(u8, a);

		a._body()->_32.m_u8 = 3;

		v.______ = 3;

		//pa->release();
		//delete (void *)pa;
		a._release();

		auto_pointer(pointer_pv, v1);
		Pointer *pv2 = new_pointer(POINTERF_AUTO | pointer_pv, 30);

		auto_pvt_size(36, _xa);
		PVT& xa = _xa;

		xa.hdr = PVTF_AUTO | PVTF_EXTYPE | PVTF_ISOLATED | pvt_cid;
		DWORD *pdw = (DWORD *)xa._4();
		*pdw++ = 0x7F012345;
		*pdw++ = 0x1F6789AB;
		*pdw++ = 0x3F6789AB;
		*pdw++ = 0x1F6789AB;
		*pdw++ = 0x1F6789AB;
		*pdw++ = 0x1F6789AB;
		*pdw++ = 0x1F6789AB;
		*pdw++ = 0x0DEF0123;
		*pdw = (DWORD)new a_t[20];	// subtype: 0123456789ABCDEF0123 -> content
		lstrcpy((LPTSTR)*pdw, _T("hello, world!"));


		v.A = xa._size_subtype_id();
		LPTSTR psz = (LPTSTR)xa._body();

		xa._release();

		//auto_pvt_size(
		v1._release();
		pv2->_destroy();
	}

	return 0;
}
