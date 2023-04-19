
#include "stdafx.h"

#include "_SComp2.h"
#include "sc_plugin.h"

HMODULE			hmodPlugin;
score_plugin_mode_enum	score_plugin_mode;
stream_units_work::stream_units_work_compare::score_proc_type	score_plugin_dll;

float _stdcall	advanced_score(size_t match, size_t unmatch, size_t extra, size_t lost) {
	float	score	= 0.f;

	if (score_plugin_mode == spm_none) {
		score	= stream_units_work::stream_units_work_compare::default_score(match, unmatch, extra, lost);
	} else if (score_plugin_mode == spm_dll) {
		score	= score_plugin_dll(match, unmatch, extra, lost);
	} else if (score_plugin_mode == spm_activex) {
		score	= 0;
	} else {
		score	= stream_units_work::stream_units_work_compare::default_score(match, unmatch, extra, lost);
	}

	return score;
}


// 函数参数的线性估计
void compute_k(stream_units_work::stream_units_work_compare::score_proc_type sp, float& k0, float& k1, float& k2, float& k3, float& k4) {
	k0	= sp(0, 0, 0, 0);
	k1	= sp(1, 0, 0, 0) - k0;
	k2	= sp(0, 1, 0, 0) - k0;
	k3	= sp(0, 0, 1, 0) - k0;
	k4	= sp(0, 0, 0, 1) - k0;
}
