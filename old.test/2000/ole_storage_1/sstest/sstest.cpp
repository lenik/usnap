// sstest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gwin.h"

#define MODE	(STGM_CREATE | STGM_READWRITE | STGM_SHARE_EXCLUSIVE)
#define ERR()	PrintError(GetLastError());

int main(int argc, char* argv[])
{
	HRESULT		hr;
	IStorage	*s1	= NULL,
			*s2	= NULL,
			*s3	= NULL,
			*s4	= NULL;
	IStream		*sm1	= NULL,
			*sm2	= NULL;
	IRootStorage	*rs1	= NULL,
			*rs2	= NULL;

	hr	= StgCreateDocfile(L"B:\\stg01",
		MODE | STGM_TRANSACTED,
		0, &s1);

	if (SUCCEEDED(hr)) {
		hr	= s1->CreateStream(
			L"abcd",
			MODE,
			0, 0,
			&sm1);
		if (SUCCEEDED(hr)) {
			hr	= sm1->Write((LPVOID)"abcdefg!", 9, NULL);
			hr	= sm1->Commit(STGC_DEFAULT);
			sm1->Release();
		} else {
			PrintError(hr);
			return -1;
		}
	}

	if (SUCCEEDED(hr)) {
		s1->QueryInterface(IID_IRootStorage, (LPVOID *)&rs1);
		hr = s1->CreateStorage(
			L"stg01",
			MODE,
			0, 0,
			&s2);
		if (SUCCEEDED(hr)) {
			s2->QueryInterface(IID_IRootStorage, (LPVOID *)&rs2);
			hr = s2->CreateStream(L"stream01", MODE, 0, 0, &sm1);
			if (SUCCEEDED(hr)) {
				hr	= sm1->Write((LPVOID)"Hello, world!", 14, NULL);
				hr	= sm1->Commit(STGC_DEFAULT);
				sm1->Release();
			} else {
				ERR();
			}
		} else {
			ERR();
		}
	} else {
		ERR();
	}

	return 0;
}
