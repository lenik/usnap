#include <stdio.h>
#include <string.h>
#include <glib.h>
#include "defs.h"
#include "simxml.h"
#include "util.h"

/* .section. node */

#define ERR_INCONS_PARENT "siblings have different parent"
#define ERR_INCONS_SIBLING "siblings connected in wrong way"
#define ERR_NODE_DUP "looped nodes detected: duplicated entry"
#define ERR_NODE_LOST "node lost: a node isn't listed in the flattened index"
#define ERR_ATTACHED "node has already been attached"
#define ERR_INV_FLAT "unexpected: wrong flat pointer"

static gboolean
_node_check_failure_default(const char *msg, node_t *err, node_t *ref) {
    char buffer[1000];
    char head[200];
    char *p = buffer;

    ASSERT(msg);
    ASSERT(err);

    p += sprintf(p,
                 "node_check_failure: %s\n"
                 "error node 0x%08x (%s: \"%s\", parent=0x%08x)\n",
                 msg,
                 err, node_typename(err),
                 strhead(head, err->text, sizeof(head)), err->parent);
    if (ref)
        p += sprintf(p,
                     "reference node 0x%08x (%s: \"%s\", parent=0x%08x)\n",
                     ref, node_typename(ref),
                     strhead(head, ref->text, sizeof(head)), ref->parent);
    g_error(buffer);
    return FALSE;
}

static gboolean (*node_check_failure)(const char *, node_t *, node_t *) =
    _node_check_failure_default;

gboolean
_node_check_node(flat_t *flat, node_t *start, gboolean upwards) {
    node_t *prevs = start;

    ASSERT(flat);
    ASSERT(start);

    if (upwards)
        start = start->next;    /* skip the start node in siblings */

    while (start) {
        if (start->parent != prevs->parent)
            if (! node_check_failure(ERR_INCONS_PARENT, start, prevs))
                return FALSE;
        if (flat_contain(flat, start))
            if (! node_check_failure(ERR_NODE_DUP, start, NULL))
                return FALSE;
        flat_add(flat, start);
#ifdef SIMXML_CHECK_INCONSISTENCY
        start->flat = flat;     /* #node.check_node.1 */
#endif
        if ((start->next && start != start->next->prev))
            if (! node_check_failure(ERR_INCONS_SIBLING, start, start->next))
                return FALSE;
        if ((start->prev && start != start->prev->next))
            if (! node_check_failure(ERR_INCONS_SIBLING, start, start->prev))
                return FALSE;

        if (start->child)
            if (! _node_check_node(flat, start->child, FALSE))
                return FALSE;

        start = start->next;
    }

    start = prevs;
    while (prevs = prevs->prev) {
        if (prevs->parent != start->parent) {
            if (! node_check_failure(ERR_INCONS_PARENT, prevs, start))
                return FALSE;
        }
        if (flat_contain(flat, prevs)) {
            if (! node_check_failure(ERR_NODE_DUP, prevs, NULL))
                return FALSE;
        }

        flat_add(flat, prevs);
#ifdef SIMXML_CHECK_INCONSISTENCY
        prevs->flat = flat;     /* #node.check_node.1 */
#endif
        if ((prevs->next && prevs != prevs->next->prev))
            if (! node_check_failure(ERR_INCONS_SIBLING, prevs, prevs->next))
                return FALSE;
        if ((prevs->prev && prevs != prevs->prev->next))
            if (! node_check_failure(ERR_INCONS_SIBLING, prevs, prevs->prev))
                return FALSE;

        if (prevs->child)
            if (! _node_check_node(flat, prevs->child, FALSE))
                return FALSE;
    }

    if (upwards)
        if (start->parent)
            return _node_check_node(flat, start->parent, TRUE);
    return TRUE;
}

gboolean
node_check_node(flat_t *flat, node_t *node) {
    ASSERT(flat);
    ASSERT(node);
    return _node_check_node(flat, node, FALSE)
        && _node_check_node(flat, node, TRUE);
}

gboolean
node_check_add(flat_t *flat, node_t *add) {
    ASSERT(add);

    if (add->parent)
        if (! node_check_failure(ERR_ATTACHED, add, add->parent))
            return FALSE;
    /* ignore add->flat */

    if (flat_contain(flat, add))
        if (! node_check_failure(ERR_NODE_DUP, add, NULL))
            return FALSE;

    flat_add(flat, add);
#ifdef SIMXML_CHECK_INCONSISTENCY
    add->flat = flat;
#endif
    return TRUE;
}

gboolean
node_check_remove(flat_t *flat, node_t *remove) {
    node_t *root;
    node_t *prevs;

    ASSERT(remove);

    if (flat == NULL) {
#ifdef SIMXML_CHECK_INCONSISTENCY
        /* find ancestors if not specified */
        for (root = remove; root; root = root->parent)
            if (root->flat) {
                flat = root;
                break;
            }
#endif
        ASSERT(flat != NULL);
    }

    if (! flat_contain(flat, remove))
        if (! node_check_failure(ERR_NODE_LOST, remove, NULL))
            return FALSE;
    flat_remove(flat, remove);

    if (remove->child) {
        prevs = remove->child;
        while (prevs = prevs->prev)
            if (! node_check_remove(flat, prevs))
                return FALSE;
        remove = remove->child;
        while (remove) {
            if (! node_check_remove(flat, remove))
                return FALSE;
            remove = remove->next;
        }
    }

    if (flat_size(flat) == 0)
        flat_free(flat);
    return TRUE;
}

flat_t *
node_flat(node_t *node) {
    flat_t *flat;
    ASSERT(node);
#ifdef SIMXML_CHECK_INCONSISTENCY
    if (node->flat)
        return node->flat;
    if (node->parent)
        return node->flat = node_flat(node->parent);
#endif
    flat = flat_new();
    node_check_node(flat, node);
    return flat;
}

node_t *
node_new(node_t *parent, int type, const char *text) {
    node_t *node = g_new(node_t, 1);
    node_init(node, parent, type, text);
    return node;
}

void
node_init(node_t *node, node_t *parent, int type, const char *text) {
    ASSERT(node);
    node->type = type;
    node->text = text ? strdup(text) : NULL;
    node->prev = NULL;
    node->next = NULL;
    node->parent = NULL;
    if (parent) {
        node_set_parent(node, parent);
    } else {
        NODE_FLAT(node);        /* build new flat if not exists */
    }
}

void
node_free(node_t *node) {       /* free all */
    ASSERT(node);
    node_detach(node);
    node_free_recursive(node);
}

void
node_free_recursive(node_t *node) {
    ASSERT(node);
    if (node->child) {
        node_t *child = node->child->prev;
        node_t *remove;
        while (child) {
            remove = child;
            child = child->prev;
            node_free_recursive(remove);
        }
        child = node->child;
        while (child) {
            remove = child;
            child = child->next;
            node_free_recursive(remove);
        }
    }
    if (node->text)
        free(node->text);
    free(node);
}

void
node_detach(node_t *node) {
    ASSERT(node);
#ifdef SIMXML_CHECK_INCONSISTENCY
    NODE_CHECK_REMOVE(node);
#endif
    if (node->parent) {
        if (node->parent->child == node) {
            /* modify the child pointer to point to any other node in
               the siblings */
            if (node->prev)
                node->parent->child = node->prev;
            else if (node->next)
                node->parent->child = node->next;
            else
                node->parent->child = NULL;
        }
        node->parent = NULL;
    }
    if (node->prev)
        node->prev->next = node->next;
    node->prev = NULL;
    if (node->next)
        node->next->prev = node->prev;
    node->next = NULL;
}

node_t *
node_swap_children(node_t *node) {
    node_t *child_first = NULL;
    node_t *child_last;

    ASSERT(node);
#ifdef SIMXML_CHECK_INCONSISTENCY
    ASSERT(node->flat);
    /* Don't use NODE_CHECK_REMOVE which will do remove recursively */
    flat_remove(node->flat, node);
    node->flat = NULL;
#endif

    if (node->child) {
        /* move children up to substitute out self */
        child_first = node_first(node->child);
        child_last = node_last(node->child);

        child_first->prev = node->prev;
        if (node->prev)
            node->prev->next = child_first;
        child_last->next = node->next;
        if (node->next)
            node->next->prev = child_last;

        node->child = NULL;
    }

    if (node->parent) {
        if (node->parent->child == node) {
            /* modify the child pointer to point to any other node in
               the siblings */
            if (node->prev)
                node->parent->child = node->prev;
            else if (node->next)
                node->parent->child = node->next;
            else
                node->parent->child = NULL;
        }
        node->parent = NULL;
    }

    node->prev = NULL;
    node->next = NULL;

    return child_first;
}

int
node_type(node_t *node) {
    ASSERT(node);
    return node->type;
}

static const char *typenames[] = {
    "node",
    "element",
    "attribute",
    "text",
    "processing-instruction",
    "comment",
};
static int ntypenames = sizeof(typenames) / sizeof(typenames[0]);

const char *
node_typename(node_t *node) {
    ASSERT(node);
    if (node->type >= 0 && node->type < ntypenames) {
        return typenames[node->type];
    }
    return "undefined";
}

const char *
node_text(node_t *node) {
    ASSERT(node);
    return node->text;
}

void
node_set_text(node_t *node, const char *text) {
    ASSERT(node);
    if (node->text)
        free(node->text);
    node->text = text ? strdup(text) : NULL;
}

node_t *
node_prev(node_t *node) {
    ASSERT(node);
    return node->prev;
}

node_t *
node_set_prev(node_t *node, node_t *prev) {
    node_t *old_prev = node->prev;
    ASSERT(node);
    if (prev == old_prev)
        return prev;
    if (old_prev)
        node_detach(old_prev);
    if (prev) {
        node_insert_prev(node, prev);
    }
    return old_prev;
}

node_t *
node_next(node_t *node) {
    ASSERT(node);
    return node->next;
}

node_t *
node_set_next(node_t *node, node_t *next) {
    node_t *old_next = node->next;
    ASSERT(node);
    if (next == old_next)
        return next;
    if (old_next)
        node_detach(old_next);
    if (next) {
        node_insert_next(node, next);
    }
    return old_next;
}

node_t *
node_prev_type(node_t *node, int node_type) {
    ASSERT(node);
    while (node = node->prev) {
        if (node->type == node_type)
            return node;
    }
    return NULL;
}

node_t *
node_next_type(node_t *node, int node_type) {
    ASSERT(node);
    while (node = node->next) {
        if (node->type == node_type)
            return node;
    }
    return NULL;
}

node_t *
node_first(node_t *node) {
    ASSERT(node);
    while (node->prev) node = node->prev;
    return node;
}

node_t *
node_last(node_t *node) {
    ASSERT(node);
    while (node->next) node = node->next;
    return node;
}

void
node_insert_prev(node_t *node, node_t *prev) {
    ASSERT(node);
    ASSERT(prev);
    ASSERT(! prev->prev);
    ASSERT(! prev->next);
    NODE_CHECK_ADD(node, prev);
    if (node->prev)
        node->prev->next = prev;
    prev->prev = node->prev;
    prev->next = node;
    node->prev = prev;
    prev->parent = node->parent;
}

void
node_insert_next(node_t *node, node_t *next) {
    ASSERT(node);
    ASSERT(next);
    ASSERT(! next->prev);
    ASSERT(! next->next);
    NODE_CHECK_ADD(node, next);
    if (node->next)
        node->next->prev = next;
    next->next = node->next;
    next->prev = node;
    node->next = next;
    next->parent = node->parent;
}

node_t *
node_root(node_t *node) {
    ASSERT(node);
    while (node->parent) node = node->parent;
    return node;
}

node_t *
node_parent(node_t *node) {
    ASSERT(node);
    return node->parent;
}

node_t *
node_set_parent(node_t *node, node_t *parent) {
    node_t *old_parent = node->parent;
    ASSERT(node);
    if (parent == old_parent)
        return parent;
    if (old_parent)
        node_detach(node);
    if (parent) {
        NODE_CHECK_ADD(parent, node);
        if (! parent->child) {
            parent->child = node;
        } else {
            node_insert_next(parent->child, node);
            parent->child = node;
        }
        parent->child = node;
    }
    node->parent = parent;
    return old_parent;
}

node_t *
node_child(node_t *node) {
    ASSERT(node);
    return node->child;
}

node_t *
node_set_child(node_t *node, node_t *child) {
    node_t *old_child = node->child;
    ASSERT(node);
    if (child == old_child)
        return child;
    if (old_child)
        node_detach(old_child);
    /* #node.set_child */
    if (child) {
        NODE_CHECK_ADD(node, child);
        child->parent = node;
    }
    node->child = child;
    return old_child;
}

void
node_remove_children(node_t *node) {
    ASSERT(node);
    if (node->child) {
        node_t *child = node_first(node->child);
        node->child = NULL;     /* #node.remove_children */
        while (child) {
            node_free(child);
            child = child->next;
        }
    }
}

int
node_breadth(node_t *node) {
    int breadth = 0;
    node_t *prevs;

    ASSERT(node);
    if (node == NULL) return 0;

    prevs = node;
    while (prevs = prevs->prev)
        breadth++;
    while (node) {
        breadth++;
        node = node->next;
    }

    return breadth;
}

int
node_depth(node_t *node) {
    int depth = 1;

    ASSERT(node);
    if (node == NULL) return 0;

    while (node->parent) {
        node = node->parent;
        depth++;
    }

    return depth;
}


/* .section. attribute */

attribute_t *
attribute_new(node_t *parent, const char *name, typed_value_t *value) {
    attribute_t *attribute;
    ASSERT(name);
    attribute = g_new(attribute_t, 1);
    node_init((node_t *)attribute, parent, NODE_ATTRIBUTE, name);
    typed_value_set(&attribute->value, value);
    return attribute;
}

/* attribute_new_XXX */
#define _attribute_new_impl(vn, vt) \
    attribute_t * \
    attribute_new_##vn(node_t *parent, const char *name, vt value) { \
        attribute_t *attribute; \
        ASSERT(name);  \
        attribute = g_new(attribute_t, 1); \
        node_init((node_t *)attribute, parent, NODE_ATTRIBUTE, name); \
        typed_value_set_##vn(&attribute->value, value); \
        return attribute; \
    }
TYPED_VALUE_GENERIC(_attribute_new_impl);

void
attribute_free(attribute_t *attribute) {
    ASSERT(attribute);
    ASSERT(attribute->node.text);
    typed_value_unset(&attribute->value);
    node_free((node_t *)attribute);
}

typed_value_t *
attribute_value(attribute_t *attribute) {
    ASSERT(attribute);
    return &attribute->value;
}

void
attribute_set_value(attribute_t *attribute, typed_value_t *value) {
    ASSERT(attribute);
    typed_value_unset(&attribute->value);
    typed_value_set(&attribute->value, value);
}

/* attribute_value_XXX */
#define _attribute_value_impl(vn, vt) \
    vt \
    attribute_value_##vn(attribute_t *attribute) { \
        ASSERT(attribute); \
        return typed_value_get_##vn(&attribute->value); \
    }
TYPED_VALUE_GENERIC(_attribute_value_impl);

/* attribute_set_value_XXX */
#define _attribute_set_value_impl(vn, vt) \
    void \
    attribute_set_value_##vn(attribute_t *attribute, vt value) { \
        ASSERT(attribute); \
        typed_value_set_##vn(&attribute->value, value); \
    }
TYPED_VALUE_GENERIC(_attribute_set_value_impl);


/* .section. element */

element_t *
element_new(node_t *parent, const char *name, GPtrArray *attributes) {
    element_t *element;
    ASSERT(name);
    element = (element_t *)g_new(element_t, 1);
    element_init(element, parent, NODE_ELEMENT, name);
    return element;
}

void
element_init(element_t *element, node_t *parent, const char *name, GPtrArray *attributes) {
    ASSERT(element);
    ASSERT(name);
    node_init((node_t *)element, parent, NODE_ELEMENT, name);
    element->attributes = attributes;
    element->n_children = -1;
}

void
element_free(element_t *element) {
    ASSERT(element);
    /* keep-children:
     *   node_swap_children(element)
     *   element_free(element)
     */
    if (element->attributes)
        attributes_free(element->attributes);
    if (element->a_index)
        g_hash_table_free(element->a_index);
    node_free((node_t *)element);
}


/* .section. simxml */

static const char *built_in_namespaces[] = {
    "six",
    "http://www.bodz.net/xml/c/simxml",
    "simxml",
    "http://www.bodz.net/xml/c/simxml",
};

static int n_built_in_namespaces =
    sizeof(built_in_namespaces) / sizeof(const char *) / 2;

static const char *built_in_variables[] = {
    "_version", "1.0",
    "_author", "Xima J.Lenik",
    "_site", "http://xjl.sourceforge.net/simxml",
    "_copyright", "(C)Copyright TC & S-FIA, 2005",
};

simxml_context_t *
simxml_context_new() {
    simxml_context_t *context;
    int i;
    context = g_new(simxml_context_t, 1);
    context->namespaces = g_ptr_array_new();
    context->lookup = g_tree_new();
    context->prefixes = g_hash_table_new(g_string_equal, g_string_hash);
    context->variables = g_hash_table_new(g_string_equal, g_string_hash);
    for (i = 0; i < n_built_in_namespaces; i += 2)
        simxml_add_namespace(built_in_namespaces[i],
                             built_in_namespaces[i + 1]);
    for (i = 0; i < n_built_in_variables; i += 2)
        simxml_add_variable_string(built_in_variables[i],
                                   built_in_variables[i + 1]);
    return context;
}

simxml_t *
simxml_new(simxml_context_t *context, element_t *root) {
    simxml_t *simxml;
    simxml = g_new(simxml_t, 1);
    simxml->context = context;
    simxml->root = root;
    return simxml;
}

void
simxml_add_namespace(simxml_context_t *context, const char *ns_prefix, const char *ns_uri) {
    ASSERT(context);
    ASSERT(context->namespaces);
    ASSERT(context->prefixes);
    ASSERT(uri);
    if (g_tree_lookup(context->lookup, ns_uri))
        ns_uri = g_tree_get(ns_uri);
    g_ptr_array_append(context->namespaces, ns_uri);
    g_hash_table_insert(context->prefixes, ns_prefix, ns_uri);
    g_tree_insert(context->lookup, ns_uri);
}
