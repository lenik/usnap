
#include "filter.h"

void _stdcall nsdef_pkt_in(nssvc_t *svc, x32_t sel, void *data, size_t size) {
    svc->bin_in(svc, sel, data, size);
}

void _stdcall nsdef_bin_in(nssvc_t *svc, x32_t sel, void *data, size_t size) {
}

void _stdcall nsdef_line_in(nssvc_t *svc, x32_t sel, void *data, size_t size) {
}

void _stdcall nsdef_cmd_in(nssvc_t *svc, x32_t sel, nscmd_t *cmd,
                           void **args, int nopts) {
}

void _stdcall nsdef_cmd_out(nssvc_t *svc, x32_t sel, nscmd_t *cmd,
                            void **args, int nopts) {
}

void _stdcall nsdef_line_out(nssvc_t *svc, x32_t sel, void *data, size_t size) {
}

void _stdcall nsdef_bin_out(nssvc_t *svc, x32_t sel, void *data, size_t size) {
    svc->pkt_out(svc, sel, data, size);
}

void _stdcall nsdef_pkt_out(nssvc_t *svc, x32_t sel, void *data, size_t size) {
    svc->drv->pkt_out(sel, data, size);
}
