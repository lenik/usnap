
// Right-Cylinder Plane Extractor
// ֱ��ƽ��չ���㷨
//
// л����, �ҿǸ߿Ƽ� 2002


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
	bool	normalright;	// ���߳��� ����೯�ң�

	shape	xp;		// չ�����ƽ��

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


ST *right_cylinder_plane_extract(ST *topcap,	// ��������
				 T height,	// ����
				 T pastewidth,	// ճ�����ֺ��
				 bool adaptive,	// �Զ���Ӧ����
				 ...
				 ) {
	//
	ST *pnew = new ST;

	return pnew;
}

// ����ֽ׶ν��У���ô��Щ����������ֲ��ʣ���ֻ�ܴӳ��ֲ��ʵ��Ǹ��׶ε��������
//	���С������Ʊصò���ȫ�ֵ����Ž����
// �����һ����׶��н��У����ĳ�����ֳ��ֲ��ʣ���ô��Ҫ���ò��ʵĲ�������������
//	ǰһ���׶λ�����������ʵ�ϱ�ͷֽ׶��޲���ˡ�
// ��˿������Ժ�Ϊ�׶κ�����Ӳ��ʲ����ﵽ���µ�����Ŀ�ġ�

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
