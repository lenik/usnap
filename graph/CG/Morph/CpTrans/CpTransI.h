
#ifndef __CPTRANSI_H
#define __CPTRANSI_H

#include "stdtypes.h"

/* 关联点 */
typedef struct _POINTR {
	INT	ref;		/* 关联点索引 */
	INT	obj;		/* 被关联点索引 */
	REAL	dist;		/* 距离权值 */
} POINTR, *PPOINTR, *LPPOINTR;

/* 距离度量回调类型 */
typedef REAL (STDCALL *DISTANCEPROC)(LPPOINT pA, LPPOINT pB);
/* 关联方法回调类型 */
typedef BOOL (STDCALL *CPREFERPROC)(LPPOINTR		rt,
				    INT			nt,
				    LPPOINT		cpSrc,
				    INT			nSrc,
				    LPPOINT		cpDst,
				    INT			nDst,
				    LPINT		cpDstEx,
				    INT			nDstEx,
				    INT			ref,
				    INT			obj,
				    REAL		dist,
				    DISTANCEPROC	distProc);
/* 插值过程回调类型 */
typedef BOOL (STDCALL *CPTRANSFORMPROC)(REAL		slider,
					LPPOINT		cp,
					INT		ncp,
					DWORD		dwParam);
/* 双向关联表检测回调类型 */
typedef BOOL (STDCALL *CPRELATIONPROC)(LPPOINTR		rtSrc,
				       INT		nSrc,
				       LPPOINTR		rtDst,
				       INT		nDst,
				       DWORD		dwParam);

/* distance_e		欧氏距离: 预定义距离度量回调函数 */
REAL	STDCALL distance_e(LPPOINT pA, LPPOINT pB);

BOOL	STDCALL draw_on_screen(REAL, LPPOINT, INT, DWORD);

/* cp_refer		关联函数
 * 功能
 *	关联指定的关联, 并在必要的时候重新关联与指定关联冲突的关联
 * 输入
 *	rTable		关联表
 *	nTable		关联表的大小
 *	cpSrc, nSrc	源控制点
 *	cpDst, nDst	目标控制点
 *	cpDstEx		排斥目标索引集
 *	nDstEx		排斥目标索引集的元数
 *	ref		指定关联的关联点
 *	obj		指定关联的被关联点
 *	dist		关联的距离权值
 *	distProc	度量回调
 * 输出
 *	rTable		修改后的关联表
 * 返回
 *	关联成功返回TRUE, 否则返回FALSE
 */
BOOL	STDCALL	cp_refer(LPPOINTR	rTable,
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
			 DISTANCEPROC	distProc
			 );

/* cp_transform		控制点转换函数
 * 功能
 *	将源控制点集逐渐转换到目标控制点集
 * 输入
 *	cpSrc		源控制点数组
 *	nSrc		源控制点数目
 *	cpDst		目标控制点
 *	nDst		目标控制点数目
 *	sample		转换插值间隔, 定义域(0,1], 越小转换过程越平滑, 默认0.1
 *	distProc	度量方法回调, 默认为欧拉距离
 *	transProc	插值过程回调, 默认为在缺省输出设备上作图
 *	transParam	传递给插值过程回调的参数
 *	relProc		双向关联表检测回调, 默认NULL忽略
 *	relParam	传递给双向关联表检测回调的参数
 *	relDemonstrate	演示关联表构造过程
 * 返回
 *	转换成功TRUE, 否则转换失败
 */
BOOL	STDCALL cp_transform(LPPOINT		cpSrc,
			     INT		nSrc,
			     LPPOINT		cpDst,
			     INT		nDst,
			     REAL		sample		DEFAULT(0.1),
			     DISTANCEPROC	distProc	DEFAULT(distance_e),
			     CPTRANSFORMPROC	transProc	DEFAULT(draw_on_screen),
			     DWORD		transParam	DEFAULT(0),
			     CPRELATIONPROC	relProc		DEFAULT(NULL),
			     DWORD		relParam	DEFAULT(0),
			     BOOL		relDemonstrate	DEFAULT(FALSE),
			     CPREFERPROC	referProc	DEFAULT(cp_refer)
			     );

/* cp_setrefer		设置关联
 * 功能
 *	设置关联点与被关联点(目标点)的关联
 * 输入
 *	rTable		关联表
 *	nTable		关联表中含有的关联数目
 *	ref		关联点索引
 *	obj		被关联点索引
 *	dist		关联的距离
 *	initp		搜索关联表的起点, 用于加速, 默认为从头开始搜索
 * 输出
 *	rTable		设置新的关联后的关联表
 * 返回
 *	设置关联成功TRUE, 否则失败
 */
BOOL	STDCALL cp_setrefer(LPPOINTR	rTable,
			    INT		nTable,
			    INT		ref,
			    INT		obj,
			    REAL	dist,
			    INT		initp		DEFAULT(0)
			    );

/* 返回关联表中实际使用的关联数 */
INT	STDCALL cp_rtcounts(LPPOINTR rTable, INT nTable);


#endif
