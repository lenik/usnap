
#ifndef __CPTRANSI_EASY_H
#define __CPTRANSI_EASY_H

#include "CpTransI.h"

/*
 * rTable, nTable	: ������
 * cpDst, nDst		: Ŀ��㣬���б�Ҫʱͨ������Ŀ��㼯����������������
 * cDstEx, nDstEx	: ����������������Ŀ���ʱ��Ҫ�ų���Ŀ�������
 * ref, obj		: ָ��������
 * dist			: �����Ե�����
 */
BOOL	STDCALL cp_refer_easy(LPPOINTR		rTable,
			      INT		nTable,
			      LPPOINT		cpSrc,
			      INT		nSrc,
			      LPPOINT		cpDst,
			      INT		nDst,
			      LPINT		cpDstEx,
			      INT		nDstEx,
			      INT		ref,
			      INT		obj,
			      REAL		dist,
			      DISTANCEPROC	distProc);

#endif
