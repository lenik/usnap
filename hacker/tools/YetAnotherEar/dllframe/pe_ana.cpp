
#include "stdafx.h"

#include "pe.h"
#include <pos/error.h>
using namespace pos;


void *rva_addr(u32_t rva, PEFile *_arch) {
	Section *_s;
	Sections *p = _arch->_Sections;
	if (rva < _arch->_hdr_Opt->_file->SizeOfHeaders) {
		return (pb_t)_arch->_image + rva;
	}
	while (p) {
		_s = p->data;
		if (rva >= _s->_file->VirtualAddress &&
			rva < _s->_file->VirtualAddress + _s->_file->VirtualSize) {
			return (pb_t)_s->_raw + rva - _s->_file->VirtualAddress;
		}
		p = p->l;
	}
	return NULL;
}

u32_t addr_rva(void *_addr, PEFile *_arch) {
	u32_t image_off = (u32_t)_addr - (u32_t)_arch->_image;
	if (image_off < _arch->_hdr_Opt->_file->SizeOfHeaders) {
		return image_off;
	}
	Sections *p = _arch->_Sections;
	Section *_s;
	while (p) {
		_s = p->data;
		if (image_off >= _s->_file->PointerToRawData &&
			image_off < _s->_file->PointerToRawData + _s->_file->SizeOfRawData) {
			return _s->_file->VirtualAddress +
				image_off - _s->_file->PointerToRawData;
		}
		p = p->l;
	}
	return (u32_t)-1;
}

error_t PE_Analyse(void *pv, u32_t len, PEFile **ppPEArch) {
	error_t e;
	__zero(e);
	e.bFailure = true;

	if (!pv || !ppPEArch) {
		e.type = err_pointer;
		return e;
	}
	if (len < sizeof(::DOS_Header) + sizeof(::PE_Header) + sizeof(::Opt_Header)) {
		e.type = err_verify_pre;
		return e;
	}

	PEFile *_a = NULL;
	if ((
		(_a = new PEFile)
		&& (_a->_hdr_DOS = new DOS_Header)
		&& (_a->_hdr_PE = new PE_Header)
		&& (_a->_hdr_Opt = new Opt_Header)
		&& (_a->_Datas = new Datas)
		)) {
		_a->_image = pv;
		__zero(*_a->_hdr_DOS);
		__zero(*_a->_hdr_PE);
		__zero(*_a->_hdr_Opt);
		__zero(*_a->_Datas);
	} else {
		e.type = err_res_memory;
		return e;
	}

	// begin translate.
	pb_t _raw = (pb_t)pv;

	_a->_hdr_DOS->_file = (DOS_Header::_FILE *)_raw;
	// assert _a->_hdr_DOS->_file->e_magic=="MZ"

	_a->_hdr_PE->_file = (PE_Header::_FILE *)(_raw + _a->_hdr_DOS->_file->e_lfanew);
	// assert _a->_hdr_PE->_file->Signature == "PE\0\0"

	_a->_hdr_PE->dwChars = _a->_hdr_PE->_file->Characteristics;

	_a->_hdr_Opt->_file = (Opt_Header::_FILE *)((pb_t)_a->_hdr_PE->_file + sizeof(PE_Header::_FILE));
	// assert _a->_hdr_Opt->_file->Magic == 0x10b

	_a->_Datas->_file = (Datas::_FILE *)((pb_t)_a->_hdr_Opt->_file + sizeof(Opt_Header::_FILE));

	// sections
	{
		int nSects = _a->_hdr_PE->_file->NumberOfSections;
		Section::_FILE *_sects = (Section::_FILE *)((pb_t)_a->_Datas->_file + 0x80);
		Sections *_p = new Sections;
		_a->_Sections = _p;
		_p->_l = NULL;
		for (int iSect = 0; iSect < nSects; iSect++) {
			if (iSect > 0) {
				_p->l = new Sections;
				_p->l->_l = _p;
				_p = _p->l;
			}
			Section *_s = new Section;
			__zero(*_s);
			_s->_file = _sects + iSect;
			_s->_raw = _raw + _s->_file->PointerToRawData;
			_s->_name = new a_t[9];
			strncpy(_s->_name, (asz_ct)(_s->_file->Name), 8);
			_p->data = _s;
		}
		_p->l = NULL;	// terminate.
	}

	// data directories
	if (_a->_Datas->_file->DataDirectory[0].VirtualAddress) {			// Data_Export
		_a->_Datas->_Export = new Data_Export;
		__zero(*_a->_Datas->_Export);
		_a->_Datas->_Export->_file = (Data_Export::_FILE *)(
			rva_addr(_a->_Datas->_file->DataDirectory[0].VirtualAddress, _a));
		_a->_Datas->_Export->_length = _a->_Datas->_file->DataDirectory[0].Size;
	}
	if (_a->_Datas->_file->DataDirectory[1].VirtualAddress) {			// Data_Import
		_a->_Datas->_Import = new Data_Import;
		__zero(*_a->_Datas->_Import);
		_a->_Datas->_Import->_file = (Data_Import::_FILE *)(
			rva_addr(_a->_Datas->_file->DataDirectory[1].VirtualAddress, _a));
		_a->_Datas->_Import->_length = _a->_Datas->_file->DataDirectory[1].Size;
	}
	if (_a->_Datas->_file->DataDirectory[2].VirtualAddress) {			// Data_Resource
		_a->_Datas->_Resource = new Data_Resource;
		__zero(*_a->_Datas->_Resource);
		_a->_Datas->_Resource->_file = (Data_Resource::_FILE *)(
			rva_addr(_a->_Datas->_file->DataDirectory[2].VirtualAddress, _a));
		_a->_Datas->_Resource->_length = _a->_Datas->_file->DataDirectory[2].Size;
	}
	if (_a->_Datas->_file->DataDirectory[3].VirtualAddress) {			// Data_Exception
		_a->_Datas->_Exception = new Data_Exception;
		__zero(*_a->_Datas->_Exception);
		_a->_Datas->_Exception->_file = (Data_Exception::_FILE *)(
			rva_addr(_a->_Datas->_file->DataDirectory[3].VirtualAddress, _a));
		_a->_Datas->_Exception->_length = _a->_Datas->_file->DataDirectory[3].Size;
	}
	if (_a->_Datas->_file->DataDirectory[4].VirtualAddress) {			// Data_Security
		_a->_Datas->_Security = new Data_Security;
		__zero(*_a->_Datas->_Security);
		_a->_Datas->_Security->_file = (Data_Security::_FILE *)(
			rva_addr(_a->_Datas->_file->DataDirectory[4].VirtualAddress, _a));
		_a->_Datas->_Security->_length = _a->_Datas->_file->DataDirectory[4].Size;
	}
	if (_a->_Datas->_file->DataDirectory[5].VirtualAddress) {			// Data_BaseReloc
		_a->_Datas->_BaseReloc = new Data_BaseReloc;
		__zero(*_a->_Datas->_BaseReloc);
		_a->_Datas->_BaseReloc->_file = (Data_BaseReloc::_FILE *)(
			rva_addr(_a->_Datas->_file->DataDirectory[5].VirtualAddress, _a));
		_a->_Datas->_BaseReloc->_length = _a->_Datas->_file->DataDirectory[5].Size;
	}
	if (_a->_Datas->_file->DataDirectory[6].VirtualAddress) {			// Data_Debug
		_a->_Datas->_Debug = new Data_Debug;
		__zero(*_a->_Datas->_Debug);
		_a->_Datas->_Debug->_file = (Data_Debug::_FILE *)(
			rva_addr(_a->_Datas->_file->DataDirectory[6].VirtualAddress, _a));
		_a->_Datas->_Debug->_length = _a->_Datas->_file->DataDirectory[6].Size;
	}
	if (_a->_Datas->_file->DataDirectory[7].VirtualAddress) {			// Data_Copyright
		_a->_Datas->_Copyright = new Data_Copyright;
		__zero(*_a->_Datas->_Copyright);
		_a->_Datas->_Copyright->_file = (Data_Copyright::_FILE *)(
			rva_addr(_a->_Datas->_file->DataDirectory[7].VirtualAddress, _a));
		_a->_Datas->_Copyright->_length = _a->_Datas->_file->DataDirectory[7].Size;
	}
	if (_a->_Datas->_file->DataDirectory[8].VirtualAddress) {			// Data_GlobalPointer
		_a->_Datas->_GlobalPointer = new Data_GlobalPointer;
		__zero(*_a->_Datas->_GlobalPointer);
		_a->_Datas->_GlobalPointer->_file = (Data_GlobalPointer::_FILE *)(
			rva_addr(_a->_Datas->_file->DataDirectory[8].VirtualAddress, _a));
		_a->_Datas->_GlobalPointer->_length = _a->_Datas->_file->DataDirectory[8].Size;
	}
	if (_a->_Datas->_file->DataDirectory[9].VirtualAddress) {			// Data_TLS
		_a->_Datas->_TLS = new Data_TLS;
		__zero(*_a->_Datas->_TLS);
		_a->_Datas->_TLS->_file = (Data_TLS::_FILE *)(
			rva_addr(_a->_Datas->_file->DataDirectory[9].VirtualAddress, _a));
		_a->_Datas->_TLS->_length = _a->_Datas->_file->DataDirectory[9].Size;
	}
	if (_a->_Datas->_file->DataDirectory[10].VirtualAddress) {			// Data_LoadConfig
		_a->_Datas->_LoadConfig = new Data_LoadConfig;
		__zero(*_a->_Datas->_LoadConfig);
		_a->_Datas->_LoadConfig->_file = (Data_LoadConfig::_FILE *)(
			rva_addr(_a->_Datas->_file->DataDirectory[10].VirtualAddress, _a));
		_a->_Datas->_LoadConfig->_length = _a->_Datas->_file->DataDirectory[10].Size;
	}
	if (_a->_Datas->_file->DataDirectory[11].VirtualAddress) {			// Data_BoundImport
		_a->_Datas->_BoundImport = new Data_BoundImport;
		__zero(*_a->_Datas->_BoundImport);
		_a->_Datas->_BoundImport->_file = (Data_BoundImport::_FILE *)(
			rva_addr(_a->_Datas->_file->DataDirectory[11].VirtualAddress, _a));
		_a->_Datas->_BoundImport->_length = _a->_Datas->_file->DataDirectory[11].Size;
	}
	if (_a->_Datas->_file->DataDirectory[12].VirtualAddress) {			// Data_IAT
		_a->_Datas->_IAT = new Data_IAT;
		__zero(*_a->_Datas->_IAT);
		_a->_Datas->_IAT->_file = (Data_IAT::_FILE *)(
			rva_addr(_a->_Datas->_file->DataDirectory[12].VirtualAddress, _a));
		_a->_Datas->_IAT->_length = _a->_Datas->_file->DataDirectory[12].Size;
	}

	// Data_Export:
	Data_Export *_exp = _a->_Datas->_Export;
	{
		_exp->_dll_name = (asz_t)rva_addr(_exp->_file->Name, _a);

		int funcs = _exp->_file->NumberOfFunctions;
		if (funcs > 0) {
			u32_t *_rva_funcs = (u32_t *)rva_addr(_exp->_file->AddressOfFunctions, _a);
			_exp->_funcs = new Data_Export::_ITEM[funcs];
			for (int i = 0; i < funcs; i++) {
				__zero(_exp->_funcs[i]);
				void *_raw = rva_addr(_rva_funcs[i], _a);
				if (_raw > (void *)_exp->_file &&
					_raw < (void *)((u32_t)_exp->_file + _exp->_length)
					) {
					_exp->_funcs[i]._forward = (asz_t)_raw;
				} else {
					_exp->_funcs[i]._func_body = (void *)_raw;
				}
				_exp->_funcs[i]._ordinal = i + _exp->_file->Base;
			}
		}

		int names = _exp->_file->NumberOfNames;
		if (names > 0) {
			u32_t *_names = (u32_t *)rva_addr(_exp->_file->AddressOfNames, _a);
			u16_t *_nameords = (u16_t *)rva_addr(_exp->_file->AddressOfNameOrdinals, _a);
			_exp->_names = new Data_Export::_NAMES[names];
			for (int i = 0; i < names; i++) {
				_exp->_names[i].ordinal = _exp->_file->Base + _nameords[i];
				_exp->_names[i].name = (asz_t)rva_addr(_names[i], _a);
				_exp->_funcs[_nameords[i]]._name = _exp->_names[i].name;
			}
		}
	}

	// Data_Import:
	Data_Import *_imp = _a->_Datas->_Import;
	Data_Import::LIBITEMS *p = NULL;
	Data_Import::_FILE::_LIBITEM *_libf = _imp->_file->Items + 0;
	while (_libf->Characteristics != 0) {
		if (p) {
			p->l = new Data_Import::LIBITEMS;
			p->l->_l = p;
			p = p->l;
		} else {
			p = new Data_Import::LIBITEMS;
			p->_l = NULL;
			_imp->_libs = p;
		}
		Data_Import::LIBITEM *_lib;
		_lib = new Data_Import::LIBITEM;
		__zero(*_lib);
		p->data = _lib;

		_lib->_name = (asz_t)rva_addr(_libf->Name, _a);

		int nImports = 0;
		Data_Import::_FILE::_THUNKITEM *_thunk0 = (Data_Import::_FILE::_THUNKITEM *)
			rva_addr(_libf->OriginalFirstThunk, _a);
		Data_Import::_FILE::_THUNKITEM *_thunk = (Data_Import::_FILE::_THUNKITEM *)
			rva_addr(_libf->FirstThunk, _a);
		Data_Import::_FILE::_THUNKITEM *_th0 = _thunk0;
		Data_Import::_FILE::_THUNKITEM *_th = _thunk;
		while (_th0->AddressOfData) {
			nImports++;
			_th0++;
		}
		// nImports > 0
		_lib->_imports = nImports;
		_lib->_items = new Data_Import::IMPITEM[nImports];
		memset(_lib->_items, 0, sizeof(Data_Import::IMPITEM) * nImports);
		Data_Import::IMPITEM *_it = _lib->_items;
		_th0 = _thunk0;
		int iImport = 0;
		u32_t _fwd_chain = _libf->ForwarderChain;
		if (_fwd_chain == 0) _fwd_chain = (u32_t)-1;
		bool bBound = _libf->TimeDateStamp != 0;
		while (_th0->AddressOfData) {
			if (_fwd_chain != (u32_t)-1 && iImport == _fwd_chain) {
				_fwd_chain = _th[_fwd_chain].AddressOfData;
				asz_t szFwd = (asz_t)rva_addr(_th0->ForwarderString, _a);
				_it->bForward = true;
				asz_t szFwdName = strchr(szFwd, '.');
				// assert (szFwdName != 0) {
				szFwdName++;
				if (*szFwdName == '#') {
					_it->bForwardByOrd = true;
					_it->_fwd_ord = strtol(szFwdName, NULL, 10);
				} else {
					_it->_fwd_name = szFwdName;
				}
				_it->_fwd_libname = strdup(szFwd);
				*strchr(_it->_fwd_libname, '.') = '\0';
			} else {
				if (_th0->Ordinal & 0x80000000) {
					_it->bByOrd = true;
					_it->_ord = _th0->Ordinal & 0x0000FFFF;
				} else {
					_it->_name_hint = *(u16_t *)rva_addr(_th0->AddressOfData, _a);
					_it->_name = (asz_t)rva_addr(_th0->AddressOfData + 2, _a);
				}
			}
			if (bBound) {
				_it->bByBound = true;
				_it->_bound_addr = _th[iImport].Function;	// prefered virtual address
				_it->_bound_timestamp = _libf->TimeDateStamp;
			}

			_th0++;
			_it++;
			iImport++;
		}
		_libf++;
	}
	p->l = NULL;

	*ppPEArch = _a;
	e.bFailure = false;
	return e;
}