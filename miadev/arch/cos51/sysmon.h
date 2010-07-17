#ifndef COS51_SYSMON_H
#define COS51_SYSMON_H

#include "types.h"

byte getsfr(register byte addr)
__naked __reentrant __using(0);

void setsfr(register word addr_val)
__naked __reentrant __using(0);

#endif
