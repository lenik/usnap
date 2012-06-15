
#ifndef __ESCSTR_H
#define __ESCSTR_H


//#define __DEBUG_ESCSTR

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

int make_escaped_string(char *instr, size_t cInstr, char *outstr, size_t cOutstr, size_t *pcNeeded);

char *l_make_escaped_string(char *instr);

#ifdef __cplusplus
}
#endif

#endif
