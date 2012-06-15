
#pragma once

#include "AEtype.h"


/*
	typedef HRESULT (_stdcall *GetPluginHeaderProc)(AEConfig *pSvrCfg, PluginHeader **ppHdr);

	plugin application shall implement one of the follow entry points:

		HRESULT _stdcall GetGraphPluginHeader(AEConfig *pSvrCfg, GraphPluginHeader **ppHdr);
		HRESULT _stdcall GetFontPluginHeader(AEConfig *pSvrCfg, FontPluginHeader **ppHdr);
		HRESULT _stdcall GetOutputPluginHeader(AEConfig *pSvrCfg, OutputPluginHeader **ppHdr);
		HRESULT _stdcall GetKernelPluginHeader(AEConfig *pSvrCfg, KernelPluginHeader **ppHdr);

	the pSvrCfg pointer can be saved for later using, but invalid when the server is exited.
*/


struct AEConfig;

struct PluginHeader;
struct GraphPluginHeader;
struct FontPluginHeader;
struct OutputPluginHeader;
struct AEKernelPluginHeader;


typedef HRESULT (_stdcall *AE_InputImageProc)(AEImage *pImageRet);
typedef HRESULT (_stdcall *AE_DynamicFontProc)(AEFont **pFontRet);
typedef HRESULT (_stdcall *AE_OutputLayoutProc)(AETextLayout *pTextLayout, AEFont *pFontUsing);
typedef HRESULT (_stdcall *AE_KernelAdjustProc)(AEImage *pImage, AETextLayout *pTL);

// callbacks for kernel adjustment
typedef HRESULT (_stdcall *AE_FixedSelect)(AEImage *pImage, double x0, double y0, double x1, double y1,
					   AEFont *pFont, CharAttribute **pCharSelected);
typedef HRESULT (_stdcall *AE_FontOrder)(AEFont *pFont);
typedef HRESULT (_stdcall *AE_OptimizeLayout)(AETextLayout *pTL);


struct AEConfig {
	//
	LPCTSTR pAppName;
	int major;
	int minor;

	// these plugins is configed in AE server app.
	// the first plugin pointer for each plugin class.
	// use GetPluginsCount/GetPluginInList to retrieve plugins info.
	void *pGraphs;		// List:GraphPlugin *
	void *pFonts;		// List:FontPlugin *
	void *pOutputs;		// List:OutputPlugin *
	void *pKernels;		// List:AEKernelPlugin *

	//
	HINSTANCE hApp;
	HWND hConfigWindow;
	struct {
		// current input file name (an image file)
		LPTSTR pszInputFile;
		// current output file name (a text or document file)
		LPTSTR pszOutputFile;
		// generally, text file has a coding method, such as ANSI, Unicode, UTF-9, ...
		// iOutputCoding == 0 is ANSI.
		int iOutputCoding;	// not support
		// whether to fill the extra space, to make the text as same size as image.
		BOOL bSpaceFilled;
	} cfg;

	struct {
		PluginHeader *(_stdcall *_get_plugin_hdr)(void *plistentry);
	} svrproc;
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
inline PluginHeader *GetPluginInList(AEConfig *pCfg, void *PluginListEntry, int index) {
	if (PluginListEntry == NULL) return NULL;
	while (index > 0) {
		if (PluginListEntry == NULL) return NULL;
		PluginListEntry = *(void **)PluginListEntry;
		index--;
	}
	if (PluginListEntry == NULL) return NULL;
	return pCfg->svrproc._get_plugin_hdr(PluginListEntry);
};


struct PluginHeader {
	LPCTSTR pszName;
	int major;
	int minor;
	LPCTSTR pszAuthor;
	LPCTSTR pszCompany;
	LPCTSTR pszEmail;
	LPCTSTR pszWeb;
	LPCTSTR pszCopyright;

	int iUserTag;
	void *pvUserTag;
	int iSpecific;
	void *pvSpecific;

	HANDLE hModule;
	// plugin wants all information directly from the main app.
	//	if all of plugins check the bSilenceMode, then the config
	//	window must be shown after streaming is started.
	BOOL bSilenceMode;

	// plugin is run as a support-routine. e.g. a graphics plugin
	//	is designed for .bmp file load support.
	// if not set the supportmode, the plugin may inaccessable when
	//	the main app searchs for a certain type supporting.
	BOOL bSupportMode;

	// plugin is support color, only if setted bColorEnabled.
	BOOL bColorEnabled;

	int iSupportCode;
	// in most certain, this is the extension name for a specified file.
	TCHAR szSupportCode[32];
	void *pvSupport;

};

struct GraphPluginHeader : public PluginHeader {
	AE_InputImageProc pfMain;
};

struct FontPluginHeader : public PluginHeader {
	// font plugin may be 1).AEF file containing rasterized or vector font shape data,
	// or 2)executables which geenrates dynamics font. when:
	// 1) .AEF file
	//
	// 2) executables
	//
	AE_DynamicFontProc pfMain;	// reserved, should be NULL.
	AEFont font;		// chars within the font may be ordered

	FontPluginHeader() { pfMain = NULL; }
};

struct OutputPluginHeader : public PluginHeader {
	AE_OutputLayoutProc pfMain;
};


struct AEKernelPluginHeader : public PluginHeader {
	/*
		callbacks architecture:
		main proc:
			KA plugin can provide the topmost function, to convert image->layout.
			if plugin doesn't provide that, the server's internal main proc (IKA) will be used.
		fixed select:
			IKA or other module will call the selecting function to select an
			appropriate character from the font collection, to match the fixed-size
			shape in image's protion.
		font orderer:
			characters in a font may have ordered. so some character will be used instead
			of others even when its shape is less matched.
			generally, KA plugin give higher order to smooth characters.
			notice: 'order' is the iTypeSpecific in each AEImage for characters.
		optimize:

	*/

	AE_KernelAdjustProc pfMain;
	AE_FixedSelect pfFixedSelect;
	AE_FontOrder pfFontOrder;
	AE_OptimizeLayout pfOptimizeLayout;
};
