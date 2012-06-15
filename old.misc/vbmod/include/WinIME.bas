Attribute VB_Name = "modIME"
Option Explicit

' ********************************************************************
'       IMM.H - Input Method Manager definitions
'
'       Copyright (c) 1993-1995  Microsoft Corporation
' ********************************************************************

Public Const VK_PROCESSKEY = &HE5

Type COMPOSITIONFORM
        dwStyle As Long
        ptCurrentPos As POINTAPI
        rcArea As RECT
End Type

Type CANDIDATEFORM
        dwIndex As Long
        dwStyle As Long
        ptCurrentPos As POINTAPI
        rcArea As RECT
End Type

Type CANDIDATELIST
        dwSize As Long
        dwStyle As Long
        dwCount As Long
        dwSelection As Long
        dwPageStart As Long
        dwPageSize As Long
        dwOffset(1) As Long
End Type

Public Const STYLE_DESCRIPTION_SIZE = 32

Type STYLEBUF
        dwStyle As Long
        szDescription As String * STYLE_DESCRIPTION_SIZE
End Type
'  prototype of IMM API

Declare Function ImmInstallIME Lib "imm32.dll" Alias "ImmInstallIMEA" (ByVal lpszIMEFileName As String, ByVal lpszLayoutText As String) As Long
Declare Function ImmGetDefaultIMEWnd Lib "imm32.dll" (ByVal hWnd As Long) As Long
Declare Function ImmGetDescription Lib "imm32.dll" Alias "ImmGetDescriptionA" (ByVal hkl As Long, ByVal lpsz As String, ByVal uBufLen As Long) As Long
Declare Function ImmGetIMEFileName Lib "imm32.dll" Alias "ImmGetIMEFileNameA" (ByVal hkl As Long, ByVal lpStr As String, ByVal uBufLen As Long) As Long
Declare Function ImmGetProperty Lib "imm32.dll" (ByVal hkl As Long, ByVal dw As Long) As Long
Declare Function ImmIsIME Lib "imm32.dll" (ByVal hkl As Long) As Long
Declare Function ImmSimulateHotKey Lib "imm32.dll" (ByVal hWnd As Long, ByVal dw As Long) As Long
Declare Function ImmCreateContext Lib "imm32.dll" () As Long
Declare Function ImmDestroyContext Lib "imm32.dll" (ByVal himc As Long) As Long
Declare Function ImmGetContext Lib "imm32.dll" (ByVal hWnd As Long) As Long
Declare Function ImmReleaseContext Lib "imm32.dll" (ByVal hWnd As Long, ByVal himc As Long) As Long
Declare Function ImmAssociateContext Lib "imm32.dll" (ByVal hWnd As Long, ByVal himc As Long) As Long
Declare Function ImmGetCompositionString Lib "imm32.dll" Alias "ImmGetCompositionStringA" (ByVal himc As Long, ByVal dw As Long, lpv As Any, ByVal dw2 As Long) As Long
Declare Function ImmSetCompositionString Lib "imm32.dll" Alias "ImmSetCompositionStringA" (ByVal himc As Long, ByVal dwIndex As Long, lpComp As Any, ByVal dw As Long, lpRead As Any, ByVal dw2 As Long) As Long
Declare Function ImmGetCandidateListCount Lib "imm32.dll" Alias "ImmGetCandidateListCountA" (ByVal himc As Long, lpdwListCount As Long) As Long
Declare Function ImmGetCandidateList Lib "imm32.dll" Alias "ImmGetCandidateListA" (ByVal himc As Long, ByVal deIndex As Long, lpCandidateList As CANDIDATELIST, ByVal dwBufLen As Long) As Long
Declare Function ImmGetGuideLine Lib "imm32.dll" Alias " ImmGetGuideLineA" (ByVal himc As Long, ByVal dwIndex As Long, ByVal lpStr As String, ByVal dwBufLen As Long) As Long
Declare Function ImmGetConversionStatus Lib "imm32.dll" (ByVal himc As Long, lpdw As Long, lpdw2 As Long) As Long
Declare Function ImmSetConversionStatus Lib "imm32.dll" (ByVal himc As Long, ByVal dw1 As Long, ByVal dw2 As Long) As Long
Declare Function ImmGetOpenStatus Lib "imm32.dll" (ByVal himc As Long) As Long
Declare Function ImmSetOpenStatus Lib "imm32.dll" (ByVal himc As Long, ByVal b As Long) As Long
Declare Function ImmGetCompositionFont Lib "imm32.dll" Alias "ImmGetCompositionFontA" (ByVal himc As Long, lpLogFont As LOGFONT) As Long
Declare Function ImmSetCompositionFont Lib "imm32.dll" Alias "ImmSetCompositionFontA" (ByVal himc As Long, lpLogFont As LOGFONT) As Long
Declare Function ImmConfigureIME Lib "imm32.dll" (ByVal hkl As Long, ByVal hWnd As Long, ByVal dw As Long) As Long
Declare Function ImmEscape Lib "imm32.dll" Alias "ImmEscapeA" (ByVal hkl As Long, ByVal himc As Long, ByVal un As Long, lpv As Any) As Long
Declare Function ImmGetConversionList Lib "imm32.dll" Alias "ImmGetConversionListA" (ByVal hkl As Long, ByVal himc As Long, ByVal lpsz As String, lpCandidateList As CANDIDATELIST, ByVal dwBufLen As Long, ByVal uFlag As Long) As Long
Declare Function ImmNotifyIME Lib "imm32.dll" (ByVal himc As Long, ByVal dwAction As Long, ByVal dwIndex As Long, ByVal dwValue As Long) As Long
Declare Function ImmGetStatusWindowPos Lib "imm32.dll" (ByVal himc As Long, lpPoint As POINTAPI) As Long
Declare Function ImmSetStatusWindowPos Lib "imm32.dll" (ByVal himc As Long, lpPoint As POINTAPI) As Long
Declare Function ImmGetCompositionWindow Lib "imm32.dll" (ByVal himc As Long, lpCompositionForm As COMPOSITIONFORM) As Long
Declare Function ImmSetCompositionWindow Lib "imm32.dll" (ByVal himc As Long, lpCompositionForm As COMPOSITIONFORM) As Long
Declare Function ImmGetCandidateWindow Lib "imm32.dll" (ByVal himc As Long, ByVal dw As Long, lpCandidateForm As CANDIDATEFORM) As Long
Declare Function ImmSetCandidateWindow Lib "imm32.dll" (ByVal himc As Long, lpCandidateForm As CANDIDATEFORM) As Long
Declare Function ImmIsUIMessage Lib "imm32.dll" Alias "ImmIsUIMessageA" (ByVal hWnd As Long, ByVal un As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Declare Function ImmGetVirtualKey Lib "imm32.dll" (ByVal hWnd As Long) As Long
Declare Function ImmRegisterWord Lib "imm32.dll" Alias "ImmRegisterWordA" (ByVal hkl As Long, ByVal lpszReading As String, ByVal dw As Long, ByVal lpszRegister As String) As Long
Declare Function ImmUnregisterWord Lib "imm32.dll" Alias "ImmUnregisterWordA" (ByVal hkl As Long, ByVal lpszReading As String, ByVal dw As Long, ByVal lpszUnregister As String) As Long
Declare Function ImmGetRegisterWordStyle Lib "imm32.dll" Alias " ImmGetRegisterWordStyleA" (ByVal hkl As Long, ByVal nItem As Long, lpStyleBuf As STYLEBUF) As Long
Declare Function ImmEnumRegisterWord Lib "imm32.dll" Alias "ImmEnumRegisterWordA" (ByVal hkl As Long, ByVal RegisterWordEnumProc As Long, ByVal lpszReading As String, ByVal dw As Long, ByVal lpszRegister As String, lpv As Any) As Long
'  the IME related messages
Public Const WM_CONVERTREQUESTEX = &H108
Public Const WM_IME_STARTCOMPOSITION = &H10D
Public Const WM_IME_ENDCOMPOSITION = &H10E
Public Const WM_IME_COMPOSITION = &H10F
Public Const WM_IME_KEYLAST = &H10F

Public Const WM_IME_SETCONTEXT = &H281
Public Const WM_IME_NOTIFY = &H282
Public Const WM_IME_CONTROL = &H283
Public Const WM_IME_COMPOSITIONFULL = &H284
Public Const WM_IME_SELECT = &H285
Public Const WM_IME_CHAR = &H286

Public Const WM_IME_KEYDOWN = &H290
Public Const WM_IME_KEYUP = &H291

'  wParam for WM_IME_CONTROL
Public Const IMC_GETCANDIDATEPOS = &H7
Public Const IMC_SETCANDIDATEPOS = &H8
Public Const IMC_GETCOMPOSITIONFONT = &H9
Public Const IMC_SETCOMPOSITIONFONT = &HA
Public Const IMC_GETCOMPOSITIONWINDOW = &HB
Public Const IMC_SETCOMPOSITIONWINDOW = &HC
Public Const IMC_GETSTATUSWINDOWPOS = &HF
Public Const IMC_SETSTATUSWINDOWPOS = &H10
Public Const IMC_CLOSESTATUSWINDOW = &H21
Public Const IMC_OPENSTATUSWINDOW = &H22


'  wParam for WM_IME_CONTROL to the soft keyboard
'  dwAction for ImmNotifyIME
Public Const NI_OPENCANDIDATE = &H10
Public Const NI_CLOSECANDIDATE = &H11
Public Const NI_SELECTCANDIDATESTR = &H12
Public Const NI_CHANGECANDIDATELIST = &H13
Public Const NI_FINALIZECONVERSIONRESULT = &H14
Public Const NI_COMPOSITIONSTR = &H15
Public Const NI_SETCANDIDATE_PAGESTART = &H16
Public Const NI_SETCANDIDATE_PAGESIZE = &H17

'  lParam for WM_IME_SETCONTEXT
Public Const ISC_SHOWUICANDIDATEWINDOW = &H1
Public Const ISC_SHOWUICOMPOSITIONWINDOW = &H80000000
Public Const ISC_SHOWUIGUIDELINE = &H40000000
Public Const ISC_SHOWUIALLCANDIDATEWINDOW = &HF
Public Const ISC_SHOWUIALL = &HC000000F

'  dwIndex for ImmNotifyIME/NI_COMPOSITIONSTR
Public Const CPS_COMPLETE = &H1
Public Const CPS_CONVERT = &H2
Public Const CPS_REVERT = &H3
Public Const CPS_CANCEL = &H4

'  Windows for Simplified Chinese Edition hot key ID from 0x10 - 0x2F
Public Const IME_CHOTKEY_IME_NONIME_TOGGLE = &H10
Public Const IME_CHOTKEY_SHAPE_TOGGLE = &H11
Public Const IME_CHOTKEY_SYMBOL_TOGGLE = &H12

'  Windows for Japanese Edition hot key ID from 0x30 - 0x4F
Public Const IME_JHOTKEY_CLOSE_OPEN = &H30

'  Windows for Korean Edition hot key ID from 0x50 - 0x6F
Public Const IME_KHOTKEY_SHAPE_TOGGLE = &H50
Public Const IME_KHOTKEY_HANJACONVERT = &H51
Public Const IME_KHOTKEY_ENGLISH = &H52

'  Windows for Tranditional Chinese Edition hot key ID from 0x70 - 0x8F
Public Const IME_THOTKEY_IME_NONIME_TOGGLE = &H70
Public Const IME_THOTKEY_SHAPE_TOGGLE = &H71
Public Const IME_THOTKEY_SYMBOL_TOGGLE = &H72

'  direct switch hot key ID from 0x100 - 0x11F
Public Const IME_HOTKEY_DSWITCH_FIRST = &H100
Public Const IME_HOTKEY_DSWITCH_LAST = &H11F

'  IME private hot key from 0x200 - 0x21F
Public Const IME_ITHOTKEY_RESEND_RESULTSTR = &H200
Public Const IME_ITHOTKEY_PREVIOUS_COMPOSITION = &H201
Public Const IME_ITHOTKEY_UISTYLE_TOGGLE = &H202

'  parameter of ImmGetCompositionString
Public Const GCS_COMPREADSTR = &H1
Public Const GCS_COMPREADATTR = &H2
Public Const GCS_COMPREADCLAUSE = &H4
Public Const GCS_COMPSTR = &H8
Public Const GCS_COMPATTR = &H10
Public Const GCS_COMPCLAUSE = &H20
Public Const GCS_CURSORPOS = &H80
Public Const GCS_DELTASTART = &H100
Public Const GCS_RESULTREADSTR = &H200
Public Const GCS_RESULTREADCLAUSE = &H400
Public Const GCS_RESULTSTR = &H800
Public Const GCS_RESULTCLAUSE = &H1000

'  style bit flags for WM_IME_COMPOSITION
Public Const CS_INSERTCHAR = &H2000
Public Const CS_NOMOVECARET = &H4000

'  bits of fdwInit of INPUTCONTEXT
'  IME property bits
Public Const IME_PROP_AT_CARET = &H10000
Public Const IME_PROP_SPECIAL_UI = &H20000
Public Const IME_PROP_CANDLIST_START_FROM_1 = &H40000
Public Const IME_PROP_UNICODE = &H80000

'  IME UICapability bits
Public Const UI_CAP_2700 = &H1
Public Const UI_CAP_ROT90 = &H2
Public Const UI_CAP_ROTANY = &H4

'  ImmSetCompositionString Capability bits
Public Const SCS_CAP_COMPSTR = &H1
Public Const SCS_CAP_MAKEREAD = &H2

'  IME WM_IME_SELECT inheritance Capability bits
Public Const SELECT_CAP_CONVERSION = &H1
Public Const SELECT_CAP_SENTENCE = &H2

'  ID for deIndex of ImmGetGuideLine
Public Const GGL_LEVEL = &H1
Public Const GGL_INDEX = &H2
Public Const GGL_STRING = &H3
Public Const GGL_PRIVATE = &H4

'  ID for dwLevel of GUIDELINE Structure
Public Const GL_LEVEL_NOGUIDELINE = &H0
Public Const GL_LEVEL_FATAL = &H1
Public Const GL_LEVEL_ERROR = &H2
Public Const GL_LEVEL_WARNING = &H3
Public Const GL_LEVEL_INFORMATION = &H4

'  ID for dwIndex of GUIDELINE Structure
Public Const GL_ID_UNKNOWN = &H0
Public Const GL_ID_NOMODULE = &H1
Public Const GL_ID_NODICTIONARY = &H10
Public Const GL_ID_CANNOTSAVE = &H11
Public Const GL_ID_NOCONVERT = &H20
Public Const GL_ID_TYPINGERROR = &H21
Public Const GL_ID_TOOMANYSTROKE = &H22
Public Const GL_ID_READINGCONFLICT = &H23
Public Const GL_ID_INPUTREADING = &H24
Public Const GL_ID_INPUTRADICAL = &H25
Public Const GL_ID_INPUTCODE = &H26
Public Const GL_ID_INPUTSYMBOL = &H27
Public Const GL_ID_CHOOSECANDIDATE = &H28
Public Const GL_ID_REVERSECONVERSION = &H29
Public Const GL_ID_PRIVATE_FIRST = &H8000
Public Const GL_ID_PRIVATE_LAST = &HFFFF

'  ID for dwIndex of ImmGetProperty
Public Const IGP_PROPERTY = &H4
Public Const IGP_CONVERSION = &H8
Public Const IGP_SENTENCE = &HC
Public Const IGP_UI = &H10
Public Const IGP_SETCOMPSTR = &H14
Public Const IGP_SELECT = &H18

'  dwIndex for ImmSetCompositionString API
Public Const SCS_SETSTR = (GCS_COMPREADSTR Or GCS_COMPSTR)
Public Const SCS_CHANGEATTR = (GCS_COMPREADATTR Or GCS_COMPATTR)
Public Const SCS_CHANGECLAUSE = (GCS_COMPREADCLAUSE Or GCS_COMPCLAUSE)

'  attribute for COMPOSITIONSTRING Structure
Public Const ATTR_INPUT = &H0
Public Const ATTR_TARGET_CONVERTED = &H1
Public Const ATTR_CONVERTED = &H2
Public Const ATTR_TARGET_NOTCONVERTED = &H3
Public Const ATTR_INPUT_ERROR = &H4

'  bit field for IMC_SETCOMPOSITIONWINDOW, IMC_SETCANDIDATEWINDOW
Public Const CFS_DEFAULT = &H0
Public Const CFS_RECT = &H1
Public Const CFS_POINT = &H2
Public Const CFS_SCREEN = &H4
Public Const CFS_FORCE_POSITION = &H20
Public Const CFS_CANDIDATEPOS = &H40
Public Const CFS_EXCLUDE = &H80

'  conversion direction for ImmGetConversionList
Public Const GCL_CONVERSION = &H1
Public Const GCL_REVERSECONVERSION = &H2
Public Const GCL_REVERSE_LENGTH = &H3

'  bit field for conversion mode
Public Const IME_CMODE_ALPHANUMERIC = &H0
Public Const IME_CMODE_NATIVE = &H1
Public Const IME_CMODE_CHINESE = IME_CMODE_NATIVE
Public Const IME_CMODE_HANGEUL = IME_CMODE_NATIVE
Public Const IME_CMODE_JAPANESE = IME_CMODE_NATIVE
Public Const IME_CMODE_KATAKANA = &H2                   '  only effect under IME_CMODE_NATIVE
Public Const IME_CMODE_LANGUAGE = &H3
Public Const IME_CMODE_FULLSHAPE = &H8
Public Const IME_CMODE_ROMAN = &H10
Public Const IME_CMODE_CHARCODE = &H20
Public Const IME_CMODE_HANJACONVERT = &H40
Public Const IME_CMODE_SOFTKBD = &H80
Public Const IME_CMODE_NOCONVERSION = &H100
Public Const IME_CMODE_EUDC = &H200
Public Const IME_CMODE_SYMBOL = &H400

Public Const IME_SMODE_NONE = &H0
Public Const IME_SMODE_PLAURALCLAUSE = &H1
Public Const IME_SMODE_SINGLECONVERT = &H2
Public Const IME_SMODE_AUTOMATIC = &H4
Public Const IME_SMODE_PHRASEPREDICT = &H8

'  style of candidate
Public Const IME_CAND_UNKNOWN = &H0
Public Const IME_CAND_READ = &H1
Public Const IME_CAND_CODE = &H2
Public Const IME_CAND_MEANING = &H3
Public Const IME_CAND_RADICAL = &H4
Public Const IME_CAND_STROKE = &H5

'  wParam of report message WM_IME_NOTIFY
Public Const IMN_CLOSESTATUSWINDOW = &H1
Public Const IMN_OPENSTATUSWINDOW = &H2
Public Const IMN_CHANGECANDIDATE = &H3
Public Const IMN_CLOSECANDIDATE = &H4
Public Const IMN_OPENCANDIDATE = &H5
Public Const IMN_SETCONVERSIONMODE = &H6
Public Const IMN_SETSENTENCEMODE = &H7
Public Const IMN_SETOPENSTATUS = &H8
Public Const IMN_SETCANDIDATEPOS = &H9
Public Const IMN_SETCOMPOSITIONFONT = &HA
Public Const IMN_SETCOMPOSITIONWINDOW = &HB
Public Const IMN_SETSTATUSWINDOWPOS = &HC
Public Const IMN_GUIDELINE = &HD
Public Const IMN_PRIVATE = &HE

'  error code of ImmGetCompositionString
Public Const IMM_ERROR_NODATA = (-1)
Public Const IMM_ERROR_GENERAL = (-2)

'  dialog mode of ImmConfigureIME
Public Const IME_CONFIG_GENERAL = 1
Public Const IME_CONFIG_REGISTERWORD = 2
Public Const IME_CONFIG_SELECTDICTIONARY = 3

'  dialog mode of ImmEscape
Public Const IME_ESC_QUERY_SUPPORT = &H3
Public Const IME_ESC_RESERVED_FIRST = &H4
Public Const IME_ESC_RESERVED_LAST = &H7FF
Public Const IME_ESC_PRIVATE_FIRST = &H800
Public Const IME_ESC_PRIVATE_LAST = &HFFF
Public Const IME_ESC_SEQUENCE_TO_INTERNAL = &H1001
Public Const IME_ESC_GET_EUDC_DICTIONARY = &H1003
Public Const IME_ESC_SET_EUDC_DICTIONARY = &H1004
Public Const IME_ESC_MAX_KEY = &H1005
Public Const IME_ESC_IME_NAME = &H1006
Public Const IME_ESC_SYNC_HOTKEY = &H1007
Public Const IME_ESC_HANJA_MODE = &H1008

'  style of word registration
Public Const IME_REGWORD_STYLE_EUDC = &H1
Public Const IME_REGWORD_STYLE_USER_FIRST = &H80000000
Public Const IME_REGWORD_STYLE_USER_LAST = &HFFFF

'  type of soft keyboard
'  for Windows Tranditional Chinese Edition
Public Const SOFTKEYBOARD_TYPE_T1 = &H1
'  for Windows Simplified Chinese Edition
Public Const SOFTKEYBOARD_TYPE_C1 = &H2
