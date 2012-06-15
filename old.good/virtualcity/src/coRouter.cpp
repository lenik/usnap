
#include "coRouter.h"

// 初始化
	coP	coRouter::coRouter(
		solve_t		init_callback,
		enum_t		init_enumerator,
		enum_filter_t	init_enumerator_with_filter,
		filter_t	init_filter
		) {
	m_enum		= init_enumerator;
	m_enum_filter	= init_enumerator_with_filter;
	m_filter	= init_filter;
	m_callback	= init_callback;
}

// 成员枚举函数
	coSF	coRouter::enumpath(
		coINT		node_count,
		coNode_ra	node_seqs,
		coDATA32	enum_context) {
		coRet	r;
		if (!co_specified(m_enum) || !co_specified(m_callback)) {
			co_seter(r);
			co_setce(r, coe_uninit_enum);
		}
		return m_enum(node_count, node_seqs, enum_context, m_callback);
	}

	coSF	coRouter::enumpath_f(
		coINT		node_count,
		coNode_ra	node_seqs,
		coDATA32	enum_context,
		coDATA32	filter_context
		) {
		coRet	r;
		if (!co_specified(m_enum_filter) || !co_specified(m_callback)) {
			co_seter(r);
			co_setce(r, coe_uninit_enum);
		}

		return m_enum_filter(node_count, node_seqs, enum_context, m_filter, filter_context, m_callback);
	}

	coSF	coRouter::enum_path_limit_links(
		const coINT	node_count,
		const coNode_ra	node_seqs,
		const coINT	max_delta_links
		) {
		coRet	r;
		filter_t old_filter;

		// 将 内部过滤器 临时设置为 预定义过滤连结数过滤器
		old_filter = m_filter;
		m_filter = co_path_filter_links;
		r = enumpath_f(node_count, node_seqs, 0, co_cast(coDATA32)max_delta_links);
		m_filter = old_filter;
		return r;
	}

	coSF	coRouter::enum_path_limit_dists(
		const coINT	node_count,
		const coNode_ra	node_seqs,
		const coREAL	max_delta_dists
		) {
		coRet	r;
		filter_t old_filter;

		// 将 内部过滤器 临时设置为 预定义过滤距离过滤器
		old_filter = m_filter;
		m_filter = co_path_filter_links;
		r = enumpath_f(node_count, node_seqs, 0, co_cast(coDATA32)max_delta_dists);
		m_filter = old_filter;
		return r;
	}

	coSF	coRouter::shortest_path_links(
		const coINT	node_count,
		const coNode_ra	node_seqs,
		const coDATA32	enum_context
		) {
		return enum_path_limit_links(node_count, node_seqs, 0);
	}

	coSF	coRouter::shortest_path_dists(
		const coINT	node_count,
		const coNode_ra	node_seqs,
		const coDATA32	enum_context
		) {
		return enum_path_limit_links(node_count, node_seqs, 0);
	}

// 枚举回调设置函数
	coSF	coRouter::set_enum(enum_t new_enumerator) {
		coRet	r;
		co_setok(r);
		r.avail = co_avail_data_callback;
		r.data = co_cast(coDATA32)m_enum;
		m_enum = new_enumerator;
		return r;
	}

	coSF	coRouter::set_enum_filter(enum_filter_t new_enumerator_with_filter) {
		coRet	r;
		co_setok(r);
		r.avail = co_avail_data_callback;
		r.data = co_cast(coDATA32)m_enum_filter;
		m_enum_filter = new_enumerator_with_filter;
		return r;
	}

	coSF	coRouter::set_filter(filter_t new_filter) {
		coRet	r;
		co_setok(r);
		r.avail = co_avail_data_callback;
		r.data = co_cast(coDATA32)m_filter;
		m_filter = new_filter;
		return r;
	}

	coSF	coRouter::set_callback(solve_t new_callback) {
		coRet	r;
		co_setok(r);
		r.avail = co_avail_data_callback;
		r.data = co_cast(coDATA32)m_callback;
		m_callback = new_callback;
		return r;
	}

// 预定义枚举函数

/////////////////////////////////////////////////////////////
//
//
//
//
//
	// 主枚举函数 枚举所有路径, 无过滤
	coRet	coRouter::co_path_enumerator(
		const coINT	node_count,
		const coNode_ra	node_seqs,
		const coDATA32	enum_context,
		const solve_t	enum_callback) {
		coRet	r;
		co_setok(r);

		// 基本任务: 从coGuider::city中枚举经过node_seqs的所有结点
		// 选项:可以选择指定节点的顺序是不是必需的,
		// 当顺序不是必需的时候程序可以安排节点获取最优顺序.
		// 自动计算顺序可以在另外一个过程中完成.

		//

		return r;
	}
	// 主枚举函数 枚举所有路径, 有过滤
	coRet	coRouter::co_path_enumerator_f(
		const coINT	node_count,
		const coNode_ra	node_seqs,
		const coDATA32	enum_context,
		const filter_t	filter_callback,
		const coDATA32	filter_context,
		const solve_t	enum_callback) {
		coRet	r;
		co_setok(r);

		// ......
		return r;
	}
	// 枚举最短路径
	coRet	coRouter::co_path_shortest_links(
		const coINT	node_count,
		const coNode_ra	node_seqs,
		const coDATA32	enum_context,
		const filter_t	filter_callback,	// 对相同最短路径的筛选
		const coDATA32	filter_context,
		const solve_t	enum_callback) {
		//
		coRet	r;
		co_setok(r);

		return r;
	}

	// (预置最短距离枚举函数)
	coRet	coRouter::co_path_shortest_dists(
		const coINT	node_count,
		const coNode_ra	node_seqs,
		const coDATA32	enum_context,
		const filter_t	filter_callback,	// 对相同最短路径的筛选
		const coDATA32	filter_context,
		const solve_t	enum_callback) {
		//
		coRet	r;
		co_setok(r);

		return r;
	}

//
//
//
//
//
/////////////////////////////////////////////////////////////
	// 预定义限定路径连结数过滤函数
	coRet	coRouter::co_path_filter_links(
		const coINT	node_count,
		const coNode_ra	node_seqs_to_be_valid,
		const coDATA32	max_delta_links,
		const coRet_r	enum_status
		) {
		static coINT node_seq_count = 0;	// 主枚举函数接受的经由结点数
		static coINT link_count_least = 0;	// 初始化保存的最少连结数
		coRet	r, r_c;
		co_setok(r);

		if (co_isce(*enum_status)) {			// coerror可用
			switch (enum_status->coerror) {
			case coe_start:
				node_seq_count = (coINT)enum_status->data;
				return r;
			case coe_init:
				// 初始化, 计算最少连结数后退出过滤
				// 设置回调函数为保存信息回调, 用以保存最短连结数
				r_c = co_path_shortest_links(
					node_seq_count,
					(coNode_ra)enum_status->data,
					(coDATA32)&link_count_least,	// 传递给co_path_save_links的link_count_r
					NULL,				// 过滤回调
					0,				// 过滤上下文
					co_path_save_links
					);
				if (coerror(r_c)) co_seter(r);
				return r;
			case coe_finish:
				// 枚举收尾, 退出过滤
				return r;
			}
		}

		// 过滤 超出最少连结路径 限定连结数的 路径
		if (node_count - link_count_least <= (coINT)max_delta_links) {
			co_setcn(r, coc_accept);
		} else {
			co_setcn(r, coc_deny);
		}

		return r;
	}

	// 预定义限定路径距离过滤函数
	coRet	coRouter::co_path_filter_dist(
		const coINT	node_count,
		const coNode_ra	node_seqs_to_be_valid,
		const coDATA32	max_delta_dist,
		const coRet_r	enum_status
		) {
		static coINT	node_seq_count = 0;	// 主枚举函数接受的经由结点数
		static coREAL	link_dist_shortest = 0;	// 初始化保存的最短距离
		coRet	r, r_c;
		co_setok(r);

		if (co_isce(*enum_status)) {			// coerror可用
			switch (enum_status->coerror) {
			case coe_start:
				node_seq_count = (coINT)enum_status->data;
				return r;
			case coe_init:
				// 初始化, 计算最短距离后退出过滤
				// 设置回调函数为保存信息回调, 用以保存最短距离
				r_c = co_path_shortest_links(
					node_seq_count,
					(coNode_ra)enum_status->data,
					(coDATA32)&link_dist_shortest,	// 传递给co_path_save_dist的link_dist_r
					NULL,				// 过滤回调
					0,				// 过滤上下文
					co_path_save_dist
					);
				if (coerror(r_c)) co_seter(r);
				return r;
			case coe_finish:
				// 枚举收尾, 退出过滤
				return r;
			}
		}

		// 过滤 超出最少连结路径 限定距离的 路径
		// 计算本路径距离
		coREAL	link_dist_current = 0;
		for (int i = 0; i < node_count - 1; i++) {
			link_dist_current +=
				node_seqs_to_be_valid[i + 1]->disto(
					*(node_seqs_to_be_valid[i])
				);
		}

		if (link_dist_current - link_dist_shortest <= (coREAL)max_delta_dist) {
			co_setcn(r, coc_accept);
		} else {
			co_setcn(r, coc_deny);
		}

		return r;
	}

	// 预定义最终回调 / 保存路径信息 / 保存连结数
	coRet	coRouter::co_path_save_links(
		const coINT	node_count,
		const coNode_ra	node_seqs_to_be_processed,
		const coDATA32	link_count_r,
		const coRet_r	enum_status
		) {
		coRet	r;

		*((coINT_r)link_count_r) = node_count;
		co_setok(r);
		co_setcn(r, coc_continue);
		return r;
	}

	// 预定义最终回调 / 保存路径信息 / 保存距离
	coRet	coRouter::co_path_save_dist(
		const coINT	node_count,
		const coNode_ra	node_seqs_to_be_processed,
		const coDATA32	link_dist_r,
		const coRet_r	enum_status
		) {
		coRet	r;
		coREAL	node_seqs_dist = 0;

		for (int i = 0; i < node_count; i++) {
			node_seqs_dist +=
				node_seqs_to_be_processed[i + 1]->disto(
					*(node_seqs_to_be_processed[i])
				);
		}
		*((coREAL_r)link_dist_r) = node_seqs_dist;
		co_setok(r);
		co_setcn(r, coc_continue);
		return r;
	}

	// 预定义最终回调 / 保存路径信息 / 保存结点序列
	coRet	coRouter::co_path_save_nodes_seq(
		const coINT	node_count,
		const coNode_ra	node_seqs_to_be_processed,
		const coDATA32	*node_ra_r,
		const coRet_r	enum_status
		) {
		coRet	r;

		*((coNode_ra *)node_ra_r) = node_seqs_to_be_processed;
		co_setok(r);
		co_setcn(r, coc_continue);
		return r;
	}
