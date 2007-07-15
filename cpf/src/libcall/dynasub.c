
#include "stdhdrs.h"
#include <windows.h>
#include <tchar.h>
#include <cpf/assert.h>
#include <cpf/dynasub.h>

#define _EX_FLAG_PIN                (0x00000001)
#define _EX_FLAG_UNCHANGED_REFCOUNT (0x00000002)
#define _EX_FLAG_FROM_ADDRESS       (0x00000004)

typedef BOOL (__stdcall *_GETEX)(DWORD, LPCSTR, HMODULE *);

HMODULE _cc
get_calling_module() {
    void *  thisp   = &get_calling_module;
    HMODULE hmker   = LoadLibrary("kernel32");
    HMODULE hm      = NULL;
    _GETEX  getex;

    _assert_(hmker != NULL);
    getex = (_GETEX) GetProcAddress(hmker, "GetModuleHandleExA");
    if (getex == NULL) {
        /* Not supported */
    } else {
        /* XP/2003 */
        if (getex(_EX_FLAG_FROM_ADDRESS | _EX_FLAG_UNCHANGED_REFCOUNT,
                  (LPCSTR) thisp, &hm)) {
        } else {
            /* GetLastError if fails */
            hm = NULL;
        }
    }
    FreeLibrary(hmker);
    return hm;
}

void * _cc
load_proc(LPCTSTR lib, LPCTSTR proc) {
    HMODULE hlib = LoadLibrary(lib);
    if (hlib == NULL) {
        HMODULE hparent = get_calling_module();
        TCHAR   buf[MAX_PATH];
        DWORD   ret;
        LPTSTR  p;
        if (hparent == NULL)
            return 0;
        ret = GetModuleFileName(hparent, buf, MAX_PATH);
        if (ret == 0)
            return 0;
        p = buf + ret;
        while (--p >= buf) {
            if (*p == _T('\\') || *p == _T('/'))
                break;
        }
        if (p < buf)            /* dirname() == "" */
            return 0;
        lstrcpy(p + 1, lib);    /* path_join(dirname, lib) */
        hlib = LoadLibrary(buf);
        if (hlib == NULL)
            return 0;
    }
    return GetProcAddress(hlib, proc);
}
