
#pragma once

#include "pe.h"
#include <pos/error.h>


void *rva_addr(pos::u32_t rva, PEFile *_arch);
pos::u32_t addr_rva(void *_addr, PEFile *_arch);

pos::error_t PE_Analyse(void *pv, pos::u32_t len, PEFile **ppPEArch);
