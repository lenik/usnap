#include "parser_stx.h"

int
parse_pi(input_souce_t *input, context_t *context) {
    input <?xml version="1.0"
}

int simxml_pi_parse() {
    input_source_t *input;

    oonst char **args = parse_arguments(parser);
    char *command = *args++;
    char buf[1000];

    if (! strcmp(command, "define")) {
        ASSERT(args[0]);        /* macro-name */
        ASSERT(args[1]);        /* macro-start-expand */
        if (args[3]) {          /* macro-options */
            macro_set(parser, args[0], args[1], args[2], args[3]);
        } else if (args[2]) {   /* macro-end-expand */
            macro_set(parser, args[0], args[1], args[2], NULL);
        } else {
            macro_set(parser, args[0], args[1], NULL, NULL);
        }
    } else if (! strcmp(command, "undef")) {
        ASSERT(args[0]);        /* macro-name */
        macro_unset(parser, args[0]);
    } else if (! strcmp(command, "comment")) {
        /* ignore */
    } else if (! strcmp(command, "include")) {
        input_source_t *source;
        ASSERT(args[0]);        /* include-path */

        source->fh = fopen(args[0], "rb");
        if (source->fh == NULL) {
            sprintf(buf, "can't open include file %s", args[0]);
            parse_error(parser, buf, NULL, 1);
        }
        source->line = 0;
        source->col = 0;
    } else {
        sprintf(buf, "invalid command %s of simxml-pi", command);
        parse_error(parser, buf, "define, undef, comment, include", 0);
    }
}











/* if element {...} immediately followed by a comma(,) then its
   attributes will be inherited. */
int attributes_share;

enum simxml_tokens {
    T_WORD,
    T_BRACE_L,                  /* { */
    T_BRACE_R,                  /* } */
    T_SQUARE_L,                 /* [ */
    T_SQUARE_R,                 /* ] */
    T_COMMA,                    /* , */
    T_EQU,                      /* = */
    T_QQ,                       /* " */
    T_Q,                        /* ' */
};

enum simxml_states {
    S_NORMAL,                   /* T_WORD T_BRACE T_SQUARE */
    S_ATTR,                     /* T_WORD T_BRACE T_EQU T_QQ T_Q */
};


void
simxml_default_macros() {
    /* == -- */
}


simxml_t *
parse_simxml(parser_t *parser) {
    simxml_token_t token;
    tokenval_t *tokenval;

    token = input_next_token(parser);
    tokenval = &parser->last_value;
    legema k
    switch (token) {
    case T_WORD:
        {
            simxml_keyword_t keyword;
            keyword = word_type(tokenval->vstr);


/* membuf, glist?  top-down parser.  */
