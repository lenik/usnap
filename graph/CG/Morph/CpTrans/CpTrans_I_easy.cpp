
#include "stdafx.h"

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
			      DISTANCEPROC	distProc) {
	LPPOINTR	outsTable	= NULL;	/* �ۼ������� */
	INT		ocounts		= 0;	/* �ۼ����������Լ�ʹ�ó��� */
	INT		rcounts		= cp_rtcounts(rTable, nTable);
						/* ������ʹ�ó��� */
	BOOL		ret		= TRUE;	/* ����ֵ */
	INT		i, ii;

	if (rcounts != 0) {
		/* ��ʼ���ۼ������� */
		if ((outsTable = NEWA(POINTR, rcounts)) == NULL) {
			return FALSE;
		}
		outsTable[0].ref	= -1;

		/* �����ѹ�����obj������ۼ��������� */
		for (i = 0; i < rcounts; i++) {
			if (rTable[i].obj == obj || rTable[i].ref != ref) {
				cp_setrefer(outsTable, rcounts, rTable[i].ref, rTable[i].obj, rTable[i].dist, ocounts);
				ocounts++;
			}
		}
	}

	if (1) {
		/* Ŀ�����δ������, �򵥵����ù��� */
		ret	= cp_setrefer(rTable, nTable, ref, obj, dist, rcounts);
	} else {
		/* Ŀ����ѱ�һ�����������������,
		 * 1. �ж��Ƿ���Ҫ���¹���ԭ�����еĲ��ֻ�ȫ��
		 *	1.1 �������в�������������ָ��������Ĺ���, ��Ϊ��һ����������Ҫ���¹���
		 *	1.2 ����[(�����ĳ��ȴ���ָ�������ĳ���)�Ĳ��ֹ���]��Ҫ���¹���
		 *		1.2.1 ��Ϊ���õݹ�, ����û�б�Ҫ���¹������������еķ���̹���
		 * 2. ������Ҫ���¹����ĵ�(�˹������ھۼ���������)�ݹ���ñ�����
		 *	2.1 Ϊ��֤���¹�����������������, �ṩ����Ŀ��㼯
		 *		2.1.1 ���objΪ����Ŀ���
		 *		2.1.2 ����Ŀ��㼯���붯̬����
		 *	2.2 �ݹ���ñ�����
		 * 3. ����ָ���Ĺ���
		 *	3.1 ���(����������������Ŀ��㼯)������Ѱ�ұ�������
		 *		3.1.1 ��{Ŀ��㼯} - {����Ŀ��㼯}��Ѱ�����ʺϵĹ���
		 *		3.1.2 ������������ʺϵĹ�����ǿ�ƹ���ָ������
		 *	3.2 ����ָ������
		 */

		/* �� Ra = ref->obj, Rb(1..n) = ref'(1..n)->obj,
		 * �������Rb(j)��|Rb(j)|Ϊ���볤��|Ra|������Rb(j1..jm)��
		 *	������̵Ĺ���, �����ref->obj�����¹���Rb(j)->obj
		 * ����˵������|Rb(j)| < |Ra|,
		 *	���������obj'����cpDst, ʹref->obj'�����ɹ�,
		 *	��ǿ�ƹ���ref->obj.
		 */

		/* 1 */
		REAL	NearestLong	= -1;
		INT	NearestLongI	= 0;
		for (i = 0; i < ocounts; i++) {
			REAL	disti	= outsTable[i].dist;

			if (disti > dist && (disti < NearestLong || NearestLong < 0)) {
				NearestLong	= disti;
				NearestLongI	= i;
			}
		}
		/* 2 */
		if (NearestLong >= 0) {
			/* 2.1.2 */
				LPINT	cpDstEx_Inc;
				if (cpDstEx == NULL) {
					cpDstEx_Inc	= NEWA(INT, 1);
				} else {
					cpDstEx_Inc	= NEWA(INT, nDstEx + 1);
				}
				/* if new failed ... */
				if (cpDstEx != NULL) {
					memcpy(cpDstEx_Inc, cpDstEx, sizeof(INT) * nDstEx);
					DELETEA(cpDstEx);
				}
				cpDstEx			= cpDstEx_Inc;

			/* 2.1.1 */
			cpDstEx[nDstEx++]	= obj;
			/* 2.2 */
			cp_refer(rTable, nTable,
				cpSrc, nSrc, cpDst, nDst,
				cpDstEx_Inc, nDstEx,
				outsTable[NearestLongI].ref,
				outsTable[NearestLongI].obj,
				outsTable[NearestLongI].dist,
				distProc);
		}
		/* 3 */
		{
			BOOL	refered	= FALSE;
			for (i = 0; i < nDstEx; i++) {
				if (cpDstEx[i] == obj) {
					/* 3.1 */
					REAL	Nearest		= -1;
					INT	NearestI;
					for (i = 0; i < nDst; i++) {
						/* 3.1.1 */
						BOOL	isExclude	= FALSE;
						for (ii = 0; ii < nDstEx; ii++) {
							if (i == cpDstEx[ii]) {
								isExclude	= TRUE;
								break;
							}
						}
						if (!isExclude) {
							REAL	disti;
							disti	= distProc(cpSrc + ref, cpDst + obj);
							if (disti < Nearest || Nearest < 0) {
								Nearest		= disti;
								NearestI	= i;
							}
						}
					}
					/* 3.1.2 */
					if (Nearest < 0) {
						cp_setrefer(rTable, nTable, ref, obj, dist, 0);
					} else {
						cp_setrefer(rTable, nTable, ref, NearestI, Nearest, 0);
					}
					refered	= TRUE;
					break;
				}
			}
			/* 3.2 */
			if (!refered) {
				cp_setrefer(rTable, nTable, ref, obj, dist, rcounts);
			}
		}
	}

	if (ocounts != 0) DELETEA(outsTable);
	return ret;
}
