#include <assert.h>
#include <string.h>

#include "crazykbd.h"

/**
 * Crazy Keyboard
 * If the key button is connected to the I/O pin directly, without any filter to
 * ignore the unwanted noises when the key is pressing down or releasing up,
 * such keyboard we call it Crazy Keyboard.
 *
 * This driver do the underlying noise filter, and repeat key when the key is
 * pressed down after a repeat timeout.
 *
 * @author Lenik
 * @date 2010-7-8
 */

#define CRAZYKBD_VERSION "0.1"

#ifndef CRAZYKBD_FILTER_WINDOW
#define CRAZYKBD_FILTER_WINDOW 3 // Not used, yet
#endif

#ifndef CRAZYKBD_REPEAT_TIMEOUT
#define CRAZYKBD_REPEAT_TIMEOUT 100
#endif

#ifndef CRAZYKBD_REPEAT_RATE
#define CRAZYKBD_REPEAT_RATE 30
#endif

extern __xdata BYTE *crazykbd_state;
extern __xdata BYTE *crazykbd_scan;

BYTE crazykbd_poll() {
    __xdata BYTE *state = crazykbd_state;
    __xdata BYTE *scan = crazykbd_scan;
    keyscan_t keys = kbd_scan(crazykbd_scan);
    keyscan_t changes = 0;
    BYTE st = 0, sc = 0, stb, scb;
    int keyScan = 0;
    BYTE bitMask = 0x80;
    while (keys) {
        if (! (keyScan & 7)) {
            st = *state++;
            sc = *scan++;
            if (keys >= 8 && st == sc) {
                keys -= 8;
                keyScan += 8;
                continue;
            }
        }
        stb = st & bitMask;
        scb = sc & bitMask;
        if (stb != scb) {
            enqueue_b(scb ? M_KEYDOWN : M_KEYUP, keyScan);
            changes++;
        }
        bitMask = (bitMask >> 1) | (bitMask << 7);
        keyScan++;
        keys--;
    }
    return changes;
}
