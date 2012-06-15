
#pragma once

#include <stdio.h>

#include <pos/pos.h>
using namespace pos;

#include <posic/parse/parse_env.h>
using namespace pos::ic::parse;


#define LEXF_NEWLINE		0x00000001
#define LEXF_NOCASE			0x00000002
#define LEXF_QQ				0x00000004
#define LEXF_Q				0x00000008
#define LEXF_NUM			0x00000010
#define LEXF_ID				0x00000020
#define LEXF_CM_SHARP		0x00000100
#define LEXF_CM_SLASH_AST	0x00000200


#define YYPARSE_PARAM	pvParse
#define YYPARSE_HEAD	\
	parse_env_t&		_e = *(parse_env_t *)pvParse;				\
	graph_t *			_graph = (graph_t *)_e.target.body._pv;		\
	parse_env_t::_stop&	_e_l = _e.s[0];								\
	parse_env_t::_stop&	_e_g = _e.s[1];								\
	int&				_col = (int&)_e_l.loc.x;					\
	int&				_line = (int&)_e_l.loc.y;					\
	YYSTYPE *&			_e_lval = (YYSTYPE *&)_e_l.out.L;			\
						_e_lval	= &yylval;

#define YYLEX_PARAM		pvParse


int YTMFlex(void *plval, void *pParse);
int YTMFerror(const char *);



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
        int     length;
        char *  _start;
        char *  _ps_cur;
};
