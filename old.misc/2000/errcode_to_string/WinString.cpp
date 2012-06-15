// WinString.cpp : Defines the entry point for the DLL application.
//

#pragma once

#include <string.h>

#include "stdafx.h"

#include "WinString.h"

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

LPSTR WINSTRING_API LookUpTheMessage(UINT message, LPSTR Buf) {
	switch (message) {
	case WM_NULL:
		lstrcpy(Buf, "WM_NULL"); break;
	case WM_CREATE:
		lstrcpy(Buf, "WM_CREATE"); break;
	case WM_DESTROY:
		lstrcpy(Buf, "WM_DESTROY"); break;
	case WM_MOVE:
		lstrcpy(Buf, "WM_MOVE"); break;
	case WM_SIZE:
		lstrcpy(Buf, "WM_SIZE"); break;
	case WM_ACTIVATE:
		lstrcpy(Buf, "WM_ACTIVATE"); break;
	case WM_SETFOCUS:
		lstrcpy(Buf, "WM_SETFOCUS"); break;
	case WM_KILLFOCUS:
		lstrcpy(Buf, "WM_KILLFOCUS"); break;
	case WM_ENABLE:
		lstrcpy(Buf, "WM_ENABLE"); break;
	case WM_SETREDRAW:
		lstrcpy(Buf, "WM_SETREDRAW"); break;
	case WM_SETTEXT:
		lstrcpy(Buf, "WM_SETTEXT"); break;
	case WM_GETTEXT:
		lstrcpy(Buf, "WM_GETTEXT"); break;
	case WM_GETTEXTLENGTH:
		lstrcpy(Buf, "WM_GETTEXTLENGTH"); break;
	case WM_PAINT:
		lstrcpy(Buf, "WM_PAINT"); break;
	case WM_CLOSE:
		lstrcpy(Buf, "WM_CLOSE"); break;
	case WM_QUERYENDSESSION:
		lstrcpy(Buf, "WM_QUERYENDSESSION"); break;
	case WM_QUIT:
		lstrcpy(Buf, "WM_QUIT"); break;
	case WM_QUERYOPEN:
		lstrcpy(Buf, "WM_QUERYOPEN"); break;
	case WM_ERASEBKGND:
		lstrcpy(Buf, "WM_ERASEBKGND"); break;
	case WM_SYSCOLORCHANGE:
		lstrcpy(Buf, "WM_SYSCOLORCHANGE"); break;
	case WM_ENDSESSION:
		lstrcpy(Buf, "WM_ENDSESSION"); break;
	case WM_SHOWWINDOW:
		lstrcpy(Buf, "WM_SHOWWINDOW"); break;
	case WM_WININICHANGE:
		lstrcpy(Buf, "WM_WININICHANGE"); break;
	case WM_DEVMODECHANGE:
		lstrcpy(Buf, "WM_DEVMODECHANGE"); break;
	case WM_ACTIVATEAPP:
		lstrcpy(Buf, "WM_ACTIVATEAPP"); break;
	case WM_FONTCHANGE:
		lstrcpy(Buf, "WM_FONTCHANGE"); break;
	case WM_TIMECHANGE:
		lstrcpy(Buf, "WM_TIMECHANGE"); break;
	case WM_CANCELMODE:
		lstrcpy(Buf, "WM_CANCELMODE"); break;
	case WM_SETCURSOR:
		lstrcpy(Buf, "WM_SETCURSOR"); break;
	case WM_MOUSEACTIVATE:
		lstrcpy(Buf, "WM_MOUSEACTIVATE"); break;
	case WM_CHILDACTIVATE:
		lstrcpy(Buf, "WM_CHILDACTIVATE"); break;
	case WM_QUEUESYNC:
		lstrcpy(Buf, "WM_QUEUESYNC"); break;
	case WM_GETMINMAXINFO:
		lstrcpy(Buf, "WM_GETMINMAXINFO"); break;
	case WM_PAINTICON:
		lstrcpy(Buf, "WM_PAINTICON"); break;
	case WM_ICONERASEBKGND:
		lstrcpy(Buf, "WM_ICONERASEBKGND"); break;
	case WM_NEXTDLGCTL:
		lstrcpy(Buf, "WM_NEXTDLGCTL"); break;
	case WM_SPOOLERSTATUS:
		lstrcpy(Buf, "WM_SPOOLERSTATUS"); break;
	case WM_DRAWITEM:
		lstrcpy(Buf, "WM_DRAWITEM"); break;
	case WM_MEASUREITEM:
		lstrcpy(Buf, "WM_MEASUREITEM"); break;
	case WM_DELETEITEM:
		lstrcpy(Buf, "WM_DELETEITEM"); break;
	case WM_VKEYTOITEM:
		lstrcpy(Buf, "WM_VKEYTOITEM"); break;
	case WM_CHARTOITEM:
		lstrcpy(Buf, "WM_CHARTOITEM"); break;
	case WM_SETFONT:
		lstrcpy(Buf, "WM_SETFONT"); break;
	case WM_GETFONT:
		lstrcpy(Buf, "WM_GETFONT"); break;
	case WM_SETHOTKEY:
		lstrcpy(Buf, "WM_SETHOTKEY"); break;
	case WM_GETHOTKEY:
		lstrcpy(Buf, "WM_GETHOTKEY"); break;
	case WM_QUERYDRAGICON:
		lstrcpy(Buf, "WM_QUERYDRAGICON"); break;
	case WM_COMPAREITEM:
		lstrcpy(Buf, "WM_COMPAREITEM"); break;
	case WM_COMPACTING:
		lstrcpy(Buf, "WM_COMPACTING"); break;
	case WM_COMMNOTIFY:
		lstrcpy(Buf, "WM_COMMNOTIFY"); break;
	case WM_WINDOWPOSCHANGING:
		lstrcpy(Buf, "WM_WINDOWPOSCHANGING"); break;
	case WM_WINDOWPOSCHANGED:
		lstrcpy(Buf, "WM_WINDOWPOSCHANGED"); break;
	case WM_POWER:
		lstrcpy(Buf, "WM_POWER"); break;
	case WM_COPYDATA:
		lstrcpy(Buf, "WM_COPYDATA"); break;
	case WM_CANCELJOURNAL:
		lstrcpy(Buf, "WM_CANCELJOURNAL"); break;
	case WM_NOTIFY:
		lstrcpy(Buf, "WM_NOTIFY"); break;
	case WM_INPUTLANGCHANGEREQUEST:
		lstrcpy(Buf, "WM_INPUTLANGCHANGEREQUEST"); break;
	case WM_INPUTLANGCHANGE:
		lstrcpy(Buf, "WM_INPUTLANGCHANGE"); break;
	case WM_TCARD:
		lstrcpy(Buf, "WM_TCARD"); break;
	case WM_HELP:
		lstrcpy(Buf, "WM_HELP"); break;
	case WM_USERCHANGED:
		lstrcpy(Buf, "WM_USERCHANGED"); break;
	case WM_NOTIFYFORMAT:
		lstrcpy(Buf, "WM_NOTIFYFORMAT"); break;
	case WM_CONTEXTMENU:
		lstrcpy(Buf, "WM_CONTEXTMENU"); break;
	case WM_STYLECHANGING:
		lstrcpy(Buf, "WM_STYLECHANGING"); break;
	case WM_STYLECHANGED:
		lstrcpy(Buf, "WM_STYLECHANGED"); break;
	case WM_DISPLAYCHANGE:
		lstrcpy(Buf, "WM_DISPLAYCHANGE"); break;
	case WM_GETICON:
		lstrcpy(Buf, "WM_GETICON"); break;
	case WM_SETICON:
		lstrcpy(Buf, "WM_SETICON"); break;
	case WM_NCCREATE:
		lstrcpy(Buf, "WM_NCCREATE"); break;
	case WM_NCDESTROY:
		lstrcpy(Buf, "WM_NCDESTROY"); break;
	case WM_NCCALCSIZE:
		lstrcpy(Buf, "WM_NCCALCSIZE"); break;
	case WM_NCHITTEST:
		lstrcpy(Buf, "WM_NCHITTEST"); break;
	case WM_NCPAINT:
		lstrcpy(Buf, "WM_NCPAINT"); break;
	case WM_NCACTIVATE:
		lstrcpy(Buf, "WM_NCACTIVATE"); break;
	case WM_GETDLGCODE:
		lstrcpy(Buf, "WM_GETDLGCODE"); break;
	case WM_SYNCPAINT:
		lstrcpy(Buf, "WM_SYNCPAINT"); break;
	case WM_NCMOUSEMOVE:
		lstrcpy(Buf, "WM_NCMOUSEMOVE"); break;
	case WM_NCLBUTTONDOWN:
		lstrcpy(Buf, "WM_NCLBUTTONDOWN"); break;
	case WM_NCLBUTTONUP:
		lstrcpy(Buf, "WM_NCLBUTTONUP"); break;
	case WM_NCLBUTTONDBLCLK:
		lstrcpy(Buf, "WM_NCLBUTTONDBLCLK"); break;
	case WM_NCRBUTTONDOWN:
		lstrcpy(Buf, "WM_NCRBUTTONDOWN"); break;
	case WM_NCRBUTTONUP:
		lstrcpy(Buf, "WM_NCRBUTTONUP"); break;
	case WM_NCRBUTTONDBLCLK:
		lstrcpy(Buf, "WM_NCRBUTTONDBLCLK"); break;
	case WM_NCMBUTTONDOWN:
		lstrcpy(Buf, "WM_NCMBUTTONDOWN"); break;
	case WM_NCMBUTTONUP:
		lstrcpy(Buf, "WM_NCMBUTTONUP"); break;
	case WM_NCMBUTTONDBLCLK:
		lstrcpy(Buf, "WM_NCMBUTTONDBLCLK"); break;
	case WM_KEYDOWN:
		lstrcpy(Buf, "WM_KEYDOWN"); break;
	case WM_KEYUP:
		lstrcpy(Buf, "WM_KEYUP"); break;
	case WM_CHAR:
		lstrcpy(Buf, "WM_CHAR"); break;
	case WM_DEADCHAR:
		lstrcpy(Buf, "WM_DEADCHAR"); break;
	case WM_SYSKEYDOWN:
		lstrcpy(Buf, "WM_SYSKEYDOWN"); break;
	case WM_SYSKEYUP:
		lstrcpy(Buf, "WM_SYSKEYUP"); break;
	case WM_SYSCHAR:
		lstrcpy(Buf, "WM_SYSCHAR"); break;
	case WM_SYSDEADCHAR:
		lstrcpy(Buf, "WM_SYSDEADCHAR"); break;
	case WM_KEYLAST:
		lstrcpy(Buf, "WM_KEYLAST"); break;
	case WM_IME_STARTCOMPOSITION:
		lstrcpy(Buf, "WM_IME_STARTCOMPOSITION"); break;
	case WM_IME_ENDCOMPOSITION:
		lstrcpy(Buf, "WM_IME_ENDCOMPOSITION"); break;
	case WM_IME_COMPOSITION:
		lstrcpy(Buf, "WM_IME_COMPOSITION"); break;
	case WM_INITDIALOG:
		lstrcpy(Buf, "WM_INITDIALOG"); break;
	case WM_COMMAND:
		lstrcpy(Buf, "WM_COMMAND"); break;
	case WM_SYSCOMMAND:
		lstrcpy(Buf, "WM_SYSCOMMAND"); break;
	case WM_TIMER:
		lstrcpy(Buf, "WM_TIMER"); break;
	case WM_HSCROLL:
		lstrcpy(Buf, "WM_HSCROLL"); break;
	case WM_VSCROLL:
		lstrcpy(Buf, "WM_VSCROLL"); break;
	case WM_INITMENU:
		lstrcpy(Buf, "WM_INITMENU"); break;
	case WM_INITMENUPOPUP:
		lstrcpy(Buf, "WM_INITMENUPOPUP"); break;
	case WM_MENUSELECT:
		lstrcpy(Buf, "WM_MENUSELECT"); break;
	case WM_MENUCHAR:
		lstrcpy(Buf, "WM_MENUCHAR"); break;
	case WM_ENTERIDLE:
		lstrcpy(Buf, "WM_ENTERIDLE"); break;
	case WM_CTLCOLORMSGBOX:
		lstrcpy(Buf, "WM_CTLCOLORMSGBOX"); break;
	case WM_CTLCOLOREDIT:
		lstrcpy(Buf, "WM_CTLCOLOREDIT"); break;
	case WM_CTLCOLORLISTBOX:
		lstrcpy(Buf, "WM_CTLCOLORLISTBOX"); break;
	case WM_CTLCOLORBTN:
		lstrcpy(Buf, "WM_CTLCOLORBTN"); break;
	case WM_CTLCOLORDLG:
		lstrcpy(Buf, "WM_CTLCOLORDLG"); break;
	case WM_CTLCOLORSCROLLBAR:
		lstrcpy(Buf, "WM_CTLCOLORSCROLLBAR"); break;
	case WM_CTLCOLORSTATIC:
		lstrcpy(Buf, "WM_CTLCOLORSTATIC"); break;
	case WM_MOUSEMOVE:
		lstrcpy(Buf, "WM_MOUSEMOVE"); break;
	case WM_LBUTTONDOWN:
		lstrcpy(Buf, "WM_LBUTTONDOWN"); break;
	case WM_LBUTTONUP:
		lstrcpy(Buf, "WM_LBUTTONUP"); break;
	case WM_LBUTTONDBLCLK:
		lstrcpy(Buf, "WM_LBUTTONDBLCLK"); break;
	case WM_RBUTTONDOWN:
		lstrcpy(Buf, "WM_RBUTTONDOWN"); break;
	case WM_RBUTTONUP:
		lstrcpy(Buf, "WM_RBUTTONUP"); break;
	case WM_RBUTTONDBLCLK:
		lstrcpy(Buf, "WM_RBUTTONDBLCLK"); break;
	case WM_MBUTTONDOWN:
		lstrcpy(Buf, "WM_MBUTTONDOWN"); break;
	case WM_MBUTTONUP:
		lstrcpy(Buf, "WM_MBUTTONUP"); break;
	case WM_MBUTTONDBLCLK:
		lstrcpy(Buf, "WM_MBUTTONDBLCLK"); break;
	case WM_PARENTNOTIFY:
		lstrcpy(Buf, "WM_PARENTNOTIFY"); break;
	case WM_ENTERMENULOOP:
		lstrcpy(Buf, "WM_ENTERMENULOOP"); break;
	case WM_EXITMENULOOP:
		lstrcpy(Buf, "WM_EXITMENULOOP"); break;
	case WM_NEXTMENU:
		lstrcpy(Buf, "WM_NEXTMENU"); break;
	case WM_SIZING:
		lstrcpy(Buf, "WM_SIZING"); break;
	case WM_CAPTURECHANGED:
		lstrcpy(Buf, "WM_CAPTURECHANGED"); break;
	case WM_MOVING:
		lstrcpy(Buf, "WM_MOVING"); break;
	case WM_POWERBROADCAST:
		lstrcpy(Buf, "WM_POWERBROADCAST"); break;
	case WM_DEVICECHANGE:
		lstrcpy(Buf, "WM_DEVICECHANGE"); break;
	case WM_MDICREATE:
		lstrcpy(Buf, "WM_MDICREATE"); break;
	case WM_MDIDESTROY:
		lstrcpy(Buf, "WM_MDIDESTROY"); break;
	case WM_MDIACTIVATE:
		lstrcpy(Buf, "WM_MDIACTIVATE"); break;
	case WM_MDIRESTORE:
		lstrcpy(Buf, "WM_MDIRESTORE"); break;
	case WM_MDINEXT:
		lstrcpy(Buf, "WM_MDINEXT"); break;
	case WM_MDIMAXIMIZE:
		lstrcpy(Buf, "WM_MDIMAXIMIZE"); break;
	case WM_MDITILE:
		lstrcpy(Buf, "WM_MDITILE"); break;
	case WM_MDICASCADE:
		lstrcpy(Buf, "WM_MDICASCADE"); break;
	case WM_MDIICONARRANGE:
		lstrcpy(Buf, "WM_MDIICONARRANGE"); break;
	case WM_MDIGETACTIVE:
		lstrcpy(Buf, "WM_MDIGETACTIVE"); break;
	case WM_MDISETMENU:
		lstrcpy(Buf, "WM_MDISETMENU"); break;
	case WM_ENTERSIZEMOVE:
		lstrcpy(Buf, "WM_ENTERSIZEMOVE"); break;
	case WM_EXITSIZEMOVE:
		lstrcpy(Buf, "WM_EXITSIZEMOVE"); break;
	case WM_DROPFILES:
		lstrcpy(Buf, "WM_DROPFILES"); break;
	case WM_MDIREFRESHMENU:
		lstrcpy(Buf, "WM_MDIREFRESHMENU"); break;
	case WM_IME_SETCONTEXT:
		lstrcpy(Buf, "WM_IME_SETCONTEXT"); break;
	case WM_IME_NOTIFY:
		lstrcpy(Buf, "WM_IME_NOTIFY"); break;
	case WM_IME_CONTROL:
		lstrcpy(Buf, "WM_IME_CONTROL"); break;
	case WM_IME_COMPOSITIONFULL:
		lstrcpy(Buf, "WM_IME_COMPOSITIONFULL"); break;
	case WM_IME_SELECT:
		lstrcpy(Buf, "WM_IME_SELECT"); break;
	case WM_IME_CHAR:
		lstrcpy(Buf, "WM_IME_CHAR"); break;
	case WM_IME_KEYDOWN:
		lstrcpy(Buf, "WM_IME_KEYDOWN"); break;
	case WM_IME_KEYUP:
		lstrcpy(Buf, "WM_IME_KEYUP"); break;
	case WM_CUT:
		lstrcpy(Buf, "WM_CUT"); break;
	case WM_COPY:
		lstrcpy(Buf, "WM_COPY"); break;
	case WM_PASTE:
		lstrcpy(Buf, "WM_PASTE"); break;
	case WM_CLEAR:
		lstrcpy(Buf, "WM_CLEAR"); break;
	case WM_UNDO:
		lstrcpy(Buf, "WM_UNDO"); break;
	case WM_RENDERFORMAT:
		lstrcpy(Buf, "WM_RENDERFORMAT"); break;
	case WM_RENDERALLFORMATS:
		lstrcpy(Buf, "WM_RENDERALLFORMATS"); break;
	case WM_DESTROYCLIPBOARD:
		lstrcpy(Buf, "WM_DESTROYCLIPBOARD"); break;
	case WM_DRAWCLIPBOARD:
		lstrcpy(Buf, "WM_DRAWCLIPBOARD"); break;
	case WM_PAINTCLIPBOARD:
		lstrcpy(Buf, "WM_PAINTCLIPBOARD"); break;
	case WM_VSCROLLCLIPBOARD:
		lstrcpy(Buf, "WM_VSCROLLCLIPBOARD"); break;
	case WM_SIZECLIPBOARD:
		lstrcpy(Buf, "WM_SIZECLIPBOARD"); break;
	case WM_ASKCBFORMATNAME:
		lstrcpy(Buf, "WM_ASKCBFORMATNAME"); break;
	case WM_CHANGECBCHAIN:
		lstrcpy(Buf, "WM_CHANGECBCHAIN"); break;
	case WM_HSCROLLCLIPBOARD:
		lstrcpy(Buf, "WM_HSCROLLCLIPBOARD"); break;
	case WM_QUERYNEWPALETTE:
		lstrcpy(Buf, "WM_QUERYNEWPALETTE"); break;
	case WM_PALETTEISCHANGING:
		lstrcpy(Buf, "WM_PALETTEISCHANGING"); break;
	case WM_PALETTECHANGED:
		lstrcpy(Buf, "WM_PALETTECHANGED"); break;
	case WM_HOTKEY:
		lstrcpy(Buf, "WM_HOTKEY"); break;
	case WM_PRINT:
		lstrcpy(Buf, "WM_PRINT"); break;
	case WM_PRINTCLIENT:
		lstrcpy(Buf, "WM_PRINTCLIENT"); break;
	case WM_HANDHELDFIRST:
		lstrcpy(Buf, "WM_HANDHELDFIRST"); break;
	case WM_HANDHELDLAST:
		lstrcpy(Buf, "WM_HANDHELDLAST"); break;
	case WM_AFXFIRST:
		lstrcpy(Buf, "WM_AFXFIRST"); break;
	case WM_AFXLAST:
		lstrcpy(Buf, "WM_AFXLAST"); break;
	case WM_PENWINFIRST:
		lstrcpy(Buf, "WM_PENWINFIRST"); break;
	case WM_PENWINLAST:
		lstrcpy(Buf, "WM_PENWINLAST"); break;
	case WM_APP:
		lstrcpy(Buf, "WM_APP"); break;
	case WM_USER:
		lstrcpy(Buf, "WM_USER"); break;

	default:
		lstrcpy(Buf, "??_????");
	}

	return Buf;
}