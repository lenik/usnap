Attribute VB_Name = "modWNet"

'  Windows Network support

'  RESOURCE ENUMERATION

Public Const RESOURCE_CONNECTED = &H1
Public Const RESOURCE_PUBLICNET = &H2
Public Const RESOURCE_REMEMBERED = &H3

Public Const RESOURCETYPE_ANY = &H0
Public Const RESOURCETYPE_DISK = &H1
Public Const RESOURCETYPE_PRINT = &H2
Public Const RESOURCETYPE_UNKNOWN = &HFFFF

Public Const RESOURCEUSAGE_CONNECTABLE = &H1
Public Const RESOURCEUSAGE_CONTAINER = &H2
Public Const RESOURCEUSAGE_RESERVED = &H80000000

Public Const RESOURCEDISPLAYTYPE_GENERIC = &H0&
Public Const RESOURCEDISPLAYTYPE_DOMAIN = &H1&
Public Const RESOURCEDISPLAYTYPE_SERVER = &H2&
Public Const RESOURCEDISPLAYTYPE_SHARE = &H3&
Public Const RESOURCEDISPLAYTYPE_FILE = &H4&
Public Const RESOURCEDISPLAYTYPE_GROUP = &H5&
Public Const RESOURCEDISPLAYTYPE_NETWORK = &H6&
Public Const RESOURCEDISPLAYTYPE_ROOT = &H7&
Public Const RESOURCEDISPLAYTYPE_SHAREADMIN = &H8&
Public Const RESOURCEDISPLAYTYPE_DIRECTORY = &H9&
Public Const RESOURCEDISPLAYTYPE_TREE = &HA&
Public Const RESOURCEDISPLAYTYPE_NDSCONTAINER = &HB&

Type NETRESOURCE
        dwScope As Long                 ' + 0
        dwType As Long                  ' + 4
        dwDisplayType As Long           ' + 8
        dwUsage As Long                 ' + 12
        lpLocalName As String           ' + 16
        lpRemoteName As String          ' + 20
        lpComment As String             ' + 24
        lpProvider As String            ' + 28
End Type

Public Const NETRESOURCE_dwScope = 0
Public Const NETRESOURCE_dwType = 4
Public Const NETRESOURCE_dwDisplayType = 8
Public Const NETRESOURCE_dwUsage = 12
Public Const NETRESOURCE_lpLocalName = 16
Public Const NETRESOURCE_lpRemoteName = 20
Public Const NETRESOURCE_lpComment = 24
Public Const NETRESOURCE_lpProvider = 28

Public Const CONNECT_UPDATE_PROFILE = &H1

Declare Function WNetAddConnection Lib "mpr.dll" Alias "WNetAddConnectionA" (ByVal lpszNetPath As String, ByVal lpszPassword As String, ByVal lpszLocalName As String) As Long
Declare Function WNetAddConnection2 Lib "mpr.dll" Alias "WNetAddConnection2A" (addrNetResource As Long, ByVal lpPassword As String, ByVal lpUserName As String, ByVal dwFlags As Long) As Long
Declare Function WNetCancelConnection Lib "mpr.dll" Alias "WNetCancelConnectionA" (ByVal lpszName As String, ByVal bForce As Long) As Long
Declare Function WNetCancelConnection2 Lib "mpr.dll" Alias "WNetCancelConnection2A" (ByVal lpName As String, ByVal dwFlags As Long, ByVal fForce As Long) As Long
Declare Function WNetGetConnection Lib "mpr.dll" Alias "WNetGetConnectionA" (ByVal lpszLocalName As String, ByVal lpszRemoteName As String, cbRemoteName As Long) As Long
Declare Function WNetOpenEnum Lib "mpr.dll" Alias "WNetOpenEnumA" (ByVal dwScope As Long, ByVal dwType As Long, ByVal dwUsage As Long, ByVal addrNetResource As Long, lphEnum As Long) As Long
Declare Function WNetEnumResource Lib "mpr.dll" Alias "WNetEnumResourceA" (ByVal hEnum As Long, lpcCount As Long, ByVal addrBuffer As Long, lpBufferSize As Long) As Long
Declare Function WNetCloseEnum Lib "mpr.dll" (ByVal hEnum As Long) As Long

Declare Function WNetGetUser Lib "mpr.dll" Alias "WNetGetUserA" (ByVal lpName As String, ByVal lpUserName As String, lpnLength As Long) As Long
Declare Function WNetConnectionDialog Lib "mpr.dll" (ByVal hwnd As Long, ByVal dwType As Long) As Long
Declare Function WNetDisconnectDialog Lib "mpr.dll" (ByVal hwnd As Long, ByVal dwType As Long) As Long

Declare Function WNetGetLastError Lib "mpr.dll" Alias "WNetGetLastErrorA" (lpError As Long, ByVal lpErrorBuf As String, ByVal nErrorBufSize As Long, ByVal lpNameBuf As String, ByVal nNameBufSize As Long) As Long

' Status Codes

' This section is provided for backward compatibility.  Use of the ERROR_
' codes is preferred.  The WN_ error codes may not be available in future
' releases.

' General

Public Const WN_SUCCESS = NO_ERROR
Public Const WN_NOT_SUPPORTED = ERROR_NOT_SUPPORTED
Public Const WN_NET_ERROR = ERROR_UNEXP_NET_ERR
Public Const WN_MORE_DATA = ERROR_MORE_DATA
Public Const WN_BAD_POINTER = ERROR_INVALID_ADDRESS
Public Const WN_BAD_VALUE = ERROR_INVALID_PARAMETER
Public Const WN_BAD_PASSWORD = ERROR_INVALID_PASSWORD
Public Const WN_ACCESS_DENIED = ERROR_ACCESS_DENIED
Public Const WN_FUNCTION_BUSY = ERROR_BUSY
Public Const WN_WINDOWS_ERROR = ERROR_UNEXP_NET_ERR
Public Const WN_BAD_USER = ERROR_BAD_USERNAME
Public Const WN_OUT_OF_MEMORY = ERROR_NOT_ENOUGH_MEMORY
Public Const WN_NO_NETWORK = ERROR_NO_NETWORK
Public Const WN_EXTENDED_ERROR = ERROR_EXTENDED_ERROR

' Connection

Public Const WN_NOT_CONNECTED = ERROR_NOT_CONNECTED
Public Const WN_OPEN_FILES = ERROR_OPEN_FILES
Public Const WN_DEVICE_IN_USE = ERROR_DEVICE_IN_USE
Public Const WN_BAD_NETNAME = ERROR_BAD_NET_NAME
Public Const WN_BAD_LOCALNAME = ERROR_BAD_DEVICE
Public Const WN_ALREADY_CONNECTED = ERROR_ALREADY_ASSIGNED
Public Const WN_DEVICE_ERROR = ERROR_GEN_FAILURE
Public Const WN_CONNECTION_CLOSED = ERROR_CONNECTION_UNAVAIL
Public Const WN_NO_NET_OR_BAD_PATH = ERROR_NO_NET_OR_BAD_PATH
Public Const WN_BAD_PROVIDER = ERROR_BAD_PROVIDER
Public Const WN_CANNOT_OPEN_PROFILE = ERROR_CANNOT_OPEN_PROFILE
Public Const WN_BAD_PROFILE = ERROR_BAD_PROFILE

' Enumeration

Public Const WN_BAD_HANDLE = ERROR_INVALID_HANDLE
Public Const WN_NO_MORE_ENTRIES = ERROR_NO_MORE_ITEMS
Public Const WN_NOT_CONTAINER = ERROR_NOT_CONTAINER

Public Const WN_NO_ERROR = NO_ERROR

' This section contains the definitions
' for portable NetBIOS 3.0 support.

Public Const NCBNAMSZ = 16  '  absolute length of a net name
Public Const MAX_LANA = 254  '  lana's in range 0 to MAX_LANA

Type NCB
        ncb_command As Integer
        ncb_retcode As Integer
        ncb_lsn As Integer
        ncb_num As Integer
        ncb_buffer As String
        ncb_length As Integer
        ncb_callname As String * NCBNAMSZ
        ncb_name As String * NCBNAMSZ
        ncb_rto As Integer
        ncb_sto As Integer
        ncb_post As Long
        ncb_lana_num As Integer
        ncb_cmd_cplt As Integer
        ncb_reserve(10) As Byte ' Reserved, must be 0
        ncb_event As Long
End Type

Type ADAPTER_STATUS
        adapter_address As String * 6
        rev_major As Integer
        reserved0 As Integer
        adapter_type As Integer
        rev_minor As Integer
        duration As Integer
        frmr_recv As Integer
        frmr_xmit As Integer
        iframe_recv_err As Integer
        xmit_aborts As Integer
        xmit_success As Long
        recv_success As Long
        iframe_xmit_err As Integer
        recv_buff_unavail As Integer
        t1_timeouts As Integer
        ti_timeouts As Integer
        Reserved1 As Long
        free_ncbs As Integer
        max_cfg_ncbs As Integer
        max_ncbs As Integer
        xmit_buf_unavail As Integer
        max_dgram_size As Integer
        pending_sess As Integer
        max_cfg_sess As Integer
        max_sess As Integer
        max_sess_pkt_size As Integer
        name_count As Integer
End Type

Type NAME_BUFFER
        name  As String * NCBNAMSZ
        name_num As Integer
        name_flags As Integer
End Type

' values for name_flags bits.

Public Const NAME_FLAGS_MASK = &H87

Public Const GROUP_NAME = &H80
Public Const UNIQUE_NAME = &H0

Public Const REGISTERING = &H0
Public Const REGISTERED = &H4
Public Const DEREGISTERED = &H5
Public Const DUPLICATE = &H6
Public Const DUPLICATE_DEREG = &H7

Type SESSION_HEADER
        sess_name As Integer
        num_sess As Integer
        rcv_dg_outstanding As Integer
        rcv_any_outstanding As Integer
End Type

Type SESSION_BUFFER
        lsn As Integer
        State As Integer
        local_name As String * NCBNAMSZ
        remote_name As String * NCBNAMSZ
        rcvs_outstanding As Integer
        sends_outstanding As Integer
End Type

' Values for state
Public Const LISTEN_OUTSTANDING = &H1
Public Const CALL_PENDING = &H2
Public Const SESSION_ESTABLISHED = &H3
Public Const HANGUP_PENDING = &H4
Public Const HANGUP_COMPLETE = &H5
Public Const SESSION_ABORTED = &H6

Type LANA_ENUM
        Length As Integer
        lana(MAX_LANA) As Integer
End Type

Type FIND_NAME_HEADER
        node_count As Integer
        Reserved As Integer
        unique_group As Integer
End Type

Type FIND_NAME_BUFFER
        Length As Integer
        access_control As Integer
        frame_control As Integer
        destination_addr(6) As Integer
        source_addr(6) As Integer
        routing_info(18) As Integer
End Type

Type ACTION_HEADER
        transport_id As Long
        action_code As Integer
        Reserved As Integer
End Type

' Values for transport_id
Public Const ALL_TRANSPORTS = "M\0\0\0"
Public Const MS_NBF = "MNBF"

' NCB Command codes
Public Const NCBCALL = &H10  '  NCB CALL
Public Const NCBLISTEN = &H11  '  NCB LISTEN
Public Const NCBHANGUP = &H12  '  NCB HANG UP
Public Const NCBSEND = &H14  '  NCB SEND
Public Const NCBRECV = &H15  '  NCB RECEIVE
Public Const NCBRECVANY = &H16  '  NCB RECEIVE ANY
Public Const NCBCHAINSEND = &H17  '  NCB CHAIN SEND
Public Const NCBDGSEND = &H20  '  NCB SEND DATAGRAM
Public Const NCBDGRECV = &H21  '  NCB RECEIVE DATAGRAM
Public Const NCBDGSENDBC = &H22  '  NCB SEND BROADCAST DATAGRAM
Public Const NCBDGRECVBC = &H23  '  NCB RECEIVE BROADCAST DATAGRAM
Public Const NCBADDNAME = &H30  '  NCB ADD NAME
Public Const NCBDELNAME = &H31  '  NCB DELETE NAME
Public Const NCBRESET = &H32  '  NCB RESET
Public Const NCBASTAT = &H33  '  NCB ADAPTER STATUS
Public Const NCBSSTAT = &H34  '  NCB SESSION STATUS
Public Const NCBCANCEL = &H35  '  NCB CANCEL
Public Const NCBADDGRNAME = &H36  '  NCB ADD GROUP NAME
Public Const NCBENUM = &H37  '  NCB ENUMERATE LANA NUMBERS
Public Const NCBUNLINK = &H70  '  NCB UNLINK
Public Const NCBSENDNA = &H71  '  NCB SEND NO ACK
Public Const NCBCHAINSENDNA = &H72  '  NCB CHAIN SEND NO ACK
Public Const NCBLANSTALERT = &H73  '  NCB LAN STATUS ALERT
Public Const NCBACTION = &H77  '  NCB ACTION
Public Const NCBFINDNAME = &H78  '  NCB FIND NAME
Public Const NCBTRACE = &H79  '  NCB TRACE

Public Const ASYNCH = &H80  '  high bit set == asynchronous

' NCB Return codes
Public Const NRC_GOODRET = &H0   '  good return
                                '  also returned when ASYNCH request accepted
Public Const NRC_BUFLEN = &H1   '  illegal buffer length
Public Const NRC_ILLCMD = &H3   '  illegal command
Public Const NRC_CMDTMO = &H5   '  command timed out
Public Const NRC_INCOMP = &H6   '  message incomplete, issue another command
Public Const NRC_BADDR = &H7   '  illegal buffer address
Public Const NRC_SNUMOUT = &H8   '  session number out of range
Public Const NRC_NORES = &H9   '  no resource available
Public Const NRC_SCLOSED = &HA   '  session closed
Public Const NRC_CMDCAN = &HB   '  command cancelled
Public Const NRC_DUPNAME = &HD   '  duplicate name
Public Const NRC_NAMTFUL = &HE   '  name table full
Public Const NRC_ACTSES = &HF   '  no deletions, name has active sessions
Public Const NRC_LOCTFUL = &H11  '  local session table full
Public Const NRC_REMTFUL = &H12  '  remote session table full
Public Const NRC_ILLNN = &H13  '  illegal name number
Public Const NRC_NOCALL = &H14  '  no callname
Public Const NRC_NOWILD = &H15  '  cannot put  in NCB_NAME
Public Const NRC_INUSE = &H16  '  name in use on remote adapter
Public Const NRC_NAMERR = &H17  '  name deleted
Public Const NRC_SABORT = &H18  '  session ended abnormally
Public Const NRC_NAMCONF = &H19  '  name conflict detected
Public Const NRC_IFBUSY = &H21  '  interface busy, IRET before retrying
Public Const NRC_TOOMANY = &H22  '  too many commands outstanding, retry later
Public Const NRC_BRIDGE = &H23  '  ncb_lana_num field invalid
Public Const NRC_CANOCCR = &H24  '  command completed while cancel occurring
Public Const NRC_CANCEL = &H26  '  command not valid to cancel
Public Const NRC_DUPENV = &H30  '  name defined by anther local process
Public Const NRC_ENVNOTDEF = &H34  '  environment undefined. RESET required
Public Const NRC_OSRESNOTAV = &H35  '  required OS resources exhausted
Public Const NRC_MAXAPPS = &H36  '  max number of applications exceeded
Public Const NRC_NOSAPS = &H37  '  no saps available for netbios
Public Const NRC_NORESOURCES = &H38  '  requested resources are not available
Public Const NRC_INVADDRESS = &H39  '  invalid ncb address or length > segment
Public Const NRC_INVDDID = &H3B  '  invalid NCB DDID
Public Const NRC_LOCKFAIL = &H3C  '  lock of user area failed
Public Const NRC_OPENERR = &H3F  '  NETBIOS not loaded
Public Const NRC_SYSTEM = &H40  '  system error

Public Const NRC_PENDING = &HFF  '  asynchronous command is not yet finished

'
' Win32 NetAPIs.
'
Declare Function NetUserChangePassword Lib "netapi32.dll" (Domain As Any, User As Any, OldPass As Byte, NewPass As Byte) As Long
Declare Function NetUserGetInfo Lib "netapi32.dll" (lpServer As Any, UserName As Byte, ByVal level As Long, lpBuffer As Long) As Long
Declare Function NetUserGetGroups Lib "netapi32.dll" (lpServer As Any, UserName As Byte, ByVal level As Long, lpBuffer As Long, ByVal PrefMaxLen As Long, lpEntriesRead As Long, lpTotalEntries As Long) As Long
Declare Function NetUserGetLocalGroups Lib "netapi32.dll" (lpServer As Any, UserName As Byte, ByVal level As Long, ByVal flags As Long, lpBuffer As Long, ByVal MAXLEN As Long, lpEntriesRead As Long, lpTotalEntries As Long) As Long
' lpUser is pointer to USER_INFO_3_API
Declare Function NetUserAdd Lib "netapi32" (lpServer As Any, ByVal level As Long, lpUser As Byte, lpError As Long) As Long
Declare Function NetWkstaGetInfo Lib "netapi32.dll" (lpServer As Any, ByVal level As Long, lpBuffer As Any) As Long
Declare Function NetWkstaUserGetInfo Lib "netapi32.dll" (ByVal Reserved As Any, ByVal level As Long, lpBuffer As Any) As Long
Declare Function NetApiBufferFree Lib "netapi32.dll" (ByVal lpBuffer As Long) As Long
Declare Function NetRemoteTOD Lib "netapi32.dll" (yServer As Any, pBuffer As Long) As Long
Declare Function GetUserName Lib "advapi32.dll" Alias "GetUserNameA" (ByVal lpBuffer As String, nSize As Long) As Long
Declare Function GetUserNameW Lib "advapi32.dll" (lpBuffer As Byte, nSize As Long) As Long
Declare Function GetComputerName Lib "kernel32" Alias "GetComputerNameA" (ByVal lpBuffer As String, nSize As Long) As Long
Declare Function GetComputerNameW Lib "kernel32" (lpBuffer As Any, nSize As Long) As Long
Declare Function GetCurrentProcess Lib "kernel32" () As Long
Declare Function OpenProcessToken Lib "advapi32.dll" (ByVal ProcessHandle As Long, ByVal DesiredAccess As Long, TokenHandle As Long) As Long
Declare Function GetTokenInformation Lib "advapi32.dll" (ByVal TokenHandle As Long, ByVal TokenInformationClass As Long, TokenInformation As Any, ByVal TokenInformationLength As Long, ReturnLength As Long) As Long
Declare Function LookupAccountSid Lib "advapi32.dll" Alias "LookupAccountSidW" (ByVal lpSystemName As Any, Sid As Any, name As Any, cbName As Long, ReferencedDomainName As Any, cbReferencedDomainName As Long, peUse As Integer) As Long
Declare Function NetLocalGroupDelMembers Lib "netapi32.dll" (ByVal psServer As Long, ByVal psLocalGroup As Long, ByVal lLevel As Long, uMember As LOCALGROUP_MEMBERS_INFO_0, ByVal lMemberCount As Long) As Long
Declare Function NetLocalGroupGetMembers Lib "netapi32.dll" (ByVal psServer As Long, ByVal psLocalGroup As Long, ByVal lLevel As Long, pBuffer As Long, ByVal lMaxLength As Long, plEntriesRead As Long, plTotalEntries As Long, phResume As Long) As Long
Declare Function Netbios Lib "netapi32.dll" (pncb As NCB) As Byte

Type USER_INFO_3
   ' Level 0 starts here
   name As Long
   ' Level 1 starts here
   Password As Long
   PasswordAge As Long
   Privilege As Long
   HomeDir As Long
   Comment As Long
   flags As Long
   ScriptPath As Long
   ' Level 2 starts here
   AuthFlags As Long
   FullName As Long
   UserComment As Long
   Parms As Long
   Workstations As Long
   LastLogon As Long
   LastLogoff As Long
   AcctExpires As Long
   MaxStorage As Long
   UnitsPerWeek As Long
   LogonHours As Long
   BadPwCount As Long
   NumLogons As Long
   LogonServer As Long
   CountryCode As Long
   CodePage As Long
   ' Level 3 starts here
   UserID As Long
   PrimaryGroupID As Long
   Profile As Long
   HomeDirDrive As Long
   PasswordExpired As Long
End Type

Type GROUP_INFO_2
   name As Long
   Comment As Long
   GroupID As Long
   Attributes As Long
End Type

Type LOCALGROUP_MEMBERS_INFO_0
   pSID As Long
End Type

Type LOCALGROUP_MEMBERS_INFO_1
   'Level 0 Starts Here
   pSID As Long
   'Level 1 Starts Here
   eUsage As g_netSID_NAME_USE
   psName As Long
End Type

Type WKSTA_INFO_102
   wki102_platform_id As Long
   wki102_computername As Long
   wki102_langroup As Long
   wki102_ver_major As Long
   wki102_ver_minor As Long
   wki102_lanroot As Long
   wki102_logged_on_users As Long
End Type

Type WKSTA_USER_INFO_1
   wkui1_username As Long
   wkui1_logon_domain As Long
   wkui1_oth_domains As Long
   wkui1_logon_server As Long
End Type

Enum g_netSID_NAME_USE
   SidTypeUser = 1&
   SidTypeGroup = 2&
   SidTypeDomain = 3&
   SidTypeAlias = 4&
   SidTypeWellKnownGroup = 5&
   SidTypeDeletedAccount = 6&
   SidTypeInvalid = 7&
   SidTypeUnknown = 8&
End Enum

Public Const FILTER_TEMP_DUPLICATE_ACCOUNT As Long = &H1&
Public Const FILTER_NORMAL_ACCOUNT As Long = &H2&
Public Const FILTER_PROXY_ACCOUNT As Long = &H4&
Public Const FILTER_INTERDOMAIN_TRUST_ACCOUNT As Long = &H8&
Public Const FILTER_WORKSTATION_TRUST_ACCOUNT As Long = &H10&
Public Const FILTER_SERVER_TRUST_ACCOUNT As Long = &H20&

Public Const TIMEQ_FOREVER = -1&             '((unsigned long) -1L)
Public Const USER_MAXSTORAGE_UNLIMITED = -1& '((unsigned long) -1L)
Public Const USER_NO_LOGOFF = -1&            '((unsigned long) -1L)
Public Const UNITS_PER_DAY = 24
Public Const UNITS_PER_WEEK = UNITS_PER_DAY * 7

Public Const USER_PRIV_MASK = 3
Public Const USER_PRIV_GUEST = 0
Public Const USER_PRIV_USER = 1
Public Const USER_PRIV_ADMIN = 2

Public Const UNLEN = 256         ' Maximum username length
Public Const GNLEN = UNLEN       ' Maximum groupname length
Public Const CNLEN = 15          ' Maximum computer name length
Public Const PWLEN = 256         ' Maximum password length
Public Const LM20_PWLEN = 14     ' LM 2.0 Maximum password length
Public Const MAXCOMMENTSZ = 256  ' Multipurpose comment length
Public Const LG_INCLUDE_INDIRECT As Long = &H1&

Public Const UF_SCRIPT = &H1
Public Const UF_ACCOUNTDISABLE = &H2
Public Const UF_HOMEDIR_REQUIRED = &H8
Public Const UF_LOCKOUT = &H10
Public Const UF_PASSWD_NOTREQD = &H20
Public Const UF_PASSWD_CANT_CHANGE = &H40

Public Const NERR_Success As Long = 0&
Public Const NERR_BASE = 2100
Public Const NERR_InvalidComputer = (NERR_BASE + 251)
Public Const NERR_NotPrimary = (NERR_BASE + 126)
Public Const NERR_GroupExists = (NERR_BASE + 123)
Public Const NERR_UserExists = (NERR_BASE + 124)
Public Const NERR_PasswordTooShort = (NERR_BASE + 145)

Public Const RESOURCE_GLOBALNET As Long = &H2&
Public Const RESOURCE_ENUM_ALL As Long = &HFFFF
Public Const RESOURCEUSAGE_ALL As Long = &H0&

' Legal values for expression in except().
Public Const EXCEPTION_EXECUTE_HANDLER = 1
Public Const EXCEPTION_CONTINUE_SEARCH = 0
Public Const EXCEPTION_CONTINUE_EXECUTION = -1
