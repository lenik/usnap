
#include "mcell.h"

#define FULL            EOF

void *mcell_allocator::allocate_cells(int count) {
    /*
    bitmap analyse
        parent->alloc-big-chunk
        or return NULL.
    bitmap modify
    return ptr.
    */

    if (next_oct == FULL) {
        // DEBUG_ERROR("no more cells available");
        return NULL;
    }

    size_t bmp_oct;
    u8_t bmp_mask;
    if (next_mask == 0x01) {
        bmp_oct = next_oct + 1;
        bmp_mask = 0x80;
    } else {
        bmp_oct = next_oct;
        bmp_mask = next_mask >> 1;
    }
    int i = 1;
    while (i < count) {
        if (bitmap[bmp_oct] & bmp_mask)
        i++;
    }
    return NULL;
}
