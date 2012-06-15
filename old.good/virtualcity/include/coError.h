
#pragma once

#include "coType.h"

// �������
	enum co_tag_type(coRetError) {
		coe_none = 0,

		// com����
		coe_not_existed_node,
		coe_not_existed_link,
		coe_not_existed_path,
		coe_not_existed_map,
		coe_not_existed_city,

		coe_not_existed_guider,

		// ���ô���
		coe_uninit_enum,

		// ��Ϣ

		// ������Ϣ
		coe_start,
		coe_init,
		coe_try,
		coe_retry,
		coe_finish,
		coe_exit,
		// ������Ϣ
		coe_processed,
		coe_skipped
	};
	co_def_type(co_tag_type(coRetError), coRetError);

// ���Ƴ���
	enum co_tag_type(coRetControl) {
		// �������� (��׼)
		coc_continue,				// N2 = N1 + 1
		coc_break,				// ����
		coc_errorbreak,				// ���� (��Ϊ����)
		// �������� (��չ)
		coc_previous,				// N2 = N1 - 1
		coc_again,				// N2 = N1
		coc_skip,				// N2 = N2 + 2
		coc_skips,				// N2 = N2 + data + 1
		coc_home,				// �ֲ�ʼ
		coc_end,				// �ֲ�β
		coc_first,				// ʼ
		coc_last,				// β
		coc_before_first,			// ��Խ�Ͻ�
		coc_after_last,				// ��Խ�½�
		// ����״̬
		coc_query,				// ѯ���Ƿ����
		coc_accept,				// ����
		coc_deny, 				// �ܾ�
		coc_casual, 				// �����޷�ȷ��
		coc_unknown				// δ֪
	};
	co_def_type(co_tag_type(coRetControl), coRetControl);

struct co_tag_type(coErrorHash) {
	coRetError		coerror;
	coSTR			info;
};
extern co_tag_type(coErrorHash)	co_error_hash[];
