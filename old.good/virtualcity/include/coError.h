
#pragma once

#include "coType.h"

// 特殊错误
	enum co_tag_type(coRetError) {
		coe_none = 0,

		// com错误
		coe_not_existed_node,
		coe_not_existed_link,
		coe_not_existed_path,
		coe_not_existed_map,
		coe_not_existed_city,

		coe_not_existed_guider,

		// 调用错误
		coe_uninit_enum,

		// 消息

		// 发出消息
		coe_start,
		coe_init,
		coe_try,
		coe_retry,
		coe_finish,
		coe_exit,
		// 返回消息
		coe_processed,
		coe_skipped
	};
	co_def_type(co_tag_type(coRetError), coRetError);

// 控制常量
	enum co_tag_type(coRetControl) {
		// 控制流程 (标准)
		coc_continue,				// N2 = N1 + 1
		coc_break,				// 跳出
		coc_errorbreak,				// 跳出 (因为出错)
		// 控制流程 (扩展)
		coc_previous,				// N2 = N1 - 1
		coc_again,				// N2 = N1
		coc_skip,				// N2 = N2 + 2
		coc_skips,				// N2 = N2 + data + 1
		coc_home,				// 局部始
		coc_end,				// 局部尾
		coc_first,				// 始
		coc_last,				// 尾
		coc_before_first,			// 超越上界
		coc_after_last,				// 超越下界
		// 控制状态
		coc_query,				// 询问是否接受
		coc_accept,				// 接受
		coc_deny, 				// 拒绝
		coc_casual, 				// 均可无法确定
		coc_unknown				// 未知
	};
	co_def_type(co_tag_type(coRetControl), coRetControl);

struct co_tag_type(coErrorHash) {
	coRetError		coerror;
	coSTR			info;
};
extern co_tag_type(coErrorHash)	co_error_hash[];
