/*
 * PrintError	�������, �������Reporter
 *   hWnd		��ʾ����
 *   lpHint		������Ϣ
 *   e
 */
void PrintError(HWND hWnd, LPSTR lpHint, DWORD e) {
	LPVOID lpMsg;
	LPSTR lpPrintMsg;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, e, 0, (LPTSTR)&lpMsg, 0, NULL);
	lpPrintMsg = new char[lstrlen(lpHint) + lstrlen((LPSTR)lpMsg) + 3];
	if (lpPrintMsg != NULL) {
		lstrcpy(lpPrintMsg, lpHint);
		lstrcat(lpPrintMsg, (LPSTR)lpMsg);
		lstrcat(lpPrintMsg, "\r\n");
		MessageBox(hWnd, lpPrintMsg, lpHint, MB_OK);
		r->Append(lpPrintMsg);
		delete lpPrintMsg;
	} else {
		MessageBox(hWnd, (LPCTSTR)lpMsg, lpHint, MB_OK);
	}
	LocalFree(lpMsg);
}

void RegClose(HKEY hKeyS, HKEY hKeyD) {
	if (hKeyS != NULL) { RegCloseKey(hKeyS); }
	if (hKeyD != NULL) {RegCloseKey(hKeyD); }
	return;
}

struct StrAssoc {
	HKEY hkVal;
	LPSTR lpStr;
} sa[6] = {
	{ HKEY_CLASSES_ROOT, "HKEY_CLASSES_ROOT" },
	{ HKEY_CURRENT_USER, "HKEY_CURRENT_USER" },
	{ HKEY_LOCAL_MACHINE, "HKEY_LOCAL_MACHINE" },
	{ HKEY_USERS, "HKEY_USERS" },
	{ HKEY_CURRENT_CONFIG, "HKEY_CURRENT_CONFIG" },
	{ HKEY_DYN_DATA, "HKEY_DYN_DATA" }
};

/*
 * PreKey		Ԥ�������, ���������ϵͳԤ���������ʼ, �����Ԥ�������ǰ׺,
 *				�����ض�ӦԤ�������; ����Ĭ��ʹ��Ԥ����HKEY_USERS��.
 *   *_lpStr		Ԥ�������
 * ����:		Ԥ�������
 */
INT PreKey(LPSTR *_lpStr) {
	int i, l;
	CHAR s;
	LPSTR lpStr = new CHAR[lstrlen(*_lpStr) + 1];
	if (lpStr == NULL) { return 3; }
	lstrcpy(lpStr, *_lpStr);
	for (int c = 0; c < 6; c++) {
		l = lstrlen(sa[c].lpStr);
		s = lpStr[l];
		lpStr[l] = '\0';
		i = lstrcmpi(sa[c].lpStr, lpStr);
		lpStr[l] = s;
		if (i == 0) {
			(*_lpStr) += l;
			if (**_lpStr == '\\') { (*_lpStr)++; }
			break;
		}
	}
	return c >= 6 ? 3 : c;
}

BOOL bSub = FALSE;

/*
 * PerCmdLine	������Ԥ����
 *   lpCmdLine		������
 *   *hKeyS			����Դ����
 *   *hKeyD			����Ŀ�����
 *   *strNameS		����Դ����
 *   *strNameD		����Ŀ�����
 * ����:		�������
 */
int PerCmdLine(LPSTR lpCmdLine, HKEY *hKeyS, HKEY *hKeyD, LPSTR *strNameS, LPSTR *strNameD) {
	LPSTR lpA1 = "", lpA2 = "Backup";
	LONG l;
	CHAR c;
	BOOL bSpecify = FALSE;
	INT i = 0, a, b;

	while ((c = *lpCmdLine) != '\0') {
		if (IS_SPACE(c)) continue;
		if (c == '-' && (*(lpCmdLine + 1) == 's' || *(lpCmdLine + 1)== 'S')) {
			bSub = TRUE;
			lpCmdLine += 2;
			continue;
		}
		if (i == 0) {	// Parameter / Source
			lpA1 = lpCmdLine;
			while (*lpCmdLine != '\0' && (!IS_SPACE(*lpCmdLine))) { lpCmdLine++; }
			if (*lpCmdLine == '\0') break;
			*lpCmdLine++ = '\0';
			i++;
		} else if (i == 1) {	// Dest
			lpA2 = lpCmdLine;
			while (*lpCmdLine != '\0' && (!IS_SPACE(*lpCmdLine))) { lpCmdLine++; }
			*lpCmdLine++ = '\0';
			bSpecify = TRUE;
			i++;
			break;
		}
	}

	r->Append("��Դ��: ");
	r->Append(lpA1);
	*hKeyS = sa[a = PreKey(&lpA1)].hkVal;
	l = lstrlen(lpA1) == 0 ? ERROR_SUCCESS : RegOpenKey(*hKeyS, lpA1, hKeyS);
	if (l == ERROR_SUCCESS) {
		r->Append("�ɹ�!\r\n");
	} else {
		r->Append("ʧ��: ");
		PrintError(NULL, "�򿪳�ʼԴ������: ", l);
		return 1;
	}

	r->Append("��Ŀ���: ");
	r->Append(lpA2);
	*hKeyD = sa[b = PreKey(&lpA2)].hkVal;
	if (lstrlen(lpA2) == 0) {
		r->Append("�ɹ�!");
		l = ERROR_SUCCESS;
	} else {
		l = RegCreateKey(*hKeyD, lpA2, hKeyD);
		if (l == ERROR_SUCCESS) {
			r->Append("�ɹ�");
		} else {
			PrintError(NULL, bSpecify == TRUE ? "�򿪳�ʼָ��Ŀ�������: " : "�򿪳�ʼȱʡĿ�������: ", l);
			RegCloseKey(*hKeyS);
			return 2;
		}
	}
	r->Append("\r\n");

	if ((*strNameS = new CHAR[lstrlen(sa[a].lpStr) + lstrlen(lpA1) + 2]) != NULL) {
		lstrcpy(*strNameS, sa[a].lpStr);
		if (lstrlen(lpA1) != 0) {
			lstrcat(*strNameS, "\\");
			lstrcat(*strNameS, lpA1);
		}
	}
	if ((*strNameD = new CHAR[lstrlen(sa[b].lpStr) + lstrlen(lpA2) + 2]) != NULL) {
		lstrcpy(*strNameD, sa[b].lpStr);
		if (lstrlen(lpA2) != 0) {
			lstrcat(*strNameD, "\\");
			lstrcat(*strNameD, lpA2);
		}
	}
	return 0;
}