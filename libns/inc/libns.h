
class bin_in {
};

class bin_out {
};

typedef enum _param_type_t param_type_t;
typedef struct _nscmd_t nscmd_t;
typedef struct _nsext_t nsext_t;

enum _param_type_t {
    PARAMTYPE_STRING = 0,               /* const char * */
    PARAMTYPE_INT = 1,                  /* int */
    PARAMTYPE_LONG = 2,                 /* long */
    PARAMTYPE_SHORT = 3,                /* short */
    PARAMTYPE_CHAR = 4,                 /* char */
    PARAMTYPE_FLOAT = 5,                /* float */
    PARAMTYPE_DOUBLE = 6,               /* double */
    PARAMTYPE_BOOL = 7,                 /* char (format: 'true', 'false') */
    PARAMTYPE_BIN = 8,                  /* const void *, size_t */
    PARAMTYPE_ARRAY = 0x1000,           /* (<type> *) */
    PARAMTYPE_VT = 0x2000,              /* (typed_value_t<type> *) */
} param_type_t;

#define NSCMDF_HIDDEN 1                 /* invisible in high-level prog-lang */
#define NSCMDF_ASYNC 2                  /* asynchronized command */

struct _nscmd_t {
    const char *name;
    u32_t flags;
    u32_t (_stdcall *entry)(void **args, int nopts);
    const param_type_t *args;
    u32_t nargs;
    const param_type_t *opts;           /* optional parameters */
    u32_t nopts;
    nscmd_t *subcmds;                   /* load into sub symbol table */
    u32_t nsubcmds;
    const char *help;
    const char *version;
} nscmd_t;

struct nsext_t {
    const nscmd_t *cmds;
    int ncmds;
    const char *help;
    const char *version;
} nsext_t;
