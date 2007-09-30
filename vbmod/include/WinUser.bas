Attribute VB_Name = "modWinUser"
Option Explicit

' --------------
'  USER Section
' --------------

' Scroll Bar Constants
Public Const SB_HORZ = 0
Public Const SB_VERT = 1
Public Const SB_CTL = 2
Public Const SB_BOTH = 3

' Scroll Bar Commands
Public Const SB_LINEUP = 0
Public Const SB_LINELEFT = 0
Public Const SB_LINEDOWN = 1
Public Const SB_LINERIGHT = 1
Public Const SB_PAGEUP = 2
Public Const SB_PAGELEFT = 2
Public Const SB_PAGEDOWN = 3
Public Const SB_PAGERIGHT = 3
Public Const SB_THUMBPOSITION = 4
Public Const SB_THUMBTRACK = 5
Public Const SB_TOP = 6
Public Const SB_LEFT = 6
Public Const SB_BOTTOM = 7
Public Const SB_RIGHT = 7
Public Const SB_ENDSCROLL = 8

' ShowWindow() Commands
Public Const SW_HIDE = 0
Public Const SW_SHOWNORMAL = 1
Public Const SW_NORMAL = 1
Public Const SW_SHOWMINIMIZED = 2
Public Const SW_SHOWMAXIMIZED = 3
Public Const SW_MAXIMIZE = 3
Public Const SW_SHOWNOACTIVATE = 4
Public Const SW_SHOW = 5
Public Const SW_MINIMIZE = 6
Public Const SW_SHOWMINNOACTIVE = 7
Public Const SW_SHOWNA = 8
Public Const SW_RESTORE = 9
Public Const SW_SHOWDEFAULT = 10
Public Const SW_MAX = 10

' Old ShowWindow() Commands
Public Const HIDE_WINDOW = 0
Public Const SHOW_OPENWINDOW = 1
Public Const SHOW_ICONWINDOW = 2
Public Const SHOW_FULLSCREEN = 3
Public Const SHOW_OPENNOACTIVATE = 4

' Identifiers for the WM_SHOWWINDOW message
Public Const SW_PARENTCLOSING = 1
Public Const SW_OTHERZOOM = 2
Public Const SW_PARENTOPENING = 3
Public Const SW_OTHERUNZOOM = 4

' WM_KEYUP/DOWN/CHAR HIWORD(lParam) flags
Public Const KF_EXTENDED = &H100
Public Const KF_DLGMODE = &H800
Public Const KF_MENUMODE = &H1000
Public Const KF_ALTDOWN = &H2000
Public Const KF_REPEAT = &H4000
Public Const KF_UP = &H8000

' Virtual Keys, Standard Set
Public Const VK_LBUTTON = &H1
Public Const VK_RBUTTON = &H2
Public Const VK_CANCEL = &H3
Public Const VK_MBUTTON = &H4             '  NOT contiguous with L RBUTTON

Public Const VK_BACK = &H8
Public Const VK_TAB = &H9

Public Const VK_CLEAR = &HC
Public Const VK_RETURN = &HD

Public Const VK_SHIFT = &H10
Public Const VK_CONTROL = &H11
Public Const VK_MENU = &H12
Public Const VK_PAUSE = &H13
Public Const VK_CAPITAL = &H14

Public Const VK_ESCAPE = &H1B

Public Const VK_SPACE = &H20
Public Const VK_PRIOR = &H21
Public Const VK_NEXT = &H22
Public Const VK_END = &H23
Public Const VK_HOME = &H24
Public Const VK_LEFT = &H25
Public Const VK_UP = &H26
Public Const VK_RIGHT = &H27
Public Const VK_DOWN = &H28
Public Const VK_SELECT = &H29
Public Const VK_PRINT = &H2A
Public Const VK_EXECUTE = &H2B
Public Const VK_SNAPSHOT = &H2C
Public Const VK_INSERT = &H2D
Public Const VK_DELETE = &H2E
Public Const VK_HELP = &H2F

' VK_A thru VK_Z are the same as their ASCII equivalents: 'A' thru 'Z'
' VK_0 thru VK_9 are the same as their ASCII equivalents: '0' thru '9'

Public Const VK_NUMPAD0 = &H60
Public Const VK_NUMPAD1 = &H61
Public Const VK_NUMPAD2 = &H62
Public Const VK_NUMPAD3 = &H63
Public Const VK_NUMPAD4 = &H64
Public Const VK_NUMPAD5 = &H65
Public Const VK_NUMPAD6 = &H66
Public Const VK_NUMPAD7 = &H67
Public Const VK_NUMPAD8 = &H68
Public Const VK_NUMPAD9 = &H69
Public Const VK_MULTIPLY = &H6A
Public Const VK_ADD = &H6B
Public Const VK_SEPARATOR = &H6C
Public Const VK_SUBTRACT = &H6D
Public Const VK_DECIMAL = &H6E
Public Const VK_DIVIDE = &H6F
Public Const VK_F1 = &H70
Public Const VK_F2 = &H71
Public Const VK_F3 = &H72
Public Const VK_F4 = &H73
Public Const VK_F5 = &H74
Public Const VK_F6 = &H75
Public Const VK_F7 = &H76
Public Const VK_F8 = &H77
Public Const VK_F9 = &H78
Public Const VK_F10 = &H79
Public Const VK_F11 = &H7A
Public Const VK_F12 = &H7B
Public Const VK_F13 = &H7C
Public Const VK_F14 = &H7D
Public Const VK_F15 = &H7E
Public Const VK_F16 = &H7F
Public Const VK_F17 = &H80
Public Const VK_F18 = &H81
Public Const VK_F19 = &H82
Public Const VK_F20 = &H83
Public Const VK_F21 = &H84
Public Const VK_F22 = &H85
Public Const VK_F23 = &H86
Public Const VK_F24 = &H87

Public Const VK_NUMLOCK = &H90
Public Const VK_SCROLL = &H91

'
'   VK_L VK_R - left and right Alt, Ctrl and Shift virtual keys.
'   Used only as parameters to GetAsyncKeyState() and GetKeyState().
'   No other API or message will distinguish left and right keys in this way.
'  /
Public Const VK_LSHIFT = &HA0
Public Const VK_RSHIFT = &HA1
Public Const VK_LCONTROL = &HA2
Public Const VK_RCONTROL = &HA3
Public Const VK_LMENU = &HA4
Public Const VK_RMENU = &HA5

Public Const VK_ATTN = &HF6
Public Const VK_CRSEL = &HF7
Public Const VK_EXSEL = &HF8
Public Const VK_EREOF = &HF9
Public Const VK_PLAY = &HFA
Public Const VK_ZOOM = &HFB
Public Const VK_NONAME = &HFC
Public Const VK_PA1 = &HFD
Public Const VK_OEM_CLEAR = &HFE

' SetWindowsHook() codes
Public Const WH_MIN = (-1)
Public Const WH_MSGFILTER = (-1)
Public Const WH_JOURNALRECORD = 0
Public Const WH_JOURNALPLAYBACK = 1
Public Const WH_KEYBOARD = 2
Public Const WH_GETMESSAGE = 3
Public Const WH_CALLWNDPROC = 4
Public Const WH_CBT = 5
Public Const WH_SYSMSGFILTER = 6
Public Const WH_MOUSE = 7
Public Const WH_HARDWARE = 8
Public Const WH_DEBUG = 9
Public Const WH_SHELL = 10
Public Const WH_FOREGROUNDIDLE = 11
Public Const WH_MAX = 11

' Hook Codes
Public Const HC_ACTION = 0
Public Const HC_GETNEXT = 1
Public Const HC_SKIP = 2
Public Const HC_NOREMOVE = 3
Public Const HC_NOREM = HC_NOREMOVE
Public Const HC_SYSMODALON = 4
Public Const HC_SYSMODALOFF = 5

' CBT Hook Codes
Public Const HCBT_MOVESIZE = 0
Public Const HCBT_MINMAX = 1
Public Const HCBT_QS = 2
Public Const HCBT_CREATEWND = 3
Public Const HCBT_DESTROYWND = 4
Public Const HCBT_ACTIVATE = 5
Public Const HCBT_CLICKSKIPPED = 6
Public Const HCBT_KEYSKIPPED = 7
Public Const HCBT_SYSCOMMAND = 8
Public Const HCBT_SETFOCUS = 9

' HCBT_ACTIVATE structure pointed to by lParam
Type CBTACTIVATESTRUCT
        fMouse As Long
        hWndActive As Long
End Type

' WH_MSGFILTER Filter Proc Codes
Public Const MSGF_DIALOGBOX = 0
Public Const MSGF_MESSAGEBOX = 1
Public Const MSGF_MENU = 2
Public Const MSGF_MOVE = 3
Public Const MSGF_SIZE = 4
Public Const MSGF_SCROLLBAR = 5
Public Const MSGF_NEXTWINDOW = 6
Public Const MSGF_MAINLOOP = 8
Public Const MSGF_MAX = 8
Public Const MSGF_USER = 4096

Public Const HSHELL_WINDOWCREATED = 1
Public Const HSHELL_WINDOWDESTROYED = 2
Public Const HSHELL_ACTIVATESHELLWINDOW = 3

' Message Structure used in Journaling
Type EVENTMSG
        message As Long
        paramL As Long
        paramH As Long
        time As Long
        hWnd As Long
End Type

Type CWPSTRUCT
        lParam As Long
        wParam As Long
        message As Long
        hWnd As Long
End Type

Type DEBUGHOOKINFO
        hModuleHook As Long
        Reserved As Long
        lParam As Long
        wParam As Long
        code As Long
End Type


Type MOUSEHOOKSTRUCT
        pt As POINTAPI
        hWnd As Long
        wHitTestCode As Long
        dwExtraInfo As Long
End Type

' Keyboard Layout API
Public Const HKL_PREV = 0
Public Const HKL_NEXT = 1

Public Const KLF_ACTIVATE = &H1
Public Const KLF_SUBSTITUTE_OK = &H2
Public Const KLF_UNLOADPREVIOUS = &H4
Public Const KLF_REORDER = &H8
Public Const KLF_REPLACELANG = &H10
Public Const KLF_NOTELLSHELL = &H80
Public Const KLF_SETFORPROCESS = &H100
' Win2000
Public Const KLF_SHIFTLOCK = &H10000
Public Const KLF_RESET = &H40000000


' Size of KeyboardLayoutName (number of characters), including nul terminator
Public Const KL_NAMELENGTH = 9

Declare Function LoadKeyboardLayout Lib "user32" Alias "LoadKeyboardLayoutA" (ByVal pwszKLID As String, ByVal flags As Long) As Long
Declare Function ActivateKeyboardLayout Lib "user32" (ByVal hkl As Long, ByVal flags As Long) As Long
Declare Function UnloadKeyboardLayout Lib "user32" (ByVal hkl As Long) As Long
Declare Function GetKeyboardLayoutName Lib "user32" Alias "GetKeyboardLayoutNameA" (ByVal pwszKLID As String) As Long

' Desktop-specific access flags
Public Const DESKTOP_READOBJECTS = &H1&
Public Const DESKTOP_CREATEWINDOW = &H2&
Public Const DESKTOP_CREATEMENU = &H4&
Public Const DESKTOP_HOOKCONTROL = &H8&
Public Const DESKTOP_JOURNALRECORD = &H10&
Public Const DESKTOP_JOURNALPLAYBACK = &H20&
Public Const DESKTOP_ENUMERATE = &H40&
Public Const DESKTOP_WRITEOBJECTS = &H80&

Declare Function GetThreadDesktop Lib "user32" (ByVal dwThread As Long) As Long

' Windowstation-specific access flags
Public Const WINSTA_ENUMDESKTOPS = &H1&
Public Const WINSTA_READATTRIBUTES = &H2&
Public Const WINSTA_ACCESSCLIPBOARD = &H4&
Public Const WINSTA_CREATEDESKTOP = &H8&
Public Const WINSTA_WRITEATTRIBUTES = &H10&
Public Const WINSTA_ACCESSPUBLICATOMS = &H20&
Public Const WINSTA_EXITWINDOWS = &H40&
Public Const WINSTA_ENUMERATE = &H100&
Public Const WINSTA_READSCREEN = &H200&

' Message structure

' Window field offsets for GetWindowLong() and GetWindowWord()
Public Const GWL_WNDPROC = (-4)
Public Const GWL_HINSTANCE = (-6)
Public Const GWL_HWNDPARENT = (-8)
Public Const GWL_STYLE = (-16)
Public Const GWL_EXSTYLE = (-20)
Public Const GWL_USERDATA = (-21)
Public Const GWL_ID = (-12)

' Class field offsets for GetClassLong() and GetClassWord()
Public Const GCL_MENUNAME = (-8)
Public Const GCL_HBRBACKGROUND = (-10)
Public Const GCL_HCURSOR = (-12)
Public Const GCL_HICON = (-14)
Public Const GCL_HMODULE = (-16)
Public Const GCL_CBWNDEXTRA = (-18)
Public Const GCL_CBCLSEXTRA = (-20)
Public Const GCL_WNDPROC = (-24)
Public Const GCL_STYLE = (-26)
Public Const GCW_ATOM = (-32)

' Window Messages
Public Const WM_NULL = &H0
Public Const WM_CREATE = &H1
Public Const WM_DESTROY = &H2
Public Const WM_MOVE = &H3
Public Const WM_SIZE = &H5

Public Const WM_ACTIVATE = &H6
'
'  WM_ACTIVATE state values

Public Const WA_INACTIVE = 0
Public Const WA_ACTIVE = 1
Public Const WA_CLICKACTIVE = 2

Public Const WM_SETFOCUS = &H7
Public Const WM_KILLFOCUS = &H8
Public Const WM_ENABLE = &HA
Public Const WM_SETREDRAW = &HB
Public Const WM_SETTEXT = &HC
Public Const WM_GETTEXT = &HD
Public Const WM_GETTEXTLENGTH = &HE
Public Const WM_PAINT = &HF
Public Const WM_CLOSE = &H10
Public Const WM_QUERYENDSESSION = &H11
Public Const WM_QUIT = &H12
Public Const WM_QUERYOPEN = &H13
Public Const WM_ERASEBKGND = &H14
Public Const WM_SYSCOLORCHANGE = &H15
Public Const WM_ENDSESSION = &H16
Public Const WM_SHOWWINDOW = &H18
Public Const WM_WININICHANGE = &H1A
Public Const WM_DEVMODECHANGE = &H1B
Public Const WM_ACTIVATEAPP = &H1C
Public Const WM_FONTCHANGE = &H1D
Public Const WM_TIMECHANGE = &H1E
Public Const WM_CANCELMODE = &H1F
Public Const WM_SETCURSOR = &H20
Public Const WM_MOUSEACTIVATE = &H21
Public Const WM_CHILDACTIVATE = &H22
Public Const WM_QUEUESYNC = &H23

Public Const WM_GETMINMAXInfo = &H24

Type MINMAXINFO
        ptReserved As POINTAPI
        ptMaxSize As POINTAPI
        ptMaxPosition As POINTAPI
        ptMinTrackSize As POINTAPI
        ptMaxTrackSize As POINTAPI
End Type

Public Const WM_PAINTICON = &H26
Public Const WM_ICONERASEBKGND = &H27
Public Const WM_NEXTDLGCTL = &H28
Public Const WM_SPOOLERSTATUS = &H2A
Public Const WM_DRAWITEM = &H2B
Public Const WM_MEASUREITEM = &H2C
Public Const WM_DELETEITEM = &H2D
Public Const WM_VKEYTOITEM = &H2E
Public Const WM_CHARTOITEM = &H2F
Public Const WM_SETFONT = &H30
Public Const WM_GETFONT = &H31
Public Const WM_SETHOTKEY = &H32
Public Const WM_GETHOTKEY = &H33
Public Const WM_QUERYDRAGICON = &H37
Public Const WM_COMPAREITEM = &H39
Public Const WM_COMPACTING = &H41
Public Const WM_OTHERWINDOWCREATED = &H42               '  no longer suported
Public Const WM_OTHERWINDOWDESTROYED = &H43             '  no longer suported
Public Const WM_COMMNOTIFY = &H44                       '  no longer suported

' notifications passed in low word of lParam on WM_COMMNOTIFY messages
Public Const CN_RECEIVE = &H1
Public Const CN_TRANSMIT = &H2
Public Const CN_EVENT = &H4

Public Const WM_WINDOWPOSCHANGING = &H46
Public Const WM_WINDOWPOSCHANGED = &H47

Public Const WM_POWER = &H48
'
'  wParam for WM_POWER window message and DRV_POWER driver notification

Public Const PWR_OK = 1
Public Const PWR_FAIL = (-1)
Public Const PWR_SUSPENDREQUEST = 1
Public Const PWR_SUSPENDRESUME = 2
Public Const PWR_CRITICALRESUME = 3

Public Const WM_COPYDATA = &H4A
Public Const WM_CANCELJOURNAL = &H4B

Type COPYDATASTRUCT
        dwData As Long
        cbData As Long
        lpData As Long
End Type

Public Const WM_NCCREATE = &H81
Public Const WM_NCDESTROY = &H82
Public Const WM_NCCALCSIZE = &H83
Public Const WM_NCHITTEST = &H84
Public Const WM_NCPAINT = &H85
Public Const WM_NCACTIVATE = &H86
Public Const WM_GETDLGCODE = &H87
Public Const WM_NCMOUSEMOVE = &HA0
Public Const WM_NCLBUTTONDOWN = &HA1
Public Const WM_NCLBUTTONUP = &HA2
Public Const WM_NCLBUTTONDBLCLK = &HA3
Public Const WM_NCRBUTTONDOWN = &HA4
Public Const WM_NCRBUTTONUP = &HA5
Public Const WM_NCRBUTTONDBLCLK = &HA6
Public Const WM_NCMBUTTONDOWN = &HA7
Public Const WM_NCMBUTTONUP = &HA8
Public Const WM_NCMBUTTONDBLCLK = &HA9

Public Const WM_KEYFIRST = &H100
Public Const WM_KEYDOWN = &H100
Public Const WM_KEYUP = &H101
Public Const WM_CHAR = &H102
Public Const WM_DEADCHAR = &H103
Public Const WM_SYSKEYDOWN = &H104
Public Const WM_SYSKEYUP = &H105
Public Const WM_SYSCHAR = &H106
Public Const WM_SYSDEADCHAR = &H107
Public Const WM_KEYLAST = &H108
Public Const WM_INITDIALOG = &H110
Public Const WM_COMMAND = &H111
Public Const WM_SYSCOMMAND = &H112
Public Const WM_TIMER = &H113
Public Const WM_HSCROLL = &H114
Public Const WM_VSCROLL = &H115
Public Const WM_INITMENU = &H116
Public Const WM_INITMENUPOPUP = &H117
Public Const WM_MENUSELECT = &H11F
Public Const WM_MENUCHAR = &H120
Public Const WM_ENTERIDLE = &H121

Public Const WM_CTLCOLORMSGBOX = &H132
Public Const WM_CTLCOLOREDIT = &H133
Public Const WM_CTLCOLORLISTBOX = &H134
Public Const WM_CTLCOLORBTN = &H135
Public Const WM_CTLCOLORDLG = &H136
Public Const WM_CTLCOLORSCROLLBAR = &H137
Public Const WM_CTLCOLORSTATIC = &H138

Public Const WM_MOUSEFIRST = &H200
Public Const WM_MOUSEMOVE = &H200
Public Const WM_LBUTTONDOWN = &H201
Public Const WM_LBUTTONUP = &H202
Public Const WM_LBUTTONDBLCLK = &H203
Public Const WM_RBUTTONDOWN = &H204
Public Const WM_RBUTTONUP = &H205
Public Const WM_RBUTTONDBLCLK = &H206
Public Const WM_MBUTTONDOWN = &H207
Public Const WM_MBUTTONUP = &H208
Public Const WM_MBUTTONDBLCLK = &H209
Public Const WM_MOUSELAST = &H209

Public Const WM_PARENTNOTIFY = &H210
Public Const WM_ENTERMENULOOP = &H211
Public Const WM_EXITMENULOOP = &H212

Public Const WM_SIZING = &H214
Public Const WM_CAPTURECHANGED = &H215
Public Const WM_MOVING = &H216
Public Const WM_POWERBROADCAST = &H218

Public Const WM_MDICREATE = &H220
Public Const WM_MDIDESTROY = &H221
Public Const WM_MDIACTIVATE = &H222
Public Const WM_MDIRESTORE = &H223
Public Const WM_MDINEXT = &H224
Public Const WM_MDIMAXIMIZE = &H225
Public Const WM_MDITILE = &H226
Public Const WM_MDICASCADE = &H227
Public Const WM_MDIICONARRANGE = &H228
Public Const WM_MDIGETACTIVE = &H229
Public Const WM_MDISETMENU = &H230
Public Const WM_DROPFILES = &H233
Public Const WM_MDIREFRESHMENU = &H234

Public Const WM_CUT = &H300
Public Const WM_COPY = &H301
Public Const WM_PASTE = &H302
Public Const WM_CLEAR = &H303
Public Const WM_UNDO = &H304
Public Const WM_RENDERFORMAT = &H305
Public Const WM_RENDERALLFORMATS = &H306
Public Const WM_DESTROYCLIPBOARD = &H307
Public Const WM_DRAWCLIPBOARD = &H308
Public Const WM_PAINTCLIPBOARD = &H309
Public Const WM_VSCROLLCLIPBOARD = &H30A
Public Const WM_SIZECLIPBOARD = &H30B
Public Const WM_ASKCBFORMATNAME = &H30C
Public Const WM_CHANGECBCHAIN = &H30D
Public Const WM_HSCROLLCLIPBOARD = &H30E
Public Const WM_QUERYNEWPALETTE = &H30F
Public Const WM_PALETTEISCHANGING = &H310
Public Const WM_PALETTECHANGED = &H311
Public Const WM_HOTKEY = &H312

Public Const WM_PENWINFIRST = &H380
Public Const WM_PENWINLAST = &H38F

' NOTE: All Message Numbers below 0x0400 are RESERVED.

' Private Window Messages Start Here:
Public Const WM_USER = &H400

' WM_SYNCTASK Commands
Public Const ST_BEGINSWP = 0
Public Const ST_ENDSWP = 1

' WM_NCHITTEST and MOUSEHOOKSTRUCT Mouse Position Codes
Public Const HTERROR = (-2)
Public Const HTTRANSPARENT = (-1)
Public Const HTNOWHERE = 0
Public Const HTCLIENT = 1
Public Const HTCAPTION = 2
Public Const HTSYSMENU = 3
Public Const HTGROWBOX = 4
Public Const HTSIZE = HTGROWBOX
Public Const HTMENU = 5
Public Const HTHSCROLL = 6
Public Const HTVSCROLL = 7
Public Const HTMINBUTTON = 8
Public Const HTMAXBUTTON = 9
Public Const HTLEFT = 10
Public Const HTRIGHT = 11
Public Const HTTOP = 12
Public Const HTTOPLEFT = 13
Public Const HTTOPRIGHT = 14
Public Const HTBOTTOM = 15
Public Const HTBOTTOMLEFT = 16
Public Const HTBOTTOMRIGHT = 17
Public Const HTBORDER = 18
Public Const HTREDUCE = HTMINBUTTON
Public Const HTZOOM = HTMAXBUTTON
Public Const HTSIZEFIRST = HTLEFT
Public Const HTSIZELAST = HTBOTTOMRIGHT

'  SendMessageTimeout values
Public Const SMTO_NORMAL = &H0
Public Const SMTO_BLOCK = &H1
Public Const SMTO_ABORTIFHUNG = &H2

' WM_MOUSEACTIVATE Return Codes
Public Const MA_ACTIVATE = 1
Public Const MA_ACTIVATEANDEAT = 2
Public Const MA_NOACTIVATE = 3
Public Const MA_NOACTIVATEANDEAT = 4

Declare Function RegisterWindowMessage Lib "user32" Alias "RegisterWindowMessageA" (ByVal lpString As String) As Long

' WM_SIZE message wParam values
Public Const SIZE_RESTORED = 0
Public Const SIZE_MINIMIZED = 1
Public Const SIZE_MAXIMIZED = 2
Public Const SIZE_MAXSHOW = 3
Public Const SIZE_MAXHIDE = 4

' Obsolete constant names
Public Const SIZENORMAL = SIZE_RESTORED
Public Const SIZEICONIC = SIZE_MINIMIZED
Public Const SIZEFULLSCREEN = SIZE_MAXIMIZED
Public Const SIZEZOOMSHOW = SIZE_MAXSHOW
Public Const SIZEZOOMHIDE = SIZE_MAXHIDE

' WM_WINDOWPOSCHANGING/CHANGED struct pointed to by lParam
Type WINDOWPOS
        hWnd As Long
        hWndInsertAfter As Long
        X As Long
        Y As Long
        cx As Long
        cy As Long
        flags As Long
End Type

' WM_NCCALCSIZE return flags
Public Const WVR_ALIGNTOP = &H10
Public Const WVR_ALIGNLEFT = &H20
Public Const WVR_ALIGNBOTTOM = &H40
Public Const WVR_ALIGNRIGHT = &H80
Public Const WVR_HREDRAW = &H100
Public Const WVR_VREDRAW = &H200
Public Const WVR_REDRAW = (WVR_HREDRAW Or WVR_VREDRAW)
Public Const WVR_VALIDRECTS = &H400

' Key State Masks for Mouse Messages
Public Const MK_LBUTTON = &H1
Public Const MK_RBUTTON = &H2
Public Const MK_SHIFT = &H4
Public Const MK_CONTROL = &H8
Public Const MK_MBUTTON = &H10

' Window Styles
Public Const WS_OVERLAPPED = &H0&
Public Const WS_POPUP = &H80000000
Public Const WS_CHILD = &H40000000
Public Const WS_MINIMIZE = &H20000000
Public Const WS_VISIBLE = &H10000000
Public Const WS_DISABLED = &H8000000
Public Const WS_CLIPSIBLINGS = &H4000000
Public Const WS_CLIPCHILDREN = &H2000000
Public Const WS_MAXIMIZE = &H1000000
Public Const WS_CAPTION = &HC00000                  '  WS_BORDER Or WS_DLGFRAME
Public Const WS_BORDER = &H800000
Public Const WS_DLGFRAME = &H400000
Public Const WS_VSCROLL = &H200000
Public Const WS_HSCROLL = &H100000
Public Const WS_SYSMENU = &H80000
Public Const WS_THICKFRAME = &H40000
Public Const WS_GROUP = &H20000
Public Const WS_TABSTOP = &H10000

Public Const WS_MINIMIZEBOX = &H20000
Public Const WS_MAXIMIZEBOX = &H10000

Public Const WS_TILED = WS_OVERLAPPED
Public Const WS_ICONIC = WS_MINIMIZE
Public Const WS_SIZEBOX = WS_THICKFRAME
Public Const WS_OVERLAPPEDWINDOW = (WS_OVERLAPPED Or WS_CAPTION Or WS_SYSMENU Or WS_THICKFRAME Or WS_MINIMIZEBOX Or WS_MAXIMIZEBOX)
Public Const WS_TILEDWINDOW = WS_OVERLAPPEDWINDOW

'
'   Common Window Styles
'  /


Public Const WS_POPUPWINDOW = (WS_POPUP Or WS_BORDER Or WS_SYSMENU)

Public Const WS_CHILDWINDOW = (WS_CHILD)

' Extended Window Styles
Public Const WS_EX_DLGMODALFRAME = &H1&
Public Const WS_EX_NOPARENTNOTIFY = &H4&
Public Const WS_EX_TOPMOST = &H8&
Public Const WS_EX_ACCEPTFILES = &H10&
Public Const WS_EX_TRANSPARENT = &H20&

' Class styles
Public Const CS_VREDRAW = &H1
Public Const CS_HREDRAW = &H2
Public Const CS_KEYCVTWINDOW = &H4
Public Const CS_DBLCLKS = &H8
Public Const CS_OWNDC = &H20
Public Const CS_CLASSDC = &H40
Public Const CS_PARENTDC = &H80
Public Const CS_NOKEYCVT = &H100
Public Const CS_NOCLOSE = &H200
Public Const CS_SAVEBITS = &H800
Public Const CS_BYTEALIGNCLIENT = &H1000
Public Const CS_BYTEALIGNWINDOW = &H2000
Public Const CS_PUBLICCLASS = &H4000

' Predefined Clipboard Formats
Public Const CF_TEXT = 1
Public Const CF_BITMAP = 2
Public Const CF_METAFILEPICT = 3
Public Const CF_SYLK = 4
Public Const CF_DIF = 5
Public Const CF_TIFF = 6
Public Const CF_OEMTEXT = 7
Public Const CF_DIB = 8
Public Const CF_PALETTE = 9
Public Const CF_PENDATA = 10
Public Const CF_RIFF = 11
Public Const CF_WAVE = 12
Public Const CF_UNICODETEXT = 13
Public Const CF_ENHMETAFILE = 14

Public Const CF_OWNERDISPLAY = &H80
Public Const CF_DSPTEXT = &H81
Public Const CF_DSPBITMAP = &H82
Public Const CF_DSPMETAFILEPICT = &H83
Public Const CF_DSPENHMETAFILE = &H8E

' "Private" formats don't get GlobalFree()'d
Public Const CF_PRIVATEFIRST = &H200
Public Const CF_PRIVATELAST = &H2FF

' "GDIOBJ" formats do get DeleteObject()'d
Public Const CF_GDIOBJFIRST = &H300
Public Const CF_GDIOBJLAST = &H3FF

'  Defines for the fVirt field of the Accelerator table structure.
Public Const FVIRTKEY = True          '  Assumed to be == TRUE
Public Const FNOINVERT = &H2
Public Const FSHIFT = &H4
Public Const FCONTROL = &H8
Public Const FALT = &H10

Type ACCEL
        fVirt As Byte
        key As Integer
        cmd As Integer
End Type

Type PAINTSTRUCT
        hdc As Long
        fErase As Long
        rcPaint As RECT
        fRestore As Long
        fIncUpdate As Long
        rgbReserved(32) As Byte
End Type

Type CREATESTRUCT
        lpCreateParams As Long
        hInstance As Long
        hMenu As Long
        hwndParent As Long
        cy As Long
        cx As Long
        Y As Long
        X As Long
        style As Long
        lpszName As String
        lpszClass As String
        ExStyle As Long
End Type

' HCBT_CREATEWND parameters pointed to by lParam
Type CBT_CREATEWND
        lpcs As CREATESTRUCT
        hWndInsertAfter As Long
End Type

Type WINDOWPLACEMENT
        Length As Long
        flags As Long
        showCmd As Long
        ptMinPosition As POINTAPI
        ptMaxPosition As POINTAPI
        rcNormalPosition As RECT
End Type

Public Const WPF_SETMINPOSITION = &H1
Public Const WPF_RESTORETOMAXIMIZED = &H2

' Owner draw control types
Public Const ODT_MENU = 1
Public Const ODT_LISTBOX = 2
Public Const ODT_COMBOBOX = 3
Public Const ODT_BUTTON = 4

' Owner draw actions
Public Const ODA_DRAWENTIRE = &H1
Public Const ODA_SELECT = &H2
Public Const ODA_FOCUS = &H4

' Owner draw state
Public Const ODS_SELECTED = &H1
Public Const ODS_GRAYED = &H2
Public Const ODS_DISABLED = &H4
Public Const ODS_CHECKED = &H8
Public Const ODS_FOCUS = &H10

' MEASUREITEMSTRUCT for ownerdraw
Type MEASUREITEMSTRUCT
        CtlType As Long
        CtlID As Long
        itemID As Long
        itemWidth As Long
        itemHeight As Long
        itemData As Long
End Type

' DRAWITEMSTRUCT for ownerdraw
Type DRAWITEMSTRUCT
        CtlType As Long
        CtlID As Long
        itemID As Long
        itemAction As Long
        itemState As Long
        hwndItem As Long
        hdc As Long
        rcItem As RECT
        itemData As Long
End Type

' DELETEITEMSTRUCT for ownerdraw
Type DELETEITEMSTRUCT
        CtlType As Long
        CtlID As Long
        itemID As Long
        hwndItem As Long
        itemData As Long
End Type

' COMPAREITEMSTRUCT for ownerdraw sorting
Type COMPAREITEMSTRUCT
        CtlType As Long
        CtlID As Long
        hwndItem As Long
        itemID1 As Long
        itemData1 As Long
        itemID2 As Long
        itemData2 As Long
End Type

' Message Function Templates
Declare Function GetMessage Lib "user32" Alias "GetMessageA" (lpMsg As Msg, ByVal hWnd As Long, ByVal wMsgFilterMin As Long, ByVal wMsgFilterMax As Long) As Long
Declare Function TranslateMessage Lib "user32" (lpMsg As Msg) As Long
Declare Function DispatchMessage Lib "user32" Alias "DispatchMessageA" (lpMsg As Msg) As Long
Declare Function PeekMessage Lib "user32" Alias "PeekMessageA" (lpMsg As Msg, ByVal hWnd As Long, ByVal wMsgFilterMin As Long, ByVal wMsgFilterMax As Long, ByVal wRemoveMsg As Long) As Long

' PeekMessage() Options
Public Const PM_NOREMOVE = &H0
Public Const PM_REMOVE = &H1
Public Const PM_NOYIELD = &H2

Declare Function RegisterHotKey Lib "user32" (ByVal hWnd As Long, ByVal id As Long, ByVal fsModifiers As Long, ByVal vk As Long) As Long
Declare Function UnregisterHotKey Lib "user32" (ByVal hWnd As Long, ByVal id As Long) As Long

Public Const MOD_ALT = &H1
Public Const MOD_CONTROL = &H2
Public Const MOD_SHIFT = &H4

Public Const IDHOT_SNAPWINDOW = (-1)    '  SHIFT-PRINTSCRN
Public Const IDHOT_SNAPDESKTOP = (-2)    '  PRINTSCRN

Public Const EWX_LOGOFF = 0
Public Const EWX_SHUTDOWN = 1
Public Const EWX_REBOOT = 2
Public Const EWX_FORCE = 4

Public Const READAPI = 0        '  Flags for _lopen
Public Const WRITEAPI = 1
Public Const READ_WRITE = 2

Declare Function ExitWindows Lib "user32" (ByVal dwReserved As Long, ByVal uReturnCode As Long) As Long
Declare Function ExitWindowsEx Lib "user32" (ByVal uFlags As Long, ByVal dwReserved As Long) As Long

Declare Function SwapMouseButton Lib "user32" (ByVal bSwap As Long) As Long
Declare Function GetMessagePos Lib "user32" () As Long
Declare Function GetMessageTime Lib "user32" () As Long
Declare Function GetMessageExtraInfo Lib "user32" () As Long
Declare Function SendMessage Lib "user32" Alias "SendMessageA" (ByVal hWnd As Long, ByVal wMsg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Declare Function SendMessageTimeout Lib "user32" Alias "SendMessageTimeoutA" (ByVal hWnd As Long, ByVal Msg As Long, ByVal wParam As Long, ByVal lParam As Long, ByVal fuFlags As Long, ByVal uTimeout As Long, lpdwResult As Long) As Long
Declare Function SendNotifyMessage Lib "user32" Alias "SendNotifyMessageA" (ByVal hWnd As Long, ByVal Msg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Declare Function SendMessageCallback Lib "user32" Alias "SendMessageCallbackA" (ByVal hWnd As Long, ByVal Msg As Long, ByVal wParam As Long, ByVal lParam As Long, ByVal lpResultCallBack As Long, ByVal dwData As Long) As Long
Declare Function PostMessage Lib "user32" Alias "PostMessageA" (ByVal hWnd As Long, ByVal wMsg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Declare Function PostThreadMessage Lib "user32" Alias "PostThreadMessageA" (ByVal idThread As Long, ByVal Msg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long

' Special HWND value for use with PostMessage and SendMessage
Public Const HWND_BROADCAST = &HFFFF&


Type WNDCLASS
    style As Long
    lpfnWndProc As Long
    cbClsExtra As Long
    cbWndExtra2 As Long
    hInstance As Long
    hIcon As Long
    hCursor As Long
    hbrBackground As Long
    lpszMenuName As String
    lpszClassName As String
End Type

Declare Function AttachThreadInput Lib "user32" (ByVal idAttach As Long, ByVal idAttachTo As Long, ByVal fAttach As Long) As Long
Declare Function ReplyMessage Lib "user32" (ByVal lReply As Long) As Long
Declare Function WaitMessage Lib "user32" () As Long
Declare Function WaitForInputIdle Lib "user32" (ByVal hProcess As Long, ByVal dwMilliseconds As Long) As Long
Declare Function DefWindowProc Lib "user32" Alias "DefWindowProcA" (ByVal hWnd As Long, ByVal wMsg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Declare Sub PostQuitMessage Lib "user32" (ByVal nExitCode As Long)
Declare Function InSendMessage Lib "user32" () As Long

Private Declare Function InitCommonControls Lib "COMCTL32" () As Long
Private Declare Function ImageList_Create Lib "COMCTL32" (ByVal MinCx As Long, ByVal MinCy As Long, ByVal flags As Long, ByVal cInitial As Long, ByVal cGrow As Long) As Long
Private Declare Function ImageList_AddIcon Lib "COMCTL32" (ByVal himl As Long, ByVal hIcon As Long) As Long
Private Declare Function ImageList_GetIcon Lib "COMCTL32" (ByVal HIMAGELIST As Long, ByVal ImgIndex As Long, hbmMask As Long) As Long
Private Declare Function ImageList_Draw Lib "COMCTL32" (ByVal HIMAGELIST As Long, ByVal ImgIndex As Long, ByVal hDCDest As Long, ByVal xDest As Long, ByVal yDest As Long, ByVal lStyle As Long) As Long




Declare Function GetDoubleClickTime Lib "user32" () As Long
Declare Function SetDoubleClickTime Lib "user32" (ByVal wCount As Long) As Long
Declare Function RegisterClass Lib "user32" Alias "RegisterClassA" (Class As WNDCLASS) As Long
Declare Function UnregisterClass Lib "user32" Alias "UnregisterClassA" (ByVal lpClassName As String, ByVal hInstance As Long) As Long
Declare Function GetClassInfo Lib "user32" Alias "GetClassInfoA" (ByVal hInstance As Long, ByVal lpClassName As String, lpWndClass As WNDCLASS) As Long

Public Const CW_USEDEFAULT = &H80000000
Public Const HWND_DESKTOP = 0

Declare Function CreateWindowEx Lib "user32" Alias "CreateWindowExA" (ByVal dwExStyle As Long, ByVal lpClassName As String, ByVal lpWindowName As String, ByVal dwStyle As Long, ByVal X As Long, ByVal Y As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hwndParent As Long, ByVal hMenu As Long, ByVal hInstance As Long, lpParam As Any) As Long
Declare Function IsWindow Lib "user32" (ByVal hWnd As Long) As Long
Declare Function IsMenu Lib "user32" (ByVal hMenu As Long) As Long
Declare Function IsChild Lib "user32" (ByVal hwndParent As Long, ByVal hWnd As Long) As Long
Declare Function DestroyWindow Lib "user32" (ByVal hWnd As Long) As Long

Declare Function ShowWindow Lib "user32" (ByVal hWnd As Long, ByVal nCmdShow As Long) As Long
Declare Function FlashWindow Lib "user32" (ByVal hWnd As Long, ByVal bInvert As Long) As Long
Declare Function ShowOwnedPopups Lib "user32" (ByVal hWnd As Long, ByVal fShow As Long) As Long

Declare Function OpenIcon Lib "user32" (ByVal hWnd As Long) As Long
Declare Function CloseWindow Lib "user32" (ByVal hWnd As Long) As Long
Declare Function MoveWindow Lib "user32" (ByVal hWnd As Long, ByVal X As Long, ByVal Y As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal bRepaint As Long) As Long
Declare Function SetWindowPos Lib "user32" (ByVal hWnd As Long, ByVal hWndInsertAfter As Long, ByVal X As Long, ByVal Y As Long, ByVal cx As Long, ByVal cy As Long, ByVal wFlags As Long) As Long
Declare Function GetWindowPlacement Lib "user32" (ByVal hWnd As Long, lpwndpl As WINDOWPLACEMENT) As Long
Declare Function SetWindowPlacement Lib "user32" (ByVal hWnd As Long, lpwndpl As WINDOWPLACEMENT) As Long

Declare Function BeginDeferWindowPos Lib "user32" (ByVal nNumWindows As Long) As Long
Declare Function DeferWindowPos Lib "user32" (ByVal hWinPosInfo As Long, ByVal hWnd As Long, ByVal hWndInsertAfter As Long, ByVal X As Long, ByVal Y As Long, ByVal cx As Long, ByVal cy As Long, ByVal wFlags As Long) As Long
Declare Function EndDeferWindowPos Lib "user32" (ByVal hWinPosInfo As Long) As Long

Declare Function IsWindowVisible Lib "user32" (ByVal hWnd As Long) As Long
Declare Function IsIconic Lib "user32" (ByVal hWnd As Long) As Long
Declare Function AnyPopup Lib "user32" () As Long
Declare Function BringWindowToTop Lib "user32" (ByVal hWnd As Long) As Long
Declare Function IsZoomed Lib "user32" (ByVal hWnd As Long) As Long

' SetWindowPos Flags
Public Const SWP_NOSIZE = &H1
Public Const SWP_NOMOVE = &H2
Public Const SWP_NOZORDER = &H4
Public Const SWP_NOREDRAW = &H8
Public Const SWP_NOACTIVATE = &H10
Public Const SWP_FRAMECHANGED = &H20        '  The frame changed: send WM_NCCALCSIZE
Public Const SWP_SHOWWINDOW = &H40
Public Const SWP_HIDEWINDOW = &H80
Public Const SWP_NOCOPYBITS = &H100
Public Const SWP_NOOWNERZORDER = &H200      '  Don't do owner Z ordering

Public Const SWP_DRAWFRAME = SWP_FRAMECHANGED
Public Const SWP_NOREPOSITION = SWP_NOOWNERZORDER

' SetWindowPos() hwndInsertAfter values
Public Const HWND_TOP = 0
Public Const HWND_BOTTOM = 1
Public Const HWND_TOPMOST = -1
Public Const HWND_NOTOPMOST = -2

Type DLGTEMPLATE
        style As Long
        dwExtendedStyle As Long
        cdit As Integer
        X As Integer
        Y As Integer
        cx As Integer
        cy As Integer
End Type

Type DLGITEMTEMPLATE
        style As Long
        dwExtendedStyle As Long
        X As Integer
        Y As Integer
        cx As Integer
        cy As Integer
        id As Integer
End Type

Declare Function EndDialog Lib "user32" (ByVal hDlg As Long, ByVal nResult As Long) As Long
Declare Function GetDlgItem Lib "user32" (ByVal hDlg As Long, ByVal nIDDlgItem As Long) As Long
Declare Function SetDlgItemInt Lib "user32" (ByVal hDlg As Long, ByVal nIDDlgItem As Long, ByVal wValue As Long, ByVal bSigned As Long) As Long
Declare Function GetDlgItemInt Lib "user32" (ByVal hDlg As Long, ByVal nIDDlgItem As Long, ByVal lpTranslated As Long, ByVal bSigned As Long) As Long
Declare Function SetDlgItemText Lib "user32" Alias "SetDlgItemTextA" (ByVal hDlg As Long, ByVal nIDDlgItem As Long, ByVal lpString As String) As Long
Declare Function GetDlgItemText Lib "user32" Alias "GetDlgItemTextA" (ByVal hDlg As Long, ByVal nIDDlgItem As Long, ByVal lpString As String, ByVal nMaxCount As Long) As Long
Declare Function CheckDlgButton Lib "user32" Alias "CheckDLGButtonA" (ByVal hDlg As Long, ByVal nIDButton As Long, ByVal wCheck As Long) As Long
Declare Function CheckRadioButton Lib "user32" Alias "CheckRadioButtonA" (ByVal hDlg As Long, ByVal nIDFirstButton As Long, ByVal nIDLastButton As Long, ByVal nIDCheckButton As Long) As Long
Declare Function IsDlgButtonChecked Lib "user32" (ByVal hDlg As Long, ByVal nIDButton As Long) As Long
Declare Function SendDlgItemMessage Lib "user32" Alias "SendDlgItemMessageA" (ByVal hDlg As Long, ByVal nIDDlgItem As Long, ByVal wMsg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Declare Function GetNextDlgGroupItem Lib "user32" (ByVal hDlg As Long, ByVal hCtl As Long, ByVal bPrevious As Long) As Long
Declare Function GetNextDlgTabItem Lib "user32" (ByVal hDlg As Long, ByVal hCtl As Long, ByVal bPrevious As Long) As Long
Declare Function GetDlgCtrlID Lib "user32" (ByVal hWnd As Long) As Long
Declare Function GetDialogBaseUnits Lib "user32" () As Long
Declare Function DefDlgProc Lib "user32" Alias "DefDlgProcA" (ByVal hDlg As Long, ByVal wMsg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long

Public Const DLGWINDOWEXTRA = 30        '  Window extra bytes needed for private dialog classes

Declare Function CallMsgFilter Lib "user32" Alias "CallMsgFilterA" (lpMsg As Msg, ByVal nCode As Long) As Long

' Clipboard Manager Functions
Declare Function OpenClipboard Lib "user32" (ByVal hWnd As Long) As Long
Declare Function CloseClipboard Lib "user32" () As Long
Declare Function GetClipboardOwner Lib "user32" () As Long
Declare Function SetClipboardViewer Lib "user32" (ByVal hWnd As Long) As Long
Declare Function GetClipboardViewer Lib "user32" () As Long
Declare Function ChangeClipboardChain Lib "user32" (ByVal hWnd As Long, ByVal hWndNext As Long) As Long
Declare Function SetClipboardData Lib "user32" Alias "SetClipboardDataA" (ByVal wFormat As Long, ByVal hMem As Long) As Long
Declare Function GetClipboardData Lib "user32" Alias "GetClipboardDataA" (ByVal wFormat As Long) As Long
Declare Function RegisterClipboardFormat Lib "user32" Alias "RegisterClipboardFormatA" (ByVal lpString As String) As Long
Declare Function CountClipboardFormats Lib "user32" () As Long
Declare Function EnumClipboardFormats Lib "user32" (ByVal wFormat As Long) As Long
Declare Function GetClipboardFormatName Lib "user32" Alias "GetClipboardFormatNameA" (ByVal wFormat As Long, ByVal lpString As String, ByVal nMaxCount As Long) As Long
Declare Function EmptyClipboard Lib "user32" () As Long
Declare Function IsClipboardFormatAvailable Lib "user32" (ByVal wFormat As Long) As Long
Declare Function GetPriorityClipboardFormat Lib "user32" (lpPriorityList As Long, ByVal nCount As Long) As Long
Declare Function GetOpenClipboardWindow Lib "user32" () As Long
Declare Function CharToOem Lib "user32" Alias "CharToOemA" (ByVal lpszSrc As String, ByVal lpszDst As String) As Long
Declare Function OemToChar Lib "user32" Alias "OemToCharA" (ByVal lpszSrc As String, ByVal lpszDst As String) As Long
Declare Function CharToOemBuff Lib "user32" Alias "CharToOemBuffA" (ByVal lpszSrc As String, ByVal lpszDst As String, ByVal cchDstLength As Long) As Long
Declare Function OemToCharBuff Lib "user32" Alias "OemToCharBuffA" (ByVal lpszSrc As String, ByVal lpszDst As String, ByVal cchDstLength As Long) As Long
Declare Function CharUpper Lib "user32" Alias "CharUpperA" (ByVal lpsz As String) As String
Declare Function CharUpperBuff Lib "user32" Alias "CharUpperBuffA" (ByVal lpsz As String, ByVal cchLength As Long) As Long
Declare Function CharLower Lib "user32" Alias "CharLowerA" (ByVal lpsz As String) As String
Declare Function CharLowerBuff Lib "user32" Alias "CharLowerBuffA" (ByVal lpsz As String, ByVal cchLength As Long) As Long
Declare Function CharNext Lib "user32" Alias "CharNextA" (ByVal lpsz As String) As String
Declare Function CharPrev Lib "user32" Alias "CharPrevA" (ByVal lpszStart As String, ByVal lpszCurrent As String) As String

' Language dependent Routines
Declare Function IsCharAlpha Lib "user32" Alias "IsCharAlphaA" (ByVal cChar As Byte) As Long
Declare Function IsCharAlphaNumeric Lib "user32" Alias "IsCharAlphaNumericA" (ByVal cChar As Byte) As Long
Declare Function IsCharUpper Lib "user32" Alias "IsCharUpperA" (ByVal cChar As Byte) As Long
Declare Function IsCharLower Lib "user32" Alias "IsCharLowerA" (ByVal cChar As Byte) As Long

Declare Function SetFocus Lib "user32" (ByVal hWnd As Long) As Long
Declare Function GetFocus Lib "user32" () As Long
Declare Function GetActiveWindow Lib "user32" () As Long

' Keyboard Information Routines
Declare Function GetKBCodePage Lib "user32" () As Long
Declare Function GetKeyState Lib "user32" (ByVal nVirtKey As Long) As Integer
Declare Function GetAsyncKeyState Lib "user32" (ByVal vKey As Long) As Integer
Declare Function GetKeyboardState Lib "user32" (pbKeyState As Byte) As Long
Declare Function SetKeyboardState Lib "user32" (lppbKeyState As Byte) As Long
Declare Function GetKeyboardType Lib "user32" (ByVal nTypeFlag As Long) As Long
Declare Function GetKeyNameText Lib "user32" Alias "GetKeyNameTextA" (ByVal lParam As Long, ByVal lpBuffer As String, ByVal nSize As Long) As Long

Declare Function ToAscii Lib "user32" (ByVal uVirtKey As Long, ByVal uScanCode As Long, lpbKeyState As Byte, lpwTransKey As Long, ByVal fuState As Long) As Long
Declare Function ToUnicode Lib "user32" (ByVal wVirtKey As Long, ByVal wScanCode As Long, lpKeyState As Byte, ByVal pwszBuff As String, ByVal cchBuff As Long, ByVal wFlags As Long) As Long

Declare Function OemKeyScan Lib "user32" (ByVal wOemChar As Long) As Long
Declare Function VkKeyScan Lib "user32" Alias "VkKeyScanA" (ByVal cChar As Byte) As Integer

Public Const KEYEVENTF_EXTENDEDKEY = &H1
Public Const KEYEVENTF_KEYUP = &H2

Declare Sub keybd_event Lib "user32" (ByVal bVk As Byte, ByVal bScan As Byte, ByVal dwFlags As Long, ByVal dwExtraInfo As Long)

Public Const MOUSEEVENTF_MOVE = &H1 '  mouse move
Public Const MOUSEEVENTF_LEFTDOWN = &H2 '  left button down
Public Const MOUSEEVENTF_LEFTUP = &H4 '  left button up
Public Const MOUSEEVENTF_RIGHTDOWN = &H8 '  right button down
Public Const MOUSEEVENTF_RIGHTUP = &H10 '  right button up
Public Const MOUSEEVENTF_MIDDLEDOWN = &H20 '  middle button down
Public Const MOUSEEVENTF_MIDDLEUP = &H40 '  middle button up
Public Const MOUSEEVENTF_ABSOLUTE = &H8000 '  absolute move

Declare Sub mouse_event Lib "user32" (ByVal dwFlags As Long, ByVal dx As Long, ByVal dy As Long, ByVal cButtons As Long, ByVal dwExtraInfo As Long)
Declare Function MapVirtualKey Lib "user32" Alias "MapVirtualKeyA" (ByVal wCode As Long, ByVal wMapType As Long) As Long

Declare Function GetInputState Lib "user32" () As Long
Declare Function GetQueueStatus Lib "user32" (ByVal fuFlags As Long) As Long
Declare Function GetCapture Lib "user32" () As Long
Declare Function SetCapture Lib "user32" (ByVal hWnd As Long) As Long
Declare Function ReleaseCapture Lib "user32" () As Long

Declare Function MsgWaitForMultipleObjects Lib "user32" (ByVal nCount As Long, pHandles As Long, ByVal fWaitAll As Long, ByVal dwMilliseconds As Long, ByVal dwWakeMask As Long) As Long

' GetQueueStatus flags
Public Const QS_KEY = &H1
Public Const QS_MOUSEMOVE = &H2
Public Const QS_MOUSEBUTTON = &H4
Public Const QS_POSTMESSAGE = &H8
Public Const QS_TIMER = &H10
Public Const QS_PAINT = &H20
Public Const QS_SENDMESSAGE = &H40
Public Const QS_HOTKEY = &H80

Public Const QS_MOUSE = (QS_MOUSEMOVE Or QS_MOUSEBUTTON)

Public Const QS_INPUT = (QS_MOUSE Or QS_KEY)

Public Const QS_ALLEVENTS = (QS_INPUT Or QS_POSTMESSAGE Or QS_TIMER Or QS_PAINT Or QS_HOTKEY)

Public Const QS_ALLINPUT = (QS_SENDMESSAGE Or QS_PAINT Or QS_TIMER Or QS_POSTMESSAGE Or QS_MOUSEBUTTON Or QS_MOUSEMOVE Or QS_HOTKEY Or QS_KEY)

' Windows Functions
Declare Function KillTimer Lib "user32" (ByVal hWnd As Long, ByVal nIDEvent As Long) As Long

Declare Function IsWindowUnicode Lib "user32" (ByVal hWnd As Long) As Long

Declare Function EnableWindow Lib "user32" (ByVal hWnd As Long, ByVal fEnable As Long) As Long
Declare Function IsWindowEnabled Lib "user32" (ByVal hWnd As Long) As Long

Declare Function LoadAccelerators Lib "user32" Alias "LoadAcceleratorsA" (ByVal hInstance As Long, ByVal lpTableName As String) As Long
Declare Function CreateAcceleratorTable Lib "user32" Alias "CreateAcceleratorTableA" (lpaccl As ACCEL, ByVal cEntries As Long) As Long
Declare Function DestroyAcceleratorTable Lib "user32" (ByVal haccel As Long) As Long
Declare Function CopyAcceleratorTable Lib "user32" Alias "CopyAcceleratorTableA" (ByVal hAccelSrc As Long, lpAccelDst As ACCEL, ByVal cAccelEntries As Long) As Long
Declare Function TranslateAccelerator Lib "user32" Alias "TranslateAcceleratorA" (ByVal hWnd As Long, ByVal hAccTable As Long, lpMsg As Msg) As Long

' GetSystemMetrics() codes
Public Const SM_CXSCREEN = 0
Public Const SM_CYSCREEN = 1
Public Const SM_CXVSCROLL = 2
Public Const SM_CYHSCROLL = 3
Public Const SM_CYCAPTION = 4
Public Const SM_CXBORDER = 5
Public Const SM_CYBORDER = 6
Public Const SM_CXDLGFRAME = 7
Public Const SM_CYDLGFRAME = 8
Public Const SM_CYVTHUMB = 9
Public Const SM_CXHTHUMB = 10
Public Const SM_CXICON = 11
Public Const SM_CYICON = 12
Public Const SM_CXCURSOR = 13
Public Const SM_CYCURSOR = 14
Public Const SM_CYMENU = 15
Public Const SM_CXFULLSCREEN = 16
Public Const SM_CYFULLSCREEN = 17
Public Const SM_CYKANJIWINDOW = 18
Public Const SM_MOUSEPRESENT = 19
Public Const SM_CYVSCROLL = 20
Public Const SM_CXHSCROLL = 21
Public Const SM_DEBUG = 22
Public Const SM_SWAPBUTTON = 23
Public Const SM_RESERVED1 = 24
Public Const SM_RESERVED2 = 25
Public Const SM_RESERVED3 = 26
Public Const SM_RESERVED4 = 27
Public Const SM_CXMIN = 28
Public Const SM_CYMIN = 29
Public Const SM_CXSIZE = 30
Public Const SM_CYSIZE = 31
Public Const SM_CXFRAME = 32
Public Const SM_CYFRAME = 33
Public Const SM_CXMINTRACK = 34
Public Const SM_CYMINTRACK = 35
Public Const SM_CXDOUBLECLK = 36
Public Const SM_CYDOUBLECLK = 37
Public Const SM_CXICONSPACING = 38
Public Const SM_CYICONSPACING = 39
Public Const SM_MENUDROPALIGNMENT = 40
Public Const SM_PENWINDOWS = 41
Public Const SM_DBCSENABLED = 42
Public Const SM_CMOUSEBUTTONS = 43
Public Const SM_CMETRICS = 44
Public Const SM_CXSIZEFRAME = SM_CXFRAME
Public Const SM_CYSIZEFRAME = SM_CYFRAME
Public Const SM_CXFIXEDFRAME = SM_CXDLGFRAME
Public Const SM_CYFIXEDFRAME = SM_CYDLGFRAME

Declare Function GetSystemMetrics Lib "user32" (ByVal nIndex As Long) As Long

Declare Function LoadMenu Lib "user32" Alias "LoadMenuA" (ByVal hInstance As Long, ByVal lpString As String) As Long
Declare Function LoadMenuIndirect Lib "user32" Alias "LoadMenuIndirectA" (ByVal lpMenuTemplate As Long) As Long
Declare Function GetMenu Lib "user32" (ByVal hWnd As Long) As Long
Declare Function SetMenu Lib "user32" (ByVal hWnd As Long, ByVal hMenu As Long) As Long
Declare Function HiliteMenuItem Lib "user32" (ByVal hWnd As Long, ByVal hMenu As Long, ByVal wIDHiliteItem As Long, ByVal wHilite As Long) As Long
Declare Function GetMenuString Lib "user32" Alias "GetMenuStringA" (ByVal hMenu As Long, ByVal wIDItem As Long, ByVal lpString As String, ByVal nMaxCount As Long, ByVal wFlag As Long) As Long
Declare Function GetMenuState Lib "user32" (ByVal hMenu As Long, ByVal wID As Long, ByVal wFlags As Long) As Long
Declare Function DrawMenuBar Lib "user32" (ByVal hWnd As Long) As Long
Declare Function GetSystemMenu Lib "user32" (ByVal hWnd As Long, ByVal bRevert As Long) As Long
Declare Function CreateMenu Lib "user32" () As Long
Declare Function CreatePopupMenu Lib "user32" () As Long
Declare Function DestroyMenu Lib "user32" (ByVal hMenu As Long) As Long
Declare Function CheckMenuItem Lib "user32" (ByVal hMenu As Long, ByVal wIDCheckItem As Long, ByVal wCheck As Long) As Long
Declare Function EnableMenuItem Lib "user32" (ByVal hMenu As Long, ByVal wIDEnableItem As Long, ByVal wEnable As Long) As Long
Declare Function GetSubMenu Lib "user32" (ByVal hMenu As Long, ByVal nPos As Long) As Long
Declare Function GetMenuItemID Lib "user32" (ByVal hMenu As Long, ByVal nPos As Long) As Long
Declare Function GetMenuItemCount Lib "user32" (ByVal hMenu As Long) As Long

Declare Function InsertMenu Lib "user32" Alias "InsertMenuA" (ByVal hMenu As Long, ByVal nPosition As Long, ByVal wFlags As Long, ByVal wIDNewItem As Long, ByVal lpNewItem As Any) As Long
Declare Function AppendMenu Lib "user32" Alias "AppendMenuA" (ByVal hMenu As Long, ByVal wFlags As Long, ByVal wIDNewItem As Long, ByVal lpNewItem As Any) As Long
Declare Function ModifyMenu Lib "user32" Alias "ModifyMenuA" (ByVal hMenu As Long, ByVal nPosition As Long, ByVal wFlags As Long, ByVal wIDNewItem As Long, ByVal lpString As Any) As Long
Declare Function RemoveMenu Lib "user32" (ByVal hMenu As Long, ByVal nPosition As Long, ByVal wFlags As Long) As Long
Declare Function DeleteMenu Lib "user32" (ByVal hMenu As Long, ByVal nPosition As Long, ByVal wFlags As Long) As Long
Declare Function SetMenuItemBitmaps Lib "user32" (ByVal hMenu As Long, ByVal nPosition As Long, ByVal wFlags As Long, ByVal hBitmapUnchecked As Long, ByVal hBitmapChecked As Long) As Long
Declare Function GetMenuCheckMarkDimensions Lib "user32" () As Long
Declare Function TrackPopupMenu Lib "user32" (ByVal hMenu As Long, ByVal wFlags As Long, ByVal X As Long, ByVal Y As Long, ByVal nReserved As Long, ByVal hWnd As Long, lprc As RECT) As Long

' Flags for TrackPopupMenu
Public Const TPM_LEFTBUTTON = &H0&
Public Const TPM_RIGHTBUTTON = &H2&
Public Const TPM_LEFTALIGN = &H0&
Public Const TPM_CENTERALIGN = &H4&
Public Const TPM_RIGHTALIGN = &H8&

Declare Function DrawIcon Lib "user32" (ByVal hdc As Long, ByVal X As Long, ByVal Y As Long, ByVal hIcon As Long) As Long

' DrawText() Format Flags
Public Const DT_TOP = &H0
Public Const DT_LEFT = &H0
Public Const DT_CENTER = &H1
Public Const DT_RIGHT = &H2
Public Const DT_VCENTER = &H4
Public Const DT_BOTTOM = &H8
Public Const DT_WORDBREAK = &H10
Public Const DT_SINGLELINE = &H20
Public Const DT_EXPANDTABS = &H40
Public Const DT_TABSTOP = &H80
Public Const DT_NOCLIP = &H100
Public Const DT_EXTERNALLEADING = &H200
Public Const DT_CALCRECT = &H400
Public Const DT_NOPREFIX = &H800
Public Const DT_INTERNAL = &H1000

Declare Function DrawText Lib "user32" Alias "DrawTextA" (ByVal hdc As Long, ByVal lpStr As String, ByVal nCount As Long, lpRect As RECT, ByVal wFormat As Long) As Long
Declare Function TabbedTextOut Lib "user32" Alias "TabbedTextOutA" (ByVal hdc As Long, ByVal X As Long, ByVal Y As Long, ByVal lpString As String, ByVal nCount As Long, ByVal nTabPositions As Long, lpnTabStopPositions As Long, ByVal nTabOrigin As Long) As Long
Declare Function GetTabbedTextExtent Lib "user32" Alias "GetTabbedTextExtentA" (ByVal hdc As Long, ByVal lpString As String, ByVal nCount As Long, ByVal nTabPositions As Long, lpnTabStopPositions As Long) As Long

Declare Function UpdateWindow Lib "user32" (ByVal hWnd As Long) As Long
Declare Function SetActiveWindow Lib "user32" (ByVal hWnd As Long) As Long
Declare Function GetForegroundWindow Lib "user32" () As Long
Declare Function SetForegroundWindow Lib "user32" (ByVal hWnd As Long) As Long
Declare Function WindowFromDC Lib "user32" (ByVal hdc As Long) As Long

Declare Function GetDC Lib "user32" (ByVal hWnd As Long) As Long
Declare Function GetDCEx Lib "user32" (ByVal hWnd As Long, ByVal hrgnclip As Long, ByVal fdwOptions As Long) As Long

Public Const DCX_WINDOW = &H1&
Public Const DCX_CACHE = &H2&
Public Const DCX_NORESETATTRS = &H4&
Public Const DCX_CLIPCHILDREN = &H8&
Public Const DCX_CLIPSIBLINGS = &H10&
Public Const DCX_PARENTCLIP = &H20&

Public Const DCX_EXCLUDERGN = &H40&
Public Const DCX_INTERSECTRGN = &H80&

Public Const DCX_EXCLUDEUPDATE = &H100&
Public Const DCX_INTERSECTUPDATE = &H200&

Public Const DCX_LOCKWINDOWUPDATE = &H400&

Public Const DCX_NORECOMPUTE = &H100000
Public Const DCX_VALIDATE = &H200000

Declare Function GetWindowDC Lib "user32" (ByVal hWnd As Long) As Long
Declare Function ReleaseDC Lib "user32" (ByVal hWnd As Long, ByVal hdc As Long) As Long

Declare Function BeginPaint Lib "user32" (ByVal hWnd As Long, lpPaint As PAINTSTRUCT) As Long
Declare Function EndPaint Lib "user32" (ByVal hWnd As Long, lpPaint As PAINTSTRUCT) As Long
Declare Function GetUpdateRect Lib "user32" (ByVal hWnd As Long, lpRect As RECT, ByVal bErase As Long) As Long
Declare Function GetUpdateRgn Lib "user32" (ByVal hWnd As Long, ByVal hRgn As Long, ByVal fErase As Long) As Long
Declare Function ExcludeUpdateRgn Lib "user32" (ByVal hdc As Long, ByVal hWnd As Long) As Long
Declare Function InvalidateRect Lib "user32" (ByVal hWnd As Long, lpRect As RECT, ByVal bErase As Long) As Long
Declare Function ValidateRect Lib "user32" (ByVal hWnd As Long, lpRect As RECT) As Long
Declare Function InvalidateRgn Lib "user32" (ByVal hWnd As Long, ByVal hRgn As Long, ByVal bErase As Long) As Long
Declare Function ValidateRgn Lib "user32" (ByVal hWnd As Long, ByVal hRgn As Long) As Long

Declare Function RedrawWindow Lib "user32" (ByVal hWnd As Long, lprcUpdate As RECT, ByVal hrgnUpdate As Long, ByVal fuRedraw As Long) As Long

Public Const RDW_INVALIDATE = &H1
Public Const RDW_INTERNALPAINT = &H2
Public Const RDW_ERASE = &H4

Public Const RDW_VALIDATE = &H8
Public Const RDW_NOINTERNALPAINT = &H10
Public Const RDW_NOERASE = &H20

Public Const RDW_NOCHILDREN = &H40
Public Const RDW_ALLCHILDREN = &H80

Public Const RDW_UPDATENOW = &H100
Public Const RDW_ERASENOW = &H200

Public Const RDW_FRAME = &H400
Public Const RDW_NOFRAME = &H800

Declare Function LockWindowUpdate Lib "user32" (ByVal hwndLock As Long) As Long

Declare Function ScrollWindow Lib "user32" (ByVal hWnd As Long, ByVal XAmount As Long, ByVal YAmount As Long, lpRect As RECT, lpClipRect As RECT) As Long
Declare Function ScrollDC Lib "user32" (ByVal hdc As Long, ByVal dx As Long, ByVal dy As Long, lprcScroll As RECT, lprcClip As RECT, ByVal hrgnUpdate As Long, lprcUpdate As RECT) As Long
Declare Function ScrollWindowEx Lib "user32" (ByVal hWnd As Long, ByVal dx As Long, ByVal dy As Long, lprcScroll As RECT, lprcClip As RECT, ByVal hrgnUpdate As Long, lprcUpdate As RECT, ByVal fuScroll As Long) As Long

Public Const SW_SCROLLCHILDREN = &H1
Public Const SW_INVALIDATE = &H2
Public Const SW_ERASE = &H4

Declare Function SetScrollPos Lib "user32" (ByVal hWnd As Long, ByVal nBar As Long, ByVal nPos As Long, ByVal bRedraw As Long) As Long
Declare Function GetScrollPos Lib "user32" (ByVal hWnd As Long, ByVal nBar As Long) As Long
Declare Function SetScrollRange Lib "user32" (ByVal hWnd As Long, ByVal nBar As Long, ByVal nMinPos As Long, ByVal nMaxPos As Long, ByVal bRedraw As Long) As Long
Declare Function GetScrollRange Lib "user32" (ByVal hWnd As Long, ByVal nBar As Long, lpMinPos As Long, lpMaxPos As Long) As Long
Declare Function ShowScrollBar Lib "user32" (ByVal hWnd As Long, ByVal wBar As Long, ByVal bShow As Long) As Long
Declare Function EnableScrollBar Lib "user32" (ByVal hWnd As Long, ByVal wSBflags As Long, ByVal wArrows As Long) As Long

' EnableScrollBar() flags
Public Const ESB_ENABLE_BOTH = &H0
Public Const ESB_DISABLE_BOTH = &H3

Public Const ESB_DISABLE_LEFT = &H1
Public Const ESB_DISABLE_RIGHT = &H2

Public Const ESB_DISABLE_UP = &H1
Public Const ESB_DISABLE_DOWN = &H2

Public Const ESB_DISABLE_LTUP = ESB_DISABLE_LEFT
Public Const ESB_DISABLE_RTDN = ESB_DISABLE_RIGHT

Declare Function SetProp Lib "user32" Alias "SetPropA" (ByVal hWnd As Long, ByVal lpString As String, ByVal hData As Long) As Long
Declare Function GetProp Lib "user32" Alias "GetPropA" (ByVal hWnd As Long, ByVal lpString As String) As Long
Declare Function RemoveProp Lib "user32" Alias "RemovePropA" (ByVal hWnd As Long, ByVal lpString As String) As Long

Declare Function SetWindowText Lib "user32" Alias "SetWindowTextA" (ByVal hWnd As Long, ByVal lpString As String) As Long
Declare Function GetWindowText Lib "user32" Alias "GetWindowTextA" (ByVal hWnd As Long, ByVal lpString As String, ByVal cch As Long) As Long
Declare Function GetWindowTextLength Lib "user32" Alias "GetWindowTextLengthA" (ByVal hWnd As Long) As Long

Declare Function GetClientRect Lib "user32" (ByVal hWnd As Long, lpRect As RECT) As Long
Declare Function GetWindowRect Lib "user32" (ByVal hWnd As Long, lpRect As RECT) As Long
Declare Function AdjustWindowRect Lib "user32" (lpRect As RECT, ByVal dwStyle As Long, ByVal bMenu As Long) As Long
Declare Function AdjustWindowRectEx Lib "user32" (lpRect As RECT, ByVal dsStyle As Long, ByVal bMenu As Long, ByVal dwEsStyle As Long) As Long

' MessageBox() Flags
Public Const MB_OK = &H0&
Public Const MB_OKCANCEL = &H1&
Public Const MB_ABORTRETRYIGNORE = &H2&
Public Const MB_YESNOCANCEL = &H3&
Public Const MB_YESNO = &H4&
Public Const MB_RETRYCANCEL = &H5&

Public Const MB_ICONHAND = &H10&
Public Const MB_ICONQUESTION = &H20&
Public Const MB_ICONEXCLAMATION = &H30&
Public Const MB_ICONASTERISK = &H40&

Public Const MB_ICONINFORMATION = MB_ICONASTERISK
Public Const MB_ICONSTOP = MB_ICONHAND

Public Const MB_DEFBUTTON1 = &H0&
Public Const MB_DEFBUTTON2 = &H100&
Public Const MB_DEFBUTTON3 = &H200&

Public Const MB_APPLMODAL = &H0&
Public Const MB_SYSTEMMODAL = &H1000&
Public Const MB_TASKMODAL = &H2000&

Public Const MB_NOFOCUS = &H8000&
Public Const MB_SETFOREGROUND = &H10000
Public Const MB_DEFAULT_DESKTOP_ONLY = &H20000

Public Const MB_TYPEMASK = &HF&
Public Const MB_ICONMASK = &HF0&
Public Const MB_DEFMASK = &HF00&
Public Const MB_MODEMASK = &H3000&
Public Const MB_MISCMASK = &HC000&

Declare Function MessageBox Lib "user32" Alias "MessageBoxA" (ByVal hWnd As Long, ByVal lpText As String, ByVal lpCaption As String, ByVal wType As Long) As Long
Declare Function MessageBoxEx Lib "user32" Alias "MessageBoxExA" (ByVal hWnd As Long, ByVal lpText As String, ByVal lpCaption As String, ByVal uType As Long, ByVal wLanguageId As Long) As Long
Declare Function MessageBeep Lib "user32" (ByVal wType As Long) As Long

Declare Function ShowCursor Lib "user32" (ByVal bShow As Long) As Long
Declare Function SetCursorPos Lib "user32" (ByVal X As Long, ByVal Y As Long) As Long
Declare Function SetCursor Lib "user32" (ByVal hCursor As Long) As Long
Declare Function GetCursorPos Lib "user32" (lpPoint As POINTAPI) As Long
Declare Function ClipCursor Lib "user32" (ByVal lpRect As Long) As Long
Declare Function ClipCursor_ Lib "user32" Alias "ClipCursor" (ByVal lpRect As Long) As Long
Declare Function GetCursor Lib "user32" () As Long
Declare Function GetClipCursor Lib "user32" (lprc As RECT) As Long

Declare Function CreateCaret Lib "user32" (ByVal hWnd As Long, ByVal hBitmap As Long, ByVal nWidth As Long, ByVal nHeight As Long) As Long
Declare Function GetCaretBlinkTime Lib "user32" () As Long
Declare Function SetCaretBlinkTime Lib "user32" (ByVal wMSeconds As Long) As Long
Declare Function DestroyCaret Lib "user32" () As Long
Declare Function HideCaret Lib "user32" (ByVal hWnd As Long) As Long
Declare Function ShowCaret Lib "user32" (ByVal hWnd As Long) As Long
Declare Function SetCaretPos Lib "user32" (ByVal X As Long, ByVal Y As Long) As Long
Declare Function GetCaretPos Lib "user32" (lpPoint As POINTAPI) As Long

Declare Function ClientToScreen Lib "user32" (ByVal hWnd As Long, lpPoint As POINTAPI) As Long
Declare Function ScreenToClient Lib "user32" (ByVal hWnd As Long, lpPoint As POINTAPI) As Long

Declare Function MapWindowPoints Lib "user32" (ByVal hwndFrom As Long, ByVal hwndTo As Long, lppt As Any, ByVal cPoints As Long) As Long
Declare Function WindowFromPoint Lib "user32" (ByVal xPoint As Long, ByVal yPoint As Long) As Long
Declare Function ChildWindowFromPoint Lib "user32" (ByVal hWnd As Long, ByVal xPoint As Long, ByVal yPoint As Long) As Long

' Color Types
Public Const CTLCOLOR_MSGBOX = 0
Public Const CTLCOLOR_EDIT = 1
Public Const CTLCOLOR_LISTBOX = 2
Public Const CTLCOLOR_BTN = 3
Public Const CTLCOLOR_DLG = 4
Public Const CTLCOLOR_SCROLLBAR = 5
Public Const CTLCOLOR_STATIC = 6
Public Const CTLCOLOR_MAX = 8   '  three bits max

Public Const COLOR_SCROLLBAR = 0
Public Const COLOR_BACKGROUND = 1
Public Const COLOR_ACTIVECAPTION = 2
Public Const COLOR_INACTIVECAPTION = 3
Public Const COLOR_MENU = 4
Public Const COLOR_WINDOW = 5
Public Const COLOR_WINDOWFRAME = 6
Public Const COLOR_MENUTEXT = 7
Public Const COLOR_WINDOWTEXT = 8
Public Const COLOR_CAPTIONTEXT = 9
Public Const COLOR_ACTIVEBORDER = 10
Public Const COLOR_INACTIVEBORDER = 11
Public Const COLOR_APPWORKSPACE = 12
Public Const COLOR_HIGHLIGHT = 13
Public Const COLOR_HIGHLIGHTTEXT = 14
Public Const COLOR_BTNFACE = 15
Public Const COLOR_BTNSHADOW = 16
Public Const COLOR_GRAYTEXT = 17
Public Const COLOR_BTNTEXT = 18
Public Const COLOR_INACTIVECAPTIONTEXT = 19
Public Const COLOR_BTNHIGHLIGHT = 20

Declare Function GetSysColor Lib "user32" (ByVal nIndex As Long) As Long
Declare Function SetSysColors Lib "user32" (ByVal nChanges As Long, lpSysColor As Long, lpColorValues As Long) As Long

Declare Function DrawFocusRect Lib "user32" (ByVal hdc As Long, lpRect As RECT) As Long
Declare Function FillRect Lib "user32" (ByVal hdc As Long, lpRect As RECT, ByVal hBrush As Long) As Long
Declare Function FrameRect Lib "user32" (ByVal hdc As Long, lpRect As RECT, ByVal hBrush As Long) As Long
Declare Function InvertRect Lib "user32" (ByVal hdc As Long, lpRect As RECT) As Long
Declare Function SetRect Lib "user32" (lpRect As RECT, ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long) As Long
Declare Function SetRectEmpty Lib "user32" (lpRect As RECT) As Long
Declare Function CopyRect Lib "user32" (lpDestRect As RECT, lpSourceRect As RECT) As Long
Declare Function InflateRect Lib "user32" (lpRect As RECT, ByVal X As Long, ByVal Y As Long) As Long
Declare Function IntersectRect Lib "user32" (lpDestRect As RECT, lpSrc1Rect As RECT, lpSrc2Rect As RECT) As Long
Declare Function UnionRect Lib "user32" (lpDestRect As RECT, lpSrc1Rect As RECT, lpSrc2Rect As RECT) As Long
Declare Function SubtractRect Lib "user32" (lprcDst As RECT, lprcSrc1 As RECT, lprcSrc2 As RECT) As Long
Declare Function OffsetRect Lib "user32" (lpRect As RECT, ByVal X As Long, ByVal Y As Long) As Long
Declare Function IsRectEmpty Lib "user32" (lpRect As RECT) As Long
Declare Function EqualRect Lib "user32" (lpRect1 As RECT, lpRect2 As RECT) As Long
Declare Function PtInRect Lib "user32" (lpRect As RECT, pt As POINTAPI) As Long

Declare Function GetWindowWord Lib "user32" (ByVal hWnd As Long, ByVal nIndex As Long) As Integer
Declare Function SetWindowWord Lib "user32" (ByVal hWnd As Long, ByVal nIndex As Long, ByVal wNewWord As Long) As Long
Declare Function GetWindowLong Lib "user32" Alias "GetWindowLongA" (ByVal hWnd As Long, ByVal nIndex As Long) As Long
Declare Function SetWindowLong Lib "user32" Alias "SetWindowLongA" (ByVal hWnd As Long, ByVal nIndex As Long, ByVal dwNewLong As Long) As Long
Declare Function GetClassWord Lib "user32" (ByVal hWnd As Long, ByVal nIndex As Long) As Long
Declare Function SetClassWord Lib "user32" (ByVal hWnd As Long, ByVal nIndex As Long, ByVal wNewWord As Long) As Long
Declare Function GetClassLong Lib "user32" Alias "GetClassLongA" (ByVal hWnd As Long, ByVal nIndex As Long) As Long
Declare Function SetClassLong Lib "user32" Alias "SetClassLongA" (ByVal hWnd As Long, ByVal nIndex As Long, ByVal dwNewLong As Long) As Long
Declare Function GetDesktopWindow Lib "user32" () As Long

Declare Function GetParent Lib "user32" (ByVal hWnd As Long) As Long
Declare Function SetParent Lib "user32" (ByVal hWndChild As Long, ByVal hWndNewParent As Long) As Long
Declare Function FindWindow Lib "user32" Alias "FindWindowA" (ByVal lpClassName As String, ByVal lpWindowName As String) As Long

Declare Function GetClassName Lib "user32" Alias "GetClassNameA" (ByVal hWnd As Long, ByVal lpClassName As String, ByVal nMaxCount As Long) As Long
Declare Function GetTopWindow Lib "user32" (ByVal hWnd As Long) As Long
Declare Function GetNextWindow Lib "user32" Alias "GetWindow" (ByVal hWnd As Long, ByVal wFlag As Long) As Long

Declare Function GetWindowThreadProcessId Lib "user32" (ByVal hWnd As Long, lpdwProcessId As Long) As Long

Declare Function GetLastActivePopup Lib "user32" (ByVal hwndOwnder As Long) As Long

' GetWindow() Constants
Public Const GW_HWNDFIRST = 0
Public Const GW_HWNDLAST = 1
Public Const GW_HWNDNEXT = 2
Public Const GW_HWNDPREV = 3
Public Const GW_OWNER = 4
Public Const GW_CHILD = 5
Public Const GW_MAX = 5

Declare Function GetWindow Lib "user32" (ByVal hWnd As Long, ByVal wCmd As Long) As Long
Declare Function UnhookWindowsHookEx Lib "user32" (ByVal hHook As Long) As Long
Declare Function CallNextHookEx Lib "user32" (ByVal hHook As Long, ByVal nCode As Long, ByVal wParam As Long, lParam As Any) As Long

' Menu flags for Add/Check/EnableMenuItem()
Public Const MF_INSERT = &H0&
Public Const MF_CHANGE = &H80&
Public Const MF_APPEND = &H100&
Public Const MF_DELETE = &H200&
Public Const MF_REMOVE = &H1000&

Public Const MF_BYCOMMAND = &H0&
Public Const MF_BYPOSITION = &H400&

Public Const MF_SEPARATOR = &H800&

Public Const MF_ENABLED = &H0&
Public Const MF_GRAYED = &H1&
Public Const MF_DISABLED = &H2&

Public Const MF_UNCHECKED = &H0&
Public Const MF_CHECKED = &H8&
Public Const MF_USECHECKBITMAPS = &H200&

Public Const MF_STRING = &H0&
Public Const MF_BITMAP = &H4&
Public Const MF_OWNERDRAW = &H100&

Public Const MF_POPUP = &H10&
Public Const MF_MENUBARBREAK = &H20&
Public Const MF_MENUBREAK = &H40&

Public Const MF_UNHILITE = &H0&
Public Const MF_HILITE = &H80&

Public Const MF_SYSMENU = &H2000&
Public Const MF_HELP = &H4000&
Public Const MF_MOUSESELECT = &H8000&

' Menu item resource format
Type MENUITEMTEMPLATEHEADER
        versionNumber As Integer
        offset As Integer
End Type

Type MENUITEMTEMPLATE
        mtOption As Integer
        mtID As Integer
        mtString As Byte
End Type

Public Const MF_END = &H80

' System Menu Command Values


Public Const SC_SIZE = &HF000&
Public Const SC_MOVE = &HF010&
Public Const SC_MINIMIZE = &HF020&
Public Const SC_MAXIMIZE = &HF030&
Public Const SC_NEXTWINDOW = &HF040&
Public Const SC_PREVWINDOW = &HF050&
Public Const SC_CLOSE = &HF060&
Public Const SC_VSCROLL = &HF070&
Public Const SC_HSCROLL = &HF080&
Public Const SC_MOUSEMENU = &HF090&
Public Const SC_KEYMENU = &HF100&
Public Const SC_ARRANGE = &HF110&
Public Const SC_RESTORE = &HF120&
Public Const SC_TASKLIST = &HF130&
Public Const SC_SCREENSAVE = &HF140&
Public Const SC_HOTKEY = &HF150&

' Obsolete names
Public Const SC_ICON = SC_MINIMIZE
Public Const SC_ZOOM = SC_MAXIMIZE

' Resource Loading Routines
Declare Function LoadBitmap Lib "user32" Alias "LoadBitmapA" (ByVal hInstance As Long, ByVal lpBitmapName As String) As Long
Declare Function LoadCursor Lib "user32" Alias "LoadCursorA" (ByVal hInstance As Long, ByVal lpCursorName As String) As Long
Declare Function CreateCursor Lib "user32" (ByVal hInstance As Long, ByVal nXhotspot As Long, ByVal nYhotspot As Long, ByVal nWidth As Long, ByVal nHeight As Long, lpANDbitPlane As Any, lpXORbitPlane As Any) As Long
Declare Function DestroyCursor Lib "user32" (ByVal hCursor As Long) As Long
Declare Function CopyCursor Lib "user32" (ByVal hcur As Long) As Long

' Standard Cursor IDs
Public Const IDC_ARROW = 32512&
Public Const IDC_IBEAM = 32513&
Public Const IDC_WAIT = 32514&
Public Const IDC_CROSS = 32515&
Public Const IDC_UPARROW = 32516&
Public Const IDC_SIZE = 32640&
Public Const IDC_ICON = 32641&
Public Const IDC_SIZENWSE = 32642&
Public Const IDC_SIZENESW = 32643&
Public Const IDC_SIZEWE = 32644&
Public Const IDC_SIZENS = 32645&
Public Const IDC_SIZEALL = 32646&
Public Const IDC_NO = 32648&
Public Const IDC_APPSTARTING = 32650&

Type ICONINFO
        fIcon As Long
        xHotspot As Long
        yHotspot As Long
        hbmMask As Long
        hbmColor As Long
End Type

Declare Function LoadIcon Lib "user32" Alias "LoadIconA" (ByVal hInstance As Long, ByVal lpIconName As String) As Long
Declare Function CreateIcon Lib "user32" (ByVal hInstance As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal nPlanes As Byte, ByVal nBitsPixel As Byte, lpANDbits As Byte, lpXORbits As Byte) As Long
Declare Function DestroyIcon Lib "user32" (ByVal hIcon As Long) As Long
Declare Function LookupIconIdFromDirectory Lib "user32" (presbits As Byte, ByVal fIcon As Long) As Long
Declare Function CreateIconIndirect Lib "user32" (piconinfo As ICONINFO) As Long
Declare Function CopyIcon Lib "user32" (ByVal hIcon As Long) As Long
Declare Function GetIconInfo Lib "user32" (ByVal hIcon As Long, piconinfo As ICONINFO) As Long

' OEM Resource Ordinal Numbers
Public Const OBM_CLOSE = 32754
Public Const OBM_UPARROW = 32753
Public Const OBM_DNARROW = 32752
Public Const OBM_RGARROW = 32751
Public Const OBM_LFARROW = 32750
Public Const OBM_REDUCE = 32749
Public Const OBM_ZOOM = 32748
Public Const OBM_RESTORE = 32747
Public Const OBM_REDUCED = 32746
Public Const OBM_ZOOMD = 32745
Public Const OBM_RESTORED = 32744
Public Const OBM_UPARROWD = 32743
Public Const OBM_DNARROWD = 32742
Public Const OBM_RGARROWD = 32741
Public Const OBM_LFARROWD = 32740
Public Const OBM_MNARROW = 32739
Public Const OBM_COMBO = 32738
Public Const OBM_UPARROWI = 32737
Public Const OBM_DNARROWI = 32736
Public Const OBM_RGARROWI = 32735
Public Const OBM_LFARROWI = 32734

Public Const OBM_OLD_CLOSE = 32767
Public Const OBM_SIZE = 32766
Public Const OBM_OLD_UPARROW = 32765
Public Const OBM_OLD_DNARROW = 32764
Public Const OBM_OLD_RGARROW = 32763
Public Const OBM_OLD_LFARROW = 32762
Public Const OBM_BTSIZE = 32761
Public Const OBM_CHECK = 32760
Public Const OBM_CHECKBOXES = 32759
Public Const OBM_BTNCORNERS = 32758
Public Const OBM_OLD_REDUCE = 32757
Public Const OBM_OLD_ZOOM = 32756
Public Const OBM_OLD_RESTORE = 32755

Public Const OCR_NORMAL = 32512
Public Const OCR_IBEAM = 32513
Public Const OCR_WAIT = 32514
Public Const OCR_CROSS = 32515
Public Const OCR_UP = 32516
Public Const OCR_SIZE = 32640
Public Const OCR_ICON = 32641
Public Const OCR_SIZENWSE = 32642
Public Const OCR_SIZENESW = 32643
Public Const OCR_SIZEWE = 32644
Public Const OCR_SIZENS = 32645
Public Const OCR_SIZEALL = 32646
Public Const OCR_ICOCUR = 32647
Public Const OCR_NO = 32648 ' not in win3.1

Public Const OIC_SAMPLE = 32512
Public Const OIC_HAND = 32513
Public Const OIC_QUES = 32514
Public Const OIC_BANG = 32515
Public Const OIC_NOTE = 32516

Public Const ORD_LANGDRIVER = 1 '  The ordinal number for the entry point of
                                '  language drivers.

' Standard Icon IDs
Public Const IDI_APPLICATION = 32512&
Public Const IDI_HAND = 32513&
Public Const IDI_QUESTION = 32514&
Public Const IDI_EXCLAMATION = 32515&
Public Const IDI_ASTERISK = 32516&

Declare Function LoadString Lib "user32" Alias "LoadStringA" (ByVal hInstance As Long, ByVal wID As Long, ByVal lpBuffer As String, ByVal nBufferMax As Long) As Long

' Dialog Box Command IDs
Public Const IDOK = 1
Public Const IDCANCEL = 2
Public Const IDABORT = 3
Public Const IDRETRY = 4
Public Const IDIGNORE = 5
Public Const IDYES = 6
Public Const IDNO = 7

' Control Manager Structures and Definitions

' Edit Control Styles
Public Const ES_LEFT = &H0&
Public Const ES_CENTER = &H1&
Public Const ES_RIGHT = &H2&
Public Const ES_MULTILINE = &H4&
Public Const ES_UPPERCASE = &H8&
Public Const ES_LOWERCASE = &H10&
Public Const ES_PASSWORD = &H20&
Public Const ES_AUTOVSCROLL = &H40&
Public Const ES_AUTOHSCROLL = &H80&
Public Const ES_NOHIDESEL = &H100&
Public Const ES_OEMCONVERT = &H400&
Public Const ES_READONLY = &H800&
Public Const ES_WANTRETURN = &H1000&

' Edit Control Notification Codes
Public Const EN_SETFOCUS = &H100
Public Const EN_KILLFOCUS = &H200
Public Const EN_CHANGE = &H300
Public Const EN_UPDATE = &H400
Public Const EN_ERRSPACE = &H500
Public Const EN_MAXTEXT = &H501
Public Const EN_HSCROLL = &H601
Public Const EN_VSCROLL = &H602

' Edit Control Messages
Public Const EM_GETSEL = &HB0
Public Const EM_SETSEL = &HB1
Public Const EM_GETRECT = &HB2
Public Const EM_SETRECT = &HB3
Public Const EM_SETRECTNP = &HB4
Public Const EM_SCROLL = &HB5
Public Const EM_LINESCROLL = &HB6
Public Const EM_SCROLLCARET = &HB7
Public Const EM_GETMODIFY = &HB8
Public Const EM_SETMODIFY = &HB9
Public Const EM_GETLINECOUNT = &HBA
Public Const EM_LINEINDEX = &HBB
Public Const EM_SETHANDLE = &HBC
Public Const EM_GETHANDLE = &HBD
Public Const EM_GETTHUMB = &HBE
Public Const EM_LINELENGTH = &HC1
Public Const EM_REPLACESEL = &HC2
Public Const EM_GETLINE = &HC4
Public Const EM_LIMITTEXT = &HC5
Public Const EM_CANUNDO = &HC6
Public Const EM_UNDO = &HC7
Public Const EM_FMTLINES = &HC8
Public Const EM_LINEFROMCHAR = &HC9
Public Const EM_SETTABSTOPS = &HCB
Public Const EM_SETPASSWORDCHAR = &HCC
Public Const EM_EMPTYUNDOBUFFER = &HCD
Public Const EM_GETFIRSTVISIBLELINE = &HCE
Public Const EM_SETREADONLY = &HCF
Public Const EM_SETWORDBREAKPROC = &HD0
Public Const EM_GETWORDBREAKPROC = &HD1
Public Const EM_GETPASSWORDCHAR = &HD2

' EDITWORDBREAKPROC code values
Public Const WB_LEFT = 0
Public Const WB_RIGHT = 1
Public Const WB_ISDELIMITER = 2

' Button Control Styles
Public Const BS_PUSHBUTTON = &H0&
Public Const BS_DEFPUSHBUTTON = &H1&
Public Const BS_CHECKBOX = &H2&
Public Const BS_AUTOCHECKBOX = &H3&
Public Const BS_RADIOBUTTON = &H4&
Public Const BS_3STATE = &H5&
Public Const BS_AUTO3STATE = &H6&
Public Const BS_GROUPBOX = &H7&
Public Const BS_USERBUTTON = &H8&
Public Const BS_AUTORADIOBUTTON = &H9&
Public Const BS_OWNERDRAW = &HB&
Public Const BS_LEFTTEXT = &H20&

' User Button Notification Codes
Public Const BN_CLICKED = 0
Public Const BN_PAINT = 1
Public Const BN_HILITE = 2
Public Const BN_UNHILITE = 3
Public Const BN_DISABLE = 4
Public Const BN_DOUBLECLICKED = 5

' Button Control Messages
Public Const BM_GETCHECK = &HF0
Public Const BM_SETCHECK = &HF1
Public Const BM_GETSTATE = &HF2
Public Const BM_SETSTATE = &HF3
Public Const BM_SETSTYLE = &HF4

' Static Control Constants
Public Const SS_LEFT = &H0&
Public Const SS_CENTER = &H1&
Public Const SS_RIGHT = &H2&
Public Const SS_ICON = &H3&
Public Const SS_BLACKRECT = &H4&
Public Const SS_GRAYRECT = &H5&
Public Const SS_WHITERECT = &H6&
Public Const SS_BLACKFRAME = &H7&
Public Const SS_GRAYFRAME = &H8&
Public Const SS_WHITEFRAME = &H9&
Public Const SS_USERITEM = &HA&
Public Const SS_SIMPLE = &HB&
Public Const SS_LEFTNOWORDWRAP = &HC&
Public Const SS_NOPREFIX = &H80           '  Don't do "&" character translation

' Static Control Mesages
Public Const STM_SETICON = &H170
Public Const STM_GETICON = &H171
Public Const STM_MSGMAX = &H172

Public Const WC_DIALOG = 8002&

'  Get/SetWindowWord/Long offsets for use with WC_DIALOG windows
Public Const DWL_MSGRESULT = 0
Public Const DWL_DLGPROC = 4
Public Const DWL_USER = 8

' Dialog Manager Routines
Declare Function IsDialogMessage Lib "user32" Alias "IsDialogMessageA" (ByVal hDlg As Long, lpMsg As Msg) As Long
Declare Function MapDialogRect Lib "user32" (ByVal hDlg As Long, lpRect As RECT) As Long
Declare Function DlgDirList Lib "user32" Alias "DlgDirListA" (ByVal hDlg As Long, ByVal lpPathSpec As String, ByVal nIDListBox As Long, ByVal nIDStaticPath As Long, ByVal wFileType As Long) As Long

' DlgDirList, DlgDirListComboBox flags values
Public Const DDL_READWRITE = &H0
Public Const DDL_READONLY = &H1
Public Const DDL_HIDDEN = &H2
Public Const DDL_SYSTEM = &H4
Public Const DDL_DIRECTORY = &H10
Public Const DDL_ARCHIVE = &H20

Public Const DDL_POSTMSGS = &H2000
Public Const DDL_DRIVES = &H4000
Public Const DDL_EXCLUSIVE = &H8000

Declare Function DlgDirSelectEx Lib "user32" Alias "DlgDirSelectExA" (ByVal hWndDlg As Long, ByVal lpszPath As String, ByVal cbPath As Long, ByVal idListBox As Long) As Long
Declare Function DlgDirListComboBox Lib "user32" Alias "DlgDirListComboBoxA" (ByVal hDlg As Long, ByVal lpPathSpec As String, ByVal nIDComboBox As Long, ByVal nIDStaticPath As Long, ByVal wFileType As Long) As Long
Declare Function DlgDirSelectComboBoxEx Lib "user32" Alias "DlgDirSelectComboBoxExA" (ByVal hWndDlg As Long, ByVal lpszPath As String, ByVal cbPath As Long, ByVal idComboBox As Long) As Long

' Dialog Styles
Public Const DS_ABSALIGN = &H1&
Public Const DS_SYSMODAL = &H2&
Public Const DS_LOCALEDIT = &H20          '  Edit items get Local storage.
Public Const DS_SETFONT = &H40            '  User specified font for Dlg controls
Public Const DS_MODALFRAME = &H80         '  Can be combined with WS_CAPTION
Public Const DS_NOIDLEMSG = &H100         '  WM_ENTERIDLE message will not be sent
Public Const DS_SETFOREGROUND = &H200     '  not in win3.1

Public Const DM_GETDEFID = WM_USER + 0
Public Const DM_SETDEFID = WM_USER + 1
Public Const DC_HASDEFID = &H534      '0x534B

' Dialog Codes
Public Const DLGC_WANTARROWS = &H1              '  Control wants arrow keys
Public Const DLGC_WANTTAB = &H2                 '  Control wants tab keys
Public Const DLGC_WANTALLKEYS = &H4             '  Control wants all keys
Public Const DLGC_WANTMESSAGE = &H4             '  Pass message to control
Public Const DLGC_HASSETSEL = &H8               '  Understands EM_SETSEL message
Public Const DLGC_DEFPUSHBUTTON = &H10          '  Default pushbutton
Public Const DLGC_UNDEFPUSHBUTTON = &H20        '  Non-default pushbutton
Public Const DLGC_RADIOBUTTON = &H40            '  Radio button
Public Const DLGC_WANTCHARS = &H80              '  Want WM_CHAR messages
Public Const DLGC_STATIC = &H100                '  Static item: don't include
Public Const DLGC_BUTTON = &H2000               '  Button item: can be checked

Public Const LB_CTLCODE = 0&

' Listbox Return Values
Public Const LB_OKAY = 0
Public Const LB_ERR = (-1)
Public Const LB_ERRSPACE = (-2)

' The idStaticPath parameter to DlgDirList can have the following values
' ORed if the list box should show other details of the files along with
' the name of the files;
' all other details also will be returned

' Listbox Notification Codes
Public Const LBN_ERRSPACE = (-2)
Public Const LBN_SELCHANGE = 1
Public Const LBN_DBLCLK = 2
Public Const LBN_SELCANCEL = 3
Public Const LBN_SETFOCUS = 4
Public Const LBN_KILLFOCUS = 5

' Listbox messages
Public Const LB_ADDSTRING = &H180
Public Const LB_INSERTSTRING = &H181
Public Const LB_DELETESTRING = &H182
Public Const LB_SELITEMRANGEEX = &H183
Public Const LB_RESETCONTENT = &H184
Public Const LB_SETSEL = &H185
Public Const LB_SETCURSEL = &H186
Public Const LB_GETSEL = &H187
Public Const LB_GETCURSEL = &H188
Public Const LB_GETTEXT = &H189
Public Const LB_GETTEXTLEN = &H18A
Public Const LB_GETCOUNT = &H18B
Public Const LB_SELECTSTRING = &H18C
Public Const LB_DIR = &H18D
Public Const LB_GETTOPINDEX = &H18E
Public Const LB_FINDSTRING = &H18F
Public Const LB_GETSELCOUNT = &H190
Public Const LB_GETSELITEMS = &H191
Public Const LB_SETTABSTOPS = &H192
Public Const LB_GETHORIZONTALEXTENT = &H193
Public Const LB_SETHORIZONTALEXTENT = &H194
Public Const LB_SETCOLUMNWIDTH = &H195
Public Const LB_ADDFILE = &H196
Public Const LB_SETTOPINDEX = &H197
Public Const LB_GETITEMRECT = &H198
Public Const LB_GETITEMDATA = &H199
Public Const LB_SETITEMDATA = &H19A
Public Const LB_SELITEMRANGE = &H19B
Public Const LB_SETANCHORINDEX = &H19C
Public Const LB_GETANCHORINDEX = &H19D
Public Const LB_SETCARETINDEX = &H19E
Public Const LB_GETCARETINDEX = &H19F
Public Const LB_SETITEMHEIGHT = &H1A0
Public Const LB_GETITEMHEIGHT = &H1A1
Public Const LB_FINDSTRINGEXACT = &H1A2
Public Const LB_SETLOCALE = &H1A5
Public Const LB_GETLOCALE = &H1A6
Public Const LB_SETCOUNT = &H1A7
Public Const LB_MSGMAX = &H1A8

' Listbox Styles
Public Const LBS_NOTIFY = &H1&
Public Const LBS_SORT = &H2&
Public Const LBS_NOREDRAW = &H4&
Public Const LBS_MULTIPLESEL = &H8&
Public Const LBS_OWNERDRAWFIXED = &H10&
Public Const LBS_OWNERDRAWVARIABLE = &H20&
Public Const LBS_HASSTRINGS = &H40&
Public Const LBS_USETABSTOPS = &H80&
Public Const LBS_NOINTEGRALHEIGHT = &H100&
Public Const LBS_MULTICOLUMN = &H200&
Public Const LBS_WANTKEYBOARDINPUT = &H400&
Public Const LBS_EXTENDEDSEL = &H800&
Public Const LBS_DISABLENOSCROLL = &H1000&
Public Const LBS_NODATA = &H2000&
Public Const LBS_STANDARD = (LBS_NOTIFY Or LBS_SORT Or WS_VSCROLL Or WS_BORDER)

' Combo Box return Values
Public Const CB_OKAY = 0
Public Const CB_ERR = (-1)
Public Const CB_ERRSPACE = (-2)

' Combo Box Notification Codes
Public Const CBN_ERRSPACE = (-1)
Public Const CBN_SELCHANGE = 1
Public Const CBN_DBLCLK = 2
Public Const CBN_SETFOCUS = 3
Public Const CBN_KILLFOCUS = 4
Public Const CBN_EDITCHANGE = 5
Public Const CBN_EDITUPDATE = 6
Public Const CBN_DROPDOWN = 7
Public Const CBN_CLOSEUP = 8
Public Const CBN_SELENDOK = 9
Public Const CBN_SELENDCANCEL = 10

' Combo Box styles
Public Const CBS_SIMPLE = &H1&
Public Const CBS_DROPDOWN = &H2&
Public Const CBS_DROPDOWNLIST = &H3&
Public Const CBS_OWNERDRAWFIXED = &H10&
Public Const CBS_OWNERDRAWVARIABLE = &H20&
Public Const CBS_AUTOHSCROLL = &H40&
Public Const CBS_OEMCONVERT = &H80&
Public Const CBS_SORT = &H100&
Public Const CBS_HASSTRINGS = &H200&
Public Const CBS_NOINTEGRALHEIGHT = &H400&
Public Const CBS_DISABLENOSCROLL = &H800&

' Combo Box messages
Public Const CB_GETEDITSEL = &H140
Public Const CB_LIMITTEXT = &H141
Public Const CB_SETEDITSEL = &H142
Public Const CB_ADDSTRING = &H143
Public Const CB_DELETESTRING = &H144
Public Const CB_DIR = &H145
Public Const CB_GETCOUNT = &H146
Public Const CB_GETCURSEL = &H147
Public Const CB_GETLBTEXT = &H148
Public Const CB_GETLBTEXTLEN = &H149
Public Const CB_INSERTSTRING = &H14A
Public Const CB_RESETCONTENT = &H14B
Public Const CB_FINDSTRING = &H14C
Public Const CB_SELECTSTRING = &H14D
Public Const CB_SETCURSEL = &H14E
Public Const CB_SHOWDROPDOWN = &H14F
Public Const CB_GETITEMDATA = &H150
Public Const CB_SETITEMDATA = &H151
Public Const CB_GETDROPPEDCONTROLRECT = &H152
Public Const CB_SETITEMHEIGHT = &H153
Public Const CB_GETITEMHEIGHT = &H154
Public Const CB_SETEXTENDEDUI = &H155
Public Const CB_GETEXTENDEDUI = &H156
Public Const CB_GETDROPPEDSTATE = &H157
Public Const CB_FINDSTRINGEXACT = &H158
Public Const CB_SETLOCALE = &H159
Public Const CB_GETLOCALE = &H15A
Public Const CB_MSGMAX = &H15B

' Scroll Bar Styles
Public Const SBS_HORZ = &H0&
Public Const SBS_VERT = &H1&
Public Const SBS_TOPALIGN = &H2&
Public Const SBS_LEFTALIGN = &H2&
Public Const SBS_BOTTOMALIGN = &H4&
Public Const SBS_RIGHTALIGN = &H4&
Public Const SBS_SIZEBOXTOPLEFTALIGN = &H2&
Public Const SBS_SIZEBOXBOTTOMRIGHTALIGN = &H4&
Public Const SBS_SIZEBOX = &H8&

'  Scroll bar messages
Public Const SBM_SETPOS = &HE0 ' not in win3.1
Public Const SBM_GETPOS = &HE1 ' not in win3.1
Public Const SBM_SETRANGE = &HE2 ' not in win3.1
Public Const SBM_SETRANGEREDRAW = &HE6 ' not in win3.1
Public Const SBM_GETRANGE = &HE3 ' not in win3.1
Public Const SBM_ENABLE_ARROWS = &HE4 ' not in win3.1

Public Const MDIS_ALLCHILDSTYLES = &H1

' wParam values for WM_MDITILE and WM_MDICASCADE messages.
Public Const MDITILE_VERTICAL = &H0
Public Const MDITILE_HORIZONTAL = &H1
Public Const MDITILE_SKIPDISABLED = &H2

Type MDICREATESTRUCT
        szClass As String
        szTitle As String
        hOwner As Long
        X As Long
        Y As Long
        cx As Long
        cy As Long
        style As Long
        lParam As Long
End Type

Type CLIENTCREATESTRUCT
        hWindowMenu As Long
        idFirstChild As Long
End Type

Declare Function DefFrameProc Lib "user32" Alias "DefFrameProcA" (ByVal hWnd As Long, ByVal hWndMDIClient As Long, ByVal wMsg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Declare Function DefMDIChildProc Lib "user32" Alias "DefMDIChildProcA" (ByVal hWnd As Long, ByVal wMsg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long

Declare Function TranslateMDISysAccel Lib "user32" (ByVal hWndClient As Long, lpMsg As Msg) As Long

Declare Function ArrangeIconicWindows Lib "user32" (ByVal hWnd As Long) As Long

Declare Function CreateMDIWindow Lib "user32" Alias "CreateMDIWindowA" (ByVal lpClassName As String, ByVal lpWindowName As String, ByVal dwStyle As Long, ByVal X As Long, ByVal Y As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hwndParent As Long, ByVal hInstance As Long, ByVal lParam As Long) As Long

'  Help engine section.

Type MULTIKEYHELP
        mkSize As Long
        mkKeylist As Byte
        szKeyphrase As String * 253 ' Array length is arbitrary; may be changed
End Type

Type HELPWININFO
        wStructSize As Long
        X As Long
        Y As Long
        dx As Long
        dy As Long
        wMax As Long
        rgchMember As String * 2
End Type

' Commands to pass WinHelp()
Public Const HELP_CONTEXT = &H1          '  Display topic in ulTopic
Public Const HELP_QUIT = &H2             '  Terminate help
Public Const HELP_INDEX = &H3            '  Display index
Public Const HELP_CONTENTS = &H3&
Public Const HELP_HELPONHELP = &H4       '  Display help on using help
Public Const HELP_SETINDEX = &H5         '  Set current Index for multi index help
Public Const HELP_SETCONTENTS = &H5&
Public Const HELP_CONTEXTPOPUP = &H8&
Public Const HELP_FORCEFILE = &H9&
Public Const HELP_KEY = &H101            '  Display topic for keyword in offabData
Public Const HELP_COMMAND = &H102&
Public Const HELP_PARTIALKEY = &H105&
Public Const HELP_MULTIKEY = &H201&
Public Const HELP_SETWINPOS = &H203&

Declare Function WinHelp Lib "user32" Alias "WinHelpA" (ByVal hWnd As Long, ByVal lpHelpFile As String, ByVal wCommand As Long, ByVal dwData As Long) As Long

' Parameter for SystemParametersInfo()
Public Const SPI_GETBEEP = 1
Public Const SPI_SETBEEP = 2
Public Const SPI_GETMOUSE = 3
Public Const SPI_SETMOUSE = 4
Public Const SPI_GETBORDER = 5
Public Const SPI_SETBORDER = 6
Public Const SPI_GETKEYBOARDSPEED = 10
Public Const SPI_SETKEYBOARDSPEED = 11
Public Const SPI_LANGDRIVER = 12
Public Const SPI_ICONHORIZONTALSPACING = 13
Public Const SPI_GETSCREENSAVETIMEOUT = 14
Public Const SPI_SETSCREENSAVETIMEOUT = 15
Public Const SPI_GETSCREENSAVEACTIVE = 16
Public Const SPI_SETSCREENSAVEACTIVE = 17
Public Const SPI_GETGRIDGRANULARITY = 18
Public Const SPI_SETGRIDGRANULARITY = 19
Public Const SPI_SETDESKWALLPAPER = 20
Public Const SPI_SETDESKPATTERN = 21
Public Const SPI_GETKEYBOARDDELAY = 22
Public Const SPI_SETKEYBOARDDELAY = 23
Public Const SPI_ICONVERTICALSPACING = 24
Public Const SPI_GETICONTITLEWRAP = 25
Public Const SPI_SETICONTITLEWRAP = 26
Public Const SPI_GETMENUDROPALIGNMENT = 27
Public Const SPI_SETMENUDROPALIGNMENT = 28
Public Const SPI_SETDOUBLECLKWIDTH = 29
Public Const SPI_SETDOUBLECLKHEIGHT = 30
Public Const SPI_GETICONTITLELOGFONT = 31
Public Const SPI_SETDOUBLECLICKTIME = 32
Public Const SPI_SETMOUSEBUTTONSWAP = 33
Public Const SPI_SETICONTITLELOGFONT = 34
Public Const SPI_GETFASTTASKSWITCH = 35
Public Const SPI_SETFASTTASKSWITCH = 36
Public Const SPI_SETDRAGFULLWINDOWS = 37
Public Const SPI_GETDRAGFULLWINDOWS = 38
Public Const SPI_GETNONCLIENTMETRICS = 41
Public Const SPI_SETNONCLIENTMETRICS = 42
Public Const SPI_GETMINIMIZEDMETRICS = 43
Public Const SPI_SETMINIMIZEDMETRICS = 44
Public Const SPI_GETICONMETRICS = 45
Public Const SPI_SETICONMETRICS = 46
Public Const SPI_SETWORKAREA = 47
Public Const SPI_GETWORKAREA = 48
Public Const SPI_SETPENWINDOWS = 49
Public Const SPI_GETFILTERKEYS = 50
Public Const SPI_SETFILTERKEYS = 51
Public Const SPI_GETTOGGLEKEYS = 52
Public Const SPI_SETTOGGLEKEYS = 53
Public Const SPI_GETMOUSEKEYS = 54
Public Const SPI_SETMOUSEKEYS = 55
Public Const SPI_GETSHOWSOUNDS = 56
Public Const SPI_SETSHOWSOUNDS = 57
Public Const SPI_GETSTICKYKEYS = 58
Public Const SPI_SETSTICKYKEYS = 59
Public Const SPI_GETACCESSTIMEOUT = 60
Public Const SPI_SETACCESSTIMEOUT = 61
Public Const SPI_GETSERIALKEYS = 62
Public Const SPI_SETSERIALKEYS = 63
Public Const SPI_GETSOUNDSENTRY = 64
Public Const SPI_SETSOUNDSENTRY = 65
Public Const SPI_GETHIGHCONTRAST = 66
Public Const SPI_SETHIGHCONTRAST = 67
Public Const SPI_GETKEYBOARDPREF = 68
Public Const SPI_SETKEYBOARDPREF = 69
Public Const SPI_GETSCREENREADER = 70
Public Const SPI_SETSCREENREADER = 71
Public Const SPI_GETANIMATION = 72
Public Const SPI_SETANIMATION = 73
Public Const SPI_GETFONTSMOOTHING = 74
Public Const SPI_SETFONTSMOOTHING = 75
Public Const SPI_SETDRAGWIDTH = 76
Public Const SPI_SETDRAGHEIGHT = 77
Public Const SPI_SETHANDHELD = 78
Public Const SPI_GETLOWPOWERTIMEOUT = 79
Public Const SPI_GETPOWEROFFTIMEOUT = 80
Public Const SPI_SETLOWPOWERTIMEOUT = 81
Public Const SPI_SETPOWEROFFTIMEOUT = 82
Public Const SPI_GETLOWPOWERACTIVE = 83
Public Const SPI_GETPOWEROFFACTIVE = 84
Public Const SPI_SETLOWPOWERACTIVE = 85
Public Const SPI_SETPOWEROFFACTIVE = 86
Public Const SPI_SETCURSORS = 87
Public Const SPI_SETICONS = 88
Public Const SPI_GETDEFAULTINPUTLANG = 89
Public Const SPI_SETDEFAULTINPUTLANG = 90
Public Const SPI_SETLANGTOGGLE = 91
Public Const SPI_GETWINDOWSEXTENSION = 92
Public Const SPI_SETMOUSETRAILS = 93
Public Const SPI_GETMOUSETRAILS = 94
Public Const SPI_SCREENSAVERRUNNING = 97

' SystemParametersInfo flags
Public Const SPIF_UPDATEINIFILE = &H1
Public Const SPIF_SENDWININICHANGE = &H2

Declare Function SystemParametersInfo Lib "user32" Alias "SystemParametersInfoA" (ByVal uAction As Long, ByVal uParam As Long, ByRef lpvParam As Any, ByVal fuWinIni As Long) As Long

'  DDE window messages
Public Const WM_DDE_FIRST = &H3E0
Public Const WM_DDE_INITIATE = (WM_DDE_FIRST)
Public Const WM_DDE_TERMINATE = (WM_DDE_FIRST + 1)
Public Const WM_DDE_ADVISE = (WM_DDE_FIRST + 2)
Public Const WM_DDE_UNADVISE = (WM_DDE_FIRST + 3)
Public Const WM_DDE_ACK = (WM_DDE_FIRST + 4)
Public Const WM_DDE_DATA = (WM_DDE_FIRST + 5)
Public Const WM_DDE_REQUEST = (WM_DDE_FIRST + 6)
Public Const WM_DDE_POKE = (WM_DDE_FIRST + 7)
Public Const WM_DDE_EXECUTE = (WM_DDE_FIRST + 8)
Public Const WM_DDE_LAST = (WM_DDE_FIRST + 8)

' *****************************************************************************                                                                             *
' * dde.h -       Dynamic Data Exchange structures and definitions              *
' *                                                                             *
' * Copyright (c) 1993-1995, Microsoft Corp.        All rights reserved              *
' *                                                                             *
' \*****************************************************************************/


' ----------------------------------------------------------------------------
'        DDEACK structure
'
'         Structure of wStatus (LOWORD(lParam)) in WM_DDE_ACK message
'        sent in response to a WM_DDE_DATA, WM_DDE_REQUEST, WM_DDE_POKE,
'        WM_DDE_ADVISE, or WM_DDE_UNADVISE message.
'
' ----------------------------------------------------------------------------*/

Type DDEACK
        bAppReturnCode As Integer
        Reserved As Integer
        fbusy As Integer
        fAck As Integer
End Type

' ----------------------------------------------------------------------------
'        DDEADVISE structure
'
'         WM_DDE_ADVISE parameter structure for hOptions (LOWORD(lParam))
'
' ----------------------------------------------------------------------------*/

Type DDEADVISE
        Reserved As Integer
        fDeferUpd As Integer
        fAckReq As Integer
        cfFormat As Integer
End Type


' ----------------------------------------------------------------------------
'        DDEDATA structure
'
'        WM_DDE_DATA parameter structure for hData (LOWORD(lParam)).
'        The actual size of this structure depends on the size of
'        the Value array.
'
' ----------------------------------------------------------------------------*/

Type DDEDATA
        unused As Integer
        fresponse As Integer
        fRelease As Integer
        Reserved As Integer
        fAckReq As Integer
        cfFormat As Integer
        Value(1) As Byte
End Type


' ----------------------------------------------------------------------------
'         DDEPOKE structure
'
'         WM_DDE_POKE parameter structure for hData (LOWORD(lParam)).
'        The actual size of this structure depends on the size of
'        the Value array.
'
' ----------------------------------------------------------------------------*/

Type DDEPOKE
        unused As Integer
        fRelease As Integer
        fReserved As Integer
        cfFormat As Integer
        Value(1) As Byte
End Type

' ----------------------------------------------------------------------------
' The following typedef's were used in previous versions of the Windows SDK.
' They are still valid.  The above typedef's define exactly the same structures
' as those below.  The above typedef names are recommended, however, as they
' are more meaningful.

' Note that the DDEPOKE structure typedef'ed in earlier versions of DDE.H did
' not correctly define the bit positions.
' ----------------------------------------------------------------------------*/

Type DDELN
        unused As Integer
        fRelease As Integer
        fDeferUpd As Integer
        fAckReq As Integer
        cfFormat As Integer
End Type

Type DDEUP
        unused As Integer
        fAck As Integer
        fRelease As Integer
        fReserved As Integer
        fAckReq As Integer
        cfFormat As Integer
        rgb(1) As Byte
End Type

Declare Function DdeSetQualityOfService Lib "user32" (ByVal hWndClient As Long, pqosNew As SECURITY_QUALITY_OF_SERVICE, pqosPrev As SECURITY_QUALITY_OF_SERVICE) As Long
Declare Function ImpersonateDdeClientWindow Lib "user32" (ByVal hWndClient As Long, ByVal hWndServer As Long) As Long
Declare Function PackDDElParam Lib "user32" (ByVal Msg As Long, ByVal uiLo As Long, ByVal uiHi As Long) As Long
Declare Function UnpackDDElParam Lib "user32" (ByVal Msg As Long, ByVal lParam As Long, puiLo As Long, puiHi As Long) As Long
Declare Function FreeDDElParam Lib "user32" (ByVal Msg As Long, ByVal lParam As Long) As Long
Declare Function ReuseDDElParam Lib "user32" (ByVal lParam As Long, ByVal msgIn As Long, ByVal msgOut As Long, ByVal uiLo As Long, ByVal uiHi As Long) As Long

Type HSZPAIR
        hszSvc As Long
        hszTopic As Long
End Type

'//
'// Quality Of Service
'//

Type SECURITY_QUALITY_OF_SERVICE
    Length As Long
    Impersonationlevel As Integer
    ContextTrackingMode As Integer
    EffectiveOnly As Long
End Type

Type CONVCONTEXT
        cb As Long
        wFlags As Long
        wCountryID As Long
        iCodePage As Long
        dwLangID As Long
        dwSecurity As Long
        qos As SECURITY_QUALITY_OF_SERVICE
End Type

Type CONVINFO
        cb As Long
        hUser As Long
        hConvPartner As Long
        hszSvcPartner As Long
        hszServiceReq As Long
        hszTopic As Long
        hszItem As Long
        wFmt As Long
        wType As Long
        wStatus As Long
        wConvst As Long
        wLastError As Long
        hConvList As Long
        ConvCtxt As CONVCONTEXT
        hWnd As Long
        hwndPartner As Long
End Type

'  conversation states (usState)
Public Const XST_NULL = 0  '  quiescent states
Public Const XST_INCOMPLETE = 1
Public Const XST_CONNECTED = 2
Public Const XST_INIT1 = 3  '  mid-initiation states
Public Const XST_INIT2 = 4
Public Const XST_REQSENT = 5  '  active conversation states
Public Const XST_DATARCVD = 6
Public Const XST_POKESENT = 7
Public Const XST_POKEACKRCVD = 8
Public Const XST_EXECSENT = 9
Public Const XST_EXECACKRCVD = 10
Public Const XST_ADVSENT = 11
Public Const XST_UNADVSENT = 12
Public Const XST_ADVACKRCVD = 13
Public Const XST_UNADVACKRCVD = 14
Public Const XST_ADVDATASENT = 15
Public Const XST_ADVDATAACKRCVD = 16

'  used in LOWORD(dwData1) of XTYP_ADVREQ callbacks...
Public Const CADV_LATEACK = &HFFFF

'  conversation status bits (fsStatus)
Public Const ST_CONNECTED = &H1
Public Const ST_ADVISE = &H2
Public Const ST_ISLOCAL = &H4
Public Const ST_BLOCKED = &H8
Public Const ST_CLIENT = &H10
Public Const ST_TERMINATED = &H20
Public Const ST_INLIST = &H40
Public Const ST_BLOCKNEXT = &H80
Public Const ST_ISSELF = &H100

'  DDE constants for wStatus field
Public Const DDE_FACK = &H8000
Public Const DDE_FBUSY = &H4000
Public Const DDE_FDEFERUPD = &H4000
Public Const DDE_FACKREQ = &H8000
Public Const DDE_FRELEASE = &H2000
Public Const DDE_FREQUESTED = &H1000
Public Const DDE_FAPPSTATUS = &HFF
Public Const DDE_FNOTPROCESSED = &H0

Public Const DDE_FACKRESERVED = (Not (DDE_FACK Or DDE_FBUSY Or DDE_FAPPSTATUS))
Public Const DDE_FADVRESERVED = (Not (DDE_FACKREQ Or DDE_FDEFERUPD))
Public Const DDE_FDATRESERVED = (Not (DDE_FACKREQ Or DDE_FRELEASE Or DDE_FREQUESTED))
Public Const DDE_FPOKRESERVED = (Not (DDE_FRELEASE))

'  message filter hook types
Public Const MSGF_DDEMGR = &H8001

'  codepage constants
Public Const CP_WINANSI = 1004  '  default codepage for windows old DDE convs.
Public Const CP_WINUNICODE = 1200

'  transaction types
Public Const XTYPF_NOBLOCK = &H2     '  CBR_BLOCK will not work
Public Const XTYPF_NODATA = &H4     '  DDE_FDEFERUPD
Public Const XTYPF_ACKREQ = &H8     '  DDE_FACKREQ

Public Const XCLASS_MASK = &HFC00
Public Const XCLASS_BOOL = &H1000
Public Const XCLASS_DATA = &H2000
Public Const XCLASS_FLAGS = &H4000
Public Const XCLASS_NOTIFICATION = &H8000

Public Const XTYP_ERROR = (&H0 Or XCLASS_NOTIFICATION Or XTYPF_NOBLOCK)
Public Const XTYP_ADVDATA = (&H10 Or XCLASS_FLAGS)
Public Const XTYP_ADVREQ = (&H20 Or XCLASS_DATA Or XTYPF_NOBLOCK)
Public Const XTYP_ADVSTART = (&H30 Or XCLASS_BOOL)
Public Const XTYP_ADVSTOP = (&H40 Or XCLASS_NOTIFICATION)
Public Const XTYP_EXECUTE = (&H50 Or XCLASS_FLAGS)
Public Const XTYP_CONNECT = (&H60 Or XCLASS_BOOL Or XTYPF_NOBLOCK)
Public Const XTYP_CONNECT_CONFIRM = (&H70 Or XCLASS_NOTIFICATION Or XTYPF_NOBLOCK)
Public Const XTYP_XACT_COMPLETE = (&H80 Or XCLASS_NOTIFICATION)
Public Const XTYP_POKE = (&H90 Or XCLASS_FLAGS)
Public Const XTYP_REGISTER = (&HA0 Or XCLASS_NOTIFICATION Or XTYPF_NOBLOCK)
Public Const XTYP_REQUEST = (&HB0 Or XCLASS_DATA)
Public Const XTYP_DISCONNECT = (&HC0 Or XCLASS_NOTIFICATION Or XTYPF_NOBLOCK)
Public Const XTYP_UNREGISTER = (&HD0 Or XCLASS_NOTIFICATION Or XTYPF_NOBLOCK)
Public Const XTYP_WILDCONNECT = (&HE0 Or XCLASS_DATA Or XTYPF_NOBLOCK)

Public Const XTYP_MASK = &HF0
Public Const XTYP_SHIFT = 4  '  shift to turn XTYP_ into an index

'  Timeout constants
Public Const TIMEOUT_ASYNC = &HFFFF

'  Transaction ID constants
Public Const QID_SYNC = &HFFFF

' Public strings used in DDE
Public Const SZDDESYS_TOPIC = "System"
Public Const SZDDESYS_ITEM_TOPICS = "Topics"
Public Const SZDDESYS_ITEM_SYSITEMS = "SysItems"
Public Const SZDDESYS_ITEM_RTNMSG = "ReturnMessage"
Public Const SZDDESYS_ITEM_STATUS = "Status"
Public Const SZDDESYS_ITEM_FORMATS = "Formats"
Public Const SZDDESYS_ITEM_HELP = "Help"
Public Const SZDDE_ITEM_ITEMLIST = "TopicItemList"

Public Const CBR_BLOCK = &HFFFF

' Callback filter flags for use with standard apps.
Public Const CBF_FAIL_SELFCONNECTIONS = &H1000
Public Const CBF_FAIL_CONNECTIONS = &H2000
Public Const CBF_FAIL_ADVISES = &H4000
Public Const CBF_FAIL_EXECUTES = &H8000
Public Const CBF_FAIL_POKES = &H10000
Public Const CBF_FAIL_REQUESTS = &H20000
Public Const CBF_FAIL_ALLSVRXACTIONS = &H3F000

Public Const CBF_SKIP_CONNECT_CONFIRMS = &H40000
Public Const CBF_SKIP_REGISTRATIONS = &H80000
Public Const CBF_SKIP_UNREGISTRATIONS = &H100000
Public Const CBF_SKIP_DISCONNECTS = &H200000
Public Const CBF_SKIP_ALLNOTIFICATIONS = &H3C0000

' Application command flags
Public Const APPCMD_CLIENTONLY = &H10&
Public Const APPCMD_FILTERINITS = &H20&
Public Const APPCMD_MASK = &HFF0&

' Application classification flags
Public Const APPCLASS_STANDARD = &H0&
Public Const APPCLASS_MASK = &HF&

Declare Function DdeUninitialize Lib "user32" (ByVal idInst As Long) As Long

' conversation enumeration functions
Declare Function DdeConnectList Lib "user32" (ByVal idInst As Long, ByVal hszService As Long, ByVal hszTopic As Long, ByVal hConvList As Long, pCC As CONVCONTEXT) As Long
Declare Function DdeQueryNextServer Lib "user32" (ByVal hConvList As Long, ByVal hConvPrev As Long) As Long
Declare Function DdeDisconnectList Lib "user32" (ByVal hConvList As Long) As Long

' conversation control functions
Declare Function DdeConnect Lib "user32" (ByVal idInst As Long, ByVal hszService As Long, ByVal hszTopic As Long, pCC As CONVCONTEXT) As Long
Declare Function DdeDisconnect Lib "user32" (ByVal hConv As Long) As Long
Declare Function DdeReconnect Lib "user32" (ByVal hConv As Long) As Long
Declare Function DdeQueryConvInfo Lib "user32" (ByVal hConv As Long, ByVal idTransaction As Long, pConvInfo As CONVINFO) As Long
Declare Function DdeSetUserHandle Lib "user32" (ByVal hConv As Long, ByVal id As Long, ByVal hUser As Long) As Long
Declare Function DdeAbandonTransaction Lib "user32" (ByVal idInst As Long, ByVal hConv As Long, ByVal idTransaction As Long) As Long

' app server interface functions
Declare Function DdePostAdvise Lib "user32" (ByVal idInst As Long, ByVal hszTopic As Long, ByVal hszItem As Long) As Long
Declare Function DdeEnableCallback Lib "user32" (ByVal idInst As Long, ByVal hConv As Long, ByVal wCmd As Long) As Long
Declare Function DdeImpersonateClient Lib "user32" (ByVal hConv As Long) As Long

Public Const EC_ENABLEALL = 0
Public Const EC_ENABLEONE = ST_BLOCKNEXT
Public Const EC_DISABLE = ST_BLOCKED
Public Const EC_QUERYWAITING = 2

Declare Function DdeNameService Lib "user32" (ByVal idInst As Long, ByVal hsz1 As Long, ByVal hsz2 As Long, ByVal afCmd As Long) As Long

Public Const DNS_REGISTER = &H1
Public Const DNS_UNREGISTER = &H2
Public Const DNS_FILTERON = &H4
Public Const DNS_FILTEROFF = &H8

' app client interface functions
Declare Function DdeClientTransaction Lib "user32" (pData As Byte, ByVal cbData As Long, ByVal hConv As Long, ByVal hszItem As Long, ByVal wFmt As Long, ByVal wType As Long, ByVal dwTimeout As Long, pdwResult As Long) As Long

' data transfer functions
Declare Function DdeCreateDataHandle Lib "user32" (ByVal idInst As Long, pSrc As Byte, ByVal cb As Long, ByVal cbOff As Long, ByVal hszItem As Long, ByVal wFmt As Long, ByVal afCmd As Long) As Long
Declare Function DdeAddData Lib "user32" Alias "DdeAddDataA" (ByVal hData As Long, pSrc As Byte, ByVal cb As Long, ByVal cbOff As Long) As Long
Declare Function DdeGetData Lib "user32" Alias "DdeGetDataA" (ByVal hData As Long, pDst As Byte, ByVal cbMax As Long, ByVal cbOff As Long) As Long
Declare Function DdeAccessData Lib "user32" Alias "DdeAccessDataA" (ByVal hData As Long, pcbDataSize As Long) As Long
Declare Function DdeUnaccessData Lib "user32" Alias "DdeUnaccessDataA" (ByVal hData As Long) As Long
Declare Function DdeFreeDataHandle Lib "user32" (ByVal hData As Long) As Long

Public Const HDATA_APPOWNED = &H1

Declare Function DdeGetLastError Lib "user32" (ByVal idInst As Long) As Long

Public Const DMLERR_NO_ERROR = 0                           '  must be 0

Public Const DMLERR_FIRST = &H4000

Public Const DMLERR_ADVACKTIMEOUT = &H4000
Public Const DMLERR_BUSY = &H4001
Public Const DMLERR_DATAACKTIMEOUT = &H4002
Public Const DMLERR_DLL_NOT_INITIALIZED = &H4003
Public Const DMLERR_DLL_USAGE = &H4004
Public Const DMLERR_EXECACKTIMEOUT = &H4005
Public Const DMLERR_INVALIDPARAMETER = &H4006
Public Const DMLERR_LOW_MEMORY = &H4007
Public Const DMLERR_MEMORY_ERROR = &H4008
Public Const DMLERR_NOTPROCESSED = &H4009
Public Const DMLERR_NO_CONV_ESTABLISHED = &H400A
Public Const DMLERR_POKEACKTIMEOUT = &H400B
Public Const DMLERR_POSTMSG_FAILED = &H400C
Public Const DMLERR_REENTRANCY = &H400D
Public Const DMLERR_SERVER_DIED = &H400E
Public Const DMLERR_SYS_ERROR = &H400F
Public Const DMLERR_UNADVACKTIMEOUT = &H4010
Public Const DMLERR_UNFOUND_QUEUE_ID = &H4011

Public Const DMLERR_LAST = &H4011

Declare Function DdeCreateStringHandle Lib "user32" Alias "DdeCreateStringHandleA" (ByVal idInst As Long, ByVal psz As String, ByVal iCodePage As Long) As Long

Declare Function DdeQueryString Lib "user32" Alias "DdeQueryStringA" (ByVal idInst As Long, ByVal hsz As Long, ByVal psz As String, ByVal cchMax As Long, ByVal iCodePage As Long) As Long

Declare Function DdeFreeStringHandle Lib "user32" (ByVal idInst As Long, ByVal hsz As Long) As Long
Declare Function DdeKeepStringHandle Lib "user32" (ByVal idInst As Long, ByVal hsz As Long) As Long
Declare Function DdeCmpStringHandles Lib "user32" (ByVal hsz1 As Long, ByVal hsz2 As Long) As Long

Type DDEML_MSG_HOOK_DATA    '  new for NT
        uiLo As Long  '  unpacked lo and hi parts of lParam
        uiHi As Long
        cbData As Long   '  amount of data in message, if any. May be > than 32 bytes.
        Data(8) As Long  '  data peeking by DDESPY is limited to 32 bytes.
End Type

Type MONMSGSTRUCT
        cb As Long
        hwndTo As Long
        dwTime As Long
        htask As Long
        wMsg As Long
        wParam As Long
        lParam As Long
        dmhd As DDEML_MSG_HOOK_DATA       '  new for NT
End Type

Type MONCBSTRUCT
        cb As Long
        dwTime As Long
        htask As Long
        dwRet As Long
        wType As Long
        wFmt As Long
        hConv As Long
        hsz1 As Long
        hsz2 As Long
        hData As Long
        dwData1 As Long
        dwData2 As Long
        cc As CONVCONTEXT                 '  new for NT for XTYP_CONNECT callbacks
        cbData As Long                  '  new for NT for data peeking
        Data(8) As Long                 '  new for NT for data peeking
End Type

Type MONHSZSTRUCT
        cb As Long
        fsAction As Long '  MH_ value
        dwTime As Long
        hsz As Long
        htask As Long
        str As Byte
End Type

Public Const MH_CREATE = 1
Public Const MH_KEEP = 2
Public Const MH_DELETE = 3
Public Const MH_CLEANUP = 4

Type MONERRSTRUCT
        cb As Long
        wLastError As Long
        dwTime As Long
        htask As Long
End Type

Type MONLINKSTRUCT
        cb As Long
        dwTime As Long
        htask As Long
        fEstablished As Long
        fNoData As Long
        hszSvc As Long
        hszTopic As Long
        hszItem As Long
        wFmt As Long
        fServer As Long
        hConvServer As Long
        hConvClient As Long
End Type

Type MONCONVSTRUCT
        cb As Long
        fConnect As Long
        dwTime As Long
        htask As Long
        hszSvc As Long
        hszTopic As Long
        hConvClient As Long        '  Globally unique value != apps local hConv
        hConvServer As Long        '  Globally unique value != apps local hConv
End Type

Public Const MAX_MONITORS = 4
Public Const APPCLASS_MONITOR = &H1&
Public Const XTYP_MONITOR = (&HF0 Or XCLASS_NOTIFICATION Or XTYPF_NOBLOCK)

' Callback filter flags for use with MONITOR apps - 0 implies no monitor callbacks
Public Const MF_HSZ_Info = &H1000000
Public Const MF_SENDMSGS = &H2000000
Public Const MF_POSTMSGS = &H4000000
Public Const MF_CALLBACKS = &H8000000
Public Const MF_ERRORS = &H10000000
Public Const MF_LINKS = &H20000000
Public Const MF_CONV = &H40000000

Public Const MF_MASK = &HFF000000


Public Type WINDOWINFO
        cbSize As Long
        rcWindow As RECT
        rcClient As RECT
        dwStyle As Long
        dwExStyle As Long
        dwWindowStatus As Long
        cxWindowBorders As Long
        cyWindowBorders As Long
        atomWindowType As Long
        wCreatorVersion As Integer
End Type
Declare Function GetWindowInfo Lib "user32" (ByVal hWnd As Long, wi As WINDOWINFO) As Boolean



' --------------------------- ¸ß¼¶

Type PIXELFORMATDESCRIPTOR
    nSize As Integer
    nVersion As Integer
    dwFlags As Long
    iPixelType As Byte
    cColorBits As Byte
    cRedBits As Byte
    cRedShift As Byte
    cGreenBits As Byte
    cGreenShift As Byte
    cBlueBits As Byte
    cBlueShift As Byte
    cAlphaBits As Byte
    cAlphaShift As Byte
    cAccumBits As Byte
    cAccumRedBits As Byte
    cAccumGreenBits As Byte
    cAccumBlueBits As Byte
    cAccumAlphaBits As Byte
    cDepthBits As Byte
    cStencilBits As Byte
    cAuxBuffers As Byte
    iLayerType As Byte
    bReserved As Byte
    dwLayerMask As Long
    dwVisibleMask As Long
    dwDamageMask As Long
End Type

Declare Function ChoosePixelFormat Lib "gdi32" (ByVal hdc As Long, pPixelFormatDescriptor As PIXELFORMATDESCRIPTOR) As Long
'Declare Function CreateDIBSection Lib "gdi32" (ByVal hdc As Long, pBitmapInfo As BITMAPINFO, ByVal un As Long, ByVal lplpVoid As Long, ByVal handle As Long, ByVal dw As Long) As Long
Declare Function DescribePixelFormat Lib "gdi32" (ByVal hdc As Long, ByVal n As Long, ByVal un As Long, lpPixelFormatDescriptor As PIXELFORMATDESCRIPTOR) As Long
Declare Function EndDoc Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function EnumFonts Lib "gdi32" Alias "EnumFontsA" (ByVal hdc As Long, ByVal lpsz As String, ByVal lpFontEnumProc As Long, ByVal lParam As Long) As Long
Declare Function EnumMetaFile Lib "gdi32" (ByVal hdc As Long, ByVal hMetafile As Long, ByVal lpMFEnumProc As Long, ByVal lParam As Long) As Long
Declare Function EnumObjects Lib "gdi32" (ByVal hdc As Long, ByVal n As Long, ByVal lpGOBJEnumProc As Long, lpVoid As Any) As Long

Declare Function FixBrushOrgEx Lib "gdi32" (ByVal hdc As Long, ByVal n1 As Long, ByVal n2 As Long, lpPoint As POINTAPI) As Long
Declare Function GetBrushOrgEx Lib "gdi32" (ByVal hdc As Long, lpPoint As POINTAPI) As Long
'Declare Function GetDIBColorTable Lib "gdi32" (ByVal hdc As Long, ByVal un1 As Long, ByVal un2 As Long, pRGBQuad As RGBQUAD) As Long
Declare Function GetPixelFormat Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function LineDDA Lib "gdi32" (ByVal n1 As Long, ByVal n2 As Long, ByVal n3 As Long, ByVal n4 As Long, ByVal lpLineDDAProc As Long, ByVal lParam As Long) As Long

Declare Function SetAbortProc Lib "gdi32" (ByVal hdc As Long, ByVal lpAbortProc As Long) As Long
'Declare Function SetDIBColorTable Lib "gdi32" (ByVal hdc As Long, ByVal un1 As Long, ByVal un2 As Long, pcRGBQuad As RGBQUAD) As Long
Declare Function SetPixelFormat Lib "gdi32" (ByVal hdc As Long, ByVal n As Long, pcPixelFormatDescriptor As PIXELFORMATDESCRIPTOR) As Long
Declare Function SwapBuffers Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function EnumCalendarInfo Lib "kernel32" Alias "EnumCalendarInfoA" (ByVal lpCalInfoEnumProc As Long, ByVal Locale As Long, ByVal Calendar As Long, ByVal CalType As Long) As Long
'Declare Function GetCurrencyFormat Lib "kernel32" Alias "GetCurrencyFormatA" (ByVal Locale As Long, ByVal dwFlags As Long, ByVal lpValue As String, lpFormat As CURRENCYFMT, ByVal lpCurrencyStr As String, ByVal cchCurrency As Long) As Long
'Declare Function GetNumberFormat Lib "kernel32" Alias "GetNumberFormatA" (ByVal Locale As Long, ByVal dwFlags As Long, ByVal lpValue As String, lpFormat As NUMBERFMT, ByVal lpNumberStr As String, ByVal cchNumber As Long) As Long
Declare Function GetStringTypeEx Lib "kernel32" Alias "GetStringTypeExA" (ByVal Locale As Long, ByVal dwInfoType As Long, ByVal lpSrcStr As String, ByVal cchSrc As Long, lpCharType As Integer) As Long
Declare Function GetStringTypeW Lib "kernel32" (ByVal dwInfoType As Long, ByVal lpSrcStr As String, ByVal cchSrc As Long, lpCharType As Integer) As Long
Declare Function SetLocaleInfo Lib "kernel32" Alias "SetLocaleInfoA" (ByVal Locale As Long, ByVal LCType As Long, ByVal lpLCData As String) As Long

Declare Function BroadcastSystemMessage Lib "user32" (ByVal dw As Long, pdw As Long, ByVal un As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Declare Function CallWindowProc Lib "user32" Alias "CallWindowProcA" (ByVal lpPrevWndFunc As Long, ByVal hWnd As Long, ByVal Msg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Declare Function CascadeWindows Lib "user32" (ByVal hwndParent As Long, ByVal wHow As Long, ByVal lpRect As RECT, ByVal cKids As Long, lpKids As Long) As Integer
Declare Function ChangeMenu Lib "user32" Alias "ChangeMenuA" (ByVal hMenu As Long, ByVal cmd As Long, ByVal lpszNewItem As String, ByVal cmdInsert As Long, ByVal flags As Long) As Long
Declare Function CheckMenuRadioItem Lib "user32" (ByVal hMenu As Long, ByVal un1 As Long, ByVal un2 As Long, ByVal un3 As Long, ByVal un4 As Long) As Long
Declare Function ChildWindowFromPointEx Lib "user32" (ByVal hWnd As Long, ByVal pt As POINTAPI, ByVal un As Long) As Long
Declare Function CloseDesktop Lib "user32" (ByVal hDesktop As Long) As Long
Declare Function CloseWindowStation Lib "user32" (ByVal hWinSta As Long) As Long

Declare Function CopyImage Lib "user32" (ByVal handle As Long, ByVal un1 As Long, ByVal n1 As Long, ByVal n2 As Long, ByVal un2 As Long) As Long
'Declare Function CreateDesktop Lib "user32" Alias "CreateDesktopA" (ByVal lpszDesktop As String, ByVal lpszDevice As String, pDevmode As DEVMODE, ByVal dwFlags As Long, ByVal dwDesiredAccess As Long, lpsa As SECURITY_ATTRIBUTES) As Long
Declare Function CreateDialogIndirectParam Lib "user32" Alias "CreateDialogIndirectParamA" (ByVal hInstance As Long, lpTemplate As DLGTEMPLATE, ByVal hwndParent As Long, ByVal lpDialogFunc As Long, ByVal dwInitParam As Long) As Long
Declare Function CreateDialogParam Lib "user32" Alias "CreateDialogParamA" (ByVal hInstance As Long, ByVal lpName As String, ByVal hwndParent As Long, ByVal lpDialogFunc As Long, ByVal lParamInit As Long) As Long
Declare Function CreateIconFromResource Lib "user32" (presbits As Byte, ByVal dwResSize As Long, ByVal fIcon As Long, ByVal dwVer As Long) As Long

Declare Function DialogBoxIndirectParam Lib "user32" Alias "DialogBoxIndirectParamA" (ByVal hInstance As Long, hDialogTemplate As DLGTEMPLATE, ByVal hwndParent As Long, ByVal lpDialogFunc As Long, ByVal dwInitParam As Long) As Long

Declare Function DragDetect Lib "user32" (ByVal hWnd As Long, ByVal pt As POINTAPI) As Long
Declare Function DragObject Lib "user32" (ByVal hWnd1 As Long, ByVal hWnd2 As Long, ByVal un As Long, ByVal dw As Long, ByVal hCursor As Long) As Long
Declare Function DrawAnimatedRects Lib "user32" (ByVal hWnd As Long, ByVal idAni As Long, lprcFrom As RECT, lprcTo As RECT) As Long
Declare Function DrawCaption Lib "user32" (ByVal hWnd As Long, ByVal hdc As Long, pcRect As RECT, ByVal un As Long) As Long
Declare Function DrawEdge Lib "user32" (ByVal hdc As Long, qrc As RECT, ByVal edge As Long, ByVal grfFlags As Long) As Long
Declare Function DrawFrameControl Lib "user32" (ByVal hdc As Long, lpRect As RECT, ByVal un1 As Long, ByVal un2 As Long) As Long
Declare Function DrawIconEx Lib "user32" (ByVal hdc As Long, ByVal xLeft As Long, ByVal yTop As Long, ByVal hIcon As Long, ByVal cxWidth As Long, ByVal cyWidth As Long, ByVal istepIfAniCur As Long, ByVal hbrFlickerFreeDraw As Long, ByVal diFlags As Long) As Long
Declare Function DrawState Lib "user32" Alias "DrawStateA" (ByVal hdc As Long, ByVal hBrush As Long, ByVal lpDrawStateProc As Long, ByVal lParam As Long, ByVal wParam As Long, ByVal n1 As Long, ByVal n2 As Long, ByVal n3 As Long, ByVal n4 As Long, ByVal un As Long) As Long

Type DRAWTEXTPARAMS
        cbSize As Long
        iTabLength As Long
        iLeftMargin As Long
        iRightMargin As Long
        uiLengthDrawn As Long
End Type

Declare Function DrawTextEx Lib "user32" Alias "DrawTextExA" (ByVal hdc As Long, ByVal lpsz As String, ByVal n As Long, lpRect As RECT, ByVal un As Long, lpDrawTextParams As DRAWTEXTPARAMS) As Long
Declare Function EnumChildWindows Lib "user32" (ByVal hwndParent As Long, ByVal lpEnumFunc As Long, ByVal lParam As Long) As Long
Declare Function EnumDesktops Lib "user32" Alias "EnumDesktopsA" (ByVal hWinSta As Long, ByVal lpEnumFunc As Long, ByVal lParam As Long) As Long
Declare Function EnumDesktopWindows Lib "user32" (ByVal hDesktop As Long, ByVal lpfn As Long, ByVal lParam As Long) As Long
Declare Function EnumPropsEx Lib "user32" Alias "EnumPropsExA" (ByVal hWnd As Long, ByVal lpEnumFunc As Long, ByVal lParam As Long) As Long
Declare Function EnumProps Lib "user32" Alias "EnumPropsA" (ByVal hWnd As Long, ByVal lpEnumFunc As Long) As Long
Declare Function EnumThreadWindows Lib "user32" (ByVal dwThreadId As Long, ByVal lpfn As Long, ByVal lParam As Long) As Long
Declare Function EnumWindows Lib "user32" (ByVal lpEnumFunc As Long, ByVal lParam As Long) As Long
Declare Function EnumWindowStations Lib "user32" Alias "EnumWindowStationsA" (ByVal lpEnumFunc As Long, ByVal lParam As Long) As Long
Declare Function FindWindowEx Lib "user32" Alias "FindWindowExA" (ByVal hWnd1 As Long, ByVal hWnd2 As Long, ByVal lpsz1 As String, ByVal lpsz2 As String) As Long

Declare Function GetKeyboardLayoutList Lib "user32" (ByVal nBuff As Long, lpList As Long) As Long
Declare Function GetKeyboardLayout Lib "user32" (ByVal dwLayout As Long) As Long
Declare Function GetMenuContextHelpId Lib "user32" (ByVal hMenu As Long) As Long
Declare Function GetMenuDefaultItem Lib "user32" (ByVal hMenu As Long, ByVal fByPos As Long, ByVal gmdiFlags As Long) As Long

Type MENUITEMINFO
    cbSize As Long
    fMask As Long
    fType As Long
    fState As Long
    wID As Long
    hSubMenu As Long
    hbmpChecked As Long
    hbmpUnchecked As Long
    dwItemData As Long
    dwTypeData As String
    cch As Long
End Type

Declare Function GetMenuItemInfo Lib "user32" Alias "GetMenuItemInfoA" (ByVal hMenu As Long, ByVal un As Long, ByVal b As Long, lpMenuItemInfo As MENUITEMINFO) As Long
Declare Function GetMenuItemRect Lib "user32" (ByVal hWnd As Long, ByVal hMenu As Long, ByVal uItem As Long, lprcItem As RECT) As Long

Type SCROLLINFO
        cbSize As Long
        fMask As Long
        nMin As Long
        nMax As Long
        nPage As Long
        nPos As Long
        nTrackPos As Long
End Type

Declare Function GetScrollInfo Lib "user32" (ByVal hWnd As Long, ByVal n As Long, lpScrollInfo As SCROLLINFO) As Long
Declare Function GetSysColorBrush Lib "user32" (ByVal nIndex As Long) As Long
Declare Function GetUserObjectInformation Lib "user32" Alias "GetUserObjectInformationA" (ByVal hObj As Long, ByVal nIndex As Long, pvInfo As Any, ByVal nLength As Long, lpnLengthNeeded As Long) As Long
Declare Function GetWindowContextHelpId Lib "user32" (ByVal hWnd As Long) As Long
Declare Function GetWindowRgn Lib "user32" (ByVal hWnd As Long, ByVal hRgn As Long) As Long
Declare Function GrayString Lib "user32" Alias "GrayStringA" (ByVal hdc As Long, ByVal hBrush As Long, ByVal lpOutputFunc As Long, ByVal lpData As Long, ByVal nCount As Long, ByVal X As Long, ByVal Y As Long, ByVal nWidth As Long, ByVal nHeight As Long) As Long
Declare Function InsertMenuItem Lib "user32" Alias "InsertMenuItemA" (ByVal hMenu As Long, ByVal un As Long, ByVal bool As Boolean, ByRef lpcMenuItemInfo As MENUITEMINFO) As Long
Declare Function LoadCursorFromFile Lib "user32" Alias "LoadCursorFromFileA" (ByVal lpFileName As String) As Long
Declare Function LoadImage Lib "user32" Alias "LoadImageA" (ByVal hInst As Long, ByVal lpsz As String, ByVal un1 As Long, ByVal n1 As Long, ByVal n2 As Long, ByVal un2 As Long) As Long
Declare Function LookupIconIdFromDirectoryEx Lib "user32" (presbits As Byte, ByVal fIcon As Boolean, ByVal cxDesired As Long, ByVal cyDesired As Long, ByVal flags As Long) As Long
Declare Function MapVirtualKeyEx Lib "user32" Alias "MapVirtualKeyExA" (ByVal uCode As Long, ByVal uMapType As Long, ByVal dwhkl As Long) As Long
Declare Function MenuItemFromPoint Lib "user32" (ByVal hWnd As Long, ByVal hMenu As Long, ByVal ptScreen As POINTAPI) As Long

Type MSGBOXPARAMS
        cbSize As Long
        hwndOwner As Long
        hInstance As Long
        lpszText As String
        lpszCaption As String
        dwStyle As Long
        lpszIcon As String
        dwContextHelpId As Long
        lpfnMsgBoxCallback As Long
        dwLanguageId As Long
End Type

Declare Function MessageBoxIndirect Lib "user32" Alias "MessageBoxIndirectA" (lpMsgBoxParams As MSGBOXPARAMS) As Long
Declare Function OpenDesktop Lib "user32" Alias "OpenDesktopA" (ByVal lpszDesktop As String, ByVal dwFlags As Long, ByVal fInherit As Boolean, ByVal dwDesiredAccess As Long) As Long
Declare Function OpenInputDesktop Lib "user32" (ByVal dwFlags As Long, ByVal fInherit As Boolean, ByVal dwDesiredAccess As Long) As Long
Declare Function OpenWindowStation Lib "user32" Alias "OpenWindowStationA" (ByVal lpszWinSta As String, ByVal fInherit As Boolean, ByVal dwDesiredAccess As Long) As Long
Declare Function PaintDesktop Lib "user32" (ByVal hdc As Long) As Long

Type WNDCLASSEX
    cbSize As Long
    style As Long
    lpfnWndProc As Long
    cbClsExtra As Long
    cbWndExtra As Long
    hInstance As Long
    hIcon As Long
    hCursor As Long
    hbrBackground As Long
    lpszMenuName As String
    lpszClassName As String
    hIconSm As Long
End Type

Declare Function RegisterClassEx Lib "user32" Alias "RegisterClassExA" (pcWndClassEx As WNDCLASSEX) As Integer
Declare Function SetMenuContextHelpId Lib "user32" (ByVal hMenu As Long, ByVal dw As Long) As Long
Declare Function SetMenuDefaultItem Lib "user32" (ByVal hMenu As Long, ByVal uItem As Long, ByVal fByPos As Long) As Long
Declare Function SetMenuItemInfo Lib "user32" Alias "SetMenuItemInfoA" (ByVal hMenu As Long, ByVal un As Long, ByVal bool As Boolean, lpcMenuItemInfo As MENUITEMINFO) As Long
Declare Function SetMessageExtraInfo Lib "user32" (ByVal lParam As Long) As Long
Declare Function SetMessageQueue Lib "user32" (ByVal cMessagesMax As Long) As Long
Declare Function SetProcessWindowStation Lib "user32" (ByVal hWinSta As Long) As Long
Declare Function SetScrollInfo Lib "user32" (ByVal hWnd As Long, ByVal n As Long, lpcScrollInfo As SCROLLINFO, ByVal bool As Boolean) As Long
Declare Function SetSystemCursor Lib "user32" (ByVal hcur As Long, ByVal id As Long) As Long
Declare Function SetThreadDesktop Lib "user32" (ByVal hDesktop As Long) As Long
Declare Function SetTimer Lib "user32" (ByVal hWnd As Long, ByVal nIDEvent As Long, ByVal uElapse As Long, ByVal lpTimerFunc As Long) As Long
Declare Function SetUserObjectInformation Lib "user32" Alias "SetUserObjectInformationA" (ByVal hObj As Long, ByVal nIndex As Long, pvInfo As Any, ByVal nLength As Long) As Long
Declare Function SetWindowContextHelpId Lib "user32" (ByVal hWnd As Long, ByVal dw As Long) As Long
Declare Function SetWindowRgn Lib "user32" (ByVal hWnd As Long, ByVal hRgn As Long, ByVal bRedraw As Boolean) As Long
Declare Function SetWindowsHook Lib "user32" Alias "SetWindowsHookA" (ByVal nFilterType As Long, ByVal pfnFilterProc As Long) As Long
Declare Function SetWindowsHookEx Lib "user32" Alias "SetWindowsHookExA" (ByVal idHook As Long, ByVal lpfn As Long, ByVal hmod As Long, ByVal dwThreadId As Long) As Long
Declare Function ShowWindowAsync Lib "user32" (ByVal hWnd As Long, ByVal nCmdShow As Long) As Long
Declare Function SwitchDesktop Lib "user32" (ByVal hDesktop As Long) As Long
Declare Function TileWindows Lib "user32" (ByVal hwndParent As Long, ByVal wHow As Long, lpRect As RECT, ByVal cKids As Long, lpKids As Long) As Integer
Declare Function ToAsciiEx Lib "user32" (ByVal uVirtKey As Long, ByVal uScanCode As Long, lpKeyState As Byte, lpChar As Integer, ByVal uFlags As Long, ByVal dwhkl As Long) As Long

Type TPMPARAMS
    cbSize As Long
    rcExclude As RECT
End Type

Declare Function TrackPopupMenuEx Lib "user32" (ByVal hMenu As Long, ByVal un As Long, ByVal n1 As Long, ByVal n2 As Long, ByVal hWnd As Long, lpTPMParams As TPMPARAMS) As Long
Declare Function UnhookWindowsHook Lib "user32" (ByVal nCode As Long, ByVal pfnFilterProc As Long) As Long
Declare Function VkKeyScanEx Lib "user32" Alias "VkKeyScanExA" (ByVal ch As Byte, ByVal dwhkl As Long) As Integer
Declare Function WNetGetUniversalName Lib "mpr" Alias "WNetGetUniversalNameA" (ByVal lpLocalPath As String, ByVal dwInfoLevel As Long, lpBuffer As Any, lpBufferSize As Long) As Long

Const INVALID_HANDLE_VALUE = -1

'DrawEdge Constants
Const BDR_RAISEDOUTER = &H1
Const BDR_SUNKENOUTER = &H2
Const BDR_RAISEDINNER = &H4
Const BDR_SUNKENINNER = &H8

Const BDR_OUTER = &H3
Const BDR_INNER = &HC
Const BDR_RAISED = &H5
Const BDR_SUNKEN = &HA

Const EDGE_RAISED = (BDR_RAISEDOUTER Or BDR_RAISEDINNER)
Const EDGE_SUNKEN = (BDR_SUNKENOUTER Or BDR_SUNKENINNER)
Const EDGE_ETCHED = (BDR_SUNKENOUTER Or BDR_RAISEDINNER)
Const EDGE_BUMP = (BDR_RAISEDOUTER Or BDR_SUNKENINNER)

Const BF_LEFT = &H1
Const BF_TOP = &H2
Const BF_RIGHT = &H4
Const BF_BOTTOM = &H8

Const BF_TOPLEFT = (BF_TOP Or BF_LEFT)
Const BF_TOPRIGHT = (BF_TOP Or BF_RIGHT)
Const BF_BOTTOMLEFT = (BF_BOTTOM Or BF_LEFT)
Const BF_BOTTOMRIGHT = (BF_BOTTOM Or BF_RIGHT)
Const BF_RECT = (BF_LEFT Or BF_TOP Or BF_RIGHT Or BF_BOTTOM)

Const BF_DIAGONAL = &H10

' For diagonal lines, the BF_RECT flags specify the end point of
' the vector bounded by the rectangle parameter.
Const BF_DIAGONAL_ENDTOPRIGHT = (BF_DIAGONAL Or BF_TOP Or BF_RIGHT)
Const BF_DIAGONAL_ENDTOPLEFT = (BF_DIAGONAL Or BF_TOP Or BF_LEFT)
Const BF_DIAGONAL_ENDBOTTOMLEFT = (BF_DIAGONAL Or BF_BOTTOM Or BF_LEFT)
Const BF_DIAGONAL_ENDBOTTOMRIGHT = (BF_DIAGONAL Or BF_BOTTOM Or BF_RIGHT)

Const BF_MIDDLE = &H800    ' Fill in the middle.
Const BF_SOFT = &H1000     ' Use for softer buttons.
Const BF_ADJUST = &H2000   ' Calculate the space left over.
Const BF_FLAT = &H4000     ' For flat rather than 3-D borders.
Const BF_MONO = &H8000     ' For monochrome borders.




Public Function GetWndClass(ByVal hWnd As Long) As WNDCLASS
        Dim clsname As String * 1024
        Dim l As Long
        l = GetClassName(hWnd, clsname, 1024)
        l = GetClassInfo(App.hInstance, Left(clsname, l), GetWndClass)

        If l = 0 Then Err.Raise -1
End Function
