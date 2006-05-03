
#include "libns.h"
#include "builtins.h"

nssvc_t *nsnew(const char *name, int builtin_drv, u32_t builtin_mods) {
    nssvc_t *svc;
    _assert_(builtin_drv >= 0 && builtin_drv <= NSDRV_MAX);

    svc = (nssvc_t *)malloc(sizeof(nssvc_t));
    svc->name = name;

    switch (builtin_drv) {
    case NSDRV_SIO:
        svc->drv = drvsio;
        break;
    default:
        svc->drv = 0;
    }

    svc->pkt_in = nsdef_pkt_in;
    svc->pkt_out = nsdef_pkt_out;
    svc->bin_in = nsdef_bin_in;
    svc->bin_out = nsdef_bin_out;
    svc->line_in = nsdef_line_in;
    svc->line_out = nsdef_line_out;
    svc->cmd_in = nsdef_cmd_in;
    svc->cmd_out = nsdef_cmd_out;

    svc->mods = 0;
    if (builtin_mods & NSMOD_CORE)
        nsinsmod(svc, modcore);
    if (builtin_mods & NSMOD_FS)
        nsinsmod(svc, modfs);
    if (builtin_mods & NSMOD_HACK)
        nsinsmod(svc, modhack);
    return svc;
}

nssvc_t *nsfree(nssvc_t *svc) {
    /* checking pending commands and wait... */
    if (svc->mods)
        list_free(svc->mods);
    if (svc->drv)
        free(svc->drv);
    free(svc);
    return 0;
}

void nsinsmod(nssvc_t *svc, nsmod_t *mod) {
}

void nsrmmod(nssvc_t *svc, nsmod_t *mod) {
}
