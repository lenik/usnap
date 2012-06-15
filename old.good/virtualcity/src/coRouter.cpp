
#include "coRouter.h"

// ��ʼ��
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

// ��Աö�ٺ���
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

		// �� �ڲ������� ��ʱ����Ϊ Ԥ�������������������
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

		// �� �ڲ������� ��ʱ����Ϊ Ԥ������˾��������
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

// ö�ٻص����ú���
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

// Ԥ����ö�ٺ���

/////////////////////////////////////////////////////////////
//
//
//
//
//
	// ��ö�ٺ��� ö������·��, �޹���
	coRet	coRouter::co_path_enumerator(
		const coINT	node_count,
		const coNode_ra	node_seqs,
		const coDATA32	enum_context,
		const solve_t	enum_callback) {
		coRet	r;
		co_setok(r);

		// ��������: ��coGuider::city��ö�پ���node_seqs�����н��
		// ѡ��:����ѡ��ָ���ڵ��˳���ǲ��Ǳ����,
		// ��˳���Ǳ����ʱ�������԰��Žڵ��ȡ����˳��.
		// �Զ�����˳�����������һ�����������.

		//

		return r;
	}
	// ��ö�ٺ��� ö������·��, �й���
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
	// ö�����·��
	coRet	coRouter::co_path_shortest_links(
		const coINT	node_count,
		const coNode_ra	node_seqs,
		const coDATA32	enum_context,
		const filter_t	filter_callback,	// ����ͬ���·����ɸѡ
		const coDATA32	filter_context,
		const solve_t	enum_callback) {
		//
		coRet	r;
		co_setok(r);

		return r;
	}

	// (Ԥ����̾���ö�ٺ���)
	coRet	coRouter::co_path_shortest_dists(
		const coINT	node_count,
		const coNode_ra	node_seqs,
		const coDATA32	enum_context,
		const filter_t	filter_callback,	// ����ͬ���·����ɸѡ
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
	// Ԥ�����޶�·�����������˺���
	coRet	coRouter::co_path_filter_links(
		const coINT	node_count,
		const coNode_ra	node_seqs_to_be_valid,
		const coDATA32	max_delta_links,
		const coRet_r	enum_status
		) {
		static coINT node_seq_count = 0;	// ��ö�ٺ������ܵľ��ɽ����
		static coINT link_count_least = 0;	// ��ʼ�����������������
		coRet	r, r_c;
		co_setok(r);

		if (co_isce(*enum_status)) {			// coerror����
			switch (enum_status->coerror) {
			case coe_start:
				node_seq_count = (coINT)enum_status->data;
				return r;
			case coe_init:
				// ��ʼ��, �����������������˳�����
				// ���ûص�����Ϊ������Ϣ�ص�, ���Ա������������
				r_c = co_path_shortest_links(
					node_seq_count,
					(coNode_ra)enum_status->data,
					(coDATA32)&link_count_least,	// ���ݸ�co_path_save_links��link_count_r
					NULL,				// ���˻ص�
					0,				// ����������
					co_path_save_links
					);
				if (coerror(r_c)) co_seter(r);
				return r;
			case coe_finish:
				// ö����β, �˳�����
				return r;
			}
		}

		// ���� ������������·�� �޶��������� ·��
		if (node_count - link_count_least <= (coINT)max_delta_links) {
			co_setcn(r, coc_accept);
		} else {
			co_setcn(r, coc_deny);
		}

		return r;
	}

	// Ԥ�����޶�·��������˺���
	coRet	coRouter::co_path_filter_dist(
		const coINT	node_count,
		const coNode_ra	node_seqs_to_be_valid,
		const coDATA32	max_delta_dist,
		const coRet_r	enum_status
		) {
		static coINT	node_seq_count = 0;	// ��ö�ٺ������ܵľ��ɽ����
		static coREAL	link_dist_shortest = 0;	// ��ʼ���������̾���
		coRet	r, r_c;
		co_setok(r);

		if (co_isce(*enum_status)) {			// coerror����
			switch (enum_status->coerror) {
			case coe_start:
				node_seq_count = (coINT)enum_status->data;
				return r;
			case coe_init:
				// ��ʼ��, ������̾�����˳�����
				// ���ûص�����Ϊ������Ϣ�ص�, ���Ա�����̾���
				r_c = co_path_shortest_links(
					node_seq_count,
					(coNode_ra)enum_status->data,
					(coDATA32)&link_dist_shortest,	// ���ݸ�co_path_save_dist��link_dist_r
					NULL,				// ���˻ص�
					0,				// ����������
					co_path_save_dist
					);
				if (coerror(r_c)) co_seter(r);
				return r;
			case coe_finish:
				// ö����β, �˳�����
				return r;
			}
		}

		// ���� ������������·�� �޶������ ·��
		// ���㱾·������
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

	// Ԥ�������ջص� / ����·����Ϣ / ����������
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

	// Ԥ�������ջص� / ����·����Ϣ / �������
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

	// Ԥ�������ջص� / ����·����Ϣ / ����������
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
