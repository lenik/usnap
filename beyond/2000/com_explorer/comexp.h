
#pragma once

static char *__p_str = NULL;
static int __p_stepped = false;

bool DumpTypeLib(ITypeLib *pTL);
bool DumpTypeInfo(ITypeInfo *pTI);
