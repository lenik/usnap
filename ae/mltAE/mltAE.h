

#pragma once

#include "AEplugin.h"
#include "AEtype.h"


struct AEEnvironment;
struct AESettings;

struct List;
struct InstalledPluginHeader;

struct GraphPlugin;
struct FontPlugin;
struct OutputPlugin;
struct AEKernelPlugin;


LPCTSTR DEFAULT_GP_ENTRY = _T("GetGraphPluginHeader");
LPCTSTR DEFAULT_FP_ENTRY = _T("GetFontPluginHeader");
LPCTSTR DEFAULT_OP_ENTRY = _T("GetOutputPluginHeader");
LPCTSTR DEFAULT_KP_ENTRY = _T("GetKernelPluginHeader");
typedef HRESULT (_stdcall *GetPluginHeaderProc)(AEConfig *pSvrCfg, PluginHeader **ppHdr);


// global functions
void _sp_init();


//

struct AEEnvironment {
	HWND hMainWindow;
	LPCTSTR pClassName;
	DWORD dwMainStyle;
};

struct AESettings {
	// dll-entry name for each plugin dll.
	LPCTSTR pszGPEntry;
	LPCTSTR pszFPEntry;
	LPCTSTR pszOPEntry;
	LPCTSTR pszKPEntry;
};

extern AEEnvironment g_Env;
extern AESettings g_Settings;
extern AEConfig g_Config;


struct List {
	List *next;
	List *prev;
	List() : prev(NULL), next(NULL) {}
};

struct InstalledPluginHeader {
	LPCTSTR pszDllName;
	HMODULE hDll;
	FARPROC pMainEntry;
};


struct GraphPlugin : public List {
	InstalledPluginHeader plugin;
	GraphPluginHeader hdr;
};

struct FontPlugin : public List {
	InstalledPluginHeader plugin;
	FontPluginHeader hdr;
};

struct OutputPlugin : public List {
	InstalledPluginHeader plugin;
	OutputPluginHeader hdr;
};

struct AEKernelPlugin : public List {
	InstalledPluginHeader plugin;
	AEKernelPluginHeader hdr;
};
