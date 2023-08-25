#ifndef COS51_CRAZYKBD_H
#define COS51_CRAZYKBD_H

#include "message.h"

typedef BYTE keyscan_t;

/**
 * The user must implement this function to read the underlying I/O ports.
 *
 * @param mem Bit buffer packed in BYTEs.
 * @return bit numbers indicating the count of key button.
 */
keyscan_t kbd_scan(BYTE *mem);

/* key-scan-index/char-ascii translate table */
extern __xdata char *kbd_transtab;

BYTE crazykbd_poll();

#endif
