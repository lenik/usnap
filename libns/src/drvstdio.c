
#include "stdhdrs.h"
#include <cpf/assert.h>

#include "libns.h"

static void _stdcall stdio_out(nssvc_t *svc, x32_t sel, const void *data,
                               size_t size) {
    FILE *fd;
    switch (sel.i) {
    case 1:                             /* stdout */
        fd = stdout;
        break;
    case 2:
        fd = stderr;
        break;
    default:
        _assert_(0);
    }
    fwrite(data, 1, size, fd);
    return;
}

static void _stdcall stdio_close(nssvc_t *svc, x32_t sel) {
}

nsdrv_t *drvstdio = {
    stdio_out,
    stdio_close,
};
