
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
	INT		rcounts		= cp_rtcounts(rTable, nTable);
						/* 关联表使用长度 */
	BOOL		ret		= TRUE;	/* 返回值 */

	/* 不管目标点尚未被关联, 简单的设置关联 */
	ret	= cp_setrefer(rTable, nTable, ref, obj, dist, rcounts);

	return ret;
}
