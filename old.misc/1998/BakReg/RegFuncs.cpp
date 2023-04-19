/*
 * PrintError	报告错误, 并输出到Reporter
 *   hWnd		显示窗口
 *   lpHint		报告信息
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
 * PreKey		预处理键名, 如果键名以系统预定义键名开始, 则调过预定义键名前缀,
 *				并返回对应预定义键柄; 否则默认使用预定义HKEY_USERS键.
 *   *_lpStr		预处理键名
 * 返回:		预定义键柄
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
 * PerCmdLine	命令行预处理
 *   lpCmdLine		命令行
 *   *hKeyS			返回源键柄
 *   *hKeyD			返回目标键柄
 *   *strNameS		返回源键名
 *   *strNameD		返回目标键名
 * 返回:		错误代码
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

	r->Append("打开源键: ");
	r->Append(lpA1);
	*hKeyS = sa[a = PreKey(&lpA1)].hkVal;
	l = lstrlen(lpA1) == 0 ? ERROR_SUCCESS : RegOpenKey(*hKeyS, lpA1, hKeyS);
	if (l == ERROR_SUCCESS) {
		r->Append("成功!\r\n");
	} else {
		r->Append("失败: ");
		PrintError(NULL, "打开初始源键错误: ", l);
		return 1;
	}

	r->Append("打开目标键: ");
	r->Append(lpA2);
	*hKeyD = sa[b = PreKey(&lpA2)].hkVal;
	if (lstrlen(lpA2) == 0) {
		r->Append("成功!");
		l = ERROR_SUCCESS;
	} else {
		l = RegCreateKey(*hKeyD, lpA2, hKeyD);
		if (l == ERROR_SUCCESS) {
			r->Append("成功");
		} else {
			PrintError(NULL, bSpecify == TRUE ? "打开初始指定目标键错误: " : "打开初始缺省目标键错误: ", l);
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