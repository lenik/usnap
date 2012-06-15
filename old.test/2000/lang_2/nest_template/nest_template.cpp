// nest_template.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

template<class T1_T>
class T1 {
public:
	template<class iT_T>
	class iT {
	public:
		iT_T	member;
	};
	T1_T		member;
	iT<T1_T>	member_object;
};

template<class T2_T>
class T2 {
public:
	template<class iT_T>
	class iT {
	public:
		iT_T	member;
	};
	T2_T		member;
	iT<T2_T>	member_object;
};

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	T1<int> t11;
	T2<int> t21;

	T1<int>::iT<int> t12;
	T2<int>::iT<int> t22;

	t11.member = t21.member = t12.member = t22.member = 0;

	return 0;
}
