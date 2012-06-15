Attribute VB_Name = "modWinBasic"

' public type definitions for Windows' basic types.
Public Const ANYSIZE_ARRAY = 1

Type RECT
        Left As Long
        Top As Long
        Right As Long
        Bottom As Long
End Type

Public Type RECTL
        Left As Long
        Top As Long
        Right As Long
        Bottom As Long
End Type

Public Type POINTAPI
        X As Long
        Y As Long
End Type

Public Type POINTL
        X As Long
        Y As Long
End Type

Public Type Size
        cx As Long
        cy As Long
End Type

Public Type POINTS
        X  As Integer
        Y  As Integer
End Type

Public Type Msg
    hWnd As Long
    message As Long
    wParam As Long
    lParam As Long
    time As Long
    pt As POINTAPI
End Type


Public Const DELETE = &H10000
Public Const READ_CONTROL = &H20000
Public Const WRITE_DAC = &H40000
Public Const WRITE_OWNER = &H80000
Public Const SYNCHRONIZE = &H100000


Public Const STANDARD_RIGHTS_READ = (READ_CONTROL)
Public Const STANDARD_RIGHTS_WRITE = (READ_CONTROL)
Public Const STANDARD_RIGHTS_EXECUTE = (READ_CONTROL)
Public Const STANDARD_RIGHTS_REQUIRED = &HF0000
Public Const STANDARD_RIGHTS_ALL = &H1F0000

Public Const SPECIFIC_RIGHTS_ALL = &HFFFF


Public Type SID_IDENTIFIER_AUTHORITY
        Value(6) As Byte
End Type

Public Const SID_REVISION = (1)                         '  Current revision level
Public Const SID_MAX_SUB_AUTHORITIES = (15)
Public Const SID_RECOMMENDED_SUB_AUTHORITIES = (1)    ' Will change to around 6 in a future release.

Public Const SidTypeUser = 1
Public Const SidTypeGroup = 2
Public Const SidTypeDomain = 3
Public Const SidTypeAlias = 4
Public Const SidTypeWellKnownGroup = 5
Public Const SidTypeDeletedAccount = 6
Public Const SidTypeInvalid = 7
Public Const SidTypeUnknown = 8

Public Type SID_AND_ATTRIBUTES
        Sid As Long
        Attributes As Long
End Type

' ///////////////////////////////////////////////////////////////////////////
'                                                                          //
'  Universal well-known SIDs                                               //
'                                                                          //
'      Null SID              S-1-0-0                                       //
'      World                 S-1-1-0                                       //
'      Local                 S-1-2-0                                       //
'      Creator Owner ID      S-1-3-0                                       //
'      Creator Group ID      S-1-3-1                                       //
'                                                                          //
'      (Non-unique IDs)      S-1-4                                         //
'                                                                          //
' ///////////////////////////////////////////////////////////////////////////
Public Const SECURITY_NULL_RID = &H0
Public Const SECURITY_WORLD_RID = &H0
Public Const SECURITY_LOCAL_RID = &H0

Public Const SECURITY_CREATOR_OWNER_RID = &H0
Public Const SECURITY_CREATOR_GROUP_RID = &H1


' ///////////////////////////////////////////////////////////////////////////
'                                                                          //
'  NT well-known SIDs                                                      //
'                                                                          //
'      NT Authority          S-1-5                                         //
'      Dialup                S-1-5-1                                       //
'                                                                          //
'      Network               S-1-5-2                                       //
'      Batch                 S-1-5-3                                       //
'      Interactive           S-1-5-4                                       //
'      Service               S-1-5-6                                       //
'      AnonymousLogon        S-1-5-7       (aka null logon session)        //
'                                                                          //
'      (Logon IDs)           S-1-5-5-X-Y                                   //
'                                                                          //
'      (NT non-unique IDs)   S-1-5-0x15-...                                //
'                                                                          //
'      (Built-in domain)     s-1-5-0x20                                    //
'                                                                          //
' ///////////////////////////////////////////////////////////////////////////

Public Const SECURITY_DIALUP_RID = &H1
Public Const SECURITY_NETWORK_RID = &H2
Public Const SECURITY_BATCH_RID = &H3
Public Const SECURITY_INTERACTIVE_RID = &H4
Public Const SECURITY_SERVICE_RID = &H6
Public Const SECURITY_ANONYMOUS_LOGON_RID = &H7
Public Const SECURITY_LOGON_IDS_RID = &H5
Public Const SECURITY_LOCAL_SYSTEM_RID = &H12
Public Const SECURITY_NT_NON_UNIQUE = &H15
Public Const SECURITY_BUILTIN_DOMAIN_RID = &H20


' ///////////////////////////////////////////////////////////////////////////
'                                                                          //
'  well-known domain relative sub-authority values (RIDs)...               //
'                                                                          //
' ///////////////////////////////////////////////////////////////////////////

Public Const DOMAIN_USER_RID_ADMIN = &H1F4
Public Const DOMAIN_USER_RID_GUEST = &H1F5

Public Const DOMAIN_GROUP_RID_ADMINS = &H200
Public Const DOMAIN_GROUP_RID_USERS = &H201
Public Const DOMAIN_GROUP_RID_GUESTS = &H202


Public Const DOMAIN_ALIAS_RID_ADMINS = &H220
Public Const DOMAIN_ALIAS_RID_USERS = &H221
Public Const DOMAIN_ALIAS_RID_GUESTS = &H222
Public Const DOMAIN_ALIAS_RID_POWER_USERS = &H223
Public Const DOMAIN_ALIAS_RID_ACCOUNT_OPS = &H224
Public Const DOMAIN_ALIAS_RID_SYSTEM_OPS = &H225
Public Const DOMAIN_ALIAS_RID_PRINT_OPS = &H226
Public Const DOMAIN_ALIAS_RID_BACKUP_OPS = &H227
Public Const DOMAIN_ALIAS_RID_REPLICATOR = &H228


'  Allocate the System Luid.  The first 1000 LUIDs are reserved.
'  Use #999 here0x3E7 = 999)

'  end_ntifs

' //////////////////////////////////////////////////////////////////////
'                                                                     //
'                           User and Group related SID attributes     //
'                                                                     //
' //////////////////////////////////////////////////////////////////////

'  Group attributes

Public Const SE_GROUP_MANDATORY = &H1
Public Const SE_GROUP_ENABLED_BY_DEFAULT = &H2
Public Const SE_GROUP_ENABLED = &H4
Public Const SE_GROUP_OWNER = &H8
Public Const SE_GROUP_LOGON_ID = &HC0000000

'  User attributes

'  (None yet defined.)

' useful funcs
Public Declare Function GetLastError Lib "kernel32" () As Long

Public Const FORMAT_MESSAGE_ALLOCATE_BUFFER = &H100
Public Const FORMAT_MESSAGE_IGNORE_INSERTS = &H200
Public Const FORMAT_MESSAGE_FROM_STRING = &H400
Public Const FORMAT_MESSAGE_FROM_HMODULE = &H800
Public Const FORMAT_MESSAGE_FROM_SYSTEM = &H1000
Public Const FORMAT_MESSAGE_ARGUMENT_ARRAY = &H2000
Public Const FORMAT_MESSAGE_MAX_WIDTH_MASK = &HFF

Public Declare Function FormatMessage Lib "kernel32" Alias "FormatMessageA" (ByVal dwFlags As Long, ByVal lpSource_addr As Long, ByVal dwMessageId As Long, ByVal dwLanguageId As Long, ByVal lpBuffer As String, ByVal nSize As Long, ByVal Arguments_addr As Long) As Long
