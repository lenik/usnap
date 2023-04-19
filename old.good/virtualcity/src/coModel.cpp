

#include "coModel.h"

////////////////////////////////////////////////////////////////////////////////
// 理论模型


// 结点

coF(coNode&)	coNode::operator =  (const coNode& o_o) {
	if (this == &o_o) return *this;

	co_dela(link_refs);
	co_new(link_refs, coLink_r[o_o.link_refs_count]) {
		link_refs_count = o_o.link_refs_count;
		memcpy(link_refs, o_o.link_refs, sizeof(coLink_r) * link_refs_count);
	}
	return *this;
}

coF(coNode&)	coNode::operator += (const coNode& n) {
	pos += n.pos;
	return *this;
}

coF(coNode&)	coNode::operator -= (const coNode& n) {
	pos -= n.pos;
	return *this;
}

coF(coNode)	coNode::operator +  (const coNode& n) const {
	coNode r = *this;
	r += n;
	return r;
}

coF(coNode)	coNode::operator -  (const coNode& n) const {
	coNode r = *this;
	r -= n;
	return r;
}

coF(coREAL)	coNode::disto() const {
	return pos.disto();
}

coF(coREAL)	coNode::disto(const coNode& n) const {
	return pos.disto(n.pos);
}

coF(coBOOL)	coNode::operator == (const coNode& n) const {
	coBOOL r = coFALSE;
	if (this == &n) return coTRUE;
	r = memcmp(this, &n, sizeof(coLink_r) * link_refs_count) == 0;
	return !r;
}

coF(coBOOL)	coNode::be_refered_by(const coLink_r link_ref) const {
	coBOOL r = coFALSE;
	for (int i = 0; i < link_refs_count; i++) {
		if (link_refs[i] == link_ref) r = coTRUE;
		break;
	}
	return r;
}

coF(coBOOL)	coNode::be_refered_by(const coPath_r path_ref) const {
	coBOOL r = coFALSE;
	for (int i = 0; i < link_refs_count; i++) {
		if (path_ref->refered(link_refs[i])) {
			r = coTRUE;
			break;
		}
	}
	return r;
}

coF(coREAL)	coNode::operator [] (const coINT xyz_index) const {
	co_ASSERT(xyz_index >= 0 && xyz_index <= 2);
	switch (xyz_index) {
	case 0: return pos.x;
	case 1: return pos.y;
	case 2: return pos.z;
	}
	coA return pos.x;
}

coF(coREAL&)	coNode::operator [] (const coINT xyz_index) {
	co_ASSERT(xyz_index >= 0 && xyz_index <= 2);
	switch (xyz_index) {
	case 0: return pos.x;
	case 1: return pos.y;
	case 2: return pos.z;
	}
	coA return pos.x;
}

// 连结

coP		coLink::coLink() {
	co_new(nodes_seq, coNode_r[2]) {
		nodes_seq[0] = NULL;
		nodes_seq[1] = NULL;
		nodes_seq_count = 2;
		directed = FALSE;
	}
}

coP		coLink::coLink(const coNode_r n1,
			       const coNode_r n2,
			       const coBOOL init_directed) {
	coLink();
	if (nodes_seq_count == 2) {
		nodes_seq[0] = n1;
		nodes_seq[1] = n2;
		directed = init_directed;
	} else {
		co_new(nodes_seq, coNode_r[2]) {
			nodes_seq[0] = n1;
			nodes_seq[1] = n2;
			nodes_seq_count = 2;
			directed = init_directed;
		}
	}
}

coP		coLink::~coLink() {
	if (nodes_seq_count != 0) co_dela(nodes_seq);
}

coF(coREAL)	coLink::length() const {
	coREAL link_length = 0;
	for (int i = 1; i < nodes_seq_count; i++) {
		link_length += nodes_seq[i]->disto(*nodes_seq[i - 1]);
	}
	return link_length;
}

coF(coBOOL)	coLink::refered(const coNode_r node_ref) const {
	coBOOL r = coFALSE;
	for (int i = 0; i < nodes_seq_count; i++) {
		if (nodes_seq[i] == node_ref) {
			r = coTRUE;
			break;
		}
	}
	return r;
}

coF(coBOOL)	coLink::be_refered_by(const coPath_r path_ref) const {
	return path_ref->refered((const coLink_r)this);
}

// 查找结点表中第一次出现node_query的位置
coF(coNode_ra)	coLink::node_at(const coNode_r node_query) const {
	coNode_ra r = NULL;
	if (refered(node_query)) {
		for (int i = 0; i < nodes_seq_count; i++) {
			if (nodes_seq[i] == node_query) {
				r = nodes_seq + i;
				break;
			}
		}
	}
	return r;
}

coF(coLink&)	coLink::operator =  (const coLink& o_o) {
	if (this == &o_o) return *this;

	co_dela(nodes_seq);
	co_new(nodes_seq, coNode_r[o_o.nodes_seq_count]) {
		memcpy(nodes_seq, o_o.nodes_seq, sizeof(coNode_r) * o_o.nodes_seq_count);
		nodes_seq_count = o_o.nodes_seq_count;
		name = o_o.name;
	}
	return *this;
}

coF(coNode_r)	coLink::operator [] (const coINT node_index) const {
	co_ASSERT(node_index >= 0 && node_index < nodes_seq_count);
	return nodes_seq[node_index];
}

coF(coNode_r&)	coLink::operator [] (const coINT node_index) {
	co_ASSERT(node_index >= 0 && node_index < nodes_seq_count);
	return nodes_seq[node_index];
}

// 路

coP		coPath::~coPath() {
	if (links_count != 0) co_dela(links);
}

coF(coBOOL)	coPath::refered(const coNode_r node_ref) const {
	coBOOL	r = coFALSE;
	for (int i = 0; i < links_count; i++) {
		if (links[i]->refered(node_ref)) {
			r = coTRUE;
			break;
		}
	}
	return r;
}

coF(coBOOL)	coPath::refered(const coLink_r link_ref) const {
	coBOOL	r = coFALSE;
	for (int i = 0; i < links_count; i++) {
		if (links[i] == link_ref) {
			r = coTRUE;
			break;
		}
	}
	return r;
}

coF(coLink_ra)	coPath::link_at(const coLink_r link_query) const {
	coLink_ra r = NULL;
	if (refered(link_query)) {
		for (int i = 0; i < links_count; i++) {
			if (links[i] == link_query) {
				r = links + i;
				break;
			}
		}
	}
	return r;
}

coF(coPath&)	coPath::operator = (const coPath& o_o) {
	if (this == &o_o) return *this;

	co_dela(links);
	co_new(links, coLink_r[o_o.links_count]) {
		memcpy(links, o_o.links, sizeof(coLink_r) * o_o.links_count);
		links_count = o_o.links_count;
		name = o_o.name;
	}
	return *this;
}

coF(coLink_r)	coPath::operator [] (const coINT link_index) const {
	co_ASSERT(link_index >= 0 && link_index < links_count);
	return links[link_index];
}

coF(coLink_r&)	coPath::operator [] (const coINT link_index) {
	co_ASSERT(link_index >= 0 && link_index < links_count);
	return links[link_index];
}

///////////////////////////////////////////////////////////////////////////////
// 表达模型
