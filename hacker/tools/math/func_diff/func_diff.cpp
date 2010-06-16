// func_diff.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#define interface struct;


template<class _t>
interface I_pure_numeric_exp {
};

template<class _t>
class pure_numeric {
public:
	typedef _t::

public:
	inline operator _t() const;

	pure_numeric operator+(_t&) const;
	pure_numeric operator-(_t&) const;
	pure_numeric operator*(_t&) const;
	pure_numeric operator/(_t&) const;
	pure_numeric operator+=(_t&) const;
	pure_numeric operator-=(_t&) const;
	pure_numeric operator*=(_t&) const;
	pure_numeric operator/=(_t&) const;

public:
	pure_numeric();
	pure_numeric(const pure_numeric<_t>&);
	pure_numeric(const _t&);
};

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	return 0;
}
