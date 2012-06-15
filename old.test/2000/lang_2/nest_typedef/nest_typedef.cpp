
#include "stdafx.h"

#include "nt.h"

#include <list>

typedef std::list<int>		ints;
typedef std::list<ints>		ints2;
typedef std::list<ints2>	ints3;

typedef std::list<ints3>	ints4;
typedef std::list<ints4>	ints5;
//typedef std::list<ints5>	ints6;
//typedef std::list<ints6>	ints7;
//typedef std::list<ints7>	ints8;

struct s1 {
	typedef char	inttype;
};

struct s2 : public s1 {
	inttype a;
	typedef long	inttype;
	inttype b;
};

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	ints5 x;

	s2 y;

	int ll = sizeof(y.a);
	ll = sizeof(y.b);

	ll = sizeof(s2::inttype);

	return 0;
}
