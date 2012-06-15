
//int DllMain(HANDLE, DWORD, LPVOID

int _stdcall add(int x, int y) {
	return x + y;
}

int _stdcall rol(int x, int y) {
	int z;
	_asm {
		push eax
		push ecx
		mov eax, x
		mov ecx, y
		rol eax, cl
		mov z, eax
		pop ecx
		pop eax
	}
	return z;
}

int _stdcall ror(int x, int y) {
	int z;
	_asm {
		push eax
		push ecx
		mov eax, x
		mov ecx, y
		ror eax, cl
		mov z, eax
		pop ecx
		pop eax
	}
	return z;
}
