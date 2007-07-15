
#include "stdhdrs.h"
#include <cpf/string.h>

int _cc
sprintf_lim(char *buffer, int size, const char *trail,
            const char *fmt, ...) {
    va_list args;
    int ret;
    va_start(args, fmt);
    ret = vsprintf_lim(buffer, size, trail, fmt, args);
    va_end(args);
    return ret;
}

int _cc
vsprintf_lim(char *buffer, int size, const char *trail,
             const char *fmt, va_list args) {
    int cc;
    int ntrail;

    if (size == 0)
        return 0;

    cc = _vsnprintf(buffer, size, fmt, args);
    if (cc < size)
        return cc;

    if (trail) {
        ntrail = strlen(trail) + 1;
        if (ntrail <= size)
            strcpy(buffer + size - ntrail, trail);
        else
            strcpy(buffer, trail + ntrail - size);
    } else {
        buffer[size - 1] = 0;
    }

    return cc;
}
