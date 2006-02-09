#ifndef _tree_umac_n_xWDeYI1ZfiVn5P_
#define _tree_umac_n_xWDeYI1ZfiVn5P_

typedef struct _node_t node_t;
struct _node_t {
    guint16 type;
    guint16 flags;
    node_t *prev;
    node_t *next;
    node_t *parent;             /* NULL for root node */
    node_t *child;              /* any of direct connected children */
    char *text;                 /* #node.text */
#ifdef CPF_CHECK_INCONSISTENCY
    flat_t flat;                /* #node.flat */
#endif
};
/* text, comment and pi nodes are the same */

#define _NODE_FUNC_1(t,f,e)     ((t)node_##f((node_t *)&(e)->node))
#define _NODE_FUNC_1X(t,f,e,s)  ((t)node_##f((node_t *)&(e)->node, s))
#define _NODE_FUNC_2(t,f,e,s)   ((t)node_##f((node_t *)&(e)->node, (node_t *)&(s)->node))

#ifdef SIMXML_CHECK_INCONSISTENCY
#  define NODE_FLAT(n)          node_flat((node_t *)(n))
#  define NODE_CHECK_ADD(n,a)   node_check_add(node_flat((node_t *)(n)), (node_t *)(a))
#  define NODE_CHECK_REMOVE(r)  node_check_remove(NULL, (node_t *)(r))
#else
#  define NODE_FLAT(n)          G_STMT_START { (void)0; } G_STMT_END
#  define NODE_CHECK_ADD(n,a)   G_STMT_START { (void)0; } G_STMT_END
#  define NODE_CHECK_REMOVE(r)  G_STMT_START { (void)0; } G_STMT_END
#endif

extern gboolean (*node_check_failure)(const char *, node_t *, node_t *);

gboolean
_node_check_node(flat_t *flat, node_t *start, gboolean upwards);

gboolean
node_check_node(flat_t *flat, node_t *node);

gboolean
node_check_add(flat_t *flat, node_t *add);

gboolean
node_check_remove(flat_t *flat, node_t *remove);

flat_t *                        /* build if not exist */
node_flat(node_t *node);

node_t *
node_new(node_t *parent, int type, const char *text);

void
node_init(node_t *node, node_t *parent, int type, const char *text);

void
node_free(node_t *node);

void
node_free_recursive(node_t *node);

void
node_detach(node_t *node);

node_t *                        /* return the first child */
node_swap_children(node_t *node);

int
node_type(node_t *node);

const char *
node_typename(node_t *node);

const char *
node_text(node_t *node);

void
node_set_text(node_t *node, const char *text);

node_t *
node_prev(node_t *node);

node_t *
node_set_prev(node_t *node, node_t *prev);

node_t *
node_next(node_t *node);

node_t *
node_set_next(node_t *node, node_t *next);

node_t *
node_prev_type(node_t *node, int node_type);

node_t *
node_next_type(node_t *node, int node_type);

node_t *
node_first(node_t *node);

node_t *
node_last(node_t *node);

void
node_insert_prev(node_t *node, node_t *prev);

void
node_insert_next(node_t *node, node_t *next);

node_t *
node_root(node_t *node);

node_t *
node_parent(node_t *node);

node_t *
node_set_parent(node_t *node, node_t *parent);

node_t *
node_child(node_t *node);

node_t *
node_set_child(node_t *node, node_t *child);

void
node_remove_children(node_t *node);

int
node_breadth(node_t *node);

int
node_depth(node_t *node);

#endif
