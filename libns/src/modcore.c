
#include "libns.h"

/* .section.  mod def */

u32_t _stdcall modcore_ver(nssvc_t *svc, x32_t *args, int nopts) {
    const char *name = NULL;
    int detail = 0;
    if (nopts > 0) {
        name = args[0].p;
        if (nopts > 1)
            detail = args[1].i;
    }

    return NSERR_OK;
}

u32_t _stdcall modcore_help(nssvc_t *svc, x32_t *args, int nopts) {
    const char *name = NULL;
    int detail = 0;
    if (nopts > 0) {
        name = args[0].p;
        if (nopts > 1)
            detail = args[1].i;
    }
    return NSERR_OK;
}

u32_t _stdcall modcore_bin(nssvc_t *svc, x32_t *args, int nopts) {
    return NSERR_OK;
}

u32_t _stdcall modcore_hex(nssvc_t *svc, x32_t *args, int nopts) {
    return NSERR_OK;
}

u32_t _stdcall modcore_escq(nssvc_t *svc, x32_t *args, int nopts) {
    return NSERR_OK;
}

u32_t _stdcall modcore_escqq(nssvc_t *svc, x32_t *args, int nopts) {
    return NSERR_OK;
}

u32_t _stdcall modcore_base64(nssvc_t *svc, x32_t *args, int nopts) {
    return NSERR_OK;
}

/* .section.  mod export */

#define MODCORE_VER "modcore $Revision: 1.1 $"
#define MODCORE_HELP \
    "modcore provides the core settings of libns and basic info of installed" \
    " modules/commands"

enum MODCORE_CMD {
    MODCORE_VER,
    MODCORE_HELP,
    MODCORE_BIN,
    MODCORE_HEX,
    MODCORE_ESCQ,
    MODCORE_ESCQQ,
    MODCORE_BASE64,
};

static nscmd_t *modcore_cmds = {
    { "ver" , 0, modcore_ver,           /* ver([cmd], [detail]) */
      NULL, 0, { PARAMTYPE_STRING, PARAMTYPE_BOOL }, 2,
      NULL, 0,
      "ver [<mod or cmd> [<bool detail>]\n"
      "\t" "display the version info of specified module or command",
      MODCORE_VER },

    { "help", 0, modcore_help,          /* help([cmd], [detail]) */
      NULL, 0, { PARAMTYPE_STRING, PARAMTYPE_BOOL }, 2,
      NULL, 0,
      "help [<mod or cmd> [<bool detail>]]\n"
      "\t" "display the help info of specified module or command",
      MODCORE_VER },

    { "bin", 0, modcore_bin,            /* bin() */
      NULL, 0, NULL, 0,
      NULL, 0,
      "bin\n"
      "\t" "using bin encoding for the following commands",
      MODCORE_VER },

    { "hex", 0, modcore_hex,            /* hex() */
      NULL, 0, NULL, 0,
      NULL, 0,
      "hex\n"
      "\t" "using hex encoding for the following commands",
      MODCORE_VER },

    { "escq", 0, modcore_escq,          /* escq() */
      NULL, 0, NULL, 0,
      NULL, 0,
      "escq\n"
      "\t" "using single-quote (\')escaped string for the following commands",
      MODCORE_VER },

    { "escqq", 0, modcore_escqq,        /* escqq() */
      NULL, 0, NULL, 0,
      NULL, 0,
      "escqq\n"
      "\t" "using double-quote (\") escaped string for the following commands",
      MODCORE_VER },

    { "base64", 0, modcore_base64,      /* base64() */
      NULL, 0, NULL, 0,
      NULL, 0,
      "base64\n"
      "\t" "using base64 encoding for the following commands",
      MODCORE_VER },
};

nsmod_t modcore = {
    "modcore",
    modcore_cmds,
    sizeof(modcore_cmds) / sizeof(modcore_cmds[0]),
    MODCORE_HELP, MODCORE_VER
};