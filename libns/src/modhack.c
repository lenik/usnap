
#include "stdhdrs.h"
#include <cpf/assert.h>

#include "libns.h"

/* modhack - Hack utilities */

u32_t _stdcall modhack_ps(nssvc_t *svc, x32_t *args, int nopts) {
    return NSERR_OK;
}

/* .section.  mod exports */

#define MODHACK_VERSION "modhack $Revision: 1.3 $"
#define MODHACK_HELPSTR "modhack is designed for hacking purpose. "

enum MODHACK_CMD {
    MODHACK_PS,
    MODHACK_KILL,
    MODHACK_EXEC,
    MODHACK_SHELLCODE,
    MODHACK_PORTS,
    MODHACK_BIND,
    MODHACK_CONNECT,
    MODHACK_HIDE,
};

static nscmd_t modhack_cmds[] = {
    { "ps", NSCMDF_HIDDEN, modhack_ps,  /* ps([options]) */
      { 0 }, 0, { NSTYPE_STRING }, 1,
      NULL, 0, 0,
      "ps [-<options>]\n"
      "\t" "show process info",
      MODHACK_VERSION },
};

nsmod_t modhack = {
    "modhack", NSMODF_HIDDEN, modhack_cmds,
    sizeof(modhack_cmds) / sizeof(modhack_cmds[0]),
    MODHACK_HELPSTR, MODHACK_VERSION
};
