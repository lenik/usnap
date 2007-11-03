#ifndef _simxml_umac_n_xWDeYKm6pAcGWe_
#define _simxml_umac_n_xWDeYKm6pAcGWe_ "$Id: simxml.h,v 1.1 2007-11-03 12:23:06 lenik Exp $"

#include <glib.h>
#include "flat.h"
#include "tv.h"

/* .section. node base */

#define NODE_BASE               0
#define NODE_ELEMENT            1
#define NODE_ATTRIBUTE          2
#define NODE_TEXT               3
#define NODE_PI                 4
#define NODE_COMMENT            5

#define NODEF_USER              0x8000

typedef struct _node_t node_t;
struct _node_t {
    guint16 type;
    guint16 flags;
    node_t *prev;
    node_t *next;
    node_t *parent;             /* NULL for root node */
    node_t *child;              /* any of direct connected children */
    char *text;                 /* #node.text */
#ifdef SIMXML_CHECK_INCONSISTENCY
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

/* .section. attribute */

typedef struct _attribute_t {
    node_t node;
    typed_value_t value;        /* variant used for typed attribute */
} attribute_t;

attribute_t *
attribute_new(node_t *parent, const char *name, typed_value_t *value);

void
attribute_free(attribute_t *attribute);

typed_value_t *
attribute_value(attribute_t *attribute);

void
attribute_set_value(attribute_t *attribute, typed_value_t *value);

/* attribute_new_XXX */
#define _attribute_new_decl(vn, vt) \
    attribute_t *attribute_new_##vn(node_t *parent, const char *name, vt value);
TYPED_VALUE_GENERIC(_attribute_new_decl);

/* attribute_value_XXX */
#define _attribute_value_decl(vn, vt) \
    vt attribute_value_##vn(attribute_t *attribute);
TYPED_VALUE_GENERIC(_attribute_value_decl);

/* attribute_set_value_XXX */
#define _attribute_set_value_decl(vn, vt) \
    void attribute_set_value_##vn(attribute_t *attribute, vt value);
TYPED_VALUE_GENERIC(_attribute_set_value_decl);

#define attribute_detach(a)     _NODE_FUNC_1(void, detach, a)
#define attribute_name(a)       _NODE_FUNC_1(const char *, text, a)
#define attribute_set_name(a,n) _NODE_FUNC_1X(void, set_text, a, n)
#define attribute_parent(a)     _NODE_FUNC_1(attribute_t *, parent, a)
#define attribute_set_parent(a,p) _NODE_FUNC_2(void, set_parent, a, p)
#define attribute_root(a)       _NODE_FUNC_1(attribute_t *, root, a)
#define attribute_prev(a)       _NODE_FUNC_1(attribute_t *, prev, a)
#define attribute_set_prev(a,p) _NODE_FUNC_2(void, set_prev, a, p)
#define attribute_next(a)       _NODE_FUNC_1(attribute_t *, next, a)
#define attribute_set_next(a,n) _NODE_FUNC_2(void, set_next, a, n)
#define attribute_first(a)      _NODE_FUNC_1(attribute_t *, first, a)
#define attribute_last(a)       _NODE_FUNC_1(attribute_t *, last, a)
#define attribute_insert_prev(a,p) _NODE_FUNC_2(void, insert_prev, a, p)
#define attribute_insert_next(a,n) _NODE_FUNC_2(void, insert_next, a, n)
#define attribute_breadth(a)    _NODE_FUNC_1(int, breadth, a)

/* .section. element */

#define ELEMENTF_PARSED 0x1     /* has sub-tree been completely parsed */

typedef struct _element_t {
    node_t node;
    GPtrArray *attributes;
    GHashTable *a_index;        /* attributes index */
    int n_children;             /* -1 if unavailable. */
    short namespace;            /* namespace index */
} element_t;

element_t *
element_new(node_t *parent, const char *name, GPtrArray *attributes);

void
element_init(element_t *element, node_t *parent, const char *name, GPtrArray *attributes);

void
element_free(element_t *element, int keep_children);

const char *
element_name(element_t *element);

void
element_set_name(element_t *element, const char *name);

int
element_attributes(element_t *element);

attribute_t *
element_attribute(element_t *element, const char *attr_name);

attribute_t *
element_attribute_index(element_t *element, int attr_index);

int
element_set_attribute(element_t *element, const char *attr_name, typed_value_t *attr_value);

int
element_set_attribute_index(element_t *element, int attr_index, typed_value_t *attr_value);

/* element_attribute_XXX */
#define _element_attribute_decl(vn, vt) \
    vt element_attribute_##vn(element_t *element, const char *attr_name);
TYPED_VALUE_GENERIC(_element_attribute_decl);

/* element_attribute_XXX_index */
#define _element_attribute_index_decl(vn, vt) \
    vt element_attribute_##vn##_index(element_t *element, int attr_index);
TYPED_VALUE_GENERIC(_element_attribute_index_decl);

/* element_set_attribute_XXX */
#define _element_set_attribute_decl(vn, vt) \
    int element_set_attribute_##vn(element_t *element, const char *attr_name, vt attr_value);
TYPED_VALUE_GENERIC(_element_set_attribute_decl);

/* element_set_attribute_XXX_index */
#define _element_set_attribute_index_decl(vn, vt) \
    int element_set_attribute_##vn##_index(element_t *element, int attr_index, vt attr_value);
TYPED_VALUE_GENERIC(_element_set_attribute_index_decl);

int
element_set_attribute_direct(element_t *element, attribute_t *attribute);

int
element_remove_attribute(element_t *element, const char *attr_name);

int
element_remove_attribute_index(element_t *element, int attr_index);

int
element_remove_attribute_direct(element_t *element, attribute_t *attribute);

int
element_add_child(element_t *element, node_t *child, node_t *insert_before);

int
element_add_child_index(element_t *element, node_t *child, int insert_before);

int
element_remove_child(element_t *element, node_t *child);

int
element_remove_child_index(element_t *element, int child_index);

void
element_remove_children(element_t *element);

int
element_add_sibling(element_t *element, node_t *sibling, node_t *insert_before);

int
element_add_sibling_index(element_t *element, node_t *sibling, int insert_before);

int
element_remove_sibling(element_t *element, node_t *sibling);

int
element_remove_sibling_index(element_t *element, int sibling_index);

#define ELEMENT_WALK_ALL (ELEMENT_WALK_CHILD \
                          | ELEMENT_WALK_ATTRIBUTE \
                          | ELEMENT_WALK_TEXT \
                          | ELEMENT_WALK_PI \
                          | ELEMENT_WALK_COMMENT \
                          | ELEMENT_WALK_THIS \
                          | ELEMENT_WALK_RECURSIVE)
#define ELEMENT_WALK_CHILD      1
#define ELEMENT_WALK_ATTRIBUTE  2
#define ELEMENT_WALK_TEXT       4
#define ELEMENT_WALK_PI         8
#define ELEMENT_WALK_COMMENT    16
#define ELEMENT_WALK_THIS       32
#define ELEMENT_WALK_RECURSIVE  0x8000
#define ELEMENT_WALK_NEXT       0       /* continue walking, add count by 1 */
#define ELEMENT_WALK_SKIP       1       /* continue walking, don't add count */
#define ELEMENT_WALK_CANCEL     -1      /* cancel walking */
int
element_walk(element_t *element,
             int (*walk_cb)(node_t *node, void *user),
             void *user,
             int flags);

GSList *
element_select_by_name(element_t *element, const char *name);

#define ELEMENT_SELECT_EXCLUDE  0
#define ELEMENT_SELECT_INCLUDE  1
GSList *
element_select_by_walk(element_t *element,
                       int (*test_cb)(node_t *node, void *user),
                       void *user,
                       int walk_flags);

GString *
element_flatten_text(element_t *element);

/* inherits */
#define element_parent(e)       _NODE_FUNC_1(element_t *, parent, e)
#define element_root(e)         _NODE_FUNC_1(element_t *, root, e)
#define element_prev(e)         _NODE_FUNC_1(node_t *, prev, e)
#define element_next(e)         _NODE_FUNC_1(node_t *, next, e)
#define element_first(e)        _NODE_FUNC_1(node_t *, first, e)
#define element_last(e)         _NODE_FUNC_1(node_t *, last, e)
#define element_prev_element(e) _NODE_FUNC_1X(element_t *, prev_type, e, NODE_ELEMENT)
#define element_next_element(e) _NODE_FUNC_1X(element_t *, next_type, e, NODE_ELEMENT)
#define element_breadth(e)      _NODE_FUNC_1(int, breadth, e)
#define element_depth(e)        _NODE_FUNC_1(int, depth, e)

/* overrides */
void
element_detach(element_t *element, int merge_children);

element_t *
element_set_parent(element_t *element, element_t *parent);

element_t *
element_set_prev(element_t *element, node_t *prev);

element_t *
element_set_next(element_t *element, node_t *next);

void
element_insert_prev(element_t *element, node_t *prev);

void
element_insert_next(element_t *element, node_t *next);

/* .section. simxml */

typedef struct _simxml_context_t {
    GPtrArray *namespaces;
    GTree *lookup;              /* fast existence test */
    GHashTable *prefixes;       /* prefix -> ns-uri */
    GHashTable *variables;
} simxml_context_t;

typedef struct _simxml_t {
    simxml_context_t *context;
    element_t *root;
    parser_context_t *parser_context;
} simxml_t;

simxml_t *
simxml_new(simxml_context_t *context, element_t *root);

void
simxml_free(simxml_t *simxml);

int                             /* return namespace index */
simxml_add_namespace(const char *namespace_uri);

int
simxml_remove_namespace(const char *namespace_uri);

void
simxml_remove_namespace_index(int index);

void *
simxml_variable(const char *name);

void
simxml_set_variable(const char *name, void *value);

void
simxml_dump(simxml_t *simxml,
            void (*printer)(void *user, const char *fmtstr, ...),
            void *user);

element_t *
simxml_root(simxml_t *simxml);

void *
simxml_set_root(simxml_t *simxml, element_t *root);

#endif
