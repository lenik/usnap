// dllframe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "dllframe.h"
using namespace std;
#include "pe_ana.h"
using namespace pos;
#include "pefix_forward.h"


char *g_szDllname	= NULL;
char *g_szDllfix	= NULL;
char *g_szFramehdr	= NULL;
char *g_szFrameimp	= NULL;
char *g_szFramedef	= NULL;

static char **_szFilenames[] = { &g_szDllname, &g_szFramehdr, &g_szFrameimp, &g_szFramedef };
static char *_szExtnames[] = { "dll", "h", "c", "def" };


void set_ext_name(char *filename, char *extname, bool setanyway) {
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char file[_MAX_FNAME];
	char ext[_MAX_EXT];
	::_splitpath(filename, drive, dir, file, ext);

	if (strlen(ext) > 0 && !setanyway) return;

	strcpy(ext, extname);
	::_makepath(filename, drive, dir, file, ext);
}

char *base_name(char *filename, char *buf) {
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char file[_MAX_FNAME];
	char ext[_MAX_EXT];
	::_splitpath(filename, drive, dir, file, ext);
	if (buf) {
		::_makepath(buf, NULL, NULL, file, NULL);
		return buf;
	}
	char _buf[256];
	::_makepath(_buf, NULL, NULL, file, NULL);
	return strdup(_buf);
}

int main(int argc, char* argv[])
{
	cerr	<< "DLL-Frame analyse & generate		author/zauj.g.d. 2003.5.18\n"
		<< "(C)Copyright CVI.Kernels, 2003		mail to: jljljjl@yahoo.com\n"
		;

	bool bDebug = false;
	if (strcmp(argv[1], "-x") == 0) {
		bDebug = true;
		argc--;
		argv++;
	}

	if (argc < 2) {
		cerr	<< "syntax:\n"
			<< "	dllframe [-x] dll-file [dll-fix.dll|framehdr.h [frameimp.c [framedef.def]]]\n"
			<< "\n"
			<< "	-x: display detail informatio.\n"
			<< "	don't miss 'dll-fix.dll' (.ext must be dll) if u want to fix a wrapper dll.\n"
			<< "	'framehdr.h' will be 'dllname.h' if u miss it.\n"
			<< "	'frameimp.c' will be 'framehdr.c' if u miss it.\n"
			<< "	'framedef.def' will be 'frameimp.def' if u miss it.\n"
			;
		return -1;
	}

	for (int iarg = 1; iarg <= 4; iarg++) {
		if (iarg < argc) {
			bool bUseFix = false;
			if (iarg == 2) {
				if (strcmpi("dll", argv[2] + strlen(argv[2]) - 3) == 0) {
					bUseFix = true;
				}
			}
			if (bUseFix) {
				g_szDllfix = strdup(argv[iarg]);
				break;
			} else {
				*(_szFilenames[iarg - 1]) = strdup(argv[iarg]);
				set_ext_name(*(_szFilenames[iarg - 1]), _szExtnames[iarg - 1], false);
			}
		} else {
			*(_szFilenames[iarg - 1]) = strdup(*(_szFilenames[iarg - 2]));
			set_ext_name(*(_szFilenames[iarg - 1]), _szExtnames[iarg - 1], true);
		}
	}

	if (g_szDllfix) {
		cerr	<< "dll-name:	" << g_szDllname << "\n"
			<< "fix-name:	" << g_szDllfix << "\n"
			;
	} else {
		cerr	<< "dll-name:	" << g_szDllname << "\n"
			<< "framehdr:	" << g_szFramehdr << "\n"
			<< "frameimp:	" << g_szFrameimp << "\n"
			<< "framedef:	" << g_szFramedef << "\n"
			<< "\n"
			;
	}

	/*
	if (!DllValid(g_szDllname)) {
		cerr	<< g_szDllname << " isn't a valid PE-format DLL file. \n"
			<< "or it may not exist, or opened by another program. \n"
			;
		return -1;
	}
	*/

	error_t e;
	void *_image = NULL;
	u32_t size = 0;
	e = LoadFile(g_szDllname, &_image, &size);
	if (e.bFailure) {
		cerr	<< "can't load " << g_szDllname << ". error: " << (void *)(e.hdr) << "\n"
			;
		return -1;
	}

	PEFile *_pe = NULL;
	e = PE_Analyse(_image, size, &_pe);
	_pe->_name = base_name(g_szDllname);
	if (e.bFailure) {
		cerr	<< "parse " << g_szDllname << " error! (error: " << (void *)e.hdr << ")\n"
			;
		return -1;
	}

	if (bDebug) {
	//	DebugDump(_pe, g_szDllname);
	}

	if (g_szDllfix) {
		void *_image2 = NULL;
		u32_t size2 = 0;
		e = LoadFile(g_szDllfix, &_image2, &size2);
		if (e.bFailure) {
			cerr	<< "can't load " << g_szDllfix << ". error: " << (void *)e.hdr << "\n"
				;
			return -1;
		}

		PEFile *_pe2 = NULL;
		e = PE_Analyse(_image2, size2, &_pe2);
		_pe2->_name = base_name(g_szDllfix);
		if (e.bFailure) {
			cerr	<< "parse " << g_szDllfix << " error! (error: " << (void *)e.hdr << ")\n"
				;
			return -1;
		}

		cout	<< "\n\n------------------------- before fixed: ----------------------------\n";
		DebugDump(_pe2, g_szDllfix);

		e = FixDll_ForwardMissing(_pe, _pe2);
		if (e.bFailure) {
			cerr	<< "fix dll (forward missing export functions) error! error: "
				<< (void *)e.hdr << "\n"
				;
			return -1;
		}

		cout	<< "\n\n------------------------- fixed: ----------------------------\n";
		DebugDump(_pe2, g_szDllfix);

		//e = WritePEFile(g_szDllfix, _pe2);
		if (e.bFailure) {
			cerr	<< "can't write file " << g_szDllfix << ", error: " << (void *)e.hdr << "\n"
				;
			return -1;
		}
	} else {
		e = GenerateFrame(_pe);
		if (e.bFailure) {
			cerr	<< "can't generate files. error: " << (void *)e.hdr << "\n"
				;
			return -1;
		}
	}

	//ClearUp ...

	return 0;
}



error_t LoadFile(LPCSTR pszFilename, void **ppv, u32_t *psize) {
	HANDLE hFile = NULL;
	DWORD dwLow = 0, dwHigh = 0;
	error_t e;
	e.hdr = 0;
	e.bFailure = true;
	e._detail = NULL;

	if (!ppv || !psize) {
		e.type = err_pointer;
		return e;
	}
	hFile = ::CreateFile(pszFilename, GENERIC_READ, FILE_SHARE_READ,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		e.type = err_resource;
		return e;
	}

	dwLow = ::GetFileSize(hFile, &dwHigh);

	void *pBuf = NULL;
	if (dwHigh != 0) {
		e.type = err_unexpected;
		CloseHandle(hFile);
		return e;		// too large
	}

	pBuf = new BYTE[dwLow];
	if (!pBuf) {
		CloseHandle(hFile);
		e.type = err_res_memory;
		return e;		// memory out.
	}

	DWORD cbRead = 0;
	BOOL b;
	b = ReadFile(hFile, pBuf, dwLow, &cbRead, NULL);
	CloseHandle(hFile);

	if (!b || cbRead != dwLow) {
		delete pBuf;
		e.type = err_resource;
		return e;		// read error.
	}

	*ppv = pBuf;
	*psize = (u32_t)dwLow;
	e.bFailure = false;
	return e;
};


inline void *revdw(DWORD dw) {
	return (void *)((dw << 24)
		| ((dw & 0x0000FF00) << 8)
		| ((dw & 0x00FF0000) >> 8)
		| (dw >> 24))
		;
}

void DebugDump(PEFile *_arch, asz_t _name) {
	cout	<< "detail info : " << _name << "\n"
		<< "================================================================\n"
		;
	DumpExports(_arch);
	DumpImports(_arch);
}

void DumpExports(PEFile *_arch) {
	Data_Export *exp = _arch->_Datas->_Export;

	cout	<< "Library: " << exp->_dll_name << "\n"
		<< "----------------------------------------------------------------\n"
		;

	int i, n;
	int base = exp->_file->Base;

	n = exp->_file->NumberOfFunctions;
	int null_slots = 0;
	for (i = 0; i < n; i++) {
		Data_Export::_ITEM& _body = exp->_funcs[i];
		if (_body._forward) {
			cout	<< "	#" << base + i << "	--> " << _body._forward << "\n";
		} else {
			u32_t *_b = (u32_t *)_body._func_body;
			u32_t _rva = (u32_t)_b - (u32_t)_arch->_image;
			if (!_rva) {
				null_slots++;
				continue;
			}
			cout	<< "	#" << base + i << "	offset: " << (void *)_rva
				<< "	data: " << revdw(_b[0]) << revdw(_b[1]) << revdw(_b[2]) << "...\n";
				;
		}
	}

	n = exp->_file->NumberOfNames;
	for (i = 0; i < n; i++) {
		cout	<<  "	#" << (int)exp->_names[i].ordinal << " - " << exp->_names[i].name << "\n"
			;
	}

	cout	<< "--- empty: " << null_slots << " ---\n\n";
}

void DumpImports(PEFile *_arch) {
	Data_Import *imp = _arch->_Datas->_Import;

	int nLibs = 0;
	int nTotalImports = 0;
	Data_Import::LIBITEMS *p = imp->_libs;

	while (p) {
		Data_Import::LIBITEM *_lib = p->data;

		cout	<< "\n	Imports from " << _lib->_name << ", total " << (int)_lib->_imports << " imports. " << "\n"
			<< "	----------------------------------------------------------------\n"
			;

		for (int i = 0; i < _lib->_imports; i++) {
			Data_Import::IMPITEM& imp = _lib->_items[i];

			cout	<< "	";
			if (imp.bByBound) {
				cout	<< "	[" << (void *)imp._bound_addr << "] ";
			} else {
				cout	<< "           ";
			}

			if (imp.bByOrd) cout << "#" << (int)imp._ord;
			else cout << imp._name << "	[" << (int)imp._name_hint << "]";

			if (imp.bForward) {
				cout	<< "	--> ";
				if (imp.bForwardByOrd) cout << "#" << (int)imp._fwd_ord;
				else cout << imp._fwd_libname << "::" << imp._fwd_name;
			}

			// if (imp.bByBound) if (imp._fwd_timestamp != 0)
			cout	<< "\n";
		}
		p = p->l;
	}
}


error_t GenerateFrame(PEFile *_arch) {
	error_t e;
	__zero(e);
	e.bFailure = true;

	//
	return e;
}

error_t WritePEFile(pos::asz_t g_szDllfix, PEFile *_pe) {
	error_t e;
	__zero(e);
	e.bFailure = true;

	HANDLE hFile;
	DWORD cb;
	DWORD cbWritten;
	BOOL b;

	hFile = CreateFile(g_szDllfix, GENERIC_WRITE, 0/*FILE_SHARE_EXCLUSIVE*/,
		NULL, TRUNCATE_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		e.type = err_resource;
		return e;
	}

	cb = _pe->_hdr_DOS->_file->e_lfanew;
	b = WriteFile(hFile, _pe->_hdr_DOS->_file, cb, &cbWritten, NULL);
	// cbWritten == cb		// sizeof(DOS_Header::_FILE)

	b = WriteFile(hFile, _pe->_hdr_PE->_file, sizeof(PE_Header::_FILE), &cbWritten, NULL);
	// cbWritten == sizeof(PE_Header::_FILE)

	b = WriteFile(hFile, _pe->_hdr_Opt->_file, sizeof(Opt_Header::_FILE), &cbWritten, NULL);
	// cbWritten == sizeof(Opt_Header::_FILE)

	b = WriteFile(hFile, _pe->_Datas->_file, sizeof(Datas::_FILE), &cbWritten, NULL);
	// cbWritten == sizeof(Datas::_FILE)

	// sections header.
	Sections *p = _pe->_Sections;
	Section *_s;
	while (p) {
		_s = p->data;

		b = WriteFile(hFile, _s->_file, sizeof(Section::_FILE), &cbWritten, NULL);
		// cbWwritten == sizeof(Section::_FILE)

		p = p->l;
	}

	// write data with alignment.
	p = _pe->_Sections;
	while (p) {
		_s = p->data;
		// alignment...

		b = WriteFile(hFile, _s->_raw, _s->_file->SizeOfRawData, &cbWritten, NULL);

		p = p->l;
	}

	b = CloseHandle(hFile);
	e.bFailure = false;
	return e;
}
