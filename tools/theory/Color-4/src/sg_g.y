
%pure_parser


%{
	#include "stdafx.h"

	#include <pos/variant.h>
	#include <pos/graph.h>
	using namespace pos;
	using graph::iolinks_node_t;

	#include <posic/parse/parse_env.h>
	using namespace pos::posic::parse;

	typedef graph::iolinks_node_t::list_t	nodes_t;

	struct node_tran_t {
		asz_t name;
		iolinks_node_t *pnode;
	};
	typedef bdt::list_t<node_tran_t> node_decls_t;

	#include "poy_nodes.h"
%}


%union {
	char		c;
	int		i;
	long		l;
	char *		s;
	float		f;
	double		r;
	void *		p;
	_PVT_128	v;

	graph_t *		graph;
	iolinks_node_t *	node;
	nodes_t *		nodes;
};


%{
	#define YYPARSE_PARAM	pvParse
	#define YYPARSE_HEAD	\
		parse_env_t&		_e = *(parse_env_t *)pvParse;		\
		graph_t *		_graph = (graph_t *)_e.target.body._pv;	\
		parse_env_t::_stop&	_e_l = _e.s[0];				\
		parse_env_t::_stop&	_e_g = _e.s[1];				\
		YYSTYPE *& _e_lval = (YYSTYPE *&)_e_l.out.L;			\
		int& _col = (int&)_e_l.loc.x;					\
		int& _line = (int&)_e_l.loc.y;					\
		_e_lval = &yylval;

	#define YYLEX_PARAM	pvParse

	int SimGraphlex(YYSTYPE *plval, void *pParse);
	int SimGrapherror(const char *);

	node_decls_t	*node_decls;
%}

%token<l>	NUMBER
%token<s>	STRING
%token<s>	ID
%token		D_LINK G_LINK

%type<graph>		Graph
%type<nodes>		Nodes GraphDefs
%type<node>		Node GraphDef
%type<s>		GraphName NodeName
%type<s>		_ID

%%
Graph:
	GraphName ':' '{' GraphDefs '}'
		{
			$$ = _graph;
			_graph->_agg.m_pInfo = (var_t *)new util::v32_t;
			_graph->_agg.m_pInfo->hdr = PVTF_AUTO | pvt_asz;
			_graph->_agg.m_pInfo->_body()->p.m_asz = $1;

			((graph::iolinks_t *)_graph->m_pDetail)->s = $4;

			// release node_decls
			while (node_decls) {
				node_decls_t *p = node_decls;
				node_decls = node_decls->l;
				delete p;
			}
		}
	;

GraphDefs:
	GraphDef
		{
			$$ = NULL;
			graph::iolinks::nodes_add($$, $1);
		}
	| GraphDefs GraphDef
		{
			graph::iolinks::nodes_add($1, $2);
		}
	;

GraphDef:
	Node D_LINK Nodes
		{
			while ($3->_l) $3 = $3->_l;
			graph::iolinks::node_link_d($1, $3);
			graph::iolinks::nodes_destroy_list($3);
			$$ = $1;
		}
	| Node G_LINK Nodes
		{
			while ($3->_l) $3 = $3->_l;
			graph::iolinks::node_link($1, $3);
			graph::iolinks::nodes_destroy_list($3);
			$$ = $1;
		}
	;

Nodes:
	Node
		{
			$$ = new nodes_t;
			$$->data = $1;
			$$->_l = NULL;
			$$->l = NULL;
		}
	| Nodes ',' Node
		{
			$$ = new nodes_t;
			$1->l = $$;

			// NOTICE: here $$=$1.s, hence speed up,
			//	so Nodes shall be scaned back anywhere use Nodes.
			$$->data = $3;
			$$->_l = $1;
			$$->l = NULL;
		}
	;

Node:
	NodeName
		{
			node_tran_t *item;
			node_decls_t *p = node_decls;

			bool bFound = false;
			while (p != NULL) {
				item = &(p->data);
				if (strcmp(item->name, $1) == 0) {
					$$ = item->pnode;
					bFound = true;
					break;
				}

				// break at somewhere the "p" just != NULL, so can speed up the insertion.
				if (p->l) {
					p = p->l;
				} else {
					break;
				}
			}

			if (!bFound) {
				if (p) {
					p->l = new node_decls_t;
					p->l->_l = p;
					p = p->l;
					p->l = NULL;
				} else {
					// the node_decls must be empty.
					node_decls = p = new node_decls_t;
					p->l = p->_l = NULL;
				}
				p->data.name = $1;	// not [auto]

				iolinks_node_t *_node = new iolinks_node_t;
				$$ = p->data.pnode = _node;

				// init the graph node
				__zero(*_node);
				_node->bAuto	= true;
				_node->_p0	= $1;	// [auto]
			}
		}
	;

GraphName:
	_ID	{ $$ = $1; }
	;

NodeName:
	_ID	{ $$ = $1; }
	;

_ID:
	ID
		{
			if ($<v>1._r.bAuto) {	// generally, bAuto means the string is allocated rather than on-stack.
				$$ = $1;
				$<v>1._r.bAuto = false;		// unbind
			} else {
				$$ = strdup($1);
			}
		}
	;

%%

#define yyFlexLexer SimGraphFlexLexer
#include <FlexLexer.h>

int SimGraphlex(YYSTYPE *plval, void *pvParse) {
	parse_env_t *_e;
	_e = (parse_env_t *)pvParse;

	SimGraphFlexLexer *pSGL =
		(SimGraphFlexLexer *)_e->source.body._pv;

	int i;
	i = pSGL->yylex();

	return i;
}
int SimGrapherror(const char *) {
	return 0;
}
