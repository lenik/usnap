
//	COM\����ģ��
//	2000.12.6

#pragma once

#include "coType.h"

// ��������
co_struct(coNode);				// �򵥽��
co_struct(coLink);				// ����
co_struct(coPath);				// ·
co_struct(coPlat);				// ��ͼ

// �������󼯽ӿ�

template<class oTYPE>
interface coISets : coSet<oTYPE> {
};

co_def_type(coISets<coNode>,	coNodes);
co_def_type(coISets<coLink>,	coLinks);
co_def_type(coISets<coPath>,	coPaths);

// ���ṹ
struct coNode {
	coString	name;
	coPT3		pos;
	// ���ο�����
	coINT		link_refs_count;
	coLink_ra	link_refs;
public:
	// ����
	coVF(coNode&)	operator =  (const coNode&);
	coVF(coNode&)	operator += (const coNode&);
	coVF(coNode&)	operator -= (const coNode&);
	coVF(coNode)	operator +  (const coNode&) const;
	coVF(coNode)	operator -  (const coNode&) const;

	coVF(coREAL)	disto() const;
	coVF(coREAL)	disto(const coNode&) const;

	// �Ƚ�
	coVF(coBOOL)	operator == (const coNode&) const;
	// ��㱻�ο�
	coVF(coBOOL)	be_refered_by(const coLink_r link_ref) const;
	coVF(coBOOL)	be_refered_by(const coPath_r path_ref) const;

	// �������������ʽ
	coVF(coREAL)	operator [] (const coINT xyz_index) const;
	coVF(coREAL&)	operator [] (const coINT xyz_index);

public:
	coP		coNode() {}
	coP		coNode(const coNode& o_o) { *this = o_o; }
	coP		coNode(const coREAL x, const coREAL y, const coREAL z) : link_refs_count(0) { pos.x = x; pos.y = y; pos.z = z; }
	coVP		~coNode() {}
};

// ����ṹ
struct coLink {
	coString	name;
	coINT		nodes_seq_count;
	coNode_ra	nodes_seq;
	coBOOL		directed;

public:
	coVF(coREAL)	length() const;

public:
	// ����ο��˽��
	coVF(coBOOL)	refered(const coNode_r node_ref) const;
	// ���ᱻ�ο�
	coVF(coBOOL)	be_refered_by(const coPath_r path_ref) const;
	// ���ҽ��
	coVF(coNode_ra)	node_at(const coNode_r node_query) const;

	coVF(coLink& )	operator = (const coLink&);

	coVF(coNode_r)	operator [] (const coINT node_index) const;
	coVF(coNode_r&)	operator [] (const coINT node_index);

public:
	coP		coLink();
	coP		coLink(const coLink& o_o) { *this = o_o; }
	coP		coLink(const coNode_r n1, const coNode_r n2, const coBOOL init_directed = coFALSE);
	coVP		~coLink();
};

// ·���ṹ
struct coPath {
	coString	name;
	coINT		links_count;
	coLink_ra	links;

public:
	// ·�ο��˽��
	coVF(coBOOL)	refered(const coNode_r node_ref) const;
	// ·�ο�������
	coVF(coBOOL)	refered(const coLink_r link_ref) const;
	// ��������
	coVF(coLink_ra)	link_at(const coLink_r link_query) const;

	coVF(coPath&)	operator = (const coPath&);

	coVF(coLink_r)	operator [] (const coINT link_index) const;
	coVF(coLink_r&)	operator [] (const coINT link_index);

public:
	coP		coPath() : links_count(0) {}
	coP		coPath(const coPath& o_o) { *this = o_o; }
	coVP		~coPath();
};

// ��ͼ�ṹ
struct coPlat {
	coString	name;
	coINT		paths_count;
	coPath_ra	paths;

public:

//	COM\���ģ��

// �����, ����������
interface coNode_exp;
interface coLink_exp;

interface coUtil; 				// ����
interface coCity; 				// ����

co_type(coNode_exp);
co_type(coLink_exp);

interface coNode_exp : coNode {
	enum {
		coShape_circle,
		coShape_complex
	}		node_shape;
	coINT		node_shape_data_size;
	coINT_a		node_shape_data;
};

interface coLink_exp : coLink {
	enum {
		coLinkShape_line,
		coLinkShape_arc,
		coLinkShape_freeline
	}		link_shape;
	coINT		link_shape_data_size;
	coINT_a		link_shape_data;
};
