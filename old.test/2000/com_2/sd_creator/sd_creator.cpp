// sd_creator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>

// create a security descriptor

int main(int argc, char* argv[])
{

	PSECURITY_DESCRIPTOR	pSD	= (PSECURITY_DESCRIPTOR)
		::LocalAlloc(LPTR, SECURITY_DESCRIPTOR_MIN_LENGTH);

	if (pSD == NULL) {
		cout	<< "LocalAlloc failed. " << endl;
		return 0;
	}

	if (!InitializeSecurityDescriptor(pSD, SECURITY_DESCRIPTOR_REVISION)) {
		cout	<< "InitializeSecurityDescriptor failed. " << endl;
		return 0;
	}

	DWORD		cbACL	= 1024;
	PACL		pACLNew	= (PACL)::LocalAlloc(LPTR, cbACL);

	if (pACLNew == NULL) {
		cout	<< "LocalAlloc failed. " << endl;
		return 0;
	}

	if (!InitializeAcl(pACLNew, cbACL, ACL_REVISION2)) {
		cout	<< "InitializeAcl failed. " << endl;
		return 0;
	}

	DWORD		cbSID	= 1024;
	PSID		pSID	= (PSID)::LocalAlloc(LPTR, cbSID);
	PSID_NAME_USE	psnuType= (PSID_NAME_USE)::LocalAlloc(LPTR, 1024);
	LPSTR		lpszDomain;
	DWORD		cchDomainName	= 80;

	lpszDomain	= (LPSTR)::LocalAlloc(LPTR, cchDomainName);
	if (pSID == NULL || psnuType == NULL || lpszDomain == NULL) {
		cout	<< "LocalAlloc failed. " << endl;
		return 0;
	}

	if (!LookupAccountName((LPSTR)NULL,
		"Administrator",
		pSID,
		&cbSID,
		lpszDomain,
		&cchDomainName,
		psnuType)) {
		cout	<< "LookupAccountName failed. " << endl;
		return 0;
	}

	if (!IsValidSid(pSID)) {
		cout	<< "SID is not valid. " << endl;
	} else {
		cout	<< "SID is valid. " << endl;
	}

	if (!AddAccessAllowedAce(pACLNew, ACL_REVISION2, GENERIC_ALL, pSID)) {
		cout	<< "AddAccessAllowedAce failed. " << endl;
		return 0;
	}

	if (!SetSecurityDescriptorDacl(pSD, TRUE, pACLNew, FALSE)) {
		cout	<< "SetSecurityDescriptorDacl failed. " << endl;
		return 0;
	}

	SECURITY_ATTRIBUTES	sa;
	sa.nLength		= sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor	= pSD;
	sa.bInheritHandle	= TRUE;

	DWORD	dw = 0;
	HKEY	hk = NULL;
	LONG	l = RegCreateKeyEx(HKEY_LOCAL_MACHINE,
				"SOFTWARE\\MyKey", 0, "", 0,
				KEY_READ | KEY_WRITE, &sa, &hk, &dw);
	::FreeSid(pSID);
	if (pSD != NULL)	LocalFree((HLOCAL)pSD);
	if (pACLNew != NULL)	LocalFree((HLOCAL)pACLNew);
	if (psnuType != NULL)	LocalFree((HLOCAL)psnuType);
	if (lpszDomain != NULL)	LocalFree((HLOCAL)lpszDomain);

	return 0;
}

// Ä£·ÂÓÃ»§
int main2(int argc, char **argv) {
	HKEY	hkey;

	if (RegOpenKeyEx(
		HKEY_CLASSES_ROOT,
		"AppID\\{73FDDC80-AEA9-101A-98A7-00AA00374959}",
		0,
		KEY_SET_VALUE,
		&hkey) != ERROR_SUCCESS) {
		cout	<< "Error ::RegOpenKeyEx"
			<< GetLastError() << endl;
		return 0;
	}

	char *sz	= "Interactive User";
	if (RegSetValueEx(hkey, "RunAs", 0, REG_SZ,
		(BYTE *)sz, ::lstrlen(sz)) != ERROR_SUCCESS) {
		cout	<< "Error ::RegSetValueEx " << GetLastError() << endl;
		return 0;
	}

	return 0;
}
