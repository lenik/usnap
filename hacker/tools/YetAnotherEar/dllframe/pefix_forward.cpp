
#include "stdafx.h"
#include "dllframe.h"
#include "pe.h"
#include "pe_ana.h"		// rva_addr
#include "pefix_forward.h"
#include <pos/error.h>
#include <pos/bdt.h>
using namespace pos;

int _ordinal_based(PEFile *_a, int ord) {
	ord -= _a->_Datas->_Export->_file->Base;
	if (ord >= 0 && ord < _a->_Datas->_Export->_file->NumberOfFunctions) {
		return ord;
	}
	return -1;
}

int _name_ordinal(PEFile *_a, asz_t _name) {
	int n = _a->_Datas->_Export->_file->NumberOfNames;
	for (int i = 0; i < n; i++) {
		Data_Export::_NAMES& nameinfo = _a->_Datas->_Export->_names[i];
		if (strcmp(nameinfo.name, _name) == 0) {
			return nameinfo.ordinal;
		}
	}
	return -1;
}

int _name_ordinal_fast(PEFile *_a, asz_t _name) {
	int n = _a->_Datas->_Export->_file->NumberOfNames;
	int l = 0, r = n - 1;
	while (l <= r) {
		int i = l + (r - l) / 2;
		Data_Export::_NAMES& nameinfo = _a->_Datas->_Export->_names[i];
		int ic = strcmp(nameinfo.name, _name);
		if (ic == 0) {
			return nameinfo.ordinal;
		} else if (ic < 0) {
			l = i + 1;
		} else {
			// assume ic > 0
			r = i - 1;
		}
	}
	return -1;
}

error_t FixDll_ForwardMissing(PEFile *_peref, PEFile *_pefix) {
	error_t e;
	__zero(e);
	e.bFailure = true;

	// findout which section contain export functions.
	Sections *p = _pefix->_Sections;
	void *_exp_raw = _pefix->_Datas->_Export->_file;
	while (p) {
		Section *_s = p->data;
		if (_exp_raw >= _s->_raw &&
			_exp_raw < (void *)((u32_t)_s->_raw + _s->_file->SizeOfRawData)
			) {
			break;
		}
		p = p->l;
	}

	if (!p) {	// can't find the section contain exports.
		e.type = err_unexpected;
		return e;
	}

	// 1, clone ref' exp directory.
	// 2, found out whatever export functions that exist in _pe, but not exist in _pefix
	//	fix clone's exp items'rva, which name overloaded by pefix.
	// 3, fix clone's exp items'rva, which ordinal overloaded by pefix.
	// 4, append rest pefix'exps to clone's, append at end of list or insert into empty-slots.
	// 5. remake up the named-function list.
	int nr = _peref->_Datas->_Export->_file->NumberOfFunctions;
	int nf = _pefix->_Datas->_Export->_file->NumberOfFunctions;
	int nn = _pefix->_Datas->_Export->_file->NumberOfNames;
	int i;
	Data_Export::_ITEM *_clone = new Data_Export::_ITEM[nr + nf]; // max size
	int f_base = _pefix->_Datas->_Export->_file->Base;
	int r_base = _peref->_Datas->_Export->_file->Base;
	int c_base = _peref->_Datas->_Export->_file->Base;
	int r_up = 0;
	if (f_base < c_base) {
		r_up = c_base - f_base;		// r_up = empty-slots before ref-exps starts in clone'
		c_base = f_base;		// f_base = min(ref::base, fix::base)
	}
	// clear all within clone'
	memset(_clone, 0, sizeof(Data_Export::_ITEM) * (nr + nf));
	for (i = 0; i < nr; i++) {
		// copy ref-exps to clone', with r_up empty-slots at the beginning.
		_clone[r_up + i] = _peref->_Datas->_Export->_funcs[i];
		_clone[r_up + i]._ctx._r.bMark = false;
	}
	for (i = 0; i < nf; i++) {
		Data_Export::_ITEM& fi = _pefix->_Datas->_Export->_funcs[i];
		// mark all empty-slots in fix'. they'll be ignored.
		if (fi._func_body == NULL && fi._forward == NULL) {
			fi._ctx._r.bMark = true;
		} else {
			fi._ctx._r.bMark = false;
		}
	}

	// 2. name overload
	for (i = 0; i < nn; i++) {
		// fix' name (asz_t name, int ordinal)
		Data_Export::_NAMES& n = _pefix->_Datas->_Export->_names[i];
		int ord_ref = _name_ordinal_fast(_peref, n.name);
		if (ord_ref >= 0) {
			int ref_index = _ordinal_based(_peref, ord_ref);
			int fix_index = _ordinal_based(_pefix, n.ordinal);
			_clone[r_up + ref_index] = _pefix->_Datas->_Export->_funcs[fix_index];
			// clone' to be RVA translate.
			_clone[r_up + ref_index]._ctx._r.bMark = true;
			// fix' to be ignored in next ordinal overload.
			_pefix->_Datas->_Export->_funcs[fix_index]._ctx._r.bMark = true;
		}
	}
	// 3. ordinal overload
	for (i = 0; i < nf; i++) {
		Data_Export::_ITEM& fi = _pefix->_Datas->_Export->_funcs[i];
		// this item is overloaded, skip it.
		if (fi._ctx._r.bMark) continue;
		// the rest named-function must doesn't match any named-function in refs'
		if (fi._name) continue;

		int fix_ord = fi._ordinal; // fix_index == i
		int ref_index = _ordinal_based(_peref, fix_ord);
		if (ref_index >= 0) {
			// used. delay this to next append.
			if (_clone[r_up + ref_index]._ctx._r.bMark) continue;

			_clone[r_up + ref_index] = fi;
			// clone' to be RVA translate.
			_clone[r_up + ref_index]._ctx._r.bMark = true;
			// fix' to be ignored on next append.
			fi._ctx._r.bMark = true;
		} else {
			// ordinals out of ref' range. but assert they are within clone' range.
			int c_index = fix_ord - r_base + r_up;

			// used. delay this to next append.
			if (_clone[c_index]._ctx._r.bMark) continue;

			_clone[c_index] = fi;
			// clone' to be RVA translate
			_clone[c_index]._ctx._r.bMark = true;
			// fix' to be ignored on next append.
			fi._ctx._r.bMark = true;
		}
	}
	// 4. append
	int cs_index = 0; // next slot-index in clone'
	for (i = 0; i < nf; i++) {
		Data_Export::_ITEM& fi = _pefix->_Datas->_Export->_funcs[i];
		// only append the rest items.
		if (fi._ctx._r.bMark) continue;

		// search next empty-slot. marked-is overloaded from fix',
		// and _func_body != NULL is used by ref'. the rest is empties.
		while (_clone[cs_index]._ctx._r.bMark
			|| _clone[cs_index]._func_body != NULL) cs_index++;

		_clone[cs_index] = fi;
		// marked as used.
		_clone[cs_index]._ctx._r.bMark = true;
		// fix' is appended.
		fi._ctx._r.bMark = true;
	}

	// 5. remake.
	//	here, _clone[cs_index] is the last empty-slot. but there may be entries after some empties.
	//	n_clone = cs_index+1 is still probable.
	int n_clone = 0;
	int n_clone_names = 0;
	int namelen_sum = 0;
	int fwdlen_sum = 0;
	for (n_clone = nr + nf; n_clone > 0; n_clone--) {
		if (_clone[n_clone]._ctx._r.bMark
			|| _clone[n_clone - 1]._func_body != NULL)
			break;
	}
	for (i = 0; i < n_clone; i++) {
		// re-numbering the ordinal. old ordinals isn't exactly.
		_clone[i]._ordinal = i + c_base;

		// not overload-functions use forward instead.
		if (!_clone[i]._ctx._r.bMark) {
			_clone[i]._func_body = NULL;
			a_t nm[1024];
			a_t libname[256];
			base_name(_peref->_Datas->_Export->_dll_name, libname);
			if (_clone[i]._name) {
				sprintf(nm, "%s.%s", libname, _clone[i]._name);
			} else {
				sprintf(nm, "%s.#%d", libname, _clone[i]._ordinal);
			}
			_clone[i]._forward = strdup(nm);
			fwdlen_sum += strlen(nm) + 1/*'\0'*/;
		}

		if (_clone[i]._name) {
			// named function
			n_clone_names++;
			namelen_sum += strlen(_clone[i]._name) + 1/*'\0'*/;
		}
	}

	// calculate size, update Export-section header
	u32_t size_exp_data = sizeof(Data_Export::_FILE)
		+ n_clone * 4		// rvaFunctions
		+ n_clone_names * 4	// rvaNames
		+ n_clone_names * 4	// rvaNameOrdinals
		+ namelen_sum
		+ fwdlen_sum
		;

	//u32_t
	// fix the pefix hdrs
	//
	_pefix->_Datas->_Export->_funcs = _clone;
	_pefix->_Datas->_Export->_file->NumberOfFunctions = n_clone;
	_pefix->_Datas->_Export->_file->NumberOfNames = 0; //n_clone_names;

	//_pefix->_Datas->_Export->_names

	e.bFailure = false;
	return e;
}
