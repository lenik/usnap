

#include "stdafx.h"
#include <strstrea.h>

#include <pos/graph.h>
using namespace pos;

#include <posic/parse/parse_env.h>
using namespace pos::posic::parse;

#include "sg_script.h"

#define yyFlexLexer SimGraphFlexLexer
#include <FlexLexer.h>

int SimGraphparse(void *pvParse);

BOOL SimGraphParse(graph_t *_g, istream *_is, ostream *_os) {
	_pos_assert(_g);

	SimGraphFlexLexer lexer(_is, _os);

	parse_env_t e;

	e.source.body._pv	= &lexer;
	e.target.body._pv	= (void *)_g;

	// tell lexer the location of parse_env_t.
	extern parse_env_t * _e;
	_e = &e;

	__zero(*_g);
	_g->_agg.bAuto		= true;
	_g->_agg.bSimple	= true;		// use simple type instead PVT::extype.
	_g->_agg.m_VarHdr	= pvt_i8;	// only need 4 color representation.
	_g->type		= graph_iolinks;

	graph::iolinks_t *pDetail = new graph::iolinks_t;
	__zero(*pDetail);

	_g->m_pDetail		= (void *)pDetail;


	int i;

//	extern void lex_main();
//	lex_main();

	i = SimGraphparse((void *)&e);

	return i == 0;
}
