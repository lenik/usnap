// vtbl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define VTBL2

#ifdef VTBL1
	class _declspec(dllexport) c {
	public:
		virtual void f1() {  __asm nop }
		virtual void f2() {  __asm nop }
		virtual void f3() {  __asm nop }
		virtual void f4() {  __asm nop }
		virtual void f5() {  __asm nop }
	};

	class d : public c {
		virtual void f1() {  __asm nop }
		virtual void f2() {  __asm nop }
		virtual void f3() {  __asm nop }
		virtual void f4() {  __asm nop }
		virtual void f5() {  __asm nop }
	};

	int main(int argc, char* argv[])
	{
		int sc = sizeof(c);

		c x;

		long px = (long)(void *)&x;
		__asm mov eax, px

		__brk;

		x.f1();
		x.f2();
		x.f3();
		x.f4();
		x.f5();

		return 0;
	}
#endif

#ifdef VTBL2
	struct I1 {
		virtual void Hello() = 0;
	};
	struct I1_vtbl {
		void *pHello;
	};
	typedef I1_vtbl VTBLI1, *PVTBLI1;

	class C1 : public I1 {
	public:
		virtual void Hello() {
			printf("hello\n");
		}
	};
	class C2 : public I1 {
	public:
		virtual void Hello() {
			printf("Oh, where is my hello? \n");
		}
	};

	BOOL ChangeVtbl(void *pDestObj, int iDest, void *pSrcObj, int iSrc) {
		if (!pDestObj || !pSrcObj) return FALSE;

		((void **)pDestObj)[iDest] = ((void **)pSrcObj)[iSrc];
		return TRUE;
	}

	void main() {
		C1 x1;
		C2 x2;
		I1 *px1 = &x1;
		I1 *px2 = &x2;

		px1->Hello();
		px2->Hello();

		PVTBLI1 pvtbl_x1, pvtbl_x2;
		PVTBLI1 *ppvtbl_x1, *ppvtbl_x2;
		ppvtbl_x1 = (PVTBLI1 *)px1;
		ppvtbl_x2 = (PVTBLI1 *)px2;
		pvtbl_x1 = *ppvtbl_x1;
		pvtbl_x2 = *ppvtbl_x2;

		*ppvtbl_x1 = *ppvtbl_x2;
		//pvtbl_x1->pHello = pvtbl_x2->pHello;
		px1->Hello();
	}


#endif
