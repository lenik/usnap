// knlmem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>

typedef void *LPVOID;

extern "C" {
	HANDLE CreateThread(LPVOID lp1, unsigned stacksize, LPVOID start, LPVOID param,
		unsigned Creation, LPVOID id);
	void Sleep(unsigned dwMills);
	void ExitThread(unsigned code);
}

KSPIN_LOCK	spin;
HANDLE		hthread1;

unsigned thread1(LPVOID lpv);
int main(int argc, char* argv[])
{
	unsigned	Id;
	KIRQL		oldirql;

	printf("A->Create B. \n");
	hthread1 = CreateThread(
		NULL, 0, (LPVOID)thread1,
		NULL, 0, &Id);

	printf("\t(spin == %x)\n", spin);
	printf("A->InitSpin\n");
	KeInitializeSpinLock(&spin);
	printf("\t(spin == %x)\n", spin);

	printf("A->Spin\n");
	KeAcquireSpinLock(&spin, &oldirql);
	printf("A->Sleep 100\n");
	Sleep(100);
	printf("A->/spin\n");
	KeReleaseSpinLock(&spin, oldirql);
	printf("A->end. \n");

	return 0;
}

unsigned thread1(LPVOID lpv) {
	KIRQL	oldirql;
	printf("B->Sleep 5\n");
	Sleep(5);

	printf("B->Spin\n");
	KeAcquireSpinLock(&spin, &oldirql);
	printf("B->/spin\n");
	KeReleaseSpinLock(&spin, oldirql);
	printf("B->end. \n");
	ExitThread(0);
	return 0;
}
