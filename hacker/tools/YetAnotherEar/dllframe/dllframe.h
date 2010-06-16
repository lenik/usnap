

#pragma once

#include <pos/error.h>
#include "pe.h"

extern char *g_szDllname;
extern char *g_szDllfix;
extern char *g_szFramehdr;
extern char *g_szFrameimp;
extern char *g_szFramedef;


void set_ext_name(char *filename, char *extname, bool setanyway = false);
char *base_name(char *filename, char *buf = NULL);


inline BOOL DllValid(LPCTSTR szPath)
{
	return TRUE;
}

pos::error_t LoadFile(LPCSTR pszFilename, void **ppv, pos::u32_t *psize);

void DebugDump(PEFile *_arch, pos::asz_t _name);
void DumpExports(PEFile *_arch);
void DumpImports(PEFile *_arch);

pos::error_t GenerateFrame(PEFile *_arch);
pos::error_t WritePEFile(pos::asz_t g_szDllfix, PEFile *_pe);
