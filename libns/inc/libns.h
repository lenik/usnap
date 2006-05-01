

typedef struct _nsiodrv_t nsiodrv_t;
typedef struct _nssvc_t nssvc_t;

struct _nsiodrv_t {
    void (_stdcall *out)(x32_t, size_t, void *);
    void (_stdcall *close)();
};

struct _nssvc_t {
    const char *name;
    nsiodrv_t *drv;
    void (_stdcall *pkt_in)(nssvc_t *, x32_t, size_t, void *);
    void (_stdcall *bin_in)(nssvc_t *, x32_t, size_t, void *);
    void (_stdcall *cmd_in)(nssvc_t *, x32_t, nscmd_t *, void **args, int nopts);
    list_t mods;
};

static nsiodrv_t siodrv {
    &siodrv_out,
    &siodrv_close,
};

void siodrv_pkt_in(sioctx_t *sioctx, size_t size, void *data) {
    nssvc_t *svc = sioctx->user;
    svc->pkt_in(svc, 0, size, data);
}

// nssvc_t *nsnew(void out

typedef enum _param_type_t param_type_t;
typedef struct _nscmd_t nscmd_t;
typedef struct _nsmod_t nsmod_t;

enum _param_type_t {
    PARAMTYPE_INT,                      /* int */
    PARAMTYPE_LONG,                     /* long */
    PARAMTYPE_SHORT,                    /* short */
    PARAMTYPE_CHAR,                     /* char */
    PARAMTYPE_FLOAT,                    /* float */
    PARAMTYPE_DOUBLE,                   /* double */
    PARAMTYPE_BOOL,                     /* char (format: 'true', 'false') */
    PARAMTYPE_STRING = 0,               /* const char * */
    PARAMTYPE_BIN,                      /* const void *, size_t */
    PARAMTYPE_ARRAY = 0x1000,           /* (<type> *) */
    PARAMTYPE_VT = 0x2000,              /* (typed_value_t<type> *) */
} param_type_t;

#define NSCMDF_HIDDEN 1                 /* invisible in high-level prog-lang */
#define NSCMDF_ASYNC 2                  /* asynchronized command */

struct _nscmd_t {
    const char *name;
    u32_t flags;
    u32_t (_stdcall *cmdmain)(nssvc_t *svc, void **args, int nopts);
    const param_type_t *args;
    u32_t nargs;
    const param_type_t *opts;           /* optional parameters */
    u32_t nopts;
    nscmd_t *subcmds;                   /* load into sub symbol table */
    u32_t nsubcmds;
    const char *help;
    const char *version;
};

struct _nsmod_t {
    const nscmd_t *cmds;
    int ncmds;
    const char *help;
    const char *version;
};
