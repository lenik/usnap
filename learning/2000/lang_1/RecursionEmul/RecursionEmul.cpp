// RecursionEmul.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>

typedef std::vector<int> ivector;

//#define PRINT_OUT

int show_as_int(ivector& bin) {
	int v = 0;
	ivector::iterator i = bin.begin();
	for (; i != bin.end(); ++i) {
		v = v * 3 + *i;
	}
#ifdef PRINT_OUT
	printf("%d\t", v);
#endif
	return v;
}

ivector _b;

// 传统递归
void enum_classic(int i, int bits) {
	if (i == bits) { // if i >= bits
		show_as_int(_b);
	} else {
		// P@ 0
		_b[i] = 0;
		enum_classic(i + 1, bits);
		// P@ 1
		_b[i] = 1;
		enum_classic(i + 1, bits);
		// P@ 2
		_b[i] = 2;
		enum_classic(i + 1, bits);
		// P@ 3
	}
}

// 拟递归
void enum_p(int _current_i, int bits) {
	typedef std::vector<int>	intvector;
	intvector pnest_index;
	pnest_index.resize(bits, 0);

	int i = _current_i;
	// 判断是否回溯到最开始之前。
	while (i >= 0) {
		// 判断的是叶结点成立条件；
		if (i == bits) {
			show_as_int(_b);
			i--;
		} else {
			switch (pnest_index[i]) {
			case 0:
				_b[i] = 0;
				pnest_index[i] = 1;
				i++;
				break;
			case 1:
				_b[i] = 1;
				pnest_index[i] = 2;
				i++;
				break;
			case 2:
				_b[i] = 2;
				pnest_index[i] = 3;
				i++;
				break;
			case 3:
				pnest_index[i] = 0;
				i--;
				break;
			}
		}
	}
}

int main(int argc, char* argv[])
{
	int tbits=15;
	int t1 = ::GetTickCount();
	_b.resize(tbits, 0);
#ifdef CLASSIC
	enum_classic(0, tbits);
#endif
#ifdef PRECUR
	enum_p(0, tbits);
#endif
	int t2 = ::GetTickCount();
	printf("TIME:%d\n", t2-t1);
	return 0;
}
