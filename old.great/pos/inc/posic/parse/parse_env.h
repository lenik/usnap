
//
// POS.-ic/parse/parse_env
//

//
// 2003.7.3	change pos::posic into pos::ic
// 2003.5.15	change _PVT_256 -> _PVT_128
// 2003.5.14	started

#pragma once

#define _NS_BEGIN		namespace pos { namespace ic { namespace parse {
#define _NS_END			}}}

#include <pos/config.h>
#include <pos/variant.h>
#include <pos/error.h>
#include <pos/k_vars.h>
#include <pos/cpputil.h>

_NS_BEGIN

	// 16-bytes, 128-bit	- used for fast units
	using pos::v16_t;
	// 128-bytes, 1024-bit	- used as a small environment
	using pos::v128_t;

	// currently 2592-bytes
	struct parse_env_t {
		// target represent the result of parsing procedure.
		v128_t		target;
		v128_t		target_ctx;	// context info
		// source represent the raw-resource provide for parser.
		v128_t		source;
		v128_t		source_ctx;	// context info

		struct _stop {
			// e.g.	for lexer, in is current yytext;
			//	for lalr, in is current <$1,$2,$3,...>
			v128_t	in;
			// e.g.	for lexer, out is current yylval and the "return NUM";
			//	for lalr, out is current $$.
			v128_t	out;
			// context info.
			v128_t	ctx;
			// e.g.	for lexer, loc is row/column number;
			//	for lalr, loc is current node in symbol-reduce-tree
			v128_t	loc;
			// error info.
			error_t	error;
		};

		// e.g.	s[0] is for lexer, s[1] is for first parser, and s[2] for second, so forth.
		_stop	s[4];
	};

_NS_END