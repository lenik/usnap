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

	// ǿ��ת�����������ʹ�òο��ķ�������Ҫ�� x ����ʹ�����鶨��
	// ��ʵ�ϣ�û�а취��ָ��ת��Ϊ���顣
	//(int (&)[3])&(int&)(*x);
	INT3& x_ref1 = x;
	int (&x_ref2)[3] = (INT3&)x;
	int (&x_ref3)[3] = (int (&)[3])x;
	int refval;
	refval = x_ref1[0];
	refval = x_ref2[1];
	refval = x_ref3[2];

	// ���ο�������� ��ֵ ������ȷ�ı���������ν���ַת������ֵ��
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

	// int ** ���ܴ��� int[*][3] ��������Ϊ [3] �����±꽫����һ��[*]�ϲ������Կռ䣬
	// ���� int ** ��,
	//			int **	--> (int *) *
	//	��һ�� * ��[] ��� (int *)����һ��ָ�룬
	//	�ڶ��� * ��[] �� ͨ�� <��ָ��> ��� int��
	int **pp1 = (int **)y;
	//a = pp1[2][1];	// �ڴ���ʴ���

	// int [4][*] ��������ġ�

	return 0;
}
