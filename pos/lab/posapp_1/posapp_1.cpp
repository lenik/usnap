// posapp_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <pos/pos.h>
using namespace pos;
using namespace pos::matrix;

int main(int argc, char* argv[])
{

	M m1;
	M m2;

	util::v128_t v;
	v.a = sizeof(m1);

	__zero(m1);

	return 0;
}
