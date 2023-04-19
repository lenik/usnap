
// Right-Cylinder Plane Extractor
// 直柱平面展开算法
//
// 谢继雷, 桃壳高科技 2002


#pragma once

#include <his/stlimp.h>

template<class T>
class rcpe {
public:
	typedef T	T_type;

	struct PT {
		T x;
		T y;
	};

	typedef std::list<PT>		PTs, LT;
	typedef std::list<LT>		LTs, ST;

public:
	shape	top;
	bool	normalright;	// 法线朝右 （外侧朝右）

	shape	xp;		// 展开后的平面

public:
	import_shape(BITMAP, COLORREF solidcolor);

public:
	right_cylinder_plane_extract();
	extend_side_face();
	extend_bottom_cap();
	extend_paste_face();

public:
	rcpe();
	~rcpe();
};


ST *right_cylinder_plane_extract(ST *topcap,	// 顶面描述
				 T height,	// 柱高
				 T pastewidth,	// 粘贴部分厚度
				 bool adaptive,	// 自动适应错误
				 ...
				 ) {
	//
	ST *pnew = new ST;

	return pnew;
}

// 如果分阶段进行，那么有些部分如果出现不适，则只能从出现不适的那个阶段调整后继续
//	进行。这样势必得不出全局的最优结果。
// 如果在一个大阶段中进行，如果某个部分出现不适，那么需要设置不适的参数描述，并向
//	前一个阶段回跳，这样事实上便和分阶段无差别了。
// 因此可以在以后为阶段函数添加不适参数达到重新调整的目的。

ST *extend_side_face(
			   ) {
	return NULL;
}

ST *extend_bottom_cap(
			    ) {
	return NULL;
}

ST *extend_paste_face(
			    ) {
	return NULL;
}
