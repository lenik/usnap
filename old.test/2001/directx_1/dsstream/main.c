#define WIN32_LEAN_AND_MEAN
#define INITGUID

#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <dsound.h>
#include <commctrl.h>
#include <commdlg.h>
#include <memory.h>
#include <cderr.h>

#include "dsstream.h"
#include "wassert.h"

char szAppClass[]	= "DirectSoundStreamWindowClass";
char szAppName[]	= "DirectSoundStream";

char szAppTitle[64];
char szAppCaption[64];
char szPan[32];
char szVolume[32];
char szFrequency[32];
char szProgress[32];
char szOpenFilter[128];
char szOpenDLGTitle[64];

char szTemp[256];
char szDebug[128];
char szFileBuffer[MAX_PATH];
char szFileTitle[MAX_PATH];
char szCDStartPath[MAX_PATH]; 	// path to start the open dialog in

static const TCHAR gszRegKeyDirect3D[]  = TEXT("Software\\Microsoft\\Direct3D");
static const TCHAR gszRegValueD3DPath[] = TEXT("D3D Path");

#define MAX_TOKEN_LEN		7


static TCHAR gszPlayToken[] 	= TEXT("PLAY");
static TCHAR gszLoopToken[] 	= TEXT("LOOP");
static TCHAR gszCloseToken[]	= TEXT("CLOSE");
static TCHAR gszStickyToken[]	= TEXT("STICKY");
static TCHAR gszGlobalToken[]	= TEXT("GLOBAL");

LPDIRECTSOUND		lpDS 				= NULL;
LPDIRECTSOUNDBUFFER	lpDSBStreamBuffer	= NULL;
LPDIRECTSOUNDNOTIFY	lpDirectSoundNotify	= NULL;

WAVEINFOCA		wiWave;

HWND			hWndMain, hWndPan, hWndPanText, hWndVol, hWndVolText, hWndFreqText;
HWND			hWndBar, hWndPlay, hWndStop, hWndLoopCheck, hWndFreq, hWndProg;
HWND			hWndProgText;

#ifdef DEBUG
HWND			hWndList;
#endif

HINSTANCE		hInst;

static BOOL		bFileOpen = FALSE, bPlaying = FALSE;
static BOOL		bEnumDrivers = FALSE, gfCloseOnDone = FALSE;
static UINT		uTimerID = 0, uLastPercent = 100;
static GUID		guID;
static DWORD	gdwFocus = 0;

static BOOL		InitApp(HINSTANCE);
static BOOL		InitInstance(HINSTANCE, int);
static void		BuildTitleBarText();
static void		GetMediaStartPath();

static void		FillDataBuffer();
static void		LoadFromCommandLine(LPSTR lpszCmd);
extern void		UpdateProgressBar();


int PASCAL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG	msg;

	hInst	= hInstance;

	InitCommonControls();

	if (!hPrevInstance)
		if (!InitApp(hInstance)) {
			ErrorMessageBox(IDS_ERROR_APPINIT, MB_ICONSTOP);
			return FALSE;
		}

	if (!InitInstance(hInstance, nCmdShow)) {
		ErrorMessageBox(IDS_ERROR_INSTANCEINIT, MB_ICONSTOP);
		return FALSE;
	}

	if (lpCmdline[0]) LoadFromCommandLine(lpCmdLine);

	while (GetMessage((LPMSG)&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	UnregisterClass(szAppClass, hInstance);
	return msg.wParam;
}

static BOOL InitApp(HINSTANCE hInstance) {
	WNDCLASS		wc;
	wc.style		= CS_HREDRAW | CS_VREDRAW;
	ws.lpszClassName= szAppClass;
	wc.lpfnWndProc	= (WNDPROC)MainWindowProc;
	wc.cbClsExtra	= 0;
	wc.cbWndExtra	= sizeof(DWORD);
	wc.hInstance	= hInstance;
	wc.hIcon		= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wc.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground= (HBRUSH)(COLOR_WINDOW);
	wc.lpszMenuName	= MAKEINTRESOURCE(IDR_MAINMENU);

	if (!RegisterClass(&wc)) {
		ErrorMessageBox(IDS_ERROR_REGISTERCLASS, MB_ICONSTOP);
		return FALSE;
	}
	return TRUE;
}

static BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
	HWND		hWnd;
	HRESULT		dsRetVal;
	RECT		crect;
	int			cx, cy;
	UINT		uCharsRead;
	BOOL		fUseGuid = FALSE;
	HMENU		hSysMenu;

	DbgInitialize(TRUE);

	GetMediaStartPath();

	LoadString(hInstance, IDS_APP_TITLE, szAppTitle, sizeof(szAppTitle));
	LoadString(hInstance, IDS_APP_CAPTION, szAppCaption, sizeof(szAppCaption));
	LoadString(hInstance, IDS_TBTITLE_PAN, szPan, sizeof(szPan));
	LoadString(hInstance, IDS_TBTITLE_VOLUE, szVolume, sizeof(szVolume));
	LoadString(hInstance, IDS_TBTITLE_FREQUENCY, szFrequency, sizeof(szFrequency));
	LoadString(hInstance, IDS_TBTITLE_PROGRESS, szProgress, sizeof(szProgress));
	LoadString(hInstance, IDS_OPEN_DLGTITLE, szOpenDLGTitle, sizeof(szOpenDLGTitle));

	memset(szOpenFilter, 0, sizeof(szOpenFilter));
	uCharsRead = LoadString(hInstance, IDS_OPEN_FILTER1, szOpenFilter, sizeof(szOpenFilter)) + 1;
	uCharsRead += LoadString(hInstance, IDS_OPEN_FILTER2, &szOpenFilter[uCharsRead], sizeof(szOpenFilter) - uCharsRead) + 1;
	uCharsRead += LoadString(hInstance, IDS_OPEN_FILTER3, &szOpenFilter[uCharsRead], sizeof(szOpenFilter) - uCharsRead) + 1;
	LoadString(hInstance, IDS_OPEN_FILTER4, &szOpenFilter(uCharsRead], sizeof(szOpenFilter) - uCharsRead);

	cx = CONTROL_SPACE_CX + 2 * BORDER_SPACE_CX + BUTTON_CX + PAN_TB_CX + 2 * GetSystemMetrics(SM_CXBORDER) + PAN_TEXT_CX + TEXT_SPACE_CX;
	cy = 2 * (BORDER_SPACE_CY + GetSystemMetrics(SM_CYBORDER)) + PAN_TB_CY + VOL_TB_CY + FREQ_TB_CY + PROG_TB_CY + GetSystemMetrics(SM_CYMENU) + 3 * CONTROL_SPACE_CY + GetSystemMetrics(SM_CYCAPTION);

#ifdef DEBUG
	hWnd = CreateWindow(szAppClass, szAppCaption, WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME | WS_BORDER, CW_USEDEFAULT, CW_USEDEFAULT, cx, cy + 200, NULL, NULL, hInstance, NULL);
#else
	hWnd = CreateWindow(szAppClass, szAppCaption, WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME | WS_BORDER, CW_USEDEFAULT, CW_USEDEFAULT, cx, cy, NULL, NULL, hInstance, NULL);
#endif

	if (!hWnd) {
		ErrorMessageBox(IDS_ERROR_MAINWNDCREATE, MB_ICONSTOP);
		return FALSE;
	}

	hWndMain = hWnd;
	GetClientRect(hWndMain, &creat);

	hSysMenu = GetSystemMenu(hWndMain, FALSE);
	EnableMenuItem(hSysMenu, SC_SIZE, MF_BYCOMMAND | MF_GRAYED);
	EnableMenuItem(hSysMenu, SC_MAXIMIZE, MF_BYCOMMAND | MF_GRAYED);

#ifdef DEBUG
	cy = 2 * BORDER_SPACE_CY + PAN_TB_CY + VOL_TB_CY + FREQ_TB_CY + PROG_TB_CY + 3 * CONTROL_SPACE_CY;
	hWndList = CreateWindow("listbox", NULL, WS_CHILD | WS_VISIBLE | LBS_NOINTEGRALHEIGHT | WS_VSCROLL, 0, cy, crect.right - crect.left, crect.bottom - crect.top - cy, hWnd, NULL, hInstance, NULL);
#endif

	if (CreateChildren(crect)) return FALSE;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	bEnumDrivers = GetProfileInt("DSSTREAM", "EnumDrivers", FALSE);
	if (bEnumDrivers && !DoDSoundEnumerate(&guID)) {
		fUseGuid = TRUE;
	}

	dsRetVal = DirectSoundCreate(fUseGuid ? &guID : NULL, &lpDS, NULL);
	if (dsRetVal != DS_OK) {
		ErrorMessageBox(IDS_ERROR_DSCREATE, MB_ICONSTOP);
		return FALSE;
	}

	dsRetVal = lpDS->SetCooperativeLevel(lpDS, hWndMain, DSSCL_NORMAL);
	if (dsRetVal != DS_OK) {
		ErrorMessageBox(IDS_ERROR_DSCOOPERATIVE, MB_ICONSTOP);
		return FALSE;
	}

	return TRUE;
}

LRESULT CALLBACK MainWindowProc(HWND hWnd, unsigned uMsg, WPARAM wParam, LPARAM lParam) {
#ifndef DEBUG
	LPMINMAXINFO	lpMinMax;
#endif
	DWORD			dwCDErr = 0, dwProg;
	float			fPercent;
	UINT			uPercent;
	BOOL			bResult = FALSE;
	int				nChkErr;
	HRESULT			dsrval;

	switch (uMsg) {
	case WM_DSSTREAM_PROGRESS:
		dwProg = (DWORD)lParam;
		dwProg %= wiWave.mmckInRIFF.cksize;
		fPercent = (float)((dwProg * 100) / wiWave.mmckInRIFF.cksize);
		SendMessage(hWndProg, TBM_SETPOS, TRUE, (DWORD)(float)(fPercent * (float)PROG_multiplier));
		uPercent = (UINT)fPercent;
		wsprintf(szTemp, "%s: %u%%", szProgress, uPercent);
		Static_SetText(hWndProgText, szTemp);
		break;
	case WM_DSSTREAM_DONE:
		DPF(0, "received a dsstream_done message");
		PostMessage(hWnd, WM_COMMAND, MAKEWPARAM(IDM_STOP, 0), 0L);
		break;

#ifdef DEBUG
	case WM_DSSTREAM_DEBUG:
		if (LOWORD(wParam) == DEBUGF_PLAYPOSITION) {
			wsprintf(szDebug, "pp = %li", lParam);
			ListBox_AddString(hWndList, szDebug);
			DPF(4, szDebug);
		} else if (LOWORD(wParam) == DEBUGF_WRITEPOSITION) {
			wsprintf(szDebug, "wp = %li", lParam);
			ListBox_AddString(hWndList, szDebug);
			DPF(4, szDebug);
		} else if (LOWORD(wParam) == DEBUGF_NEXTWRITE) {
			wsprintf(szDebug, "nw = %li", lParam);
			ListBox_AddString(hWndList, szDebug);
		} else if (LOWORD(wParam) == DEBUGF_SKIP) {
			ListBox_AddString(hWndList, "Skipped segment read");
			DPF(5, szDebug);
		}
		break;
#endif
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDM_FILE_OPEN:
			{
				OPENFILENAME	ofn;
				memset(&ofn, 0, sizeof(OPENFILENAME));
				ofn.lStructSize		= sizeof(OPENFILENAME);
				ofn.hwndOwner		= hWnd;
				ofn.hInstance		= hInst;
				ofn.lpstrFilter		= szOpenFilter;
				ofn.nFilterIndex	= 1;
				szFileBuffer[0]		= '\0';
				ofn.lpstrFile		= szFileBuffer;
				ofn.nMaxFile		= sizeof(szFileBuffer);
				ofn.lpstrFileTitle	= szFileTitle;
				ofn.nMaxFileTitle	= sizeof(szFileTitle);
				ofn.lpstrInitialDir	= szCDStartPath;
				ofn.lpstrDefExt		= "WAV";
				ofn.lpstrTitle		= szOpenDLGTitle;
				ofn.Flags			= OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;

				bResult = GetOpenFileName(&ofn);
				if (hResult == FALSE) {
					dwCDErr = CommDlgExtendedError();
					if (dwCDErr) {
						HandleCommDlgError(dwCDErr);
					} else
						return 0;
				} else {
					lstrcpy(szCDStartPath, szFileBuffer);
					szCDStartPath[ofn.nFileOffset] = '\0';

					if (bFileOpen) {
						gfCloseOnDone = FALSE;
						SendMessage(hWnd, WM_COMMAND, MAKEWPARAM(IDM_FILE_CLOSE, 0), 0L);
					}
					if ((nChkErr = StreamBufferSetup()) != 0) {
						break;
					} else {
						bFileOpen = TRUE;
						EnableMenuItem(GetMenu(hWnd), IDM_PLAY, MF_BYCOMMAND | MF_ENABLED);
						EnableWindow(hWndPlay, TRUE);
						EnableMenuItem(GetMenu(hWnd), IDM_FILE_CLOSE, MF_BYCOMMAND | MF_ENABLED);
						DrawMenuBar(hWnd);
						BuildTitleBarText();
					}
				}
			}
			break;
		case IDM_FILE_CLOSE:
			SendMessage(hWnd, WM_COMMAND, MAKEWPARAM(IDM_STOP, DSSTREAM_STOPF_NOREOPEN), 0L);
			BuildTitleBarText();
			break;
		case IDM_OPTIONS_ENUMDRIVERS:
			bEnumDrivers = !bEnumDrivers;
			if (bEnumDrivers) {
				LoadString(hInst, IDS_ENUMWARNING, szTemp, sizeof(szTemp));
				MessageBox(hWnd,szTemp, szAppCaption, MB_OK);
			}
			break;
		case IDM_HELP_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWndMain, (DLGPROC)DLG_About);
			break;
		case IDC_LOOPCHECK:
			wiWave.bLoopFile = !wiWave.bLoopFile;
			Button_SetCheck(hWndLoopCheck, wiWave.bLoopFile);
			if (!bPlaying && bFileOpen)
				ResetWavePlayer();
			break;
		case IDM_PLAY:
			DPF(0, "In idm_play");
			if (bPlaying) {
				gfCloseOnDone = FALSE;
				SendMessage(hWnd, WM_COMMAND, MAKEWPARAM(IDM_STOP, 0), 0L);
			}
			if (bFileOpen && lpDSBStreamBuffer) {
				dsrval = SetupNotifications();
				if (dsrval != DS_OK) {
					DPF(0, "In Play command, setup notifications failed");
					break;
				}
				dsrval = lpDSBStreamBuffer->SetCurrentPosition(0);
				ASSERT(dsrval == DS_OK);
#ifdef DEBUG
				{
					DWORD dwWrite, dwPlay;
					dsrval = lpDSBStreamBuffer->GetCurrentPosition(&dwPlay, &dwWrite);
					ASSERT(dsrval == DS_OK);
					if (dwPlay != 0)
						DPF(0, "Couldn't set pos to 0");
				}
#endif
				wiWave.bDonePlaying = FALSE;
				DPF(0, "calling play()");
				dsrval = lpDSBStreamBuffer->Play(lpDSBStreamBuffer, 0, 0, DSBPLAY_LOOPING);
			} else {
				bPlaying = FALSE;
				break;
			}

			bPlaying = TRUE;
			EnableWindow(hWndPlay, FALSE);
			EnableWindowItem(GetMenu(hWnd), IDM_PLAY, MF_BYCOMMAND | MF_GRAYED);
			EnableWindowItem(GetMenu(hWnd), IDM_STOP, MF_BYCOMMAND | MF_ENABLED);
			EnableWindow(hWndPlay, TRUE);
			DrawMenuBar(hWnd);
			break;

		case IDM_STOP:
			DPF(0,"received a idm_stop");
			if (gfCloseOnDone)
				wiWave.bDonePlaying = TRUE;
			if (bPlaying) {
				bPlaying = FALSE;
				dsrval = lpDSBStreamBuffer->Stop(lpDSBStreamBuffer);
				EnableMenuItem(GetMenu(hWnd),IDM_STOP, MF_BYCOMMAND, MF_GRAYED);
				EnableWindow(hWndStop, FALSE);
				DrawMenuBar(hWnd);
			}

			if (!(HIWORD(wParam) & DSSTREAM_STOPF_NOREOPEN) && !gfCloseOnDone) {
				ResetWavePlayer();
				EnableMenuItem(GetMenu(hWnd), IDM_PLAY, MF_BYCOMMAND | MF_ENABLED);
				EnableWindow(hWndPlay, TRUE);
				DrawMenuBar(hWnd);
				break;
			} else {
				if (bFileOpen) {
					DPF(0, "In Stop: Closing read file");
					WaveCloseReadFile(&wiWave.hmmio, &wiWave.pwfx);
					if (lpDirectSoundNotify)
						dsrval = lpDirectSoundNotify->Release();
					lpDirectSoundNotify = NULL;

					if (lpDSBStreamBuffer)
						dsrval = lpDSBStreamBuffer->Release();
					lpDSBStreamBuffer = NULL;

					bFileOpen = FALSE;
					EnableMenuItem(GetMenu(hWnd), IDM_FILE_CLOSE, MF_BYCOMMAND | MF_GRAYED);
					EnableMenuItem(GetMenu(hWnd), IDM_PLAY, MF_BYCOMMAND | MF_GRAYED);
					EnableWindow(hWndPlay, FALSE);
					DrawMenuBar(hWnd);
					PoseMessage(hWnd, WM_DSSTREAM_PROGRESS, 0L, 0L);
					if (gfCloseOnDone && !(HIWORD(wParam) && DSSTREAM_STOPF_NOEXIT))
						SendMessage(hWnd, WM_COMMAND, MAKEWPARAM(IDM_FILE_EXIT, 0), 0L);
				}
			}
			break;
		case IDM_FILE_EXIT:
			DestroyWindow(hWnd);
			break;
		}
		break;
#ifndef DEBUG
	case WM_GETMINMAXINFO:
		lpMinMax = (LPMINMAXINFO)lParam;


void LoadFromCommandLine(LPSTR lpszCmd) {
	LPSTR	lpsz = lpszCmd;
	LPSTR	lpToken;
	BOOL	fStartPlaying = FALSE, fStartLooping = fALSE;
	char	szToken[MAX_TOKEN_LEN + 1];
	int		i;

	if (!lpsz) return;
	while (*lpsz == ' ') lpsz++;
	while (*lpsz == '/' || *lpsz == '-') {
		lpToken = ++lpsz;
		for (i = 0; i < MAX_TOKEN_LEN; i++) {
			if (!*lpToken || *lpToken == ' ) break;
			szToken[i] = *lpToken++;
		}
		szToken[i] = 0;

		if (!lstrcmpi(szToken, gszPlayToken)) {
			fStartPlaying = TRUE;
			lpsz = lpToken;
		} else if (!lstrcmpi(szToken, gszLoopToken)) {
			fStartLooping = TRUE;
			lpsz = lpToken;
		} else if (!lstrcmpi(szToken, gszStickyToken)) {
			gdwFocus = DSBCAPS_STICKYFOCUS;
			lpsz = lpToken;
		} else if (!lstrcmpi(szToken, gszGlobalToken)) {
			gdwFocus = DSBCAPS_GLOBALFOCUS;
			lpsz = lpToken;
		} else if (!lstrcmpi(szToken, gszCloseToken)) {
			gfCloseOnDone = TRUE;
			lpsz = lpToken;
		} else {
			while (*lpsz && *lpsz != ' ') lpsz++;
		}

		while (*lpsz == ' ') lpsz++;
	}

	if (!*lpsz) return;

	lstrcpy(szFileBuffer, lpsz);
	lpsz = &szFileBuffer[lstrlen(szFileBuffer)];
	while (lpsz > szFileBuffer) {
		if (*(lpsz - 1) == '\\') {
			break;
		}
		lpsz--;
	}

	lstrcpy(szFileTitle, lpsz);
	lstrcpy(szCDStartPath, szFileBuffer);
	szCDStartPath[lpsz - szFileBuffer] = 0;

	if (fStartLooping) {
		gfCloseOnDone = FALSE;
		Button_SetCheck(hWndLoopCheck, TRUE);
	}

	if (StreamBufferSetup() != 0) {
		return;
	} else {
		hFileOpen = TRUE;
		EnableMenuItem(GetMenu(hWndMain), IDM_PLAY, MF_BYCOMMAND | MF_ENABLED);
		EnableWindow(hWndPlay, TRUE);
		EnableMenuitem(GetMenu(hWndMain), IDM_FILE_CLOSE, MF_BYCOMMAND | MF_ENABLED);
		DrawMenuBar(hWndMain);
		BuildTitleBarText();

		if (fStartPlaying)
			SendMessage(hWndMain, WM_COMMAND, MAKEWPARAM(IDM_PLAY, 0), 0L);
	}
}

int SetupNotifications() {
	int hr = DS_OK;
	DSBPOSITIONNOTIFY	dsbPosNotify[NUM_PLAY_NOTIFICATIONS + 1];
	DWORD dwSize = wiWave.dwNotifySize;
	DWORD dwThreadId;
	int i;

	hNotifyEvent[0] = CreateEvent(NULL, FALSE, FALSE, NULL);
	ASSERT(hNotifyEvent[0]);
	hNotifyEvent[1] = CreateEvent(NULL, FALSE, FALSE, NULL);
	ASSERT(hNotifyEvent[1]);

	dsbPosNotify[0].dwOffset		= dwSize;
	dsbPosNotify[0].hEventNotify	= hNotifyEvent[0];
	DPF(0, "Set notifies for position %lu", dsbPosNotify[0].dwOffset);

	for (i = 1; i < NUM_PLAYNOTIFICATIONS; i++) {
		dsbPosNotify[i].dwOffset	= dsbPosNotify[i - 1].dwOffset + dwSize;
		dsbPosNotify[i].hEventNotify= hNotifyEvent[0];
		DPF(0, "Set notifies for positions %lu", dsbPosNotify[i].dwOffset);
	}

	dsbPosNotify[i - 1].dwOffset	-= 1;
	dsbPosNotify[i].dwOffset		= DSBPN_OFFSETSTOP;
	dsbPosNotify[i].hEventNotify	= hNotifyEvent[1];

	if (CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)HandleNotifications, NULL, 0, &dwThreadId) == NULL) {
		DPF(0, "Create Thread failed");
		goto HandleErr;
	} else
		DPF(0, "Created thread");

	hr = lpDirectSoundNotify->SetNotificationPositions(NUM_PLAY_NOTIFICATIONS + 1, dsbPosNotify);

HandleErr:
	if (hr != DS_OK) {
		if (hr == DSERR_INVALIDPARAM)
			DPF(0, "SetupNotificationsPos failed. Invalid Param");
		if (hr == DSERR_OUTOFMEMORY)
			DPF(0, "SetupNotificationsPos failed. OutOfMemory");
		CloseHandle(hNotifyEvent[0]);
		CloseHandle(hNotifyEvent[1]);
		hNotifyEvent[0] = hNotifyEvent[1] = (HANDLE)NULL;
	}

#ifdef DEBUG
	else {
		DPF(3, "SetNotificationPos succeeded.");
	}

#endif;
	return hr;
}


void StreamBufferSetup() {
	DSBUFFERDESC	dsbd;
	HRESULT			dsRetVal;

	int nChkErr;
	int nRem;

	if ((nChkErr = WaveOpenFile(szFileBuffer, &wiWave.hmmio,&wiWave.pwfx, &wiWave.mmckIn