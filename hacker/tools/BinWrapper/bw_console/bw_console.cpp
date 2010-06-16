// bw_console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

extern "C" BOOL _stdcall IsDebuggerPresent();
BOOL _debug = false;

typedef TCHAR * pstr;
pstr paths[100];
int npaths;


#ifdef _UNICODE
#define BW_CONSOLE_SYSFILE	_T("bw_console_u.exe")
#else
#define BW_CONSOLE_SYSFILE	_T("bw_console.exe")
#endif

size_t flength(FILE *pF) {
	long oldp = ::ftell(pF);
	fseek(pF, 0, SEEK_END);
	long endp = ::ftell(pF);
	fseek(pF, oldp, SEEK_SET);
	return endp;
}

TCHAR __buf123[_MAX_PATH];
int access_exe(pstr filename) {
	lstrcpy(__buf123, filename);
	if (_taccess(__buf123, 0) == 0) return 0;

	lstrcpy(__buf123, filename);
	lstrcat(__buf123, TEXT(".com"));
	if (_taccess(__buf123, 0) == 0) return 0;

	lstrcpy(__buf123, filename);
	lstrcat(__buf123, TEXT(".exe"));
	if (_taccess(__buf123, 0) == 0) return 0;

	lstrcpy(__buf123, filename);
	lstrcat(__buf123, TEXT(".bat"));
	if (_taccess(__buf123, 0) == 0) return 0;

	return -1;
}

pstr which(pstr name, int index) {
	pstr path = _tgetenv(TEXT("PATH"));
	int _index = 0;

	TCHAR	test[1000];
	int	i, len;

	for (i = -1; i < npaths; i++) {
		if (i == -1) {
			lstrcpy(test, TEXT("."));
		} else {
			lstrcpy(test, paths[i]);
		}
		pstr semip = _tcschr(test, TEXT(';'));
		if (semip) semip[0] = TEXT('\0');
		len = lstrlen(test);
		if (len < 0) continue;
		if (len > 0) {
			if (test[len - 1] != TEXT(':') && test[len - 1] != TEXT('\\')) {
				test[len++] = TEXT('\\');
				test[len] = TEXT('\0');
			}
		}
		lstrcat(test, name);

                if (access_exe(test) == 0) {
			if (_index == index) {
				TCHAR *pret = new TCHAR[lstrlen(__buf123) + 1];
				lstrcpy(pret, __buf123);
				return pret;
			}
			_index++;
		}
	}
	return NULL;
}

void RETURN(int c) {
	if (_debug) __asm int 3
	::_exit(c);
}

BOOL WritePrivateProfileInt(LPCTSTR lpAppName, LPCTSTR lpKeyName, INT n, LPCTSTR lpFileName) {
	TCHAR buf[100];
	::_stprintf(buf, TEXT("%d"), n);
	return WritePrivateProfileString(lpAppName, lpKeyName, buf, lpFileName);
}

pstr GetProcessName(DWORD pid) {
	HANDLE h = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (h == (HANDLE)-1) return NULL;
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(pe);
	for (BOOL b = ::Process32First(h, &pe); b; b = ::Process32Next(h, &pe)) {
		pe.dwSize = sizeof(pe);

		if (pe.th32ProcessID == pid) {
			pstr pret = new TCHAR[lstrlen(pe.szExeFile) + 1];
			lstrcpy(pret, pe.szExeFile);
			return pret;
		}
	}
	CloseHandle(h);

	return NULL;
}

void init() {
	pstr path = _tgetenv(TEXT("PATH"));

	for (npaths = 0; npaths <= 100; npaths++) {
		if (path == NULL || path[0] == TEXT('\0')) break;
		while (path[0] == TEXT(' ')) path++;
		paths[npaths] = path;
		path = ::_tcschr(path, TEXT(';'));
		if (path != NULL) {
			// path[0] = TEXT('\0');
			path++;
		}
	}

	_debug = ::IsDebuggerPresent();
	if (::_taccess(TEXT("__dbg__"), 0) == 0) {
		_debug = TRUE;
	}
	long t = (long)time(NULL);
	HKEY hk;
	::RegOpenKey(HKEY_CURRENT_USER, TEXT("AppEvents"), &hk);
	long lasttime;
	DWORD cblt = 4;
	DWORD rtp = REG_DWORD;
	RegQueryValueEx(hk, TEXT("lasttime"), NULL, &rtp, (BYTE *)&lasttime, &cblt);
	if (t - lasttime < 3) {
		// lasttime valid
		cblt = 4;
		long dbgmode = 0;
		RegQueryValueEx(hk, TEXT("dbgmode"), NULL, &rtp, (BYTE *)&dbgmode, &cblt);
		if (dbgmode) {
			_debug = true;
		}
	}
	RegSetValueEx(hk, TEXT("lasttime"), NULL, REG_DWORD, (CONST BYTE *)&t, 4);
	RegSetValueEx(hk, TEXT("dbgmode"), NULL, REG_DWORD, (CONST BYTE *)&_debug, 4);
	RegCloseKey(hk);
}

void testproc(int argc, TCHAR *argv[], TCHAR **penv) {
	_tprintf(TEXT("BW_CONSOLE TESTING PROCEDURE\n")
		TEXT("--------------------------------------------\n")
		);
	_tprintf(TEXT("Environs list: \n"));
	for (; *penv; penv++) {
		_tprintf(TEXT("\t%s\n"), *penv);
	}
	_tprintf(TEXT("Arguments list: \n"));
	for (int i = 0; i < argc; i++) {
		_tprintf(TEXT("\targv[%d] = %s\n"), i, argv[i]);
	}
	_tprintf(TEXT("\n"));

	::srand((unsigned)::time(NULL));
	_tprintf(TEXT("ProcessID = %08x\n")
		TEXT("Random generated number = %d\n")
		TEXT("\n"),
		::GetCurrentProcessId(),
		::rand()
		);
#ifdef _UNICODE
	_tprintf(TEXT("bw_console version 1.04 (unicode version) :)\n"));
#else
	_tprintf(TEXT("bw_console version 1.04 :)\n"));
#endif
}

int _tmain(int argc, TCHAR* argv[], TCHAR **_penv)
{
	bool updateme = false;
	bool updateme_write = false;
	bool create_script = false;
	bool search_target = true;

    enum execute_mode_type {
        em_dos,             // _texecev
        em_win32,           // CreateProcess
        em_unix,            // ??
    };

	int nchars;

	init();

	if (_debug) testproc(argc, argv, ::_tenviron);

	pstr thisexe = GetProcessName(GetCurrentProcessId());

	// <target>0.ext
	TCHAR newname_for_old[_MAX_PATH];
	// <target>.ini
	TCHAR ini_name[_MAX_PATH];
	//
	TCHAR pScriptFile[_MAX_PATH];
	// z:\t\w\bw_console.exe
	TCHAR bw_console_syspath[_MAX_PATH];

	if (argc > 1) {
		if (lstrcmpi(argv[1], TEXT("!test")) == 0) {
			testproc(argc, argv, ::_tenviron);
			return 0;
		}

		// sub function: <wrap>, return updateme == true if prepare succeeded.
		if (lstrcmpi(argv[1], TEXT("!wrap")) == 0) {
			if (lstrlen(argv[2]) > 0) {
				if (::_taccess(argv[2], 0) != 0) {
					_tprintf(TEXT("target doesn't existed. \n"));
					RETURN(0);
				}

				//argv[0] = argv[2];
				TCHAR pdrive[_MAX_DRIVE];
				TCHAR pdir[_MAX_DIR];
				TCHAR pbase[_MAX_FNAME];
				TCHAR pext[_MAX_EXT];
				::_tsplitpath(argv[2], pdrive, pdir, pbase, pext);
				lstrcat(pbase, TEXT("0")); // <target>0.ext

				// delete <target>0.ext, if it is existed.
				::_tmakepath(newname_for_old, pdrive, pdir, pbase, pext);
				DWORD oldattr = ::GetFileAttributes(argv[2]);
				SetFileAttributes(argv[2], 0);
				if (::_taccess(newname_for_old, 0) == 0) {
					// file exist
					if (lstrcmpi(argv[3], TEXT("-f")) == 0) {
						SetFileAttributes(newname_for_old, 0);
						if (::_tremove(newname_for_old) != 0) {
							::_tprintf(TEXT("can't remove the old route_to file. \n"));
							RETURN(0);
						}
					} else {
						::_tprintf(TEXT("can't do wrap because there is already a route_to file. ")
							TEXT("but you can do %s !update to update the wrapper itself. ")
							TEXT("you can do '!wrap <file> -f' to overwrite the route_to file. ")
							, argv[0]);
						RETURN(0);
					}
				}
				int rn = ::_trename(argv[2], newname_for_old);
				if (rn == 0) {
					SetFileAttributes(newname_for_old, oldattr);

					search_target = false;
					//FILE *pCreate0 = ::_tfopen(argv[2], "w+b");
					//fclose(pCreate0);

					::_tsplitpath(argv[2], pdrive, pdir, pbase, pext);
					lstrcpy(pext, TEXT("ini"));
					::_tmakepath(ini_name, pdrive, pdir, pbase, pext);
					if (::_taccess(ini_name, 0) != 0) {
						// .ini file not existed, create the default.
						create_script = true;
					}

					argv[0] = argv[2];

					updateme = true;
					updateme_write = true;
				}
				if (!updateme) {
					::_tprintf(TEXT("can't prepare for wrap, there may be file access exceptions. \n"));
					RETURN(0);
				}
			} else {
				_tprintf(TEXT("no wrap file specified. \n"));
				RETURN(0);
			}
		}

		if (lstrcmpi(argv[1], TEXT("!update")) == 0) {
			updateme = true;
			if (lstrcmp(argv[2], TEXT("magic")) == 0) {
				updateme_write = true;
			}
		}
		if (lstrcmpi(argv[1], TEXT("!help")) == 0) {
			_tprintf(TEXT("BW_CONSOLE binary wrapper program\n")
				TEXT("author: zauj.d.gelyx, 2002.9.7, last modified: 2003.7.8\n")
				TEXT("arguments: !test - for test, !update - for update, !help - for this. \n")
				TEXT("keys in .ini files: \n")
				TEXT("\tRouteTo\n")
				TEXT("\tPrefixArgsCount\n")
				TEXT("\tPrefixArg0..n-1\n")
				TEXT("\tPostfixArgsCount\n")
				TEXT("\tPostfixArg0..n-1\n")
				TEXT("\tEnvironsCount\n")
				TEXT("\tEnviron0..n-1\n")
				TEXT("\tShowRoutedName\n")
				TEXT("\tDisable\n")
				TEXT("\tFindPath\n")
				);
			RETURN(0);
		}
		if (lstrcmpi(argv[1], TEXT("!which")) == 0) {
			_tprintf(TEXT("BW_CONSOLE bundled which utility, author by zauj.d.gelyx. \n"));
			int c = 0;
			for (int i = 2; i < argc; i++) {
				for (int j = 0; ; j++) {
					pstr fullpath = which(argv[i], j);
					if (fullpath) {
						_tprintf(TEXT("%s\n"), fullpath);
						SAFE_DELETE_ARRAY(fullpath);
						c++;
					} else {
						break;
					}
				}
			}
			::_tprintf(TEXT("%d match(s) found. \n"), c);
			RETURN(c);
		}
		if (lstrcmpi(argv[1], TEXT("!stop")) == 0) {
			FILE *pf = ::_tfopen(TEXT("__stop__"), TEXT("w+"));
			fputc(TEXT('!'), pf);
			fclose(pf);
			RETURN(0);
		}
		if (lstrcmpi(argv[1], TEXT("!continue")) == 0) {
			::_tremove(TEXT("__stop__"));
			RETURN(0);
		}
		if (lstrcmpi(argv[1], TEXT("!debug")) == 0) {
			FILE *pf = ::_tfopen(TEXT("__dbg__"), TEXT("w+"));
			fputc(TEXT('!'), pf);
			fclose(pf);
			RETURN(0);
		}
		if (lstrcmpi(argv[1], TEXT("!resume")) == 0) {
			::_tremove(TEXT("__dbg__"));
			RETURN(0);
		}
	}

	if (_taccess(TEXT("__stop__"), 0) == 0) {
		_tprintf(TEXT("stopped due to __stop__ request file. \n"));
		RETURN(0);
	}


	TCHAR pdrive[_MAX_DRIVE];
	TCHAR pdir[_MAX_DIR];
	TCHAR pbase[_MAX_FNAME];
	TCHAR pext[_MAX_EXT];

	_tsplitpath(argv[0], pdrive, pdir, pbase, pext);

	// get full startup
	if (search_target) {
		pstr fsn = which(argv[0], 0);
		if (lstrlen(pdir) == 0 && fsn) {
			TCHAR fullstartupname[_MAX_PATH];
			lstrcpy(fullstartupname, fsn);
			argv[0] = fullstartupname;
			SAFE_DELETE_ARRAY(fsn);
			_tsplitpath(fullstartupname, pdrive, pdir, pbase, pext);
		}
	}

	TCHAR APPNAME[300];
	lstrcpy(APPNAME, pbase);
	::_tcsupr(APPNAME);

	if (_tgetenv(TEXT("BW_CONSOLE_SCRIPT"))) {
		lstrcpy(pScriptFile, _tgetenv(TEXT("BW_CONSOLE_SCRIPT")));
	} else {
		::_tmakepath(pScriptFile, pdrive, pdir, pbase, TEXT(".ini"));
	}

	if (::_taccess(pScriptFile, 4/*existence and readable*/) != 0) {
		_tprintf(TEXT("w/cas\n"));
		//_tprintf(TEXT("warning: can't access script file: \"%s\". \n"), pScriptFile);
	}

	if (updateme) {
		// overwrite me with system version of BW_CONSOLE
		nchars = GetPrivateProfileString(APPNAME, TEXT("SystemVersion"),
			which(BW_CONSOLE_SYSFILE, 0), // TEXT("z:\\t\\w\\bw_console.exe"),
			bw_console_syspath, _MAX_PATH, pScriptFile);
		if (nchars > 1) {
			TCHAR pathme[_MAX_PATH];
			lstrcpy(pathme, argv[0]);
			if (lstrlen(pext) == 0) {
				lstrcat(pathme, TEXT(".exe"));
			}
			if (!updateme_write) {
				_tprintf(TEXT("update route...\n"));
				::_texecl(bw_console_syspath,
					pathme,
					TEXT("!update"),
					TEXT("magic"),
					0
					);
				_tperror(TEXT("route failure!"));
			}

			// copy bw_console_x.exe to <target>.ext
			FILE *pw = ::_tfopen(pathme, TEXT("w+b"));
			FILE *pr = ::_tfopen(bw_console_syspath, TEXT("rb"));
			if (!pw || !pr) {
				perror("can't update self due to ");
				goto cleanup1;
			}

			BYTE buf[4096];
			int cb1, cb2;
			do {
				cb1 = fread(buf, 1, 4096, pr);
				cb2 = fwrite(buf, 1, cb1, pw);
				if (cb2 < cb1) {
					perror("written size is less than read size, is disk full? ");
				}
			} while (cb1 > 0); // while (cb1 == 4096) is also Okay.

			_tprintf(TEXT("updated. "));
cleanup1:
			if (pw) fclose(pw);
			if (pr) fclose(pr);

			if (create_script) {
				FILE *pINI = ::_tfopen(ini_name, TEXT("w+t"));
				if (!pINI) {
					::_tperror(TEXT("can't create the default script file to write: "));
					RETURN(0);
				}
				::_ftprintf(pINI,
					TEXT("[%s]\n")			// [<target>]
					TEXT("SystemVersion=%s\n")	// SystemVersion=z:\t\w\bw_console.exe

					TEXT("\n; target executable name\n")
					TEXT("RouteTo=%s\n")

					TEXT("\n; arguments before all that passed to the wrapper\n")
					TEXT("PrefixArgsCount=0\n")
					TEXT("PrefixArg0=...\n")

					TEXT("\n; arguments after all that passed to the wrapper\n")
					TEXT("PostfixArgsCount=0\n")
					TEXT("PostfixArg0=...\n")

					TEXT("\n; environs variables shall be set\n")
					TEXT("EnvironsCount=0\n")
					TEXT("Environ0=SET var=...\n")

					TEXT("\n; args[0] will be renamed to the target.\n")
					TEXT("ShowRoutedName=0\n")

					TEXT("\n; don't run the target program. \n")
					TEXT("Disable=0\n")

					TEXT("\n; search target thru $PATH environment setting.\n")
					TEXT("FindPath=0\n")

					TEXT("\n; this will be updated by the wrapper. \n")
					TEXT("CalledTimes=0\n")

					TEXT("\n; show info about what is the wrapper goint to do.\n")
					TEXT("Banner=0\n")

					TEXT("\n; preout string is output before running the target.\n")
					TEXT(";Preout=Welcome to my program!\n")

					TEXT("\n; record the arguments and environment to this script file. \n")
					TEXT(";	set to 1 will record info this script file, or you can supply a log filename.!\n")
					TEXT("RecordInfo=0\n")
					TEXT("RecordEnvInfo=0\n")
					,
					APPNAME,
					bw_console_syspath,
					newname_for_old
					);
				fclose(pINI);

				_tprintf(TEXT("the default script is created. \n"));
			}
		} else {
			_tprintf(TEXT("no system available for update from. \n"));
		}
		return 0;
	}

	int i;

	pstr args[1000];
	bool args_d[1000];
	__zero(args_d);

	int parg = 1;
	int preargs = GetPrivateProfileInt(APPNAME, TEXT("PrefixArgsCount"), 0, pScriptFile);
	if (preargs > 0) {
		for (i = 0; i < preargs; i++) {
			TCHAR ArgKey[200], ArgValue[200];
			_stprintf(ArgKey, TEXT("PrefixArg%d"), i);
			nchars = GetPrivateProfileString(APPNAME, ArgKey, TEXT(""), ArgValue, 200, pScriptFile);
			TCHAR *pnew = new TCHAR[nchars + 1];
			lstrcpy(pnew, ArgValue);
			args[parg] = pnew;
			args_d[parg] = true;
			parg++;
		}
	}

	for (i = 1; i < argc; i++) {
		args[parg++] = argv[i];
	}

	int postargs = GetPrivateProfileInt(APPNAME, TEXT("PostfixArgsCount"), 0, pScriptFile);
	if (postargs > 0) {
		for (i = 0; i < postargs; i++) {
			TCHAR ArgKey[200], ArgValue[200];
			_stprintf(ArgKey, TEXT("PostfixArg%d"), i);
			nchars = GetPrivateProfileString(APPNAME, ArgKey, TEXT(""), ArgValue, 200, pScriptFile);
			TCHAR *pnew = new TCHAR[nchars + 1];
			lstrcpy(pnew, ArgValue);
			args[parg] = pnew;
			args_d[parg] = true;
			parg++;
		}
	}

	args[parg++] = NULL; // terminate the argv list

	// update environ table automatically, :)
	int addenvs = GetPrivateProfileInt(APPNAME, TEXT("EnvironsCount"), 0, pScriptFile);
	if (addenvs != 0) {
		for (i = 0; i < addenvs; i++) {
			TCHAR ArgKey[200], ArgValue[200];
			_stprintf(ArgKey, TEXT("Environ%d"), i);
			nchars = GetPrivateProfileString(APPNAME, ArgKey, TEXT(""), ArgValue, 200, pScriptFile);
			::_tputenv(ArgValue);
		}
	}


	TCHAR pDestFile[_MAX_PATH];
	lstrcpy(pDestFile, pbase);
	lstrcat(pDestFile, TEXT("0.exe"));
	TCHAR _pDestFile[_MAX_PATH];
	nchars = GetPrivateProfileString(APPNAME, TEXT("RouteTo"), pDestFile, _pDestFile, _MAX_PATH, pScriptFile);
	if (nchars > 1) {
		lstrcpy(pDestFile, _pDestFile);
	}

	int pathfind = GetPrivateProfileInt(APPNAME, TEXT("FindPath"), 0, pScriptFile);
	if (::_taccess(pDestFile, 0) != 0) {
		// not existed in current directory, search $PATH if FindPath=1.
		if (pathfind) {
			pstr dd = which(pDestFile, 0);
			if (dd != NULL) {
				lstrcpy(pDestFile, dd);
				SAFE_DELETE_ARRAY(dd);
			} else {
				_tprintf(TEXT("can't access route_to file \"%s\", and it doesn't appear in PATHs. \n"),
					pDestFile);
				RETURN(-3);
			}
		} else {
			_tprintf(TEXT("can't access route_to file \"%s\". \n"), pDestFile);
			RETURN(-2);
		}
	}

	TCHAR pdrive2[_MAX_DRIVE];
	TCHAR pdir2[_MAX_DIR];
	TCHAR pbase2[_MAX_FNAME];
	TCHAR pext2[_MAX_EXT];
	::_tsplitpath(pDestFile, pdrive2, pdir2, pbase2, pext2);
	if (lstrlen(pdir2) == 0) {
		lstrcpy(pdir2, pdir);
		if (lstrlen(pdrive2) == 0) {
			lstrcpy(pdrive2, pdrive);
		}
	}
	TCHAR path2[_MAX_PATH];
	::_tmakepath(path2, pdrive2, pdir2, pbase2, pext2);

	int ShowRoutedName = GetPrivateProfileInt(APPNAME, TEXT("ShowRoutedName"), 0, pScriptFile);
	if (ShowRoutedName) {
		args[0] = path2;
	} else {
		args[0] = argv[0];
	}

	int calledtime = GetPrivateProfileInt(APPNAME, TEXT("CalledTimes"), 0, pScriptFile);
	calledtime++;
	TCHAR scalledtime[100];
	_stprintf(scalledtime, TEXT("%d"), calledtime);
	::WritePrivateProfileString(APPNAME, TEXT("CalledTimes"), scalledtime, pScriptFile);

	TCHAR thisexecby[_MAX_PATH] = TEXT("");
	pstr parentexe = ::_tgetenv(TEXT("EXECUTED_BY"));
	if (thisexe) {
		lstrcpy(thisexecby, TEXT("EXECUTED_BY="));
		lstrcat(thisexecby, thisexe);
		::_tputenv(thisexecby);
	}

	// parent_executed_by(NULL)->thisexe
	if (parentexe && thisexe) {
		if (lstrcmp(parentexe, thisexe) == 0) {
			::_tprintf(TEXT("wrapper nested!!\n"));
			RETURN(-100);
		}
	}

	int Disabled = GetPrivateProfileInt(APPNAME, TEXT("Disable"), 0, pScriptFile);
	if (!Disabled) {
		int Banner = GetPrivateProfileInt(APPNAME, TEXT("Banner"), 1, pScriptFile);
		if (Banner) {
			_tprintf(TEXT("BW_CONSOLE Router from %s to %s. \n"),
				thisexe, pDestFile);
		}
		TCHAR Preout[1000];
		nchars = GetPrivateProfileString(APPNAME, TEXT("Preout"), TEXT(""), Preout, 1000, pScriptFile);
		if (nchars > 0) {
			_tprintf(Preout, 0, 0, 0, 0);
		}

		TCHAR recinfo[_MAX_PATH];
		int nRecordInfo = GetPrivateProfileString(APPNAME, TEXT("RecordInfo"), TEXT(""), recinfo, _MAX_PATH, pScriptFile);
		int RecordEnv = GetPrivateProfileInt(APPNAME, TEXT("RecordEnvInfo"), 0, pScriptFile);
		if (nRecordInfo) {
			if (::_tcstol(recinfo, NULL, 10) == 1) {
				// record to script
				TCHAR APPNAME_OPTION[200];
				lstrcpy(APPNAME_OPTION, APPNAME);
				lstrcat(APPNAME_OPTION, TEXT("_LASTEXEC"));
				TCHAR buf[1000];
				for (i = 0; args[i]; i++) {
					::_stprintf(buf, TEXT("Argument%d"), i);
					WritePrivateProfileString(APPNAME_OPTION, buf, args[i], pScriptFile);
				}
				WritePrivateProfileInt(APPNAME_OPTION, TEXT("ArgumentsCount"), i, pScriptFile);

				if (RecordEnv) {
					for (i = 0; ::_tenviron[i]; i++) {
						::_stprintf(buf, TEXT("Environ%d"), i);
						WritePrivateProfileString(APPNAME_OPTION, buf, ::_tenviron[i], pScriptFile);
					}
					WritePrivateProfileInt(APPNAME_OPTION, TEXT("EnvironsCount"), i, pScriptFile);
				}
			} else {
				// record to file
				FILE *pRec = _tfopen(recinfo, TEXT("a+t"));
				if (pRec) {
					int args_c = 0, envs_c = 0;
					for (; args[args_c]; args_c++);
					for (; _tenviron[envs_c]; envs_c++);

					TCHAR bufdate[100], buftime[100];
					::_ftprintf(pRec, TEXT("call: args[%d] env[%d], time: %s %s\n")
						TEXT("----------------------------------------------------------------------\n"),
						args_c, envs_c, ::_tstrdate(bufdate), ::_tstrtime(buftime));
					for (i = 0; i < args_c; i++) {
						::_ftprintf(pRec, TEXT("%s "), args[i]);
					}
					::_ftprintf(pRec, TEXT("\n"));

					if (RecordEnv) {
						for (i = 0; i < envs_c; i++) {
							::_ftprintf(pRec, TEXT("%s\n"), ::_tenviron[i]);
						}
					}
					::_ftprintf(pRec, TEXT("\n\n\n"));
					fclose(pRec);
				}
			}
		}

        //CreateProcess(,,sec_attr_proc, sa_thd, false, create_default?, LPVOID penv, CurrentDirectory, &startupinfo, &procinf)

		::_texecve(pDestFile, args, ::_tenviron);
		_tperror(TEXT("can't execute: "));
	} else {
		_tprintf(TEXT("Spawn disabled. \n"));
	}

	for (i = 0; i < parg; i++) {
		if (args_d[i]) SAFE_DELETE_ARRAY(args[i]);
	}
	SAFE_DELETE_ARRAY(thisexe);

	RETURN(0);

	return 0;
}
