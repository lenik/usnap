
//	COM\����ģ��
//	2000.12.1


// ����·��
// ����չ���ṩ�ⲿ�ӿ�

#pragma once

#include "coModel.h"

interface coGuider;

co_type(coGuider);

interface coGuider {
	coSTR		name;
	// ������������
	coCity_r	city;
public:
	coSVF		querydata(coID_r didr, coRet_r retr) const = 0;
	coPlugin	plug;
};
