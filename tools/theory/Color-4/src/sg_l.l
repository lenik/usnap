


/*
 * -+		C++ class
 * -Cr		use read() instead of stdin (override by -+ : istream, ostream)
 * -Pxxx	set prefix=xxx
 * -b		generate back-up file "lex.backup"
 * -o <file>	set output file

 -p  generate performance report to stderr
 -Ca  trade off larger tables for better memory alignment
 -Cf  do not compress scanner tables; use -f representation
 -CF  do not compress scanner tables; use -F representation

 */


%option noyywrap
%option stack


/*
 * common terminals
 */

tOCTDIGIT	[0-7]
tDECDIGIT	[0-9]
tHEXDIGIT	[0-9a-fA-F]
tOCTNUM		0{tOCTDIGIT}+
tDECNUM		{tDECDIGIT}+
tHEXNUM		0x{tHEXDIGIT}+
tSIGNCHAR	\-?

tALPHA		[a-zA-Z]
tALPHANOTBEGIN	[0-9a-zA-Z_]
tSPC		[ \t]
tSPACE		{tSPC}+

tNUM		{tSIGNCHAR}({tOCTNUM}|{tDECNUM}|{tHEXNUM})
tMPNUM		#{tNUM}
tIDENTIFIER	{tALPHA}+{tALPHANOTBEGIN}*

tWORD_C		{tALPHANOTBEGIN}
tWORD_S		[\-\+\$\@\#\?\*\!\~]
tWORD_ITEM	{tWORD_C}|{tWORD_S}
tWORD		{tALPHA}{tWORD_ITEM}+

tLINE		.*$

tD_LINK		->
tG_LINK		--


/*
 * language-specifiers
 */

%x x_comment
%x x_string
%x x_Esc_1


%{
	#include <stdio.h>
	#include <windows.h>
	#include <tchar.h>

	#include <pos/graph.h>
	using namespace pos;
	using graph::iolinks_node_t;
	typedef graph::iolinks_node_t::list_t	nodes_t;

	#include <posic/parse/parse_env.h>
	using namespace pos::posic::parse;

	#include "sg_gy.cpp.h"

	parse_env_t *	_e;

	struct _dyn_str {
		void reset(bool fAnother = false) {
			if (!fAnother && _start) delete _start;
			_dyn_str();
		}
		bool setsize(int s) {
			if (s > length) {
				int off = _ps_cur - _start;
				if (_start) {
					_start = (char *)realloc(_start, s);
				} else {
					_start = new char[s];
				}
				if (!_start) return false;
				_ps_cur = _start + off;
			}
			length = s;
			return true;
		}
		void addchar(char c) {
			if (_ps_cur - _start >= length - 1) setsize(length + 100);
			*_ps_cur++ = c;
		}
		_dyn_str& operator+=(char c) {
			addchar(c);
			return *this;
		}
		_dyn_str() { length = 0; _start = _ps_cur = NULL; }
	public:
		int	length;
		char *	_start;
		char *	_ps_cur;
	};
%}

%%

%{
	parse_env_t::_stop&	_e_l = _e->s[0];
	parse_env_t::_stop&	_e_g = _e->s[1];

	YYSTYPE *&	_e_lval = (YYSTYPE *&)_e_l.out.L;

	int&		_col = (int&)_e_l.loc.x;
	int&		_line = (int&)_e_l.loc.y;

	int		_c_eos;

	_dyn_str	l_str;
%}


<x_comment>{
	[^*\n]*        /* eat anything that's not a '*' */
	"*"+[^*/\n]*   /* eat up '*'s not followed by '/'s */
	\n             /* ++_line; */
	"*"+"/"        { yy_pop_state(); }
}

<x_string>{
	\n	{
			/* error: x_string not end with '\"'. */
			++_line;
			yy_pop_state();
		}

	\\	{
			yy_push_state(x_Esc_1);
		}

	.	{
			char& c = yytext[0];
			if (c == _c_eos) {
				yy_pop_state();
				l_str += '\0';
				_e_lval->s = l_str._start;
				return STRING;
			} else {
				l_str += c;
			}
		}
}

<x_Esc_1>{
	a	{	l_str += '\a'; yy_pop_state(); }
	b	{	l_str += '\b'; yy_pop_state(); }
	n	{	l_str += '\n'; yy_pop_state(); }
	r	{	l_str += '\r'; yy_pop_state(); }
	0	{	l_str += '\0'; yy_pop_state(); }
	\\	{	l_str += '\\'; yy_pop_state(); }
	\"	{	l_str += '\"'; yy_pop_state(); }
	\'	{	l_str += '\''; yy_pop_state(); }
	.	{	l_str += yytext[0]; yy_pop_state(); }
}


"#".*$		/* eats up */
"/*"		yy_push_state(x_comment);

\'		{
			l_str.reset(true);
			_c_eos = '\'';
			yy_push_state(x_string);
		}

\"		{
			l_str.reset(true);
			_c_eos = '\"';
			yy_push_state(x_string);
		}

{tSPACE}	{
			/* eats up */
			/* 这一规约非常重要，用于断字。*/
		}

{tNUM}		{
			_e_lval->l = strtol(yytext, NULL, 0);
			return NUMBER;
		}


{tIDENTIFIER}	{
			_e_lval->s = strdup(yytext);
			_e_lval->v._r.bAuto = true;
			return ID;
		}
"_id(".+")"	{
			long l = lstrlen(yytext);
			yytext[l - 1] = _T('\0');
			_e_lval->s = strdup(yytext + 4);
			_e_lval->v._r.bAuto = true;
			return ID;
		}

{tD_LINK}	return D_LINK;
{tG_LINK}	return G_LINK;

.		{
			char c = yytext[0];
			_e_lval->c = c;
			return c;
		}

\n		/* eats up */


%%

void lex_main() {
	yyFlexLexer lexer(&cin, &cout);

	int c;
	for (;;) {
		c = lexer.yylex();
		if (c == 0) break;
		printf("%d,", c);
	}
}
