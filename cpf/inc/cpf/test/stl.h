#ifndef _stl_utim_dePCtWbFr8U8faBH_
#define _stl_utim_dePCtWbFr8U8faBH_ "$Header: /mnt/c/.radiko/.miaj/cvs/usnap/cpf/inc/cpf/test/stl.h,v 1.1 2006-05-14 23:38:42 dansei Exp $"

typedef struct _stl_token_t stl_token_t;
typedef struct _stl_project_t stl_project_t;

#define STL_MAX_TOKENS 256

struct _stl_token_t {
    char cmd;
    const char *name;
    /* Int, Long, Float, Double, Char, String */
    const char *args;
    int (_stdcall *func)(x64_t *);
};

struct _stl_project_t {
    /* token def */
    stl_token_t tokens[STL_MAX_TOKENS];
    int ntokens;

    /* text script */
    const char *text;
    char *textcpy;
    const char *last_error;
    int total;
    int succeeds;
    int ttotal[STL_MAX_TOKENS];
    int tsucceeds[STL_MAX_TOKENS];

    /* cache */
    stl_token_t cmap[256];              /* ascii -> token */
};

int stl_test(stl_project_t *project);
int stl_report(stl_project_t *project);

#endif
