
#include "stdhdrs.h"
#include <cpf/assert.h>
#include <cpf/net/siof.h>

#include "libns.h"

static void _stdcall sio_out(x32_t sel, void *data, size_t size) {
}

static void _stdcall sio_close() {
}

nsdrv_t *drvsio = {
    sio_out,
    sio_close,
};
