Attribute VB_Name = "modWinKernel"
Option Explicit

' ----------------
'  Kernel Section
' ----------------
' Line 213

Public Const FILE_BEGIN = 0
Public Const FILE_CURRENT = 1
Public Const FILE_END = 2

Public Const FILE_FLAG_WRITE_THROUGH = &H80000000
Public Const FILE_FLAG_OVERLAPPED = &H40000000
Public Const FILE_FLAG_NO_BUFFERING = &H20000000
Public Const FILE_FLAG_RANDOM_ACCESS = &H10000000
Public Const FILE_FLAG_SEQUENTIAL_SCAN = &H8000000
Public Const FILE_FLAG_DELETE_ON_CLOSE = &H4000000
Public Const FILE_FLAG_BACKUP_SEMANTICS = &H2000000
Public Const FILE_FLAG_POSIX_SEMANTICS = &H1000000

Public Const CREATE_NEW = 1
Public Const CREATE_ALWAYS = 2
Public Const OPEN_EXISTING = 3
Public Const OPEN_ALWAYS = 4
Public Const TRUNCATE_EXISTING = 5

' Define the dwOpenMode values for CreateNamedPipe
Public Const PIPE_ACCESS_INBOUND = &H1
Public Const PIPE_ACCESS_OUTBOUND = &H2
Public Const PIPE_ACCESS_DUPLEX = &H3

' Define the Named Pipe End flags for GetNamedPipeInfo
Public Const PIPE_CLIENT_END = &H0
Public Const PIPE_SERVER_END = &H1

' Define the dwPipeMode values for CreateNamedPipe
Public Const PIPE_WAIT = &H0
Public Const PIPE_NOWAIT = &H1
Public Const PIPE_READMODE_BYTE = &H0
Public Const PIPE_READMODE_MESSAGE = &H2
Public Const PIPE_TYPE_BYTE = &H0
Public Const PIPE_TYPE_MESSAGE = &H4

' Define the well known values for CreateNamedPipe nMaxInstances
Public Const PIPE_UNLIMITED_INSTANCES = 255

' Define the Security Quality of Service bits to be passed
'  into CreateFile
Public Const SECURITY_CONTEXT_TRACKING = &H40000
Public Const SECURITY_EFFECTIVE_ONLY = &H80000

Public Const SECURITY_SQOS_PRESENT = &H100000
Public Const SECURITY_VALID_SQOS_FLAGS = &H1F0000

Public Type OVERLAPPED
        Internal As Long
        InternalHigh As Long
        offset As Long
        OffsetHigh As Long
        hEvent As Long
End Type

Public Type SECURITY_ATTRIBUTES
        nLength As Long
        lpSecurityDescriptor As Long
        bInheritHandle As Long
End Type

Public Type PROCESS_INFORMATION
        hProcess As Long
        hThread As Long
        dwProcessId As Long
        dwThreadId As Long
End Type

Public Type FILETIME
        dwLowDateTime As Long
        dwHighDateTime As Long
End Type

Public Type SystemTime
        wYear As Integer
        wMonth As Integer
        wDayOfWeek As Integer
        wDay As Integer
        wHour As Integer
        wMinute As Integer
        wSecond As Integer
        wMilliseconds As Integer
End Type

'  Serial provider public type.
Public Const SP_SERIALCOMM = &H1&

'  Provider SubTypes
Public Const PST_UNSPECIFIED = &H0&
Public Const PST_RS232 = &H1&
Public Const PST_PARALLELPORT = &H2&
Public Const PST_RS422 = &H3&
Public Const PST_RS423 = &H4&
Public Const PST_RS449 = &H5&
Public Const PST_FAX = &H21&
Public Const PST_SCANNER = &H22&
Public Const PST_NETWORK_BRIDGE = &H100&
Public Const PST_LAT = &H101&
Public Const PST_TCPIP_TELNET = &H102&
Public Const PST_X25 = &H103&

'  Provider capabilities flags.
Public Const PCF_DTRDSR = &H1&
Public Const PCF_RTSCTS = &H2&
Public Const PCF_RLSD = &H4&
Public Const PCF_PARITY_CHECK = &H8&
Public Const PCF_XONXOFF = &H10&
Public Const PCF_SETXCHAR = &H20&
Public Const PCF_TOTALTIMEOUTS = &H40&
Public Const PCF_INTTIMEOUTS = &H80&
Public Const PCF_SPECIALCHARS = &H100&
Public Const PCF_16BITMODE = &H200&

'  Comm provider settable parameters.
Public Const SP_PARITY = &H1&
Public Const SP_BAUD = &H2&
Public Const SP_DATABITS = &H4&
Public Const SP_STOPBITS = &H8&
Public Const SP_HANDSHAKING = &H10&
Public Const SP_PARITY_CHECK = &H20&
Public Const SP_RLSD = &H40&

'  Settable baud rates in the provider.
Public Const BAUD_075 = &H1&
Public Const BAUD_110 = &H2&
Public Const BAUD_134_5 = &H4&
Public Const BAUD_150 = &H8&
Public Const BAUD_300 = &H10&
Public Const BAUD_600 = &H20&
Public Const BAUD_1200 = &H40&
Public Const BAUD_1800 = &H80&
Public Const BAUD_2400 = &H100&
Public Const BAUD_4800 = &H200&
Public Const BAUD_7200 = &H400&
Public Const BAUD_9600 = &H800&
Public Const BAUD_14400 = &H1000&
Public Const BAUD_19200 = &H2000&
Public Const BAUD_38400 = &H4000&
Public Const BAUD_56K = &H8000&
Public Const BAUD_128K = &H10000
Public Const BAUD_115200 = &H20000
Public Const BAUD_57600 = &H40000
Public Const BAUD_USER = &H10000000

'  Settable Data Bits
Public Const DATABITS_5 = &H1&
Public Const DATABITS_6 = &H2&
Public Const DATABITS_7 = &H4&
Public Const DATABITS_8 = &H8&
Public Const DATABITS_16 = &H10&
Public Const DATABITS_16X = &H20&

'  Settable Stop and Parity bits.
Public Const STOPBITS_10 = &H1&
Public Const STOPBITS_15 = &H2&
Public Const STOPBITS_20 = &H4&
Public Const PARITY_NONE = &H100&
Public Const PARITY_ODD = &H200&
Public Const PARITY_EVEN = &H400&
Public Const PARITY_MARK = &H800&
Public Const PARITY_SPACE = &H1000&

Public Type COMMPROP
        wPacketLength As Integer
        wPacketVersion As Integer
        dwServiceMask As Long
        dwReserved1 As Long
        dwMaxTxQueue As Long
        dwMaxRxQueue As Long
        dwMaxBaud As Long
        dwProvSubType As Long
        dwProvCapabilities As Long
        dwSettableParams As Long
        dwSettableBaud As Long
        wSettableData As Integer
        wSettableStopParity As Integer
        dwCurrentTxQueue As Long
        dwCurrentRxQueue As Long
        dwProvSpec1 As Long
        dwProvSpec2 As Long
        wcProvChar(1) As Integer
End Type

'public type COMSTAT
'        fCtsHold As Long
'        fDsrHold As Long
'        fRlsdHold As Long
'        fXoffHold As Long
'        fXoffSent As Long
'        fEof As Long
'        fTxim As Long
'        fReserved As Long
'        cbInQue As Long
'        cbOutQue As Long
'end type

Public Type COMSTAT
        fBitFields As Long 'See Comment in Win32API.Txt
        cbInQue As Long
        cbOutQue As Long
End Type
' The eight actual COMSTAT bit-sized data fields within the four bytes of fBitFields can be manipulated by bitwise logical And/Or operations.
' FieldName     Bit #     Description
' ---------     -----     ---------------------------
' fCtsHold        1       Tx waiting for CTS signal
' fDsrHold        2       Tx waiting for DSR signal
' fRlsdHold       3       Tx waiting for RLSD signal
' fXoffHold       4       Tx waiting, XOFF char rec'd
' fXoffSent       5       Tx waiting, XOFF char sent
' fEof            6       EOF character sent
' fTxim           7       character waiting for Tx
' fReserved       8       reserved (25 bits)

'  DTR Control Flow Values.
Public Const DTR_CONTROL_DISABLE = &H0
Public Const DTR_CONTROL_ENABLE = &H1
Public Const DTR_CONTROL_HANDSHAKE = &H2

'  RTS Control Flow Values
Public Const RTS_CONTROL_DISABLE = &H0
Public Const RTS_CONTROL_ENABLE = &H1
Public Const RTS_CONTROL_HANDSHAKE = &H2
Public Const RTS_CONTROL_TOGGLE = &H3

'public type DCB
'        DCBlength As Long
'        BaudRate As Long
'        fBinary As Long
'        fParity As Long
'        fOutxCtsFlow As Long
'        fOutxDsrFlow As Long
'        fDtrControl As Long
'        fDsrSensitivity As Long
'        fTXContinueOnXoff As Long
'        fOutX As Long
'        fInX As Long
'        fErrorChar As Long
'        fNull As Long
'        fRtsControl As Long
'        fAbortOnError As Long
'        fDummy2 As Long
'        wReserved As Integer
'        XonLim As Integer
'        XoffLim As Integer
'        ByteSize As Byte
'        Parity As Byte
'        StopBits As Byte
'        XonChar As Byte
'        XoffChar As Byte
'        ErrorChar As Byte
'        EofChar As Byte
'        EvtChar As Byte
'end type

Public Type DCB
        DCBlength As Long
        BaudRate As Long
        fBitFields As Long 'See Comments in Win32API.Txt
        wReserved As Integer
        XonLim As Integer
        XoffLim As Integer
        ByteSize As Byte
        Parity As Byte
        StopBits As Byte
        XonChar As Byte
        XoffChar As Byte
        ErrorChar As Byte
        EofChar As Byte
        EvtChar As Byte
        wReserved1 As Integer 'Reserved; Do Not Use
End Type
' The fourteen actual DCB bit-sized data fields within the four bytes of fBitFields can be manipulated by bitwise logical And/Or operations.
' FieldName             Bit #     Description
' -----------------     -----     ------------------------------
' fBinary                 1       binary mode, no EOF check
' fParity                 2       enable parity checking
' fOutxCtsFlow            3       CTS output flow control
' fOutxDsrFlow            4       DSR output flow control
' fDtrControl             5       DTR flow control public type (2 bits)
' fDsrSensitivity         7       DSR sensitivity
' fTXContinueOnXoff       8       XOFF continues Tx
' fOutX                   9       XON/XOFF out flow control
' fInX                   10       XON/XOFF in flow control
' fErrorChar             11       enable error replacement
' fNull                  12       enable null stripping
' fRtsControl            13       RTS flow control (2 bits)
' fAbortOnError          15       abort reads/writes on error
' fDummy2                16       reserved

Public Type COMMTIMEOUTS
        ReadIntervalTimeout As Long
        ReadTotalTimeoutMultiplier As Long
        ReadTotalTimeoutConstant As Long
        WriteTotalTimeoutMultiplier As Long
        WriteTotalTimeoutConstant As Long
End Type

Public Type SYSTEM_INFO
        dwOemID As Long
        dwPageSize As Long
        lpMinimumApplicationAddress As Long
        lpMaximumApplicationAddress As Long
        dwActiveProcessorMask As Long
        dwNumberOrfProcessors As Long
        dwProcessorType As Long
        dwAllocationGranularity As Long
        dwReserved As Long
End Type

' Global Memory Flags
Public Const GMEM_FIXED = &H0
Public Const GMEM_MOVEABLE = &H2
Public Const GMEM_NOCOMPACT = &H10
Public Const GMEM_NODISCARD = &H20
Public Const GMEM_ZEROINIT = &H40
Public Const GMEM_MODIFY = &H80
Public Const GMEM_DISCARDABLE = &H100
Public Const GMEM_NOT_BANKED = &H1000
Public Const GMEM_SHARE = &H2000
Public Const GMEM_DDESHARE = &H2000
Public Const GMEM_NOTIFY = &H4000
Public Const GMEM_LOWER = GMEM_NOT_BANKED
Public Const GMEM_VALID_FLAGS = &H7F72
Public Const GMEM_INVALID_HANDLE = &H8000

Public Const GHND = (GMEM_MOVEABLE Or GMEM_ZEROINIT)
Public Const GPTR = (GMEM_FIXED Or GMEM_ZEROINIT)

' Flags returned by GlobalFlags (in addition to GMEM_DISCARDABLE)
Public Const GMEM_DISCARDED = &H4000
Public Const GMEM_LOCKCOUNT = &HFF

Public Type MEMORYSTATUS
        dwLength As Long
        dwMemoryLoad As Long
        dwTotalPhys As Long
        dwAvailPhys As Long
        dwTotalPageFile As Long
        dwAvailPageFile As Long
        dwTotalVirtual As Long
        dwAvailVirtual As Long
End Type

' Local Memory Flags
Public Const LMEM_FIXED = &H0
Public Const LMEM_MOVEABLE = &H2
Public Const LMEM_NOCOMPACT = &H10
Public Const LMEM_NODISCARD = &H20
Public Const LMEM_ZEROINIT = &H40
Public Const LMEM_MODIFY = &H80
Public Const LMEM_DISCARDABLE = &HF00
Public Const LMEM_VALID_FLAGS = &HF72
Public Const LMEM_INVALID_HANDLE = &H8000

Public Const LHND = (LMEM_MOVEABLE + LMEM_ZEROINIT)
Public Const LPTR = (LMEM_FIXED + LMEM_ZEROINIT)

Public Const NONZEROLHND = (LMEM_MOVEABLE)
Public Const NONZEROLPTR = (LMEM_FIXED)

' Flags returned by LocalFlags (in addition to LMEM_DISCARDABLE)
Public Const LMEM_DISCARDED = &H4000
Public Const LMEM_LOCKCOUNT = &HFF

'  dwCreationFlag values

Public Const DEBUG_PROCESS = &H1
Public Const DEBUG_ONLY_THIS_PROCESS = &H2

Public Const CREATE_SUSPENDED = &H4

Public Const DETACHED_PROCESS = &H8

Public Const CREATE_NEW_CONSOLE = &H10

Public Const NORMAL_PRIORITY_CLASS = &H20
Public Const IDLE_PRIORITY_CLASS = &H40
Public Const HIGH_PRIORITY_CLASS = &H80
Public Const REALTIME_PRIORITY_CLASS = &H100

Public Const CREATE_NEW_PROCESS_GROUP = &H200

Public Const CREATE_NO_WINDOW = &H8000000

Public Const PROFILE_USER = &H10000000
Public Const PROFILE_KERNEL = &H20000000
Public Const PROFILE_SERVER = &H40000000

Public Const MAXLONG = &H7FFFFFFF
Public Const THREAD_BASE_PRIORITY_MIN = -2
Public Const THREAD_BASE_PRIORITY_MAX = 2
Public Const THREAD_BASE_PRIORITY_LOWRT = 15
Public Const THREAD_BASE_PRIORITY_IDLE = -15
Public Const THREAD_PRIORITY_LOWEST = THREAD_BASE_PRIORITY_MIN
Public Const THREAD_PRIORITY_BELOW_NORMAL = (THREAD_PRIORITY_LOWEST + 1)
Public Const THREAD_PRIORITY_NORMAL = 0
Public Const THREAD_PRIORITY_HIGHEST = THREAD_BASE_PRIORITY_MAX
Public Const THREAD_PRIORITY_ABOVE_NORMAL = (THREAD_PRIORITY_HIGHEST - 1)
Public Const THREAD_PRIORITY_ERROR_RETURN = (MAXLONG)

Public Const THREAD_PRIORITY_TIME_CRITICAL = THREAD_BASE_PRIORITY_LOWRT
Public Const THREAD_PRIORITY_IDLE = THREAD_BASE_PRIORITY_IDLE

' Line 616


' ++ BUILD Version: 0093     Increment this if a change has global effects

' Copyright (c) 1990-1995  Microsoft Corporation

' Module Name:

'     winnt.h

' Abstract:

'     This module defines the 32-Bit Windows types and constants that are
'     defined by NT, but exposed through the Win32 API.

' Revision History:
Public Const APPLICATION_ERROR_MASK = &H20000000
Public Const ERROR_SEVERITY_SUCCESS = &H0
Public Const ERROR_SEVERITY_INFORMATIONAL = &H40000000
Public Const ERROR_SEVERITY_WARNING = &H80000000
Public Const ERROR_SEVERITY_ERROR = &HC0000000


Public Const MINCHAR = &H80
Public Const MAXCHAR = &H7F
Public Const MINSHORT = &H8000
Public Const MAXSHORT = &H7FFF
Public Const MINLONG = &H80000000
Public Const MAXByte = &HFF
Public Const MAXWORD = &HFFFF
Public Const MAXDWORD = &HFFFF
'
'  Calculate the byte offset of a field in a structure of type type.
'  *  Language IDs.
'  *
'  *  The following two combinations of primary language ID and
'  *  sublanguage ID have special semantics:
'  *
'  *    Primary Language ID   Sublanguage ID      Result
'  *    -------------------   ---------------     ------------------------
'  *    LANG_NEUTRAL          SUBLANG_NEUTRAL     Language neutral
'  *    LANG_NEUTRAL          SUBLANG_DEFAULT     User default language
'  *    LANG_NEUTRAL          SUBLANG_SYS_DEFAULT System default language
'  */
'
'  *  Primary language IDs.
'  */
Public Const LANG_NEUTRAL = &H0

Public Const LANG_BULGARIAN = &H2
Public Const LANG_CHINESE = &H4
Public Const LANG_CROATIAN = &H1A
Public Const LANG_CZECH = &H5
Public Const LANG_DANISH = &H6
Public Const LANG_DUTCH = &H13
Public Const LANG_ENGLISH = &H9
Public Const LANG_FINNISH = &HB
Public Const LANG_FRENCH = &HC
Public Const LANG_GERMAN = &H7
Public Const LANG_GREEK = &H8
Public Const LANG_HUNGARIAN = &HE
Public Const LANG_ICELANDIC = &HF
Public Const LANG_ITALIAN = &H10
Public Const LANG_JAPANESE = &H11
Public Const LANG_KOREAN = &H12
Public Const LANG_NORWEGIAN = &H14
Public Const LANG_POLISH = &H15
Public Const LANG_PORTUGUESE = &H16
Public Const LANG_ROMANIAN = &H18
Public Const LANG_RUSSIAN = &H19
Public Const LANG_SLOVAK = &H1B
Public Const LANG_SLOVENIAN = &H24
Public Const LANG_SPANISH = &HA
Public Const LANG_SWEDISH = &H1D
Public Const LANG_TURKISH = &H1F

'
'  *  Sublanguage IDs.
'  *
'  *  The name immediately following SUBLANG_ dictates which primary
'  *  language ID that sublanguage ID can be combined with to form a
'  *  valid language ID.
'  */
Public Const SUBLANG_NEUTRAL = &H0                       '  language neutral
Public Const SUBLANG_DEFAULT = &H1                       '  user default
Public Const SUBLANG_SYS_DEFAULT = &H2                   '  system default

Public Const SUBLANG_CHINESE_TRADITIONAL = &H1           '  Chinese (Taiwan)
Public Const SUBLANG_CHINESE_SIMPLIFIED = &H2            '  Chinese (PR China)
Public Const SUBLANG_CHINESE_HONGKONG = &H3              '  Chinese (Hong Kong)
Public Const SUBLANG_CHINESE_SINGAPORE = &H4             '  Chinese (Singapore)
Public Const SUBLANG_DUTCH = &H1                         '  Dutch
Public Const SUBLANG_DUTCH_BELGIAN = &H2                 '  Dutch (Belgian)
Public Const SUBLANG_ENGLISH_US = &H1                    '  English (USA)
Public Const SUBLANG_ENGLISH_UK = &H2                    '  English (UK)
Public Const SUBLANG_ENGLISH_AUS = &H3                   '  English (Australian)
Public Const SUBLANG_ENGLISH_CAN = &H4                   '  English (Canadian)
Public Const SUBLANG_ENGLISH_NZ = &H5                    '  English (New Zealand)
Public Const SUBLANG_ENGLISH_EIRE = &H6                  '  English (Irish)
Public Const SUBLANG_FRENCH = &H1                        '  French
Public Const SUBLANG_FRENCH_BELGIAN = &H2                '  French (Belgian)
Public Const SUBLANG_FRENCH_CANADIAN = &H3               '  French (Canadian)
Public Const SUBLANG_FRENCH_SWISS = &H4                  '  French (Swiss)
Public Const SUBLANG_GERMAN = &H1                        '  German
Public Const SUBLANG_GERMAN_SWISS = &H2                  '  German (Swiss)
Public Const SUBLANG_GERMAN_AUSTRIAN = &H3               '  German (Austrian)
Public Const SUBLANG_ITALIAN = &H1                       '  Italian
Public Const SUBLANG_ITALIAN_SWISS = &H2                 '  Italian (Swiss)
Public Const SUBLANG_NORWEGIAN_BOKMAL = &H1              '  Norwegian (Bokma
Public Const SUBLANG_NORWEGIAN_NYNORSK = &H2             '  Norwegian (Nynorsk)
Public Const SUBLANG_PORTUGUESE = &H2                    '  Portuguese
Public Const SUBLANG_PORTUGUESE_BRAZILIAN = &H1          '  Portuguese (Brazilian)
Public Const SUBLANG_SPANISH = &H1                       '  Spanish (Castilian)
Public Const SUBLANG_SPANISH_MEXICAN = &H2               '  Spanish (Mexican)
Public Const SUBLANG_SPANISH_MODERN = &H3                '  Spanish (Modern)

'
'  *  Sorting IDs.
'  *
'  */
Public Const SORT_DEFAULT = &H0                          '  sorting default

Public Const SORT_JAPANESE_XJIS = &H0                    '  Japanese0xJIS order
Public Const SORT_JAPANESE_UNICODE = &H1                 '  Japanese Unicode order

Public Const SORT_CHINESE_BIG5 = &H0                     '  Chinese BIG5 order
Public Const SORT_CHINESE_UNICODE = &H1                  '  Chinese Unicode order

Public Const SORT_KOREAN_KSC = &H0                       '  Korean KSC order
Public Const SORT_KOREAN_UNICODE = &H1                   '  Korean Unicode order

'  The FILE_READ_DATA and FILE_WRITE_DATA constants are also defined in
'  devioctl.h as FILE_READ_ACCESS and FILE_WRITE_ACCESS. The values for these
'  constants *MUST* always be in sync.
'  The values are redefined in devioctl.h because they must be available to
'  both DOS and NT.
'

Public Const FILE_READ_DATA = (&H1)                     '  file pipe
Public Const FILE_LIST_DIRECTORY = (&H1)                '  directory

Public Const FILE_WRITE_DATA = (&H2)                    '  file pipe
Public Const FILE_ADD_FILE = (&H2)                      '  directory

Public Const FILE_APPEND_DATA = (&H4)                   '  file
Public Const FILE_ADD_SUBDIRECTORY = (&H4)              '  directory
Public Const FILE_CREATE_PIPE_INSTANCE = (&H4)          '  named pipe

Public Const FILE_READ_EA = (&H8)                       '  file directory
Public Const FILE_READ_PROPERTIES = FILE_READ_EA

Public Const FILE_WRITE_EA = (&H10)                     '  file directory
Public Const FILE_WRITE_PROPERTIES = FILE_WRITE_EA

Public Const FILE_EXECUTE = (&H20)                      '  file
Public Const FILE_TRAVERSE = (&H20)                     '  directory

Public Const FILE_DELETE_CHILD = (&H40)                 '  directory

Public Const FILE_READ_ATTRIBUTES = (&H80)              '  all

Public Const FILE_WRITE_ATTRIBUTES = (&H100)            '  all

Public Const FILE_ALL_ACCESS = (STANDARD_RIGHTS_REQUIRED Or SYNCHRONIZE Or &H1FF)

Public Const FILE_GENERIC_READ = (STANDARD_RIGHTS_READ Or FILE_READ_DATA Or FILE_READ_ATTRIBUTES Or FILE_READ_EA Or SYNCHRONIZE)


Public Const FILE_GENERIC_WRITE = (STANDARD_RIGHTS_WRITE Or FILE_WRITE_DATA Or FILE_WRITE_ATTRIBUTES Or FILE_WRITE_EA Or FILE_APPEND_DATA Or SYNCHRONIZE)


Public Const FILE_GENERIC_EXECUTE = (STANDARD_RIGHTS_EXECUTE Or FILE_READ_ATTRIBUTES Or FILE_EXECUTE Or SYNCHRONIZE)

Public Const FILE_SHARE_READ = &H1
Public Const FILE_SHARE_WRITE = &H2
Public Const FILE_ATTRIBUTE_READONLY = &H1
Public Const FILE_ATTRIBUTE_HIDDEN = &H2
Public Const FILE_ATTRIBUTE_SYSTEM = &H4
Public Const FILE_ATTRIBUTE_DIRECTORY = &H10
Public Const FILE_ATTRIBUTE_ARCHIVE = &H20
Public Const FILE_ATTRIBUTE_NORMAL = &H80
Public Const FILE_ATTRIBUTE_TEMPORARY = &H100
Public Const FILE_ATTRIBUTE_COMPRESSED = &H800
Public Const FILE_NOTIFY_CHANGE_FILE_NAME = &H1
Public Const FILE_NOTIFY_CHANGE_DIR_NAME = &H2
Public Const FILE_NOTIFY_CHANGE_ATTRIBUTES = &H4
Public Const FILE_NOTIFY_CHANGE_SIZE = &H8
Public Const FILE_NOTIFY_CHANGE_LAST_WRITE = &H10
Public Const FILE_NOTIFY_CHANGE_SECURITY = &H100
Public Const MAILSLOT_NO_MESSAGE = (-1)
Public Const MAILSLOT_WAIT_FOREVER = (-1)
Public Const FILE_CASE_SENSITIVE_SEARCH = &H1
Public Const FILE_CASE_PRESERVED_NAMES = &H2
Public Const FILE_UNICODE_ON_DISK = &H4
Public Const FILE_PERSISTENT_ACLS = &H8
Public Const FILE_FILE_COMPRESSION = &H10
Public Const FILE_VOLUME_IS_COMPRESSED = &H8000
Public Const IO_COMPLETION_MODIFY_STATE = &H2
Public Const IO_COMPLETION_ALL_ACCESS = (STANDARD_RIGHTS_REQUIRED Or SYNCHRONIZE Or &H3)
Public Const DUPLICATE_CLOSE_SOURCE = &H1
Public Const DUPLICATE_SAME_ACCESS = &H2

' //////////////////////////////////////////////////////////////////////
'                                                                     //
'                              ACCESS MASK                            //
'                                                                     //
' //////////////////////////////////////////////////////////////////////

'
'   Define the access mask as a longword sized structure divided up as
'   follows:

'       typedef struct _ACCESS_MASK {
'           WORD   SpecificRights;
'           Byte  StandardRights;
'           Byte  AccessSystemAcl : 1;
'           Byte  Reserved : 3;
'           Byte  GenericAll : 1;
'           Byte  GenericExecute : 1;
'           Byte  GenericWrite : 1;
'           Byte  GenericRead : 1;
'       } ACCESS_MASK;
'       typedef ACCESS_MASK *PACCESS_MASK;
'
'   but to make life simple for programmer's we'll allow them to specify
'   a desired access mask by simply OR'ing together mulitple single rights
'   and treat an access mask as a DWORD.  For example
'
'       DesiredAccess = DELETE  Or  READ_CONTROL
'
'   So we'll declare ACCESS_MASK as DWORD
'

'  begin_ntddk begin_nthal begin_ntifs

' //////////////////////////////////////////////////////////////////////
'                                                                     //
'                              ACCESS TYPES                           //
'                                                                     //
' //////////////////////////////////////////////////////////////////////


'  begin_ntddk begin_nthal begin_ntifs
'
'   The following are masks for the predefined standard access types

'  AccessSystemAcl access type

Public Const ACCESS_SYSTEM_SECURITY = &H1000000

'  MaximumAllowed access type

Public Const MAXIMUM_ALLOWED = &H2000000

'   These are the generic rights.

Public Const GENERIC_READ = &H80000000
Public Const GENERIC_WRITE = &H40000000
Public Const GENERIC_EXECUTE = &H20000000
Public Const GENERIC_ALL = &H10000000

'   Define the generic mapping array.  This is used to denote the
'   mapping of each generic access right to a specific access mask.

Type GENERIC_MAPPING
        GenericRead As Long
        GenericWrite As Long
        GenericExecute As Long
        GenericAll As Long
End Type


' //////////////////////////////////////////////////////////////////////
'                                                                     //
'                         LUID_AND_ATTRIBUTES                         //
'                                                                     //
' //////////////////////////////////////////////////////////////////////
'
Type Luid
        lowpart As Long
        highpart As Long
End Type


Type LUID_AND_ATTRIBUTES
        pLuid As Luid
        Attributes As Long
End Type

' //////////////////////////////////////////////////////////////////////
'                                                                     //
'                          ACL  and  ACE                              //
'                                                                     //
' //////////////////////////////////////////////////////////////////////

'
'   Define an ACL and the ACE format.  The structure of an ACL header
'   followed by one or more ACEs.  Pictorally the structure of an ACL header
'   is as follows:
'
'   The current AclRevision is defined to be ACL_REVISION.
'
'   AclSize is the size, in bytes, allocated for the ACL.  This includes
'   the ACL header, ACES, and remaining free space in the buffer.
'
'   AceCount is the number of ACES in the ACL.
'

'  begin_ntddk begin_ntifs
'  This is the *current* ACL revision

Public Const ACL_REVISION = (2)

'  This is the history of ACL revisions.  Add a new one whenever
'  ACL_REVISION is updated

Public Const ACL_REVISION1 = (1)
Public Const ACL_REVISION2 = (2)

Type ACL
        AclRevision As Byte
        Sbz1 As Byte
        AclSize As Integer
        AceCount As Integer
        Sbz2 As Integer
End Type

' typedef ACL *PACL;

'  end_ntddk

'   The structure of an ACE is a common ace header followed by ace type
'   specific data.  Pictorally the structure of the common ace header is
'   as follows:

'   AceType denotes the type of the ace, there are some predefined ace
'   types
'
'   AceSize is the size, in bytes, of ace.
'
'   AceFlags are the Ace flags for audit and inheritance, defined Integerly.

Type ACE_HEADER
        AceType As Byte
        AceFlags As Byte
        AceSize As Long
End Type
'
'   The following are the predefined ace types that go into the AceType
'   field of an Ace header.

Public Const ACCESS_ALLOWED_ACE_TYPE = &H0
Public Const ACCESS_DENIED_ACE_TYPE = &H1
Public Const SYSTEM_AUDIT_ACE_TYPE = &H2
Public Const SYSTEM_ALARM_ACE_TYPE = &H3

'   The following are the inherit flags that go into the AceFlags field
'   of an Ace header.

Public Const OBJECT_INHERIT_ACE = &H1
Public Const CONTAINER_INHERIT_ACE = &H2
Public Const NO_PROPAGATE_INHERIT_ACE = &H4
Public Const INHERIT_ONLY_ACE = &H8
Public Const VALID_INHERIT_FLAGS = &HF


'   The following are the currently defined ACE flags that go into the
'   AceFlags field of an ACE header.  Each ACE type has its own set of
'   AceFlags.
'
'   SUCCESSFUL_ACCESS_ACE_FLAG - used only with system audit and alarm ACE
'   types to indicate that a message is generated for successful accesses.
'
'   FAILED_ACCESS_ACE_FLAG - used only with system audit and alarm ACE types
'   to indicate that a message is generated for failed accesses.

'   SYSTEM_AUDIT and SYSTEM_ALARM AceFlags
'
'   These control the signaling of audit and alarms for success or failure.

Public Const SUCCESSFUL_ACCESS_ACE_FLAG = &H40
Public Const FAILED_ACCESS_ACE_FLAG = &H80


'
'   We'll define the structure of the predefined ACE types.  Pictorally
'   the structure of the predefined ACE's is as follows:

'   Mask is the access mask associated with the ACE.  This is either the
'   access allowed, access denied, audit, or alarm mask.
'
'   Sid is the Sid associated with the ACE.
'
'   The following are the four predefined ACE types.
'   Examine the AceType field in the Header to determine
'   which structure is appropriate to use for casting.


Type ACCESS_ALLOWED_ACE
        Header As ACE_HEADER
        Mask As Long
        SidStart As Long
End Type

Type ACCESS_DENIED_ACE
        Header As ACE_HEADER
        Mask As Long
        SidStart As Long
End Type


Type SYSTEM_AUDIT_ACE
        Header As ACE_HEADER
        Mask As Long
        SidStart As Long
End Type

Type SYSTEM_ALARM_ACE
        Header As ACE_HEADER
        Mask As Long
        SidStart As Long
End Type

'   The following declarations are used for setting and querying information
'   about and ACL.  First are the various information classes available to
'   the user.
'

Public Const AclRevisionInformation = 1
Public Const AclSizeInformation = 2
'
'   This record is returned/sent if the user is requesting/setting the
'   AclRevisionInformation
'

Type ACL_REVISION_INFORMATION
        AclRevision As Long
End Type

'
'   This record is returned if the user is requesting AclSizeInformation
'

Type ACL_SIZE_INFORMATION
        AceCount As Long
        AclBytesInUse As Long
        AclBytesFree As Long
End Type

' //////////////////////////////////////////////////////////////////////
'                                                                     //
'                              SECURITY_DESCRIPTOR                    //
'                                                                     //
' //////////////////////////////////////////////////////////////////////
'
'   Define the Security Descriptor and related data types.
'   This is an opaque data structure.
'

'  begin_ntddk begin_ntifs
'
'  Current security descriptor revision value
'

Public Const SECURITY_DESCRIPTOR_REVISION = (1)
Public Const SECURITY_DESCRIPTOR_REVISION1 = (1)

'  end_ntddk

'
'  Minimum length, in bytes, needed to build a security descriptor
'  (NOTE: This must manually be kept consistent with the)
'  (sizeof(SECURITY_DESCRIPTOR)                         )
'

Public Const SECURITY_DESCRIPTOR_MIN_LENGTH = (20)



Public Const SE_OWNER_DEFAULTED = &H1
Public Const SE_GROUP_DEFAULTED = &H2
Public Const SE_DACL_PRESENT = &H4
Public Const SE_DACL_DEFAULTED = &H8
Public Const SE_SACL_PRESENT = &H10
Public Const SE_SACL_DEFAULTED = &H20
Public Const SE_SELF_RELATIVE = &H8000

'
'   Where:
'
'       SE_OWNER_DEFAULTED - This boolean flag, when set, indicates that the
'           SID pointed to by the Owner field was provided by a
'           defaulting mechanism rather than explicitly provided by the
'           original provider of the security descriptor.  This may
'           affect the treatment of the SID with respect to inheritence
'           of an owner.
'
'       SE_GROUP_DEFAULTED - This boolean flag, when set, indicates that the
'           SID in the Group field was provided by a defaulting mechanism
'           rather than explicitly provided by the original provider of
'           the security descriptor.  This may affect the treatment of
'           the SID with respect to inheritence of a primary group.
'
'       SE_DACL_PRESENT - This boolean flag, when set, indicates that the
'           security descriptor contains a discretionary ACL.  If this
'           flag is set and the Dacl field of the SECURITY_DESCRIPTOR is
'           null, then a null ACL is explicitly being specified.
'
'       SE_DACL_DEFAULTED - This boolean flag, when set, indicates that the
'           ACL pointed to by the Dacl field was provided by a defaulting
'           mechanism rather than explicitly provided by the original
'           provider of the security descriptor.  This may affect the
'           treatment of the ACL with respect to inheritence of an ACL.
'           This flag is ignored if the DaclPresent flag is not set.
'
'       SE_SACL_PRESENT - This boolean flag, when set,  indicates that the
'           security descriptor contains a system ACL pointed to by the
'           Sacl field.  If this flag is set and the Sacl field of the
'           SECURITY_DESCRIPTOR is null, then an empty (but present)
'           ACL is being specified.
'
'       SE_SACL_DEFAULTED - This boolean flag, when set, indicates that the
'           ACL pointed to by the Sacl field was provided by a defaulting
'           mechanism rather than explicitly provided by the original
'           provider of the security descriptor.  This may affect the
'           treatment of the ACL with respect to inheritence of an ACL.
'           This flag is ignored if the SaclPresent flag is not set.
'
'       SE_SELF_RELATIVE - This boolean flag, when set, indicates that the
'           security descriptor is in self-relative form.  In this form,
'           all fields of the security descriptor are contiguous in memory
'           and all pointer fields are expressed as offsets from the
'           beginning of the security descriptor.  This form is useful
'           for treating security descriptors as opaque data structures
'           for transmission in communication protocol or for storage on
'           secondary media.
'
'
'
'  In general, this data structure should be treated opaquely to ensure future
'  compatibility.
'
'

Type SECURITY_DESCRIPTOR
        Revision As Byte
        Sbz1 As Byte
        Control As Long
        Owner As Long
        Group As Long
        Sacl As ACL
        Dacl As ACL
End Type


'  Where:
'
'      Revision - Contains the revision level of the security
'          descriptor.  This allows this structure to be passed between
'          systems or stored on disk even though it is expected to
'          change in the future.
'
'      Control - A set of flags which qualify the meaning of the
'          security descriptor or individual fields of the security
'          descriptor.
'
'      Owner - is a pointer to an SID representing an object's owner.
'          If this field is null, then no owner SID is present in the
'          security descriptor.  If the security descriptor is in
'          self-relative form, then this field contains an offset to
'          the SID, rather than a pointer.
'
'      Group - is a pointer to an SID representing an object's primary
'          group.  If this field is null, then no primary group SID is
'          present in the security descriptor.  If the security descriptor
'          is in self-relative form, then this field contains an offset to
'          the SID, rather than a pointer.
'
'      Sacl - is a pointer to a system ACL.  This field value is only
'          valid if the DaclPresent control flag is set.  If the
'          SaclPresent flag is set and this field is null, then a null
'          ACL  is specified.  If the security descriptor is in
'          self-relative form, then this field contains an offset to
'          the ACL, rather than a pointer.
'
'      Dacl - is a pointer to a discretionary ACL.  This field value is
'          only valid if the DaclPresent control flag is set.  If the
'          DaclPresent flag is set and this field is null, then a null
'          ACL (unconditionally granting access) is specified.  If the
'          security descriptor is in self-relative form, then this field
'          contains an offset to the ACL, rather than a pointer.
'



' //////////////////////////////////////////////////////////////////////
'                                                                     //
'                Privilege Related Data Structures                    //
'                                                                     //
' //////////////////////////////////////////////////////////////////////


'  Privilege attributes
'

Public Const SE_PRIVILEGE_ENABLED_BY_DEFAULT = &H1
Public Const SE_PRIVILEGE_ENABLED = &H2
Public Const SE_PRIVILEGE_USED_FOR_ACCESS = &H80000000

'
'  Privilege Set Control flags
'

Public Const PRIVILEGE_SET_ALL_NECESSARY = (1)

'
'   Privilege Set - This is defined for a privilege set of one.
'                   If more than one privilege is needed, then this structure
'                   will need to be allocated with more space.
'
'   Note: don't change this structure without fixing the INITIAL_PRIVILEGE_SET
'   structure (defined in se.h)
'

Type PRIVILEGE_SET
        PrivilegeCount As Long
        Control As Long
        Privilege(ANYSIZE_ARRAY) As LUID_AND_ATTRIBUTES
End Type


'//////////////////////////////////////////////////////////////////////
'                                                                     //
'                NT Defined Privileges                                //
'                                                                     //
' //////////////////////////////////////////////////////////////////////

Public Const SE_CREATE_TOKEN_NAME = "SeCreateTokenPrivilege"
Public Const SE_ASSIGNPRIMARYTOKEN_NAME = "SeAssignPrimaryTokenPrivilege"
Public Const SE_LOCK_MEMORY_NAME = "SeLockMemoryPrivilege"
Public Const SE_INCREASE_QUOTA_NAME = "SeIncreaseQuotaPrivilege"
Public Const SE_UNSOLICITED_INPUT_NAME = "SeUnsolicitedInputPrivilege"
Public Const SE_MACHINE_ACCOUNT_NAME = "SeMachineAccountPrivilege"
Public Const SE_TCB_NAME = "SeTcbPrivilege"
Public Const SE_SECURITY_NAME = "SeSecurityPrivilege"
Public Const SE_TAKE_OWNERSHIP_NAME = "SeTakeOwnershipPrivilege"
Public Const SE_LOAD_DRIVER_NAME = "SeLoadDriverPrivilege"
Public Const SE_SYSTEM_PROFILE_NAME = "SeSystemProfilePrivilege"
Public Const SE_SYSTEMTIME_NAME = "SeSystemtimePrivilege"
Public Const SE_PROF_SINGLE_PROCESS_NAME = "SeProfileSingleProcessPrivilege"
Public Const SE_INC_BASE_PRIORITY_NAME = "SeIncreaseBasePriorityPrivilege"
Public Const SE_CREATE_PAGEFILE_NAME = "SeCreatePagefilePrivilege"
Public Const SE_CREATE_PERMANENT_NAME = "SeCreatePermanentPrivilege"
Public Const SE_BACKUP_NAME = "SeBackupPrivilege"
Public Const SE_RESTORE_NAME = "SeRestorePrivilege"
Public Const SE_SHUTDOWN_NAME = "SeShutdownPrivilege"
Public Const SE_DEBUG_NAME = "SeDebugPrivilege"
Public Const SE_AUDIT_NAME = "SeAuditPrivilege"
Public Const SE_SYSTEM_ENVIRONMENT_NAME = "SeSystemEnvironmentPrivilege"
Public Const SE_CHANGE_NOTIFY_NAME = "SeChangeNotifyPrivilege"
Public Const SE_REMOTE_SHUTDOWN_NAME = "SeRemoteShutdownPrivilege"


' //////////////////////////////////////////////////////////////////
'                                                                 //
'            Security Quality Of Service                          //
'                                                                 //
'                                                                 //
' //////////////////////////////////////////////////////////////////

'  begin_ntddk begin_nthal begin_ntifs
'
'  Impersonation Level
'
'  Impersonation level is represented by a pair of bits in Windows.
'  If a new impersonation level is added or lowest value is changed from
'  0 to something else, fix the Windows CreateFile call.
'

Public Const SecurityAnonymous = 1
Public Const SecurityIdentification = 2

'//////////////////////////////////////////////////////////////////////
'                                                                     //
'                Registry API Constants                                //
'                                                                     //
' //////////////////////////////////////////////////////////////////////

' Reg Data Types...
Public Const REG_NONE = 0                       ' No value type
Public Const REG_SZ = 1                         ' Unicode nul terminated string
Public Const REG_EXPAND_SZ = 2                  ' Unicode nul terminated string
Public Const REG_BINARY = 3                     ' Free form binary
Public Const REG_DWORD = 4                      ' 32-bit number
Public Const REG_DWORD_LITTLE_ENDIAN = 4        ' 32-bit number (same as REG_DWORD)
Public Const REG_DWORD_BIG_ENDIAN = 5           ' 32-bit number
Public Const REG_LINK = 6                       ' Symbolic Link (unicode)
Public Const REG_MULTI_SZ = 7                   ' Multiple Unicode strings
Public Const REG_RESOURCE_LIST = 8              ' Resource list in the resource map
Public Const REG_FULL_RESOURCE_DESCRIPTOR = 9   ' Resource list in the hardware description
Public Const REG_RESOURCE_REQUIREMENTS_LIST = 10
Public Const REG_CREATED_NEW_KEY = &H1                      ' New Registry Key created
Public Const REG_OPENED_EXISTING_KEY = &H2                      ' Existing Key opened
Public Const REG_WHOLE_HIVE_VOLATILE = &H1                      ' Restore whole hive volatile
Public Const REG_REFRESH_HIVE = &H2                      ' Unwind changes to last flush
Public Const REG_NOTIFY_CHANGE_NAME = &H1                      ' Create or delete (child)
Public Const REG_NOTIFY_CHANGE_ATTRIBUTES = &H2
Public Const REG_NOTIFY_CHANGE_LAST_SET = &H4                      ' Time stamp
Public Const REG_NOTIFY_CHANGE_SECURITY = &H8
Public Const REG_LEGAL_CHANGE_FILTER = (REG_NOTIFY_CHANGE_NAME Or REG_NOTIFY_CHANGE_ATTRIBUTES Or REG_NOTIFY_CHANGE_LAST_SET Or REG_NOTIFY_CHANGE_SECURITY)
'public const REG_LEGAL_OPTION = (REG_OPTION_RESERVED Or REG_OPTION_NON_VOLATILE Or REG_OPTION_VOLATILE Or REG_OPTION_CREATE_LINK Or REG_OPTION_BACKUP_RESTORE)

' Reg Create Type Values...
Public Const REG_OPTION_RESERVED = 0           ' Parameter is reserved
Public Const REG_OPTION_NON_VOLATILE = 0       ' Key is preserved when system is rebooted
Public Const REG_OPTION_VOLATILE = 1           ' Key is not preserved when system is rebooted
Public Const REG_OPTION_CREATE_LINK = 2        ' Created key is a symbolic link
Public Const REG_OPTION_BACKUP_RESTORE = 4     ' open for backup or restore

' Reg Key Security Options
' public const READ_CONTROL = &H20000
Public Const KEY_QUERY_VALUE = &H1
Public Const KEY_SET_VALUE = &H2
Public Const KEY_CREATE_SUB_KEY = &H4
Public Const KEY_ENUMERATE_SUB_KEYS = &H8
Public Const KEY_NOTIFY = &H10
Public Const KEY_CREATE_LINK = &H20
Public Const KEY_READ = ((STANDARD_RIGHTS_READ Or KEY_QUERY_VALUE Or KEY_ENUMERATE_SUB_KEYS Or KEY_NOTIFY) And (Not SYNCHRONIZE))
Public Const KEY_WRITE = ((STANDARD_RIGHTS_WRITE Or KEY_SET_VALUE Or KEY_CREATE_SUB_KEY) And (Not SYNCHRONIZE))
Public Const KEY_ALL_ACCESS = ((STANDARD_RIGHTS_ALL Or KEY_QUERY_VALUE Or KEY_SET_VALUE Or KEY_CREATE_SUB_KEY Or KEY_ENUMERATE_SUB_KEYS Or KEY_NOTIFY Or KEY_CREATE_LINK) And (Not SYNCHRONIZE))
'public const STANDARD_RIGHTS_READ = (READ_CONTROL)
'public const STANDARD_RIGHTS_WRITE = (READ_CONTROL)
Public Const KEY_EXECUTE = ((KEY_READ) And (Not SYNCHRONIZE))

' end winnt.txt

' Debug APIs
' Line 1351

Public Const EXCEPTION_DEBUG_EVENT = 1
Public Const CREATE_THREAD_DEBUG_EVENT = 2
Public Const CREATE_PROCESS_DEBUG_EVENT = 3
Public Const EXIT_THREAD_DEBUG_EVENT = 4
Public Const EXIT_PROCESS_DEBUG_EVENT = 5
Public Const LOAD_DLL_DEBUG_EVENT = 6
Public Const UNLOAD_DLL_DEBUG_EVENT = 7
Public Const OUTPUT_DEBUG_STRING_EVENT = 8
Public Const RIP_EVENT = 9

Public Const EXCEPTION_MAXIMUM_PARAMETERS = 15

Type EXCEPTION_RECORD
    ExceptionCode As Long
    ExceptionFlags As Long
    pExceptionRecord As Long    ' Pointer to an EXCEPTION_RECORD structure
    ExceptionAddress As Long
    NumberParameters As Long
    ExceptionInformation(EXCEPTION_MAXIMUM_PARAMETERS) As Long
End Type

Type EXCEPTION_DEBUG_INFO
        pExceptionRecord As EXCEPTION_RECORD
        dwFirstChance As Long
End Type

Type CREATE_THREAD_DEBUG_INFO
        hThread As Long
        lpThreadLocalBase As Long
        lpStartAddress As Long
End Type

Type CREATE_PROCESS_DEBUG_INFO
        hFile As Long
        hProcess As Long
        hThread As Long
        lpBaseOfImage As Long
        dwDebugInfoFileOffset As Long
        nDebugInfoSize As Long
        lpThreadLocalBase As Long
        lpStartAddress As Long
        lpImageName As Long
        fUnicode As Integer
End Type

Type EXIT_THREAD_DEBUG_INFO
        dwExitCode As Long
End Type

Type EXIT_PROCESS_DEBUG_INFO
        dwExitCode As Long
End Type

Type LOAD_DLL_DEBUG_INFO
        hFile As Long
        lpBaseOfDll As Long
        dwDebugInfoFileOffset As Long
        nDebugInfoSize As Long
        lpImageName As Long
        fUnicode As Integer
End Type

Type UNLOAD_DLL_DEBUG_INFO
        lpBaseOfDll As Long
End Type

Type OUTPUT_DEBUG_STRING_INFO
        lpDebugStringData As String
        fUnicode As Integer
        nDebugStringLength As Integer
End Type

Type RIP_INFO
        dwError As Long
        dwType As Long
End Type

' GetDriveType return values
Public Const DRIVE_REMOVABLE = 2
Public Const DRIVE_FIXED = 3
Public Const DRIVE_REMOTE = 4
Public Const DRIVE_CDROM = 5
Public Const DRIVE_RAMDISK = 6

Public Const FILE_TYPE_UNKNOWN = &H0
Public Const FILE_TYPE_DISK = &H1
Public Const FILE_TYPE_CHAR = &H2
Public Const FILE_TYPE_PIPE = &H3
Public Const FILE_TYPE_REMOTE = &H8000

Public Const STD_INPUT_HANDLE = -10&
Public Const STD_OUTPUT_HANDLE = -11&
Public Const STD_ERROR_HANDLE = -12&

Public Const NOPARITY = 0
Public Const ODDPARITY = 1
Public Const EVENPARITY = 2
Public Const MARKPARITY = 3
Public Const SPACEPARITY = 4

Public Const ONESTOPBIT = 0
Public Const ONE5STOPBITS = 1
Public Const TWOSTOPBITS = 2

Public Const IGNORE = 0 '  Ignore signal
Public Const INFINITE = &HFFFF      '  Infinite timeout

' Comm Baud Rate indices
Public Const CBR_110 = 110
Public Const CBR_300 = 300
Public Const CBR_600 = 600
Public Const CBR_1200 = 1200
Public Const CBR_2400 = 2400
Public Const CBR_4800 = 4800
Public Const CBR_9600 = 9600
Public Const CBR_14400 = 14400
Public Const CBR_19200 = 19200
Public Const CBR_38400 = 38400
Public Const CBR_56000 = 56000
Public Const CBR_57600 = 57600
Public Const CBR_115200 = 115200
Public Const CBR_128000 = 128000
Public Const CBR_256000 = 256000

' Error Flags
Public Const CE_RXOVER = &H1                '  Receive Queue overflow
Public Const CE_OVERRUN = &H2               '  Receive Overrun Error
Public Const CE_RXPARITY = &H4              '  Receive Parity Error
Public Const CE_FRAME = &H8                 '  Receive Framing error
Public Const CE_BREAK = &H10                '  Break Detected
Public Const CE_TXFULL = &H100              '  TX Queue is full
Public Const CE_PTO = &H200                 '  LPTx Timeout
Public Const CE_IOE = &H400                 '  LPTx I/O Error
Public Const CE_DNS = &H800                 '  LPTx Device not selected
Public Const CE_OOP = &H1000                '  LPTx Out-Of-Paper
Public Const CE_MODE = &H8000               '  Requested mode unsupported

Public Const IE_BADID = (-1)                '  Invalid or unsupported id
Public Const IE_OPEN = (-2)                 '  Device Already Open
Public Const IE_NOPEN = (-3)                '  Device Not Open
Public Const IE_MEMORY = (-4)               '  Unable to allocate queues
Public Const IE_DEFAULT = (-5)              '  Error in default parameters
Public Const IE_HARDWARE = (-10)            '  Hardware Not Present
Public Const IE_BYTESIZE = (-11)            '  Illegal Byte Size
Public Const IE_BAUDRATE = (-12)            '  Unsupported BaudRate

' Events
Public Const EV_RXCHAR = &H1                '  Any Character received
Public Const EV_RXFLAG = &H2                '  Received certain character
Public Const EV_TXEMPTY = &H4               '  Transmitt Queue Empty
Public Const EV_CTS = &H8                   '  CTS changed state
Public Const EV_DSR = &H10                  '  DSR changed state
Public Const EV_RLSD = &H20                 '  RLSD changed state
Public Const EV_BREAK = &H40                '  BREAK received
Public Const EV_ERR = &H80                  '  Line status error occurred
Public Const EV_RING = &H100                '  Ring signal detected
Public Const EV_PERR = &H200                '  Printer error occured
Public Const EV_RX80FULL = &H400            '  Receive buffer is 80 percent full
Public Const EV_EVENT1 = &H800              '  Provider specific event 1
Public Const EV_EVENT2 = &H1000             '  Provider specific event 2

' Escape Functions
Public Const SETXOFF = 1  '  Simulate XOFF received
Public Const SETXON = 2 '  Simulate XON received
Public Const SETRTS = 3 '  Set RTS high
Public Const CLRRTS = 4 '  Set RTS low
Public Const SETDTR = 5 '  Set DTR high
Public Const CLRDTR = 6 '  Set DTR low
Public Const RESETDEV = 7       '  Reset device if possible
Public Const SETBREAK = 8  'Set the device break line
Public Const CLRBREAK = 9 ' Clear the device break line

'  PURGE function flags.
Public Const PURGE_TXABORT = &H1     '  Kill the pending/current writes to the comm port.
Public Const PURGE_RXABORT = &H2     '  Kill the pending/current reads to the comm port.
Public Const PURGE_TXCLEAR = &H4     '  Kill the transmit queue if there.
Public Const PURGE_RXCLEAR = &H8     '  Kill the typeahead buffer if there.

Public Const LPTx = &H80        '  Set if ID is for LPT device

'  Modem Status Flags
Public Const MS_CTS_ON = &H10&
Public Const MS_DSR_ON = &H20&
Public Const MS_RING_ON = &H40&
Public Const MS_RLSD_ON = &H80&

' WaitSoundState() Constants
Public Const S_QUEUEEMPTY = 0
Public Const S_THRESHOLD = 1
Public Const S_ALLTHRESHOLD = 2

' Accent Modes
Public Const S_NORMAL = 0
Public Const S_LEGATO = 1
Public Const S_STACCATO = 2

Public Const SECTION_QUERY = &H1
Public Const SECTION_MAP_WRITE = &H2
Public Const SECTION_MAP_READ = &H4
Public Const SECTION_MAP_EXECUTE = &H8
Public Const SECTION_EXTEND_SIZE = &H10
Public Const SECTION_ALL_ACCESS = STANDARD_RIGHTS_REQUIRED Or SECTION_QUERY Or SECTION_MAP_WRITE Or SECTION_MAP_READ Or SECTION_MAP_EXECUTE Or SECTION_EXTEND_SIZE

Public Const FILE_MAP_COPY = SECTION_QUERY
Public Const FILE_MAP_WRITE = SECTION_MAP_WRITE
Public Const FILE_MAP_READ = SECTION_MAP_READ
Public Const FILE_MAP_ALL_ACCESS = SECTION_ALL_ACCESS

' OpenFile() Flags
Public Const OF_READ = &H0
Public Const OF_WRITE = &H1
Public Const OF_READWRITE = &H2
Public Const OF_SHARE_COMPAT = &H0
Public Const OF_SHARE_EXCLUSIVE = &H10
Public Const OF_SHARE_DENY_WRITE = &H20
Public Const OF_SHARE_DENY_READ = &H30
Public Const OF_SHARE_DENY_NONE = &H40
Public Const OF_PARSE = &H100
Public Const OF_DELETE = &H200
Public Const OF_VERIFY = &H400
Public Const OF_CANCEL = &H800
Public Const OF_CREATE = &H1000
Public Const OF_PROMPT = &H2000
Public Const OF_EXIST = &H4000
Public Const OF_REOPEN = &H8000

Public Const OFS_MAXPATHNAME = 128

' OpenFile() Structure
Type OFSTRUCT
        cBytes As Byte
        fFixedDisk As Byte
        nErrCode As Integer
        Reserved1 As Integer
        Reserved2 As Integer
        szPathName(OFS_MAXPATHNAME) As Byte
End Type

Declare Sub CopyMemory Lib "kernel32" Alias "RtlMoveMemory" (Destination As Any, Source As Any, ByVal Length As Long)

Public Const PROCESSOR_INTEL_386 = 386
Public Const PROCESSOR_INTEL_486 = 486
Public Const PROCESSOR_INTEL_PENTIUM = 586
Public Const PROCESSOR_MIPS_R4000 = 4000
Public Const PROCESSOR_ALPHA_21064 = 21064
Public Const PROCESSOR_ARCHITECTURE_INTEL = 0
Public Const PROCESSOR_ARCHITECTURE_MIPS = 1
Public Const PROCESSOR_ARCHITECTURE_ALPHA = 2
Public Const PROCESSOR_ARCHITECTURE_PPC = 3
Public Const PROCESSOR_ARCHITECTURE_UNKNOWN = &HFFFF

Declare Function GetCurrentTime Lib "kernel32" Alias "GetTickCount" () As Long

' Flags for DrawFrameControl
Public Const DFC_CAPTION = 1
Public Const DFC_MENU = 2
Public Const DFC_SCROLL = 3
Public Const DFC_BUTTON = 4
Public Const DFCS_CAPTIONCLOSE = &H0
Public Const DFCS_CAPTIONMIN = &H1
Public Const DFCS_CAPTIONMAX = &H2
Public Const DFCS_CAPTIONRESTORE = &H3
Public Const DFCS_CAPTIONHELP = &H4
Public Const DFCS_MENUARROW = &H0
Public Const DFCS_MENUCHECK = &H1
Public Const DFCS_MENUBULLET = &H2
Public Const DFCS_MENUARROWRIGHT = &H4
Public Const DFCS_SCROLLUP = &H0
Public Const DFCS_SCROLLDOWN = &H1
Public Const DFCS_SCROLLLEFT = &H2
Public Const DFCS_SCROLLRIGHT = &H3
Public Const DFCS_SCROLLCOMBOBOX = &H5
Public Const DFCS_SCROLLSIZEGRIP = &H8
Public Const DFCS_SCROLLSIZEGRIPRIGHT = &H10
Public Const DFCS_BUTTONCHECK = &H0
Public Const DFCS_BUTTONRADIOIMAGE = &H1
Public Const DFCS_BUTTONRADIOMASK = &H2
Public Const DFCS_BUTTONRADIO = &H4
Public Const DFCS_BUTTON3STATE = &H8
Public Const DFCS_BUTTONPUSH = &H10
Public Const DFCS_INACTIVE = &H100
Public Const DFCS_PUSHED = &H200
Public Const DFCS_CHECKED = &H400
Public Const DFCS_ADJUSTRECT = &H2000
Public Const DFCS_FLAT = &H4000
Public Const DFCS_MONO = &H8000

Declare Function InterlockedIncrement Lib "kernel32" (lpAddend As Long) As Long
Declare Function InterlockedDecrement Lib "kernel32" (lpAddend As Long) As Long
Declare Function InterlockedExchange Lib "kernel32" (Target As Long, ByVal Value As Long) As Long

' Loader Routines
Declare Function GetModuleFileName Lib "kernel32" Alias "GetModuleFileNameA" (ByVal hModule As Long, ByVal lpFileName As String, ByVal nSize As Long) As Long
Declare Function GetModuleHandle Lib "kernel32" Alias "GetModuleHandleA" (ByVal lpModuleName As String) As Long

Declare Function CreateProcess Lib "kernel32" Alias "CreateProcessA" (ByVal lpApplicationName As String, ByVal lpCommandLine As String, lpProcessAttributes As SECURITY_ATTRIBUTES, lpThreadAttributes As SECURITY_ATTRIBUTES, ByVal bInheritHandles As Long, ByVal dwCreationFlags As Long, lpEnvironment As Any, ByVal lpCurrentDriectory As String, lpStartupInfo As STARTUPINFO, lpProcessInformation As PROCESS_INFORMATION) As Long

Declare Function SetProcessShutdownParameters Lib "kernel32" (ByVal dwLevel As Long, ByVal dwFlags As Long) As Long
Declare Function GetProcessShutdownParameters Lib "kernel32" (lpdwLevel As Long, lpdwFlags As Long) As Long

Declare Sub FatalAppExit Lib "kernel32" Alias "FatalAppExitA" (ByVal uAction As Long, ByVal lpMessageText As String)
Declare Sub GetStartupInfo Lib "kernel32" Alias "GetStartupInfoA" (lpStartupInfo As STARTUPINFO)
Declare Function GetCommandLine Lib "kernel32" Alias "GetCommandLineA" () As String
Declare Function GetEnvironmentVariable Lib "kernel32" Alias "GetEnvironmentVariableA" (ByVal lpName As String, ByVal lpBuffer As String, ByVal nSize As Long) As Long
Declare Function SetEnvironmentVariable Lib "kernel32" Alias "SetEnvironmentVariableA" (ByVal lpName As String, ByVal lpValue As String) As Long
Declare Function ExpandEnvironmentStrings Lib "kernel32" Alias "ExpandEnvironmentStringsA" (ByVal lpSrc As String, ByVal lpDst As String, ByVal nSize As Long) As Long

Declare Function LoadLibrary Lib "kernel32" Alias "LoadLibraryA" (ByVal lpLibFileName As String) As Long
Declare Function LoadLibraryEx Lib "kernel32" Alias "LoadLibraryExA" (ByVal lpLibFileName As String, ByVal hFile As Long, ByVal dwFlags As Long) As Long

Declare Function GetProcAddress Lib "kernel32" (ByVal hModule As Long, ByVal lpProcName As String) As Long

Public Const DONT_RESOLVE_DLL_REFERENCES = &H1

Declare Function LoadModule Lib "kernel32" (ByVal lpModuleName As String, lpParameterBlock As Any) As Long
Declare Function FreeLibrary Lib "kernel32" (ByVal hLibModule As Long) As Long
Declare Function WinExec Lib "kernel32" (ByVal lpCmdLine As String, ByVal nCmdShow As Long) As Long

Declare Sub DebugBreak Lib "kernel32" ()
Declare Function ContinueDebugEvent Lib "kernel32" (ByVal dwProcessId As Long, ByVal dwThreadId As Long, ByVal dwContinueStatus As Long) As Long
Declare Function DebugActiveProcess Lib "kernel32" (ByVal dwProcessId As Long) As Long

Type CRITICAL_SECTION
        dummy As Long
End Type

Declare Sub InitializeCriticalSection Lib "kernel32" (lpCriticalSection As CRITICAL_SECTION)

Declare Sub EnterCriticalSection Lib "kernel32" (lpCriticalSection As CRITICAL_SECTION)
Declare Sub LeaveCriticalSection Lib "kernel32" (lpCriticalSection As CRITICAL_SECTION)
Declare Sub DeleteCriticalSection Lib "kernel32" (lpCriticalSection As CRITICAL_SECTION)
Declare Function SetEvent Lib "kernel32" (ByVal hEvent As Long) As Long
Declare Function ResetEvent Lib "kernel32" (ByVal hEvent As Long) As Long
Declare Function PulseEvent Lib "kernel32" (ByVal hEvent As Long) As Long
Declare Function ReleaseSemaphore Lib "kernel32" (ByVal hSemaphore As Long, ByVal lReleaseCount As Long, lpPreviousCount As Long) As Long
Declare Function ReleaseMutex Lib "kernel32" (ByVal hMutex As Long) As Long


' by dansei
Public Const STATUS_WAIT_0 = &H0&
Public Const STATUS_ABANDONED_WAIT_0 = &H80&
Public Const STATUS_USER_APC = &HC0&
Public Const STATUS_TIMEOUT = &H102&
Public Const STATUS_PENDING = &H103&
Public Const STATUS_SEGMENT_NOTIFICATION = &H40000005
Public Const STATUS_GUARD_PAGE_VIOLATION = &H80000001
Public Const STATUS_DATATYPE_MISALIGNMENT = &H80000002
Public Const STATUS_BREAKPOINT = &H80000003
Public Const STATUS_SINGLE_STEP = &H80000004
Public Const STATUS_ACCESS_VIOLATION = &HC0000005
Public Const STATUS_IN_PAGE_ERROR = &HC0000006
Public Const STATUS_INVALID_HANDLE = &HC0000008
Public Const STATUS_NO_MEMORY = &HC0000017
Public Const STATUS_ILLEGAL_INSTRUCTION = &HC000001D
Public Const STATUS_NONCONTINUABLE_EXCEPTION = &HC0000025
Public Const STATUS_INVALID_DISPOSITION = &HC0000026
Public Const STATUS_ARRAY_BOUNDS_EXCEEDED = &HC000008C
Public Const STATUS_FLOAT_DENORMAL_OPERAND = &HC000008D
Public Const STATUS_FLOAT_DIVIDE_BY_ZERO = &HC000008E
Public Const STATUS_FLOAT_INEXACT_RESULT = &HC000008F
Public Const STATUS_FLOAT_INVALID_OPERATION = &HC0000090
Public Const STATUS_FLOAT_OVERFLOW = &HC0000091
Public Const STATUS_FLOAT_STACK_CHECK = &HC0000092
Public Const STATUS_FLOAT_UNDERFLOW = &HC0000093
Public Const STATUS_INTEGER_DIVIDE_BY_ZERO = &HC0000094
Public Const STATUS_INTEGER_OVERFLOW = &HC0000095
Public Const STATUS_PRIVILEGED_INSTRUCTION = &HC0000096
Public Const STATUS_STACK_OVERFLOW = &HC00000FD
Public Const STATUS_CONTROL_C_EXIT = &HC000013A
Public Const STATUS_FLOAT_MULTIPLE_FAULTS = &HC00002B4
Public Const STATUS_FLOAT_MULTIPLE_TRAPS = &HC00002B5
Public Const STATUS_ILLEGAL_VLM_REFERENCE = &HC00002C0

Public Const WAIT_FAILED = &HFFFFFFFF
Public Const WAIT_OBJECT_0 = STATUS_WAIT_0
Public Const WAIT_ABANDONED = STATUS_ABANDONED_WAIT_0
Public Const WAIT_ABANDONED_0 = STATUS_ABANDONED_WAIT_0
Public Const WAIT_TIMEOUT = STATUS_TIMEOUT
Public Const WAIT_IO_COMPLETION = STATUS_USER_APC

Declare Function WaitForSingleObject Lib "kernel32" (ByVal hHandle As Long, ByVal dwMilliseconds As Long) As Long
Declare Function WaitForMultipleObjects Lib "kernel32" (ByVal nCount As Long, lpHandles As Long, ByVal bWaitAll As Long, ByVal dwMilliseconds As Long) As Long
Declare Sub Sleep Lib "kernel32" (ByVal dwMilliseconds As Long)
Declare Sub OutputDebugString Lib "kernel32" Alias "OutputDebugStringA" (ByVal lpOutputString As String)
Declare Function GetVersion Lib "kernel32" () As Long

Declare Function OpenFile Lib "kernel32" (ByVal lpFileName As String, lpReOpenBuff As OFSTRUCT, ByVal wStyle As Long) As Long

' GetTempFileName() Flags
'
Public Const TF_FORCEDRIVE = &H80

Declare Function GetTempFileName Lib "kernel32" Alias "GetTempFileNameA" (ByVal lpszPath As String, ByVal lpPrefixString As String, ByVal wUnique As Long, ByVal lpTempFileName As String) As Long
Declare Function SetHandleCount Lib "kernel32" (ByVal wNumber As Long) As Long
Declare Function GetLogicalDrives Lib "kernel32" () As Long
Declare Function LockFile Lib "kernel32" (ByVal hFile As Long, ByVal dwFileOffsetLow As Long, ByVal dwFileOffsetHigh As Long, ByVal nNumberOfBytesToLockLow As Long, ByVal nNumberOfBytesToLockHigh As Long) As Long
Declare Function UnlockFile Lib "kernel32" (ByVal hFile As Long, ByVal dwFileOffsetLow As Long, ByVal dwFileOffsetHigh As Long, ByVal nNumberOfBytesToUnlockLow As Long, ByVal nNumberOfBytesToUnlockHigh As Long) As Long
Declare Function LockFileEx Lib "kernel32" (ByVal hFile As Long, ByVal dwFlags As Long, ByVal dwReserved As Long, ByVal nNumberOfBytesToLockLow As Long, ByVal nNumberOfBytesToLockHigh As Long, lpOverlapped As OVERLAPPED) As Long

Public Const LOCKFILE_FAIL_IMMEDIATELY = &H1
Public Const LOCKFILE_EXCLUSIVE_LOCK = &H2

Declare Function UnlockFileEx Lib "kernel32" (ByVal hFile As Long, ByVal dwReserved As Long, ByVal nNumberOfBytesToUnlockLow As Long, ByVal nNumberOfBytesToUnlockHigh As Long, lpOverlapped As OVERLAPPED) As Long

Type BY_HANDLE_FILE_INFORMATION
        dwFileAttributes As Long
        ftCreationTime As FILETIME
        ftLastAccessTime As FILETIME
        ftLastWriteTime As FILETIME
        dwVolumeSerialNumber As Long
        nFileSizeHigh As Long
        nFileSizeLow As Long
        nNumberOfLinks As Long
        nFileIndexHigh As Long
        nFileIndexLow As Long
End Type

Declare Function GetFileInformationByHandle Lib "kernel32" (ByVal hFile As Long, lpFileInformation As BY_HANDLE_FILE_INFORMATION) As Long
Declare Function GetFileType Lib "kernel32" (ByVal hFile As Long) As Long
Declare Function GetFileSize Lib "kernel32" (ByVal hFile As Long, lpFileSizeHigh As Long) As Long
Declare Function GetStdHandle Lib "kernel32" (ByVal nStdHandle As Long) As Long
Declare Function SetStdHandle Lib "kernel32" (ByVal nStdHandle As Long, ByVal nHandle As Long) As Long
Declare Function WriteFile Lib "kernel32" (ByVal hFile As Long, lpBuffer As Any, ByVal nNumberOfBytesToWrite As Long, lpNumberOfBytesWritten As Long, lpOverlapped As OVERLAPPED) As Long
Declare Function ReadFile Lib "kernel32" (ByVal hFile As Long, lpBuffer As Any, ByVal nNumberOfBytesToRead As Long, lpNumberOfBytesRead As Long, lpOverlapped As OVERLAPPED) As Long
Declare Function FlushFileBuffers Lib "kernel32" (ByVal hFile As Long) As Long
Declare Function DeviceIoControl Lib "kernel32" (ByVal hDevice As Long, ByVal dwIoControlCode As Long, lpInBuffer As Any, ByVal nInBufferSize As Long, lpOutBuffer As Any, ByVal nOutBufferSize As Long, lpBytesReturned As Long, lpOverlapped As OVERLAPPED) As Long
Declare Function SetEndOfFile Lib "kernel32" (ByVal hFile As Long) As Long
Declare Function SetFilePointer Lib "kernel32" (ByVal hFile As Long, ByVal lDistanceToMove As Long, lpDistanceToMoveHigh As Long, ByVal dwMoveMethod As Long) As Long
Declare Function FindClose Lib "kernel32" (ByVal hFindFile As Long) As Long
Declare Function GetFileTime Lib "kernel32" (ByVal hFile As Long, lpCreationTime As FILETIME, lpLastAccessTime As FILETIME, lpLastWriteTime As FILETIME) As Long
Declare Function SetFileTime Lib "kernel32" (ByVal hFile As Long, lpCreationTime As FILETIME, lpLastAccessTime As FILETIME, lpLastWriteTime As FILETIME) As Long
Declare Function CloseHandle Lib "kernel32" (ByVal hObject As Long) As Long
Declare Function DuplicateHandle Lib "kernel32" (ByVal hSourceProcessHandle As Long, ByVal hSourceHandle As Long, ByVal hTargetProcessHandle As Long, lpTargetHandle As Long, ByVal dwDesiredAccess As Long, ByVal bInheritHandle As Long, ByVal dwOptions As Long) As Long

Declare Function GetDriveType Lib "kernel32" Alias "GetDriveTypeA" (ByVal nDrive As String) As Long

Declare Function GlobalAlloc Lib "kernel32" (ByVal wFlags As Long, ByVal dwBytes As Long) As Long
Declare Function GlobalFree Lib "kernel32" (ByVal hMem As Long) As Long
Declare Function GlobalHandle Lib "kernel32" (wMem As Any) As Long
Declare Function GlobalLock Lib "kernel32" (ByVal hMem As Long) As Long
Declare Function GlobalReAlloc Lib "kernel32" (ByVal hMem As Long, ByVal dwBytes As Long, ByVal wFlags As Long) As Long

Declare Function GlobalSize Lib "kernel32" (ByVal hMem As Long) As Long
Declare Function GlobalUnlock Lib "kernel32" (ByVal hMem As Long) As Long
Declare Function GlobalFlags Lib "kernel32" (ByVal hMem As Long) As Long
Declare Sub GlobalMemoryStatus Lib "kernel32" (lpBuffer As MEMORYSTATUS)

Public Const LNOTIFY_OUTOFMEM = 0
Public Const LNOTIFY_MOVE = 1
Public Const LNOTIFY_DISCARD = 2

Declare Function LocalAlloc Lib "kernel32" (ByVal wFlags As Long, ByVal wBytes As Long) As Long
Declare Function LocalFree Lib "kernel32" (ByVal hMem As Long) As Long
Declare Function LocalHandle Lib "kernel32" (wMem As Any) As Long
Declare Function LocalLock Lib "kernel32" (ByVal hMem As Long) As Long
Declare Function LocalReAlloc Lib "kernel32" (ByVal hMem As Long, ByVal wBytes As Long, ByVal wFlags As Long) As Long

Declare Function LocalSize Lib "kernel32" (ByVal hMem As Long) As Long
Declare Function LocalUnlock Lib "kernel32" (ByVal hMem As Long) As Long
Declare Function LocalFlags Lib "kernel32" (ByVal hMem As Long) As Long

Type MEMORY_BASIC_INFORMATION
     BaseAddress As Long
     AllocationBase As Long
     AllocationProtect As Long
     RegionSize As Long
     State As Long
     Protect As Long
     lType As Long
End Type

Declare Function FlushInstructionCache Lib "kernel32" (ByVal hProcess As Long, lpBaseAddress As Any, ByVal dwSize As Long) As Long
Declare Function VirtualAlloc Lib "kernel32" (lpAddress As Any, ByVal dwSize As Long, ByVal flAllocationType As Long, ByVal flProtect As Long) As Long
Declare Function VirtualFree Lib "kernel32" (lpAddress As Any, ByVal dwSize As Long, ByVal dwFreeType As Long) As Long
Declare Function VirtualProtect Lib "kernel32" (lpAddress As Any, ByVal dwSize As Long, ByVal flNewProtect As Long, lpflOldProtect As Long) As Long
Declare Function VirtualQuery Lib "kernel32" (lpAddress As Any, lpBuffer As MEMORY_BASIC_INFORMATION, ByVal dwLength As Long) As Long
Declare Function VirtualProtectEx Lib "kernel32" (ByVal hProcess As Long, lpAddress As Any, ByVal dwSize As Long, ByVal flNewProtect As Long, lpflOldProtect As Long) As Long
Declare Function VirtualQueryEx Lib "kernel32" (ByVal hProcess As Long, lpAddress As Any, lpBuffer As MEMORY_BASIC_INFORMATION, ByVal dwLength As Long) As Long
Declare Function HeapCreate Lib "kernel32" (ByVal flOptions As Long, ByVal dwInitialSize As Long, ByVal dwMaximumSize As Long) As Long
Declare Function HeapDestroy Lib "kernel32" (ByVal hHeap As Long) As Long
Declare Function HeapAlloc Lib "kernel32" (ByVal hHeap As Long, ByVal dwFlags As Long, ByVal dwBytes As Long) As Long
Declare Function HeapReAlloc Lib "kernel32" (ByVal hHeap As Long, ByVal dwFlags As Long, lpMem As Any, ByVal dwBytes As Long) As Long
Declare Function HeapFree Lib "kernel32" (ByVal hHeap As Long, ByVal dwFlags As Long, lpMem As Any) As Long
Declare Function HeapSize Lib "kernel32" (ByVal hHeap As Long, ByVal dwFlags As Long, lpMem As Any) As Long
Declare Function GetProcessHeap Lib "kernel32" () As Long
Declare Function GetProcessTimes Lib "kernel32" (ByVal hProcess As Long, lpCreationTime As FILETIME, lpExitTime As FILETIME, lpKernelTime As FILETIME, lpUserTime As FILETIME) As Long

Public Const PROCESS_TERMINATE = &H1
Public Const PROCESS_CREATE_THREAD = &H2
Public Const PROCESS_SET_SESSIONID = &H4
Public Const PROCESS_VM_OPERATION = &H8
Public Const PROCESS_VM_READ = &H10
Public Const PROCESS_VM_WRITE = &H20
Public Const PROCESS_DUP_HANDLE = &H40
Public Const PROCESS_CREATE_PROCESS = &H80
Public Const PROCESS_SET_QUOTA = &H100
Public Const PROCESS_SET_INFORMATION = &H200
Public Const PROCESS_QUERY_INFORMATION = &H400
Public Const PROCESS_ALL_ACCESS = STANDARD_RIGHTS_REQUIRED Or SYNCHRONIZE Or &HFFF

Declare Function OpenProcess Lib "kernel32" (ByVal dwDesiredAccess As Long, ByVal bInheritHandle As Long, ByVal dwProcessId As Long) As Long
Declare Function GetCurrentProcess Lib "kernel32" () As Long
Declare Function GetCurrentProcessId Lib "kernel32" () As Long
Declare Sub ExitProcess Lib "kernel32" (ByVal uExitCode As Long)
Declare Function TerminateProcess Lib "kernel32" (ByVal hProcess As Long, ByVal uExitCode As Long) As Long
Declare Function GetExitCodeProcess Lib "kernel32" (ByVal hProcess As Long, lpExitCode As Long) As Long
Declare Function OpenThread Lib "kernel32" (ByVal dwDesiredAccess As Long, ByVal bInheritHandle As Long, ByVal dwThreadId As Long) As Long

Declare Function GetLastError Lib "kernel32" () As Long
Declare Sub SetLastError Lib "kernel32" (ByVal dwErrCode As Long)

Public Const SLE_ERROR = &H1
Public Const SLE_MINORERROR = &H2
Public Const SLE_WARNING = &H3

Declare Sub SetLastErrorEx Lib "user32" (ByVal dwErrCode As Long, ByVal dwType As Long)
Declare Function GetOverlappedResult Lib "kernel32" (ByVal hFile As Long, lpOverlapped As OVERLAPPED, lpNumberOfBytesTransferred As Long, ByVal bWait As Long) As Long

Public Const SEM_FAILCRITICALERRORS = &H1
Public Const SEM_NOGPFAULTERRORBOX = &H2
Public Const SEM_NOOPENFILEERRORBOX = &H8000

Declare Sub SetDebugErrorLevel Lib "user32" (ByVal dwLevel As Long)
Declare Function SetErrorMode Lib "kernel32" (ByVal wMode As Long) As Long

Declare Function ReadProcessMemory Lib "kernel32" (ByVal hProcess As Long, lpBaseAddress As Any, lpBuffer As Any, ByVal nSize As Long, lpNumberOfBytesWritten As Long) As Long
Declare Function WriteProcessMemory Lib "kernel32" (ByVal hProcess As Long, lpBaseAddress As Any, lpBuffer As Any, ByVal nSize As Long, lpNumberOfBytesWritten As Long) As Long
Declare Function GetThreadContext Lib "kernel32" (ByVal hThread As Long, lpContext As CONTEXT) As Long
Declare Function SetThreadContext Lib "kernel32" (ByVal hThread As Long, lpContext As CONTEXT) As Long
Declare Function SuspendThread Lib "kernel32" (ByVal hThread As Long) As Long
Declare Function ResumeThread Lib "kernel32" (ByVal hThread As Long) As Long

Declare Function FindResource Lib "kernel32" Alias "FindResourceA" (ByVal hInstance As Long, ByVal lpName As String, ByVal lpType As String) As Long
Declare Function FindResourceEx Lib "kernel32" Alias "FindResourceExA" (ByVal hModule As Long, ByVal lpType As String, ByVal lpName As String, ByVal wLanguage As Long) As Long
Declare Function BeginUpdateResource Lib "kernel32" Alias "BeginUpdateResourceA" (ByVal pFileName As String, ByVal bDeleteExistingResources As Long) As Long
Declare Function UpdateResource Lib "kernel32" Alias "UpdateResourceA" (ByVal hUpdate As Long, ByVal lpType As String, ByVal lpName As String, ByVal wLanguage As Long, lpData As Any, ByVal cbData As Long) As Long
Declare Function EndUpdateResource Lib "kernel32" Alias "EndUpdateResourceA" (ByVal hUpdate As Long, ByVal fDiscard As Long) As Long
Declare Function LoadResource Lib "kernel32" (ByVal hInstance As Long, ByVal hResInfo As Long) As Long
Declare Function LockResource Lib "kernel32" (ByVal hResData As Long) As Long
Declare Function SizeofResource Lib "kernel32" (ByVal hInstance As Long, ByVal hResInfo As Long) As Long

' Predefined Resource Types
Public Const RT_CURSOR = 1&
Public Const RT_BITMAP = 2&
Public Const RT_ICON = 3&
Public Const RT_MENU = 4&
Public Const RT_DIALOG = 5&
Public Const RT_STRING = 6&
Public Const RT_FONTDIR = 7&
Public Const RT_FONT = 8&
Public Const RT_ACCELERATOR = 9&
Public Const RT_RCDATA = 10&

Declare Function InitAtomTable Lib "kernel32" (ByVal nSize As Long) As Long
Declare Function GlobalAddAtom Lib "kernel32" Alias "GlobalAddAtomA" (ByVal lpString As String) As Integer
Declare Function GlobalDeleteAtom Lib "kernel32" (ByVal nAtom As Integer) As Integer
Declare Function GlobalFindAtom Lib "kernel32" Alias "GlobalFindAtomA" (ByVal lpString As String) As Integer
Declare Function GlobalGetAtomName Lib "kernel32" Alias "GlobalGetAtomNameA" (ByVal nAtom As Integer, ByVal lpBuffer As String, ByVal nSize As Long) As Long


' User Profile Routines
' NOTE: The lpKeyName argument for GetProfileString, WriteProfileString,
'       GetPrivateProfileString, and WritePrivateProfileString can be either
'       a string or NULL.  This is why the argument is defined as "As Any".
'          For example, to pass a string specify   ByVal "wallpaper"
'          To pass NULL specify                    ByVal 0&
'       You can also pass NULL for the lpString argument for WriteProfileString
'       and WritePrivateProfileString
Declare Function GetProfileInt Lib "kernel32" Alias "GetProfileIntA" (ByVal lpAppName As String, ByVal lpKeyName As String, ByVal nDefault As Long) As Long

Declare Function GetProfileString Lib "kernel32" Alias "GetProfileStringA" (ByVal lpAppName As String, ByVal lpKeyName As String, ByVal lpDefault As String, ByVal lpReturnedString As String, ByVal nSize As Long) As Long

Declare Function WriteProfileString Lib "kernel32" Alias "WriteProfileStringA" (ByVal lpszSection As String, ByVal lpszKeyName As String, ByVal lpszString As String) As Long

Declare Function GetProfileSection Lib "kernel32" Alias "GetProfileSectionA" (ByVal lpAppName As String, ByVal lpReturnedString As String, ByVal nSize As Long) As Long
Declare Function WriteProfileSection Lib "kernel32" Alias "WriteProfileSectionA" (ByVal lpAppName As String, ByVal lpString As String) As Long
Declare Function GetPrivateProfileInt Lib "kernel32" Alias "GetPrivateProfileIntA" (ByVal lpApplicationName As String, ByVal lpKeyName As String, ByVal nDefault As Long, ByVal lpFileName As String) As Long

Declare Function GetPrivateProfileString Lib "kernel32" Alias "GetPrivateProfileStringA" (ByVal lpApplicationName As String, ByVal lpKeyName As Any, ByVal lpDefault As String, ByVal lpReturnedString As String, ByVal nSize As Long, ByVal lpFileName As String) As Long

Declare Function WritePrivateProfileString Lib "kernel32" Alias "WritePrivateProfileStringA" (ByVal lpApplicationName As String, ByVal lpKeyName As Any, ByVal lpString As Any, ByVal lpFileName As String) As Long

Declare Function GetPrivateProfileSection Lib "kernel32" Alias "GetPrivateProfileSectionA" (ByVal lpAppName As String, ByVal lpReturnedString As String, ByVal nSize As Long, ByVal lpFileName As String) As Long
Declare Function WritePrivateProfileSection Lib "kernel32" Alias "WritePrivateProfileSectionA" (ByVal lpAppName As String, ByVal lpString As String, ByVal lpFileName As String) As Long

Declare Function GetWindowsDirectory Lib "kernel32" Alias "GetWindowsDirectoryA" (ByVal lpBuffer As String, ByVal nSize As Long) As Long
Declare Function GetSystemDirectory Lib "kernel32" Alias "GetSystemDirectoryA" (ByVal lpBuffer As String, ByVal nSize As Long) As Long
Declare Function GetTempPath Lib "kernel32" Alias "GetTempPathA" (ByVal nBufferLength As Long, ByVal lpBuffer As String) As Long
Declare Function SetCurrentDirectory Lib "kernel32" Alias "SetCurrentDirectoryA" (ByVal lpPathName As String) As Long
Declare Function GetCurrentDirectory Lib "kernel32" (ByVal nBufferLength As Long, ByVal lpBuffer As String) As Long
Declare Function GetDiskFreeSpace Lib "kernel32" Alias "GetDiskFreeSpaceA" (ByVal lpRootPathName As String, lpSectorsPerCluster As Long, lpBytesPerSector As Long, lpNumberOfFreeClusters As Long, lpTotalNumberOfClusters As Long) As Long
Declare Function CreateDirectory Lib "kernel32" Alias "CreateDirectoryA" (ByVal lpPathName As String, lpSecurityAttributes As SECURITY_ATTRIBUTES) As Long
Declare Function CreateDirectoryEx Lib "kernel32" Alias "CreateDirectoryExA" (ByVal lpTemplateDirectory As String, ByVal lpNewDirectory As String, lpSecurityAttributes As SECURITY_ATTRIBUTES) As Long
Declare Function RemoveDirectory Lib "kernel32" Alias "RemoveDirectoryA" (ByVal lpPathName As String) As Long
Declare Function GetFullPathName Lib "kernel32" Alias "GetFullPathNameA" (ByVal lpFileName As String, ByVal nBufferLength As Long, ByVal lpBuffer As String, ByVal lpFilePart As String) As Long

Public Const DDD_RAW_TARGET_PATH = &H1
Public Const DDD_REMOVE_DEFINITION = &H2
Public Const DDD_EXACT_MATCH_ON_REMOVE = &H4

Public Const MAX_PATH = 260

Declare Function DefineDosDevice Lib "kernel32" Alias "DefineDosDeviceA" (ByVal dwFlags As Long, ByVal lpDeviceName As String, ByVal lpTargetPath As String) As Long
Declare Function QueryDosDevice Lib "kernel32" Alias "QueryDosDeviceA" (ByVal lpDeviceName As String, ByVal lpTargetPath As String, ByVal ucchMax As Long) As Long
Declare Function CreateFile Lib "kernel32" Alias "CreateFileA" (ByVal lpFileName As String, ByVal dwDesiredAccess As Long, ByVal dwShareMode As Long, lpSecurityAttributes As SECURITY_ATTRIBUTES, ByVal dwCreationDisposition As Long, ByVal dwFlagsAndAttributes As Long, ByVal hTemplateFile As Long) As Long
Declare Function SetFileAttributes Lib "kernel32" Alias "SetFileAttributesA" (ByVal lpFileName As String, ByVal dwFileAttributes As Long) As Long
Declare Function GetFileAttributes Lib "kernel32" Alias "GetFileAttributesA" (ByVal lpFileName As String) As Long
Declare Function DeleteFile Lib "kernel32" Alias "DeleteFileA" (ByVal lpFileName As String) As Long
Declare Function FindFirstFile Lib "kernel32" Alias "FindFirstFileA" (ByVal lpFileName As String, lpFindFileData As WIN32_FIND_DATA) As Long
Declare Function FindNextFile Lib "kernel32" Alias "FindNextFileA" (ByVal hFindFile As Long, lpFindFileData As WIN32_FIND_DATA) As Long
Declare Function SearchPath Lib "kernel32" Alias "SearchPathA" (ByVal lpPath As String, ByVal lpFileName As String, ByVal lpExtension As String, ByVal nBufferLength As Long, ByVal lpBuffer As String, ByVal lpFilePart As String) As Long
Declare Function CopyFile Lib "kernel32" Alias "CopyFileA" (ByVal lpExistingFileName As String, ByVal lpNewFileName As String, ByVal bFailIfExists As Long) As Long
Declare Function MoveFile Lib "kernel32" Alias "MoveFileA" (ByVal lpExistingFileName As String, ByVal lpNewFileName As String) As Long
Declare Function MoveFileEx Lib "kernel32" Alias "MoveFileExA" (ByVal lpExistingFileName As String, ByVal lpNewFileName As String, ByVal dwFlags As Long) As Long

Public Const MOVEFILE_REPLACE_EXISTING = &H1
Public Const MOVEFILE_COPY_ALLOWED = &H2
Public Const MOVEFILE_DELAY_UNTIL_REBOOT = &H4

Type EVENTLOGRECORD
     Length As Long     '  Length of full record
     Reserved As Long     '  Used by the service
     RecordNumber As Long     '  Absolute record number
     TimeGenerated As Long     '  Seconds since 1-1-1970
     TimeWritten As Long     'Seconds since 1-1-1970
     EventID As Long
     EventType As Integer
     NumStrings As Integer
     EventCategory As Integer
     ReservedFlags As Integer     '  For use with paired events (auditing)
     ClosingRecordNumber As Long     'For use with paired events (auditing)
     StringOffset As Long     '  Offset from beginning of record
     UserSidLength As Long
     UserSidOffset As Long
     DataLength As Long
     DataOffset As Long     '  Offset from beginning of record
End Type

Declare Function CreateNamedPipe Lib "kernel32" Alias "CreateNamedPipeA" (ByVal lpName As String, ByVal dwOpenMode As Long, ByVal dwPipeMode As Long, ByVal nMaxInstances As Long, ByVal nOutBufferSize As Long, ByVal nInBufferSize As Long, ByVal nDefaultTimeOut As Long, lpSecurityAttributes As SECURITY_ATTRIBUTES) As Long
Declare Function GetNamedPipeHandleState Lib "kernel32" Alias "GetNamedPipeHandleStateA" (ByVal hNamedPipe As Long, lpState As Long, lpCurInstances As Long, lpMaxCollectionCount As Long, lpCollectDataTimeout As Long, ByVal lpUserName As String, ByVal nMaxUserNameSize As Long) As Long
Declare Function CallNamedPipe Lib "kernel32" Alias "CallNamedPipeA" (ByVal lpNamedPipeName As String, lpInBuffer As Any, ByVal nInBufferSize As Long, lpOutBuffer As Any, ByVal nOutBufferSize As Long, lpBytesRead As Long, ByVal nTimeOut As Long) As Long
Declare Function WaitNamedPipe Lib "kernel32" Alias "WaitNamedPipeA" (ByVal lpNamedPipeName As String, ByVal nTimeOut As Long) As Long
Declare Function SetVolumeLabel Lib "kernel32" Alias "SetVolumeLabelA" (ByVal lpRootPathName As String, ByVal lpVolumeName As String) As Long
Declare Sub SetFileApisToOEM Lib "kernel32" ()
Declare Function GetVolumeInformation Lib "kernel32" Alias "GetVolumeInformationA" (ByVal lpRootPathName As String, ByVal lpVolumeNameBuffer As String, ByVal nVolumeNameSize As Long, lpVolumeSerialNumber As Long, lpMaximumComponentLength As Long, lpFileSystemFlags As Long, ByVal lpFileSystemNameBuffer As String, ByVal nFileSystemNameSize As Long) As Long
Declare Function ClearEventLog Lib "advapi32.dll" Alias "ClearEventLogA" (ByVal hEventLog As Long, ByVal lpBackupFileName As String) As Long
Declare Function BackupEventLog Lib "advapi32.dll" Alias "BackupEventLogA" (ByVal hEventLog As Long, ByVal lpBackupFileName As String) As Long
Declare Function CloseEventLog Lib "advapi32.dll" (ByVal hEventLog As Long) As Long
Declare Function DeregisterEventSource Lib "advapi32.dll" (ByVal hEventLog As Long) As Long
Declare Function GetNumberOfEventLogRecords Lib "advapi32.dll" (ByVal hEventLog As Long, NumberOfRecords As Long) As Long
Declare Function GetOldestEventLogRecord Lib "advapi32.dll" (ByVal hEventLog As Long, OldestRecord As Long) As Long
Declare Function OpenEventLog Lib "advapi32.dll" Alias "OpenEventLogA" (ByVal lpUNCServerName As String, ByVal lpSourceName As String) As Long
Declare Function RegisterEventSource Lib "advapi32.dll" Alias "RegisterEventSourceA" (ByVal lpUNCServerName As String, ByVal lpSourceName As String) As Long
Declare Function OpenBackupEventLog Lib "advapi32.dll" Alias "OpenBackupEventLogA" (ByVal lpUNCServerName As String, ByVal lpFileName As String) As Long
Declare Function ReadEventLog Lib "advapi32.dll" Alias "ReadEventLogA" (ByVal hEventLog As Long, ByVal dwReadFlags As Long, ByVal dwRecordOffset As Long, lpBuffer As EVENTLOGRECORD, ByVal nNumberOfBytesToRead As Long, pnBytesRead As Long, pnMinNumberOfBytesNeeded As Long) As Long
Declare Function ReportEvent Lib "advapi32.dll" Alias "ReportEventA" (ByVal hEventLog As Long, ByVal wType As Long, ByVal wCategory As Long, ByVal dwEventID As Long, lpUserSid As Any, ByVal wNumStrings As Long, ByVal dwDataSize As Long, ByVal lpStrings As Long, lpRawData As Any) As Long

' Security APIs
Public Const TokenUser = 1
Public Const TokenGroups = 2
Public Const TokenPrivileges = 3
Public Const TokenOwner = 4
Public Const TokenPrimaryGroup = 5
Public Const TokenDefaultDacl = 6
Public Const TokenSource = 7
Public Const TokenType = 8
Public Const TokenImpersonationLevel = 9
Public Const TokenStatistics = 10

Type TOKEN_GROUPS
    GroupCount As Long
    Groups(ANYSIZE_ARRAY) As SID_AND_ATTRIBUTES
End Type

Declare Function DuplicateToken Lib "advapi32.dll" (ByVal ExistingTokenHandle As Long, Impersonationlevel As Integer, DuplicateTokenHandle As Long) As Long
Declare Function GetKernelObjectSecurity Lib "advapi32.dll" (ByVal handle As Long, ByVal RequestedInformation As Long, pSecurityDescriptor As SECURITY_DESCRIPTOR, ByVal nLength As Long, lpnLengthNeeded As Long) As Long
Declare Function ImpersonateNamedPipeClient Lib "advapi32.dll" (ByVal hNamedPipe As Long) As Long
Declare Function ImpersonateSelf Lib "advapi32.dll" (Impersonationlevel As Integer) As Long
Declare Function RevertToSelf Lib "advapi32.dll" () As Long
Declare Function AccessCheck Lib "advapi32.dll" (pSecurityDescriptor As SECURITY_DESCRIPTOR, ByVal ClientToken As Long, ByVal DesiredAccess As Long, GenericMapping As GENERIC_MAPPING, PrivilegeSet As PRIVILEGE_SET, PrivilegeSetLength As Long, GrantedAccess As Long, ByVal Status As Long) As Long

Type TOKEN_PRIVILEGES
        PrivilegeCount As Long
        Privileges(ANYSIZE_ARRAY) As LUID_AND_ATTRIBUTES
End Type

Declare Function OpenProcessToken Lib "advapi32.dll" (ByVal ProcessHandle As Long, ByVal DesiredAccess As Long, TokenHandle As Long) As Long
Declare Function OpenThreadToken Lib "advapi32.dll" (ByVal ThreadHandle As Long, ByVal DesiredAccess As Long, ByVal OpenAsSelf As Long, TokenHandle As Long) As Long

Declare Function GetTokenInformation Lib "advapi32.dll" (ByVal TokenHandle As Long, TokenInformationClass As Integer, TokenInformation As Any, ByVal TokenInformationLength As Long, ReturnLength As Long) As Long
Declare Function SetTokenInformation Lib "advapi32.dll" (ByVal TokenHandle As Long, TokenInformationClass As Integer, TokenInformation As Any, ByVal TokenInformationLength As Long) As Long
Declare Function AdjustTokenPrivileges Lib "advapi32.dll" (ByVal TokenHandle As Long, ByVal DisableAllPrivileges As Long, NewState As TOKEN_PRIVILEGES, ByVal BufferLength As Long, PreviousState As TOKEN_PRIVILEGES, ReturnLength As Long) As Long
Declare Function AdjustTokenGroups Lib "advapi32.dll" (ByVal TokenHandle As Long, ByVal ResetToDefault As Long, NewState As TOKEN_GROUPS, ByVal BufferLength As Long, PreviousState As TOKEN_GROUPS, ReturnLength As Long) As Long
Declare Function PrivilegeCheck Lib "advapi32.dll" (ByVal ClientToken As Long, RequiredPrivileges As PRIVILEGE_SET, ByVal pfResult As Long) As Long
Declare Function AccessCheckAndAuditAlarm Lib "advapi32.dll" Alias "AccessCheckAndAuditAlarmA" (ByVal SubsystemName As String, HandleId As Any, ByVal ObjectTypeName As String, ByVal ObjectName As String, SecurityDescriptor As SECURITY_DESCRIPTOR, ByVal DesiredAccess As Long, GenericMapping As GENERIC_MAPPING, ByVal ObjectCreation As Long, GrantedAccess As Long, ByVal AccessStatus As Long, ByVal pfGenerateOnClose As Long) As Long
Declare Function ObjectOpenAuditAlarm Lib "kernel32" Alias "ObjectOpenAuditAlarmA" (ByVal SubsystemName As String, HandleId As Any, ByVal ObjectTypeName As String, ByVal ObjectName As String, pSecurityDescriptor As SECURITY_DESCRIPTOR, ByVal ClientToken As Long, ByVal DesiredAccess As Long, ByVal GrantedAccess As Long, Privileges As PRIVILEGE_SET, ByVal ObjectCreation As Long, ByVal AccessGranted As Long, ByVal GenerateOnClose As Long) As Long
Declare Function ObjectPrivilegeAuditAlarm Lib "advapi32.dll" Alias "ObjectPrivilegeAuditAlarmA" (ByVal SubsystemName As String, HandleId As Any, ByVal ClientToken As Long, ByVal DesiredAccess As Long, Privileges As PRIVILEGE_SET, ByVal AccessGranted As Long) As Long
Declare Function ObjectCloseAuditAlarm Lib "advapi32.dll" Alias "ObjectCloseAuditAlarmA" (ByVal SubsystemName As String, HandleId As Any, ByVal GenerateOnClose As Long) As Long
Declare Function PrivilegedServiceAuditAlarm Lib "advapi32.dll" Alias "PrivilegedServiceAuditAlarmA" (ByVal SubsystemName As String, ByVal ServiceName As String, ByVal ClientToken As Long, Privileges As PRIVILEGE_SET, ByVal AccessGranted As Long) As Long
Declare Function IsValidSid Lib "advapi32.dll" (pSID As Any) As Long
Declare Function EqualSid Lib "advapi32.dll" (pSid1 As Any, pSid2 As Any) As Long
Declare Function EqualPrefixSid Lib "advapi32.dll" (pSid1 As Any, pSid2 As Any) As Long
Declare Function GetSidLengthRequired Lib "advapi32.dll" (ByVal nSubAuthorityCount As Byte) As Long
Declare Function AllocateAndInitializeSid Lib "advapi32.dll" (pIdentifierAuthority As SID_IDENTIFIER_AUTHORITY, ByVal nSubAuthorityCount As Byte, ByVal nSubAuthority0 As Long, ByVal nSubAuthority1 As Long, ByVal nSubAuthority2 As Long, ByVal nSubAuthority3 As Long, ByVal nSubAuthority4 As Long, ByVal nSubAuthority5 As Long, ByVal nSubAuthority6 As Long, ByVal nSubAuthority7 As Long, lpPSid As Long) As Long
Declare Sub FreeSid Lib "advapi32.dll" (pSID As Any)
Declare Function InitializeSid Lib "advapi32.dll" (Sid As Any, pIdentifierAuthority As SID_IDENTIFIER_AUTHORITY, ByVal nSubAuthorityCount As Byte) As Long
Declare Function GetSidIdentifierAuthority Lib "advapi32.dll" (pSID As Any) As SID_IDENTIFIER_AUTHORITY
Declare Function GetSidSubAuthority Lib "advapi32.dll" (pSID As Any, ByVal nSubAuthority As Long) As Long
Declare Function GetSidSubAuthorityCount Lib "advapi32.dll" (pSID As Any) As Byte
Declare Function GetLengthSid Lib "advapi32.dll" (pSID As Any) As Long
Declare Function CopySid Lib "advapi32.dll" (ByVal nDestinationSidLength As Long, pDestinationSid As Any, pSourceSid As Any) As Long
Declare Function AreAllAccessesGranted Lib "advapi32.dll" (ByVal GrantedAccess As Long, ByVal DesiredAccess As Long) As Long
Declare Function AreAnyAccessesGranted Lib "advapi32.dll" (ByVal GrantedAccess As Long, ByVal DesiredAccess As Long) As Long
Declare Sub MapGenericMask Lib "advapi32.dll" (AccessMask As Long, GenericMapping As GENERIC_MAPPING)
Declare Function IsValidAcl Lib "advapi32.dll" (pAcl As ACL) As Long
Declare Function InitializeAcl Lib "advapi32.dll" (pAcl As ACL, ByVal nAclLength As Long, ByVal dwAclRevision As Long) As Long
Declare Function GetAclInformation Lib "advapi32.dll" (pAcl As ACL, pAclInformation As Any, ByVal nAclInformationLength As Long, ByVal dwAclInformationClass As Integer) As Long
Declare Function SetAclInformation Lib "advapi32.dll" (pAcl As ACL, pAclInformation As Any, ByVal nAclInformationLength As Long, ByVal dwAclInformationClass As Integer) As Long
Declare Function AddAce Lib "advapi32.dll" (pAcl As ACL, ByVal dwAceRevision As Long, ByVal dwStartingAceIndex As Long, pAceList As Any, ByVal nAceListLength As Long) As Long
Declare Function DeleteAce Lib "advapi32.dll" (pAcl As ACL, ByVal dwAceIndex As Long) As Long
Declare Function GetAce Lib "advapi32.dll" (pAcl As ACL, ByVal dwAceIndex As Long, pAce As Any) As Long
Declare Function AddAccessAllowedAce Lib "advapi32.dll" (pAcl As ACL, ByVal dwAceRevision As Long, ByVal AccessMask As Long, pSID As Any) As Long
Declare Function AddAccessDeniedAce Lib "advapi32.dll" (pAcl As ACL, ByVal dwAceRevision As Long, ByVal AccessMask As Long, pSID As Any) As Long
Declare Function AddAuditAccessAce Lib "advapi32.dll" (pAcl As ACL, ByVal dwAceRevision As Long, ByVal dwAccessMask As Long, pSID As Any, ByVal bAuditSuccess As Long, ByVal bAuditFailure As Long) As Long
Declare Function FindFirstFreeAce Lib "advapi32.dll" (pAcl As ACL, pAce As Long) As Long
Declare Function InitializeSecurityDescriptor Lib "advapi32.dll" (pSecurityDescriptor As SECURITY_DESCRIPTOR, ByVal dwRevision As Long) As Long
Declare Function IsValidSecurityDescriptor Lib "advapi32.dll" (pSecurityDescriptor As SECURITY_DESCRIPTOR) As Long
Declare Function GetSecurityDescriptorLength Lib "advapi32.dll" (pSecurityDescriptor As SECURITY_DESCRIPTOR) As Long

Declare Function GetSecurityDescriptorControl Lib "advapi32.dll" (pSecurityDescriptor As SECURITY_DESCRIPTOR, pControl As Integer, lpdwRevision As Long) As Long
Declare Function SetSecurityDescriptorDacl Lib "advapi32.dll" (pSecurityDescriptor As SECURITY_DESCRIPTOR, ByVal bDaclPresent As Long, pDacl As ACL, ByVal bDaclDefaulted As Long) As Long
Declare Function GetSecurityDescriptorDacl Lib "advapi32.dll" (pSecurityDescriptor As SECURITY_DESCRIPTOR, lpbDaclPresent As Long, pDacl As ACL, lpbDaclDefaulted As Long) As Long
Declare Function SetSecurityDescriptorSacl Lib "advapi32.dll" (pSecurityDescriptor As SECURITY_DESCRIPTOR, ByVal bSaclPresent As Long, pSacl As ACL, ByVal bSaclDefaulted As Long) As Long
Declare Function GetSecurityDescriptorSacl Lib "advapi32.dll" (pSecurityDescriptor As SECURITY_DESCRIPTOR, ByVal lpbSaclPresent As Long, pSacl As ACL, ByVal lpbSaclDefaulted As Long) As Long
Declare Function SetSecurityDescriptorOwner Lib "advapi32.dll" (pSecurityDescriptor As SECURITY_DESCRIPTOR, pOwner As Any, ByVal bOwnerDefaulted As Long) As Long
Declare Function GetSecurityDescriptorOwner Lib "advapi32.dll" (pSecurityDescriptor As SECURITY_DESCRIPTOR, pOwner As Any, ByVal lpbOwnerDefaulted As Long) As Long
Declare Function SetSecurityDescriptorGroup Lib "advapi32.dll" (pSecurityDescriptor As SECURITY_DESCRIPTOR, pGroup As Any, ByVal bGroupDefaulted As Long) As Long
Declare Function GetSecurityDescriptorGroup Lib "advapi32.dll" (pSecurityDescriptor As SECURITY_DESCRIPTOR, pGroup As Any, ByVal lpbGroupDefaulted As Long) As Long
Declare Function CreatePrivateObjectSecurity Lib "advapi32.dll" (ParentDescriptor As SECURITY_DESCRIPTOR, CreatorDescriptor As SECURITY_DESCRIPTOR, NewDescriptor As SECURITY_DESCRIPTOR, ByVal IsDirectoryObject As Long, ByVal Token As Long, GenericMapping As GENERIC_MAPPING) As Long
Declare Function SetPrivateObjectSecurity Lib "advapi32.dll" (ByVal SecurityInformation As Long, ModificationDescriptor As SECURITY_DESCRIPTOR, ObjectsSecurityDescriptor As SECURITY_DESCRIPTOR, GenericMapping As GENERIC_MAPPING, ByVal Token As Long) As Long
Declare Function GetPrivateObjectSecurity Lib "advapi32.dll" (ObjectDescriptor As SECURITY_DESCRIPTOR, ByVal SecurityInformation As Long, ResultantDescriptor As SECURITY_DESCRIPTOR, ByVal DescriptorLength As Long, ReturnLength As Long) As Long
Declare Function DestroyPrivateObjectSecurity Lib "advapi32.dll" (ObjectDescriptor As SECURITY_DESCRIPTOR) As Long
Declare Function MakeSelfRelativeSD Lib "advapi32.dll" (pAbsoluteSecurityDescriptor As SECURITY_DESCRIPTOR, pSelfRelativeSecurityDescriptor As SECURITY_DESCRIPTOR, lpdwBufferLength As Long) As Long
Declare Function MakeAbsoluteSD Lib "advapi32.dll" (pSelfRelativeSecurityDescriptor As SECURITY_DESCRIPTOR, pAbsoluteSecurityDescriptor As SECURITY_DESCRIPTOR, lpdwAbsoluteSecurityDescriptorSize As Long, pDacl As ACL, lpdwDaclSize As Long, pSacl As ACL, lpdwSaclSize As Long, pOwner As Any, lpdwOwnerSize As Long, pPrimaryGroup As Any, lpdwPrimaryGroupSize As Long) As Long
Declare Function SetFileSecurity Lib "advapi32.dll" Alias "SetFileSecurityA" (ByVal lpFileName As String, ByVal SecurityInformation As Long, pSecurityDescriptor As SECURITY_DESCRIPTOR) As Long
Declare Function GetFileSecurity Lib "advapi32.dll" Alias "GetFileSecurityA" (ByVal lpFileName As String, ByVal RequestedInformation As Long, pSecurityDescriptor As SECURITY_DESCRIPTOR, ByVal nLength As Long, lpnLengthNeeded As Long) As Long
Declare Function SetKernelObjectSecurity Lib "advapi32.dll" (ByVal handle As Long, ByVal SecurityInformation As Long, SecurityDescriptor As SECURITY_DESCRIPTOR) As Long
Declare Function FindFirstChangeNotification Lib "kernel32" Alias "FindFirstChangeNotificationA" (ByVal lpPathName As String, ByVal bWatchSubtree As Long, ByVal dwNotifyFilter As Long) As Long
Declare Function FindNextChangeNotification Lib "kernel32" (ByVal hChangeHandle As Long) As Long
Declare Function FindCloseChangeNotification Lib "kernel32" (ByVal hChangeHandle As Long) As Long
Declare Function VirtualLock Lib "kernel32" (lpAddress As Any, ByVal dwSize As Long) As Long
Declare Function VirtualUnlock Lib "kernel32" (lpAddress As Any, ByVal dwSize As Long) As Long
Declare Function MapViewOfFileEx Lib "kernel32" (ByVal hFileMappingObject As Long, ByVal dwDesiredAccess As Long, ByVal dwFileOffsetHigh As Long, ByVal dwFileOffsetLow As Long, ByVal dwNumberOfBytesToMap As Long, lpBaseAddress As Any) As Long
Declare Function SetPriorityClass Lib "kernel32" (ByVal hProcess As Long, ByVal dwPriorityClass As Long) As Long
Declare Function GetPriorityClass Lib "kernel32" (ByVal hProcess As Long) As Long

'' ------- by dansei
Public Const SIZE_OF_80387_REGISTERS = 80
Public Const MAXIMUM_SUPPORTED_EXTENSION = 512

Public Type FLOATING_SAVE_AREA
        ControlWord As Long
        StatusWord As Long
        TagWord As Long
        ErrorOffset As Long
        ErrorSelector As Long
        DataOffset As Long
        DataSelector As Long
        RegisterArea(0 To SIZE_OF_80387_REGISTERS - 1) As Byte
        Cr0NpxState As Long
End Type

Public Type CONTEXT
        ContextFlags As Long
        Dr0 As Long
        Dr1 As Long
        Dr2 As Long
        Dr3 As Long
        Dr6 As Long
        Dr7 As Long
        FloatSave As FLOATING_SAVE_AREA
        SegGs As Long
        SegFs As Long
        SegEs As Long
        SegDs As Long
        Edi As Long
        Esi As Long
        Ebx As Long
        eDx As Long
        Ecx As Long
        Eax As Long
        Ebp As Long
        Eip As Long
        SegCs As Long
        EFlags As Long
        Esp As Long
        SegSs As Long
        ExtendedRegisters(0 To MAXIMUM_SUPPORTED_EXTENSION - 1) As Byte
End Type

''


Type EXCEPTION_POINTERS
    pExceptionRecord As EXCEPTION_RECORD
    ContextRecord As CONTEXT
End Type

Type LDT_BYTES  ' Defined for use in LDT_ENTRY Type
        BaseMid As Byte
        Flags1 As Byte
        Flags2 As Byte
        BaseHi As Byte
End Type

Type LDT_ENTRY
        LimitLow As Integer
        BaseLow As Integer
        HighWord As Long        ' Can use LDT_BYTES Type
End Type

Declare Sub FatalExit Lib "kernel32" (ByVal code As Long)
Declare Function GetEnvironmentStrings Lib "kernel32" Alias "GetEnvironmentStringsA" () As String
Declare Sub RaiseException Lib "kernel32" (ByVal dwExceptionCode As Long, ByVal dwExceptionFlags As Long, ByVal nNumberOfArguments As Long, lpArguments As Long)
Declare Function UnhandledExceptionFilter Lib "kernel32" (ExceptionInfo As EXCEPTION_POINTERS) As Long

Declare Function CreateThread Lib "kernel32" (ByVal lpThreadAttributes As Long, ByVal dwStackSize As Long, ByVal lpStartAddress As Long, ByVal lpParameter As Long, ByVal dwCreationFlags As Long, lpThreadId As Long) As Long
Declare Function CreateRemoteThread Lib "kernel32" (ByVal hProcess As Long, lpThreadAttributes As SECURITY_ATTRIBUTES, ByVal dwStackSize As Long, lpStartAddress As Long, lpParameter As Any, ByVal dwCreationFlags As Long, lpThreadId As Long) As Long
Declare Function GetCurrentThread Lib "kernel32" () As Long
Declare Function GetCurrentThreadId Lib "kernel32" () As Long
Declare Function SetThreadPriority Lib "kernel32" (ByVal hThread As Long, ByVal nPriority As Long) As Long
Declare Function GetThreadPriority Lib "kernel32" (ByVal hThread As Long) As Long
Declare Function GetThreadTimes Lib "kernel32" (ByVal hThread As Long, lpCreationTime As FILETIME, lpExitTime As FILETIME, lpKernelTime As FILETIME, lpUserTime As FILETIME) As Long
Declare Sub ExitThread Lib "kernel32" (ByVal dwExitCode As Long)
Declare Function TerminateThread Lib "kernel32" (ByVal hThread As Long, ByVal dwExitCode As Long) As Long
Declare Function GetExitCodeThread Lib "kernel32" (ByVal hThread As Long, lpExitCode As Long) As Long
Declare Function GetThreadSelectorEntry Lib "kernel32" (ByVal hThread As Long, ByVal dwSelector As Long, lpSelectorEntry As LDT_ENTRY) As Long

' COMM declarations
Declare Function SetCommState Lib "kernel32" (ByVal hCommDev As Long, lpDCB As DCB) As Long
Declare Function SetCommTimeouts Lib "kernel32" (ByVal hFile As Long, lpCommTimeouts As COMMTIMEOUTS) As Long
Declare Function GetCommState Lib "kernel32" (ByVal nCid As Long, lpDCB As DCB) As Long
Declare Function GetCommTimeouts Lib "kernel32" (ByVal hFile As Long, lpCommTimeouts As COMMTIMEOUTS) As Long
Declare Function PurgeComm Lib "kernel32" (ByVal hFile As Long, ByVal dwFlags As Long) As Long
Declare Function BuildCommDCB Lib "kernel32" Alias "BuildCommDCBA" (ByVal lpDef As String, lpDCB As DCB) As Long
Declare Function BuildCommDCBAndTimeouts Lib "kernel32" Alias "BuildCommDCBAndTimeoutsA" (ByVal lpDef As String, lpDCB As DCB, lpCommTimeouts As COMMTIMEOUTS) As Long
Declare Function TransmitCommChar Lib "kernel32" (ByVal nCid As Long, ByVal cChar As Byte) As Long
Declare Function SetCommBreak Lib "kernel32" (ByVal nCid As Long) As Long
Declare Function SetCommMask Lib "kernel32" (ByVal hFile As Long, ByVal dwEvtMask As Long) As Long
Declare Function ClearCommBreak Lib "kernel32" (ByVal nCid As Long) As Long
Declare Function ClearCommError Lib "kernel32" (ByVal hFile As Long, lpErrors As Long, lpStat As COMSTAT) As Long
Declare Function SetupComm Lib "kernel32" (ByVal hFile As Long, ByVal dwInQueue As Long, ByVal dwOutQueue As Long) As Long
Declare Function EscapeCommFunction Lib "kernel32" (ByVal nCid As Long, ByVal nFunc As Long) As Long
Declare Function GetCommMask Lib "kernel32" (ByVal hFile As Long, lpEvtMask As Long) As Long
Declare Function GetCommProperties Lib "kernel32" (ByVal hFile As Long, lpCommProp As COMMPROP) As Long
Declare Function GetCommModemStatus Lib "kernel32" (ByVal hFile As Long, lpModemStat As Long) As Long
Declare Function WaitCommEvent Lib "kernel32" (ByVal hFile As Long, lpEvtMask As Long, lpOverlapped As OVERLAPPED) As Long

Declare Function SetTapePosition Lib "kernel32" (ByVal hDevice As Long, ByVal dwPositionMethod As Long, ByVal dwPartition As Long, ByVal dwOffsetLow As Long, ByVal dwOffsetHigh As Long, ByVal bimmediate As Long) As Long
Declare Function GetTapePosition Lib "kernel32" (ByVal hDevice As Long, ByVal dwPositionType As Long, lpdwPartition As Long, lpdwOffsetLow As Long, lpdwOffsetHigh As Long) As Long
Declare Function PrepareTape Lib "kernel32" (ByVal hDevice As Long, ByVal dwOperation As Long, ByVal bimmediate As Long) As Long
Declare Function EraseTape Lib "kernel32" (ByVal hDevice As Long, ByVal dwEraseType As Long, ByVal bimmediate As Long) As Long
Declare Function CreateTapePartition Lib "kernel32" (ByVal hDevice As Long, ByVal dwPartitionMethod As Long, ByVal dwCount As Long, ByVal dwSize As Long) As Long
Declare Function WriteTapemark Lib "kernel32" (ByVal hDevice As Long, ByVal dwTapemarkType As Long, ByVal dwTapemarkCount As Long, ByVal bimmediate As Long) As Long
Declare Function GetTapeStatus Lib "kernel32" (ByVal hDevice As Long) As Long
Declare Function GetTapeParameters Lib "kernel32" (ByVal hDevice As Long, ByVal dwOperation As Long, lpdwSize As Long, lpTapeInformation As Any) As Long

Public Const GET_TAPE_MEDIA_INFORMATION = 0
Public Const GET_TAPE_DRIVE_INFORMATION = 1

Declare Function SetTapeParameters Lib "kernel32" (ByVal hDevice As Long, ByVal dwOperation As Long, lpTapeInformation As Any) As Long

Public Const SET_TAPE_MEDIA_INFORMATION = 0
Public Const SET_TAPE_DRIVE_INFORMATION = 1

Declare Function Beep Lib "kernel32" (ByVal dwFreq As Long, ByVal dwDuration As Long) As Long

Declare Function MulDiv Lib "kernel32" (ByVal nNumber As Long, ByVal nNumerator As Long, ByVal nDenominator As Long) As Long

Declare Sub GetSystemTime Lib "kernel32" (lpSystemTime As SystemTime)
Declare Function SetSystemTime Lib "kernel32" (lpSystemTime As SystemTime) As Long
Declare Sub GetLocalTime Lib "kernel32" (lpSystemTime As SystemTime)
Declare Function SetLocalTime Lib "kernel32" (lpSystemTime As SystemTime) As Long
Declare Sub GetSystemInfo Lib "kernel32" (lpSystemInfo As SYSTEM_INFO)

Type TIME_ZONE_INFORMATION
        Bias As Long
        StandardName(32) As Integer
        StandardDate As SystemTime
        StandardBias As Long
        DaylightName(32) As Integer
        DaylightDate As SystemTime
        DaylightBias As Long
End Type

Declare Function GetTimeZoneInformation Lib "kernel32" (lpTimeZoneInformation As TIME_ZONE_INFORMATION) As Long
Declare Function SetTimeZoneInformation Lib "kernel32" (lpTimeZoneInformation As TIME_ZONE_INFORMATION) As Long

' Routines to convert back and forth
' between system time and file time

Declare Function SystemTimeToFileTime Lib "kernel32" (lpSystemTime As SystemTime, lpFileTime As FILETIME) As Long
Declare Function FileTimeToLocalFileTime Lib "kernel32" (lpFileTime As FILETIME, lpLocalFileTime As FILETIME) As Long
Declare Function LocalFileTimeToFileTime Lib "kernel32" (lpLocalFileTime As FILETIME, lpFileTime As FILETIME) As Long
Declare Function FileTimeToSystemTime Lib "kernel32" (lpFileTime As FILETIME, lpSystemTime As SystemTime) As Long
Declare Function CompareFileTime Lib "kernel32" (lpFileTime1 As FILETIME, lpFileTime2 As FILETIME) As Long
Declare Function FileTimeToDosDateTime Lib "kernel32" (lpFileTime As FILETIME, ByVal lpFatDate As Long, ByVal lpFatTime As Long) As Long
Declare Function DosDateTimeToFileTime Lib "kernel32" (ByVal wFatDate As Long, ByVal wFatTime As Long, lpFileTime As FILETIME) As Long
Declare Function GetTickCount Lib "kernel32" () As Long
Declare Function FormatMessage Lib "kernel32" Alias "FormatMessageA" (ByVal dwFlags As Long, lpSource As Any, ByVal dwMessageId As Long, ByVal dwLanguageId As Long, ByVal lpBuffer As String, ByVal nSize As Long, Arguments As Long) As Long

Public Const FORMAT_MESSAGE_ALLOCATE_BUFFER = &H100
Public Const FORMAT_MESSAGE_IGNORE_INSERTS = &H200
Public Const FORMAT_MESSAGE_FROM_STRING = &H400
Public Const FORMAT_MESSAGE_FROM_HMODULE = &H800
Public Const FORMAT_MESSAGE_FROM_SYSTEM = &H1000
Public Const FORMAT_MESSAGE_ARGUMENT_ARRAY = &H2000
Public Const FORMAT_MESSAGE_MAX_WIDTH_MASK = &HFF

Declare Function CreatePipe Lib "kernel32" (phReadPipe As Long, phWritePipe As Long, lpPipeAttributes As SECURITY_ATTRIBUTES, ByVal nSize As Long) As Long
Declare Function ConnectNamedPipe Lib "kernel32" (ByVal hNamedPipe As Long, lpOverlapped As OVERLAPPED) As Long
Declare Function DisconnectNamedPipe Lib "kernel32" (ByVal hNamedPipe As Long) As Long
Declare Function SetNamedPipeHandleState Lib "kernel32" (ByVal hNamedPipe As Long, lpMode As Long, lpMaxCollectionCount As Long, lpCollectDataTimeout As Long) As Long
Declare Function GetNamedPipeInfo Lib "kernel32" (ByVal hNamedPipe As Long, lpFlags As Long, lpOutBufferSize As Long, lpInBufferSize As Long, lpMaxInstances As Long) As Long
Declare Function PeekNamedPipe Lib "kernel32" (ByVal hNamedPipe As Long, lpBuffer As Any, ByVal nBufferSize As Long, lpBytesRead As Long, lpTotalBytesAvail As Long, lpBytesLeftThisMessage As Long) As Long
Declare Function TransactNamedPipe Lib "kernel32" (ByVal hNamedPipe As Long, lpInBuffer As Any, ByVal nInBufferSize As Long, lpOutBuffer As Any, ByVal nOutBufferSize As Long, lpBytesRead As Long, lpOverlapped As OVERLAPPED) As Long

Declare Function CreateMailslot Lib "kernel32" Alias "CreateMailslotA" (ByVal lpName As String, ByVal nMaxMessageSize As Long, ByVal lReadTimeout As Long, lpSecurityAttributes As SECURITY_ATTRIBUTES) As Long
Declare Function GetMailslotInfo Lib "kernel32" (ByVal hMailslot As Long, lpMaxMessageSize As Long, lpNextSize As Long, lpMessageCount As Long, lpReadTimeout As Long) As Long
Declare Function SetMailslotInfo Lib "kernel32" (ByVal hMailslot As Long, ByVal lReadTimeout As Long) As Long
Declare Function MapViewOfFile Lib "kernel32" (ByVal hFileMappingObject As Long, ByVal dwDesiredAccess As Long, ByVal dwFileOffsetHigh As Long, ByVal dwFileOffsetLow As Long, ByVal dwNumberOfBytesToMap As Long) As Long

Declare Function FlushViewOfFile Lib "kernel32" (lpBaseAddress As Any, ByVal dwNumberOfBytesToFlush As Long) As Long
Declare Function UnmapViewOfFile Lib "kernel32" (lpBaseAddress As Any) As Long

Declare Function lstrcmp Lib "kernel32" Alias "lstrcmpA" (ByVal lpString1 As String, ByVal lpString2 As String) As Long
Declare Function lstrcmpi Lib "kernel32" Alias "lstrcmpiA" (ByVal lpString1 As String, ByVal lpString2 As String) As Long
Declare Function lstrlen Lib "kernel32" Alias "lstrlenA" (ByVal lpString As String) As Long

Declare Function lopen Lib "kernel32" Alias "_lopen" (ByVal lpPathName As String, ByVal iReadWrite As Long) As Long
Declare Function lclose Lib "kernel32" Alias "_lclose" (ByVal hFile As Long) As Long
Declare Function lcreat Lib "kernel32" Alias "_lcreat" (ByVal lpPathName As String, ByVal iAttribute As Long) As Long
Declare Function llseek Lib "kernel32" Alias "_llseek" (ByVal hFile As Long, ByVal lOffset As Long, ByVal iOrigin As Long) As Long
Declare Function lread Lib "kernel32" Alias "_lread" (ByVal hFile As Long, lpBuffer As Any, ByVal wBytes As Long) As Long
Declare Function lwrite Lib "kernel32" Alias "_lwrite" (ByVal hFile As Long, ByVal lpBuffer As String, ByVal wBytes As Long) As Long

Declare Function hread Lib "kernel32" Alias "_hread" (ByVal hFile As Long, lpBuffer As Any, ByVal lBytes As Long) As Long
Declare Function hwrite Lib "kernel32" Alias "_hwrite" (ByVal hFile As Long, ByVal lpBuffer As String, ByVal lBytes As Long) As Long

Declare Function TlsAlloc Lib "kernel32" () As Long

Public Const TLS_OUT_OF_INDEXES = &HFFFF

Declare Function TlsGetValue Lib "kernel32" (ByVal dwTlsIndex As Long) As Long
Declare Function TlsSetValue Lib "kernel32" (ByVal dwTlsIndex As Long, lpTlsValue As Any) As Long
Declare Function TlsFree Lib "kernel32" (ByVal dwTlsIndex As Long) As Long
Declare Function SleepEx Lib "kernel32" (ByVal dwMilliseconds As Long, ByVal bAlertable As Long) As Long
Declare Function WaitForSingleObjectEx Lib "kernel32" (ByVal hHandle As Long, ByVal dwMilliseconds As Long, ByVal bAlertable As Long) As Long
Declare Function WaitForMultipleObjectsEx Lib "kernel32" (ByVal nCount As Long, lpHandles As Long, ByVal bWaitAll As Long, ByVal dwMilliseconds As Long, ByVal bAlertable As Long) As Long
Declare Function BackupRead Lib "kernel32" (ByVal hFile As Long, lpBuffer As Byte, ByVal nNumberOfBytesToRead As Long, lpNumberOfBytesRead As Long, ByVal bAbort As Long, ByVal bProcessSecurity As Long, lpContext As Any) As Long
Declare Function BackupSeek Lib "kernel32" (ByVal hFile As Long, ByVal dwLowBytesToSeek As Long, ByVal dwHighBytesToSeek As Long, lpdwLowByteSeeked As Long, lpdwHighByteSeeked As Long, lpContext As Long) As Long
Declare Function BackupWrite Lib "kernel32" (ByVal hFile As Long, lpBuffer As Byte, ByVal nNumberOfBytesToWrite As Long, lpNumberOfBytesWritten As Long, ByVal bAbort As Long, ByVal bProcessSecurity As Long, lpContext As Long) As Long

' Stream ID type
Type WIN32_STREAM_ID
        dwStreamID As Long
        dwStreamAttributes As Long
        dwStreamSizeLow As Long
        dwStreamSizeHigh As Long
        dwStreamNameSize As Long
        cStreamName As Byte
End Type

' Stream IDs
Public Const BACKUP_DATA = &H1
Public Const BACKUP_EA_DATA = &H2
Public Const BACKUP_SECURITY_DATA = &H3
Public Const BACKUP_ALTERNATE_DATA = &H4
Public Const BACKUP_LINK = &H5

'   Stream Attributes
Public Const STREAM_MODIFIED_WHEN_READ = &H1
Public Const STREAM_CONTAINS_SECURITY = &H2

'  Dual Mode API below this line. Dual Mode Types also included.

Public Const STARTF_USESHOWWINDOW = &H1
Public Const STARTF_USESIZE = &H2
Public Const STARTF_USEPOSITION = &H4
Public Const STARTF_USECOUNTCHARS = &H8
Public Const STARTF_USEFILLATTRIBUTE = &H10
Public Const STARTF_RUNFULLSCREEN = &H20        '  ignored for non-x86 platforms
Public Const STARTF_FORCEONFEEDBACK = &H40
Public Const STARTF_FORCEOFFFEEDBACK = &H80
Public Const STARTF_USESTDHANDLES = &H100

Type STARTUPINFO
        cb As Long
        lpReserved As String
        lpDesktop As String
        lpTitle As String
        dwX As Long
        dwY As Long
        dwXSize As Long
        dwYSize As Long
        dwXCountChars As Long
        dwYCountChars As Long
        dwFillAttribute As Long
        dwFlags As Long
        wShowWindow As Integer
        cbReserved2 As Integer
        lpReserved2 As Long
        hStdInput As Long
        hStdOutput As Long
        hStdError As Long
End Type

Public Const SHUTDOWN_NORETRY = &H1

Type WIN32_FIND_DATA
        dwFileAttributes As Long
        ftCreationTime As FILETIME
        ftLastAccessTime As FILETIME
        ftLastWriteTime As FILETIME
        nFileSizeHigh As Long
        nFileSizeLow As Long
        dwReserved0 As Long
        dwReserved1 As Long
        cFileName As String * MAX_PATH
        cAlternate As String * 14
End Type

Declare Function CreateMutex Lib "kernel32" Alias "CreateMutexA" (lpMutexAttributes As SECURITY_ATTRIBUTES, ByVal bInitialOwner As Long, ByVal lpName As String) As Long
Declare Function OpenMutex Lib "kernel32" Alias "OpenMutexA" (ByVal dwDesiredAccess As Long, ByVal bInheritHandle As Long, ByVal lpName As String) As Long
Declare Function CreateEvent Lib "kernel32" Alias "CreateEventA" (lpEventAttributes As SECURITY_ATTRIBUTES, ByVal bManualReset As Long, ByVal bInitialState As Long, ByVal lpName As String) As Long
Declare Function OpenEvent Lib "kernel32" Alias "OpenEventA" (ByVal dwDesiredAccess As Long, ByVal bInheritHandle As Long, ByVal lpName As String) As Long
Declare Function CreateSemaphore Lib "kernel32" Alias "CreateSemaphoreA" (lpSemaphoreAttributes As SECURITY_ATTRIBUTES, ByVal lInitialCount As Long, ByVal lMaximumCount As Long, ByVal lpName As String) As Long
Declare Function OpenSemaphore Lib "kernel32" Alias "OpenSemaphoreA" (ByVal dwDesiredAccess As Long, ByVal bInheritHandle As Long, ByVal lpName As String) As Long
Declare Function CreateFileMapping Lib "kernel32" Alias "CreateFileMappingA" (ByVal hFile As Long, lpFileMappigAttributes As SECURITY_ATTRIBUTES, ByVal flProtect As Long, ByVal dwMaximumSizeHigh As Long, ByVal dwMaximumSizeLow As Long, ByVal lpName As String) As Long
Declare Function OpenFileMapping Lib "kernel32" Alias "OpenFileMappingA" (ByVal dwDesiredAccess As Long, ByVal bInheritHandle As Long, ByVal lpName As String) As Long
Declare Function GetLogicalDriveStrings Lib "kernel32" Alias "GetLogicalDriveStringsA" (ByVal nBufferLength As Long, ByVal lpBuffer As String) As Long

Declare Function IsBadReadPtr Lib "kernel32" (lp As Any, ByVal ucb As Long) As Long
Declare Function IsBadWritePtr Lib "kernel32" (lp As Any, ByVal ucb As Long) As Long
Declare Function IsBadStringPtr Lib "kernel32" Alias "IsBadStringPtrA" (ByVal lpsz As String, ByVal ucchMax As Long) As Long
Declare Function IsBadHugeReadPtr Lib "kernel32" (lp As Any, ByVal ucb As Long) As Long
Declare Function IsBadHugeWritePtr Lib "kernel32" (lp As Any, ByVal ucb As Long) As Long

Declare Function LookupAccountSid Lib "advapi32.dll" Alias "LookupAccountSidA" (ByVal lpSystemName As String, Sid As Any, ByVal Name As String, cbName As Long, ByVal ReferencedDomainName As String, cbReferencedDomainName As Long, peUse As Integer) As Long

Declare Function LookupAccountName Lib "advapi32.dll" Alias "LookupAccountNameA" (ByVal lpSystemName As String, ByVal lpAccountName As String, Sid As Long, cbSid As Long, ByVal ReferencedDomainName As String, cbReferencedDomainName As Long, peUse As Integer) As Long
'Declare Function LookupPrivilegeValue Lib "advapi32.dll" Alias "LookupPrivilegeValueA" (ByVal lpSystemName As String, ByVal lpName As String, lpLuid As LARGE_INTEGER) As Long
'Declare Function LookupPrivilegeName Lib "advapi32.dll" Alias "LookupPrivilegeNameA" (ByVal lpSystemName As String, lpLuid As LARGE_INTEGER, ByVal lpName As String, cbName As Long) As Long
Declare Function LookupPrivilegeDisplayName Lib "advapi32.dll" Alias "LookupPrivilegeDisplayNameA" (ByVal lpSystemName As String, ByVal lpName As String, ByVal lpDisplayName As String, cbDisplayName As Long, lpLanguageID As Long) As Long
'Declare Function AllocateLocallyUniqueId Lib "advapi32.dll" (Luid As LARGE_INTEGER) As Long

Declare Function GetComputerName Lib "kernel32" Alias "GetComputerNameA" (ByVal lpBuffer As String, nSize As Long) As Long
Declare Function SetComputerName Lib "kernel32" Alias "SetComputerNameA" (ByVal lpComputerName As String) As Long
Declare Function GetUserName Lib "advapi32.dll" Alias "GetUserNameA" (ByVal lpBuffer As String, nSize As Long) As Long



Public Const THREAD_TERMINATE = &H1&
Public Const THREAD_SUSPEND_RESUME = &H2&
Public Const THREAD_GET_CONTEXT = &H8&
Public Const THREAD_SET_CONTEXT = &H10&
Public Const THREAD_SET_INFORMATION = &H20&
Public Const THREAD_QUERY_INFORMATION = &H40&
Public Const THREAD_SET_THREAD_TOKEN = &H80&
Public Const THREAD_IMPERSONATE = &H100&
Public Const THREAD_DIRECT_IMPERSONATION = &H200&
Public Const THREAD_ALL_ACCESS = STANDARD_RIGHTS_REQUIRED Or SYNCHRONIZE Or &H3FF&
