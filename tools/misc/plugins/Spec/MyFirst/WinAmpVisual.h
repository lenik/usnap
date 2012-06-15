
#pragma once

// forward definition
struct winampVisModule;
struct winampVisHeader;

typedef void (*WINAMPVISPROC)(struct winampVisModule *this_mod);
typedef int (*WINAMPVISFUNC)(struct winampVisModule *this_mod);
typedef winampVisModule * (*WINAMPVISENTRY)(int which);

typedef struct winampVisModule {
	LPSTR		description;	// description of module
	HWND		hwndParent;	// parent window (filled in by valling app)
	HINSTANCE	hDllInstance;	// instance handle to this DLL (filled in by calling app)
	int		sRate;		// sample rate (filled in by calling app)
	int		nCh;		// number of channels (filled in by calling app)
	int		latencyMs;	// latency from call of RenderFrame to actual drawing
					// (calling app looks at this value when getting data)
	int		delayMs;	// delay between calls in ms

	// the data is filled in according to the respective Nch entry
	int		spectrumNch;
	int		waveformNch;
	BYTE		spectrumData[2][576];
	BYTE		waveformData[2][576];

	WINAMPVISPROC	procConfig;	// configuration dialog
	WINAMPVISFUNC	funcInit;	// 0 on success, creates window, etc.
	WINAMPVISFUNC	funcRender;	// returns 0 if successful, 1 if vis should end
	WINAMPVISPROC	procQuit;	// call when done

	LPVOID		userData;	// user data, optional
} winampVisModule;

typedef struct winampVisHeader {
	int		version;	// VID_HDRVER
	LPSTR		description; 	// description of library
	WINAMPVISENTRY	getModule;
} winampVisHeader;
