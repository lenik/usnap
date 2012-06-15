

// 色彩科学中的色彩

#include <sgp/sgpdef.h>
#include <sgp/color.h>

SGP_BEGIN

// 色彩实现(面向色彩科学)接口
class sgp_color_imps {
public:
	;
};

class sgp_color_imps_common {
public:
	// 一般色调支持
	class color_styles : public sgp_color_imps {
	public:
		redlize(sgp_color&, double factor);	// 红化
		greenlize(sgp_color&, double factor);	// 绿化
		bluelize(sgp_color&, double factor);	// 蓝化

		whitelize(sgp_color&, double factor);	// 白化
		blacklize(sgp_color&, double factor);	// 黑化
	};

	class temp_styles : public sgp_color_imps {
	public:
		hotlize(sgp_color&, double factor);
		coldlize(sgp_color&, double factor);
	};
};

SGP_END
