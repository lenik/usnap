
//	COM\理论模型
//	2000.12.6

#pragma once

#include "coType.h"

// 基本对象
co_struct(coNode);				// 简单结点
co_struct(coLink);				// 连结
co_struct(coPath);				// 路
co_struct(coPlat);				// 地图

// 基本对象集接口

template<class oTYPE>
interface coISets : coSet<oTYPE> {
};

co_def_type(coISets<coNode>,	coNodes);
co_def_type(coISets<coLink>,	coLinks);
co_def_type(coISets<coPath>,	coPaths);

// 结点结构
struct coNode {
	coString	name;
	coPT3		pos;
	// 被参考缓冲
	coINT		link_refs_count;
	coLink_ra	link_refs;
public:
	// 运算
	coVF(coNode&)	operator =  (const coNode&);
	coVF(coNode&)	operator += (const coNode&);
	coVF(coNode&)	operator -= (const coNode&);
	coVF(coNode)	operator +  (const coNode&) const;
	coVF(coNode)	operator -  (const coNode&) const;

	coVF(coREAL)	disto() const;
	coVF(coREAL)	disto(const coNode&) const;

	// 比较
	coVF(coBOOL)	operator == (const coNode&) const;
	// 结点被参考
	coVF(coBOOL)	be_refered_by(const coLink_r link_ref) const;
	coVF(coBOOL)	be_refered_by(const coPath_r path_ref) const;

	// 坐标分量索引形式
	coVF(coREAL)	operator [] (const coINT xyz_index) const;
	coVF(coREAL&)	operator [] (const coINT xyz_index);

public:
	coP		coNode() {}
	coP		coNode(const coNode& o_o) { *this = o_o; }
	coP		coNode(const coREAL x, const coREAL y, const coREAL z) : link_refs_count(0) { pos.x = x; pos.y = y; pos.z = z; }
	coVP		~coNode() {}
};

// 连结结构
struct coLink {
	coString	name;
	coINT		nodes_seq_count;
	coNode_ra	nodes_seq;
	coBOOL		directed;

public:
	coVF(coREAL)	length() const;

public:
	// 连结参考了结点
	coVF(coBOOL)	refered(const coNode_r node_ref) const;
	// 连结被参考
	coVF(coBOOL)	be_refered_by(const coPath_r path_ref) const;
	// 查找结点
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

// 路径结构
struct coPath {
	coString	name;
	coINT		links_count;
	coLink_ra	links;

public:
	// 路参考了结点
	coVF(coBOOL)	refered(const coNode_r node_ref) const;
	// 路参考了连结
	coVF(coBOOL)	refered(const coLink_r link_ref) const;
	// 查找连结
	coVF(coLink_ra)	link_at(const coLink_r link_query) const;

	coVF(coPath&)	operator = (const coPath&);

	coVF(coLink_r)	operator [] (const coINT link_index) const;
	coVF(coLink_r&)	operator [] (const coINT link_index);

public:
	coP		coPath() : links_count(0) {}
	coP		coPath(const coPath& o_o) { *this = o_o; }
	coVP		~coPath();
};

// 地图结构
struct coPlat {
	coString	name;
	coINT		paths_count;
	coPath_ra	paths;

public:

//	COM\表达模型

// 表达结点, 可以是区域
interface coNode_exp;
interface coLink_exp;

interface coUtil; 				// 杂物
interface coCity; 				// 城市

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
