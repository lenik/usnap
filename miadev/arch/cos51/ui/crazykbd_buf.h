#ifndef CRAZYKBD_MAXKEY
#define CRAZYKBD_MAXKEY 16
#endif

#define CRAZYKBD_BUFSIZE ((CRAZYKBD_MAXKEY + 7) / 8)

__xdata BYTE crazykbd_state[CRAZYKBD_BUFSIZE];
__xdata BYTE crazykbd_scan[CRAZYKBD_BUFSIZE];

#ifdef CRAZYKBD_TRANSTAB
    __xdata char crazykbd_transtab[CRAZYKBD_MAXKEY];
#else
    __xdata char *crazykbd_transtab = NULL;
#endif
