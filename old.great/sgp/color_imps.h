

// ɫ�ʿ�ѧ�е�ɫ��

#include <sgp/sgpdef.h>
#include <sgp/color.h>

SGP_BEGIN

// ɫ��ʵ��(����ɫ�ʿ�ѧ)�ӿ�
class sgp_color_imps {
public:
	;
};

class sgp_color_imps_common {
public:
	// һ��ɫ��֧��
	class color_styles : public sgp_color_imps {
	public:
		redlize(sgp_color&, double factor);	// �컯
		greenlize(sgp_color&, double factor);	// �̻�
		bluelize(sgp_color&, double factor);	// ����

		whitelize(sgp_color&, double factor);	// �׻�
		blacklize(sgp_color&, double factor);	// �ڻ�
	};

	class temp_styles : public sgp_color_imps {
	public:
		hotlize(sgp_color&, double factor);
		coldlize(sgp_color&, double factor);
	};
};

SGP_END
