

#pragma once

#include <pos/graph.h>

namespace pos {
namespace graph {
namespace iolinks {
	using iolinks_node_t::list_t;

	bool node_link_d(iolinks_node_t *_1, iolinks_node_t *_2);
	bool node_link(iolinks_node_t *_1, iolinks_node_t *_2);
	bool node_link_d(iolinks_node_t *_1, list_t *_2s);
	bool node_link(iolinks_node_t *_1, list_t *_2s);
	bool nodes_add(list_t *&_1r, iolinks_node_t *_2);
	bool nodes_union(list_t *&_1r, list_t *&_2r, bool fCreate = false);
	bool nodes_destroy_list(list_t *l);

	struct nodes_enum_t {
		u32_t		scan_mask;
		u32_t		scan_cmp;
		u32_t iolinks_node_t::*scan_val;

		void *		_ctx;
		graph_t *	_graph;

		typedef bool (_stdcall *enum_proc_t)(iolinks_node_t *, nodes_enum_t *);
		enum_proc_t proc;

		static bool _stdcall _enum_proc_dummy(iolinks_node_t *, nodes_enum_t *) { return true; }

		bool prepare(iolinks_node_t *_entry);
		bool enumerate(iolinks_node_t *_entry);

		// mark != _cmp
		inline bool is_scaned(iolinks_node_t *_node) {
			return (_node->*scan_val & scan_mask)
				!= (scan_cmp & scan_mask);
		}
		// mark = ~_cmp
		inline void scan_mark(iolinks_node_t *_node) {
			u32_t& s = _node->*scan_val;
			s = (s & ~scan_mask) | (~scan_cmp & scan_mask);
		}
		// mark = _cmp
		inline void scan_unmark(iolinks_node_t *_node) {
			u32_t& s = _node->*scan_val;
			s = (s & ~scan_mask) | (scan_cmp & scan_mask);
		}
	};


}}} // ns pos.graph.iolinks