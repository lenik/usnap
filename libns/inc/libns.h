#ifndef _libns_utim_dem35_3EvRCyfopr_
#define _libns_utim_dem35_3EvRCyfopr_ "$Header: /mnt/c/.radiko/.miaj/cvs/com/campofrontier/libns/inc/libns.h,v 1.7 2006-05-15 15:24:45 lenik Exp $"

#include <cpf/dt/raw.h>
#include <cpf/dt/list.h>

typedef struct _nssvc_t nssvc_t;
typedef struct _nsdrv_t nsdrv_t;

typedef enum _nstype_t nstype_t;
typedef struct _nscmd_t nscmd_t;
typedef struct _nscmdi_t nscmdi_t;
typedef struct _nsmod_t nsmod_t;

typedef enum _nserr_t nserr_t;

struct _nssvc_t {
    const char *name;
    nsdrv_t *drv;

    /* binary encoded */
    void (_stdcall *pkt_in)(nssvc_t *, x32_t, void *, size_t);
    void (_stdcall *pkt_out)(nssvc_t *, x32_t, void *, size_t);

    /* includes escaping-chars and control-chars */
    void (_stdcall *bin_in)(nssvc_t *, x32_t, void *, size_t);
    void (_stdcall *bin_out)(nssvc_t *, x32_t, void *, size_t);

    /* EOL of command-line is parsed, text components are encoded in utf-8 */
    void (_stdcall *line_in)(nssvc_t *, x32_t, void *, size_t);
    void (_stdcall *line_out)(nssvc_t *, x32_t, void *, size_t);

    /* texts are decoded to native charset, the line is converted to object */
    void (_stdcall *cmd_in)(nssvc_t *, x32_t, nscmdi_t *, x32_t *, int);
    void (_stdcall *cmd_out)(nssvc_t *, x32_t, nscmdi_t *, x32_t *, int);

    list_t *mods;
    list_t *callstack;

    /* pendings */
    list_t *pd_pkt_in;
    list_t *pd_pkt_out;
    list_t *pd_bin_in;
    list_t *pd_bin_out;
    list_t *pd_line_in;
    list_t *pd_line_out;
    list_t *pd_cmd_in;
    list_t *pd_cmd_out;
};

struct _nsdrv_t {
    void (_stdcall *pkt_out)(x32_t, void *, size_t);
    void (_stdcall *close)();
};

struct _nscodec_t {
    const char *name;
    size_t rest_size;
    void *rest_data;
};

#define NSCMDF_HIDDEN 1                 /* invisible in high-level prog-lang */
#define NSCMDF_ASYNC 2                  /* asynchronized command */

enum _nstype_t {
    NSTYPE_INT,                         /* int */
    NSTYPE_LONG,                        /* long */
    NSTYPE_SHORT,                       /* short */
    NSTYPE_CHAR,                        /* char */
    NSTYPE_FLOAT,                       /* float */
    NSTYPE_DOUBLE,                      /* double */
    NSTYPE_BOOL,                        /* char (format: 'true', 'false') */
    NSTYPE_STRING,                      /* const char * */
    NSTYPE_BIN,                         /* const void *, size_t */
    NSTYPE_ARRAY = 0x1000,              /* (<type> *) */
    NSTYPE_VT = 0x2000,                 /* (typed_value_t<type> *) */
};

#define NSCMD_MAXARGS 32

struct _nscmd_t {
    const char *name;
    u32_t flags;
    u32_t (_stdcall *main)(nssvc_t *svc, x32_t *args, int nopts);
    nstype_t args[NSCMD_MAXARGS];
    i32_t nargs;
    nstype_t opts[NSCMD_MAXARGS]; /* optional parameters */
    i32_t nopts;
    nscmd_t *subcmds;                   /* load into sub symbol table */
    i32_t nsubcmds;
    u32_t iextra;                       /* extra bytes to cmd instance */
    const char *help;
    const char *version;
};

struct _nscmdi_t {
    nscmd_t *proto;
    x32_t *args;
    int nopts;
    /* extra ... */
};

#define nscmdi_ex(t, i) ((t *)(((u8_t *)&(i)) + sizeof(nscmdi_t)))
#define nscmdi_size(i) (sizeof(nscmdi_t) + ((i).proto->iextra))

#define NSMODF_HIDDEN 1

struct _nsmod_t {
    const char *name;
    u32_t flags;
    const nscmd_t *cmds;
    int ncmds;
    const char *help;
    const char *version;
};

#define NSDRV_STDIO         0
#define NSDRV_SIO           1
#define NSDRV_MAX           1

#define NSMOD_CORE          (1L << 0)
#define NSMOD_FS            (1L << 1)
#define NSMOD_HACK          (1L << 2)

nssvc_t * _cc nsnew(const char *name, int builtin_drv, u32_t builtin_mods);
nssvc_t * _cc nsfree(nssvc_t *svc);
int       _cc nsinsmod(nssvc_t *svc, nsmod_t *mod);
int       _cc nsrmmod(nssvc_t *svc, nsmod_t *mod);

enum _nserr_t {
    NSERR_OK = 0,
    NSERR_FAIL,
    NSERR_NEXT,
};

#endif
