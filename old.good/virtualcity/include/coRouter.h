
//	COM\����ģ��\·��ö��
//	2000.12.6

#pragma once

#include "coGuider.h"

//
// ö�ٺ���ͨ��enum_status����˻ص����û��ص�����ö��״̬,
// �� co_isce �� cook ʱ��ʾ״̬��Ϣ��Ч
//	*coerror*	*����*		*data*
//	coe_start	ö�ٿ�ʼ	coINT node_count	(���ݸ����˺������ɽ����)
//	coe_init	��ʼ��ö��	coNode_ra node_seqs	(���ݸ����˺������ɽ��)
//	coe_try		ö�ٽ���
//	coe_finish	��βö��
//	coe_exit	ö���˳�
//
// ö�ٹ��˻ص�ͨ�� co_setok �� co_setcn ���ù��˽��,
//	*control*	*����*		*data*
//	coc_accept	ö�ٱ�����
//	coc_deny	ö�ٱ����
//
// �û����ջ������ͨ������ co_setok �� co_setcn ����ö�ٵĽ�������,
//	*control*	*����*		*data*
//	coc_next	��һ��
//	coc_break	����
//

class coRouter : public coGuider {

	// �ص���������

	// ���˻ص�����, ��һ��ö�ٽ�����й���
	typedef coRet (*filter_t)(
		const coINT	node_count,			// ���Ͽɽ��������
		const coNode_ra	node_seqs_to_be_valid,		// ���Ͽɽ��
		const coDATA32	filter_context,			// ����������
		const coRet_r	enum_status			// ö��״̬
		);
	// �ӿڻص�����, Ӧ�ó�����Զ�һ�����ս�����д���
	typedef coRet (*solve_t)(
		const coINT	node_count,			// ����·�߽����
		const coNode_ra	node_seqs_to_be_processed,	// ����·�߽������
		const coDATA32	enum_context,			// ö��������
		const coRet_r	enum_status			// ö��״̬
		);
	// ö�ٻص�����, ��ָ���Ľ�����н���ö��, �޹���
	typedef coRet (*enum_t)(
		const coINT	node_count,			// ָ�����ɽ����
		const coNode_ra	node_seqs,			// ָ�����ɽ������
		const coDATA32	enum_context,			// ����ö��������
		const solve_t	enum_callback			// ���ջص�
		);
	// ö�ٻص�����, ��ָ���Ľ�����н���ö��, ���ص����˺���
	typedef coRet (*enum_filter_t)(
		const coINT	node_count,			// ָ�����ɽ����
		const coNode_ra	node_seqs,			// ָ�����ɽ������
		const coDATA32	enum_context,			// ����ö��������
		const filter_t	filter_callback,		// �������ص�
		const coDATA32	filter_context,			// ���ݹ������ص�������
		const solve_t	enum_callback			// ���ջص�
		);

	// �ڲ�ö�ٺ���
	enum_t		m_enum;					// �ڲ�ö�ٺ���
	enum_filter_t	m_enum_filter;				// �ڲ�������ö�ٺ���
	filter_t	m_filter;				// �ڲ����˺���
	solve_t		m_callback;				// �ڲ��ӿڻص�����
public:
	// ��װ����

	// ö�� ���ɽ�����е� ����·��
	coSVF		enumpath(
		const coINT	node_count,			// ָ�����ɽ����
		const coNode_ra	node_seqs,			// ָ�����ɽ������
		const coDATA32	enum_context			// ö��������
		);
	// ö�� ���ɽ�����в�ͨ�����˵� ����·��
	coSVF		enumpath_f(
		const coINT	node_count,			// ָ�����ɽ����
		const coNode_ra	node_seqs,			// ָ�����ɽ������
		const coDATA32	enum_context, 			// ö��������
		const coDATA32	filter_context			// ����������
		);
	// ö�� �������ٽ��·�� �޶��������� ����·��		*����*
	coSVF		enum_path_limit_links(
		const coINT	node_count, 			// ָ�����ɽ����
		const coNode_ra	node_seqs, 			// ָ�����ɽ������
		const coINT	max_delta_links			// �޶�������
		);
	// ö�� ������̾���·�� �޶������ ����·��		*����*
	coSVF		enum_path_limit_dists(
		const coINT	node_count, 			// ָ�����ɽ����
		const coNode_ra	node_seqs, 			// ָ�����ɽ������
		const coREAL	max_delta_dists			// �޶�����
		);
	// ���� ���ٽ��� ·��					*����* *ȡһ*
	coSVF		shortest_path_links(
		const coINT	node_count, 			// ָ�����ɽ����
		const coNode_ra	node_seqs, 			// ָ�����ɽ������
		const coDATA32	enum_context			// ö��������
		);
	// ���� ��̾���� ·��					*����* *ȡһ*
	coSVF		shortest_path_dists(
		const coINT	node_count,  			// ָ�����ɽ����
		const coNode_ra	node_seqs, 			// ָ�����ɽ������
		const coDATA32	enum_context			// ö��������
		);
public:
	coSVF		set_enum(enum_t);			// �����޹���ö�ٻص�
	coSVF		set_enum_filter(enum_filter_t);		// ���ô�����ö�ۻص�
	coSVF		set_filter(filter_t);			// ���ù�����
	coSVF		set_callback(solve_t);			// �������ջص�
public:
	coRouter(
		solve_t		init_callback = NULL,		// ��ʼ�����ջص�
		enum_t		init_enum = NULL,		// ��ʼ���޹��˻ص�
		enum_filter_t	init_enum_filter = NULL,	// ��ʼ�������˻ص�
		filter_t	init_filter = NULL		// ��ʼ��������
		);

public:
	// Ԥ�����޹���ö��
	static coRet	co_path_enumerator(	const coINT	node_count,
						const coNode_ra	node_seqs,
						const coDATA32	enum_context,
						const solve_t	enum_callback);
	// Ԥ�����й���ö��
	static coRet	co_path_enumerator_f(	const coINT	node_count,
						const coNode_ra	node_seqs,
						const coDATA32	enum_context,
						const filter_t	filter_callback,
						const coDATA32	filter_context,
						const solve_t	enum_callback);
	// Ԥ����ö�� / ���������Ż�
	static coRet	co_path_shortest_links(	const coINT	node_count,
						const coNode_ra	node_seqs,
						const coDATA32	num_context,
						const filter_t	filter_callback,
						const coDATA32	filter_context,
						const solve_t	enum_callback);
	// Ԥ����ö�� / ���������Ż�
	static coRet	co_path_shortest_dists(	const coINT	node_count,
						const coNode_ra	node_seqs,
						const coDATA32	enum_context,
						const filter_t	filter_callback,
						const coDATA32	filter_context,
						const solve_t	enum_callback);
	// Ԥ��������� / ������������
	static coRet	co_path_filter_links(	const coINT	node_count,
						const coNode_ra	node_seqs_to_be_valid,
						const coDATA32	max_delta_links,
						const coRet_r	enum_status);
	// Ԥ��������� / ���˾�������
	static coRet	co_path_filter_dist(	const coINT	node_count,
						const coNode_ra	node_seqs_to_be_valid,
						const coDATA32	max_delta_dist,
						const coRet_r	enum_status);
	// Ԥ�������ջص� / ����·����Ϣ / ����������
	static coRet	co_path_save_links(	const coINT	node_count,
						const coNode_ra	node_seqs_to_be_processed,
						const coDATA32	link_count_r,
						const coRet_r	enum_status);
	// Ԥ�������ջص� / ����·����Ϣ / �������
	static coRet	co_path_save_dist(	const coINT	node_count,
						const coNode_ra	node_seqs_to_be_processed,
						const coDATA32	link_dist_r,
						const coRet_r	enum_status);
	// Ԥ�������ջص� / ����·����Ϣ / ����������
	static coRet	co_path_save_nodes_seq(	const coINT	node_count,
						const coNode_ra	node_seqs_to_be_processed,
						const coDATA32	*node_ra_r,
						const coRet_r	enum_status);
};
