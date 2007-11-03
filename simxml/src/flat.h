#ifndef _flat_umac_n_xWDeY89jxqW0lk_
#define _flat_umac_n_xWDeY89jxqW0lk_ "$Id: flat.h,v 1.1 2007-11-03 12:23:06 lenik Exp $"

#include <glib.h>

typedef GHashTable flat_t;

#define flat_new()          g_hash_table_new(g_direct_hash, g_direct_equal)
#define flat_add(f, p)      g_hash_table_insert(f, p, "(exist)")
#define flat_remove(f, p)   g_hash_table_remove(f, p)
#define flat_contain(f, p)  g_hash_table_lookup(f, p)
#define flat_size(f)        g_hash_table_size(f)
#define flat_free(f)        g_hash_table_destroy(f)

#endif
