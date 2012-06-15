#ifndef _set_umac_n_xWDeY89jxqW0lk_
#define _set_umac_n_xWDeY89jxqW0lk_ "$Id: coll_set.hh,v 1.1 2007-11-03 12:23:06 lenik Exp $"

#include <glib.h>

class set_t1 {
public:
};

typedef GHashTable set_t;

#define set_new()          g_hash_table_new(g_direct_hash, g_direct_equal)
#define set_add(f, p)      g_hash_table_insert(f, p, "(exist)")
#define set_remove(f, p)   g_hash_table_remove(f, p)
#define set_contain(f, p)  g_hash_table_lookup(f, p)
#define set_size(f)        g_hash_table_size(f)
#define set_free(f)        g_hash_table_destroy(f)

#endif
