
#include "stdafx.h"

#include <math.h>

#include "CpTransI.h"

BOOL	STDCALL cp_transform(LPPOINT		cpSrc,
			     INT		nSrc,
			     LPPOINT		cpDst,
			     INT		nDst,
			     REAL		sample,
			     DISTANCEPROC	distProc,
			     CPTRANSFORMPROC	transProc,
			     DWORD		transParam,
			     CPRELATIONPROC	relProc,
			     DWORD		relParam,
			     BOOL		relDemonstrate,
			     CPREFERPROC	referProc
			     ) {
	LPPOINTR	rtSrc;		/* 源控制点 -> 目标控制点 关联表 */
	LPPOINTR	rtDst;		/* 目标控制点 -> 源控制点 关联表 */
	LPPOINTR	rTable;		/* 两个关联表的合并 */
	REAL		Nearest;
	INT		NearestI;
	REAL		dist;
	INT		i, ii;
	BOOL		ret		= TRUE;
	BOOL		transRet	= TRUE;

	if (nSrc < 1 || nDst < 1) return FALSE;
	if (referProc == NULL) return FALSE;
	if (transProc == NULL && relProc == NULL) return FALSE;

	rtSrc	= NEWA(POINTR, nSrc);	/* 分配数组 */
	rtDst	= NEWA(POINTR, nDst);
	if (rtDst == NULL) {
		if (rtSrc != NULL) DELETEA(rtSrc);
		return FALSE;
	}
	rtSrc[0].ref	= -1;
	rtDst[0].ref	= -1;

	// 关联 源 -> 目标
	for (i = 0; i < nSrc; i++) {
		Nearest		= -1;
		for (ii = 0; ii < nDst; ii++) {
			dist	= distProc(cpSrc + i, cpDst + ii);
			if (dist < Nearest || Nearest < 0) {
				Nearest		= dist;
				NearestI	= ii;
			}
		}
		if (Nearest >= 0) {
			referProc(rtSrc, nSrc, cpSrc, nSrc, cpDst, nDst, NULL, 0, i, NearestI, Nearest, distProc);
			if ((relProc != NULL) && relDemonstrate) {
				relProc(rtSrc, cp_rtcounts(rtSrc, nSrc), NULL, 0, relParam);
			}
		}
	}

	// 关联 源 <- 目标, 当且仅当目标未被关联
	for (i = 0; i < nDst; i++) {
		INT	rtc	= cp_rtcounts(rtSrc, nSrc);
		BOOL	refered	= FALSE;
		for (ii = 0; ii < rtc; ii++) {
			if (rtSrc[ii].obj == i) {
				refered		= TRUE;
				break;
			}
		}
		if (!refered) {
			Nearest		= -1;
			for (ii = 0; ii < nSrc; ii++) {
				dist	= distProc(cpDst + i, cpSrc + ii);
				if (dist < Nearest || Nearest < 0) {
					Nearest		= dist;
					NearestI	= ii;
				}
			}
			if (Nearest >= 0) {
				referProc(rtDst, nDst, cpDst, nDst, cpSrc, nSrc, NULL, 0, i, NearestI, Nearest, distProc);
				if ((relProc != NULL) && relDemonstrate) {
					relProc(rtSrc, cp_rtcounts(rtSrc, nSrc),
						rtDst, cp_rtcounts(rtDst, nDst),
						relParam
						);
				}
			}
		}
	}

	if (relProc != NULL) {
		/* 检测双向关联表 */
		relProc(rtSrc, cp_rtcounts(rtSrc, nSrc),	/* 检测范围优化 */
			rtDst, cp_rtcounts(rtDst, nDst),
			relParam
			);
	}

	if (transProc != NULL) {
		/* 合并关联表并进行插值运算 */
		if (sample < 0.005) sample	= 0.005;
		while (TRUE) {
			REAL	slider;		/* 插值点([0, 1]) */
			LPPOINT	cp;		/* 插值样本 */
			INT	ncp1, ncp2;	/* ncp1 + ncp2 == cp元数 */
			ncp1	= cp_rtcounts(rtSrc, nSrc);
			ncp2	= cp_rtcounts(rtDst, nDst);

			if (ncp1 + ncp2 < 1) break;

			if ((cp = NEWA(POINT, ncp1 + ncp2)) == NULL) {
				ret	= FALSE;
				break;
			}
			rTable	= NEWA(POINTR, ncp1 + ncp2);
			if (rTable != NULL) {
				/* 合并关联表 */
				INT	i1 = 0, i2 = 0;
				INT	ref_serial = 0;
				rTable[0].ref	= -1;
				i		= 0;
				while (i1 < ncp1 || i2 < ncp2) {
					if (i1 < ncp1) {
						if (rtSrc[i1].ref == ref_serial) {
							rTable[i].ref	= rtSrc[i1].ref;
							rTable[i].obj	= rtSrc[i1].obj;
							rTable[i].dist	= rtSrc[i1].dist;
							i++;
							i1++;
							continue;
						}
					}
					if (i2 < ncp2) {
						if (rtDst[i2].obj == ref_serial) {
							rTable[i].ref	= rtDst[i2].obj;
							rTable[i].obj	= rtDst[i2].ref;
							rTable[i].dist	= rtDst[i2].dist;
							i++;
							i2++;
							continue;
						}
					}
					/* 预测下一个ref_serial */
					if (i1 < ncp1 && i2 < ncp2) {
						if (rtSrc[i1].ref <= rtDst[i2].obj) {
							ref_serial	= rtSrc[i1].ref;
						} else {
							ref_serial	= rtDst[i2].obj;
						}
						continue;
					}
					if (i1 < ncp1 && i2 >= ncp2) {
						ref_serial	= rtSrc[i1].ref;
						continue;
					}
					if (i1 >= ncp1 && i2 < ncp2) {
						ref_serial	= rtDst[i2].obj;
						continue;
					}
					ref_serial++;
					if (ref_serial > ncp1 + ncp2) break;
				}
				/* 按照目标排序 */
				if (1) {
					for (ii = 0; ii < i; ii++) {
						int	iii;
						BOOL	bModified	= FALSE;
						for (iii = 1; iii < i - ii; iii++) {
							if (rTable[iii - 1].obj > rTable[iii].obj) {
								POINTR	rtmp;
								rtmp.ref		= rTable[iii].ref;
								rtmp.obj		= rTable[iii].obj;
								rtmp.dist		= rTable[iii].dist;
								rTable[iii].ref		= rTable[iii - 1].ref;
								rTable[iii].obj		= rTable[iii - 1].obj;
								rTable[iii].dist	= rTable[iii - 1].dist;
								rTable[iii - 1].ref	= rtmp.ref;
								rTable[iii - 1].obj	= rtmp.obj;
								rTable[iii - 1].dist	= rtmp.dist;
								bModified		= TRUE;
							}
						}
						if (!bModified) break;
					}
				}

				/* 插值运算 */
				for (slider = 0; slider <= 1; slider += sample) {
					for (ii = 0; ii < i; ii++) {
						LPPOINT	ref	= cpSrc + rTable[ii].ref;
						LPPOINT obj	= cpDst + rTable[ii].obj;
						cp[ii].x	= (INT)((1 - slider) * ref->x + slider * obj->x);
						cp[ii].y	= (INT)((1 - slider) * ref->y + slider * obj->y);
					}
					transRet	= transProc(slider, cp, i, transParam);
				}
				DELETEA(rTable);
			} else {
				/* 不能合并关联表, 强行插值运算 */
				for (slider = 0; slider <= 1; slider += sample) {
					for (i = 0; i < ncp1; i++) {
						LPPOINT	ref	= cpSrc + rtSrc[i].ref;
						LPPOINT obj	= cpDst + rtSrc[i].obj;
						cp[i].x		= (INT)((1 - slider) * ref->x + slider * obj->x);
						cp[i].y		= (INT)((1 - slider) * ref->y + slider * obj->y);
					}
					for (i = 0; i < ncp2; i++) {
						LPPOINT ref	= cpDst + rtDst[i].obj;
						LPPOINT obj	= cpSrc + rtDst[i].ref;
						cp[i + ncp1].x	= (INT)((1 - slider) * ref->x + slider * obj->x);
						cp[i + ncp1].y	= (INT)((1 - slider) * ref->y + slider * obj->y);
					}
					transRet	= transProc(sample, cp, ncp1 + ncp2, transParam);
				}
			} /* if new rTable */
			DELETEA(cp);
			break;
		} /* while TRUE */
	} /* if transProc */

	DELETEA(rtSrc);
	DELETEA(rtDst);

	ret	= ret && transRet;
	return ret;
}

/*
 * rTable, nTable	: 关联表
 * cpDst, nDst		: 目标点，当有必要时通过查找目标点集发现其他关联方法
 * cDstEx, nDstEx	: 对于上述关联其他目标点时需要排除的目标点索引
 * ref, obj		: 指定关联对
 * dist			: 关联对的索引
 */
BOOL	STDCALL cp_refer(LPPOINTR	rTable,
			 INT		nTable,
			 LPPOINT	cpSrc,
			 INT		nSrc,
			 LPPOINT	cpDst,
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

	if (ocounts == 0) {
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

BOOL	STDCALL cp_setrefer(LPPOINTR rTable, INT nTable, INT ref, INT obj, REAL dist, INT initp) {
	INT	i;
	for (i = initp; i < nTable; i++) {
		/* 对于 rTable[i].ref == ref 表现在重新关联 */
		/* 对于 rTable[i].ref == NULL 表现在新增关联 */
		if (rTable[i].ref == ref || rTable[i].ref == -1) {
			if (rTable[i].ref == -1) {
				if (i + 1 < nTable) {
					rTable[i + 1].ref	= -1;
				}
			}
			rTable[i].ref	= ref;
			rTable[i].obj	= obj;
			rTable[i].dist	= dist;
			return TRUE;
		}
	}
	return FALSE;
}

INT	STDCALL cp_rtcounts(LPPOINTR rTable, INT nTable) {
	INT	i;
	for (i = 0; i < nTable; i++) if (rTable[i].ref == -1) break;
	return i;
}

REAL	STDCALL distance_e(LPPOINT pA, LPPOINT pB) {
	REAL	dist;
	dist	= sqrt(	(pA->x - pB->x) * (pA->x - pB->x) +
			(pA->y - pB->y) * (pA->y - pB->y));
	return dist;
}

BOOL	STDCALL draw_on_screen(REAL slider, LPPOINT cp, INT n, DWORD dwParam) {
	slider	= slider;
	cp	= cp;
	n	= n;
	dwParam	= dwParam;
	return TRUE;
}
