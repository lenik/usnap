// change_default_launch_permission.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <strstrea.h>

strstream	GetFormattedError() {
	strstream	*pstr	= new strstream;
	strstream &	str	= *pstr;

	DWORD		dwLastError	= GetLastError();
	if (!dwLastError) return str;

	BYTE		width	= 0;
	DWORD		flags;
	flags		= FORMAT_MESSAGE_MAX_WIDTH_MASK &width;
	flags		|= FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS;

	char		s[1024];
	FormatMessage(flags, NULL, dwLastError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			s, 1024, NULL);
	str		<< s;
	return str;
}

int main(int argc, char* argv[])
{
	PSECURITY_DESCRIPTOR	pSD	= (PSECURITY_DESCRIPTOR)
						LocalAlloc(LPTR, SECURITY_DESCRIPTOR_MIN_LENGTH);
	if (pSD == NULL) {
		cout	<< "LocalAlloc failed. " << endl;
		return 0;
	}

	if (!InitializeSecurityDescriptor(pSD, SECURITY_DESCRIPTOR_REVISION)) {
		cout	<< "InitializeSecurityDescriptor failed. " << endl;
		return 0;
	}

	DWORD	cbACL	= 1024;
	PACL	pACLNew	= (PACL)LocalAlloc(LPTR, cbACL);
	if (pACLNew == NULL) {
		cout	<< "LocalAlloc failed. " << endl;
		return 0;
	}

	if (!InitializeAcl(pACLNew, cbACL, ACL_REVISION2)) {
		cout	<< "InitializeAcl failed. " << endl;
		return 0;
	}

	DWORD	cbSID			= 1024;
	PSID	pSID			= (PSID)LocalAlloc(LPTR, cbSID);
	PSID_NAME_USE	psnuType	= (PSID_NAME_USE)LocalAlloc(LPTR, 1024);
	LPSTR	lpszDomain;
	DWORD	cchDomainName	= 80;
	lpszDomain			= (LPSTR)LocalAlloc(LPTR, cchDomainName);
	if (pSID == NULL || psnuType == NULL || lpszDomain == NULL) {
		cout	<< "LocalAlloc failed. " << endl;
		return 0;
	}

	if (!LookupAccountName((LPSTR)NULL, "Administrator", pSID, &cbSID,
				lpszDomain, &cchDomainName, psnuType)
				) {
		cout	<< "LookupAccountName failed. " << endl;
		return 0;
	}

	if (!IsValidSid(pSID)) {
		cout	<< "SID is not valid. " << endl;
	} else {
		cout	<< "SID is valid. " << endl;
	}

	if (!AddAccessAllowedAce(pACLNew, ACL_REVISION2, 1, pSID)) {
		cout	<< "AddAccessAllowedAce failed. " << endl;
		return 0;
	}

	if (!SetSecurityDescriptorDacl(pSD, TRUE, pACLNew, FALSE)) {
		cout	<< "SetSecurityDescriptorDacl failed. " << endl;
		return 0;
	}

	PSECURITY_DESCRIPTOR	pSRSD	= NULL;
	DWORD			cbSD	= 0;
	if (!MakeSelfRelativeSD(pSD, pSRSD, &cbSD)) {
		DWORD	dw	= GetLastError();
		if (dw != ERROR_INSUFFICIENT_BUFFER) {
			cout	<< "Error MakeSelfRelativeSD: " << dw << endl;
			return 0;
		}
	}

	pSRSD	= (PSECURITY_DESCRIPTOR)LocalAlloc(LPTR, cbSD);
	if (!MakeSelfRelativeSD(pSD, pSRSD, &cbSD)) {
		cout	<< "Error ::MakeSelfRelativeSD "
			<< GetFormattedError().str() << endl;
		return 0;
	}

	HKEY	hkey;

	if (RegOpenKeyEx(
		HKEY_LOCAL_MACHINE,
		"SOFTWARE\\Microsoft\\Ole", 0,
		KEY_SET_VALUE, &hkey) != ERROR_SUCCESS) {
		cout	<< "Error RegOpenKeyEx "
			<< GetFormattedError().str() << endl;
		return 0;
	}

	if (RegSetValueEx(hkey,
		"DefaultAccessPermission", 0, REG_BINARY,
		(BYTE *)pSRSD, cbSD) != ERROR_SUCCESS) {
		cout	<< "Error RegSetValueEx "
			<< GetFormattedError().str() << endl;
		return 0;
	}

	FreeSid(pSID);
	if (pSD != NULL)	LocalFree((HLOCAL)pSD);
	if (pSRSD != NULL)	LocalFree((HLOCAL)pSRSD);
	if (pACLNew != NULL)	LocalFree((HLOCAL)pACLNew);
	if (psnuType != NULL)	LocalFree((HLOCAL)psnuType);
	if (lpszDomain != NULL)	LocalFree((HLOCAL)lpszDomain);

	return 0;

}
