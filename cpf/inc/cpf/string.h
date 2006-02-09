#ifndef _string_umac_n_xWDeYIkaI9jkcy_
#define _string_umac_n_xWDeYIkaI9jkcy_

int
sprintf_lim(char *buffer, int size, const char *trail,
            const char *fmt, ...);

int
vsprintf_lim(char *buffer, int size, const char *trail,
             const char *fmt, va_list arglist);

#endif
