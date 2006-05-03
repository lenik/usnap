
#include "../libns.h"

int main() {
    nssvc_t *svc;
    char line[1000];
    svc = nsnew("libns-test-svc", NSDRV_STDIO,
                NSMOD_CORE | NSMOD_FS | NSMOD_HACK);
    while (gets(line)) {
        svc->pkt_in(svc, 0, line, strlen(line));
    }
    nsfree(svc);
    return 0;
}
