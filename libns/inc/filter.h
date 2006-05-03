#ifndef _codec_utim_c7wVeVt9x8gyeuVZ_
#define _codec_utim_c7wVeVt9x8gyeuVZ_ "$Id: filter.h,v 1.1 2006-05-03 00:45:06 lenik Exp $"

void _stdcall nsdef_pkt_in(nssvc_t *svc, x32_t sel, void *data, size_t size);
void _stdcall nsdef_bin_in(nssvc_t *svc, x32_t sel, void *data, size_t size);
void _stdcall nsdef_line_in(nssvc_t *svc, x32_t sel, void *data, size_t size);
void _stdcall nsdef_cmd_in(nssvc_t *svc, x32_t sel, nscmd_t *cmd,
                           void **args, int nopts);
void _stdcall nsdef_cmd_out(nssvc_t *svc, x32_t sel, nscmd_t *cmd,
                            void **args, int nopts);
void _stdcall nsdef_line_out(nssvc_t *svc, x32_t sel, void *data, size_t size);
void _stdcall nsdef_bin_out(nssvc_t *svc, x32_t sel, void *data, size_t size);
void _stdcall nsdef_pkt_out(nssvc_t *svc, x32_t sel, void *data, size_t size);

#endif
