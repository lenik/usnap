// array_typedef.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
/*
int __declspec(naked) retint(int v) {
	__asm {
		mov eax, [esp+4];
		ret
	}
}*/

int __declspec(naked) retint(int& v) {
	__asm {
		mov eax, [esp+4];
		ret
	}
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{

	typedef int INT3[3];

	INT3 x;
	int *x2 = new int[3];
	x[0] = 3;
	x[1] = 33;
	x[2] = 333;
	x2[0] = 4;
	x2[1] = 44;
	x2[2] = 444;

	int (*px2)[3] = (int (*)[3])&x2;

	// 强制转化至数组必须使用参考的方法。但要求 x 必须使用数组定义
	// 事实上，没有办法将指针转化为数组。
	//(int (&)[3])&(int&)(*x);
	INT3& x_ref1 = x;
	int (&x_ref2)[3] = (INT3&)x;
	int (&x_ref3)[3] = (int (&)[3])x;
	int refval;
	refval = x_ref1[0];
	refval = x_ref2[1];
	refval = x_ref3[2];

	// 而参考必须采用 左值 （即明确的变量），如何将地址转换成左值？
	int int1 = 10;
	int int2 = 20;
	int& int1r = int1;
	int& int1rr = int2;

	int **pint1rr = (int **)retint(int1rr);
	//*(int **)&(&int1rr) = &int2;
	*pint1rr = &int2;


	typedef INT3 INT3_4[4];
	INT3_4 y;
	y[2][1] = 5;

	typedef int I34[4][3];
	I34 *z = &y;

	int a = (*z)[2][1];
	int b = a;

	// INT3 * --> int[*][3]
	int (*z1)[3];
	z1 = y;
	a = z1[2][1];

	void *py = y;
	a = ((int (*)[3])py)[2][1];

	// int ** 不能代替 int[*][3] ，这是因为 [3] 定宽下标将于上一级[*]合并成线性空间，
	// 而在 int ** 中,
	//			int **	--> (int *) *
	//	第一次 * 或[] 解出 (int *)，是一个指针，
	//	第二次 * 或[] 将 通过 <该指针> 解出 int。
	int **pp1 = (int **)y;
	//a = pp1[2][1];	// 内存访问错误

	// int [4][*] 是无意义的。

	return 0;
}
