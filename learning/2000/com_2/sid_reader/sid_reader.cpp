// sid_reader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <strstrea.h>

strstream *SidToString(PSID psid) {
	strstream	*pstr	= new strstream;
	strstream &	str	= *pstr;

	if (!IsValidSid(psid)) {
		return pstr;
	}

	// retrieve identifier authority
	PSID_IDENTIFIER_AUTHORITY	pia	=
		GetSidIdentifierAuthority(psid);

	str	<< "S-" << SID_REVISION << "-";

	if ((pia->Value[0] != 0) || (pia->Value[1] != 0)) {
		str	<< (USHORT)pia->Value[0]
			<< (USHORT)pia->Value[1]
			<< (USHORT)pia->Value[2]
			<< (USHORT)pia->Value[3]
			<< (USHORT)pia->Value[4]
			<< (USHORT)pia->Value[5];
	} else {
		str	<< (
				(ULONG)(pia->Value[5]		) +
				(ULONG)(pia->Value[4] << 8	) +
				(ULONG)(pia->Value[3] << 16	) +
				(ULONG)(pia->Value[2] << 24	)
			);
	}

	DWORD	dw	= *GetSidSubAuthorityCount(psid);
	for (int i = 0; i < (int)dw; i++) {
		str	<< "-" << ::GetSidSubAuthority(psid, i);
	}
	return pstr;
}

int main(int argc, char* argv[])
{
	DWORD	dwSize	= 0;
	HANDLE	hToken;

	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
		cout	<< "Error ::OpenProcessToken "
			<< GetLastError() << endl;
		return 0;
	}

	if (!GetTokenInformation(hToken, TokenGroups, NULL, dwSize, &dwSize)) {
		DWORD	dw	= GetLastError();
		if (dw != ERROR_INSUFFICIENT_BUFFER) {
			cout	<< "Error ::GetTokenInformation "
				<< dw << endl;
			return 0;
		}
	}

	PTOKEN_GROUPS	pTokenGroups	= (PTOKEN_GROUPS)GlobalAlloc(GPTR, dwSize);

	if (!GetTokenInformation(hToken, TokenGroups, pTokenGroups, dwSize, &dwSize)) {
		cout	<< "Error ::GetTokenInformation "
			<< GetLastError() << endl;
	} else {
		for (int i = 0; i < (int)pTokenGroups->GroupCount; i++) {
			cout	<< SidToString(pTokenGroups->Groups[i].Sid)->str()
				<< endl;
		}
	}

	if (pTokenGroups) {
		GlobalFree(pTokenGroups);
	}

	return 0;
}
