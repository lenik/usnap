
#pragma once

#include "AEtype.h"

struct AEConfig;

struct PluginHeader;
struct GraphPluginHeader;
struct FontPluginHeader;
struct OutputPluginHeader;
struct AEKernelPluginHeader;


typedef HRESULT (_stdcall *AE_InputImageProc)(AEImage *pImageRet);
typedef HRESULT (_stdcall *AE_OutputLayoutProc)(AETextLayout *pTextLayout, AEFont *pFontUsing);
typedef HRESULT (_stdcall *AE_KernelAdjustProc)();


struct AEConfig {
	//
	LPCTSTR pAppName;
	int major;
	int minor;

	// these plugins is configed in AE server app.
	// the first plugin pointer for each plugin class.
	// use GetPluginsCount/GetPluginInList to retrieve plugins info.
	void *pGraphs;
	void *pFonts;
	void *pOutputs;
	void *pKernels;

	//
	HINSTANCE hApp;
	HWND hMainWindow;
	HWND hConfigWindow;
	LPCTSTR pClassName;
};

inline int GetPluginsCount(void *PluginListEntry) {
	if (PluginListEntry == NULL) return 0;
	int sum = 0;
	while (PluginListEntry) {
		PluginListEntry = *(void **)PluginListEntry;
		sum++;
	}
	return sum;
}
inline PluginHeader *GetPluginInList(void *PluginListEntry, int index) {
	if (PluginListEntry == NULL) return NULL;
	while (index > 0) {
		if (PluginListEntry == NULL) return NULL;
		PluginListEntry = *(void **)PluginListEntry;
		index--;
	}
	if (PluginListEntry == NULL) return NULL;
	return (PluginHeader *)((void **)PluginListEntry + 2);
};


struct PluginHeader {
	LPCTSTR pszName;
	int major;
	int minor;
	LPCTSTR pszAuthor;
	LPCTSTR pszCompany;
	LPCTSTR pszEmail;
	LPCTSTR pszWeb;

	int iUserTag;
	void *pvUserTag;
	int iSpecific;
	void *pvSpecific;

	BOOL bSilenceMode;
};

struct GraphPluginHeader : public PluginHeader {
	AE_InputImageProc pMain;
};

struct FontPluginHeader : public PluginHeader {
	AE_InputImageProc pMain;
};

struct OutputPluginHeader : public PluginHeader {
	AE_OutputLayoutProc pMain;
};

struct AEKernelPluginHeader : public PluginHeader {
	AE_KernelAdjustProc pMain;
};
