
//	COM\导游模型\路线枚举
//	2000.12.6

#pragma once

#include "coGuider.h"

//
// 枚举函数通过enum_status向过滤回调和用户回调传递枚举状态,
// 当 co_isce 且 cook 时表示状态信息有效
//	*coerror*	*含义*		*data*
//	coe_start	枚举开始	coINT node_count	(传递给过滤函数经由结点数)
//	coe_init	初始化枚举	coNode_ra node_seqs	(传递给过滤函数经由结点)
//	coe_try		枚举进行
//	coe_finish	收尾枚举
//	coe_exit	枚举退出
//
// 枚举过滤回调通过 co_setok 和 co_setcn 设置过滤结果,
//	*control*	*含义*		*data*
//	coc_accept	枚举被接受
//	coc_deny	枚举被否决
//
// 用户最终会调可以通过设置 co_setok 和 co_setcn 决定枚举的进行流程,
//	*control*	*含义*		*data*
//	coc_next	下一个
//	coc_break	跳出
//

class coRouter : public coGuider {

	// 回调类型声明

	// 过滤回调函数, 对一个枚举结果进行过滤
	typedef coRet (*filter_t)(
		const coINT	node_count,			// 待认可结点序列数
		const coNode_ra	node_seqs_to_be_valid,		// 待认可结点
		const coDATA32	filter_context,			// 过滤上下文
		const coRet_r	enum_status			// 枚举状态
		);
	// 接口回调函数, 应用程序可以对一个最终结果进行处理
	typedef coRet (*solve_t)(
		const coINT	node_count,			// 最终路线结点数
		const coNode_ra	node_seqs_to_be_processed,	// 最终路线结点序列
		const coDATA32	enum_context,			// 枚举上下文
		const coRet_r	enum_status			// 枚举状态
		);
	// 枚举回调函数, 对指定的结点序列进行枚举, 无过滤
	typedef coRet (*enum_t)(
		const coINT	node_count,			// 指定经由结点数
		const coNode_ra	node_seqs,			// 指定经由结点序列
		const coDATA32	enum_context,			// 传递枚举上下文
		const solve_t	enum_callback			// 最终回调
		);
	// 枚举回调函数, 对指定的结点序列进行枚举, 并回调过滤函数
	typedef coRet (*enum_filter_t)(
		const coINT	node_count,			// 指定经由结点数
		const coNode_ra	node_seqs,			// 指定经由结点序列
		const coDATA32	enum_context,			// 传递枚举上下文
		const filter_t	filter_callback,		// 过滤器回调
		const coDATA32	filter_context,			// 传递过滤器回调上下文
		const solve_t	enum_callback			// 最终回调
		);

	// 内部枚举函数
	enum_t		m_enum;					// 内部枚举函数
	enum_filter_t	m_enum_filter;				// 内部带过滤枚举函数
	filter_t	m_filter;				// 内部过滤函数
	solve_t		m_callback;				// 内部接口回调函数
public:
	// 包装函数

	// 枚举 经由结点序列的 所有路径
	coSVF		enumpath(
		const coINT	node_count,			// 指定经由结点数
		const coNode_ra	node_seqs,			// 指定经由结点序列
		const coDATA32	enum_context			// 枚举上下文
		);
	// 枚举 经由结点序列并通过过滤的 所有路径
	coSVF		enumpath_f(
		const coINT	node_count,			// 指定经由结点数
		const coNode_ra	node_seqs,			// 指定经由结点序列
		const coDATA32	enum_context, 			// 枚举上下文
		const coDATA32	filter_context			// 过滤上下文
		);
	// 枚举 超过最少结点路径 限定连结数的 所有路径		*特例*
	coSVF		enum_path_limit_links(
		const coINT	node_count, 			// 指定经由结点数
		const coNode_ra	node_seqs, 			// 指定经由结点序列
		const coINT	max_delta_links			// 限定连结数
		);
	// 枚距 超过最短距离路径 限定距离的 所有路径		*特例*
	coSVF		enum_path_limit_dists(
		const coINT	node_count, 			// 指定经由结点数
		const coNode_ra	node_seqs, 			// 指定经由结点序列
		const coREAL	max_delta_dists			// 限定距离
		);
	// 具有 最少结点的 路径					*特例* *取一*
	coSVF		shortest_path_links(
		const coINT	node_count, 			// 指定经由结点数
		const coNode_ra	node_seqs, 			// 指定经由结点序列
		const coDATA32	enum_context			// 枚举上下文
		);
	// 具有 最短距离的 路径					*特例* *取一*
	coSVF		shortest_path_dists(
		const coINT	node_count,  			// 指定经由结点数
		const coNode_ra	node_seqs, 			// 指定经由结点序列
		const coDATA32	enum_context			// 枚举上下文
		);
public:
	coSVF		set_enum(enum_t);			// 设置无过滤枚举回调
	coSVF		set_enum_filter(enum_filter_t);		// 设置带过滤枚聚回调
	coSVF		set_filter(filter_t);			// 设置过滤器
	coSVF		set_callback(solve_t);			// 设置最终回调
public:
	coRouter(
		solve_t		init_callback = NULL,		// 初始化最终回调
		enum_t		init_enum = NULL,		// 初始化无过滤回调
		enum_filter_t	init_enum_filter = NULL,	// 初始化带过滤回调
		filter_t	init_filter = NULL		// 初始化过滤器
		);

public:
	// 预定义无过滤枚举
	static coRet	co_path_enumerator(	const coINT	node_count,
						const coNode_ra	node_seqs,
						const coDATA32	enum_context,
						const solve_t	enum_callback);
	// 预定义有过滤枚举
	static coRet	co_path_enumerator_f(	const coINT	node_count,
						const coNode_ra	node_seqs,
						const coDATA32	enum_context,
						const filter_t	filter_callback,
						const coDATA32	filter_context,
						const solve_t	enum_callback);
	// 预定义枚举 / 连结条件优化
	static coRet	co_path_shortest_links(	const coINT	node_count,
						const coNode_ra	node_seqs,
						const coDATA32	num_context,
						const filter_t	filter_callback,
						const coDATA32	filter_context,
						const solve_t	enum_callback);
	// 预定义枚举 / 距离条件优化
	static coRet	co_path_shortest_dists(	const coINT	node_count,
						const coNode_ra	node_seqs,
						const coDATA32	enum_context,
						const filter_t	filter_callback,
						const coDATA32	filter_context,
						const solve_t	enum_callback);
	// 预定义过滤器 / 过滤连结条件
	static coRet	co_path_filter_links(	const coINT	node_count,
						const coNode_ra	node_seqs_to_be_valid,
						const coDATA32	max_delta_links,
						const coRet_r	enum_status);
	// 预定义过滤器 / 过滤距离条件
	static coRet	co_path_filter_dist(	const coINT	node_count,
						const coNode_ra	node_seqs_to_be_valid,
						const coDATA32	max_delta_dist,
						const coRet_r	enum_status);
	// 预定义最终回调 / 保存路径信息 / 保存连结数
	static coRet	co_path_save_links(	const coINT	node_count,
						const coNode_ra	node_seqs_to_be_processed,
						const coDATA32	link_count_r,
						const coRet_r	enum_status);
	// 预定义最终回调 / 保存路径信息 / 保存距离
	static coRet	co_path_save_dist(	const coINT	node_count,
						const coNode_ra	node_seqs_to_be_processed,
						const coDATA32	link_dist_r,
						const coRet_r	enum_status);
	// 预定义最终回调 / 保存路径信息 / 保存结点序列
	static coRet	co_path_save_nodes_seq(	const coINT	node_count,
						const coNode_ra	node_seqs_to_be_processed,
						const coDATA32	*node_ra_r,
						const coRet_r	enum_status);
};
