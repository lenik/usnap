

#include "stdafx.h"
#include <strstrea.h>

#include <pos/pos.h>
using namespace pos;

#include <posic/parse/parse_env.h>
using namespace pos::ic::parse;

#include "YTMF_script.h"

#define YY_API

#define yyFlexLexer YTMFFlexLexer
#include <FlexLexer.h>
#undef yyFlexLexer


YY_API int YTMFparse(void *pvParse);

YY_API int YTMFlex(void *plval, void *pvParse) {
    parse_env_t *_e;
    _e = (parse_env_t *)pvParse;

    YTMFFlexLexer *pYL =
        (YTMFFlexLexer *)_e->source.body._pv;

    int i;
    i = pYL->yylex();

    return i;
}

YY_API int YTMFerror(const char *) {
    return 0;
}

void YTMFlex_test() {
        YTMFFlexLexer lexer(&cin, &cout);

        int c;
        for (;;) {
                c = lexer.yylex();
                if (c == 0) break;
                printf("%d,", c);
        }
}



BOOL YTMFParse(ResultContext *_pvBody, istream *_is, ostream *_os) {
    // POS_ASSERT(_pvBody);

    YTMFFlexLexer lexer(_is, _os);

    parse_env_t e;

    e.source.body._pv   = &lexer;
    e.target.body._pv   = (void *)_pvBody;

    // tell lexer the location of parse_env_t.
    extern parse_env_t * _e;
    _e = &e;

    int i;

//  extern void lex_main();
//  lex_main();

    i = YTMFparse((void *)&e);

    return i == 0;
}
