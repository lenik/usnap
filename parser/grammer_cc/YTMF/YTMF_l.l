


/*
 * -+           C++ class
 * -Cr          use read() instead of stdin (override by -+ : istream, ostream)
 * -Pxxx        set prefix=xxx
 * -b           generate back-up file "lex.backup"
 * -o <file>    set output file

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

tOCTDIGIT       [0-7]
tDECDIGIT       [0-9]
tHEXDIGIT       [0-9a-fA-F]
tOCTNUM         0{tOCTDIGIT}+
tDECNUM         {tDECDIGIT}+
tHEXNUM         0x{tHEXDIGIT}+
tSIGNCHAR       \-?

tALPHA          [a-zA-Z]
tALPHANOTBEGIN  [0-9a-zA-Z_]
tSPC            [ \t]
tSPACE          {tSPC}+

tNUM            {tSIGNCHAR}({tOCTNUM}|{tDECNUM}|{tHEXNUM})
tMPNUM          #{tNUM}
tIDENTIFIER     {tALPHA}+{tALPHANOTBEGIN}*

tWORD_C         {tALPHANOTBEGIN}
tWORD_S         [\-\+\$\@\#\?\*\!\~]
tWORD_ITEM      {tWORD_C}|{tWORD_S}
tWORD           {tALPHA}{tWORD_ITEM}+

tPUNCT          [^a-zA-Z0-9_{tSPC}]

tLINE           .*$


/*
 * language-specifiers
 */

%x x_comment
%x x_string
%x x_Esc_1


%{
        /*
         * For compatible with Flex 2.85 & 2.91
         */
        int yy_more_offset;
        int yy_prev_more_offset;

        #include <stdio.h>

        #include "YTMF_util.h"
        #include "YTMF_gy.cpp.h"

        int lexoption =
              LEXF_NEWLINE
            | LEXF_CM_SHARP
            | LEXF_CM_SLASH_AST
            | LEXF_Q
            | LEXF_QQ
            ;

        parse_env_t *   _e;
%}

%%

%{
        parse_env_t::_stop&     _e_l = _e->s[0];
        parse_env_t::_stop&     _e_g = _e->s[1];

        YYSTYPE *&      _e_lval = (YYSTYPE *&)_e_l.out.L;

        int&            _col = (int&)_e_l.loc.x;
        int&            _line = (int&)_e_l.loc.y;

        int             _c_eos;

        _dyn_str        l_str;
%}


<x_comment>{
        [^*\n]*        /* eat anything that's not a '*' */
        "*"+[^*/\n]*   /* eat up '*'s not followed by '/'s */
        \n             /* ++_line; */
        "*"+"/"        { yy_pop_state(); }
}

<x_string>{
        \n      {
                        /* error: x_string not end with '\"'. */
                        ++_line;
                        yy_pop_state();
                }

        \\      { yy_push_state(x_Esc_1); }

        .       {
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
        a       {       l_str += '\a'; yy_pop_state(); }
        b       {       l_str += '\b'; yy_pop_state(); }
        n       {       l_str += '\n'; yy_pop_state(); }
        r       {       l_str += '\r'; yy_pop_state(); }
        0       {       l_str += '\0'; yy_pop_state(); }
        \\      {       l_str += '\\'; yy_pop_state(); }
        \"      {       l_str += '\"'; yy_pop_state(); }
        \'      {       l_str += '\''; yy_pop_state(); }
        .       {       l_str += yytext[0]; yy_pop_state(); }
}


"#".*$          {
                    if (lexoption & LEXF_CM_SHARP) {
                        /* eats up */
                        /* so the comments can act as space */
                    } else {
                        REJECT
                    }
                }

"/*"            {
                    if (lexoption & LEXF_CM_SLASH_AST) {
                        yy_push_state(x_comment);
                    } else {
                        REJECT
                    }
                }

\n              {
                    if (lexoption & LEXF_NEWLINE) {
                        char c = yytext[0];
                        _e_lval->c = c;
                        return NEWLINE;
                    }
                    REJECT
                }

<<<<<<< HEAD
{tSPACE}|\n 	{
						/* eats up */
						/* è¿™ä¸€è§„çº¦éžå¸¸é‡è¦ï¼Œç”¨äºŽæ–­å­—ã€‚*/
				}
=======
{tSPACE}|\n     {
                    /* eats up */
                    /* ÕâÒ»¹æÔ¼·Ç³£ÖØÒª£¬ÓÃÓÚ¶Ï×Ö¡£*/
                }
>>>>>>> a99e1548 (YTMF: Convert tab to space. Removed generated files.)

{tNUM}          {
                    if (lexoption & LEXF_NUM) {
                        _e_lval->l = strtol(yytext, NULL, 0);
                        return NUMBER;
                    }
                    REJECT
                }


\'              {
                    if (lexoption & LEXF_Q) {
                        l_str.reset(true);
                        _c_eos = '\'';
                        yy_push_state(x_string);
                    } else {
                        REJECT
                    }
                }

\"              {
                    if (lexoption & LEXF_QQ) {
                        l_str.reset(true);
                        _c_eos = '\"';
                        yy_push_state(x_string);
                    } else {
                        REJECT
                    }
                }

"_id(".+")"     {
                    if (lexoption & LEXF_ID) {
                        long l = lstrlen(yytext);
                        yytext[l - 1] = _T('\0');
                        _e_lval->s = strdup(yytext + 4);
                        _e_lval->v._r.bBind_ = false;
                        return ID;
                    }
                    REJECT
                }

{tPUNCT}        {
                    char c = yytext[0];
                    _e_lval->c = c;
                    return c;
                }

.               {
                    char c = yytext[0];
                    _e_lval->c = c;
                    return ANYCHAR;
                }

%%

