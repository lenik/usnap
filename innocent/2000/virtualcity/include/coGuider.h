
//	COM\导游模型
//	2000.12.1


// 管理路线
// 可扩展、提供外部接口

#pragma once

#include "coModel.h"

interface coGuider;

co_type(coGuider);

interface coGuider {
	coSTR		name;
	// 导游所属城市
	coCity_r	city;
public:
	coSVF		querydata(coID_r didr, coRet_r retr) const = 0;
	coPlugin	plug;
};
