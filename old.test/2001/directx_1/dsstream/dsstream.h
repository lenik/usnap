
#ifndef __DSSTREAM_INCLUDED__
#define __DSSTREAM_INCLUDED__

#include <dsound.h>
#include "resource.h"
#include "debug.h"


#define NUM_PLAY_NOTIFICATIONS		4

#define DSSTREAM_STOPF_NOREOPEN		0x0001
#define DSSTREAM_STOPF_NOEXIT		0x0002

#define ERR_WAVE_OPEN_FAILED		-100
#define ERR_WAVE_INVALID_FORMAT		-101
#define ERR_CREATEDSB_FAILED		-102
#define ERR_WAVE_CORRUPTED_FILE		-103


#define BORDER_SPACE_CX				10
#define BORDER_SPACE_CY				10
#define CONTROL_SPACE_CX			4
#define CONTROL_SPACE_CY			4
#define TEXT_SPACE_CY				0
#define TEXT_SPACE_CX				2

#define BUTTON_CX					70
#define BUTTON_CY					32
#define CHECK_CX					70
#define CHECK_CY					22
#define BUTTON_SPACE_CY				6

#define PAN_TEXT_CX					140
#define VOL_TEXT_CX					140
#define FREQ_TEXT_CX				140
#define PROG_TEXT_CX				140

#define PAN_TB_CX					200
#define PAN_TB_CY					30
#define VOL_TB_CX					200
#define VOL_TB_CY					30
#define FERQ_TB_CX					200
#define FREQ_TB_CY					30
#define PROG_TB_CX					200
#define PROG_TB_CY					30

#define PAN_MIN						0
#define PAN_MAX						800
#define PAN_CENTER					400
#define PAN_SHIFT					(-400)
#define PAN_PAGESIZE				10
#define PAN_DIV						10
#define PAN_MULT					10

#define VOL_SHIFT					(-400)
#define VOL_MIN						0
#define VOL_MAX						400
#define VOL_PAGESIZE				10
#define VOL_DIV						10
#define VOL_MULT					10
#define FREQ_MIN					441
#define FREQ_MAX					4410
#define FREQ_PAGESIZE				100
#define FREQ_MULTIPLIER				10
#define PROG_MIN					0
#define PROG_MAX					10000
#define PROG_MULTIPLIER				100


#define WAVEVERSION					1

#ifndef ER_MEM
#define ER_MEM						0xE000
#endif

#ifndef ER_CANNOTOPEN
#define ER_CANNOTOPEN				0xE100
#endif

#ifndef ER_NOTWAVEFILE
#define ER_NOTWAVEFILE				0xE101
#endif

#ifndef ER_CANNOTREAD
#define ER_CANNOTREAD				0xE102
#endif

#ifndef ER_CORRUPTWAVEFILE
#define ER_CORRUPTWAVEFILE			0xE103
#endif

#ifndef ER_CANNOTWRITE
#define ER_CANNOTWRITE				0xE104
#endif


#define WM_DSSTREAM_DONE			WM_USER + 0x100
#define WM_DSSTREAM_DEBUG			WM_USER + 0x101
#define WM_DSSTREAM_PROGRESS		WM_USER + 0x102

#define DEBUGF_PLAYPOSITION			0x0300
#define DEBUGF_WRITEPOSITION		0x0301
#define DEBUGF_NEXTWRITE			0x0302
#define DEBUGF_SKIP					0x0303

typedef struct waveinfoca_tag {
	WAVEFORMATEX *		pwfx;
	HMMIO			hmmio;
	MMCKINFO		mmck;
	MMCKINFO		mmckInRIFF;
	LPDIRECTSOUNDBUFFER	lpDSBStreamBuffer;
	DWORD			dwBufferSize;
	DWORD			dwNotifySize;
	DWORD			dwNextWriteOffset;
	DWORD			dwProgress;
	DWORD			dwLastPos;
	BOOL			bDonePlaying;
	BOOL			bLoopFile;
	BOOL			bFoundEnd;
} WAVEINFOCA, *LPWAVEINFOCA;

HANDLE hNotifyEvent[2];
int SetupNotifications();
DWORD HandleNotifications(LPVOID);

LRESULT CALLBACK MainWindowProc(HWND, unsigned, WPARAM, LPARAM);
BOOL CALLBACK DLG_About(HWND, UINT, WPARAM, LPARAM);
void CALLBACK TimeFunc(UINT, UINT, DWORD, DWORD, DWORD);
BOOL CALLBACK DSEnumDlgProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DSEnumProc(LPGUID, LPSTR, LPSTR, LPVOID);

void ErrorMessageBox(UINT, DWORD);
void HandlePanScroll(int, int);
void HandleVolScroll(int, int);
void HandleFreqScroll(int, int);
void ResetWavePlayer();
void UpdateFromControls();

int CreateChildren(RECT);
int HandleCommDlgError(DWORD);
int StreamBufferSetup();

BOOL DoDSoundEnumerate(LPGUID);

int WaveOpenFile(char *, HMMIO *, WAVEFORMATEX **, MMCKINFO *);
int WaveStartDataRead(HMMIO *, MMCKINFO *, MMCKINFO *);
int WaveReadFile(HMMIO, UINT, BYTE *, MMCKINFO *, UINT *);
int WaveCloseReadFile(HMMIO *, WAVEFORMATEX **);

int WaveCreateFile(char *, HMMIO *, WAVEFORMATEX *, MMCKINFO *, MMCKINFO *);
int WaveStartDataWrite(HMMIO *, MMCKINFO *, MMIOINFO *);
int WaveWriteFile(HMMIO, UINT, BYTE *, MMCKINFO *, UINT *, MMIOINFO *);
int WaveCloseWriteFile(HMMIO *, MMCKINFO *, MMCKINFO *, MMIOINFO *, DWORD);

int WaveLoadFile(char *, UINT *, DWORD *, WAVEFORMATEX **, BYTE **);
int WaveSaveFile(char *, UINT, DWORD, WAVEFORMATEX *, BYTE *);

int WaveCopyUselessChunks(HMMIO *, MMCKINFO *, MMCKINFO *, HMMIO *, MMCKINFO *, MMCKINFO *);
BOOL riffCopyChunk(HMMIO, HMMIO, const LPMMCKINFO);

#endif
