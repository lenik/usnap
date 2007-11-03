#ifndef _macro_umac_n_xWDeYMBmf0zN28_
#define _macro_umac_n_xWDeYMBmf0zN28_ "$Id: macro.h,v 1.1 2007-11-03 12:23:06 lenik Exp $"

#define MACRO_MERGE 1           /* merge with the adjacent macros */
#define MACRO_ESCAPE 2          /* " => &quot;  ' => &apos */
#define MACRO_INLINE 4          /* non-inline macros must preceding by ^\s+ */
#define MACRO_RECURSIVE 8       /* macro will be evaluated recursively */

struct macro_t {
    gchar *textstart;
    gchar *textend;
    gint options;
};

macro_t *
macro_set(parser_t *parser, gstring macro_name, gstring textstart, gstring textend, gstring options);

void
macro_unset(parser_t *parser, gstring macro_name);

#endif
