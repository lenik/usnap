
#include "coType.h"

co_tag_type(coErrorHash) co_error_hash[] = {
	{
		coe_none,			"没有错误"
	}, {
		coe_not_existed_node,		"结点不存在"
	}, {
		coe_not_existed_link,		"连结不存在"
	}, {
		coe_not_existed_path,		"路不存在"
	}, {
		coe_not_existed_map,		"地图不存在"
	}, {
		coe_not_existed_guider,		"导游对象不存在"
	}, {
		coe_uninit_enum,		"枚举回调尚未初始化"
	}
};
