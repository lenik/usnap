// c4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream.h>

#include <pos/pos.h>
using namespace pos;
using namespace pos::graph;

#include "poy_nodes.h"
using namespace pos::graph::iolinks;

#include "sg_script.h"

#include "c4_type.h"

#define _initialize(name)					\
	class __initialize_##name {				\
	public:							\
		inline bool _init_();				\
		__initialize_##name() { _init_(); }		\
	} __g_initialize_obj_##name;				\
	inline bool __initialize_##name::_init_()


int g_count;
i_info *g_i;
//pos::matrix_t g_mat;
//pos::matrix::mat2d_t *g_mat_data;
pos::graph_t g_graph;


_initialize(0001) {
	/*
	__zero(g_mat);
	g_mat._agg.bSimple = true;
	g_mat._agg.bAuto = true;
	g_mat._agg.m_VarHdr = pos::pvt_b8;
	g_mat.type = pos::matrix_mat2d;
	g_mat._type = (void *)
		(g_mat_data = new pos::matrix::mat2d_t);
	__zero(*g_mat_data);
	g_mat_data->m_Size = 0;
	g_mat._data = 0;
	*/

	__zero(g_graph);

	return true;
}

/*
int& rel(int a, int b) {
	int offset = a * g_count + b;
	return *((int *)g_mat._data + offset);
}
*/

int findcolor(iolinks_node_t *_n, int colors = 4, int mincolor = 0) {
	// only find _out_ links
	iolinks_node_t::list_t *adj;
	adj = _n->s;
	bool usedclr[100];
	__zero(usedclr);
	while (adj) {
		iolinks_node_t *_an = adj->data;
		// ignore unmark nodes
		if (_an->bMark) {
			usedclr[_an->_val] = true;
		}
		adj = adj->l;
	}
	int icolor;
	for (icolor = mincolor; icolor < colors; icolor++) {
		if (!usedclr[icolor]) {
			return icolor;
		}
	}
	return -1;
}

bool render(iolinks_node_t *_n, int colors = 4) {

	_n->bMark = true;

	// startcolor
	int rendercolor = findcolor(_n, colors, 0);
	bool b_ok = false;

	while (rendercolor >= 0) {
		_n->_val = rendercolor;

		iolinks_node_t::list_t *adj;
		adj = _n->s;

		iolinks_node_t::list_t *mark_list = NULL;

		b_ok = true;
		while (adj) {
			iolinks_node_t *_an = adj->data;
			asz_t _aname = (asz_t)_an->_p0;

			// ignore marked nodes
			if (!_an->bMark) {
				nodes_add(mark_list, _an);
				if (!render(_an, colors)) {
					b_ok = false;
					break;
				}
			}

			adj = adj->l;
		}

		if (!b_ok) {
			iolinks_node_t::list_t *i_mark = mark_list;
			while (i_mark) {
				iolinks_node_t *n_mark = i_mark->data;
				n_mark->bMark = false;
				i_mark = i_mark->l;
			}
		}

		nodes_destroy_list(mark_list);
		mark_list = NULL;

		if (b_ok) break;

		rendercolor = findcolor(_n, colors, rendercolor + 1);
	}

	if (!b_ok) _n->bMark = false;
	return b_ok;
}

bool _stdcall dump(iolinks_node_t *_node, nodes_enum_t *_e) {
	asz_t name = (asz_t)_node->_p0;
	std::cout << name;
	if (_node->bMark) {
		std::cout << "  < " << (int)_node->_val << " >\n";
	} else {
		std::cout << "  ?\n";
	}

	iolinks_node_t::list_t *adj;

	std::cout << "\t --> ";
	adj = _node->s;
	while (adj) {
		iolinks_node_t *_n = adj->data;
		name = (asz_t)_n->_p0;
		std::cout << name << " ";
		adj = adj->l;
	}


	std::cout << "\n\t <-- ";
	adj = _node->_s;
	while (adj) {
		iolinks_node_t *_n = adj->data;
		name = (asz_t)_n->_p0;
		std::cout << name << " ";
		adj = adj->l;
	}

	std::cout << "\n";
	return true;
}

bool _stdcall clearmark(iolinks_node_t *_node, nodes_enum_t *_e) {
	_node->bMark = 0;
	return true;
}

int main(int argc, char* argv[])
{
	std::cerr
		<< "c4: the 4-color problem.     author/zauj.g.d. 2003.5.15\n"
		<< "	grammer:  \n"
		<< "		define::=	graph_name: { statements } \n"
		<< "		statements::=	statement statement ... \n"
		<< "		statement::=	node_name -- node_name[,node_name[,...]] \n"
		<< "			(or)	node_name -> node_name[,node_name[,...]] \n"
		<< "		# you can put comments as this.\n"
		<< "		# write to me: jljljjl@yahoo.com (or) dansei@163.com\n"
		<< "	example: \n"
		<< "		MyGraph: { \n"
		<< "			A -- B,E,Center \n"
		<< "			B -- A,C \n"
		<< "			C -- B,Center,D \n"
		<< "			E -- A,D \n"
		<< "		}\n"
		<< "\n";

	if (!SimGraphParse(&g_graph, &cin, &cout)) {
		cerr << "error parsing!" << endl;
		return -1;
	}

	pos::graph::iolinks::nodes_enum_t enums;

	enums.scan_val = &iolinks_node_t::hdr;
	enums.scan_mask = NODEF_SCAN;
	enums.scan_cmp = 0;		// 1 is scaned.
	enums._graph = &g_graph;
	enums.proc = &clearmark;

	graph::iolinks_t *_detail = (graph::iolinks_t *)g_graph.m_pDetail;

	render(_detail->s->data);

	enums.proc = &dump;
	enums.prepare(_detail->s->data);
	enums.enumerate(_detail->s->data);
	return 0;
}
