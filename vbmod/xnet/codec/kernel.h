#ifndef __KERNEL_H
#define __KERNEL_H

#include "array.h"

char *encode(char *p, int cb, int *cb_out);
char *decode(char *p, int cb, int *cb_out);

#endif
