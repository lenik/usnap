
#include "stdhdrs.h"
#include <cpf/assert.h>

#include "libns.h"

/* modcore - Core */

/* .section.  mod def */

u32_t _stdcall modcore_ver(nssvc_t *svc, x32_t *args, int nopts) {
    const char *name = 0;
    int detail = 0;
    if (nopts > 0) {
        name = args[0].p;
        if (nopts > 1)
            detail = args[1].i;
    }

    return NSERR_OK;
}

u32_t _stdcall modcore_help(nssvc_t *svc, x32_t *args, int nopts) {
    const char *name = 0;
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

/* .section.  codec impl */

void _stdcall base64_pkt_in(nssvc_t *svc, x32_t sel, void *data, size_t size) {
    svc->bin_in(svc, sel, data, size);
}

void _stdcall base64_bin_out(nssvc_t *svc, x32_t sel, void *data, size_t size) {
    svc->pkt_out(svc, sel, data, size);
}

void _stdcall hex_pkt_in(nssvc_t *svc, x32_t sel, void *data, size_t size) {
    /* concat(rest_data, data); */
    /* decode hex -> bin */
    svc->bin_in(svc, sel, data, size);
}

void _stdcall hex_bin_out(nssvc_t *svc, x32_t sel, void *data, size_t size) {
    /* concat(rest_data, data); */
    /* decode hex -> bin */
    svc->pkt_out(svc, sel, data, size);
}

/* .section.  mod export */

#define MODCORE_VERSION "modcore $Revision: 1.4 $"
#define MODCORE_HELPSTR \
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

static nscmd_t modcore_cmds[] = {
    { "ver" , 0, modcore_ver,           /* ver([cmd], [detail]) */
      { 0 }, 0, { NSTYPE_STRING, NSTYPE_BOOL, }, 2,
      NULL, 0, 0,
      "ver [<mod or cmd> [<bool detail>]\n"
      "\t" "display the version info of specified module or command",
      MODCORE_VERSION },

    { "help", 0, modcore_help,          /* help([cmd], [detail]) */
      { 0 }, 0, { NSTYPE_STRING, NSTYPE_BOOL }, 2,
      NULL, 0, 0,
      "help [<mod or cmd> [<bool detail>]]\n"
      "\t" "display the help info of specified module or command",
      MODCORE_VERSION },

    { "bin", 0, modcore_bin,            /* bin() */
      { 0 }, 0, { 0 }, 0,
      NULL, 0, 0,
      "bin\n"
      "\t" "using bin encoding for the following commands",
      MODCORE_VERSION },

    { "hex", 0, modcore_hex,            /* hex() */
      { 0 }, 0, { 0 }, 0,
      NULL, 0, 0,
      "hex\n"
      "\t" "using hex encoding for the following commands",
      MODCORE_VERSION },

    { "escq", 0, modcore_escq,          /* escq() */
      { 0 }, 0, { 0 }, 0,
      NULL, 0, 0,
      "escq\n"
      "\t" "using single-quote (\')escaped string for the following commands",
      MODCORE_VERSION },

    { "escqq", 0, modcore_escqq,        /* escqq() */
      { 0 }, 0, { 0 }, 0,
      NULL, 0, 0,
      "escqq\n"
      "\t" "using double-quote (\") escaped string for the following commands",
      MODCORE_VERSION },

    { "base64", 0, modcore_base64,      /* base64() */
      { 0 }, 0, { 0 }, 0,
      NULL, 0, 0,
      "base64\n"
      "\t" "using base64 encoding for the following commands",
      MODCORE_VERSION },
};

nsmod_t modcore = {
    "modcore", 0, modcore_cmds,
    sizeof(modcore_cmds) / sizeof(modcore_cmds[0]),
    MODCORE_HELPSTR, MODCORE_VERSION
};
