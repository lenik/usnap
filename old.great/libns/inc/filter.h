#ifndef _codec_utim_c7wVeVt9x8gyeuVZ_
#define _codec_utim_c7wVeVt9x8gyeuVZ_ "$Id: filter.h,v 1.3 2006-05-14 04:59:39 lenik Exp $"

#include <cpf/dt/raw.h>

void _stdcall nsdef_pkt_in(nssvc_t *svc, x32_t sel, void *data, size_t size);
void _stdcall nsdef_bin_in(nssvc_t *svc, x32_t sel, void *data, size_t size);
void _stdcall nsdef_line_in(nssvc_t *svc, x32_t sel, void *data, size_t size);
void _stdcall nsdef_cmd_in(nssvc_t *svc, x32_t sel, nscmd_t *cmd,
                           x32_t *args, int nopts);
void _stdcall nsdef_cmd_out(nssvc_t *svc, x32_t sel, nscmd_t *cmd,
                            x32_t *args, int nopts);
void _stdcall nsdef_line_out(nssvc_t *svc, x32_t sel, void *data, size_t size);
void _stdcall nsdef_bin_out(nssvc_t *svc, x32_t sel, void *data, size_t size);
void _stdcall nsdef_pkt_out(nssvc_t *svc, x32_t sel, void *data, size_t size);

#endif
