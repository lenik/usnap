
#pragma once

#include <his/base.h>

// hiFS
// ��ʱ�����ṩ�ļ�ϵͳ֧��

// �����ļ�ϵͳ

// �µ��ļ�ϵͳ������ʹ���򲻱ؿ����ļ���ǰλ�õĸ���
// ����SEEKȡ��
// �ļ��ĳ��ȣ�ֻ������ָ����һ��ָ���Ͳ��ı䡣
// ������û��APPEND��������
// �ļ����ǿɶ���д����ȫ�Կ��Կ�������Ĳ��
// ������û��ATTRIBUTE���ֶ���
// ���������ݲ�����
// Ŀ¼�����⣬����ʹ��\��/���ָ������ڲ����仮�ֳ����飬��\0���ָ��������\0
// ����ϵͳû�а��ڴ��ʹ�û��ֳ�����hiFS�ǡ�

// �ڴ�û�йر������´򿪵����ԣ���FS�ǳ־õģ���Ҫopen��close����
//

// ���ݹ����ĺ����ڴ�λ��(hisroot)/proc/core/
// �����ں��ļ�ģ��Ľ�����

struct hi_core_memory {
	hicode	(hiapi *init)(char *name);
	hicode	(hiapi *uninit)();
	hicode	(hiapi *get)(hisize pos, char *retchar);
	hicode	(hiapi *set)(hisize pos, char newchar);
}
