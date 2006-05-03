
#include "../libns.h"

void console_out(nssvc_t *svc, x32_t sel, const void *data, size_t size) {
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
    return 0;
}

int main() {
    nsiodrv_t drv;
    nssvc_t *svc;
    svc = nsnew();
    while () {
        svc->pkt_in();
    }
    return 0;
}
