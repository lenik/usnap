
#pragma once

#include "_SComp2.h"

typedef HRESULT (_stdcall *DllRegisterServer_proc)(void);

float	_stdcall advanced_score(size_t match, size_t unmatch, size_t extra, size_t lost);

enum score_plugin_mode_enum {
	spm_none	= 0,
	spm_dll,
	spm_activex
};

extern HMODULE			hmodPlugin;
extern score_plugin_mode_enum	score_plugin_mode;
extern stream_units_work::stream_units_work_compare::score_proc_type score_plugin_dll;
