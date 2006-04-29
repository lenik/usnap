
#include "types.h"

typedef struct nscmd_t {
    const char *name;
    u32_t flags;
    u32_t (_stdcall *entry)(void **args);
    const param_type_t *args;
    u32_t nargs;
    const param_type_t *opts;           /* optional parameters */
    u32_t nopts;
    nscmd_t *subcmds;                   /* load into sub symbol table */
    u32_t nsubcmds;
    const char *help;
    const char *version;
} nscmd_t;

typedef struct nsext_t {
    const nscmd_t *cmds;
    int ncmds;
    const char *help;
    const char *version;
} nsext_t;


/**
 * TODO
 *   - built-in commands:
 *     .ver [<cmd-name>]
 *     .help [<cmd-name>]
 *     .osinfo (uname, uid/gid, netinfo, etc.)
 *
 *     .bind <application> [<port>]
 *     .connect <remote-ip:port> [<port>]
 *
 *     .pwd .cd .mkdir .rmdir
 *     .cp .mv .rm
 *     .ps .kill
 *
 *     .get "<path>" [<offset> [<size>]]
 *         recv: 200 { <chunk-base64> }
 *     .put "<path>" [<offset> [<size>]] { <chunk-base64> }
 *         recv: 200
 *     .resize "<path>" <new-size>
 *
 *   - command syntax
 *     char-escape:
 *       \x?? \u???? \n \t
 *       \h{XXYYZZ...}
 *
 *
 */
