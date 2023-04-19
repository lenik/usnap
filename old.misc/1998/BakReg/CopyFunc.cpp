class Copy {
	int Level;
	DWORD dwValueCount, dwMaxValueNameLen, dwMaxValueDataLen;
	HKEY hIgnoreKey;
	LPSTR Buf;
public:
	BOOL CopyKey(HKEY hKeyS, HKEY hKeyD, BOOL Sub);
	BOOL CopyValue(HKEY hKeyS, HKEY hKeyD);
public:
	Copy(HKEY hIgnoreKey) {
		Level = 0;
		this->hIgnoreKey = hIgnoreKey;
		Buf = new CHAR[10000];
	}
	~Copy() { delete Buf; }
};

BOOL Copy::CopyValue(HKEY hKeyS, HKEY hKeyD) {
	LONG l;
	DWORD j;
	LPSTR lpValueName = new CHAR[dwMaxValueNameLen];
	LPBYTE lpValueData = new BYTE[dwMaxValueDataLen];
	DWORD dwValueType;
	DWORD dwNL, dwDL;
	if (lpValueName == NULL || lpValueData == NULL) {
		PrintError(NULL, "内存分配错误!", GetLastError());
		return FALSE;
	}

	for (j = 0; j < dwValueCount; j++) {
		dwNL = dwMaxValueNameLen;
		dwDL = dwMaxValueDataLen;
		l = RegEnumValue(
			hKeyS,
			j,
			lpValueName,
			&dwNL,
			NULL,
			&dwValueType,
			lpValueData,
			&dwDL);
		wsprintf(Buf, "%s[%d]:\"%s\"...... ", lpValueName, dwDL, lpValueData);
		r->Append((Level + 1) * SWidth);
		r->Append(Buf);
		if (l == ERROR_SUCCESS) {
			l = RegSetValueEx(
				hKeyD,
				lpValueName,
				0,
				dwValueType,
				lpValueData, dwDL);
			if (l == ERROR_SUCCESS) {
				r->Append("复制成功!\r\n");
			} else {
				PrintError(NULL, "设置目标键值错误: ", l);
			}
		} else {
			PrintError(NULL, "枚举键值错误: ", l);
		}
	}
	delete lpValueData;
	delete lpValueName;
	return TRUE;
}

/*
 * CopyKey		Copy Key hKeyS to hKey hKeyD, with sub-directories if BOOL Sub set.
 */
BOOL Copy::CopyKey(HKEY hKeyS, HKEY hKeyD, BOOL Sub) {
	LONG l;
	DWORD j;
	LPSTR lpKeyName;
	DWORD dwKeyCount, dwMaxKeyLen;

	l = RegQueryInfoKey(
		hKeyS,
		NULL,	/* LPTSTR lpClass */
		NULL,	/* LPDWORD lpcbClass */
		NULL,	/* LPDWORD Reserved */
		&dwKeyCount,
		&dwMaxKeyLen,
		NULL,	/* LPDWORD lpcbMaxClassLen */
		&dwValueCount,
		&dwMaxValueNameLen,
		&dwMaxValueDataLen,
		NULL,	/* LPDWORD lpcbSecurityDescriptor */
		NULL);	/* PFILETIME lpftLastWriteTime */

	dwMaxValueNameLen++;	/* The return value doesn't include terminated-null */
	CopyValue(hKeyS, hKeyD);

	if (Sub == FALSE) { return TRUE; }

	lpKeyName = new CHAR[dwMaxKeyLen];
	for (j = 0; j < dwKeyCount; j++) {
		l = RegEnumKey(hKeyS, j, lpKeyName, dwMaxKeyLen);
		wsprintf(Buf, ">>> %s: ", lpKeyName);
		r->Append("\r\n");
		r->Append(Level * SWidth);
		r->Append(Buf);
		if (l == ERROR_SUCCESS) {
			HKEY hKeyS1, hKeyD1;
			l = RegOpenKey(hKeyS, lpKeyName, &hKeyS1);
			if (l == ERROR_SUCCESS) {
				if (hKeyS1 != hIgnoreKey) {
					l = RegCreateKey(hKeyD, lpKeyName, &hKeyD1);
					if (l == ERROR_SUCCESS) {
						//MessageBox(NULL, Buf, "Key Info.", MB_OK);
						r->Append("被建立.\r\n");
						Level++;
						CopyKey(hKeyS1, hKeyD1, Sub);
						Level--;
						RegCloseKey(hKeyD1);
					} else { PrintError(NULL, "打开 / 建立目标主键错误: ", l);	}
				}	// No nest myself
				RegCloseKey(hKeyS1);
			} else { PrintError(NULL, "打开源主键错误: ", l); }	// RegOpenKey
		} else { PrintError(NULL, "枚举主键错误: ", l); }	// EnumKey
	}
	delete lpKeyName;
	return TRUE;
}
