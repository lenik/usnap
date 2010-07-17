#ifndef COS51_SYSMON_H
#define COS51_SYSMON_H

#include "types.h"

void getsfr_tab() __naked;
void setsfr_tab() __naked;

byte getsfr(register byte addr)
__naked __reentrant  __using(0);

void setsfr(register word addr_val)
__naked __reentrant  __using(0);

#endif
