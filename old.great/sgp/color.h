
#pragma once

#include <sgp/sgpdef.h>
#include <list>

SGP_BEGIN

class color_imps;

class color {
public:
	struct {
		void *_color;
		union {
			struct {
				int r;
				int g;
				int b;
			} rgb;
			struct {
				int c;
				int m;
				int y;
				int k;
			} cmyk;
		} color_exp; /* color expression */
		enum {
			system = 0,
			rgb,
			cmyk
		};
	} _c;

public:
	invert();			// ȡ��ɫ

public:
	void mix_palette(color& o);	// ��ɫ��ɫ�ʻ��
	void mix_light(color& o);	// ����ɫ�ʻ��

public:
	friend class color_imps;
};


// ʵ��ɫ, ����������ɫ
class solid_color {
public:
	color c;
	double quantity;
public:
	void mix_palette(solid_color& o);
	void mix_light(solid_color& o);
};

class mixed_color {
public:
	typedef std::list<solid_color> solid_colors;
	solid_colors colors;
public:
	void mix_palette(mixed_color& o);
	void mix_light(mixed_color& o);
};

SGP_END
