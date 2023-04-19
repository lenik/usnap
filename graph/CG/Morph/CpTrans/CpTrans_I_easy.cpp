
#include "stdafx.h"

#include "CpTransI.h"

/*
 * rTable, nTable	: 关联表
 * cpDst, nDst		: 目标点，当有必要时通过查找目标点集发现其他关联方法
 * cDstEx, nDstEx	: 对于上述关联其他目标点时需要排除的目标点索引
 * ref, obj		: 指定关联对
 * dist			: 关联对的索引
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
	LPPOINTR	outsTable	= NULL;	/* 聚集关联表 */
	INT		ocounts		= 0;	/* 聚集关联表长度以及使用长度 */
	INT		rcounts		= cp_rtcounts(rTable, nTable);
						/* 关联表使用长度 */
	BOOL		ret		= TRUE;	/* 返回值 */
	INT		i, ii;

	if (rcounts != 0) {
		/* 初始化聚集关联表 */
		if ((outsTable = NEWA(POINTR, rcounts)) == NULL) {
			return FALSE;
		}
		outsTable[0].ref	= -1;

		/* 搜索已关联的obj并存入聚集关联表中 */
		for (i = 0; i < rcounts; i++) {
			if (rTable[i].obj == obj || rTable[i].ref != ref) {
				cp_setrefer(outsTable, rcounts, rTable[i].ref, rTable[i].obj, rTable[i].dist, ocounts);
				ocounts++;
			}
		}
	}

	if (1) {
		/* 目标点尚未被关联, 简单的设置关联 */
		ret	= cp_setrefer(rTable, nTable, ref, obj, dist, rcounts);
	} else {
		/* 目标点已被一个或数个关联点关联,
		 * 1. 判断是否需要重新关联原关联中的部分或全部
		 *	1.1 关联表中不包括关联点是指定关联点的关联, 因为这一关联可能需要重新关联
		 *	1.2 对于[(关联的长度大于指定关联的长度)的部分关联]需要重新关联
		 *		1.2.1 因为采用递归, 所以没有必要重新关联上述部分中的非最短关联
		 * 2. 对于需要重新关联的点(此关联必在聚集关联表中)递归调用本函数
		 *	2.1 为保证重新关联到其它被关联点, 提供屏蔽目标点集
		 *		2.1.1 添加obj为屏蔽目标点
		 *		2.1.2 屏蔽目标点集必须动态生成
		 *	2.2 递归调用本函数
		 * 3. 关联指定的关联
		 *	3.1 如果(被关联点属于屏蔽目标点集)则重新寻找被关联点
		 *		3.1.1 在{目标点集} - {屏蔽目标点集}中寻找最适合的关联
		 *		3.1.2 如果不存在最适合的关联则强制关联指定关联
		 *	3.2 关联指定关联
		 */

		/* 设 Ra = ref->obj, Rb(1..n) = ref'(1..n)->obj,
		 * 如果存在Rb(j)且|Rb(j)|为距离长于|Ra|的所有Rb(j1..jm)中
		 *	距离最短的关联, 则关联ref->obj且重新关联Rb(j)->obj
		 * 否则说明所有|Rb(j)| < |Ra|,
		 *	如果不存在obj'属于cpDst, 使ref->obj'关联成功,
		 *	则强制关联ref->obj.
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
