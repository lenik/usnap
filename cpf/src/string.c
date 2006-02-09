#include <string.h>
#include <stdarg.h>
#include <cpf/string.h>

int
sprintf_lim(char *buffer, int size, const char *trail,
            const char *fmt, ...) {
    va_list args;
    int ret;
    va_start(args, fmt);
    ret = vsprintf_lim(buffer, size, trail, fmt, args);
    va_end(args);
    return ret;
}

int
vsprintf_lim(char *buffer, int size, const char *trail,
             const char *fmt, va_list args) {
    int cmax = size - 1;
    int need = _vscprintf(fmt, args);
    char *tmp;

    if (need <= cmax)
        return vsprintf(buffer, fmt, args);

    tmp = (char *)malloc(need + 1);
    vsprintf(tmp, fmt, args);
    strncpy(buffer, tmp, cmax);

    if (trail) {
        int trail_len = strlen(trail);
        if (trail_len <= cmax)
            strcpy(buffer + cmax - trail_len,
                   trail);
    }
    return cmax;
}
