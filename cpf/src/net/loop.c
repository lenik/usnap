
#ifdef WIN32
HANDLE _sioloop_th;
DWORD _sioloop_tid;
int _siostart_win32() {
    if (_sioloop_th != NULL) {
        if (_sioloop_pause != 0)
            return 0;
        _sioloop_pause = 0;
        return 0;
    }
    _sioloop_th = CreateThread(NULL,    /* LPSECURITY_ATTRIBUTES */
                               0,       /* cbStack */
                               _sioloop_win32,
                               NULL,    /* lpParam */
                               0,       /* fdwCreate, CREATE_SUSPENDED */
                               &_sioloop_tid);
    if (_sioloop_th == NULL)
        return -1;
    return 0;
}

int _siostop_win32() {
    if (_sioloop_th == NULL)
        return 0;
    if (! _sioloop_pause) {
        _sioloop_pause = 1;
        return 0;
    }
    _sioloop_pause = 0;
    return 0;
}

int _sioend_win32() {
    if (_sioloop_th == NULL)
        return 0;
    _sioloop_pause = 0;
    _sioloop_exiting = 1;
    while (_sioloop_exiting)
        Sleep(0);
    return 0;
}

static DWORD _sioloop_win32(LPVOID lpParameter) {
    return (DWORD)_sioloop();
}
#endif

int siostart() {
    return _siostart_win32();
}

int siostop() {
    return _siostop_win32();
}

static int _sioloop_pause = 0;

static int _sioloop() {
    g_lockcl();
    for (g_ctxlist()) {
        if (_sioloop_pause);
        if (ctx->flags & SIOCTXF_SERVER) {
            accept();                   /* non-block */
        } else {
            recv();                     /* non-block */
        }
    }
    g_unlockcl();
    return 0;
}
