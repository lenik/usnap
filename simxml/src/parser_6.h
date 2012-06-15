#ifndef _parser_6_umac_n_xWDeYntdFYJfDf_
#define _parser_6_umac_n_xWDeYntdFYJfDf_ "$Id: parser_6.h,v 1.1 2007-11-03 12:23:06 lenik Exp $"

#include "parser.h"
#include "simxml.h"             /* simxml memory model */

G_BEGIN_DECLS

/* .section. parser context and macros */

typedef enum _macro_type_t {
    MACRO_TYPE_NORMAL = 0,
    MACRO_TYPE_INLINE,
    MACRO_TYPE_VARIABLE,
    MACRO_TYPE_ELEMENT,
} macro_type_t;

#define MACRO_OPT_IS_PREFIX 1

typedef struct _macro_t {
    string_t name;
    macro_type_t type;
    int options;
} *macro_t;

typedef struct _parser_context_t {
    input_source_t input;
} *parser_context_t;

/* parser ext for simxml elements */
#define ELEMENT_OPT_MERGE 0x8000

#define MACRO_EVAL_SPACE_X 0xf
#define MACRO_EVAL_RECURSIVE 0x10
#define MACRO_EVAL_ESCAPE 0x20

void
macro_evaluate(parser_context_t context, macro_t macro, string_t *args,
               int options);


/* .section. simxml parser api */


#define PARSER_OPT_FORCE 1      /* force continue on error */

simxml_t *
parse_simxml(input_source_t *input);


GTree *
parse_attributes(input_source_t *input);


attribute_t *
parse_attribute(input_source_t *input);


#define PARSE_COMMENT_KILL 1    /* don't return the comment string */

string_t
parse_comment(input_source_t *input, int options);


string_t
parse_pi(input_source_t *input, context_t *context);


int
parse_pi_simxml(input_source_t *input, context_t *context);


G_END_DECLS

#endif
