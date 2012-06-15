// cpp_hints.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <pos/pos.h>
using namespace pos;

template<typename _ty>
struct _Type {
	_ty _val;
};

typedef _Type<u16_2t> z16_t;

typedef _Type<r16_t> Float;

struct CC {
	struct c1;

	struct c2;
	struct c2 {
		int z;
		int h;
	};
};

struct CC::c1 {
	int x;
	int y;
};

CC cc1;

union UUU {
	//r17_t f;
	int z[2][2];
			i8_t	i1[128];
			i16_t	i2[64];
			i32_t	i4[32];
			u8_t	u1[128];
			u16_t	u2[64];
			u32_t	u4[32];
			r16_t	r2[64];
			r32_t	r4[32];
			c16_t	c2[32];
			c32_t	c4[8];
	var_t v1;
};

UUU u1;


int main(int argc, char* argv[])
{

	cc1
	_DEF(int,dfgf)(int a, int b) {
		return a + b;
	} _AS(add);

	_DEF(int, ghsdfg)(int a, int b) {
		return a + b;
	} _AS(sub);

	int x = add(3, 4);
	int y = sub(3, 4);

	UUU u;
//	u.c[0]._val[0] = 3;
	float f;
//	f = u.f;

	return 0;
}
